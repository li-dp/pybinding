/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company ɽ��֤ȯ�ɷ����޹�˾
///@file QdFtdcUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 20190711 �˺�
/////////////////////////////////////////////////////////////////////////

#if !defined(Qd_FTDCSTRUCT_H)
#define Qd_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QdFtdcUserApiDataType.h"

///��Ӧ��Ϣ
struct CQdFtdcRspInfoField
{
	///�������
	TQdFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdFtdcErrorMsgType	ErrorMsg;
};

///Qdp��Ӧ��Ϣ
struct CQdFtdcQdpRspInfoField
{
	///�������
	TQdFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdFtdcQdpErrorMsgType	ErrorMsg;
};

///ϵͳ�û���¼����
struct CQdFtdcReqUserLoginField
{
	///������
	TQdFtdcDateType	TradingDay;
	///�����û�����
	TQdFtdcUserIDType	UserID;
	///���͹�˾���
	TQdFtdcBrokerIDType	BrokerID;
	///����
	TQdFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TQdFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQdFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQdFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TQdFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TQdFtdcMacAddressType	MacAddress;
	///�������Ĵ���
	TQdFtdcDataCenterIDType	DataCenterID;
	///��̬����
	TQdFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TQdFtdcIPAddressType	ClientIPAddress;
	///��Ȩ����
	TQdFtdcAuthCodeType	AuthCode;
};

///Qdpϵͳ�û���¼����
struct CQdFtdcQdpReqUserLoginField
{
	///������
	TQdFtdcDateType	TradingDay;
	///�����û�����
	TQdFtdcQdpUserIDType	UserID;
	///���͹�˾���
	TQdFtdcBrokerIDType	BrokerID;
	///����
	TQdFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TQdFtdcQdpProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQdFtdcQdpProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQdFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TQdFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TQdFtdcMacAddressType	MacAddress;
	///�������Ĵ���
	TQdFtdcDataCenterIDType	DataCenterID;
	///��̬����
	TQdFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TQdFtdcIPAddressType	ClientIPAddress;
};

///ϵͳ�û���¼Ӧ��
struct CQdFtdcRspUserLoginField
{
	///������
	TQdFtdcDateType	TradingDay;
	///���͹�˾���
	TQdFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdFtdcUserIDType	UserID;
	///��¼�ɹ�ʱ��
	TQdFtdcTimeType	LoginTime;
	///�û���󱾵ر�����
	TQdFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///����ϵͳ����
	TQdFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TQdFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TQdFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TQdFtdcSequenceNoType	UserFlowSize;
	///��¼������Ϣ
	TQdFtdcLoginInfoType	LoginInfo;
	///�Ự���
	TQdFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TQdFtdcFrontIDType	FrontID;
};

///Qdpϵͳ�û���¼Ӧ��
struct CQdFtdcQdpRspUserLoginField
{
	///������
	TQdFtdcDateType	TradingDay;
	///���͹�˾���
	TQdFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdFtdcQdpUserIDType	UserID;
	///��¼�ɹ�ʱ��
	TQdFtdcTimeType	LoginTime;
	///�û���󱾵ر�����
	TQdFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///����ϵͳ����
	TQdFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TQdFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TQdFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TQdFtdcSequenceNoType	UserFlowSize;
	///�Ự���
	TQdFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TQdFtdcFrontIDType	FrontID;
};

///�û��ǳ�����
struct CQdFtdcReqUserLogoutField
{
	///���͹�˾���
	TQdFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdFtdcUserIDType	UserID;
};

///�û��ǳ�����
struct CQdFtdcRspUserLogoutField
{
	///���͹�˾���
	TQdFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdFtdcUserIDType	UserID;
};

///�����������
struct CQdFtdcMarketDataBaseField
{
	///������
	TQdFtdcTradingDayType	TradingDay;
	///�����
	TQdFtdcPriceType	PreSettlementPrice;
	///������
	TQdFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdFtdcRatioType	PreDelta;
};

///Qdp�����������
struct CQdFtdcQdpMarketDataBaseField
{
	///������
	TQdFtdcTradingDayType	TradingDay;
	///���������
	TQdFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQdFtdcSettlementIDType	SettlementID;
	///�����
	TQdFtdcPriceType	PreSettlementPrice;
	///������
	TQdFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdFtdcRatioType	PreDelta;
};

///���龲̬����
struct CQdFtdcMarketDataStaticField
{
	///����
	TQdFtdcPriceType	OpenPrice;
	///��߼�
	TQdFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdFtdcPriceType	LowestPrice;
	///������
	TQdFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdFtdcPriceType	LowerLimitPrice;
	///�����
	TQdFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CQdFtdcMarketDataLastMatchField
{
	///���¼�
	TQdFtdcPriceType	LastPrice;
	///����
	TQdFtdcVolumeType	Volume;
	///�ɽ�����
	TQdFtdcVolumeType	NumberVloume;
	///�ɽ����
	TQdFtdcMoneyType	Turnover;
	///�ֲ���
	TQdFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CQdFtdcMarketDataBestPriceField
{
	///�����һ
	TQdFtdcPriceType	BidPrice1;
	///������һ
	TQdFtdcVolumeType	BidVolume1;
	///������һ
	TQdFtdcPriceType	AskPrice1;
	///������һ
	TQdFtdcVolumeType	AskVolume1;
};

///�����������������
struct CQdFtdcMarketDataBid23Field
{
	///����۶�
	TQdFtdcPriceType	BidPrice2;
	///��������
	TQdFtdcVolumeType	BidVolume2;
	///�������
	TQdFtdcPriceType	BidPrice3;
	///��������
	TQdFtdcVolumeType	BidVolume3;
};

///������������������
struct CQdFtdcMarketDataAsk23Field
{
	///�����۶�
	TQdFtdcPriceType	AskPrice2;
	///��������
	TQdFtdcVolumeType	AskVolume2;
	///��������
	TQdFtdcPriceType	AskPrice3;
	///��������
	TQdFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CQdFtdcMarketDataBid45Field
{
	///�������
	TQdFtdcPriceType	BidPrice4;
	///��������
	TQdFtdcVolumeType	BidVolume4;
	///�������
	TQdFtdcPriceType	BidPrice5;
	///��������
	TQdFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CQdFtdcMarketDataAsk45Field
{
	///��������
	TQdFtdcPriceType	AskPrice4;
	///��������
	TQdFtdcVolumeType	AskVolume4;
	///��������
	TQdFtdcPriceType	AskPrice5;
	///��������
	TQdFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CQdFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdFtdcMillisecType	UpdateMillisec;
};

///�������
struct CQdFtdcDepthMarketDataField
{
	///������
	TQdFtdcTradingDayType	TradingDay;
	///�����
	TQdFtdcPriceType	PreSettlementPrice;
	///������
	TQdFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdFtdcRatioType	PreDelta;
	///����
	TQdFtdcPriceType	OpenPrice;
	///��߼�
	TQdFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdFtdcPriceType	LowestPrice;
	///������
	TQdFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdFtdcPriceType	LowerLimitPrice;
	///�����
	TQdFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdFtdcRatioType	CurrDelta;
	///���¼�
	TQdFtdcPriceType	LastPrice;
	///����
	TQdFtdcVolumeType	Volume;
	///�ɽ�����
	TQdFtdcVolumeType	NumberVloume;
	///�ɽ����
	TQdFtdcMoneyType	Turnover;
	///�ֲ���
	TQdFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdFtdcPriceType	BidPrice1;
	///������һ
	TQdFtdcVolumeType	BidVolume1;
	///������һ
	TQdFtdcPriceType	AskPrice1;
	///������һ
	TQdFtdcVolumeType	AskVolume1;
	///����۶�
	TQdFtdcPriceType	BidPrice2;
	///��������
	TQdFtdcVolumeType	BidVolume2;
	///�������
	TQdFtdcPriceType	BidPrice3;
	///��������
	TQdFtdcVolumeType	BidVolume3;
	///�����۶�
	TQdFtdcPriceType	AskPrice2;
	///��������
	TQdFtdcVolumeType	AskVolume2;
	///��������
	TQdFtdcPriceType	AskPrice3;
	///��������
	TQdFtdcVolumeType	AskVolume3;
	///�������
	TQdFtdcPriceType	BidPrice4;
	///��������
	TQdFtdcVolumeType	BidVolume4;
	///�������
	TQdFtdcPriceType	BidPrice5;
	///��������
	TQdFtdcVolumeType	BidVolume5;
	///��������
	TQdFtdcPriceType	AskPrice4;
	///��������
	TQdFtdcVolumeType	AskVolume4;
	///��������
	TQdFtdcPriceType	AskPrice5;
	///��������
	TQdFtdcVolumeType	AskVolume5;
	///�������
	TQdFtdcPriceType	BidPrice6;
	///��������
	TQdFtdcVolumeType	BidVolume6;
	///�������
	TQdFtdcPriceType	BidPrice7;
	///��������
	TQdFtdcVolumeType	BidVolume7;
	///��������
	TQdFtdcPriceType	AskPrice6;
	///��������
	TQdFtdcVolumeType	AskVolume6;
	///��������
	TQdFtdcPriceType	AskPrice7;
	///��������
	TQdFtdcVolumeType	AskVolume7;
	///����۰�
	TQdFtdcPriceType	BidPrice8;
	///��������
	TQdFtdcVolumeType	BidVolume8;
	///����۾�
	TQdFtdcPriceType	BidPrice9;
	///��������
	TQdFtdcVolumeType	BidVolume9;
	///�����۰�
	TQdFtdcPriceType	AskPrice8;
	///��������
	TQdFtdcVolumeType	AskVolume8;
	///�����۾�
	TQdFtdcPriceType	AskPrice9;
	///��������
	TQdFtdcVolumeType	AskVolume9;
	///�����ʮ
	TQdFtdcPriceType	BidPrice10;
	///������ʮ
	TQdFtdcVolumeType	BidVolume10;
	///������ʮ
	TQdFtdcPriceType	AskPrice10;
	///������ʮ
	TQdFtdcVolumeType	AskVolume10;
	///���볷������
	TQdFtdcVolumeType	WithdrawBuyNumber;
	///������������
	TQdFtdcVolumeType	WithdrawSellNumber;
	///���볷������
	TQdFtdcVolumeType	WithdrawBuyAmount;
	///���볷�����
	TQdFtdcPriceType	WithdrawBuyMoney;
	///������������
	TQdFtdcVolumeType	WithdrawSellAmount;
	///�����������
	TQdFtdcPriceType	WithdrawSellMoney;
	///�����ܱ���
	TQdFtdcVolumeType	TotalBidNumber;
	///�����ܱ���
	TQdFtdcVolumeType	TotalOfferNumber;
	///����ί�гɽ����ȴ�ʱ��ms
	TQdFtdcVolumeType	BidTradeMaxDuration;
	///����ί�гɽ����ȴ�ʱ��ms
	TQdFtdcVolumeType	OfferTradeMaxDuration;
	///ί�����
	TQdFtdcVolumeType	NumBidOrders;
	///ί������
	TQdFtdcVolumeType	NumOfferOrders;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdFtdcMillisecType	UpdateMillisec;
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///����������
	TQdFtdcVolumeType	VolumeAskLot;
	///����������
	TQdFtdcVolumeType	VolumeBidLot;
	///��Ȩƽ��ί��۸�
	TQdFtdcPriceType	WeightAvgBidPx;
	///��Ȩƽ��ί���۸�
	TQdFtdcPriceType	WeightAvgSellPx;
	///��Լ״̬
	TQdFtdcInstrumentStatusType	InstrumentStatus;
	///��ǰ����
	TQdFtdcTradingDayType	CalendarDate;
};

///�������
struct CQdFtdcQdpDepthMarketDataField
{
	///������
	TQdFtdcTradingDayType	TradingDay;
	///���������
	TQdFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQdFtdcSettlementIDType	SettlementID;
	///�����
	TQdFtdcPriceType	PreSettlementPrice;
	///������
	TQdFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdFtdcRatioType	PreDelta;
	///����
	TQdFtdcPriceType	OpenPrice;
	///��߼�
	TQdFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdFtdcPriceType	LowestPrice;
	///������
	TQdFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdFtdcPriceType	LowerLimitPrice;
	///�����
	TQdFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdFtdcRatioType	CurrDelta;
	///���¼�
	TQdFtdcPriceType	LastPrice;
	///����
	TQdFtdcVolumeType	Volume;
	///�ɽ�����
	TQdFtdcVolumeType	NumberVloume;
	///�ɽ����
	TQdFtdcMoneyType	Turnover;
	///�ֲ���
	TQdFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdFtdcPriceType	BidPrice1;
	///������һ
	TQdFtdcVolumeType	BidVolume1;
	///������һ
	TQdFtdcPriceType	AskPrice1;
	///������һ
	TQdFtdcVolumeType	AskVolume1;
	///����۶�
	TQdFtdcPriceType	BidPrice2;
	///��������
	TQdFtdcVolumeType	BidVolume2;
	///�������
	TQdFtdcPriceType	BidPrice3;
	///��������
	TQdFtdcVolumeType	BidVolume3;
	///�����۶�
	TQdFtdcPriceType	AskPrice2;
	///��������
	TQdFtdcVolumeType	AskVolume2;
	///��������
	TQdFtdcPriceType	AskPrice3;
	///��������
	TQdFtdcVolumeType	AskVolume3;
	///�������
	TQdFtdcPriceType	BidPrice4;
	///��������
	TQdFtdcVolumeType	BidVolume4;
	///�������
	TQdFtdcPriceType	BidPrice5;
	///��������
	TQdFtdcVolumeType	BidVolume5;
	///��������
	TQdFtdcPriceType	AskPrice4;
	///��������
	TQdFtdcVolumeType	AskVolume4;
	///��������
	TQdFtdcPriceType	AskPrice5;
	///��������
	TQdFtdcVolumeType	AskVolume5;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdFtdcMillisecType	UpdateMillisec;
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
};

///���ĺ�Լ�������Ϣ
struct CQdFtdcSpecificInstrumentField
{
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
};

///����������
struct CQdFtdcMarketDataExchangeIDField
{
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
};

///Qdp����������
struct CQdFtdcQdpMarketDataExchangeIDField
{
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
};

///�����ڴ������ѯ
struct CQdFtdcShmDepthMarketDataField
{
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TQdFtdcIPAddressType	IPAddress;
	///���ĺ�
	TQdFtdcTopicIDType	TopicID;
};

///TOPIC��ѯ
struct CQdFtdcTopicSearchField
{
	///���ĺ�
	TQdFtdcTopicIDType	TopicID;
};

///�ּ�����
struct CQdFtdcMBLMarketDataField
{
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdFtdcDirectionType	Direction;
	///�۸�
	TQdFtdcPriceType	Price;
	///����
	TQdFtdcVolumeType	Volume;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdFtdcMillisecType	UpdateMillisec;
};

///������Լ��������
struct CQdFtdcMarketDataCMBVolumeField
{
	///����������
	TQdFtdcVolumeType	VolumeAskLot;
	///����������
	TQdFtdcVolumeType	VolumeBidLot;
	///��Ȩƽ��ί��۸�
	TQdFtdcPriceType	WeightAvgBidPx;
	///��Ȩƽ��ί���۸�
	TQdFtdcPriceType	WeightAvgSellPx;
};

///��Լ״̬
struct CQdFtdcQmdInstrumentStateField
{
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TQdFtdcInstrumentStatusType	InstrumentStatus;
};

///�����Լ״̬
struct CQdFtdcMarketDataInstrumentStatusField
{
	///��Լ״̬
	TQdFtdcInstrumentStatusType	InstrumentStatus;
};

///��Ϣ�ַ�
struct CQdFtdcDisseminationField
{
	///����ϵ�к�
	TQdFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TQdFtdcSequenceNoType	SequenceNo;
};

///Qdp��Ϣ�ַ�
struct CQdFtdcQdpDisseminationField
{
	///����ϵ�к�
	TQdFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TQdFtdcSequenceNoType	SequenceNo;
};

///�����ѯ
struct CQdFtdcQryMarketDataField
{
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
};

///����Ӧ��
struct CQdFtdcRspMarketDataField
{
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///������
	TQdFtdcTradingDayType	TradingDay;
	///�����
	TQdFtdcPriceType	PreSettlementPrice;
	///������
	TQdFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdFtdcRatioType	PreDelta;
	///����
	TQdFtdcPriceType	OpenPrice;
	///��߼�
	TQdFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdFtdcPriceType	LowestPrice;
	///������
	TQdFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdFtdcPriceType	LowerLimitPrice;
	///�����
	TQdFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdFtdcRatioType	CurrDelta;
	///���¼�
	TQdFtdcPriceType	LastPrice;
	///����
	TQdFtdcVolumeType	Volume;
	///�ɽ�����
	TQdFtdcVolumeType	NumberVloume;
	///�ɽ����
	TQdFtdcMoneyType	Turnover;
	///�ֲ���
	TQdFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdFtdcPriceType	BidPrice1;
	///������һ
	TQdFtdcVolumeType	BidVolume1;
	///������һ
	TQdFtdcPriceType	AskPrice1;
	///������һ
	TQdFtdcVolumeType	AskVolume1;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdFtdcMillisecType	UpdateMillisec;
	///��Լ״̬
	TQdFtdcInstrumentStatusType	InstrumentStatus;
};

///MDTen����������
struct CQdFtdcMDTenBestBuyOrderField
{
	///������۸�
	TQdFtdcPriceType	BestBuyOrderPrice;
	///������һ
	TQdFtdcVolumeType	BestBuyOrderQtyOne;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyTwo;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyThree;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyFour;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyFive;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtySix;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtySeven;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyEight;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyNine;
	///������ʮ
	TQdFtdcVolumeType	BestBuyOrderQtyTen;
};

///MDTen����������
struct CQdFtdcMDTenBestSellOrderField
{
	///�������۸�
	TQdFtdcPriceType	BestSellOrderPrice;
	///������һ
	TQdFtdcVolumeType	BestSellOrderQtyOne;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyTwo;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyThree;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyFour;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyFive;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtySix;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtySeven;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyEight;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyNine;
	///������ʮ
	TQdFtdcVolumeType	BestSellOrderQtyTen;
};

///MDTen�������
struct CQdFtdcMDTenDepthMarketDataField
{
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdFtdcMillisecType	UpdateMillisec;
	///������۸�
	TQdFtdcPriceType	BestBuyOrderPrice;
	///������һ
	TQdFtdcVolumeType	BestBuyOrderQtyOne;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyTwo;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyThree;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyFour;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyFive;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtySix;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtySeven;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyEight;
	///��������
	TQdFtdcVolumeType	BestBuyOrderQtyNine;
	///������ʮ
	TQdFtdcVolumeType	BestBuyOrderQtyTen;
	///�������۸�
	TQdFtdcPriceType	BestSellOrderPrice;
	///������һ
	TQdFtdcVolumeType	BestSellOrderQtyOne;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyTwo;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyThree;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyFour;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyFive;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtySix;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtySeven;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyEight;
	///��������
	TQdFtdcVolumeType	BestSellOrderQtyNine;
	///������ʮ
	TQdFtdcVolumeType	BestSellOrderQtyTen;
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
};

///��Ȩ��̬����
struct CQdFtdcOptionStaticField
{
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///������
	TQdFtdcTradingDayType	TradingDay;
	///�û�
	TQdFtdcUserIDType	UserID;
	///�ͻ������ò�����
	TQdFtdcManalSetVolType	IsManalSetVol;
};

///��Ȩ���¼�
struct CQdFtdcOptionLastpriceField
{
	///������¼�
	TQdFtdcPriceType	UnderlyingLastPrice;
	///���¼�
	TQdFtdcPriceType	LastPrice;
	///���۲�����
	TQdFtdcPriceType	TheoryVol;
};

///��Ȩ��һ��
struct CQdFtdcOptionBidpriceField
{
	///�����1��
	TQdFtdcPriceType	UnderlyingBidPrice1;
	///��1��
	TQdFtdcPriceType	BidPrice1;
};

///��Ȩ��һ��
struct CQdFtdcOptionAskpriceField
{
	///�����1��
	TQdFtdcPriceType	UnderlyingAskPrice1;
	///��1��
	TQdFtdcPriceType	AskPrice1;
};

///��Ȩϣ��ֵ
struct CQdFtdcOptionGreeksField
{
	///ʣ������
	TQdFtdcPriceType	RemainDay;
	///��1�۲�����
	TQdFtdcPriceType	AskVol;
	///��1�۲�����
	TQdFtdcPriceType	BidVol;
	///���¼۲�����
	TQdFtdcPriceType	LastVol;
	///�м�۲�����
	TQdFtdcPriceType	MidVol;
	///Delta
	TQdFtdcPriceType	Delta;
	///Gamma
	TQdFtdcPriceType	Gamma;
	///Vega
	TQdFtdcPriceType	Vega;
	///Theta
	TQdFtdcPriceType	Theta;
	///Rho
	TQdFtdcPriceType	Rho;
};

///��Ȩ����
struct CQdFtdcOptionIndexDataField
{
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdFtdcMillisecType	UpdateMillisec;
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///������
	TQdFtdcTradingDayType	TradingDay;
	///�û�
	TQdFtdcUserIDType	UserID;
	///�ͻ������ò�����
	TQdFtdcManalSetVolType	IsManalSetVol;
	///������¼�
	TQdFtdcPriceType	UnderlyingLastPrice;
	///���¼�
	TQdFtdcPriceType	LastPrice;
	///���۲�����
	TQdFtdcPriceType	TheoryVol;
	///�����1��
	TQdFtdcPriceType	UnderlyingBidPrice1;
	///��1��
	TQdFtdcPriceType	BidPrice1;
	///�����1��
	TQdFtdcPriceType	UnderlyingAskPrice1;
	///��1��
	TQdFtdcPriceType	AskPrice1;
	///ʣ������
	TQdFtdcPriceType	RemainDay;
	///��1�۲�����
	TQdFtdcPriceType	AskVol;
	///��1�۲�����
	TQdFtdcPriceType	BidVol;
	///���¼۲�����
	TQdFtdcPriceType	LastVol;
	///�м�۲�����
	TQdFtdcPriceType	MidVol;
	///Delta
	TQdFtdcPriceType	Delta;
	///Gamma
	TQdFtdcPriceType	Gamma;
	///Vega
	TQdFtdcPriceType	Vega;
	///Theta
	TQdFtdcPriceType	Theta;
	///Rho
	TQdFtdcPriceType	Rho;
};

///��ǰ����
struct CQdFtdcMarketDataActionDayField
{
	///��ǰ����
	TQdFtdcTradingDayType	CalendarDate;
};

///���������ѯ
struct CQdFtdcQryMinMarketDataField
{
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///������
	TQdFtdcTradingDayType	TradingDay;
	///��ʼʱ��
	TQdFtdcTimeType	StartUpdateTime;
	///��ֹʱ��
	TQdFtdcTimeType	EndUpdateTime;
};

///������������
struct CQdFtdcDeptMinMarketDataField
{
	///������
	TQdFtdcDateType	TradingDay;
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///ǰ����
	TQdFtdcPriceType	PreClosePrice;
	///ǰ�ֲ���
	TQdFtdcLargeVolumeType	PreOpenInterest;
	///���̼�
	TQdFtdcPriceType	OpenPrice;
	///��߼�
	TQdFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdFtdcPriceType	LowestPrice;
	///���¼�
	TQdFtdcPriceType	LastPrice;
	///���̼�
	TQdFtdcPriceType	ClosePrice;
	///�ɽ���
	TQdFtdcVolumeType	Volume;
	///�ɽ����
	TQdFtdcMoneyType	Turnover;
	///�ֲ���
	TQdFtdcLargeVolumeType	OpenInterest;
	///��ͣ���
	TQdFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdFtdcPriceType	LowerLimitPrice;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///tick������
	TQdFtdcPriceType	TickOpenPrice;
	///tick������
	TQdFtdcPriceType	TickPreClosePrice;
	///����յ�Tick��ʱ��
	TQdFtdcTimeType	TickUpdateTime;
	///��Լ״̬
	TQdFtdcInstrumentStatusType	InstrumentStatus;
};

///�������ڲ���ϸ��Ϣ
struct CQdFtdcDepthMinMarketDataTickField
{
	///������
	TQdFtdcTradingDayType	TradingDay;
	///�����
	TQdFtdcPriceType	PreSettlementPrice;
	///������
	TQdFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdFtdcRatioType	PreDelta;
	///����
	TQdFtdcPriceType	OpenPrice;
	///��߼�
	TQdFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdFtdcPriceType	LowestPrice;
	///������
	TQdFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdFtdcPriceType	LowerLimitPrice;
	///�����
	TQdFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdFtdcRatioType	CurrDelta;
	///���¼�
	TQdFtdcPriceType	LastPrice;
	///����
	TQdFtdcVolumeType	Volume;
	///�ɽ�����
	TQdFtdcVolumeType	NumberVloume;
	///�ɽ����
	TQdFtdcMoneyType	Turnover;
	///�ֲ���
	TQdFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdFtdcPriceType	BidPrice1;
	///������һ
	TQdFtdcVolumeType	BidVolume1;
	///������һ
	TQdFtdcPriceType	AskPrice1;
	///������һ
	TQdFtdcVolumeType	AskVolume1;
	///����۶�
	TQdFtdcPriceType	BidPrice2;
	///��������
	TQdFtdcVolumeType	BidVolume2;
	///�������
	TQdFtdcPriceType	BidPrice3;
	///��������
	TQdFtdcVolumeType	BidVolume3;
	///�����۶�
	TQdFtdcPriceType	AskPrice2;
	///��������
	TQdFtdcVolumeType	AskVolume2;
	///��������
	TQdFtdcPriceType	AskPrice3;
	///��������
	TQdFtdcVolumeType	AskVolume3;
	///�������
	TQdFtdcPriceType	BidPrice4;
	///��������
	TQdFtdcVolumeType	BidVolume4;
	///�������
	TQdFtdcPriceType	BidPrice5;
	///��������
	TQdFtdcVolumeType	BidVolume5;
	///��������
	TQdFtdcPriceType	AskPrice4;
	///��������
	TQdFtdcVolumeType	AskVolume4;
	///��������
	TQdFtdcPriceType	AskPrice5;
	///��������
	TQdFtdcVolumeType	AskVolume5;
	///�������
	TQdFtdcPriceType	BidPrice6;
	///��������
	TQdFtdcVolumeType	BidVolume6;
	///�������
	TQdFtdcPriceType	BidPrice7;
	///��������
	TQdFtdcVolumeType	BidVolume7;
	///��������
	TQdFtdcPriceType	AskPrice6;
	///��������
	TQdFtdcVolumeType	AskVolume6;
	///��������
	TQdFtdcPriceType	AskPrice7;
	///��������
	TQdFtdcVolumeType	AskVolume7;
	///����۰�
	TQdFtdcPriceType	BidPrice8;
	///��������
	TQdFtdcVolumeType	BidVolume8;
	///����۾�
	TQdFtdcPriceType	BidPrice9;
	///��������
	TQdFtdcVolumeType	BidVolume9;
	///�����۰�
	TQdFtdcPriceType	AskPrice8;
	///��������
	TQdFtdcVolumeType	AskVolume8;
	///�����۾�
	TQdFtdcPriceType	AskPrice9;
	///��������
	TQdFtdcVolumeType	AskVolume9;
	///�����ʮ
	TQdFtdcPriceType	BidPrice10;
	///������ʮ
	TQdFtdcVolumeType	BidVolume10;
	///������ʮ
	TQdFtdcPriceType	AskPrice10;
	///������ʮ
	TQdFtdcVolumeType	AskVolume10;
	///���볷������
	TQdFtdcVolumeType	WithdrawBuyNumber;
	///������������
	TQdFtdcVolumeType	WithdrawSellNumber;
	///���볷������
	TQdFtdcVolumeType	WithdrawBuyAmount;
	///���볷�����
	TQdFtdcPriceType	WithdrawBuyMoney;
	///������������
	TQdFtdcVolumeType	WithdrawSellAmount;
	///�����������
	TQdFtdcPriceType	WithdrawSellMoney;
	///�����ܱ���
	TQdFtdcVolumeType	TotalBidNumber;
	///�����ܱ���
	TQdFtdcVolumeType	TotalOfferNumber;
	///����ί�гɽ����ȴ�ʱ��ms
	TQdFtdcVolumeType	BidTradeMaxDuration;
	///����ί�гɽ����ȴ�ʱ��ms
	TQdFtdcVolumeType	OfferTradeMaxDuration;
	///ί�����
	TQdFtdcVolumeType	NumBidOrders;
	///ί������
	TQdFtdcVolumeType	NumOfferOrders;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdFtdcMillisecType	UpdateMillisec;
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///����������
	TQdFtdcVolumeType	VolumeAskLot;
	///����������
	TQdFtdcVolumeType	VolumeBidLot;
	///��Ȩƽ��ί��۸�
	TQdFtdcPriceType	WeightAvgBidPx;
	///��Ȩƽ��ί���۸�
	TQdFtdcPriceType	WeightAvgSellPx;
	///��Լ״̬
	TQdFtdcInstrumentStatusType	InstrumentStatus;
	///��ǰ����
	TQdFtdcTradingDayType	CalendarDate;
	///tick������
	TQdFtdcPriceType	TickOpenPrice;
	///tick������
	TQdFtdcPriceType	TickPreClosePrice;
	///����յ�Tick��ʱ��
	TQdFtdcTimeType	TickUpdateTime;
};

///��ʳɽ�����
struct CQdFtdcDeptTradeMaketDataField
{
	///������
	TQdFtdcDateType	TradingDay;
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///�ɽ����
	TQdFtdcIndexType	TradeIndex;
	///�ɽ���
	TQdFtdcPriceType	TradePirce;
	///�ɽ���
	TQdFtdcVolumeType	TradeVolume;
	///�ɽ����
	TQdFtdcMoneyType	TradeTurnover;
	///�ɽ�ʱ�䣨s��
	TQdFtdcTimeType	TradeTime;
	///�ɽ�ʱ�䣨���룩
	TQdFtdcMillisecType	TradeMillisec;
	///�ɽ�ͨ��
	TQdFtdcIndexType	TradeChannel;
	///�򷽶�����
	TQdFtdcIndexType	TradeBuyNo;
	///����������
	TQdFtdcIndexType	TradeSellNo;
	///�ɽ����(���)
	TQdFtdcCustomType	ExecType;
	///�����̱�־
	TQdFtdcTradeBSFlagType	TradeBSFlag;
	///ҵ�����к�
	TQdFtdcIndexType	BizIndex;
};

///���ί������
struct CQdFtdcDeptOrderMaketDataField
{
	///������
	TQdFtdcDateType	TradingDay;
	///����������
	TQdFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdFtdcInstrumentIDType	InstrumentID;
	///���ί����������
	TQdFtdcOrderDirSideType	Direction;
	///��������
	TQdFtdcOrderTypeStrType	OrderTypeStr;
	///ί�м۸�
	TQdFtdcPriceType	OrderPirce;
	///�ɽ���
	TQdFtdcVolumeType	OrderVolume;
	///ί��ʱ�䣨s��
	TQdFtdcTimeType	OrderTime;
	///ί��ʱ�䣨���룩
	TQdFtdcMillisecType	OrderMillisec;
	///��������Լ����
	TQdFtdcCustomType	comfirmID;
	///�ɽ����
	TQdFtdcIndexType	TradeIndex;
	///�ɽ�ͨ��
	TQdFtdcIndexType	TradeChannel;
};

///������������������
struct CQdFtdcMarketDataBid67Field
{
	///�������
	TQdFtdcPriceType	BidPrice6;
	///��������
	TQdFtdcVolumeType	BidVolume6;
	///�������
	TQdFtdcPriceType	BidPrice7;
	///��������
	TQdFtdcVolumeType	BidVolume7;
};

///������������������
struct CQdFtdcMarketDataAsk67Field
{
	///��������
	TQdFtdcPriceType	AskPrice6;
	///��������
	TQdFtdcVolumeType	AskVolume6;
	///��������
	TQdFtdcPriceType	AskPrice7;
	///��������
	TQdFtdcVolumeType	AskVolume7;
};

///��������ˡ�������
struct CQdFtdcMarketDataBid89Field
{
	///����۰�
	TQdFtdcPriceType	BidPrice8;
	///��������
	TQdFtdcVolumeType	BidVolume8;
	///����۾�
	TQdFtdcPriceType	BidPrice9;
	///��������
	TQdFtdcVolumeType	BidVolume9;
};

///���������ˡ�������
struct CQdFtdcMarketDataAsk89Field
{
	///�����۰�
	TQdFtdcPriceType	AskPrice8;
	///��������
	TQdFtdcVolumeType	AskVolume8;
	///�����۾�
	TQdFtdcPriceType	AskPrice9;
	///��������
	TQdFtdcVolumeType	AskVolume9;
};

///����������ʮ����
struct CQdFtdcMarketDataBidAsk10Field
{
	///�����ʮ
	TQdFtdcPriceType	BidPrice10;
	///������ʮ
	TQdFtdcVolumeType	BidVolume10;
	///������ʮ
	TQdFtdcPriceType	AskPrice10;
	///������ʮ
	TQdFtdcVolumeType	AskVolume10;
};

///���������仯��Ϣ
struct CQdFtdcSellBuyChangeField
{
	///���볷������
	TQdFtdcVolumeType	WithdrawBuyNumber;
	///������������
	TQdFtdcVolumeType	WithdrawSellNumber;
	///���볷������
	TQdFtdcVolumeType	WithdrawBuyAmount;
	///���볷�����
	TQdFtdcPriceType	WithdrawBuyMoney;
	///������������
	TQdFtdcVolumeType	WithdrawSellAmount;
	///�����������
	TQdFtdcPriceType	WithdrawSellMoney;
	///�����ܱ���
	TQdFtdcVolumeType	TotalBidNumber;
	///�����ܱ���
	TQdFtdcVolumeType	TotalOfferNumber;
	///����ί�гɽ����ȴ�ʱ��ms
	TQdFtdcVolumeType	BidTradeMaxDuration;
	///����ί�гɽ����ȴ�ʱ��ms
	TQdFtdcVolumeType	OfferTradeMaxDuration;
	///ί�����
	TQdFtdcVolumeType	NumBidOrders;
	///ί������
	TQdFtdcVolumeType	NumOfferOrders;
};



#endif
