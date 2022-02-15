/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company ɽ��֤ȯ�ɷ����޹�˾  ����������Ʒ��
///@author �˺�
///@file FocusFtdcTraderApi.h
///@brief �����˿ͻ��˽ӿ�
///@history
///20150520	���һ�	�������ļ�
///20170517	�˺�	��������Ȩ������ؽӿ�
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
	

	///����Ӧ��
	virtual void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ��ر�
	virtual void OnRtnTrade(CFocusFtdcTradeField *pTrade) {};

	///�����ر�
	virtual void OnRtnOrder(CFocusFtdcOrderField *pOrder) {};

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) {};

	///������Ϣ֪ͨ
	virtual void OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) {};

	///������ѯӦ��
	virtual void OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

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

	///��ƷӦ��
	virtual void OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������־����
	virtual void OnRtnStrategyLog(CFocusFtdcStrategyLogField *pStrategyLog) {};

	///Ͷ���ֲ߳�����
	virtual void OnRtnInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition) {};

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

	///��Ʊ��������¼������Ӧ��
	virtual void OnRspBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ʊ������������Ӧ��
	virtual void OnRspBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨ���ڲ���ԭʼ��������
	virtual void OnRtnSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) {};

	///֪ͨ�޸Ŀ��ڲ���ԭʼ��������
	virtual void OnRtnAmendPSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) {};
};

class TRADER_API_EXPORT CFocusFtdcTraderApi
{
public:
	///����TraderApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	static CFocusFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");
	
	///��ȡϵͳ�汾��
	///@param nMajorVersion ���汾��
	///@param nMinorVersion �Ӱ汾��
	///@return ϵͳ��ʶ�ַ���
	static const char *GetVersion();
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
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
	virtual void RegisterSpi(CFocusFtdcTraderSpi *pSpi) = 0;
	
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
	

	///�û���¼����
	virtual int ReqUserLogin(CFocusFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///�û��˳�����
	virtual int ReqUserLogout(CFocusFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CFocusFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///������������
	virtual int ReqOrderAction(CFocusFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///������ѯ����
	virtual int ReqQryOrder(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

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

	///��Ʒ��ѯ
	virtual int ReqQryProduct(CFocusFtdcQryProductField *pQryProduct, int nRequestID) = 0;

	///����ĸ����չ��ϸ��Ϣ
	virtual int ReqSetParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage, int nRequestID) = 0;

	///��ѯ�г���Ʒ����ʱ��
	virtual int ReqQryMarketTradingTime(CFocusFtdcAPIQryMarketTradingTimeField *pAPIQryMarketTradingTime, int nRequestID) = 0;

	///����Java ALGO����״̬
	virtual int ReqSetJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, int nRequestID) = 0;

	///��Ʊ��������¼������
	virtual int ReqBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, int nRequestID) = 0;

	///��Ʊ������������
	virtual int ReqBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, int nRequestID) = 0;
protected:
	~CFocusFtdcTraderApi(){};
};

#endif
