//说明部分
/*
由于femas API中和资金转账相关的函数太多，
同时也已经有大量的客户端支持这些功能，
因此在这个Python封装中暂时选择只支持交易功能
*/


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
#include "FocusFtdcTraderApi.h"

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
#define ONRSPORDERINSERT 7
#define ONRSPORDERACTION 8
#define ONRTNTRADE 9
#define ONRTNORDER 10
#define ONRTNINSTRUMENTSTATUS 11
#define ONRTNMESSAGENOTIFY 12
#define ONRSPQRYORDER 13
#define ONRSPQRYTRADE 14
#define ONRSPQRYINVESTORACCOUNT 15
#define ONRSPQRYINSTRUMENT 16
#define ONRSPQRYEXCHANGE 17
#define ONRSPQRYINVESTORPOSITION 18
#define ONRSPSUBSCRIBETOPIC 19
#define ONRSPQRYTOPIC 20
#define ONRSPQRYPRODUCT 21
#define ONRTNSTRATEGYLOG 22
#define ONRTNINVESTORPOSITION 23
#define ONRTNPARENTORDER 24
#define ONRTNPARENTORDERACTION 25
#define ONRTNAMENDPARENTORDER 26
#define ONRTNEXTRAMANUALPARENTORDER 27
#define ONRSPQRYMARKETTRADINGTIME 28
#define ONRSPBATCHORDERINSERT 29
#define ONRSPBATCHORDERACTION 30
#define ONRTNSPREADINSTRSTRATEGY 31
#define ONRTNAMENDPSPREADINSTRSTRATEGY 32




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
	mutable mutex the_mutex;							//boost互斥锁
	condition_variable the_condition_variable;			//boost条件变量

public:

	//存入新的任务
	void push(Data const& data)
	{
		mutex::scoped_lock lock(the_mutex);				//获取互斥锁
		the_queue.push(data);							//向队列中存入数据
		lock.unlock();									//释放锁
		the_condition_variable.notify_one();			//通知正在阻塞等待的线程
	}

	//检查队列是否为空
	bool empty() const
	{
		mutex::scoped_lock lock(the_mutex);
		return the_queue.empty();
	}

	//取出
	Data wait_and_pop()
	{
		mutex::scoped_lock lock(the_mutex);

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
class TdApi : public CFocusFtdcTraderSpi
{
private:
	CFocusFtdcTraderApi* api;			//API对象
	thread *task_thread;				//工作线程指针（向python中推送数据）
	ConcurrentQueue<Task> task_queue;	//任务队列

public:
	TdApi()
	{
		function0<void> f = boost::bind(&TdApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~TdApi()
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

	void processRspOrderInsert(Task task);

	void processRspOrderAction(Task task);

	void processRtnTrade(Task task);

	void processRtnOrder(Task task);

	void processRtnInstrumentStatus(Task task);

	void processRtnMessageNotify(Task task);

	void processRspQryOrder(Task task);

	void processRspQryTrade(Task task);

	void processRspQryInvestorAccount(Task task);

	void processRspQryInstrument(Task task);

	void processRspQryExchange(Task task);

	void processRspQryInvestorPosition(Task task);

	void processRspSubscribeTopic(Task task);

	void processRspQryTopic(Task task);

	void processRspQryProduct(Task task);

	void processRtnStrategyLog(Task task);

	void processRtnInvestorPosition(Task task);

	void processRtnParentOrder(Task task);

	void processRtnParentOrderAction(Task task);

	void processRtnAmendParentOrder(Task task);

	void processRtnExtraManualParentOrder(Task task);

	void processRspQryMarketTradingTime(Task task);

	void processRspBatchOrderInsert(Task task);

	void processRspBatchOrderAction(Task task);

	void processRtnSpreadInstrStrategy(Task task);

	void processRtnAmendPSpreadInstrStrategy(Task task);



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

	virtual void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspError(dict error, int id, bool last) {};

	virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUserLogin(dict data, dict error, int id, bool last) {};

	virtual void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUserLogout(dict data, dict error, int id, bool last) {};

	virtual void OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspOrderInsert(dict data, dict error, int id, bool last) {};

	virtual void OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspOrderAction(dict data, dict error, int id, bool last) {};

	virtual void OnRtnTrade(CFocusFtdcTradeField *pTrade) ;
	virtual void onRtnTrade(dict data) {};

	virtual void OnRtnOrder(CFocusFtdcOrderField *pOrder) ;
	virtual void onRtnOrder(dict data) {};

	virtual void OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) ;
	virtual void onRtnInstrumentStatus(dict data) {};

	virtual void OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) ;
	virtual void onRtnMessageNotify(dict data) {};

	virtual void OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryOrder(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryTrade(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInvestorAccount(CFocusFtdcRspInvestorAccountField *pRspInvestorAccount, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInvestorAccount(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInstrument(CFocusFtdcRspInstrumentField *pRspInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInstrument(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryExchange(CFocusFtdcRspExchangeField *pRspExchange, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryExchange(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInvestorPosition(dict data, dict error, int id, bool last) {};

	virtual void OnRspSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSubscribeTopic(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryTopic(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryProduct(dict data, dict error, int id, bool last) {};

	virtual void OnRtnStrategyLog(CFocusFtdcStrategyLogField *pStrategyLog) ;
	virtual void onRtnStrategyLog(dict data) {};

	virtual void OnRtnInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition) ;
	virtual void onRtnInvestorPosition(dict data) {};

	virtual void OnRtnParentOrder(CFocusFtdcParentOrderField *pParentOrder) ;
	virtual void onRtnParentOrder(dict data) {};

	virtual void OnRtnParentOrderAction(CFocusFtdcParentOrderActionField *pParentOrderAction) ;
	virtual void onRtnParentOrderAction(dict data) {};

	virtual void OnRtnAmendParentOrder(CFocusFtdcAmendParentOrderField *pAmendParentOrder) ;
	virtual void onRtnAmendParentOrder(dict data) {};

	virtual void OnRtnExtraManualParentOrder(CFocusFtdcExtraManualParentOrderField *pExtraManualParentOrder) ;
	virtual void onRtnExtraManualParentOrder(dict data) {};

	virtual void OnRspQryMarketTradingTime(CFocusFtdcMarketTradingPeriodInfoField *pMarketTradingPeriodInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryMarketTradingTime(dict data, dict error, int id, bool last) {};

	virtual void OnRspBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspBatchOrderInsert(dict data, dict error, int id, bool last) {};

	virtual void OnRspBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspBatchOrderAction(dict data, dict error, int id, bool last) {};

	virtual void OnRtnSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) ;
	virtual void onRtnSpreadInstrStrategy(dict data) {};

	virtual void OnRtnAmendPSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) ;
	virtual void onRtnAmendPSpreadInstrStrategy(dict data) {};



	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void createFtdcTraderApi(string pszFlowPath = "");

	void release();

	void init();

	int join();

	int exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	void subscribePrivateTopic(int nType);

	void subscribePublicTopic(int nType);

	int reqUserLogin(dict req, int nRequestID);

	int reqUserLogout(dict req, int nRequestID);

	int reqOrderInsert(dict req, int nRequestID);

	int reqOrderAction(dict req, int nRequestID);

	int reqQryOrder(dict req, int nRequestID);

	int reqQryTrade(dict req, int nRequestID);

	int reqQryInvestorAccount(dict req, int nRequestID);

	int reqQryInstrument(dict req, int nRequestID);

	int reqQryExchange(dict req, int nRequestID);

	int reqQryInvestorPosition(dict req, int nRequestID);

	int reqSubscribeTopic(dict req, int nRequestID);

	int reqQryTopic(dict req, int nRequestID);

	int reqQryProduct(dict req, int nRequestID);

	int reqSetParentDetialUpdateMessage(dict req, int nRequestID);

	int reqQryMarketTradingTime(dict req, int nRequestID);

	int reqSetJavaAlgoStatus(dict req, int nRequestID);

	int reqBatchOrderInsert(dict req, int nRequestID);

	int reqBatchOrderAction(dict req, int nRequestID);


};

