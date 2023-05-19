//说明部分

//系统
#ifdef WIN32
#include "stdafx.h"
#endif
#include <string>
#include <queue>

//Boost
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python/module.hpp>	//python封装
#include <boost/python/def.hpp>		//python封装
#include <boost/python/dict.hpp>	//python封装
#include <boost/python/object.hpp>	//python封装
#include <boost/python.hpp>			//python封装
#include <boost/thread.hpp>			//任务队列的线程功能
#include <boost/bind.hpp>			//任务队列的线程功能
#include <boost/any.hpp>			//任务队列的任务实现
#include <boost/locale.hpp>
//API
#include "QdFtdcMduserApi.h"

//命名空间
using namespace std;
using namespace boost::python;
using namespace boost;

#define GBK_TO_UTF8(gbk_str) boost::locale::conv::to_utf<wchar_t>(gbk_str, "gbk")

//常量
#define ONFRONTCONNECTED 1
#define ONFRONTDISCONNECTED 2
#define ONHEARTBEATWARNING 3
#define ONRSPERROR 4
#define ONRSPUSERLOGIN 5
#define ONRSPUSERLOGOUT 6
#define ONRTNDEPTHMARKETDATA 7
#define ONRTNMULTIDEPTHMARKETDATA 8
#define ONRSPSUBMARKETDATA 9
#define ONRSPUNSUBMARKETDATA 10
#define ONRTNMBLMARKETDATA 11
#define ONRTNQMDINSTRUMENTSTATU 12
#define ONRSPSUBSCRIBETOPIC 13
#define ONRSPQRYTOPIC 14
#define ONRSPQRYMARKETDATA 15
#define ONRSPQRYINSTRUMENTLIST 16
#define ONRTNTENENTRUST 17
#define ONRTNOPTIONINDEXDATA 18
#define ONRTNDEPTHMINMARKETDATA 19
#define ONRSPQRYMINMARKETDATA 20
#define ONRTNDEPTHONEMINBARSLICE 21
#define ONRSPQRYSTINSTRUMENT 22
#define ONRTNTRADEMAKETDATA 23
#define ONRTNORDERMAKETDATA 24




///-------------------------------------------------------------------------------------
///API中的部分组件
///-------------------------------------------------------------------------------------

//GIL全局锁简化获取用，
//用于帮助C++线程获得GIL锁，从而防止python崩溃
class PyLock
{
private:
	PyGILState_STATE gil_state;

public:
	//在某个函数方法中创建该对象时，获得GIL锁
	PyLock()
	{
		gil_state = PyGILState_Ensure();
	}

	//在某个函数完成后销毁该对象时，解放GIL锁
	~PyLock()
	{
		PyGILState_Release(gil_state);
	}
};


//任务结构体
struct Task
{
	int task_name;		//回调函数名称对应的常量
	any task_data;		//数据结构体
	any task_error;		//错误结构体
	int task_id;		//请求id
	bool task_last;		//是否为最后返回
};


///线程安全的队列
template<typename Data>

class ConcurrentQueue
{
private:
	queue<Data> the_queue;								//标准库队列
	mutable boost::mutex the_mutex;							//boost互斥锁
	boost::condition_variable the_condition_variable;			//boost条件变量

public:

	//存入新的任务
	void push(Data const& data)
	{
		boost::mutex::scoped_lock lock(the_mutex);				//获取互斥锁
		the_queue.push(data);							//向队列中存入数据
		lock.unlock();									//释放锁
		the_condition_variable.notify_one();			//通知正在阻塞等待的线程
	}

	//检查队列是否为空
	bool empty() const
	{
		boost::mutex::scoped_lock lock(the_mutex);
		return the_queue.empty();
	}

	//取出
	Data wait_and_pop()
	{
		boost::mutex::scoped_lock lock(the_mutex);

		while (the_queue.empty())						//当队列为空时
		{
			the_condition_variable.wait(lock);			//等待条件变量通知
		}

		Data popped_value = the_queue.front();			//获取队列中的最后一个任务
		the_queue.pop();								//删除该任务
		return popped_value;							//返回该任务
	}

};


//从字典中获取某个建值对应的整数，并赋值到请求结构体对象的值上
void getInt(dict d, string key, int* value);


//从字典中获取某个建值对应的浮点数，并赋值到请求结构体对象的值上
void getDouble(dict d, string key, double* value);


//从字典中获取某个建值对应的字符，并赋值到请求结构体对象的值上
void getChar(dict d, string key, char* value);


//从字典中获取某个建值对应的字符串，并赋值到请求结构体对象的值上
void getStr(dict d, string key, char* value);


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class MdApi : public CQdFtdcMduserSpi
{
private:
	CQdFtdcMduserApi* api;				//API对象
	thread *task_thread;				//工作线程指针（向python中推送数据）
	ConcurrentQueue<Task> task_queue;	//任务队列

public:
	MdApi()
	{
		function0<void> f = boost::bind(&MdApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~MdApi()
	{
	};


	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task task);

	void processFrontDisconnected(Task task);

	void processHeartBeatWarning(Task task);

	void processRspError(Task task);

	void processRspUserLogin(Task task);

	void processRspUserLogout(Task task);

	void processRtnDepthMarketData(Task task);

	void processRtnMultiDepthMarketData(Task task);

	void processRspSubMarketData(Task task);

	void processRspUnSubMarketData(Task task);

	void processRtnMBLMarketData(Task task);

	void processRtnQmdInstrumentStatu(Task task);

	void processRspSubscribeTopic(Task task);

	void processRspQryTopic(Task task);

	void processRspQryMarketData(Task task);

	void processRspQryInstrumentList(Task task);

	void processRtnTenEntrust(Task task);

	void processRtnOptionIndexData(Task task);

	void processRtnDepthMinMarketData(Task task);

	void processRspQryMinMarketData(Task task);

	void processRtnDepthOneMinBarSlice(Task task);

	void processRspQryStInstrument(Task task);

	void processRtnTradeMaketData(Task task);

	void processRtnOrderMaketData(Task task);



	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//error：回调函数的错误字典
	//id：请求id
	//last：是否为最后返回
	//i：整数
	//-------------------------------------------------------------------------------------


	virtual void OnFrontConnected();
	virtual void onFrontConnected() {};

	virtual void OnFrontDisconnected(int nReason);
	virtual void onFrontDisconnected(int i) {};

	virtual void OnHeartBeatWarning(int nTimeLapse);
	virtual void onHeartBeatWarning(int i) {};

	virtual void OnRspError(CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspError(dict error, int id, bool last) {};

	virtual void OnRspUserLogin(CQdFtdcRspUserLoginField *pRspUserLogin, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUserLogin(dict data, dict error, int id, bool last) {};

	virtual void OnRspUserLogout(CQdFtdcRspUserLogoutField *pRspUserLogout, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUserLogout(dict data, dict error, int id, bool last) {};

	virtual void OnRtnDepthMarketData(CQdFtdcDepthMarketDataField *pDepthMarketData) ;
	virtual void onRtnDepthMarketData(dict data) {};

	virtual void OnRtnMultiDepthMarketData(CQdFtdcDepthMarketDataField *pDepthMarketData) ;
	virtual void onRtnMultiDepthMarketData(dict data) {};

	virtual void OnRspSubMarketData(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSubMarketData(dict data, dict error, int id, bool last) {};

	virtual void OnRspUnSubMarketData(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUnSubMarketData(dict data, dict error, int id, bool last) {};

	virtual void OnRtnMBLMarketData(CQdFtdcMBLMarketDataField *pMBLMarketData) ;
	virtual void onRtnMBLMarketData(dict data) {};

	virtual void OnRtnQmdInstrumentStatu(CQdFtdcQmdInstrumentStateField *pQmdInstrumentState) ;
	virtual void onRtnQmdInstrumentStatu(dict data) {};

	virtual void OnRspSubscribeTopic(CQdFtdcDisseminationField *pDissemination, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSubscribeTopic(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryTopic(CQdFtdcDisseminationField *pDissemination, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryTopic(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryMarketData(CQdFtdcRspMarketDataField *pRspMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryMarketData(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInstrumentList(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInstrumentList(dict data, dict error, int id, bool last) {};

	virtual void OnRtnTenEntrust(CQdFtdcMDTenDepthMarketDataField *pMDTenDepthMarketData) ;
	virtual void onRtnTenEntrust(dict data) {};

	virtual void OnRtnOptionIndexData(CQdFtdcOptionIndexDataField *pOptionIndexData) ;
	virtual void onRtnOptionIndexData(dict data) {};

	virtual void OnRtnDepthMinMarketData(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData) ;
	virtual void onRtnDepthMinMarketData(dict data) {};

	virtual void OnRspQryMinMarketData(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryMinMarketData(dict data, dict error, int id, bool last) {};

	virtual void OnRtnDepthOneMinBarSlice(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData) ;
	virtual void onRtnDepthOneMinBarSlice(dict data) {};

	virtual void OnRspQryStInstrument(CQdFtdcQryMarketDataField *pQryMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryStInstrument(dict data, dict error, int id, bool last) {};

	virtual void OnRtnTradeMaketData(CQdFtdcDeptTradeMaketDataField *pDeptTradeMaketData) ;
	virtual void onRtnTradeMaketData(dict data) {};

	virtual void OnRtnOrderMaketData(CQdFtdcDeptOrderMaketDataField *pDeptOrderMaketData) ;
	virtual void onRtnOrderMaketData(dict data) {};



	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void createFtdcMdApi(string pszFlowPath = "");

	void release();

	void init();

	int join();

	int exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	void subscribeMarketDataTopic(int topicID, int resumeType);

	int subscribeMarketData(string instrumentID);

	int unSubscribeMarketData(string instrumentID);

	int reqUserLogin(dict req, int nRequestID);

	int reqUserLogout(dict req, int nRequestID);

	int reqSubMarketData(dict req, int nRequestID);

	int reqUnSubMarketData(dict req, int nRequestID);

	int reqSubscribeTopic(dict req, int nRequestID);

	int reqQryTopic(dict req, int nRequestID);

	int reqQryMarketData(dict req, int nRequestID);

	int reqQryInstrumentList(dict req, int nRequestID);

	int reqQryMinMarketData(dict req, int nRequestID);

	int reqQryStInstrument(dict req, int nRequestID);


};
