/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company ɽ��֤ȯ�ɷ����޹�˾����������Ʒ��
///@file QdFtdcMduserApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
///20130520	�˺�	�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef QD_FTDCMDUSERAPI_H
#define QD_FTDCMDUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QdFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_MDUSER_API_EXPORT
#define MDUSER_API_EXPORT __declspec(dllexport)
#else
#define MDUSER_API_EXPORT __declspec(dllimport)
#endif
#else
#define MDUSER_API_EXPORT 
#endif

class CQdFtdcMduserSpi
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

	//�����ಥ�����ӿ� add by zbz 20150304
	virtual void  OnMultiHeartbeat(char *CurrTime,char *MultiCastIP) {};

	//���㲥�յ�ֵ��ʱ�򣬻ص����������ã�����qmdata
	virtual void UdpMarketData(CQdFtdcDepthMarketDataField *qmdata){};

	///����Ӧ��
	virtual void OnRspError(CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CQdFtdcRspUserLoginField *pRspUserLogin, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CQdFtdcRspUserLogoutField *pRspUserLogout, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CQdFtdcDepthMarketDataField *pDepthMarketData) {};

	///�������֪ͨ
	virtual void OnRtnMultiDepthMarketData(CQdFtdcDepthMarketDataField *pDepthMarketData) {};

	///���ĺ�Լ�������Ϣ
	virtual void OnRspSubMarketData(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˶���Լ�������Ϣ
	virtual void OnRspUnSubMarketData(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ּ�����
	virtual void OnRtnMBLMarketData(CQdFtdcMBLMarketDataField *pMBLMarketData) {};

	///֣�ݺ�Լ״̬
	virtual void OnRtnQmdInstrumentStatu(CQdFtdcQmdInstrumentStateField *pQmdInstrumentState) {};

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CQdFtdcDisseminationField *pDissemination, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯӦ��
	virtual void OnRspQryTopic(CQdFtdcDisseminationField *pDissemination, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ����Ӧ��
	virtual void OnRspQryMarketData(CQdFtdcRspMarketDataField *pRspMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�г���Լ�б��ѯӦ��
	virtual void OnRspQryInstrumentList(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///DCE��Level2�������֪ͨ
	virtual void OnRtnTenEntrust(CQdFtdcMDTenDepthMarketDataField *pMDTenDepthMarketData) {};

	///��Ȩ����֪ͨ
	virtual void OnRtnOptionIndexData(CQdFtdcOptionIndexDataField *pOptionIndexData) {};

	///��������֪ͨ
	virtual void OnRtnDepthMinMarketData(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData) {};

	///���������ѯӦ��
	virtual void OnRspQryMinMarketData(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������֪ͨ��Ƭ(�������鵽������)
	virtual void OnRtnDepthOneMinBarSlice(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData) {};

	///��ѯst��ƱӦ��
	virtual void OnRspQryStInstrument(CQdFtdcQryMarketDataField *pQryMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ʳɽ�����
	virtual void OnRtnTradeMaketData(CQdFtdcDeptTradeMaketDataField *pDeptTradeMaketData) {};

	///���ί������
	virtual void OnRtnOrderMaketData(CQdFtdcDeptOrderMaketDataField *pDeptOrderMaketData) {};
};

class MDUSER_API_EXPORT CQdFtdcMduserApi
{
public:
	///����MduserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	static CQdFtdcMduserApi *CreateFtdcMduserApi(const char *pszFlowPath = "");
	
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

	//ע��ಥ��ַ
	virtual void RegTopicMultiAddr(char *pMultiAddr)=0;
	
	
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
	virtual void RegisterSpi(CQdFtdcMduserSpi *pSpi) = 0;

	///�����г����顣
	///@param nTopicID �г���������  
	///@param nResumeType �г������ش���ʽ  
	///        QD_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        QD_TERT_RESUME:���ϴ��յ�������(�Ƕ���ȫ����Լʱ����֧������ģʽ)
	///        QD_TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribeMarketDataTopic(int nTopicID, QD_TE_RESUME_TYPE nResumeType) = 0;

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
	
	///�����ڴ�ȡֵ
	///@param CQdFtdcShmDepthMarketDataField  �������
	///@param CQdFtdcDepthMarketDataField ��ѯ��������ֵ
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual void ShmMarketData(CQdFtdcShmDepthMarketDataField *reqfield,CQdFtdcDepthMarketDataField *defdata) = 0;
	
    ///����UDP����
	///@param  udpip�㲥��ַ
	///@return 0 �����ɹ�
	///@return -1 ��ȡUDPʧ��
	virtual  void setudpchannel(char *udpip)= 0;

	///�û���¼����
	virtual int ReqUserLogin(CQdFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///�û��˳�����
	virtual int ReqUserLogout(CQdFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///���ĺ�Լ�������Ϣ
	virtual int ReqSubMarketData(CQdFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///�˶���Լ�������Ϣ
	virtual int ReqUnSubMarketData(CQdFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///������������
	virtual int ReqSubscribeTopic(CQdFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryTopic(CQdFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///��Լ�����ѯ
	virtual int ReqQryMarketData(CQdFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///�г���Լ�б��ѯ����
	virtual int ReqQryInstrumentList(CQdFtdcMarketDataExchangeIDField *pMarketDataExchangeID, int nRequestID) = 0;

	///���������ѯ����
	virtual int ReqQryMinMarketData(CQdFtdcQryMinMarketDataField *pQryMinMarketData, int nRequestID) = 0;

	///��ѯst��Ʊ
	virtual int ReqQryStInstrument(CQdFtdcMarketDataExchangeIDField *pMarketDataExchangeID, int nRequestID) = 0;

	//�����ಥ
	//���޷���¼������������£����ô˽ӿڿ��Խ����鲥����
	//�ڿ��Ե�¼�������������ô˽ӿ�
	//@param TradingDay �����գ���û�е�¼������£���������Ȼ�գ�����Ҫע�⽻�����Ľ�����
	virtual void ActiveMultiMarketData(char * TradingDay) = 0;
protected:
	~CQdFtdcMduserApi(){};
};

#endif
