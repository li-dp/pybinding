
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
#include "FocusFtdcUserApi.h"

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
#define ONRSPUSERPASSWORDUPDATE 7
#define ONRSPFORCEUSEREXIT 8
#define ONRSPFORCEUSERLOGOUT 9
#define ONRSPDUMPMEMDB 10
#define ONRSPORDERINSERT 11
#define ONRSPORDERACTION 12
#define ONRSPACCOUNTDEPOSIT 13
#define ONRSPINVESTORRIGHT 14
#define ONRSPTBCOMMAND 15
#define ONRSPPINGPONG 16
#define ONRSPSETADVICERUNMODE 17
#define ONRTNDEPTHMARKETDATA 18
#define ONRTNMULTIDEPTHMARKETDATA 19
#define ONRSPSUBMARKETDATA 20
#define ONRSPUNSUBMARKETDATA 21
#define ONRSPTOPICSEARCH 22
#define ONRTNMBLMARKETDATA 23
#define ONRTNQMDINSTRUMENTSTATU 24
#define ONRTNFLOWMESSAGECANCEL 25
#define ONRTNTRADE 26
#define ONRTNORDER 27
#define ONERRRTNORDERINSERT 28
#define ONERRRTNORDERACTION 29
#define ONRTNINSTRUMENTSTATUS 30
#define ONRTNINVESTORACCOUNTDEPOSIT 31
#define ONRTNMESSAGENOTIFY 32
#define ONRTNADVICEORDER 33
#define ONRTNSUBINSTRUMENTSTATUS 34
#define ONRSPQRYORDER 35
#define ONRSPQRYTRADE 36
#define ONRSPQRYUSERINVESTOR 37
#define ONRSPQRYINVESTORACCOUNT 38
#define ONRSPQRYINSTRUMENT 39
#define ONRSPQRYEXCHANGE 40
#define ONRSPQRYINVESTORPOSITION 41
#define ONRSPSUBSCRIBETOPIC 42
#define ONRSPQRYTOPIC 43
#define ONRSPQRYUSER 44
#define ONRSPQRYINVESTORFEE 45
#define ONRSPQRYINVESTORMARGIN 46
#define ONRSPQRYINVESTOR 47
#define ONRSPQRYACCOUNTRISK 48
#define ONRSPQRYUSERSESSION 49
#define ONRSPQRYMARKETDATA 50
#define ONRSPQRYINVESTORRELATION 51
#define ONRSPQRYPRODUCT 52
#define ONRSPQRYADVICETRADER 53
#define ONRSPQRYMAXVOLUME 54
#define ONRSPQRYCMBPOSITIONDETAIL 55
#define ONRSPQRYSETTLEMENTINFO 56
#define ONRSPSUBINSTRUMENT 57
#define ONRSPUNSUBINSTRUMENT 58
#define ONRSPQRYRESULTPAGE 59
#define ONRSPQRYINVESTORPOSITIONDETAIL 60
#define ONRTNTHEORYPRICEDATA 61
#define ONRTNOPTIONINDEXDATA 62
#define ONRSPSETPRICINGPARAM 63
#define ONRSPSETOPTIONTHEORYVOL 64
#define ONRSPCALCONEOPTION 65
#define ONRSPCALCBARRIEROPTION 66
#define ONRSPVOLATILITYFITTING 67
#define ONRSPQRYWINGMODELPARAM 68
#define ONRSPSETWINGMODELPARAM 69
#define ONRTNQUOTETOTALTRADEPRICE 70
#define ONRSPQRYMARKERSTRATEGYSET 71
#define ONRSPUPMARKERSTRATEGYSET 72
#define ONRSPQRYUSERSWITCH 73
#define ONRSPUSERSWITCH 74
#define ONRSPQRYMARKERHEDGE 75
#define ONRSPUPMARKERHEDGE 76
#define ONRSPQRYFITTINGPARAM 77
#define ONRSPSETFITTINGPARAM 78
#define ONRSPQRYPRICINGPARAM 79
#define ONRSPQRYOPTIONTHEORYVOL 80
#define ONRSPQUOTEINSERT 81
#define ONRSPQUOTEACTION 82
#define ONRSPQRYQUOTE 83
#define ONRTNQUOTE 84
#define ONRSPFORQUOTE 85
#define ONRTNFORQUOTE 86
#define ONRSPQRYORDERINSERTFAILED 87
#define ONRSPCLEANQUOTETHRESHOLD 88
#define ONRSPSETPRICESPREAD 89
#define ONRSPQRYPRICESPREAD 90
#define ONRSPDELPRICINGPARAM 91
#define ONRSPDELMARKERSTRATEGYSET 92
#define ONRSPSETALERTPARAM 93
#define ONRSPQRYALERTPARAM 94
#define ONRSPQRYALERTDATA 95
#define ONRTNALERTDATA 96
#define ONRTNSTRATEGYLOG 97
#define ONRTNQUOTETOTALTRADEPOSITION 98
#define ONRSPDELOPTIONTHEORYVOL 99
#define ONRSPDELMARKERHEDGE 100
#define ONRSPSETMARKERSTEP 101
#define ONRSPDELMARKERSTEP 102
#define ONRSPDELALERTPARAM 103
#define ONRSPSETQUOTEMOVE 104
#define ONRSPDELQUOTEMOVE 105
#define ONRSPREBACKQUOTE 106
#define ONRSPQRYDEPMARKETDATA 107
#define ONRSPQRYQUOTEMOVE 108
#define ONRSPQRYBASEMARKERSTEP 109
#define ONRSPQRYMARKERSTEP 110
#define ONRSPFOCUSSTATUS 111
#define ONRTNATMPRICEDATA 112
#define ONRSPSETFUTUREMAKERWHOLESWITCH 113
#define ONRSPSETFUTUREMAKERSTRATEGY 114
#define ONRSPSETSLEFHEDGESTRATEGY 115
#define ONRSPSETFUTUREHEDGESTRATEGY 116
#define ONRSPSETQUOTEADDITIONPARM 117
#define ONRTNMARKERSTRATEGYCHANGE 118
#define ONRSPSTOPALLFUTUREMAKERHEDGEOFFER 119
#define ONRTNFUTUREMAKERHEDGESTATUS 120
#define ONRTNINVESTORPOSITION 121
#define ONRSPQRYFUTUREMAKERSTRATEGY 122
#define ONRSPQRYALLINNERHIGHSTOCKSTRATEGY 123
#define ONRTNINNERHIGHSTOCKSTRATEGY 124
#define ONRSPSETHIGHSTOCKSTRATEGYSWITCH 125
#define ONRSPQRYAPIHIGHSTOCKSTRATEGY 126
#define ONRSPQRYSIGNALPIHIGHSTOCKSTRATEGY 127
#define ONRSPSETSIGNALHIGHSTOCKSTRATEGYSWITCH 128
#define ONRSPSETHIGHSTOCKSTRATEGYRELATIONPARAM 129
#define ONRTNHIGHINNERFUTURESTRATEGYRELATION 130
#define ONRSPQRYALLSTRATEGYRELATION 131
#define ONRSPSETAPIHIGHSTOCKSTRATEGYPARAM 132
#define ONRSPDELHIGHSTOCKSTRATEGYRELATIONPARAM 133
#define ONRSPDELAPIHIGHSTOCKSTRATEGYPARAM 134
#define ONRSPQRYALLTRADINGPERIODSTRATEGY 135
#define ONRSPSETTRADINGPERIODSTRATEGY 136
#define ONRSPDELTRADINGPERIODSTRATEGY 137
#define ONRSPQRYALLINNERSTRATEGYRELATION 138
#define ONRSPCANCELALLSTRATEGYRELATIONORDER 139
#define ONRSPSETAUTOREBUYSWITCH 140
#define ONRSPSENDFUTURESTRATEGYORDER 141
#define ONRSPSETALGOPARM 142
#define ONRTNINNERFUTURESTRATEGYORDER 143
#define ONRSPQRYALGOPARM 144
#define ONRSPQRYFUTURESTRATEGYORDER 145
#define ONRSPQRYINNERFUTURESTRATEGYORDER 146
#define ONRSPSETSTRAGEDYMESSAGE 147
#define ONRSPQRYINDEXDIRSIGNAL 148
#define ONRSPDELFUTURESTRATEGYORDER 149
#define ONRSPDELALGOPARM 150
#define ONRSPSETSPREADINSTRSTRATEGY 151
#define ONRSPQRYSPREADINSTRSTRATEGY 152
#define ONRSPDELSPREADINSTRSTRATEGY 153
#define ONRSPQRYINNERSPREADINSTRSTRATEGY 154
#define ONRTNINNERSPREADINSTRSTRATEGY 155
#define ONRSPSETTZEROHIGHSTOCKSTRATEGY 156
#define ONRSPQRYTZEROHIGHSTOCKSTRATEGY 157
#define ONRTNSTRAGEDYMESSAGE 158
#define ONRSPSETFUTRUETRADEINSTR 159
#define ONRSPQRYFLOWERFUTURETARGETMONEY 160
#define ONRSPSETFLOWERFUTURETARGETMONEY 161
#define ONRTNPARENTORDER 162
#define ONRTNPARENTORDERACTION 163
#define ONRTNAMENDPARENTORDER 164
#define ONRTNEXTRAMANUALPARENTORDER 165
#define ONRSPQRYMARKETTRADINGTIME 166
#define ONRSPSETFUTURESTRATEGYTOTALSECONDRELATIONPARAM 167
#define ONRTNHIGHINNERFUTURESTRATEGYTOTALSECONDRELATION 168
#define ONRSPQRYALLTOTALSECONDSTRATEGYRELATION 169
#define ONRSPDELHIGHSTOCKSTRATEGYTOTALSECONDRELATIONPARAM 170
#define ONRSPQRYALLINNERTOTALSECONDSTRATEGYRELATION 171
#define ONRSPQRYPARENTDETIALUPDATEMESSAGE 172
#define ONRSPQRYPARENTORDERSTATICPARAM 173
#define ONRTNPARENTDETIALUPDATEMESSAGE 174
#define ONRSPSETPARENTORDERSTATICPARAM 175
#define ONRSPDELPARENTORDERSTATICPARAM 176
#define ONRSPQRYJAVAALGOSTATUS 177
#define ONRTNJAVAALGOSTATUS 178
#define ONRSPQRYFUSKACCOUNTRELATION 179
#define ONRSPBATCHORDERINSERT 180
#define ONRSPBATCHORDERACTION 181
#define ONRSPSETUSERINVESTORSEATBASEPASSWD 182
#define ONRTNSPREADINSTRSTRATEGY 183
#define ONRTNAMENDPSPREADINSTRSTRATEGY 184
#define ONRSPQRYUNFINSHPUTUREORDER 185
#define ONRSPQRYTODAYTAYOUTDETAILS 186




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
class UserApi : public CFocusFtdcUserSpi
{
private:
	CFocusFtdcUserApi* api;			//API对象
	thread *task_thread;				//工作线程指针（向python中推送数据）
	ConcurrentQueue<Task> task_queue;	//任务队列

public:
	UserApi()
	{
		function0<void> f = boost::bind(&UserApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~UserApi()
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

	void processRspUserPasswordUpdate(Task task);

	void processRspForceUserExit(Task task);

	void processRspForceUserLogout(Task task);

	void processRspDumpMemDB(Task task);

	void processRspOrderInsert(Task task);

	void processRspOrderAction(Task task);

	void processRspAccountDeposit(Task task);

	void processRspInvestorRight(Task task);

	void processRspTBCommand(Task task);

	void processRspPingPong(Task task);

	void processRspSetAdviceRunMode(Task task);

	void processRtnDepthMarketData(Task task);

	void processRtnMultiDepthMarketData(Task task);

	void processRspSubMarketData(Task task);

	void processRspUnSubMarketData(Task task);

	void processRspTopicSearch(Task task);

	void processRtnMBLMarketData(Task task);

	void processRtnQmdInstrumentStatu(Task task);

	void processRtnFlowMessageCancel(Task task);

	void processRtnTrade(Task task);

	void processRtnOrder(Task task);

	void processErrRtnOrderInsert(Task task);

	void processErrRtnOrderAction(Task task);

	void processRtnInstrumentStatus(Task task);

	void processRtnInvestorAccountDeposit(Task task);

	void processRtnMessageNotify(Task task);

	void processRtnAdviceOrder(Task task);

	void processRtnSubInstrumentStatus(Task task);

	void processRspQryOrder(Task task);

	void processRspQryTrade(Task task);

	void processRspQryUserInvestor(Task task);

	void processRspQryInvestorAccount(Task task);

	void processRspQryInstrument(Task task);

	void processRspQryExchange(Task task);

	void processRspQryInvestorPosition(Task task);

	void processRspSubscribeTopic(Task task);

	void processRspQryTopic(Task task);

	void processRspQryUser(Task task);

	void processRspQryInvestorFee(Task task);

	void processRspQryInvestorMargin(Task task);

	void processRspQryInvestor(Task task);

	void processRspQryAccountRisk(Task task);

	void processRspQryUserSession(Task task);

	void processRspQryMarketData(Task task);

	void processRspQryInvestorRelation(Task task);

	void processRspQryProduct(Task task);

	void processRspQryAdviceTrader(Task task);

	void processRspQryMaxVolume(Task task);

	void processRspQryCmbPositionDetail(Task task);

	void processRspQrySettlementInfo(Task task);

	void processRspSubInstrument(Task task);

	void processRspUnSubInstrument(Task task);

	void processRspQryResultPage(Task task);

	void processRspQryInvestorPositionDetail(Task task);

	void processRtnTheoryPriceData(Task task);

	void processRtnOptionIndexData(Task task);

	void processRspSetPricingParam(Task task);

	void processRspSetOptionTheoryVol(Task task);

	void processRspCalcOneOption(Task task);

	void processRspCalcBarrierOption(Task task);

	void processRspVolatilityFitting(Task task);

	void processRspQryWingModelParam(Task task);

	void processRspSetWingModelParam(Task task);

	void processRtnQuoteTotalTradePrice(Task task);

	void processRspQryMarkerStrategySet(Task task);

	void processRspUpMarkerStrategySet(Task task);

	void processRspQryUserSwitch(Task task);

	void processRspUserSwitch(Task task);

	void processRspQryMarkerHedge(Task task);

	void processRspUpMarkerHedge(Task task);

	void processRspQryFittingParam(Task task);

	void processRspSetFittingParam(Task task);

	void processRspQryPricingParam(Task task);

	void processRspQryOptionTheoryVol(Task task);

	void processRspQuoteInsert(Task task);

	void processRspQuoteAction(Task task);

	void processRspQryQuote(Task task);

	void processRtnQuote(Task task);

	void processRspForQuote(Task task);

	void processRtnForQuote(Task task);

	void processRspQryOrderInsertFailed(Task task);

	void processRspCleanQuoteThresHold(Task task);

	void processRspSetPriceSpread(Task task);

	void processRspQryPriceSpread(Task task);

	void processRspDelPricingParam(Task task);

	void processRspDelMarkerStrategySet(Task task);

	void processRspSetAlertParam(Task task);

	void processRspQryAlertParam(Task task);

	void processRspQryAlertData(Task task);

	void processRtnAlertData(Task task);

	void processRtnStrategyLog(Task task);

	void processRtnQuoteTotalTradePosition(Task task);

	void processRspDelOptionTheoryVol(Task task);

	void processRspDelMarkerHedge(Task task);

	void processRspSetMarkerStep(Task task);

	void processRspDelMarkerStep(Task task);

	void processRspDelAlertParam(Task task);

	void processRspSetQuoteMove(Task task);

	void processRspDelQuoteMove(Task task);

	void processRspRebackQuote(Task task);

	void processRspQryDepMarketData(Task task);

	void processRspQryQuoteMove(Task task);

	void processRspQryBaseMarkerStep(Task task);

	void processRspQryMarkerStep(Task task);

	void processRspFocusStatus(Task task);

	void processRtnATMPriceData(Task task);

	void processRspSetFutureMakerWholeSwitch(Task task);

	void processRspSetFutureMakerStrategy(Task task);

	void processRspSetSlefHedgeStrategy(Task task);

	void processRspSetFutureHedgeStrategy(Task task);

	void processRspSetQuoteAdditionParm(Task task);

	void processRtnMarkerStrategyChange(Task task);

	void processRspStopAllFutureMakerHedgeOffer(Task task);

	void processRtnFutureMakerHedgeStatus(Task task);

	void processRtnInvestorPosition(Task task);

	void processRspQryFutureMakerStrategy(Task task);

	void processRspQryAllInnerHighStockStrategy(Task task);

	void processRtnInnerHighStockStrategy(Task task);

	void processRspSetHighStockStrategySwitch(Task task);

	void processRspQryAPIHighStockStrategy(Task task);

	void processRspQrySignalPIHighStockStrategy(Task task);

	void processRspSetSignalHighStockStrategySwitch(Task task);

	void processRspSetHighStockStrategyRelationParam(Task task);

	void processRtnHighInnerFutureStrategyRelation(Task task);

	void processRspQryAllStrategyRelation(Task task);

	void processRspSetAPIHighStockStrategyParam(Task task);

	void processRspDelHighStockStrategyRelationParam(Task task);

	void processRspDelAPIHighStockStrategyParam(Task task);

	void processRspQryAllTradingPeriodStrategy(Task task);

	void processRspSetTradingPeriodStrategy(Task task);

	void processRspDelTradingPeriodStrategy(Task task);

	void processRspQryAllInnerStrategyRelation(Task task);

	void processRspCancelAllStrategyRelationOrder(Task task);

	void processRspSetAutoReBuySwitch(Task task);

	void processRspSendFutureStrategyOrder(Task task);

	void processRspSetAlgoParm(Task task);

	void processRtnInnerFutureStrategyOrder(Task task);

	void processRspQryAlgoParm(Task task);

	void processRspQryFutureStrategyOrder(Task task);

	void processRspQryInnerFutureStrategyOrder(Task task);

	void processRspSetStragedyMessage(Task task);

	void processRspQryIndexDirSignal(Task task);

	void processRspDelFutureStrategyOrder(Task task);

	void processRspDelAlgoParm(Task task);

	void processRspSetSpreadInstrStrategy(Task task);

	void processRspQrySpreadInstrStrategy(Task task);

	void processRspDelSpreadInstrStrategy(Task task);

	void processRspQryInnerSpreadInstrStrategy(Task task);

	void processRtnInnerSpreadInstrStrategy(Task task);

	void processRspSetTZeroHighStockStrategy(Task task);

	void processRspQryTZeroHighStockStrategy(Task task);

	void processRtnStragedyMessage(Task task);

	void processRspSetfutruetradeinstr(Task task);

	void processRspQryFlowerFutureTargetMoney(Task task);

	void processRspSetFlowerFutureTargetMoney(Task task);

	void processRtnParentOrder(Task task);

	void processRtnParentOrderAction(Task task);

	void processRtnAmendParentOrder(Task task);

	void processRtnExtraManualParentOrder(Task task);

	void processRspQryMarketTradingTime(Task task);

	void processRspSetFutureStrategyTotalSecondRelationParam(Task task);

	void processRtnHighInnerFutureStrategyTotalSecondRelation(Task task);

	void processRspQryAllTotalSecondStrategyRelation(Task task);

	void processRspDelHighStockStrategyTotalSecondRelationParam(Task task);

	void processRspQryAllInnerTotalSecondStrategyRelation(Task task);

	void processRspQryParentDetialUpdateMessage(Task task);

	void processRspQryParentOrderStaticParam(Task task);

	void processRtnParentDetialUpdateMessage(Task task);

	void processRspSetParentOrderStaticParam(Task task);

	void processRspDelParentOrderStaticParam(Task task);

	void processRspQryJavaAlgoStatus(Task task);

	void processRtnJavaAlgoStatus(Task task);

	void processRspQryFuSkAccountRelation(Task task);

	void processRspBatchOrderInsert(Task task);

	void processRspBatchOrderAction(Task task);

	void processRspSetUserInvestorSeatBasePasswd(Task task);

	void processRtnSpreadInstrStrategy(Task task);

	void processRtnAmendPSpreadInstrStrategy(Task task);

	void processRspQryUnFinshPutureOrder(Task task);

	void processRspQryTodayTayoutDetails(Task task);



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

	virtual void OnRspUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUserPasswordUpdate(dict data, dict error, int id, bool last) {};

	virtual void OnRspForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspForceUserExit(dict data, dict error, int id, bool last) {};

	virtual void OnRspForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspForceUserLogout(dict data, dict error, int id, bool last) {};

	virtual void OnRspDumpMemDB(CFocusFtdcMemDBField *pMemDB, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDumpMemDB(dict data, dict error, int id, bool last) {};

	virtual void OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspOrderInsert(dict data, dict error, int id, bool last) {};

	virtual void OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspOrderAction(dict data, dict error, int id, bool last) {};

	virtual void OnRspAccountDeposit(CFocusFtdcRspAccountDepositField *pRspAccountDeposit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspAccountDeposit(dict data, dict error, int id, bool last) {};

	virtual void OnRspInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspInvestorRight(dict data, dict error, int id, bool last) {};

	virtual void OnRspTBCommand(CFocusFtdcTBCommandField *pTBCommand, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspTBCommand(dict data, dict error, int id, bool last) {};

	virtual void OnRspPingPong(CFocusFtdcPingPongField *pPingPong, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspPingPong(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetAdviceRunMode(dict data, dict error, int id, bool last) {};

	virtual void OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) ;
	virtual void onRtnDepthMarketData(dict data) {};

	virtual void OnRtnMultiDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) ;
	virtual void onRtnMultiDepthMarketData(dict data) {};

	virtual void OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSubMarketData(dict data, dict error, int id, bool last) {};

	virtual void OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUnSubMarketData(dict data, dict error, int id, bool last) {};

	virtual void OnRspTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspTopicSearch(dict data, dict error, int id, bool last) {};

	virtual void OnRtnMBLMarketData(CFocusFtdcMBLMarketDataField *pMBLMarketData) ;
	virtual void onRtnMBLMarketData(dict data) {};

	virtual void OnRtnQmdInstrumentStatu(CFocusFtdcQmdInstrumentStateField *pQmdInstrumentState) ;
	virtual void onRtnQmdInstrumentStatu(dict data) {};

	virtual void OnRtnFlowMessageCancel(CFocusFtdcFlowMessageCancelField *pFlowMessageCancel) ;
	virtual void onRtnFlowMessageCancel(dict data) {};

	virtual void OnRtnTrade(CFocusFtdcTradeField *pTrade) ;
	virtual void onRtnTrade(dict data) {};

	virtual void OnRtnOrder(CFocusFtdcOrderField *pOrder) ;
	virtual void onRtnOrder(dict data) {};

	virtual void OnErrRtnOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo) ;
	virtual void onErrRtnOrderInsert(dict data, dict error) {};

	virtual void OnErrRtnOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo) ;
	virtual void onErrRtnOrderAction(dict data, dict error) {};

	virtual void OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) ;
	virtual void onRtnInstrumentStatus(dict data) {};

	virtual void OnRtnInvestorAccountDeposit(CFocusFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) ;
	virtual void onRtnInvestorAccountDeposit(dict data) {};

	virtual void OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) ;
	virtual void onRtnMessageNotify(dict data) {};

	virtual void OnRtnAdviceOrder(CFocusFtdcAdviceOrderField *pAdviceOrder) ;
	virtual void onRtnAdviceOrder(dict data) {};

	virtual void OnRtnSubInstrumentStatus(CFocusFtdcSubInstrumentStatusField *pSubInstrumentStatus) ;
	virtual void onRtnSubInstrumentStatus(dict data) {};

	virtual void OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryOrder(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryTrade(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryUserInvestor(CFocusFtdcRspUserInvestorField *pRspUserInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryUserInvestor(dict data, dict error, int id, bool last) {};

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

	virtual void OnRspQryUser(CFocusFtdcRspUserField *pRspUser, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryUser(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInvestorFee(CFocusFtdcRspInvestorFeeField *pRspInvestorFee, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInvestorFee(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInvestorMargin(CFocusFtdcRspInvestorMarginField *pRspInvestorMargin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInvestorMargin(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInvestor(CFocusFtdcRspInvestorField *pRspInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInvestor(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAccountRisk(CFocusFtdcRspAccountRiskField *pRspAccountRisk, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAccountRisk(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryUserSession(CFocusFtdcRspUserSessionField *pRspUserSession, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryUserSession(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryMarketData(CFocusFtdcRspMarketDataField *pRspMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryMarketData(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInvestorRelation(CFocusFtdcRspInvestorRelationField *pRspInvestorRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInvestorRelation(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryProduct(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAdviceTrader(CFocusFtdcRspAdviceTraderField *pRspAdviceTrader, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAdviceTrader(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryMaxVolume(CFocusFtdcRspMaxVolumeField *pRspMaxVolume, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryMaxVolume(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryCmbPositionDetail(CFocusFtdcRspCmbPositionDetailField *pRspCmbPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryCmbPositionDetail(dict data, dict error, int id, bool last) {};

	virtual void OnRspQrySettlementInfo(CFocusFtdcRspSettlementInfoField *pRspSettlementInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQrySettlementInfo(dict data, dict error, int id, bool last) {};

	virtual void OnRspSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSubInstrument(dict data, dict error, int id, bool last) {};

	virtual void OnRspUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUnSubInstrument(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryResultPage(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInvestorPositionDetail(CFocusFtdcRspPositionDetailField *pRspPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInvestorPositionDetail(dict data, dict error, int id, bool last) {};

	virtual void OnRtnTheoryPriceData(CFocusFtdcTheoryPriceDataField *pTheoryPriceData) ;
	virtual void onRtnTheoryPriceData(dict data) {};

	virtual void OnRtnOptionIndexData(CFocusFtdcOptionIndexDataField *pOptionIndexData) ;
	virtual void onRtnOptionIndexData(dict data) {};

	virtual void OnRspSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetPricingParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetOptionTheoryVol(dict data, dict error, int id, bool last) {};

	virtual void OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspCalcOneOption(dict data, dict error, int id, bool last) {};

	virtual void OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspCalcBarrierOption(dict data, dict error, int id, bool last) {};

	virtual void OnRspVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspVolatilityFitting(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryWingModelParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetWingModelParam(dict data, dict error, int id, bool last) {};

	virtual void OnRtnQuoteTotalTradePrice(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice) ;
	virtual void onRtnQuoteTotalTradePrice(dict data) {};

	virtual void OnRspQryMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryMarkerStrategySet(dict data, dict error, int id, bool last) {};

	virtual void OnRspUpMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUpMarkerStrategySet(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryUserSwitch(dict data, dict error, int id, bool last) {};

	virtual void OnRspUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUserSwitch(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryMarkerHedge(dict data, dict error, int id, bool last) {};

	virtual void OnRspUpMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspUpMarkerHedge(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryFittingParam(CFocusFtdcFittingParamField *pFittingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryFittingParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetFittingParam(CFocusFtdcFittingParamField *pFittingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetFittingParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryPricingParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryOptionTheoryVol(dict data, dict error, int id, bool last) {};

	virtual void OnRspQuoteInsert(CFocusFtdcInputQuoteField *pInputQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQuoteInsert(dict data, dict error, int id, bool last) {};

	virtual void OnRspQuoteAction(CFocusFtdcQuoteActionField *pQuoteAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQuoteAction(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryQuote(CFocusFtdcQuoteField *pQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryQuote(dict data, dict error, int id, bool last) {};

	virtual void OnRtnQuote(CFocusFtdcQuoteField *pQuote) ;
	virtual void onRtnQuote(dict data) {};

	virtual void OnRspForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspForQuote(dict data, dict error, int id, bool last) {};

	virtual void OnRtnForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote) ;
	virtual void onRtnForQuote(dict data) {};

	virtual void OnRspQryOrderInsertFailed(CFocusFtdcOrderInsertFailedField *pOrderInsertFailed, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryOrderInsertFailed(dict data, dict error, int id, bool last) {};

	virtual void OnRspCleanQuoteThresHold(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspCleanQuoteThresHold(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetPriceSpread(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryPriceSpread(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelPricingParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelMarkerStrategySet(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetAlertParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAlertParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAlertData(CFocusFtdcAlertIndexSetDataField *pAlertIndexSetData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAlertData(dict data, dict error, int id, bool last) {};

	virtual void OnRtnAlertData(CFocusFtdcAlertIndexSetDataField *pAlertIndexSetData) ;
	virtual void onRtnAlertData(dict data) {};

	virtual void OnRtnStrategyLog(CFocusFtdcStrategyLogField *pStrategyLog) ;
	virtual void onRtnStrategyLog(dict data) {};

	virtual void OnRtnQuoteTotalTradePosition(CFocusFtdcQuoteTotalTradePositionField *pQuoteTotalTradePosition) ;
	virtual void onRtnQuoteTotalTradePosition(dict data) {};

	virtual void OnRspDelOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelOptionTheoryVol(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelMarkerHedge(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetMarkerStep(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelMarkerStep(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelAlertParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetQuoteMove(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelQuoteMove(dict data, dict error, int id, bool last) {};

	virtual void OnRspRebackQuote(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspRebackQuote(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryDepMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryDepMarketData(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryQuoteMove(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryBaseMarkerStep(CFocusFtdcBaseMarkerStepField *pBaseMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryBaseMarkerStep(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryMarkerStep(dict data, dict error, int id, bool last) {};

	virtual void OnRspFocusStatus(CFocusFtdcFocusStatusField *pFocusStatus, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspFocusStatus(dict data, dict error, int id, bool last) {};

	virtual void OnRtnATMPriceData(CFocusFtdcATMPriceDataField *pATMPriceData) ;
	virtual void onRtnATMPriceData(dict data) {};

	virtual void OnRspSetFutureMakerWholeSwitch(CFocusFtdcFutureMakerWholeSwitchField *pFutureMakerWholeSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetFutureMakerWholeSwitch(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetFutureMakerStrategy(CFocusFtdcFutureMakerStrategyField *pFutureMakerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetFutureMakerStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetSlefHedgeStrategy(CFocusFtdcSlefHedgeStrategyField *pSlefHedgeStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetSlefHedgeStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetFutureHedgeStrategy(CFocusFtdcFutureHedgeStrategyField *pFutureHedgeStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetFutureHedgeStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetQuoteAdditionParm(CFocusFtdcQuoteAdditionParmField *pQuoteAdditionParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetQuoteAdditionParm(dict data, dict error, int id, bool last) {};

	virtual void OnRtnMarkerStrategyChange(CFocusFtdcMarkerStrategyField *pMarkerStrategy) ;
	virtual void onRtnMarkerStrategyChange(dict data) {};

	virtual void OnRspStopAllFutureMakerHedgeOffer(CFocusFtdcStopAllFutureMakerHedgeOfferField *pStopAllFutureMakerHedgeOffer, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspStopAllFutureMakerHedgeOffer(dict data, dict error, int id, bool last) {};

	virtual void OnRtnFutureMakerHedgeStatus(CFocusFtdcFutureMakerHedgeStatusField *pFutureMakerHedgeStatus) ;
	virtual void onRtnFutureMakerHedgeStatus(dict data) {};

	virtual void OnRtnInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition) ;
	virtual void onRtnInvestorPosition(dict data) {};

	virtual void OnRspQryFutureMakerStrategy(CFocusFtdcAllFutureMakerStrategyField *pAllFutureMakerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryFutureMakerStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAllInnerHighStockStrategy(CFocusFtdcInnerHighStockStrategyField *pInnerHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAllInnerHighStockStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRtnInnerHighStockStrategy(CFocusFtdcInnerHighStockStrategyField *pInnerHighStockStrategy) ;
	virtual void onRtnInnerHighStockStrategy(dict data) {};

	virtual void OnRspSetHighStockStrategySwitch(CFocusFtdcWholeHighStockStrategySwitchField *pWholeHighStockStrategySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetHighStockStrategySwitch(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAPIHighStockStrategy(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAPIHighStockStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspQrySignalPIHighStockStrategy(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQrySignalPIHighStockStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetSignalHighStockStrategySwitch(CFocusFtdcSignalHighStockStrategySwitchField *pSignalHighStockStrategySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetSignalHighStockStrategySwitch(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetHighStockStrategyRelationParam(dict data, dict error, int id, bool last) {};

	virtual void OnRtnHighInnerFutureStrategyRelation(CFocusFtdcHighInnerFutureStrategyRelationField *pHighInnerFutureStrategyRelation) ;
	virtual void onRtnHighInnerFutureStrategyRelation(dict data) {};

	virtual void OnRspQryAllStrategyRelation(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAllStrategyRelation(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetAPIHighStockStrategyParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelHighStockStrategyRelationParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelAPIHighStockStrategyParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAllTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAllTradingPeriodStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetTradingPeriodStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelTradingPeriodStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAllInnerStrategyRelation(CFocusFtdcHighInnerFutureStrategyRelationField *pHighInnerFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAllInnerStrategyRelation(dict data, dict error, int id, bool last) {};

	virtual void OnRspCancelAllStrategyRelationOrder(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspCancelAllStrategyRelationOrder(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetAutoReBuySwitch(CFocusFtdcRelationAutoReBuySwitchField *pRelationAutoReBuySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetAutoReBuySwitch(dict data, dict error, int id, bool last) {};

	virtual void OnRspSendFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSendFutureStrategyOrder(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetAlgoParm(dict data, dict error, int id, bool last) {};

	virtual void OnRtnInnerFutureStrategyOrder(CFocusFtdcInnerFutureStrategyOrderField *pInnerFutureStrategyOrder) ;
	virtual void onRtnInnerFutureStrategyOrder(dict data) {};

	virtual void OnRspQryAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAlgoParm(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryFutureStrategyOrder(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInnerFutureStrategyOrder(CFocusFtdcInnerFutureStrategyOrderField *pInnerFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInnerFutureStrategyOrder(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetStragedyMessage(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryIndexDirSignal(CFocusFtdcIndexDirSignalField *pIndexDirSignal, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryIndexDirSignal(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelFutureStrategyOrder(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelAlgoParm(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelAlgoParm(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetSpreadInstrStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspQrySpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQrySpreadInstrStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelSpreadInstrStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryInnerSpreadInstrStrategy(CFocusFtdcInnerSpreadInstrStrategyField *pInnerSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryInnerSpreadInstrStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRtnInnerSpreadInstrStrategy(CFocusFtdcInnerSpreadInstrStrategyField *pInnerSpreadInstrStrategy) ;
	virtual void onRtnInnerSpreadInstrStrategy(dict data) {};

	virtual void OnRspSetTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetTZeroHighStockStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryTZeroHighStockStrategy(dict data, dict error, int id, bool last) {};

	virtual void OnRtnStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal) ;
	virtual void onRtnStragedyMessage(dict data) {};

	virtual void OnRspSetfutruetradeinstr(CFocusFtdcQryInstrumentField *pQryInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetfutruetradeinstr(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryFlowerFutureTargetMoney(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetFlowerFutureTargetMoney(dict data, dict error, int id, bool last) {};

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

	virtual void OnRspSetFutureStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetFutureStrategyTotalSecondRelationParam(dict data, dict error, int id, bool last) {};

	virtual void OnRtnHighInnerFutureStrategyTotalSecondRelation(CFocusFtdcInnerFutureStrategyTotalSecondRelationField *pInnerFutureStrategyTotalSecondRelation) ;
	virtual void onRtnHighInnerFutureStrategyTotalSecondRelation(dict data) {};

	virtual void OnRspQryAllTotalSecondStrategyRelation(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAllTotalSecondStrategyRelation(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelHighStockStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelHighStockStrategyTotalSecondRelationParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryAllInnerTotalSecondStrategyRelation(CFocusFtdcInnerFutureStrategyTotalSecondRelationField *pInnerFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryAllInnerTotalSecondStrategyRelation(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryParentDetialUpdateMessage(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryParentOrderStaticParam(dict data, dict error, int id, bool last) {};

	virtual void OnRtnParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage) ;
	virtual void onRtnParentDetialUpdateMessage(dict data) {};

	virtual void OnRspSetParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetParentOrderStaticParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspDelParentOrderStaticParam(CFocusFtdcParentOrderIndexField *pParentOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspDelParentOrderStaticParam(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryJavaAlgoStatus(dict data, dict error, int id, bool last) {};

	virtual void OnRtnJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus) ;
	virtual void onRtnJavaAlgoStatus(dict data) {};

	virtual void OnRspQryFuSkAccountRelation(CFocusFtdcFuSkAccountRelationField *pFuSkAccountRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryFuSkAccountRelation(dict data, dict error, int id, bool last) {};

	virtual void OnRspBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspBatchOrderInsert(dict data, dict error, int id, bool last) {};

	virtual void OnRspBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspBatchOrderAction(dict data, dict error, int id, bool last) {};

	virtual void OnRspSetUserInvestorSeatBasePasswd(CFocusFtdcUserInvestorSeatBaseField *pUserInvestorSeatBase, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspSetUserInvestorSeatBasePasswd(dict data, dict error, int id, bool last) {};

	virtual void OnRtnSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) ;
	virtual void onRtnSpreadInstrStrategy(dict data) {};

	virtual void OnRtnAmendPSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) ;
	virtual void onRtnAmendPSpreadInstrStrategy(dict data) {};

	virtual void OnRspQryUnFinshPutureOrder(CFocusFtdcUnFinshPutureOrderField *pUnFinshPutureOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryUnFinshPutureOrder(dict data, dict error, int id, bool last) {};

	virtual void OnRspQryTodayTayoutDetails(CFocusFtdcTodayTayoutDetailsField *pTodayTayoutDetails, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	virtual void onRspQryTodayTayoutDetails(dict data, dict error, int id, bool last) {};



	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void createFtdcUserApi(string pszFlowPath = "");

	void release();

	void init(int nPrivatePort);

	int join();

	int exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	void subscribePrivateTopic(int nType);

	void subscribePublicTopic(int nType);

	int reqUserLogin(dict req, int nRequestID);

	int reqUserLogout(dict req, int nRequestID);

	int reqUserPasswordUpdate(dict req, int nRequestID);

	int reqForceUserExit(dict req, int nRequestID);

	int reqForceUserLogout(dict req, int nRequestID);

	int reqDumpMemDB(dict req, int nRequestID);

	int reqOrderInsert(dict req, int nRequestID);

	int reqOrderAction(dict req, int nRequestID);

	int reqAccountDeposit(dict req, int nRequestID);

	int reqInvestorRight(dict req, int nRequestID);

	int reqTBCommand(dict req, int nRequestID);

	int reqPingPong(dict req, int nRequestID);

	int reqSetAdviceRunMode(dict req, int nRequestID);

	int reqSubMarketData(dict req, int nRequestID);

	int reqUnSubMarketData(dict req, int nRequestID);

	int reqTopicSearch(dict req, int nRequestID);

	int reqQryOrder(dict req, int nRequestID);

	int reqQryTrade(dict req, int nRequestID);

	int reqQryUserInvestor(dict req, int nRequestID);

	int reqQryInvestorAccount(dict req, int nRequestID);

	int reqQryInstrument(dict req, int nRequestID);

	int reqQryExchange(dict req, int nRequestID);

	int reqQryInvestorPosition(dict req, int nRequestID);

	int reqSubscribeTopic(dict req, int nRequestID);

	int reqQryTopic(dict req, int nRequestID);

	int reqQryUser(dict req, int nRequestID);

	int reqQryInvestorFee(dict req, int nRequestID);

	int reqQryInvestorMargin(dict req, int nRequestID);

	int reqQryInvestor(dict req, int nRequestID);

	int reqQryAccountRisk(dict req, int nRequestID);

	int reqQryUserSession(dict req, int nRequestID);

	int reqQryMarketData(dict req, int nRequestID);

	int reqQryInvestorRelation(dict req, int nRequestID);

	int reqQryProduct(dict req, int nRequestID);

	int reqQryAdviceTrader(dict req, int nRequestID);

	int reqQryMaxVolume(dict req, int nRequestID);

	int reqQryCmbPositionDetail(dict req, int nRequestID);

	int reqQrySettlementInfo(dict req, int nRequestID);

	int reqSubInstrument(dict req, int nRequestID);

	int reqUnSubInstrument(dict req, int nRequestID);

	int reqQryResultPage(dict req, int nRequestID);

	int reqQryOrderPage(dict req, int nRequestID);

	int reqQryTradePage(dict req, int nRequestID);

	int reqQryInvestorPositionPage(dict req, int nRequestID);

	int reqQryInvestorPositionDetail(dict req, int nRequestID);

	int reqSetPricingParam(dict req, int nRequestID);

	int reqSetOptionTheoryVol(dict req, int nRequestID);

	int reqCalcOneOption(dict req, int nRequestID);

	int reqCalcBarrierOption(dict req, int nRequestID);

	int reqMarketDataTest(dict req, int nRequestID);

	int reqVolatilityFitting(dict req, int nRequestID);

	int reqQryWingModelParam(dict req, int nRequestID);

	int reqSetWingModelParam(dict req, int nRequestID);

	int reqQryMarkerStrategySet(dict req, int nRequestID);

	int reqUpMarkerStrategySet(dict req, int nRequestID);

	int reqQryUserSwitch(dict req, int nRequestID);

	int reqUserSwitch(dict req, int nRequestID);

	int reqQryMarkerHedge(dict req, int nRequestID);

	int reqUpMarkerHedge(dict req, int nRequestID);

	int reqQryFittingParam(dict req, int nRequestID);

	int reqSetFittingParam(dict req, int nRequestID);

	int reqQryPricingParam(dict req, int nRequestID);

	int reqQryOptionTheoryVol(dict req, int nRequestID);

	int reqQuoteInsert(dict req, int nRequestID);

	int reqQuoteAction(dict req, int nRequestID);

	int reqQryQuote(dict req, int nRequestID);

	int reqForQuote(dict req, int nRequestID);

	int reqQryOrderInsertFailed(dict req, int nRequestID);

	int reqCleanQuoteThresHold(dict req, int nRequestID);

	int reqSetPriceSpread(dict req, int nRequestID);

	int reqQryPriceSpread(dict req, int nRequestID);

	int reqDelPricingParam(dict req, int nRequestID);

	int reqDelMarkerStrategySet(dict req, int nRequestID);

	int reqSetAlertParam(dict req, int nRequestID);

	int reqQryAlertParam(dict req, int nRequestID);

	int reqQryAlertData(dict req, int nRequestID);

	int reqDelOptionTheoryVol(dict req, int nRequestID);

	int reqDelMarkerHedge(dict req, int nRequestID);

	int reqSetMarkerStep(dict req, int nRequestID);

	int reqDelMarkerStep(dict req, int nRequestID);

	int reqDelAlertParam(dict req, int nRequestID);

	int reqSetQuoteMove(dict req, int nRequestID);

	int reqDelQuoteMove(dict req, int nRequestID);

	int reqRebackQuote(dict req, int nRequestID);

	int reqQryDepMarketData(dict req, int nRequestID);

	int reqQryQuoteMove(dict req, int nRequestID);

	int reqQryBaseMarkerStep(dict req, int nRequestID);

	int reqQryMarkerStep(dict req, int nRequestID);

	int reqFocusStatus(dict req, int nRequestID);

	int reqSetFutureMakerWholeSwitch(dict req, int nRequestID);

	int reqSetFutureMakerStrategy(dict req, int nRequestID);

	int reqSetSlefHedgeStrategy(dict req, int nRequestID);

	int reqSetFutureHedgeStrategy(dict req, int nRequestID);

	int reqSetQuoteAdditionParm(dict req, int nRequestID);

	int reqStopAllFutureMakerHedgeOffer(dict req, int nRequestID);

	int reqQryFutureMakerStrategy(dict req, int nRequestID);

	int reqQryAllInnerHighStockStrategy(dict req, int nRequestID);

	int reqSetHighStockStrategySwitch(dict req, int nRequestID);

	int reqQryAllAPIHighStockStrategy(dict req, int nRequestID);

	int reqQrySignalAPIHighStockStrategy(dict req, int nRequestID);

	int reqSetSignalHighStockStrategySwitch(dict req, int nRequestID);

	int reqSetHighStockStrategyRelationParam(dict req, int nRequestID);

	int reqQryAllStrategyRelation(dict req, int nRequestID);

	int reqSetAPIHighStockStrategyParam(dict req, int nRequestID);

	int reqDelHighStockStrategyRelationParam(dict req, int nRequestID);

	int reqDelAPIHighStockStrategyParam(dict req, int nRequestID);

	int reqQryAllTradingPeriodStrategy(dict req, int nRequestID);

	int reqSetTradingPeriodStrategy(dict req, int nRequestID);

	int reqDelTradingPeriodStrategy(dict req, int nRequestID);

	int reqQryAllInnerStrategyRelation(dict req, int nRequestID);

	int reqCancelAllStrategyRelationOrder(dict req, int nRequestID);

	int reqSetAutoReBuySwitch(dict req, int nRequestID);

	int reqSendFutureStrategyOrder(dict req, int nRequestID);

	int reqSetAlgoParm(dict req, int nRequestID);

	int reqQryAlgoParm(dict req, int nRequestID);

	int reqQryFutureStrategyOrder(dict req, int nRequestID);

	int reqQryInnerFutureStrategyOrder(dict req, int nRequestID);

	int reqSetStragedyMessage(dict req, int nRequestID);

	int reqQryIndexDirSignal(dict req, int nRequestID);

	int reqDelFutureStrategyOrder(dict req, int nRequestID);

	int reqDelAlgoParm(dict req, int nRequestID);

	int reqSetSpreadInstrStrategy(dict req, int nRequestID);

	int reqQrySpreadInstrStrategy(dict req, int nRequestID);

	int reqDelSpreadInstrStrategy(dict req, int nRequestID);

	int reqQryInnerSpreadInstrStrategy(dict req, int nRequestID);

	int reqSetTZeroHighStockStrategy(dict req, int nRequestID);

	int reqQryTZeroHighStockStrategy(dict req, int nRequestID);

	int reqSetfutruetradeinstr(dict req, int nRequestID);

	int reqQryFlowerFutureTargetMoney(dict req, int nRequestID);

	int reqSetFlowerFutureTargetMoney(dict req, int nRequestID);

	int reqSetParentDetialUpdateMessage(dict req, int nRequestID);

	int reqQryMarketTradingTime(dict req, int nRequestID);

	int reqSetFutureStrategyTotalSecondRelationParam(dict req, int nRequestID);

	int reqQryAllTotalSecondStrategyRelation(dict req, int nRequestID);

	int reqDelHighStockStrategyTotalSecondRelationParam(dict req, int nRequestID);

	int reqQryAllInnerTotalSecondStrategyRelation(dict req, int nRequestID);

	int reqQryParentDetialUpdateMessage(dict req, int nRequestID);

	int reqQryParentOrderStaticParam(dict req, int nRequestID);

	int reqSetParentOrderStaticParam(dict req, int nRequestID);

	int reqDelParentOrderStaticParam(dict req, int nRequestID);

	int reqQryJavaAlgoStatus(dict req, int nRequestID);

	int reqSetJavaAlgoStatus(dict req, int nRequestID);

	int reqQryFuSkAccountRelation(dict req, int nRequestID);

	int reqBatchOrderInsert(dict req, int nRequestID);

	int reqBatchOrderAction(dict req, int nRequestID);

	int reqSetUserInvestorSeatBasePasswd(dict req, int nRequestID);

	int reqQryUnFinshPutureOrder(dict req, int nRequestID);

	int reqQryTodayTayoutDetails(dict req, int nRequestID);


};

