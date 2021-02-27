/////////////////////////////////////////////////////////////////////////
///@system 山西证券金融衍生品 Platform
///@company 山西证券金融衍生品
///@file FocusFtdcUserApi.h
///@brief 定义了客户端接口
///@history 
///20150520	顾浩	创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(FOCUS_FTDCUSERAPI_H)
#define FOCUS_FTDCUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FocusFtdcUserApiStruct.h"

#if defined(USERAPI_IS_LIB) && defined(WIN32)
#ifdef LIB_USER_API_EXPORT
#define USER_API_EXPORT __declspec(dllexport)
#else
#define USER_API_EXPORT __declspec(dllimport)
#endif
#else
#define USER_API_EXPORT 
#endif


class CFocusFtdcUserSpi
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

	///没有权限的多播订阅主题
	///@param nTopicID 被主题代码
	virtual void OnStopMultiTopic(int nTopicID){};

	//新增多播心跳接口 add by zbz 20150304
	virtual void OnMultiHeartbeat(char *CurrTime,char *MultiCastIP) {};

	///错误应答
	virtual void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登录应答
	virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户退出应答
	virtual void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户密码修改应答
	virtual void OnRspUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///强制用户退出应答
	virtual void OnRspForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户会话删除应答
	virtual void OnRspForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求导出内存数据库
	virtual void OnRspDumpMemDB(CFocusFtdcMemDBField *pMemDB, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单录入应答
	virtual void OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单操作应答
	virtual void OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者资金帐户出入金应答
	virtual void OnRspAccountDeposit(CFocusFtdcRspAccountDepositField *pRspAccountDeposit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者权限应答
	virtual void OnRspInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///实时上场应答
	virtual void OnRspTBCommand(CFocusFtdcTBCommandField *pTBCommand, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///来回测试应答
	virtual void OnRspPingPong(CFocusFtdcPingPongField *pPingPong, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///审批模式设置应答
	virtual void OnRspSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///深度行情通知
	virtual void OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) {};

	///深度行情通知
	virtual void OnRtnMultiDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) {};

	///订阅合约的相关信息
	virtual void OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///退订合约的相关信息
	virtual void OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Topic查询应答
	virtual void OnRspTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///分价行情
	virtual void OnRtnMBLMarketData(CFocusFtdcMBLMarketDataField *pMBLMarketData) {};

	///郑州合约状态
	virtual void OnRtnQmdInstrumentStatu(CFocusFtdcQmdInstrumentStateField *pQmdInstrumentState) {};

	///数据流回退通知
	virtual void OnRtnFlowMessageCancel(CFocusFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///成交回报
	virtual void OnRtnTrade(CFocusFtdcTradeField *pTrade) {};

	///报单回报
	virtual void OnRtnOrder(CFocusFtdcOrderField *pOrder) {};

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo) {};

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo) {};

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) {};

	///账户出入金回报
	virtual void OnRtnInvestorAccountDeposit(CFocusFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) {};

	///警告消息通知
	virtual void OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) {};

	///工作流指令通知
	virtual void OnRtnAdviceOrder(CFocusFtdcAdviceOrderField *pAdviceOrder) {};

	///订阅合约交易状态通知
	virtual void OnRtnSubInstrumentStatus(CFocusFtdcSubInstrumentStatusField *pSubInstrumentStatus) {};

	///报单查询应答
	virtual void OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交单查询应答
	virtual void OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///可用投资者账户查询应答
	virtual void OnRspQryUserInvestor(CFocusFtdcRspUserInvestorField *pRspUserInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

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

	///用户查询应答
	virtual void OnRspQryUser(CFocusFtdcRspUserField *pRspUser, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者手续费率查询应答
	virtual void OnRspQryInvestorFee(CFocusFtdcRspInvestorFeeField *pRspInvestorFee, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者保证金率查询应答
	virtual void OnRspQryInvestorMargin(CFocusFtdcRspInvestorMarginField *pRspInvestorMargin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者及其关系查询
	virtual void OnRspQryInvestor(CFocusFtdcRspInvestorField *pRspInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///账号风险状况应答
	virtual void OnRspQryAccountRisk(CFocusFtdcRspAccountRiskField *pRspAccountRisk, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易用户会话应答
	virtual void OnRspQryUserSession(CFocusFtdcRspUserSessionField *pRspUserSession, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约行情应答
	virtual void OnRspQryMarketData(CFocusFtdcRspMarketDataField *pRspMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者及其关系查询应答
	virtual void OnRspQryInvestorRelation(CFocusFtdcRspInvestorRelationField *pRspInvestorRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///产品应答
	virtual void OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///工作流交易员查询应答
	virtual void OnRspQryAdviceTrader(CFocusFtdcRspAdviceTraderField *pRspAdviceTrader, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///最大可交易数量查询应答
	virtual void OnRspQryMaxVolume(CFocusFtdcRspMaxVolumeField *pRspMaxVolume, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///组合持仓明细查询应答
	virtual void OnRspQryCmbPositionDetail(CFocusFtdcRspCmbPositionDetailField *pRspCmbPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者结算结果查询应答
	virtual void OnRspQrySettlementInfo(CFocusFtdcRspSettlementInfoField *pRspSettlementInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅合约的相关信息
	virtual void OnRspSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///退订合约的相关信息
	virtual void OnRspUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///结果集分页查询应答
	virtual void OnRspQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单查询应答(分页)
	virtual void OnRspQryOrderPage(CFocusFtdcOrderField *pOrder, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交单查询应答(分页)
	virtual void OnRspQryTradePage(CFocusFtdcTradeField *pTrade, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者持仓查询应答(分页)
	virtual void OnRspQryInvestorPositionPage(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///持仓明细查询应答
	virtual void OnRspQryInvestorPositionDetail(CFocusFtdcRspPositionDetailField *pRspPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///理论价行情通知
	virtual void OnRtnTheoryPriceData(CFocusFtdcTheoryPriceDataField *pTheoryPriceData) {};

	///期权指标行情通知
	virtual void OnRtnOptionIndexData(CFocusFtdcOptionIndexDataField *pOptionIndexData) {};

	///设置定价参数应答
	virtual void OnRspSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置期权理论波动率应答
	virtual void OnRspSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///计算单个期权应答
	virtual void OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///计算障碍期权应答
	virtual void OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///波动率拟合应答
	virtual void OnRspVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Wing模型参数查询应答
	virtual void OnRspQryWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Wing模型参数设置应答
	virtual void OnRspSetWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///做市报价累计价格成交推送
	virtual void OnRtnQuoteTotalTradePrice(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice) {};

	///做市策略设置查询应答
	virtual void OnRspQryMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///修改做市策略设置应答
	virtual void OnRspUpMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户开关设置查询应答
	virtual void OnRspQryUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置用户开关应答
	virtual void OnRspUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///回复查询对冲参数
	virtual void OnRspQryMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///回复修改对冲参数
	virtual void OnRspUpMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///拟合参数查询应答
	virtual void OnRspQryFittingParam(CFocusFtdcFittingParamField *pFittingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///拟合参数设置应答
	virtual void OnRspSetFittingParam(CFocusFtdcFittingParamField *pFittingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询定价参数应答
	virtual void OnRspQryPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询期权理论波动率应答
	virtual void OnRspQryOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价录入应答
	virtual void OnRspQuoteInsert(CFocusFtdcInputQuoteField *pInputQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价操作应答
	virtual void OnRspQuoteAction(CFocusFtdcQuoteActionField *pQuoteAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价查询应答
	virtual void OnRspQryQuote(CFocusFtdcQuoteField *pQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价回报
	virtual void OnRtnQuote(CFocusFtdcQuoteField *pQuote) {};

	///询价应答
	virtual void OnRspForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///询价通知
	virtual void OnRtnForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote) {};

	///错误报单查询应答
	virtual void OnRspQryOrderInsertFailed(CFocusFtdcOrderInsertFailedField *pOrderInsertFailed, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///清空成交阀值请求应答
	virtual void OnRspCleanQuoteThresHold(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///定价合约价差设置应答
	virtual void OnRspSetPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///定价合约价差查询应答
	virtual void OnRspQryPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除定价参数应答
	virtual void OnRspDelPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除做市策略参数应答
	virtual void OnRspDelMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置做市预警参数应答
	virtual void OnRspSetAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询做市预警参数应答
	virtual void OnRspQryAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询做市预警指标值应答
	virtual void OnRspQryAlertData(CFocusFtdcAlertIndexSetDataField *pAlertIndexSetData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///做市预警指标值推送
	virtual void OnRtnAlertData(CFocusFtdcAlertIndexSetDataField *pAlertIndexSetData) {};

	///做市日志推送
	virtual void OnRtnStrategyLog(CFocusFtdcStrategyLogField *pStrategyLog) {};

	///做市报价累计持仓推送
	virtual void OnRtnQuoteTotalTradePosition(CFocusFtdcQuoteTotalTradePositionField *pQuoteTotalTradePosition) {};

	///删除期权理论波动率应答
	virtual void OnRspDelOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除对冲参数应答
	virtual void OnRspDelMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///做市报价宽度设置请求应答
	virtual void OnRspSetMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除做市报价宽度设置请求应答
	virtual void OnRspDelMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除做市预警参数应答
	virtual void OnRspDelAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///做市报价移动策略应答
	virtual void OnRspSetQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除做市报价移动策略应答
	virtual void OnRspDelQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///恢复报价不进行报价偏移应答
	virtual void OnRspRebackQuote(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///深度行情查询应答
	virtual void OnRspQryDepMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询偏移报价参数应答
	virtual void OnRspQryQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询做市报价宽度设置基础信息应答
	virtual void OnRspQryBaseMarkerStep(CFocusFtdcBaseMarkerStepField *pBaseMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询做市报价宽度梯度应答
	virtual void OnRspQryMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询后台进程交易状态应答
	virtual void OnRspFocusStatus(CFocusFtdcFocusStatusField *pFocusStatus, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ATM相关值推送
	virtual void OnRtnATMPriceData(CFocusFtdcATMPriceDataField *pATMPriceData) {};

	///设置期货做市总开关应答
	virtual void OnRspSetFutureMakerWholeSwitch(CFocusFtdcFutureMakerWholeSwitchField *pFutureMakerWholeSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置期货做市报价参数应答
	virtual void OnRspSetFutureMakerStrategy(CFocusFtdcFutureMakerStrategyField *pFutureMakerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置期货反手对冲参数应答
	virtual void OnRspSetSlefHedgeStrategy(CFocusFtdcSlefHedgeStrategyField *pSlefHedgeStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置期货对冲合约对冲参数应答
	virtual void OnRspSetFutureHedgeStrategy(CFocusFtdcFutureHedgeStrategyField *pFutureHedgeStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置做市报价额外参数设置应答
	virtual void OnRspSetQuoteAdditionParm(CFocusFtdcQuoteAdditionParmField *pQuoteAdditionParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知期权做市策略改变
	virtual void OnRtnMarkerStrategyChange(CFocusFtdcMarkerStrategyField *pMarkerStrategy) {};

	///一键撤销所有期货做市对冲单应答
	virtual void OnRspStopAllFutureMakerHedgeOffer(CFocusFtdcStopAllFutureMakerHedgeOfferField *pStopAllFutureMakerHedgeOffer, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///期货对冲报价状态通知
	virtual void OnRtnFutureMakerHedgeStatus(CFocusFtdcFutureMakerHedgeStatusField *pFutureMakerHedgeStatus) {};

	///投资者持仓推送
	virtual void OnRtnInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition) {};

	///查询期货做市参数应答
	virtual void OnRspQryFutureMakerStrategy(CFocusFtdcAllFutureMakerStrategyField *pAllFutureMakerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///所有个股内部高频策略表详细信息应答
	virtual void OnRspQryAllInnerHighStockStrategy(CFocusFtdcInnerHighStockStrategyField *pInnerHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知内部股票高频策略表
	virtual void OnRtnInnerHighStockStrategy(CFocusFtdcInnerHighStockStrategyField *pInnerHighStockStrategy) {};

	///设置整个股票策略开关应答
	virtual void OnRspSetHighStockStrategySwitch(CFocusFtdcWholeHighStockStrategySwitchField *pWholeHighStockStrategySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询该策略的所有股票成员应答
	virtual void OnRspQryAPIHighStockStrategy(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询单个股票策略详情应答
	virtual void OnRspQrySignalPIHighStockStrategy(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置单个股票策略开关应答
	virtual void OnRspSetSignalHighStockStrategySwitch(CFocusFtdcSignalHighStockStrategySwitchField *pSignalHighStockStrategySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置设置股票策略参数应答
	virtual void OnRspSetHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知股票期货对冲关系内部表
	virtual void OnRtnHighInnerFutureStrategyRelation(CFocusFtdcHighInnerFutureStrategyRelationField *pHighInnerFutureStrategyRelation) {};

	///查询所有策略关系表应答
	virtual void OnRspQryAllStrategyRelation(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置单个股票策略参数应答
	virtual void OnRspSetAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求删除股票策略参数应答
	virtual void OnRspDelHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求删除个股股票参数应答
	virtual void OnRspDelAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询股票交易阶段下单方式参数应答
	virtual void OnRspQryAllTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求设置股票交易阶段下单方式参数应答
	virtual void OnRspSetTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求删除股票交易阶段下单方式参数应答
	virtual void OnRspDelTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///股票期货对冲关系内部表详细信息应答
	virtual void OnRspQryAllInnerStrategyRelation(CFocusFtdcHighInnerFutureStrategyRelationField *pHighInnerFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///撤销所有该资金号的未成交股票，并且将策略置为false应答
	virtual void OnRspCancelAllStrategyRelationOrder(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///逆回购自动卖出开关设置应答
	virtual void OnRspSetAutoReBuySwitch(CFocusFtdcRelationAutoReBuySwitchField *pRelationAutoReBuySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置期货算法订单应答
	virtual void OnRspSendFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置算法参数应答
	virtual void OnRspSetAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知期货算法订单详情
	virtual void OnRtnInnerFutureStrategyOrder(CFocusFtdcInnerFutureStrategyOrderField *pInnerFutureStrategyOrder) {};

	///查询算法参数应答
	virtual void OnRspQryAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询期货算法订单应答
	virtual void OnRspQryFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询算法订单详情应答
	virtual void OnRspQryInnerFutureStrategyOrder(CFocusFtdcInnerFutureStrategyOrderField *pInnerFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置策略消息信号应答
	virtual void OnRspSetStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询大盘信号应答
	virtual void OnRspQryIndexDirSignal(CFocusFtdcIndexDirSignalField *pIndexDirSignal, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除期货算法订单应答
	virtual void OnRspDelFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除算法参数应答
	virtual void OnRspDelAlgoParm(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置跨期策略应答
	virtual void OnRspSetSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询跨期策略应答
	virtual void OnRspQrySpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除跨期策略应答
	virtual void OnRspDelSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询跨期策略执行情况应答
	virtual void OnRspQryInnerSpreadInstrStrategy(CFocusFtdcInnerSpreadInstrStrategyField *pInnerSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知期货算法订单详情
	virtual void OnRtnInnerSpreadInstrStrategy(CFocusFtdcInnerSpreadInstrStrategyField *pInnerSpreadInstrStrategy) {};

	///设置盘中list请求域参数应答
	virtual void OnRspSetTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询盘中list成员应答
	virtual void OnRspQryTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知(发布)策略消息
	virtual void OnRtnStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal) {};

	///设置可交易期货合约应答
	virtual void OnRspSetfutruetradeinstr(CFocusFtdcQryInstrumentField *pQryInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询跟随期货初始总资金应答
	virtual void OnRspQryFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置跟随期货初始总资金应答
	virtual void OnRspSetFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

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

	///设置算法2股票期货对冲关系表应答
	virtual void OnRspSetFutureStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知算法2股票期货对冲关系内部表
	virtual void OnRtnHighInnerFutureStrategyTotalSecondRelation(CFocusFtdcInnerFutureStrategyTotalSecondRelationField *pInnerFutureStrategyTotalSecondRelation) {};

	///查询所有算法2策略关系表应答
	virtual void OnRspQryAllTotalSecondStrategyRelation(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求删除算法2股票策略参数应答
	virtual void OnRspDelHighStockStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询算法2所有内部所有策略关系表应答
	virtual void OnRspQryAllInnerTotalSecondStrategyRelation(CFocusFtdcInnerFutureStrategyTotalSecondRelationField *pInnerFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询母单进展详细信息应答
	virtual void OnRspQryParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询母单算法基本信息参数应答
	virtual void OnRspQryParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///母单进展详细信息应答
	virtual void OnRtnParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage) {};

	///更改母单算法基本信息参数应答
	virtual void OnRspSetParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除母单算法基本信息参数应答
	virtual void OnRspDelParentOrderStaticParam(CFocusFtdcParentOrderIndexField *pParentOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询Java ALGO交易状态应答
	virtual void OnRspQryJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Java ALGO状态通知
	virtual void OnRtnJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus) {};

	///查询期现账户关系表应答
	virtual void OnRspQryFuSkAccountRelation(CFocusFtdcFuSkAccountRelationField *pFuSkAccountRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///股票批量报单录入请求应答
	virtual void OnRspBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///股票批量撤单请求应答
	virtual void OnRspBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///调整账户信息应答
	virtual void OnRspSetUserInvestorSeatBasePasswd(CFocusFtdcUserInvestorSeatBaseField *pUserInvestorSeatBase, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知跨期策略原始订单详情
	virtual void OnRtnSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) {};

	///通知修改跨期策略原始订单详情
	virtual void OnRtnAmendPSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) {};
};

class USER_API_EXPORT CFocusFtdcUserApi
{
public:
	///创建UserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@param pszUserApiType UserAPI类型
	///@return 创建出的UserApi
	static CFocusFtdcUserApi *CreateFtdcUserApi(const char *pszFlowPath = "",
											const char *pszUserApiType = "");
	
	///获取系统版本号
	///@param nMajorVersion 主版本号
	///@param nMinorVersion 子版本号
	///@return 系统标识字符串
	static const char *GetVersion();
	
	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;

	//多播设置开关
	virtual void SetMultiCast(bool bMultiCast=false) = 0;
	virtual void RegMultiTopicID(int TopicID)=0;
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init(int nPrivatePort) = 0;
	
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
	virtual void RegisterSpi(CFocusFtdcUserSpi *pSpi) = 0;
	
	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        FOCUS_TERT_RESTART:从本交易日开始重传
	///        FOCUS_TERT_RESUME:从上次收到的续传
	///        FOCUS_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribeMarketDataTopic(int nTopicID, FOCUS_TE_RESUME_TYPE nResumeType) = 0;

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
	
	///订阅合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	virtual int SubMarketData(char *ppInstrumentID[], int nCount)=0;

	///退订合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	virtual int UnSubMarketData(char *ppInstrumentID[], int nCount)=0;	
	
	
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
	
	///打开执行追踪日志文件
	///@param pszRspLogFileName 追踪日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenTraceLog(const char *pszTraceLogFileName) = 0;

	///用户登录请求
	virtual int ReqUserLogin(CFocusFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///用户退出请求
	virtual int ReqUserLogout(CFocusFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///用户密码修改请求
	virtual int ReqUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///强制用户退出请求
	virtual int ReqForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///用户会话删除请求
	virtual int ReqForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///请求导出内存数据库
	virtual int ReqDumpMemDB(CFocusFtdcMemDBField *pMemDB, int nRequestID) = 0;

	///报单录入请求
	virtual int ReqOrderInsert(CFocusFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///报单操作请求
	virtual int ReqOrderAction(CFocusFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///投资者资金帐户出入金请求
	virtual int ReqAccountDeposit(CFocusFtdcReqAccountDepositField *pReqAccountDeposit, int nRequestID) = 0;

	///投资者权限请求
	virtual int ReqInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, int nRequestID) = 0;

	///实时上场请求
	virtual int ReqTBCommand(CFocusFtdcTBCommandField *pTBCommand, int nRequestID) = 0;

	///来回测试请求
	virtual int ReqPingPong(CFocusFtdcPingPongField *pPingPong, int nRequestID) = 0;

	///审批模式设置请求
	virtual int ReqSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, int nRequestID) = 0;

	///订阅合约的相关信息
	virtual int ReqSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///退订合约的相关信息
	virtual int ReqUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///Topic查询请求
	virtual int ReqTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, int nRequestID) = 0;

	///报单查询请求
	virtual int ReqQryOrder(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///成交单查询请求
	virtual int ReqQryTrade(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///可用投资者账户查询请求
	virtual int ReqQryUserInvestor(CFocusFtdcQryUserInvestorField *pQryUserInvestor, int nRequestID) = 0;

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

	///用户查询请求
	virtual int ReqQryUser(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///投资者手续费率查询请求
	virtual int ReqQryInvestorFee(CFocusFtdcQryInvestorFeeField *pQryInvestorFee, int nRequestID) = 0;

	///投资者保证金率查询请求
	virtual int ReqQryInvestorMargin(CFocusFtdcQryInvestorMarginField *pQryInvestorMargin, int nRequestID) = 0;

	///投资者及其关系查询
	virtual int ReqQryInvestor(CFocusFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///账号风险状况查询
	virtual int ReqQryAccountRisk(CFocusFtdcQryAccountRiskField *pQryAccountRisk, int nRequestID) = 0;

	///交易用户会话查询
	virtual int ReqQryUserSession(CFocusFtdcQryUserSessionField *pQryUserSession, int nRequestID) = 0;

	///合约行情查询
	virtual int ReqQryMarketData(CFocusFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///投资者及其关系查询请求
	virtual int ReqQryInvestorRelation(CFocusFtdcQryInvestorRelationField *pQryInvestorRelation, int nRequestID) = 0;

	///产品查询
	virtual int ReqQryProduct(CFocusFtdcQryProductField *pQryProduct, int nRequestID) = 0;

	///工作流交易员查询请求
	virtual int ReqQryAdviceTrader(CFocusFtdcQryAdviceTraderField *pQryAdviceTrader, int nRequestID) = 0;

	///最大可交易数量查询请求
	virtual int ReqQryMaxVolume(CFocusFtdcQryMaxVolumeField *pQryMaxVolume, int nRequestID) = 0;

	///组合持仓明细查询请求
	virtual int ReqQryCmbPositionDetail(CFocusFtdcQryCmbPositionDetailField *pQryCmbPositionDetail, int nRequestID) = 0;

	///投资者结算结果查询请求
	virtual int ReqQrySettlementInfo(CFocusFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID) = 0;

	///订阅合约的相关信息
	virtual int ReqSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, int nRequestID) = 0;

	///退订合约的相关信息
	virtual int ReqUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, int nRequestID) = 0;

	///结果集分页查询请求
	virtual int ReqQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, int nRequestID) = 0;

	///报单查询请求(分页)
	virtual int ReqQryOrderPage(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///成交单查询请求(分页)
	virtual int ReqQryTradePage(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///投资者持仓查询请求(分页)
	virtual int ReqQryInvestorPositionPage(CFocusFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///持仓明细查询请求
	virtual int ReqQryInvestorPositionDetail(CFocusFtdcQryPositionDetailField *pQryPositionDetail, int nRequestID) = 0;

	///设置定价参数请求
	virtual int ReqSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, int nRequestID) = 0;

	///设置期权理论波动率请求
	virtual int ReqSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, int nRequestID) = 0;

	///计算单个期权请求
	virtual int ReqCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, int nRequestID) = 0;

	///计算障碍期权请求
	virtual int ReqCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, int nRequestID) = 0;

	///测试行情模拟
	virtual int ReqMarketDataTest(CFocusFtdcDepthMarketDataField *pDepthMarketData, int nRequestID) = 0;

	///波动率拟合请求
	virtual int ReqVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, int nRequestID) = 0;

	///Wing模型参数查询请求
	virtual int ReqQryWingModelParam(CFocusFtdcQryWingModelParamField *pQryWingModelParam, int nRequestID) = 0;

	///Wing模型参数设置请求
	virtual int ReqSetWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, int nRequestID) = 0;

	///查询做市策略设置
	virtual int ReqQryMarkerStrategySet(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///修改做市策略设置
	virtual int ReqUpMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, int nRequestID) = 0;

	///查询用户开关设置
	virtual int ReqQryUserSwitch(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///设置用户开关
	virtual int ReqUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, int nRequestID) = 0;

	///查询对冲参数
	virtual int ReqQryMarkerHedge(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///修改对冲参数
	virtual int ReqUpMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, int nRequestID) = 0;

	///拟合参数查询请求
	virtual int ReqQryFittingParam(CFocusFtdcQryFittingParamField *pQryFittingParam, int nRequestID) = 0;

	///拟合参数设置请求
	virtual int ReqSetFittingParam(CFocusFtdcFittingParamField *pFittingParam, int nRequestID) = 0;

	///查询定价参数请求
	virtual int ReqQryPricingParam(CFocusFtdcQryPricingParamField *pQryPricingParam, int nRequestID) = 0;

	///查询期权理论波动率请求
	virtual int ReqQryOptionTheoryVol(CFocusFtdcQryOptionTheoryVolField *pQryOptionTheoryVol, int nRequestID) = 0;

	///报价录入请求
	virtual int ReqQuoteInsert(CFocusFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///报价操作请求
	virtual int ReqQuoteAction(CFocusFtdcQuoteActionField *pQuoteAction, int nRequestID) = 0;

	///报价查询请求
	virtual int ReqQryQuote(CFocusFtdcQryQuoteField *pQryQuote, int nRequestID) = 0;

	///询价请求
	virtual int ReqForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote, int nRequestID) = 0;

	///错误报单查询请求
	virtual int ReqQryOrderInsertFailed(CFocusFtdcQryOrderInsertFailedField *pQryOrderInsertFailed, int nRequestID) = 0;

	///清空成交阀值请求
	virtual int ReqCleanQuoteThresHold(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, int nRequestID) = 0;

	///定价合约价差设置
	virtual int ReqSetPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, int nRequestID) = 0;

	///定价合约价差查询
	virtual int ReqQryPriceSpread(CFocusFtdcQryPriceSpreadField *pQryPriceSpread, int nRequestID) = 0;

	///删除用户定价参数
	virtual int ReqDelPricingParam(CFocusFtdcPricingParamField *pPricingParam, int nRequestID) = 0;

	///删除做市策略参数
	virtual int ReqDelMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, int nRequestID) = 0;

	///设置做市预警参数
	virtual int ReqSetAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, int nRequestID) = 0;

	///查询做市预警参数
	virtual int ReqQryAlertParam(CFocusFtdcQryAlertIndexSetParamField *pQryAlertIndexSetParam, int nRequestID) = 0;

	///查询做市预警指标值
	virtual int ReqQryAlertData(CFocusFtdcQryAlertIndexSetParamField *pQryAlertIndexSetParam, int nRequestID) = 0;

	///删除期权理论波动率请求
	virtual int ReqDelOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, int nRequestID) = 0;

	///删除对冲参数请求
	virtual int ReqDelMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, int nRequestID) = 0;

	///做市报价宽度设置请求
	virtual int ReqSetMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, int nRequestID) = 0;

	///删除做市报价宽度设置请求
	virtual int ReqDelMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, int nRequestID) = 0;

	///删除做市预警参数
	virtual int ReqDelAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, int nRequestID) = 0;

	///设置做市报价移动策略
	virtual int ReqSetQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, int nRequestID) = 0;

	///删除做市报价移动策略
	virtual int ReqDelQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, int nRequestID) = 0;

	///恢复报价不进行报价偏移
	virtual int ReqRebackQuote(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, int nRequestID) = 0;

	///深度行情查询请求
	virtual int ReqQryDepMarketData(CFocusFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///查询偏移报价参数
	virtual int ReqQryQuoteMove(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///查询做市报价宽度设置基础信息
	virtual int ReqQryBaseMarkerStep(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///查询做市报价宽度梯度
	virtual int ReqQryMarkerStep(CFocusFtdcBaseMarkerStepField *pBaseMarkerStep, int nRequestID) = 0;

	///查询后台进程交易状态
	virtual int ReqFocusStatus(CFocusFtdcFocusStatusField *pFocusStatus, int nRequestID) = 0;

	///请求期货做市总开关
	virtual int ReqSetFutureMakerWholeSwitch(CFocusFtdcFutureMakerWholeSwitchField *pFutureMakerWholeSwitch, int nRequestID) = 0;

	///请求期货做市报价参数
	virtual int ReqSetFutureMakerStrategy(CFocusFtdcFutureMakerStrategyField *pFutureMakerStrategy, int nRequestID) = 0;

	///请求设置期货反手对冲参数
	virtual int ReqSetSlefHedgeStrategy(CFocusFtdcSlefHedgeStrategyField *pSlefHedgeStrategy, int nRequestID) = 0;

	///请求设置期货对冲合约对冲参数
	virtual int ReqSetFutureHedgeStrategy(CFocusFtdcFutureHedgeStrategyField *pFutureHedgeStrategy, int nRequestID) = 0;

	///请求设置做市报价额外参数设置
	virtual int ReqSetQuoteAdditionParm(CFocusFtdcQuoteAdditionParmField *pQuoteAdditionParm, int nRequestID) = 0;

	///请求一键撤销所有期货做市对冲单
	virtual int ReqStopAllFutureMakerHedgeOffer(CFocusFtdcStopAllFutureMakerHedgeOfferField *pStopAllFutureMakerHedgeOffer, int nRequestID) = 0;

	///查询期货做市参数
	virtual int ReqQryFutureMakerStrategy(CFocusFtdcFutureMakerIndexField *pFutureMakerIndex, int nRequestID) = 0;

	///查询所有个股内部高频策略表详细信息请求
	virtual int ReqQryAllInnerHighStockStrategy(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, int nRequestID) = 0;

	///请求设置整个股票策略开关
	virtual int ReqSetHighStockStrategySwitch(CFocusFtdcWholeHighStockStrategySwitchField *pWholeHighStockStrategySwitch, int nRequestID) = 0;

	///请求查询该策略的所有股票成员
	virtual int ReqQryAllAPIHighStockStrategy(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, int nRequestID) = 0;

	///请求查询单个股票策略详情
	virtual int ReqQrySignalAPIHighStockStrategy(CFocusFtdcQrySignalHighStockStrategyField *pQrySignalHighStockStrategy, int nRequestID) = 0;

	///请求设置单个股票策略开关
	virtual int ReqSetSignalHighStockStrategySwitch(CFocusFtdcSignalHighStockStrategySwitchField *pSignalHighStockStrategySwitch, int nRequestID) = 0;

	///请求设置股票策略参数
	virtual int ReqSetHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, int nRequestID) = 0;

	///请求查询所有策略关系表
	virtual int ReqQryAllStrategyRelation(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///请求设置单个股票策略参数
	virtual int ReqSetAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, int nRequestID) = 0;

	///请求删除股票策略参数
	virtual int ReqDelHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, int nRequestID) = 0;

	///请求删除个股股票参数
	virtual int ReqDelAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, int nRequestID) = 0;

	///请求查询股票交易阶段下单方式参数
	virtual int ReqQryAllTradingPeriodStrategy(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, int nRequestID) = 0;

	///请求设置股票交易阶段下单方式参数
	virtual int ReqSetTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, int nRequestID) = 0;

	///请求删除股票交易阶段下单方式参数
	virtual int ReqDelTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, int nRequestID) = 0;

	///查询股票期货对冲关系内部表详细信息请求
	virtual int ReqQryAllInnerStrategyRelation(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///请求撤销所有该资金号的未成交股票，并且将策略置为false
	virtual int ReqCancelAllStrategyRelationOrder(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, int nRequestID) = 0;

	///设置逆回购自动卖出开关
	virtual int ReqSetAutoReBuySwitch(CFocusFtdcRelationAutoReBuySwitchField *pRelationAutoReBuySwitch, int nRequestID) = 0;

	///设置期货算法订单
	virtual int ReqSendFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, int nRequestID) = 0;

	///设置算法参数
	virtual int ReqSetAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, int nRequestID) = 0;

	///查询算法参数
	virtual int ReqQryAlgoParm(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///查询期货算法订单
	virtual int ReqQryFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///查询算法订单详情
	virtual int ReqQryInnerFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///设置策略消息信号
	virtual int ReqSetStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal, int nRequestID) = 0;

	///查询大盘信号
	virtual int ReqQryIndexDirSignal(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///删除期货算法订单
	virtual int ReqDelFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///删除算法参数
	virtual int ReqDelAlgoParm(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///设置跨期策略
	virtual int ReqSetSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, int nRequestID) = 0;

	///查询跨期策略
	virtual int ReqQrySpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyIndexField *pSpreadInstrStrategyIndex, int nRequestID) = 0;

	///删除跨期策略
	virtual int ReqDelSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyIndexField *pSpreadInstrStrategyIndex, int nRequestID) = 0;

	///查询跨期策略
	virtual int ReqQryInnerSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyIndexField *pSpreadInstrStrategyIndex, int nRequestID) = 0;

	///请求盘中list请求域参数
	virtual int ReqSetTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, int nRequestID) = 0;

	///请求查询盘中list成员
	virtual int ReqQryTZeroHighStockStrategy(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///设置可交易期货合约
	virtual int ReqSetfutruetradeinstr(CFocusFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///请求查询跟随期货初始总资金
	virtual int ReqQryFlowerFutureTargetMoney(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///请求设置跟随期货初始总资金
	virtual int ReqSetFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, int nRequestID) = 0;

	///发送母单进展详细信息
	virtual int ReqSetParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage, int nRequestID) = 0;

	///查询市场产品交易时间
	virtual int ReqQryMarketTradingTime(CFocusFtdcAPIQryMarketTradingTimeField *pAPIQryMarketTradingTime, int nRequestID) = 0;

	///请求设置算法2股票期货对冲关系表参数
	virtual int ReqSetFutureStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, int nRequestID) = 0;

	///请求查询算法2所有策略关系表
	virtual int ReqQryAllTotalSecondStrategyRelation(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///请求删除算法2股票策略参数
	virtual int ReqDelHighStockStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, int nRequestID) = 0;

	///请求查询算法2所有内部策略关系表
	virtual int ReqQryAllInnerTotalSecondStrategyRelation(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///请求查询母单进展详细信息
	virtual int ReqQryParentDetialUpdateMessage(CFocusFtdcParentOrderDetialIndexField *pParentOrderDetialIndex, int nRequestID) = 0;

	///请求查询母单算法基本信息参数
	virtual int ReqQryParentOrderStaticParam(CFocusFtdcParentOrderIndexField *pParentOrderIndex, int nRequestID) = 0;

	///请求更改母单算法基本信息参数
	virtual int ReqSetParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, int nRequestID) = 0;

	///请求删除母单算法基本信息参数
	virtual int ReqDelParentOrderStaticParam(CFocusFtdcParentOrderIndexField *pParentOrderIndex, int nRequestID) = 0;

	///查询Java ALGO进程交易状态
	virtual int ReqQryJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, int nRequestID) = 0;

	///设置Java ALGO交易状态
	virtual int ReqSetJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, int nRequestID) = 0;

	///查询期现账户关系表
	virtual int ReqQryFuSkAccountRelation(CFocusFtdcFuSkAccountRelationField *pFuSkAccountRelation, int nRequestID) = 0;

	///股票批量报单录入请求
	virtual int ReqBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, int nRequestID) = 0;

	///股票批量撤单请求
	virtual int ReqBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, int nRequestID) = 0;

	///调整账户信息
	virtual int ReqSetUserInvestorSeatBasePasswd(CFocusFtdcUserInvestorSeatBaseField *pUserInvestorSeatBase, int nRequestID) = 0;
protected:
	~CFocusFtdcUserApi(){};
};

#endif
