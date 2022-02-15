/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company 山西证券股份有限公司  金融衍生产品部
///@author 顾浩
///@file FocusFtdcTraderApi.h
///@brief 定义了客户端接口
///@history
///20150520	徐忠华	创建该文件
///20170517	顾浩	增加了期权做市相关接口
/////////////////////////////////////////////////////////////////////////

#if !defined(FOCUS_FTDCTRADERAPI_H)
#define FOCUS_FTDCTRADERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FocusFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_API_EXPORT __declspec(dllexport)
#else
#define TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_API_EXPORT 
#endif

class CFocusFtdcTraderSpi
{
public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected(){};
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason){};
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};
	

	///错误应答
	virtual void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登录应答
	virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户退出应答
	virtual void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单录入应答
	virtual void OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单操作应答
	virtual void OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交回报
	virtual void OnRtnTrade(CFocusFtdcTradeField *pTrade) {};

	///报单回报
	virtual void OnRtnOrder(CFocusFtdcOrderField *pOrder) {};

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) {};

	///警告消息通知
	virtual void OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) {};

	///报单查询应答
	virtual void OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交单查询应答
	virtual void OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者资金账户查询应答
	virtual void OnRspQryInvestorAccount(CFocusFtdcRspInvestorAccountField *pRspInvestorAccount, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约查询应答
	virtual void OnRspQryInstrument(CFocusFtdcRspInstrumentField *pRspInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所查询应答
	virtual void OnRspQryExchange(CFocusFtdcRspExchangeField *pRspExchange, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者持仓查询应答
	virtual void OnRspQryInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅主题应答
	virtual void OnRspSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主题查询应答
	virtual void OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///产品应答
	virtual void OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///做市日志推送
	virtual void OnRtnStrategyLog(CFocusFtdcStrategyLogField *pStrategyLog) {};

	///投资者持仓推送
	virtual void OnRtnInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition) {};

	///新母单信息推送通知
	virtual void OnRtnParentOrder(CFocusFtdcParentOrderField *pParentOrder) {};

	///母单信息操作通知
	virtual void OnRtnParentOrderAction(CFocusFtdcParentOrderActionField *pParentOrderAction) {};

	///母单信息修改通知
	virtual void OnRtnAmendParentOrder(CFocusFtdcAmendParentOrderField *pAmendParentOrder) {};

	///母单操作手动操作信息
	virtual void OnRtnExtraManualParentOrder(CFocusFtdcExtraManualParentOrderField *pExtraManualParentOrder) {};

	///市场产品交易时间查询应答
	virtual void OnRspQryMarketTradingTime(CFocusFtdcMarketTradingPeriodInfoField *pMarketTradingPeriodInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///股票批量报单录入请求应答
	virtual void OnRspBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///股票批量撤单请求应答
	virtual void OnRspBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知跨期策略原始订单详情
	virtual void OnRtnSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) {};

	///通知修改跨期策略原始订单详情
	virtual void OnRtnAmendPSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) {};
};

class TRADER_API_EXPORT CFocusFtdcTraderApi
{
public:
	///创建TraderApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@return 创建出的UserApi
	static CFocusFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");
	
	///获取系统版本号
	///@param nMajorVersion 主版本号
	///@param nMinorVersion 子版本号
	///@return 系统标识字符串
	static const char *GetVersion();
	
	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;
	
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init() = 0;
	
	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;
	
	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;
	
	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///注册名字服务器网络地址
	///@param pszNsAddress：名字服务器网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
	///@remark RegisterFront优先于RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CFocusFtdcTraderSpi *pSpi) = 0;
	
	///订阅私有流。
	///@param nResumeType 私有流重传方式  
	///        FOCUS_TERT_RESTART:从本交易日开始重传
	///        FOCUS_TERT_RESUME:从上次收到的续传
	///        FOCUS_TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribePrivateTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅公共流。
	///@param nResumeType 公共流重传方式  
	///        FOCUS_TERT_RESTART:从本交易日开始重传
	///        FOCUS_TERT_RESUME:从上次收到的续传
	///        FOCUS_TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	virtual void SubscribePublicTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;

	///订阅交易员流。
	///@param nResumeType 交易员流重传方式  
	///        FOCUS_TERT_RESTART:从本交易日开始重传
	///        FOCUS_TERT_RESUME:从上次收到的续传
	///        FOCUS_TERT_QUICK:只传送登录后交易员流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
	virtual void SubscribeUserTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///设置心跳超时时间。
	///@param timeout 心跳超时时间(秒)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	///打开请求日志文件
	///@param pszReqLogFileName 请求日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenRequestLog(const char *pszReqLogFileName) = 0;

	///打开应答日志文件
	///@param pszRspLogFileName 应答日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenResponseLog(const char *pszRspLogFileName) = 0;

	///订阅交易合约
	///@param char *ppInstrumentID[] 订阅合约列表
	///@param nCount 订阅数量
	///@return 0 操作成功
	virtual int SubInstrumentStatus(char *ppInstrumentID[], int nCount) = 0;
	
	///取消订阅交易合约
	///@param char *ppInstrumentID[] 订阅合约列表
	///@param nCount 订阅数量
	///@return 0 操作成功
	virtual int UnSubInstrumentStatus(char *ppInstrumentID[], int nCount) = 0;
	

	///用户登录请求
	virtual int ReqUserLogin(CFocusFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///用户退出请求
	virtual int ReqUserLogout(CFocusFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///报单录入请求
	virtual int ReqOrderInsert(CFocusFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///报单操作请求
	virtual int ReqOrderAction(CFocusFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///报单查询请求
	virtual int ReqQryOrder(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///成交单查询请求
	virtual int ReqQryTrade(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///投资者资金账户查询请求
	virtual int ReqQryInvestorAccount(CFocusFtdcQryInvestorAccountField *pQryInvestorAccount, int nRequestID) = 0;

	///合约查询请求
	virtual int ReqQryInstrument(CFocusFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///交易所查询请求
	virtual int ReqQryExchange(CFocusFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///投资者持仓查询请求
	virtual int ReqQryInvestorPosition(CFocusFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///订阅主题请求
	virtual int ReqSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///主题查询请求
	virtual int ReqQryTopic(CFocusFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///产品查询
	virtual int ReqQryProduct(CFocusFtdcQryProductField *pQryProduct, int nRequestID) = 0;

	///发送母单进展详细信息
	virtual int ReqSetParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage, int nRequestID) = 0;

	///查询市场产品交易时间
	virtual int ReqQryMarketTradingTime(CFocusFtdcAPIQryMarketTradingTimeField *pAPIQryMarketTradingTime, int nRequestID) = 0;

	///设置Java ALGO交易状态
	virtual int ReqSetJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, int nRequestID) = 0;

	///股票批量报单录入请求
	virtual int ReqBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, int nRequestID) = 0;

	///股票批量撤单请求
	virtual int ReqBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, int nRequestID) = 0;
protected:
	~CFocusFtdcTraderApi(){};
};

#endif
