/////////////////////////////////////////////////////////////////////////
///@system ɽ��֤ȯ��������Ʒ Platform
///@company ɽ��֤ȯ��������Ʒ
///@file FocusFtdcUserApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
///20150520	�˺�	�������ļ�
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
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};

	///û��Ȩ�޵Ķಥ��������
	///@param nTopicID ���������
	virtual void OnStopMultiTopic(int nTopicID){};

	//�����ಥ�����ӿ� add by zbz 20150304
	virtual void OnMultiHeartbeat(char *CurrTime,char *MultiCastIP) {};

	///����Ӧ��
	virtual void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û������޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ǿ���û��˳�Ӧ��
	virtual void OnRspForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��Ựɾ��Ӧ��
	virtual void OnRspForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���󵼳��ڴ����ݿ�
	virtual void OnRspDumpMemDB(CFocusFtdcMemDBField *pMemDB, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ�����ʽ��ʻ������Ӧ��
	virtual void OnRspAccountDeposit(CFocusFtdcRspAccountDepositField *pRspAccountDeposit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ����Ȩ��Ӧ��
	virtual void OnRspInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ʵʱ�ϳ�Ӧ��
	virtual void OnRspTBCommand(CFocusFtdcTBCommandField *pTBCommand, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ز���Ӧ��
	virtual void OnRspPingPong(CFocusFtdcPingPongField *pPingPong, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ģʽ����Ӧ��
	virtual void OnRspSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) {};

	///�������֪ͨ
	virtual void OnRtnMultiDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) {};

	///���ĺ�Լ�������Ϣ
	virtual void OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˶���Լ�������Ϣ
	virtual void OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Topic��ѯӦ��
	virtual void OnRspTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ּ�����
	virtual void OnRtnMBLMarketData(CFocusFtdcMBLMarketDataField *pMBLMarketData) {};

	///֣�ݺ�Լ״̬
	virtual void OnRtnQmdInstrumentStatu(CFocusFtdcQmdInstrumentStateField *pQmdInstrumentState) {};

	///����������֪ͨ
	virtual void OnRtnFlowMessageCancel(CFocusFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///�ɽ��ر�
	virtual void OnRtnTrade(CFocusFtdcTradeField *pTrade) {};

	///�����ر�
	virtual void OnRtnOrder(CFocusFtdcOrderField *pOrder) {};

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo) {};

	///������������ر�
	virtual void OnErrRtnOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo) {};

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) {};

	///�˻������ر�
	virtual void OnRtnInvestorAccountDeposit(CFocusFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) {};

	///������Ϣ֪ͨ
	virtual void OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) {};

	///������ָ��֪ͨ
	virtual void OnRtnAdviceOrder(CFocusFtdcAdviceOrderField *pAdviceOrder) {};

	///���ĺ�Լ����״̬֪ͨ
	virtual void OnRtnSubInstrumentStatus(CFocusFtdcSubInstrumentStatusField *pSubInstrumentStatus) {};

	///������ѯӦ��
	virtual void OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ͷ�����˻���ѯӦ��
	virtual void OnRspQryUserInvestor(CFocusFtdcRspUserInvestorField *pRspUserInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ�����ʽ��˻���ѯӦ��
	virtual void OnRspQryInvestorAccount(CFocusFtdcRspInvestorAccountField *pRspInvestorAccount, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ��ѯӦ��
	virtual void OnRspQryInstrument(CFocusFtdcRspInstrumentField *pRspInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������ѯӦ��
	virtual void OnRspQryExchange(CFocusFtdcRspExchangeField *pRspExchange, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���ֲֲ߳�ѯӦ��
	virtual void OnRspQryInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯӦ��
	virtual void OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���ѯӦ��
	virtual void OnRspQryUser(CFocusFtdcRspUserField *pRspUser, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ�����������ʲ�ѯӦ��
	virtual void OnRspQryInvestorFee(CFocusFtdcRspInvestorFeeField *pRspInvestorFee, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߱�֤���ʲ�ѯӦ��
	virtual void OnRspQryInvestorMargin(CFocusFtdcRspInvestorMarginField *pRspInvestorMargin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߼����ϵ��ѯ
	virtual void OnRspQryInvestor(CFocusFtdcRspInvestorField *pRspInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˺ŷ���״��Ӧ��
	virtual void OnRspQryAccountRisk(CFocusFtdcRspAccountRiskField *pRspAccountRisk, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����û��ỰӦ��
	virtual void OnRspQryUserSession(CFocusFtdcRspUserSessionField *pRspUserSession, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ����Ӧ��
	virtual void OnRspQryMarketData(CFocusFtdcRspMarketDataField *pRspMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߼����ϵ��ѯӦ��
	virtual void OnRspQryInvestorRelation(CFocusFtdcRspInvestorRelationField *pRspInvestorRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ƷӦ��
	virtual void OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������Ա��ѯӦ��
	virtual void OnRspQryAdviceTrader(CFocusFtdcRspAdviceTraderField *pRspAdviceTrader, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ɽ���������ѯӦ��
	virtual void OnRspQryMaxVolume(CFocusFtdcRspMaxVolumeField *pRspMaxVolume, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ϳֲ���ϸ��ѯӦ��
	virtual void OnRspQryCmbPositionDetail(CFocusFtdcRspCmbPositionDetailField *pRspCmbPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߽�������ѯӦ��
	virtual void OnRspQrySettlementInfo(CFocusFtdcRspSettlementInfoField *pRspSettlementInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ĺ�Լ�������Ϣ
	virtual void OnRspSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˶���Լ�������Ϣ
	virtual void OnRspUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������ҳ��ѯӦ��
	virtual void OnRspQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ѯӦ��(��ҳ)
	virtual void OnRspQryOrderPage(CFocusFtdcOrderField *pOrder, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ�����ѯӦ��(��ҳ)
	virtual void OnRspQryTradePage(CFocusFtdcTradeField *pTrade, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���ֲֲ߳�ѯӦ��(��ҳ)
	virtual void OnRspQryInvestorPositionPage(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ֲ���ϸ��ѯӦ��
	virtual void OnRspQryInvestorPositionDetail(CFocusFtdcRspPositionDetailField *pRspPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ۼ�����֪ͨ
	virtual void OnRtnTheoryPriceData(CFocusFtdcTheoryPriceDataField *pTheoryPriceData) {};

	///��Ȩָ������֪ͨ
	virtual void OnRtnOptionIndexData(CFocusFtdcOptionIndexDataField *pOptionIndexData) {};

	///���ö��۲���Ӧ��
	virtual void OnRspSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������Ȩ���۲�����Ӧ��
	virtual void OnRspSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���㵥����ȨӦ��
	virtual void OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ϰ���ȨӦ��
	virtual void OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���������Ӧ��
	virtual void OnRspVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Wingģ�Ͳ�����ѯӦ��
	virtual void OnRspQryWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Wingģ�Ͳ�������Ӧ��
	virtual void OnRspSetWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���б����ۼƼ۸�ɽ�����
	virtual void OnRtnQuoteTotalTradePrice(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice) {};

	///���в������ò�ѯӦ��
	virtual void OnRspQryMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�޸����в�������Ӧ��
	virtual void OnRspUpMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��������ò�ѯӦ��
	virtual void OnRspQryUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����û�����Ӧ��
	virtual void OnRspUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ظ���ѯ�Գ����
	virtual void OnRspQryMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ظ��޸ĶԳ����
	virtual void OnRspUpMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ϲ�����ѯӦ��
	virtual void OnRspQryFittingParam(CFocusFtdcFittingParamField *pFittingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ϲ�������Ӧ��
	virtual void OnRspSetFittingParam(CFocusFtdcFittingParamField *pFittingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ���۲���Ӧ��
	virtual void OnRspQryPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ��Ȩ���۲�����Ӧ��
	virtual void OnRspQryOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspQuoteInsert(CFocusFtdcInputQuoteField *pInputQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���۲���Ӧ��
	virtual void OnRspQuoteAction(CFocusFtdcQuoteActionField *pQuoteAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���۲�ѯӦ��
	virtual void OnRspQryQuote(CFocusFtdcQuoteField *pQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ۻر�
	virtual void OnRtnQuote(CFocusFtdcQuoteField *pQuote) {};

	///ѯ��Ӧ��
	virtual void OnRspForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ѯ��֪ͨ
	virtual void OnRtnForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote) {};

	///���󱨵���ѯӦ��
	virtual void OnRspQryOrderInsertFailed(CFocusFtdcOrderInsertFailedField *pOrderInsertFailed, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ճɽ���ֵ����Ӧ��
	virtual void OnRspCleanQuoteThresHold(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ۺ�Լ�۲�����Ӧ��
	virtual void OnRspSetPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ۺ�Լ�۲��ѯӦ��
	virtual void OnRspQryPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ�����۲���Ӧ��
	virtual void OnRspDelPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ�����в��Բ���Ӧ��
	virtual void OnRspDelMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ԥ������Ӧ��
	virtual void OnRspSetAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ����Ԥ������Ӧ��
	virtual void OnRspQryAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ����Ԥ��ָ��ֵӦ��
	virtual void OnRspQryAlertData(CFocusFtdcAlertIndexSetDataField *pAlertIndexSetData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ԥ��ָ��ֵ����
	virtual void OnRtnAlertData(CFocusFtdcAlertIndexSetDataField *pAlertIndexSetData) {};

	///������־����
	virtual void OnRtnStrategyLog(CFocusFtdcStrategyLogField *pStrategyLog) {};

	///���б����ۼƳֲ�����
	virtual void OnRtnQuoteTotalTradePosition(CFocusFtdcQuoteTotalTradePositionField *pQuoteTotalTradePosition) {};

	///ɾ����Ȩ���۲�����Ӧ��
	virtual void OnRspDelOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ���Գ����Ӧ��
	virtual void OnRspDelMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���б��ۿ����������Ӧ��
	virtual void OnRspSetMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ�����б��ۿ����������Ӧ��
	virtual void OnRspDelMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ������Ԥ������Ӧ��
	virtual void OnRspDelAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���б����ƶ�����Ӧ��
	virtual void OnRspSetQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ�����б����ƶ�����Ӧ��
	virtual void OnRspDelQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ָ����۲����б���ƫ��Ӧ��
	virtual void OnRspRebackQuote(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������ѯӦ��
	virtual void OnRspQryDepMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯƫ�Ʊ��۲���Ӧ��
	virtual void OnRspQryQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ���б��ۿ�����û�����ϢӦ��
	virtual void OnRspQryBaseMarkerStep(CFocusFtdcBaseMarkerStepField *pBaseMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ���б��ۿ���ݶ�Ӧ��
	virtual void OnRspQryMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ��̨���̽���״̬Ӧ��
	virtual void OnRspFocusStatus(CFocusFtdcFocusStatusField *pFocusStatus, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ATM���ֵ����
	virtual void OnRtnATMPriceData(CFocusFtdcATMPriceDataField *pATMPriceData) {};

	///�����ڻ������ܿ���Ӧ��
	virtual void OnRspSetFutureMakerWholeSwitch(CFocusFtdcFutureMakerWholeSwitchField *pFutureMakerWholeSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ڻ����б��۲���Ӧ��
	virtual void OnRspSetFutureMakerStrategy(CFocusFtdcFutureMakerStrategyField *pFutureMakerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ڻ����ֶԳ����Ӧ��
	virtual void OnRspSetSlefHedgeStrategy(CFocusFtdcSlefHedgeStrategyField *pSlefHedgeStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ڻ��Գ��Լ�Գ����Ӧ��
	virtual void OnRspSetFutureHedgeStrategy(CFocusFtdcFutureHedgeStrategyField *pFutureHedgeStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������б��۶����������Ӧ��
	virtual void OnRspSetQuoteAdditionParm(CFocusFtdcQuoteAdditionParmField *pQuoteAdditionParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ��Ȩ���в��Ըı�
	virtual void OnRtnMarkerStrategyChange(CFocusFtdcMarkerStrategyField *pMarkerStrategy) {};

	///һ�����������ڻ����жԳ嵥Ӧ��
	virtual void OnRspStopAllFutureMakerHedgeOffer(CFocusFtdcStopAllFutureMakerHedgeOfferField *pStopAllFutureMakerHedgeOffer, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ڻ��Գ屨��״̬֪ͨ
	virtual void OnRtnFutureMakerHedgeStatus(CFocusFtdcFutureMakerHedgeStatusField *pFutureMakerHedgeStatus) {};

	///Ͷ���ֲ߳�����
	virtual void OnRtnInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition) {};

	///��ѯ�ڻ����в���Ӧ��
	virtual void OnRspQryFutureMakerStrategy(CFocusFtdcAllFutureMakerStrategyField *pAllFutureMakerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���и����ڲ���Ƶ���Ա���ϸ��ϢӦ��
	virtual void OnRspQryAllInnerHighStockStrategy(CFocusFtdcInnerHighStockStrategyField *pInnerHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ�ڲ���Ʊ��Ƶ���Ա�
	virtual void OnRtnInnerHighStockStrategy(CFocusFtdcInnerHighStockStrategyField *pInnerHighStockStrategy) {};

	///����������Ʊ���Կ���Ӧ��
	virtual void OnRspSetHighStockStrategySwitch(CFocusFtdcWholeHighStockStrategySwitchField *pWholeHighStockStrategySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�ò��Ե����й�Ʊ��ԱӦ��
	virtual void OnRspQryAPIHighStockStrategy(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ������Ʊ��������Ӧ��
	virtual void OnRspQrySignalPIHighStockStrategy(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���õ�����Ʊ���Կ���Ӧ��
	virtual void OnRspSetSignalHighStockStrategySwitch(CFocusFtdcSignalHighStockStrategySwitchField *pSignalHighStockStrategySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������ù�Ʊ���Բ���Ӧ��
	virtual void OnRspSetHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ��Ʊ�ڻ��Գ��ϵ�ڲ���
	virtual void OnRtnHighInnerFutureStrategyRelation(CFocusFtdcHighInnerFutureStrategyRelationField *pHighInnerFutureStrategyRelation) {};

	///��ѯ���в��Թ�ϵ��Ӧ��
	virtual void OnRspQryAllStrategyRelation(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���õ�����Ʊ���Բ���Ӧ��
	virtual void OnRspSetAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ɾ����Ʊ���Բ���Ӧ��
	virtual void OnRspDelHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ɾ�����ɹ�Ʊ����Ӧ��
	virtual void OnRspDelAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��Ʊ���׽׶��µ���ʽ����Ӧ��
	virtual void OnRspQryAllTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������ù�Ʊ���׽׶��µ���ʽ����Ӧ��
	virtual void OnRspSetTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ɾ����Ʊ���׽׶��µ���ʽ����Ӧ��
	virtual void OnRspDelTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ʊ�ڻ��Գ��ϵ�ڲ�����ϸ��ϢӦ��
	virtual void OnRspQryAllInnerStrategyRelation(CFocusFtdcHighInnerFutureStrategyRelationField *pHighInnerFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������и��ʽ�ŵ�δ�ɽ���Ʊ�����ҽ�������ΪfalseӦ��
	virtual void OnRspCancelAllStrategyRelationOrder(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ع��Զ�������������Ӧ��
	virtual void OnRspSetAutoReBuySwitch(CFocusFtdcRelationAutoReBuySwitchField *pRelationAutoReBuySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ڻ��㷨����Ӧ��
	virtual void OnRspSendFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����㷨����Ӧ��
	virtual void OnRspSetAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ�ڻ��㷨��������
	virtual void OnRtnInnerFutureStrategyOrder(CFocusFtdcInnerFutureStrategyOrderField *pInnerFutureStrategyOrder) {};

	///��ѯ�㷨����Ӧ��
	virtual void OnRspQryAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�ڻ��㷨����Ӧ��
	virtual void OnRspQryFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�㷨��������Ӧ��
	virtual void OnRspQryInnerFutureStrategyOrder(CFocusFtdcInnerFutureStrategyOrderField *pInnerFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ò�����Ϣ�ź�Ӧ��
	virtual void OnRspSetStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�����ź�Ӧ��
	virtual void OnRspQryIndexDirSignal(CFocusFtdcIndexDirSignalField *pIndexDirSignal, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ���ڻ��㷨����Ӧ��
	virtual void OnRspDelFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ���㷨����Ӧ��
	virtual void OnRspDelAlgoParm(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ÿ��ڲ���Ӧ��
	virtual void OnRspSetSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ���ڲ���Ӧ��
	virtual void OnRspQrySpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ�����ڲ���Ӧ��
	virtual void OnRspDelSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ���ڲ���ִ�����Ӧ��
	virtual void OnRspQryInnerSpreadInstrStrategy(CFocusFtdcInnerSpreadInstrStrategyField *pInnerSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ�ڻ��㷨��������
	virtual void OnRtnInnerSpreadInstrStrategy(CFocusFtdcInnerSpreadInstrStrategyField *pInnerSpreadInstrStrategy) {};

	///��������list���������Ӧ��
	virtual void OnRspSetTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ����list��ԱӦ��
	virtual void OnRspQryTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ(����)������Ϣ
	virtual void OnRtnStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal) {};

	///���ÿɽ����ڻ���ԼӦ��
	virtual void OnRspSetfutruetradeinstr(CFocusFtdcQryInstrumentField *pQryInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�����ڻ���ʼ���ʽ�Ӧ��
	virtual void OnRspQryFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ø����ڻ���ʼ���ʽ�Ӧ��
	virtual void OnRspSetFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ĸ����Ϣ����֪ͨ
	virtual void OnRtnParentOrder(CFocusFtdcParentOrderField *pParentOrder) {};

	///ĸ����Ϣ����֪ͨ
	virtual void OnRtnParentOrderAction(CFocusFtdcParentOrderActionField *pParentOrderAction) {};

	///ĸ����Ϣ�޸�֪ͨ
	virtual void OnRtnAmendParentOrder(CFocusFtdcAmendParentOrderField *pAmendParentOrder) {};

	///ĸ�������ֶ�������Ϣ
	virtual void OnRtnExtraManualParentOrder(CFocusFtdcExtraManualParentOrderField *pExtraManualParentOrder) {};

	///�г���Ʒ����ʱ���ѯӦ��
	virtual void OnRspQryMarketTradingTime(CFocusFtdcMarketTradingPeriodInfoField *pMarketTradingPeriodInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����㷨2��Ʊ�ڻ��Գ��ϵ��Ӧ��
	virtual void OnRspSetFutureStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ�㷨2��Ʊ�ڻ��Գ��ϵ�ڲ���
	virtual void OnRtnHighInnerFutureStrategyTotalSecondRelation(CFocusFtdcInnerFutureStrategyTotalSecondRelationField *pInnerFutureStrategyTotalSecondRelation) {};

	///��ѯ�����㷨2���Թ�ϵ��Ӧ��
	virtual void OnRspQryAllTotalSecondStrategyRelation(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ɾ���㷨2��Ʊ���Բ���Ӧ��
	virtual void OnRspDelHighStockStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�㷨2�����ڲ����в��Թ�ϵ��Ӧ��
	virtual void OnRspQryAllInnerTotalSecondStrategyRelation(CFocusFtdcInnerFutureStrategyTotalSecondRelationField *pInnerFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯĸ����չ��ϸ��ϢӦ��
	virtual void OnRspQryParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯĸ���㷨������Ϣ����Ӧ��
	virtual void OnRspQryParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ĸ����չ��ϸ��ϢӦ��
	virtual void OnRtnParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage) {};

	///����ĸ���㷨������Ϣ����Ӧ��
	virtual void OnRspSetParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ��ĸ���㷨������Ϣ����Ӧ��
	virtual void OnRspDelParentOrderStaticParam(CFocusFtdcParentOrderIndexField *pParentOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯJava ALGO����״̬Ӧ��
	virtual void OnRspQryJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Java ALGO״̬֪ͨ
	virtual void OnRtnJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus) {};

	///��ѯ�����˻���ϵ��Ӧ��
	virtual void OnRspQryFuSkAccountRelation(CFocusFtdcFuSkAccountRelationField *pFuSkAccountRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ʊ��������¼������Ӧ��
	virtual void OnRspBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ʊ������������Ӧ��
	virtual void OnRspBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����˻���ϢӦ��
	virtual void OnRspSetUserInvestorSeatBasePasswd(CFocusFtdcUserInvestorSeatBaseField *pUserInvestorSeatBase, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ���ڲ���ԭʼ��������
	virtual void OnRtnSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) {};

	///֪ͨ�޸Ŀ��ڲ���ԭʼ��������
	virtual void OnRtnAmendPSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) {};

	///��ѯδ���ĸ����ϢӦ��
	virtual void OnRspQryUnFinshPutureOrder(CFocusFtdcUnFinshPutureOrderField *pUnFinshPutureOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�����Ӧ��
	virtual void OnRspQryTodayTayoutDetails(CFocusFtdcTodayTayoutDetailsField *pTodayTayoutDetails, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class USER_API_EXPORT CFocusFtdcUserApi
{
public:
	///����UserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@param pszUserApiType UserAPI����
	///@return ��������UserApi
	static CFocusFtdcUserApi *CreateFtdcUserApi(const char *pszFlowPath = "",
											const char *pszUserApiType = "");
	
	///��ȡϵͳ�汾��
	///@param nMajorVersion ���汾��
	///@param nMinorVersion �Ӱ汾��
	///@return ϵͳ��ʶ�ַ���
	static const char *GetVersion();
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;

	//�ಥ���ÿ���
	virtual void SetMultiCast(bool bMultiCast=false) = 0;
	virtual void RegMultiTopicID(int TopicID)=0;
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init(int nPrivatePort) = 0;
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;
	
	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	///@remark RegisterFront������RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CFocusFtdcUserSpi *pSpi) = 0;
	
	///�����г����顣
	///@param nTopicID �г���������  
	///@param nResumeType �г������ش���ʽ  
	///        FOCUS_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        FOCUS_TERT_RESUME:���ϴ��յ�������
	///        FOCUS_TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribeMarketDataTopic(int nTopicID, FOCUS_TE_RESUME_TYPE nResumeType) = 0;

	///����˽������
	///@param nResumeType ˽�����ش���ʽ  
	///        FOCUS_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        FOCUS_TERT_RESUME:���ϴ��յ�������
	///        FOCUS_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribePrivateTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ĺ�������
	///@param nResumeType �������ش���ʽ  
	///        FOCUS_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        FOCUS_TERT_RESUME:���ϴ��յ�������
	///        FOCUS_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribePublicTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ľ���Ա����
	///@param nResumeType ����Ա���ش���ʽ  
	///        FOCUS_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        FOCUS_TERT_RESUME:���ϴ��յ�������
	///        FOCUS_TERT_QUICK:ֻ���͵�¼����Ա��������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�����Ա�������ݡ�
	virtual void SubscribeUserTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ľ��׺�Լ
	///@param char *ppInstrumentID[] ���ĺ�Լ�б�
	///@param nCount ��������
	///@return 0 �����ɹ�
	virtual int SubInstrumentStatus(char *ppInstrumentID[], int nCount) = 0;
	
	///ȡ�����Ľ��׺�Լ
	///@param char *ppInstrumentID[] ���ĺ�Լ�б�
	///@param nCount ��������
	///@return 0 �����ɹ�
	virtual int UnSubInstrumentStatus(char *ppInstrumentID[], int nCount) = 0;	
	
	///���ĺ�Լ���顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int SubMarketData(char *ppInstrumentID[], int nCount)=0;

	///�˶���Լ���顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubMarketData(char *ppInstrumentID[], int nCount)=0;	
	
	
	///����������ʱʱ�䡣
	///@param timeout ������ʱʱ��(��)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	///��������־�ļ�
	///@param pszReqLogFileName ������־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenRequestLog(const char *pszReqLogFileName) = 0;

	///��Ӧ����־�ļ�
	///@param pszRspLogFileName Ӧ����־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenResponseLog(const char *pszRspLogFileName) = 0;
	
	///��ִ��׷����־�ļ�
	///@param pszRspLogFileName ׷����־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenTraceLog(const char *pszTraceLogFileName) = 0;

	///�û���¼����
	virtual int ReqUserLogin(CFocusFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///�û��˳�����
	virtual int ReqUserLogout(CFocusFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///�û������޸�����
	virtual int ReqUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///ǿ���û��˳�����
	virtual int ReqForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///�û��Ựɾ������
	virtual int ReqForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///���󵼳��ڴ����ݿ�
	virtual int ReqDumpMemDB(CFocusFtdcMemDBField *pMemDB, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CFocusFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///������������
	virtual int ReqOrderAction(CFocusFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///Ͷ�����ʽ��ʻ����������
	virtual int ReqAccountDeposit(CFocusFtdcReqAccountDepositField *pReqAccountDeposit, int nRequestID) = 0;

	///Ͷ����Ȩ������
	virtual int ReqInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, int nRequestID) = 0;

	///ʵʱ�ϳ�����
	virtual int ReqTBCommand(CFocusFtdcTBCommandField *pTBCommand, int nRequestID) = 0;

	///���ز�������
	virtual int ReqPingPong(CFocusFtdcPingPongField *pPingPong, int nRequestID) = 0;

	///����ģʽ��������
	virtual int ReqSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, int nRequestID) = 0;

	///���ĺ�Լ�������Ϣ
	virtual int ReqSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///�˶���Լ�������Ϣ
	virtual int ReqUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///Topic��ѯ����
	virtual int ReqTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, int nRequestID) = 0;

	///������ѯ����
	virtual int ReqQryOrder(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///����Ͷ�����˻���ѯ����
	virtual int ReqQryUserInvestor(CFocusFtdcQryUserInvestorField *pQryUserInvestor, int nRequestID) = 0;

	///Ͷ�����ʽ��˻���ѯ����
	virtual int ReqQryInvestorAccount(CFocusFtdcQryInvestorAccountField *pQryInvestorAccount, int nRequestID) = 0;

	///��Լ��ѯ����
	virtual int ReqQryInstrument(CFocusFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///��������ѯ����
	virtual int ReqQryExchange(CFocusFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///Ͷ���ֲֲ߳�ѯ����
	virtual int ReqQryInvestorPosition(CFocusFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///������������
	virtual int ReqSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryTopic(CFocusFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///�û���ѯ����
	virtual int ReqQryUser(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///Ͷ�����������ʲ�ѯ����
	virtual int ReqQryInvestorFee(CFocusFtdcQryInvestorFeeField *pQryInvestorFee, int nRequestID) = 0;

	///Ͷ���߱�֤���ʲ�ѯ����
	virtual int ReqQryInvestorMargin(CFocusFtdcQryInvestorMarginField *pQryInvestorMargin, int nRequestID) = 0;

	///Ͷ���߼����ϵ��ѯ
	virtual int ReqQryInvestor(CFocusFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///�˺ŷ���״����ѯ
	virtual int ReqQryAccountRisk(CFocusFtdcQryAccountRiskField *pQryAccountRisk, int nRequestID) = 0;

	///�����û��Ự��ѯ
	virtual int ReqQryUserSession(CFocusFtdcQryUserSessionField *pQryUserSession, int nRequestID) = 0;

	///��Լ�����ѯ
	virtual int ReqQryMarketData(CFocusFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///Ͷ���߼����ϵ��ѯ����
	virtual int ReqQryInvestorRelation(CFocusFtdcQryInvestorRelationField *pQryInvestorRelation, int nRequestID) = 0;

	///��Ʒ��ѯ
	virtual int ReqQryProduct(CFocusFtdcQryProductField *pQryProduct, int nRequestID) = 0;

	///����������Ա��ѯ����
	virtual int ReqQryAdviceTrader(CFocusFtdcQryAdviceTraderField *pQryAdviceTrader, int nRequestID) = 0;

	///���ɽ���������ѯ����
	virtual int ReqQryMaxVolume(CFocusFtdcQryMaxVolumeField *pQryMaxVolume, int nRequestID) = 0;

	///��ϳֲ���ϸ��ѯ����
	virtual int ReqQryCmbPositionDetail(CFocusFtdcQryCmbPositionDetailField *pQryCmbPositionDetail, int nRequestID) = 0;

	///Ͷ���߽�������ѯ����
	virtual int ReqQrySettlementInfo(CFocusFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID) = 0;

	///���ĺ�Լ�������Ϣ
	virtual int ReqSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, int nRequestID) = 0;

	///�˶���Լ�������Ϣ
	virtual int ReqUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, int nRequestID) = 0;

	///�������ҳ��ѯ����
	virtual int ReqQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, int nRequestID) = 0;

	///������ѯ����(��ҳ)
	virtual int ReqQryOrderPage(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///�ɽ�����ѯ����(��ҳ)
	virtual int ReqQryTradePage(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///Ͷ���ֲֲ߳�ѯ����(��ҳ)
	virtual int ReqQryInvestorPositionPage(CFocusFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///�ֲ���ϸ��ѯ����
	virtual int ReqQryInvestorPositionDetail(CFocusFtdcQryPositionDetailField *pQryPositionDetail, int nRequestID) = 0;

	///���ö��۲�������
	virtual int ReqSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, int nRequestID) = 0;

	///������Ȩ���۲���������
	virtual int ReqSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, int nRequestID) = 0;

	///���㵥����Ȩ����
	virtual int ReqCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, int nRequestID) = 0;

	///�����ϰ���Ȩ����
	virtual int ReqCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, int nRequestID) = 0;

	///��������ģ��
	virtual int ReqMarketDataTest(CFocusFtdcDepthMarketDataField *pDepthMarketData, int nRequestID) = 0;

	///�������������
	virtual int ReqVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, int nRequestID) = 0;

	///Wingģ�Ͳ�����ѯ����
	virtual int ReqQryWingModelParam(CFocusFtdcQryWingModelParamField *pQryWingModelParam, int nRequestID) = 0;

	///Wingģ�Ͳ�����������
	virtual int ReqSetWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, int nRequestID) = 0;

	///��ѯ���в�������
	virtual int ReqQryMarkerStrategySet(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///�޸����в�������
	virtual int ReqUpMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, int nRequestID) = 0;

	///��ѯ�û���������
	virtual int ReqQryUserSwitch(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///�����û�����
	virtual int ReqUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, int nRequestID) = 0;

	///��ѯ�Գ����
	virtual int ReqQryMarkerHedge(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///�޸ĶԳ����
	virtual int ReqUpMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, int nRequestID) = 0;

	///��ϲ�����ѯ����
	virtual int ReqQryFittingParam(CFocusFtdcQryFittingParamField *pQryFittingParam, int nRequestID) = 0;

	///��ϲ�����������
	virtual int ReqSetFittingParam(CFocusFtdcFittingParamField *pFittingParam, int nRequestID) = 0;

	///��ѯ���۲�������
	virtual int ReqQryPricingParam(CFocusFtdcQryPricingParamField *pQryPricingParam, int nRequestID) = 0;

	///��ѯ��Ȩ���۲���������
	virtual int ReqQryOptionTheoryVol(CFocusFtdcQryOptionTheoryVolField *pQryOptionTheoryVol, int nRequestID) = 0;

	///����¼������
	virtual int ReqQuoteInsert(CFocusFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///���۲�������
	virtual int ReqQuoteAction(CFocusFtdcQuoteActionField *pQuoteAction, int nRequestID) = 0;

	///���۲�ѯ����
	virtual int ReqQryQuote(CFocusFtdcQryQuoteField *pQryQuote, int nRequestID) = 0;

	///ѯ������
	virtual int ReqForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote, int nRequestID) = 0;

	///���󱨵���ѯ����
	virtual int ReqQryOrderInsertFailed(CFocusFtdcQryOrderInsertFailedField *pQryOrderInsertFailed, int nRequestID) = 0;

	///��ճɽ���ֵ����
	virtual int ReqCleanQuoteThresHold(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, int nRequestID) = 0;

	///���ۺ�Լ�۲�����
	virtual int ReqSetPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, int nRequestID) = 0;

	///���ۺ�Լ�۲��ѯ
	virtual int ReqQryPriceSpread(CFocusFtdcQryPriceSpreadField *pQryPriceSpread, int nRequestID) = 0;

	///ɾ���û����۲���
	virtual int ReqDelPricingParam(CFocusFtdcPricingParamField *pPricingParam, int nRequestID) = 0;

	///ɾ�����в��Բ���
	virtual int ReqDelMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, int nRequestID) = 0;

	///��������Ԥ������
	virtual int ReqSetAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, int nRequestID) = 0;

	///��ѯ����Ԥ������
	virtual int ReqQryAlertParam(CFocusFtdcQryAlertIndexSetParamField *pQryAlertIndexSetParam, int nRequestID) = 0;

	///��ѯ����Ԥ��ָ��ֵ
	virtual int ReqQryAlertData(CFocusFtdcQryAlertIndexSetParamField *pQryAlertIndexSetParam, int nRequestID) = 0;

	///ɾ����Ȩ���۲���������
	virtual int ReqDelOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, int nRequestID) = 0;

	///ɾ���Գ��������
	virtual int ReqDelMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, int nRequestID) = 0;

	///���б��ۿ����������
	virtual int ReqSetMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, int nRequestID) = 0;

	///ɾ�����б��ۿ����������
	virtual int ReqDelMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, int nRequestID) = 0;

	///ɾ������Ԥ������
	virtual int ReqDelAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, int nRequestID) = 0;

	///�������б����ƶ�����
	virtual int ReqSetQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, int nRequestID) = 0;

	///ɾ�����б����ƶ�����
	virtual int ReqDelQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, int nRequestID) = 0;

	///�ָ����۲����б���ƫ��
	virtual int ReqRebackQuote(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, int nRequestID) = 0;

	///��������ѯ����
	virtual int ReqQryDepMarketData(CFocusFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///��ѯƫ�Ʊ��۲���
	virtual int ReqQryQuoteMove(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///��ѯ���б��ۿ�����û�����Ϣ
	virtual int ReqQryBaseMarkerStep(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///��ѯ���б��ۿ���ݶ�
	virtual int ReqQryMarkerStep(CFocusFtdcBaseMarkerStepField *pBaseMarkerStep, int nRequestID) = 0;

	///��ѯ��̨���̽���״̬
	virtual int ReqFocusStatus(CFocusFtdcFocusStatusField *pFocusStatus, int nRequestID) = 0;

	///�����ڻ������ܿ���
	virtual int ReqSetFutureMakerWholeSwitch(CFocusFtdcFutureMakerWholeSwitchField *pFutureMakerWholeSwitch, int nRequestID) = 0;

	///�����ڻ����б��۲���
	virtual int ReqSetFutureMakerStrategy(CFocusFtdcFutureMakerStrategyField *pFutureMakerStrategy, int nRequestID) = 0;

	///���������ڻ����ֶԳ����
	virtual int ReqSetSlefHedgeStrategy(CFocusFtdcSlefHedgeStrategyField *pSlefHedgeStrategy, int nRequestID) = 0;

	///���������ڻ��Գ��Լ�Գ����
	virtual int ReqSetFutureHedgeStrategy(CFocusFtdcFutureHedgeStrategyField *pFutureHedgeStrategy, int nRequestID) = 0;

	///�����������б��۶����������
	virtual int ReqSetQuoteAdditionParm(CFocusFtdcQuoteAdditionParmField *pQuoteAdditionParm, int nRequestID) = 0;

	///����һ�����������ڻ����жԳ嵥
	virtual int ReqStopAllFutureMakerHedgeOffer(CFocusFtdcStopAllFutureMakerHedgeOfferField *pStopAllFutureMakerHedgeOffer, int nRequestID) = 0;

	///��ѯ�ڻ����в���
	virtual int ReqQryFutureMakerStrategy(CFocusFtdcFutureMakerIndexField *pFutureMakerIndex, int nRequestID) = 0;

	///��ѯ���и����ڲ���Ƶ���Ա���ϸ��Ϣ����
	virtual int ReqQryAllInnerHighStockStrategy(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, int nRequestID) = 0;

	///��������������Ʊ���Կ���
	virtual int ReqSetHighStockStrategySwitch(CFocusFtdcWholeHighStockStrategySwitchField *pWholeHighStockStrategySwitch, int nRequestID) = 0;

	///�����ѯ�ò��Ե����й�Ʊ��Ա
	virtual int ReqQryAllAPIHighStockStrategy(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, int nRequestID) = 0;

	///�����ѯ������Ʊ��������
	virtual int ReqQrySignalAPIHighStockStrategy(CFocusFtdcQrySignalHighStockStrategyField *pQrySignalHighStockStrategy, int nRequestID) = 0;

	///�������õ�����Ʊ���Կ���
	virtual int ReqSetSignalHighStockStrategySwitch(CFocusFtdcSignalHighStockStrategySwitchField *pSignalHighStockStrategySwitch, int nRequestID) = 0;

	///�������ù�Ʊ���Բ���
	virtual int ReqSetHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, int nRequestID) = 0;

	///�����ѯ���в��Թ�ϵ��
	virtual int ReqQryAllStrategyRelation(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///�������õ�����Ʊ���Բ���
	virtual int ReqSetAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, int nRequestID) = 0;

	///����ɾ����Ʊ���Բ���
	virtual int ReqDelHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, int nRequestID) = 0;

	///����ɾ�����ɹ�Ʊ����
	virtual int ReqDelAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, int nRequestID) = 0;

	///�����ѯ��Ʊ���׽׶��µ���ʽ����
	virtual int ReqQryAllTradingPeriodStrategy(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, int nRequestID) = 0;

	///�������ù�Ʊ���׽׶��µ���ʽ����
	virtual int ReqSetTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, int nRequestID) = 0;

	///����ɾ����Ʊ���׽׶��µ���ʽ����
	virtual int ReqDelTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, int nRequestID) = 0;

	///��ѯ��Ʊ�ڻ��Գ��ϵ�ڲ�����ϸ��Ϣ����
	virtual int ReqQryAllInnerStrategyRelation(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///���������и��ʽ�ŵ�δ�ɽ���Ʊ�����ҽ�������Ϊfalse
	virtual int ReqCancelAllStrategyRelationOrder(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, int nRequestID) = 0;

	///������ع��Զ���������
	virtual int ReqSetAutoReBuySwitch(CFocusFtdcRelationAutoReBuySwitchField *pRelationAutoReBuySwitch, int nRequestID) = 0;

	///�����ڻ��㷨����
	virtual int ReqSendFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, int nRequestID) = 0;

	///�����㷨����
	virtual int ReqSetAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, int nRequestID) = 0;

	///��ѯ�㷨����
	virtual int ReqQryAlgoParm(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///��ѯ�ڻ��㷨����
	virtual int ReqQryFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///��ѯ�㷨��������
	virtual int ReqQryInnerFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///���ò�����Ϣ�ź�
	virtual int ReqSetStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal, int nRequestID) = 0;

	///��ѯ�����ź�
	virtual int ReqQryIndexDirSignal(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///ɾ���ڻ��㷨����
	virtual int ReqDelFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///ɾ���㷨����
	virtual int ReqDelAlgoParm(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///���ÿ��ڲ���
	virtual int ReqSetSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, int nRequestID) = 0;

	///��ѯ���ڲ���
	virtual int ReqQrySpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyIndexField *pSpreadInstrStrategyIndex, int nRequestID) = 0;

	///ɾ�����ڲ���
	virtual int ReqDelSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyIndexField *pSpreadInstrStrategyIndex, int nRequestID) = 0;

	///��ѯ���ڲ���
	virtual int ReqQryInnerSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyIndexField *pSpreadInstrStrategyIndex, int nRequestID) = 0;

	///��������list���������
	virtual int ReqSetTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, int nRequestID) = 0;

	///�����ѯ����list��Ա
	virtual int ReqQryTZeroHighStockStrategy(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, int nRequestID) = 0;

	///���ÿɽ����ڻ���Լ
	virtual int ReqSetfutruetradeinstr(CFocusFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///�����ѯ�����ڻ���ʼ���ʽ�
	virtual int ReqQryFlowerFutureTargetMoney(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///�������ø����ڻ���ʼ���ʽ�
	virtual int ReqSetFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, int nRequestID) = 0;

	///����ĸ����չ��ϸ��Ϣ
	virtual int ReqSetParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage, int nRequestID) = 0;

	///��ѯ�г���Ʒ����ʱ��
	virtual int ReqQryMarketTradingTime(CFocusFtdcAPIQryMarketTradingTimeField *pAPIQryMarketTradingTime, int nRequestID) = 0;

	///���������㷨2��Ʊ�ڻ��Գ��ϵ�����
	virtual int ReqSetFutureStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, int nRequestID) = 0;

	///�����ѯ�㷨2���в��Թ�ϵ��
	virtual int ReqQryAllTotalSecondStrategyRelation(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///����ɾ���㷨2��Ʊ���Բ���
	virtual int ReqDelHighStockStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, int nRequestID) = 0;

	///�����ѯ�㷨2�����ڲ����Թ�ϵ��
	virtual int ReqQryAllInnerTotalSecondStrategyRelation(CFocusFtdcQryAllHighFutureStrategyRelationField *pQryAllHighFutureStrategyRelation, int nRequestID) = 0;

	///�����ѯĸ����չ��ϸ��Ϣ
	virtual int ReqQryParentDetialUpdateMessage(CFocusFtdcParentOrderDetialIndexField *pParentOrderDetialIndex, int nRequestID) = 0;

	///�����ѯĸ���㷨������Ϣ����
	virtual int ReqQryParentOrderStaticParam(CFocusFtdcParentOrderIndexField *pParentOrderIndex, int nRequestID) = 0;

	///�������ĸ���㷨������Ϣ����
	virtual int ReqSetParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, int nRequestID) = 0;

	///����ɾ��ĸ���㷨������Ϣ����
	virtual int ReqDelParentOrderStaticParam(CFocusFtdcParentOrderIndexField *pParentOrderIndex, int nRequestID) = 0;

	///��ѯJava ALGO���̽���״̬
	virtual int ReqQryJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, int nRequestID) = 0;

	///����Java ALGO����״̬
	virtual int ReqSetJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, int nRequestID) = 0;

	///��ѯ�����˻���ϵ��
	virtual int ReqQryFuSkAccountRelation(CFocusFtdcFuSkAccountRelationField *pFuSkAccountRelation, int nRequestID) = 0;

	///��Ʊ��������¼������
	virtual int ReqBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, int nRequestID) = 0;

	///��Ʊ������������
	virtual int ReqBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, int nRequestID) = 0;

	///�����˻���Ϣ
	virtual int ReqSetUserInvestorSeatBasePasswd(CFocusFtdcUserInvestorSeatBaseField *pUserInvestorSeatBase, int nRequestID) = 0;

	///��ѯδ���ĸ����Ϣ
	virtual int ReqQryUnFinshPutureOrder(CFocusFtdcParentOrderIndexField *pParentOrderIndex, int nRequestID) = 0;

	///��ѯ�����
	virtual int ReqQryTodayTayoutDetails(CFocusFtdcQryTodayTayoutDetailsIndexField *pQryTodayTayoutDetailsIndex, int nRequestID) = 0;
protected:
	~CFocusFtdcUserApi(){};
};

#endif
