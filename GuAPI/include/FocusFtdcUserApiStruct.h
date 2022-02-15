/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company ɽ��֤ȯ�ɷ����޹�˾  ����������Ʒ��
///@author �˺�
///@file FocusFtdcUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(Focus_FTDCSTRUCT_H)
#define Focus_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FocusFtdcUserApiDataType.h"

///��Ӧ��Ϣ
struct CFocusFtdcRspInfoField
{
	///�������
	TFocusFtdcErrorIDType	ErrorID;
	///������Ϣ
	TFocusFtdcErrorMsgType	ErrorMsg;
};

///ϵͳ�û���¼����
struct CFocusFtdcReqUserLoginField
{
	///������
	TFocusFtdcDateType	TradingDay;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����
	TFocusFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TFocusFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TFocusFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TFocusFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///�������Ĵ���
	TFocusFtdcDataCenterIDType	DataCenterID;
	///��̬����
	TFocusFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TFocusFtdcIPAddressType	ClientIPAddress;
	///��Ȩ����
	TFocusFtdcAuthCodeType	AuthCode;
};

///ϵͳ�û���¼Ӧ��
struct CFocusFtdcRspUserLoginField
{
	///������
	TFocusFtdcDateType	TradingDay;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///��¼�ɹ�ʱ��
	TFocusFtdcTimeType	LoginTime;
	///�û���󱾵ر�����
	TFocusFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///����ϵͳ����
	TFocusFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TFocusFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TFocusFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TFocusFtdcSequenceNoType	UserFlowSize;
	///��¼������Ϣ
	TFocusFtdcLoginInfoType	LoginInfo;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
};

///�û��ǳ�����
struct CFocusFtdcReqUserLogoutField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
};

///�û��ǳ�����
struct CFocusFtdcRspUserLogoutField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
};

///ǿ���û��˳�
struct CFocusFtdcForceUserExitField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
};

///�û������޸�
struct CFocusFtdcUserPasswordUpdateField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///������
	TFocusFtdcPasswordType	OldPassword;
	///������
	TFocusFtdcPasswordType	NewPassword;
};

///���뱨��
struct CFocusFtdcInputOrderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Ʊί������(������ί����Ч)
	TFocusFtdcOrderSysIDType	BatchNum;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///��������
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///��Ч������
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD����
	TFocusFtdcDateType	GTDDate;
	///�ɽ�������
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TFocusFtdcVolumeType	MinVolume;
	///ֹ���
	TFocusFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TFocusFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TFocusFtdcBusinessTypeType	BusinessType;
};

///��������
struct CFocusFtdcOrderActionField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Ʊί������(������ί����Ч)
	TFocusFtdcOrderSysIDType	BatchNum;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���γ��������ı��ر��
	TFocusFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///����������־
	TFocusFtdcActionFlagType	ActionFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///�����仯
	TFocusFtdcVolumeType	VolumeChange;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
};

///�ڴ����
struct CFocusFtdcMemDBField
{
	///�ڴ����
	TFocusFtdcMemTableNameType	MemTableName;
};

///Ͷ�����ʽ��ʻ����������
struct CFocusFtdcReqAccountDepositField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�ʽ���ˮ��
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���
	TFocusFtdcMoneyType	Amount;
	///�������
	TFocusFtdcAccountDirectionType	AmountDirection;
	///���������
	TFocusFtdcDateType	Date;
	///�����ʱ��
	TFocusFtdcTimeType	Time;
	///�����ע
	TFocusFtdcDepositNoteType	Note;
	///�Ƿ�ɹ�
	TFocusFtdcBoolType	isSuccess;
	///�û�����
	TFocusFtdcUserIDType	UserID;
};

///Ͷ�����ʽ��ʻ������Ӧ��
struct CFocusFtdcRspAccountDepositField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///���
	TFocusFtdcMoneyType	Amount;
	///�������
	TFocusFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TFocusFtdcMoneyType	Available;
	///����׼����
	TFocusFtdcMoneyType	Balance;
	///�û�����
	TFocusFtdcUserIDType	UserID;
};

///ʵʱ�ϳ�
struct CFocusFtdcTBCommandField
{
	///DB�������
	TFocusFtdcCommandNoType	CommandNo;
	///��������
	TFocusFtdcDateType	CommandDate;
	///����ʱ��
	TFocusFtdcTimeType	CommandTime;
	///DB��������
	TFocusFtdcCommandTypeType	CommandType;
	///�ֶ���
	TFocusFtdcFieldNameType	FieldName;
	///�ֶ�����
	TFocusFtdcFieldContentType	FieldContent;
};

///�������
struct CFocusFtdcInvestorAccountDepositResField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///���
	TFocusFtdcMoneyType	Amount;
	///�������
	TFocusFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TFocusFtdcMoneyType	Available;
	///����׼����
	TFocusFtdcMoneyType	Balance;
	///�û�����
	TFocusFtdcUserIDType	UserID;
};

///��Լ״̬
struct CFocusFtdcInstrumentStatusField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TFocusFtdcProductIDType	ProductID;
	///Ʒ������
	TFocusFtdcProductNameType	ProductName;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///�������
	TFocusFtdcYearType	DeliveryYear;
	///������
	TFocusFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TFocusFtdcLargeVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TFocusFtdcLargeVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TFocusFtdcLargeVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TFocusFtdcLargeVolumeType	MinMarketOrderVolume;
	///��Ʊÿ������������
	TFocusFtdcLargeVolumeType	MinStkBuyQty;
	///��Ʊÿ������������
	TFocusFtdcLargeVolumeType	MinStkSellQty;
	///��������
	TFocusFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TFocusFtdcPriceTickType	PriceTick;
	///����
	TFocusFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TFocusFtdcLargeVolumeType	LongPosLimit;
	///��ͷ�޲�
	TFocusFtdcLargeVolumeType	ShortPosLimit;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TFocusFtdcDateType	CreateDate;
	///������
	TFocusFtdcDateType	OpenDate;
	///������
	TFocusFtdcDateType	ExpireDate;
	///��ʼ������
	TFocusFtdcDateType	StartDelivDate;
	///��󽻸���
	TFocusFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TFocusFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TFocusFtdcBoolType	IsTrading;
	///������Ʒ����
	TFocusFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TFocusFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TFocusFtdcPositionTypeType	PositionType;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType;
	///����
	TFocusFtdcRatioType	ExchangeRate;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///��Ʒ����
	TFocusFtdcProductClassType	ProductClass;
	///��Ȩ��Ȩ��ʽ
	TFocusFtdcOptionsModeType	OptionsMode;
	///��֤���㷨����
	TFocusFtdcMarginCombTypeType	MarginCombType;
};

///����ģʽ��������
struct CFocusFtdcAdviceRunModeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�Զ������ֶ�
	TFocusFtdcAdviceRunModeType	RunMode;
};

///���ĺ�Լ״̬
struct CFocusFtdcSubInstrumentStatusField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///���뱾״̬ʱ��
	TFocusFtdcTimeType	EnterTime;
	///���뱾״̬ԭ��
	TFocusFtdcEnterReasonType	EnterReason;
};

///�����������
struct CFocusFtdcMarketDataBaseField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///������
	TFocusFtdcPriceType	PreClosePrice;
	///��ֲ���
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TFocusFtdcRatioType	PreDelta;
	///֤ȯ����״̬
	TFocusFtdcStkOrderStatusType	StkOrderStatus;
};

///���龲̬����
struct CFocusFtdcMarketDataStaticField
{
	///����
	TFocusFtdcPriceType	OpenPrice;
	///��߼�
	TFocusFtdcPriceType	HighestPrice;
	///��ͼ�
	TFocusFtdcPriceType	LowestPrice;
	///������
	TFocusFtdcPriceType	ClosePrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///�����
	TFocusFtdcPriceType	SettlementPrice;
	///����ʵ��
	TFocusFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CFocusFtdcMarketDataLastMatchField
{
	///���¼�
	TFocusFtdcPriceType	LastPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///�ɽ����
	TFocusFtdcMoneyType	Turnover;
	///�ֲ���
	TFocusFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CFocusFtdcMarketDataBestPriceField
{
	///�����һ
	TFocusFtdcPriceType	BidPrice1;
	///������һ
	TFocusFtdcVolumeType	BidVolume1;
	///������һ
	TFocusFtdcPriceType	AskPrice1;
	///������һ
	TFocusFtdcVolumeType	AskVolume1;
};

///�����������������
struct CFocusFtdcMarketDataBid23Field
{
	///����۶�
	TFocusFtdcPriceType	BidPrice2;
	///��������
	TFocusFtdcVolumeType	BidVolume2;
	///�������
	TFocusFtdcPriceType	BidPrice3;
	///��������
	TFocusFtdcVolumeType	BidVolume3;
};

///������������������
struct CFocusFtdcMarketDataAsk23Field
{
	///�����۶�
	TFocusFtdcPriceType	AskPrice2;
	///��������
	TFocusFtdcVolumeType	AskVolume2;
	///��������
	TFocusFtdcPriceType	AskPrice3;
	///��������
	TFocusFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CFocusFtdcMarketDataBid45Field
{
	///�������
	TFocusFtdcPriceType	BidPrice4;
	///��������
	TFocusFtdcVolumeType	BidVolume4;
	///�������
	TFocusFtdcPriceType	BidPrice5;
	///��������
	TFocusFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CFocusFtdcMarketDataAsk45Field
{
	///��������
	TFocusFtdcPriceType	AskPrice4;
	///��������
	TFocusFtdcVolumeType	AskVolume4;
	///��������
	TFocusFtdcPriceType	AskPrice5;
	///��������
	TFocusFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CFocusFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TFocusFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TFocusFtdcMillisecType	UpdateMillisec;
};

///�������
struct CFocusFtdcDepthMarketDataField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///������
	TFocusFtdcPriceType	PreClosePrice;
	///��ֲ���
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TFocusFtdcRatioType	PreDelta;
	///֤ȯ����״̬
	TFocusFtdcStkOrderStatusType	StkOrderStatus;
	///����
	TFocusFtdcPriceType	OpenPrice;
	///��߼�
	TFocusFtdcPriceType	HighestPrice;
	///��ͼ�
	TFocusFtdcPriceType	LowestPrice;
	///������
	TFocusFtdcPriceType	ClosePrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///�����
	TFocusFtdcPriceType	SettlementPrice;
	///����ʵ��
	TFocusFtdcRatioType	CurrDelta;
	///���¼�
	TFocusFtdcPriceType	LastPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///�ɽ����
	TFocusFtdcMoneyType	Turnover;
	///�ֲ���
	TFocusFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TFocusFtdcPriceType	BidPrice1;
	///������һ
	TFocusFtdcVolumeType	BidVolume1;
	///������һ
	TFocusFtdcPriceType	AskPrice1;
	///������һ
	TFocusFtdcVolumeType	AskVolume1;
	///����۶�
	TFocusFtdcPriceType	BidPrice2;
	///��������
	TFocusFtdcVolumeType	BidVolume2;
	///�������
	TFocusFtdcPriceType	BidPrice3;
	///��������
	TFocusFtdcVolumeType	BidVolume3;
	///�����۶�
	TFocusFtdcPriceType	AskPrice2;
	///��������
	TFocusFtdcVolumeType	AskVolume2;
	///��������
	TFocusFtdcPriceType	AskPrice3;
	///��������
	TFocusFtdcVolumeType	AskVolume3;
	///�������
	TFocusFtdcPriceType	BidPrice4;
	///��������
	TFocusFtdcVolumeType	BidVolume4;
	///�������
	TFocusFtdcPriceType	BidPrice5;
	///��������
	TFocusFtdcVolumeType	BidVolume5;
	///��������
	TFocusFtdcPriceType	AskPrice4;
	///��������
	TFocusFtdcVolumeType	AskVolume4;
	///��������
	TFocusFtdcPriceType	AskPrice5;
	///��������
	TFocusFtdcVolumeType	AskVolume5;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TFocusFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TFocusFtdcMillisecType	UpdateMillisec;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///����������
	TFocusFtdcVolumeType	VolumeAskLot;
	///����������
	TFocusFtdcVolumeType	VolumeBidLot;
};

///���ĺ�Լ�������Ϣ
struct CFocusFtdcSpecificInstrumentField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///Ͷ����Ȩ��
struct CFocusFtdcInvestorRightField
{
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TFocusFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TFocusFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TFocusFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TFocusFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TFocusFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TFocusFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TFocusFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TFocusFtdcDistributeTypeType	DistributeType;
};

///����������
struct CFocusFtdcMarketDataExchangeIDField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
};

///�����ڴ������ѯ
struct CFocusFtdcShmDepthMarketDataField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///���ĺ�
	TFocusFtdcTopicIDType	TopicID;
};

///TOPIC��ѯ
struct CFocusFtdcTopicSearchField
{
	///���ĺ�
	TFocusFtdcTopicIDType	TopicID;
};

///�ּ�����
struct CFocusFtdcMBLMarketDataField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///�۸�
	TFocusFtdcPriceType	Price;
	///����
	TFocusFtdcVolumeType	Volume;
	///����޸�ʱ��
	TFocusFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TFocusFtdcMillisecType	UpdateMillisec;
};

///������Լ��������
struct CFocusFtdcMarketDataCMBVolumeField
{
	///����������
	TFocusFtdcVolumeType	VolumeAskLot;
	///����������
	TFocusFtdcVolumeType	VolumeBidLot;
};

///��Լ״̬
struct CFocusFtdcQmdInstrumentStateField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
};

///���ĺ�Լ�������Ϣ
struct CFocusFtdcSubSpecificInstrumentField
{
	///��Լ����
	TFocusFtdcSubInstrumentIDType	InstrumentID;
};

///�ɽ�
struct CFocusFtdcTradeField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TFocusFtdcTradeIDType	TradeID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�ɽ��۸�
	TFocusFtdcPriceType	TradePrice;
	///�ɽ�����
	TFocusFtdcVolumeType	TradeVolume;
	///�ɽ�ʱ��
	TFocusFtdcTimeType	TradeTime;
	///�г�����
	TFocusFtdcMarketIDType	MarketID;
	///�ɽ����
	TFocusFtdcMoneyType	TradeAmnt;
	///��������
	TFocusFtdcTradeTypeType	TradeType;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
};

///����
struct CFocusFtdcOrderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Ʊί������(������ί����Ч)
	TFocusFtdcOrderSysIDType	BatchNum;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///��������
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///��Ч������
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD����
	TFocusFtdcDateType	GTDDate;
	///�ɽ�������
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TFocusFtdcVolumeType	MinVolume;
	///ֹ���
	TFocusFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TFocusFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TFocusFtdcBusinessTypeType	BusinessType;
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����ʱ��
	TFocusFtdcTimeType	InsertTime;
	///������Դ
	TFocusFtdcOrderSourceType	OrderSource;
	///����״̬
	TFocusFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TFocusFtdcTimeType	CancelTime;
	///�����û����
	TFocusFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TFocusFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TFocusFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TFocusFtdcVolumeType	VolumeCancled;
	///�������
	TFocusFtdcErrorIDType	ErrorID;
	///������Ϣ
	TFocusFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TFocusFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TFocusFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///������
	TFocusFtdcRequestIDType	RequestID;
	///ÿ��������
	TFocusFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TFocusFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TFocusFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TFocusFtdcBranchIDType	BranchID;
	///��¼���
	TFocusFtdcSequenceNoType	RecNum;
};

///����������
struct CFocusFtdcFlowMessageCancelField
{
	///����ϵ�к�
	TFocusFtdcSequenceSeriesType	SequenceSeries;
	///������
	TFocusFtdcDateType	TradingDay;
	///�������Ĵ���
	TFocusFtdcDataCenterIDType	DataCenterID;
	///������ʼ���к�
	TFocusFtdcSequenceNoType	StartSequenceNo;
	///���˽������к�
	TFocusFtdcSequenceNoType	EndSequenceNo;
};

///��Ϣ�ַ�
struct CFocusFtdcDisseminationField
{
	///����ϵ�к�
	TFocusFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TFocusFtdcSequenceNoType	SequenceNo;
};

///������Ϣ֪ͨ
struct CFocusFtdcMessageNotifyField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ۼӴ���
	TFocusFtdcTotalNumsType	Nums;
	///���漶��
	TFocusFtdcErrorLevelType	WarnLevel;
	///������
	TFocusFtdcErrorIDType	WarnID;
	///������Ϣ
	TFocusFtdcLargeErrorMsgType	WarnMsg;
	///����ʱ��
	TFocusFtdcTimeType	WarnTime;
};

///������ָ��֪ͨ
struct CFocusFtdcAdviceOrderField
{
	///Ͷ���û�����
	TFocusFtdcUserIDType	InvestorAdvicer;
	///Ͷ�ʾ���
	TFocusFtdcUserIDType	InvestorManager;
	///����Ա
	TFocusFtdcUserIDType	UserTrader;
	///��������
	TFocusFtdcVolumeType	VolumeFrozen;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Ʊί������(������ί����Ч)
	TFocusFtdcOrderSysIDType	BatchNum;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///��������
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///��Ч������
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD����
	TFocusFtdcDateType	GTDDate;
	///�ɽ�������
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TFocusFtdcVolumeType	MinVolume;
	///ֹ���
	TFocusFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TFocusFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TFocusFtdcBusinessTypeType	BusinessType;
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����ʱ��
	TFocusFtdcTimeType	InsertTime;
	///������Դ
	TFocusFtdcOrderSourceType	OrderSource;
	///����״̬
	TFocusFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TFocusFtdcTimeType	CancelTime;
	///�����û����
	TFocusFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TFocusFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TFocusFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TFocusFtdcVolumeType	VolumeCancled;
	///�������
	TFocusFtdcErrorIDType	ErrorID;
	///������Ϣ
	TFocusFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TFocusFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TFocusFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///������
	TFocusFtdcRequestIDType	RequestID;
	///ÿ��������
	TFocusFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TFocusFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TFocusFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TFocusFtdcBranchIDType	BranchID;
	///��¼���
	TFocusFtdcSequenceNoType	RecNum;
	///ָ��û���Ϣ
	TFocusFtdcAdviceUserInfoType	AdviceUserInfo;
};

///������ѯ
struct CFocusFtdcQryOrderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///�ɽ���ѯ
struct CFocusFtdcQryTradeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ɽ����
	TFocusFtdcTradeIDType	TradeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///��Լ��ѯ
struct CFocusFtdcQryInstrumentField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///��Լ��ѯӦ��
struct CFocusFtdcRspInstrumentField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TFocusFtdcProductIDType	ProductID;
	///Ʒ������
	TFocusFtdcProductNameType	ProductName;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///�������
	TFocusFtdcYearType	DeliveryYear;
	///������
	TFocusFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TFocusFtdcLargeVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TFocusFtdcLargeVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TFocusFtdcLargeVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TFocusFtdcLargeVolumeType	MinMarketOrderVolume;
	///��Ʊÿ������������
	TFocusFtdcLargeVolumeType	MinStkBuyQty;
	///��Ʊÿ������������
	TFocusFtdcLargeVolumeType	MinStkSellQty;
	///��������
	TFocusFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TFocusFtdcPriceTickType	PriceTick;
	///����
	TFocusFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TFocusFtdcLargeVolumeType	LongPosLimit;
	///��ͷ�޲�
	TFocusFtdcLargeVolumeType	ShortPosLimit;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TFocusFtdcDateType	CreateDate;
	///������
	TFocusFtdcDateType	OpenDate;
	///������
	TFocusFtdcDateType	ExpireDate;
	///��ʼ������
	TFocusFtdcDateType	StartDelivDate;
	///��󽻸���
	TFocusFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TFocusFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TFocusFtdcBoolType	IsTrading;
	///������Ʒ����
	TFocusFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TFocusFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TFocusFtdcPositionTypeType	PositionType;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType;
	///����
	TFocusFtdcRatioType	ExchangeRate;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///��Ʒ����
	TFocusFtdcProductClassType	ProductClass;
	///��Ȩ��Ȩ��ʽ
	TFocusFtdcOptionsModeType	OptionsMode;
	///��֤���㷨����
	TFocusFtdcMarginCombTypeType	MarginCombType;
};

///Ͷ�����ʽ��ѯ
struct CFocusFtdcQryInvestorAccountField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///Ͷ�����ʽ�Ӧ��
struct CFocusFtdcRspInvestorAccountField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///�ʽ�����
	TFocusFtdcPasswordType	InvestorPasswd;
	///�ϴν���׼����
	TFocusFtdcMoneyType	PreBalance;
	///���տ����ʽ�
	TFocusFtdcMoneyType	PreAvailable;
	///�����
	TFocusFtdcMoneyType	Deposit;
	///������
	TFocusFtdcMoneyType	Withdraw;
	///ռ�ñ�֤��
	TFocusFtdcMoneyType	Margin;
	///��ȨȨ������֧
	TFocusFtdcMoneyType	Premium;
	///������
	TFocusFtdcMoneyType	Fee;
	///����ı�֤��
	TFocusFtdcMoneyType	FrozenMargin;
	///����Ȩ����
	TFocusFtdcMoneyType	FrozenPremium;
	///����������
	TFocusFtdcMoneyType	FrozenFee;
	///ƽ��ӯ��
	TFocusFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TFocusFtdcMoneyType	PositionProfit;
	///�����ʽ�
	TFocusFtdcMoneyType	Available;
	///����׼����
	TFocusFtdcMoneyType	Balance;
	///��ͷռ�ñ�֤��
	TFocusFtdcMoneyType	LongMargin;
	///��ͷռ�ñ�֤��
	TFocusFtdcMoneyType	ShortMargin;
	///��ͷ����ı�֤��
	TFocusFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TFocusFtdcMoneyType	ShortFrozenMargin;
	///��̬Ȩ��
	TFocusFtdcMoneyType	DynamicRights;
	///���ն�
	TFocusFtdcRatioType	Risk;
	///��������
	TFocusFtdcMoneyType	OtherFee;
	///��Ѻ���
	TFocusFtdcMoneyType	Mortgage;
	///����
	TFocusFtdcCurrencyType	Currency;
	///��ȡ�ʽ�
	TFocusFtdcMoneyType	WithdrawQuota;
	///������
	TFocusFtdcMoneyType	TransferFee;
	///����Ĺ�����
	TFocusFtdcMoneyType	FrozenTransferFee;
	///ӡ��˰
	TFocusFtdcMoneyType	StampTax;
	///�����ӡ��˰
	TFocusFtdcMoneyType	FrozenStampTax;
};

///����Ͷ���߲�ѯ
struct CFocusFtdcQryUserInvestorField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
};

///����Ͷ����Ӧ��
struct CFocusFtdcRspUserInvestorField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///Ĭ���û�����
	TFocusFtdcUserIDType	NextUserID;
	///�Ƿ���µ�
	TFocusFtdcAdviceUserOrderModeType	OrderMode;
	///�Զ������ֶ�
	TFocusFtdcAdviceRunModeType	RunMode;
	///���������ߴ����ʾ��
	TFocusFtdcAdviceSwitchFlagType	AdviceSwitchFlag;
};

///Ͷ���߹�ϵ��ѯ
struct CFocusFtdcQryInvestorRelationField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///Ͷ���߹�ϵӦ��
struct CFocusFtdcRspInvestorRelationField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Ͷ���߱��
	TFocusFtdcInvestorIDType	ParentInvestorID;
};

///��������ѯ����
struct CFocusFtdcQryExchangeField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
};

///��������ѯӦ��
struct CFocusFtdcRspExchangeField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///����������
	TFocusFtdcExchangeNameType	ExchangeName;
};

///Ͷ���ֲֲ߳�ѯ����
struct CFocusFtdcQryInvestorPositionField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///Ͷ���ֲֲ߳�ѯӦ��
struct CFocusFtdcRspInvestorPositionField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///��������
	TFocusFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///ռ�ñ�֤��
	TFocusFtdcMoneyType	UsedMargin;
	///�ֲܳ���
	TFocusFtdcVolumeType	Position;
	///�ֲֳܳɱ�
	TFocusFtdcPriceType	PositionCost;
	///��ʼ��ֲ���(���ղ���)
	TFocusFtdcVolumeType	YdPosition;
	///��ʼ���ճֲֳɱ�(���ղ���)
	TFocusFtdcMoneyType	YdPositionCost;
	///����ı�֤��
	TFocusFtdcMoneyType	FrozenMargin;
	///���ֶ���ֲ�
	TFocusFtdcVolumeType	FrozenPosition;
	///ƽ�ֶ���ֲ�
	TFocusFtdcVolumeType	FrozenClosing;
	///�ֲ�ӯ��
	TFocusFtdcMoneyType	PositionProfit;
	///�����Ȩ����
	TFocusFtdcMoneyType	FrozenPremium;
	///���һ�ʳɽ����
	TFocusFtdcTradeIDType	LastTradeID;
	///���һ�ʱ��ر������
	TFocusFtdcOrderLocalIDType	LastOrderLocalID;
	///�ֲֿܳ�ƽ������(����ƽ�ֶ���ֲ�)
	TFocusFtdcVolumeType	PositionClose;
	///��ֲֿ�ƽ������(����ƽ�ֶ���ֲ�)
	TFocusFtdcVolumeType	YdPositionClose;
	///��ֲ�ƽ�ֶ���ֲ�
	TFocusFtdcVolumeType	YdFrozenClosing;
	///���տ�������(����������)
	TFocusFtdcVolumeType	OpenVolume;
	///����ƽ������(������ֲֵ�ƽ��,����������)
	TFocusFtdcVolumeType	CloseVolume;
	///ƽ��ӯ��
	TFocusFtdcMoneyType	CloseProfit;
	///�깺�������
	TFocusFtdcVolumeType	PurRedVolume;
	///�깺��ض�������
	TFocusFtdcVolumeType	FrozenPurRedVolume;
	///���տ��ֶ�������
	TFocusFtdcVolumeType	FrozenOpenVolume;
	///֤ȯ������ֵ
	TFocusFtdcMoneyType	CurrentStkValue;
	///֤ȯί�е�λ��0-�ɣ�1-��
	TFocusFtdcOrderUnitType	OrderUnit;
};

///�û���ѯ
struct CFocusFtdcQryUserField
{
	///�����û�����
	TFocusFtdcUserIDType	StartUserID;
	///�����û�����
	TFocusFtdcUserIDType	EndUserID;
};

///�û�
struct CFocusFtdcRspUserField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û���¼����
	TFocusFtdcPasswordType	Password;
	///Ͷ��������
	TFocusFtdcInvestorIDType	GroupID;
	///Ͷ��������
	TFocusFtdcInvestorNameType	GroupName;
	///�Ƿ��Ծ
	TFocusFtdcIsActiveType	IsActive;
	///�û�����
	TFocusFtdcUserNameType	UserName;
	///�û�����
	TFocusFtdcUserTypeType	UserType;
	///Ӫҵ��
	TFocusFtdcDepartmentType	Department;
	///��Ȩ���ܼ�
	TFocusFtdcGrantFuncSetType	GrantFuncSet;
	///���������
	TFocusFtdcNumberType	MaxOnline;
	///IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///�Ƿ������Ӳ�Ʒ
	TFocusFtdcBoolType	CheckProductInfo;
	///Mac��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///�Ƿ���IP��MAC
	TFocusFtdcBoolType	CheckIPMacAddr;
	///�����½��������
	TFocusFtdcNumberType	LoginErrorLimit;
	///Ŀǰ�����½����
	TFocusFtdcNumberType	LoginErrorCount;
};

///Ͷ�����������ʲ�ѯ
struct CFocusFtdcQryInvestorFeeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///Ͷ������������
struct CFocusFtdcRspInvestorFeeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���������Ѱ�����
	TFocusFtdcRatioType	OpenFeeRate;
	///���������Ѱ�����
	TFocusFtdcRatioType	OpenFeeAmt;
	///ƽ�������Ѱ�����
	TFocusFtdcRatioType	OffsetFeeRate;
	///ƽ�������Ѱ�����
	TFocusFtdcRatioType	OffsetFeeAmt;
	///ƽ��������Ѱ�����
	TFocusFtdcRatioType	OTFeeRate;
	///ƽ��������Ѱ�����
	TFocusFtdcRatioType	OTFeeAmt;
};

///Ͷ���߱�֤���ʲ�ѯ
struct CFocusFtdcQryInvestorMarginField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
};

///Ͷ���߱�֤����
struct CFocusFtdcRspInvestorMarginField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///��ͷռ�ñ�֤�𰴱���
	TFocusFtdcRatioType	LongMarginRate;
	///��ͷ��֤������
	TFocusFtdcRatioType	LongMarginAmt;
	///��ͷռ�ñ�֤�𰴱���
	TFocusFtdcRatioType	ShortMarginRate;
	///��ͷ��֤������
	TFocusFtdcRatioType	ShortMarginAmt;
};

///Ͷ���߲�ѯ
struct CFocusFtdcQryInvestorField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///Ͷ����Ӧ��
struct CFocusFtdcRspInvestorField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ�����
	TFocusFtdcPasswordType	InvestorPasswd;
	///Ͷ��������
	TFocusFtdcInvestorNameType	InvestorName;
	///Ͷ��������
	TFocusFtdcInvestorTypeType	InvestorType;
	///�ͻ�����
	TFocusFtdcClientTypeType	ClientType;
	///�Ϻ��ɶ�����(����������)
	TFocusFtdcInvestorIDType	SSERegId;
	///���ڹɶ�����(����������)
	TFocusFtdcInvestorIDType	SZSERegId;
	///���������ױ���(����������)
	TFocusFtdcInvestorIDType	SHFERegId;
	///֣����������(����������)
	TFocusFtdcInvestorIDType	ZCERegId;
	///����������(����������)
	TFocusFtdcInvestorIDType	DCERegId;
	///Ͷ��������
	TFocusFtdcInvestorIDType	GroupID;
	///Ͷ��������
	TFocusFtdcInvestorNameType	GroupName;
	///����
	TFocusFtdcAliasType	Alias;
	///��������
	TFocusFtdcLinkTypeType	LinkType;
	///�ն���ϢID����͸ʽ�������Ҫ�õ��ģ�
	TFocusFtdcCustomType	F_TerminalId;
	///�ʽ��˻����
	TFocusFtdcInvestorIDType	ParentInvestorID;
	///��¼����
	TFocusFtdcNumberType	LoginStatus;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TFocusFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TFocusFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TFocusFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TFocusFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TFocusFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TFocusFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TFocusFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TFocusFtdcDistributeTypeType	DistributeType;
};

///�˺ŷ���״����ѯ
struct CFocusFtdcQryAccountRiskField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///�˺ŷ���״��Ӧ��
struct CFocusFtdcRspAccountRiskField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///����׼����
	TFocusFtdcMoneyType	SetBalance;
	///���ֺ���
	TFocusFtdcMoneyType	OpenAvailable;
	///ƽ�ֺ���
	TFocusFtdcMoneyType	OffsetAvailable;
	///�˻�״̬
	TFocusFtdcAccountStatusType	AccountStatus;
	///��̬Ȩ��
	TFocusFtdcMoneyType	DynamicRights;
	///�˻�Ȩ��
	TFocusFtdcTradingRightType	TradingRight;
};

///�����û��Ự��ѯ
struct CFocusFtdcQryUserSessionField
{
	///�����û�����
	TFocusFtdcUserIDType	StartUserID;
	///�����û�����
	TFocusFtdcUserIDType	EndUserID;
};

///�����û��ỰӦ��
struct CFocusFtdcRspUserSessionField
{
	///���͹�˾����
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///�����û�����
	TFocusFtdcUserTypeType	UserType;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///��¼ʱ��
	TFocusFtdcTimeType	LoginTime;
	///IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///�û��˲�Ʒ��Ϣ
	TFocusFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TFocusFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TFocusFtdcProtocolInfoType	ProtocolInfo;
};

///�����ѯ
struct CFocusFtdcQryMarketDataField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///����Ӧ��
struct CFocusFtdcRspMarketDataField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///������
	TFocusFtdcPriceType	PreClosePrice;
	///��ֲ���
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TFocusFtdcRatioType	PreDelta;
	///֤ȯ����״̬
	TFocusFtdcStkOrderStatusType	StkOrderStatus;
	///����
	TFocusFtdcPriceType	OpenPrice;
	///��߼�
	TFocusFtdcPriceType	HighestPrice;
	///��ͼ�
	TFocusFtdcPriceType	LowestPrice;
	///������
	TFocusFtdcPriceType	ClosePrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///�����
	TFocusFtdcPriceType	SettlementPrice;
	///����ʵ��
	TFocusFtdcRatioType	CurrDelta;
	///���¼�
	TFocusFtdcPriceType	LastPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///�ɽ����
	TFocusFtdcMoneyType	Turnover;
	///�ֲ���
	TFocusFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TFocusFtdcPriceType	BidPrice1;
	///������һ
	TFocusFtdcVolumeType	BidVolume1;
	///������һ
	TFocusFtdcPriceType	AskPrice1;
	///������һ
	TFocusFtdcVolumeType	AskVolume1;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TFocusFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TFocusFtdcMillisecType	UpdateMillisec;
};

///��Ʒ��ѯ
struct CFocusFtdcQryProductField
{
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
};

///��ƷӦ��
struct CFocusFtdcRspProductField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///Ͷ���߷��еĲ�Ʒ����
	TFocusFtdcProductNameType	ProductName;
	///����
	TFocusFtdcCurrencyType	Currency;
	///����
	TFocusFtdcRatioType	ExchangeRate;
	///��Ʒ����
	TFocusFtdcProductClassType	ProductClass;
};

///�ڲ�������Ϣ
struct CFocusFtdcPingPongField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���
	TFocusFtdcSequenceNoType	SequenceNo;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
};

///���ɽ���������ѯ����
struct CFocusFtdcQryMaxVolumeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
};

///���ɽ���������ѯӦ��
struct CFocusFtdcRspMaxVolumeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
};

///����������Ա��ѯ����
struct CFocusFtdcQryAdviceTraderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��¼���͹�˾���
	TFocusFtdcBrokerIDType	LogBrokerID;
	///��¼�û�����
	TFocusFtdcUserIDType	LogUserID;
};

///����������Ա��ѯӦ��
struct CFocusFtdcRspAdviceTraderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�����û�����
	TFocusFtdcUserIDType	RelationUserID;
	///�����û�����
	TFocusFtdcUserNameType	RelationUserName;
};

///��ϳֲ���ϸ��ѯ����
struct CFocusFtdcQryCmbPositionDetailField
{
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///��ϳֲ���ϸ��ѯӦ��
struct CFocusFtdcRspCmbPositionDetailField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���Ⱥ�Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���Ⱥ�Լ����
	TFocusFtdcInstrumentIDType	CmbInstrumentID;
	///�ɽ����
	TFocusFtdcTradeIDType	TradeID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�ֲ���
	TFocusFtdcVolumeType	Position;
	///���ȱ��
	TFocusFtdcNumberType	LegQty;
	///��������
	TFocusFtdcTradingDayType	TradingDay;
};

///Ͷ���߽�������ѯ����
struct CFocusFtdcQrySettlementInfoField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��������
	TFocusFtdcTradingDayType	TradingDay;
};

///Ͷ���߽�������ѯӦ��
struct CFocusFtdcRspSettlementInfoField
{
	///��������
	TFocusFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���
	TFocusFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TFocusFtdcContentType	Content;
};

///��ѯ�������ҳ
struct CFocusFtdcQryResultPageField
{
	///��������
	TFocusFtdcSessionIDType	ResultID;
	///�ܼ�¼��
	TFocusFtdcNumberType	Count;
	///��ҳ��
	TFocusFtdcNumberType	Pages;
	///ʣ��ҳ��
	TFocusFtdcNumberType	Remain;
};

///��ѯ�ֲ���ϸ����
struct CFocusFtdcQryPositionDetailField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���Ⱥ�Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///��ѯ�ֲ���ϸӦ��
struct CFocusFtdcRspPositionDetailField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��������
	TFocusFtdcDateType	OpenDate;
	///�ɽ����
	TFocusFtdcTradeIDType	TradeID;
	///����
	TFocusFtdcVolumeType	Volume;
	///���ּ�
	TFocusFtdcMoneyType	OpenPrice;
	///������
	TFocusFtdcDateType	TradingDay;
	///��������
	TFocusFtdcTradeTypeType	TradeType;
	///��Ϻ�Լ����
	TFocusFtdcInstrumentIDType	CombInstrumentID;
	///���ն���ƽ��ӯ��
	TFocusFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TFocusFtdcMoneyType	CloseProfitByTrade;
	///���ն��гֲ�ӯ��
	TFocusFtdcMoneyType	PositionProfitByDate;
	///��ʶԳ�ֲ�ӯ��
	TFocusFtdcMoneyType	PositionProfitByTrade;
	///Ͷ���߱�֤��
	TFocusFtdcMoneyType	Margin;
	///��������֤��
	TFocusFtdcMoneyType	ExchMargin;
	///��֤����
	TFocusFtdcMoneyType	MarginRateByMoney;
	///��֤����(������)
	TFocusFtdcMoneyType	MarginRateByVolume;
	///������
	TFocusFtdcPriceType	LastSettlementPrice;
	///�����
	TFocusFtdcPriceType	SettlementPrice;
	///ƽ����
	TFocusFtdcVolumeType	CloseVolume;
	///ƽ�ֽ��
	TFocusFtdcMoneyType	CloseAmount;
};

///���ۼ�����
struct CFocusFtdcTheoryPriceDataField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���ۼ�
	TFocusFtdcPriceType	TheoryPrice;
	///���۲�����
	TFocusFtdcVolatilityType	TheoryVol;
	///������¼�
	TFocusFtdcPriceType	UnderlyingLastPrice;
	///�����1��
	TFocusFtdcPriceType	UnderlyingBidPrice1;
	///�����1��
	TFocusFtdcPriceType	UnderlyingAskPrice1;
	///ʣ��ʱ��
	TFocusFtdcTimeValueType	RemainDay;
};

///��Ȩָ������
struct CFocusFtdcOptionIndexDataField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///Delta
	TFocusFtdcGreekValueType	Delta;
	///Gamma
	TFocusFtdcGreekValueType	Gamma;
	///Vega
	TFocusFtdcGreekValueType	Vega;
	///Theta
	TFocusFtdcGreekValueType	Theta;
	///Rho
	TFocusFtdcGreekValueType	Rho;
	///��1�۲�����
	TFocusFtdcVolatilityType	BidVol;
	///��1�۲�����
	TFocusFtdcVolatilityType	AskVol;
	///�м�۲�����
	TFocusFtdcVolatilityType	MidVol;
	///���¼۲�����
	TFocusFtdcVolatilityType	LastVol;
	///���¼�
	TFocusFtdcPriceType	LastPrice;
	///��1��
	TFocusFtdcPriceType	BidPrice1;
	///��1��
	TFocusFtdcPriceType	AskPrice1;
	///���۲�����
	TFocusFtdcVolatilityType	TheoryVol;
	///������¼�
	TFocusFtdcPriceType	UnderlyingLastPrice;
	///�����1��
	TFocusFtdcPriceType	UnderlyingBidPrice1;
	///�����1��
	TFocusFtdcPriceType	UnderlyingAskPrice1;
	///ʣ������
	TFocusFtdcTimeValueType	RemainDay;
	///�Ƿ��ǿͻ������õĲ�����
	TFocusFtdcYesOrNoType	IsManalSetVol;
	///AtmVol������
	TFocusFtdcVolatilityType	AtmVol;
};

///���۲���
struct CFocusFtdcPricingParamField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Ĵ���
	TFocusFtdcInstrumentIDType	UnderlyingId;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///һ���۸�
	TFocusFtdcPriceTypeType	PriceLevel1;
	///�����۸�
	TFocusFtdcPriceTypeType	PriceLevel2;
	///�����۸�
	TFocusFtdcPriceTypeType	PriceLevel3;
	///��������
	TFocusFtdcDateTypeType	CalcDayType;
	///��������
	TFocusFtdcVolumeType	YearTotalDay;
	///��ʱ��ʽ
	TFocusFtdcTimingPatternType	CalcTimeType;
	///�޷�������
	TFocusFtdcRatioType	RiskFreeRate;
	///��Ϣ��
	TFocusFtdcRatioType	Dividend;
	///����ģ��
	TFocusFtdcPricingMethodType	PricingEngine;
	///��Ȩ��ʽ
	TFocusFtdcExerciseTypeType	ExerciseType;
	///�����ʾ���
	TFocusFtdcToleranceType	VolTolerance;
	///����������
	TFocusFtdcVolTypeType	VolType;
};

///��Ȩ���۲�����
struct CFocusFtdcOptionTheoryVolField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���۲�����
	TFocusFtdcVolatilityType	TheoryVol;
};

///���ۻ�������
struct CFocusFtdcBasePricingParamField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����Ŀ��
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///��Ȩ��ʽ
	TFocusFtdcExerciseTypeType	ExerciseType;
	///��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType;
	///��ļ۸�
	TFocusFtdcPriceType	UnderlyingPrice;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///�޷�������
	TFocusFtdcRatioType	RiskFreeRate;
	///��Ϣ��
	TFocusFtdcRatioType	Dividend;
	///ʣ������
	TFocusFtdcTimeValueType	RemainDay;
	///������
	TFocusFtdcDateType	TradingDate;
	///������
	TFocusFtdcDateType	ExpireDate;
	///������
	TFocusFtdcVolatilityType	Vol;
	///����ģ��
	TFocusFtdcPricingMethodType	PricingModel;
	///��Ȩ��ֵ
	TFocusFtdcPriceType	OptionPrice;
	///����Ƶ��
	TFocusFtdcVolumeType	ResetFrequency;
	///Delta
	TFocusFtdcGreekValueType	Delta;
	///Gamma
	TFocusFtdcGreekValueType	Gamma;
	///Vega
	TFocusFtdcGreekValueType	Vega;
	///Theta
	TFocusFtdcGreekValueType	Theta;
	///Rho
	TFocusFtdcGreekValueType	Rho;
	///Vanna
	TFocusFtdcGreekValueType	Vanna;
	///Volga
	TFocusFtdcGreekValueType	Volga;
};

///˫�ϰ���Ȩ���۲���
struct CFocusFtdcDoubleBarrierPricingParamField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����Ŀ��
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///��Ȩ��ʽ
	TFocusFtdcExerciseTypeType	ExerciseType;
	///��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType;
	///��ļ۸�
	TFocusFtdcPriceType	UnderlyingPrice;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///�޷�������
	TFocusFtdcRatioType	RiskFreeRate;
	///��Ϣ��
	TFocusFtdcRatioType	Dividend;
	///ʣ������
	TFocusFtdcTimeValueType	RemainDay;
	///������
	TFocusFtdcDateType	TradingDate;
	///������
	TFocusFtdcDateType	ExpireDate;
	///������
	TFocusFtdcVolatilityType	Vol;
	///����ģ��
	TFocusFtdcPricingMethodType	PricingModel;
	///��Ȩ��ֵ
	TFocusFtdcPriceType	OptionPrice;
	///����Ƶ��
	TFocusFtdcVolumeType	ResetFrequency;
	///Delta
	TFocusFtdcGreekValueType	Delta;
	///Gamma
	TFocusFtdcGreekValueType	Gamma;
	///Vega
	TFocusFtdcGreekValueType	Vega;
	///Theta
	TFocusFtdcGreekValueType	Theta;
	///Rho
	TFocusFtdcGreekValueType	Rho;
	///Vanna
	TFocusFtdcGreekValueType	Vanna;
	///Volga
	TFocusFtdcGreekValueType	Volga;
	///�ϰ�����
	TFocusFtdcBarrierTypeType	BarrierType;
	///�ϰ�����ֵ
	TFocusFtdcRatioType	LowerBarrierRate;
	///�ϰ�����ֵ
	TFocusFtdcRatioType	UpperBarrierRate;
};

///��������ϲ���
struct CFocusFtdcVolatilityFittingField
{
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///ʣ������
	TFocusFtdcTimeValueType	RemainDay;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///������
	TFocusFtdcVolatilityType	Vol;
};

///Wingģ�Ͳ���
struct CFocusFtdcWingModelParamField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ʒ�ֱ��
	TFocusFtdcProductIDType	ProductID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///���ʱѡ�õ�ģ��
	TFocusFtdcFitModelTypeType	FitModel;
	///wingģ�Ͳ�������
	TFocusFtdcWingParamTypeType	WingParamType;
	///������
	TFocusFtdcDateType	TradingDay;
	///����ʱ��
	TFocusFtdcTimeType	InsertTime;
	///ATM
	TFocusFtdcPriceType	Atm;
	///Days
	TFocusFtdcPriceType	Days;
	///�ο��۸�
	TFocusFtdcPriceType	ref;
	///ssr
	TFocusFtdcPriceType	ssr;
	///vcr
	TFocusFtdcPriceType	vcr;
	///scr
	TFocusFtdcPriceType	scr;
	///cc
	TFocusFtdcPriceType	cc;
	///uc
	TFocusFtdcPriceType	uc;
	///usm
	TFocusFtdcPriceType	usm;
	///pc
	TFocusFtdcPriceType	pc;
	///dc
	TFocusFtdcPriceType	dc;
	///dsm
	TFocusFtdcPriceType	dsm;
	///vr
	TFocusFtdcPriceType	vr;
	///sr
	TFocusFtdcPriceType	sr;
	///vc
	TFocusFtdcPriceType	vc;
	///sc
	TFocusFtdcPriceType	sc;
};

///Wingģ�Ͳ�����ѯ����
struct CFocusFtdcQryWingModelParamField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///wingģ�Ͳ�������
	TFocusFtdcWingParamTypeType	WingParamType;
	///���ʱѡ�õ�ģ��
	TFocusFtdcFitModelTypeType	FitModel;
};

///���б����ۼƼ۸�
struct CFocusFtdcQuoteTotalTradePriceField
{
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��ǰ���ɽ���������Ա���ã����ܿ�ƽ
	TFocusFtdcVolumeType	AskTradeVolume;
	///��ǰ��ɽ���������Ա���ã����ܿ�ƽ
	TFocusFtdcVolumeType	BidTradeVolume;
	///��ǰ����ʵ�ʱ����
	TFocusFtdcPriceType	BidQuotePrice;
	///��ǰ����ʵ�ʱ�����
	TFocusFtdcVolumeType	BidQuoteAmount;
	///��ǰ����ʵ�ʱ�����
	TFocusFtdcPriceType	AskQuotePrice;
	///��ǰ����ʵ�ʱ�����
	TFocusFtdcVolumeType	AskQuoteAmount;
	///����ʵ�ʻ�Ӧѯ������
	TFocusFtdcVolumeType	ForQuoteSendAmount;
	///�����յ�ѯ����������
	TFocusFtdcVolumeType	ForQuoteTotalAmount;
	///��ǰѯ�ۻ�Ӧʵ�ʱ����
	TFocusFtdcPriceType	BidForQuotePrice;
	///��ǰѯ�ۻ�Ӧʵ�ʱ�����
	TFocusFtdcVolumeType	BidForQuoteAmount;
	///��ǰѯ�ۻ�Ӧʵ�ʱ�����
	TFocusFtdcPriceType	AskForQuotePrice;
	///��ǰѯ�ۻ�Ӧʵ�ʱ�����
	TFocusFtdcVolumeType	AskForQuoteAmount;
	///�ƶ����۷���
	TFocusFtdcFowardDirectionType	FowardDirection;
};

///���в���
struct CFocusFtdcMarkerStrategyField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�Զ�����
	TFocusFtdcIsActiveType	AutoOffer;
	///�Զ���Ӧѯ��
	TFocusFtdcIsActiveType	AutoRespAsking;
	///���۱�����
	TFocusFtdcVolumeType	BidAmount;
	///���۱�����
	TFocusFtdcVolumeType	AskAmount;
	///ѯ�۱�����
	TFocusFtdcVolumeType	ForQuoteBidAmount;
	///ѯ�۱�����
	TFocusFtdcVolumeType	ForQuoteAskAmount;
	///��������
	TFocusFtdcVolumeType	BidMax;
	///��������
	TFocusFtdcVolumeType	AskMax;
	///�۲�����
	TFocusFtdcSpreadTypeType	SpreadType;
	///���ۼ۲���
	TFocusFtdcMoneyType	QuotePriceWidth;
	///���ۼ۲��
	TFocusFtdcLargeVolumeType	QuoteWidthRatio;
	///ѯ�ۼ۲���
	TFocusFtdcMoneyType	ForQuotePriceWidth;
	///ѯ�ۼ۲��
	TFocusFtdcLargeVolumeType	ForQuoteWidthRatio;
	///�Ƿ���Ч
	TFocusFtdcIsActiveType	IsActive;
	///��ע
	TFocusFtdcRemarkType	Remark;
	///���۷�ʽ
	TFocusFtdcQuoteRightPriceTypeType	OfferType;
	///���ļ����̶�
	TFocusFtdcVolumeType	TOL_TICK;
	///ѯ�ۻ�Ӧ���۷�ʽ
	TFocusFtdcQuoteRightPriceTypeType	ForQuoteOfferType;
	///���ۿ�ȵ�λ
	TFocusFtdcQuoteWidthTypeType	QuoteWidthType;
	///ѯ�ۻ�Ӧ��ȵ�λ
	TFocusFtdcQuoteWidthTypeType	ForQuoteWidthType;
	///��Լ������ֹͣ����
	TFocusFtdcYesOrNoType	InstrumentOneSide;
	///��ĵ�����ֹͣ����
	TFocusFtdcYesOrNoType	UnderlyingOneSide;
	///��Լ����Э����ֹͣ����
	TFocusFtdcMoneyType	MinPrice;
	///���ۼۿ�ģ��
	TFocusFtdcQuoteStepType	QuoteStepID;
	///����Delta�ۿ�ģ��
	TFocusFtdcQuoteStepType	QuoteDeltaStepID;
	///����Vega�ۿ�ģ��
	TFocusFtdcQuoteStepType	QuoteVegaStepID;
	///ѯ�ۻ�Ӧ�ۿ�ģ��
	TFocusFtdcQuoteStepType	ForQuoteStepID;
	///ѯ�ۻ�ӦDelta�ۿ�ģ��
	TFocusFtdcQuoteStepType	ForQuoteDeltaStepID;
	///ѯ�ۻ�ӦVega�ۿ�ģ��
	TFocusFtdcQuoteStepType	ForQuoteVegaStepID;
};

///�û�����
struct CFocusFtdcUserSwitchField
{
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///����Ա�ܿ���
	TFocusFtdcSwitchFlagType	WholeSwitch;
	///�Զ�����
	TFocusFtdcSwitchFlagType	WholeOffer;
	///�Զ���Ӧѯ��
	TFocusFtdcSwitchFlagType	WholeRespAsking;
	///�Զ��Գ�
	TFocusFtdcSwitchFlagType	WholeHedge;
};

///���жԳ�
struct CFocusFtdcMarkerHedgeField
{
	///�Գ���
	TFocusFtdcInstrumentIDType	UnderlyingId;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Ȩϵ��
	TFocusFtdcContentType	OptionSeriesId;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�Զ��Գ�
	TFocusFtdcIsActiveType	AutoHedge;
	///�Գ屨������
	TFocusFtdcHedgePriceTypeType	HedgePriceType;
	///�Գ��㷨
	TFocusFtdcHdegeTypeType	HdegeType;
	///�Գ�����
	TFocusFtdcVolumeType	HedgePeriod;
	///Delta����
	TFocusFtdcPriceType	DeltaMax;
	///Delta����
	TFocusFtdcPriceType	DelatMin;
	///���Գ�ʱ��
	TFocusFtdcTimeType	LastHedgeTime;
	///Ĭ���µ�ʱ�ĳ���ɱ�
	TFocusFtdcVolumeType	OrderPriceSlip;
};

///��ϲ���
struct CFocusFtdcFittingParamField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///���ģ��
	TFocusFtdcFitModelTypeType	FitModel;
	///CallBid����
	TFocusFtdcSwitchFlagType	CallBidFlag;
	///CallAsk����
	TFocusFtdcSwitchFlagType	CallAskFlag;
	///PutBid����
	TFocusFtdcSwitchFlagType	PutBidFlag;
	///PutAsk����
	TFocusFtdcSwitchFlagType	PutAskFlag;
	///CallMid����
	TFocusFtdcSwitchFlagType	CallMidFlag;
	///PutMid����
	TFocusFtdcSwitchFlagType	PutMidFlag;
	///OTM����
	TFocusFtdcSwitchFlagType	OTMFlag;
	///�Զ��޳��쳣ֵ
	TFocusFtdcSwitchFlagType	AutoRemoveOutlier;
	///��Ч��������
	TFocusFtdcValidIntervalTypeType	ValidIntervalMax;
	///��Ч��������
	TFocusFtdcValidIntervalTypeType	ValidIntervalMin;
	///�Զ����
	TFocusFtdcSwitchFlagType	AutoFit;
	///�Զ���ϼ��ʱ��
	TFocusFtdcNumberType	AUTO_FIT_TIME;
};

///��ϲ�����ѯ����
struct CFocusFtdcQryFittingParamField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
};

///��ѯ�۸��������
struct CFocusFtdcQryPricingParamField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
};

///��ѯ��Ȩ���۲���������
struct CFocusFtdcQryOptionTheoryVolField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///���뱨��
struct CFocusFtdcInputQuoteField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���زο����
	TFocusFtdcQuoteRefType	QuoteRef;
	///���ر��۱��
	TFocusFtdcOrderLocalIDType	QuoteLocalID;
	///�򱾵زο����۱��
	TFocusFtdcQuoteRefType	AskOrderRef;
	///�����زο����۱��
	TFocusFtdcQuoteRefType	BidOrderRef;
	///���۱��
	TFocusFtdcQuoteSysIDType	QuoteSysID;
	///Ӧ�۱��
	TFocusFtdcQuoteSysIDType	ForQuoteSysID;
	///��������
	TFocusFtdcVolumeType	BidVolume;
	///��������
	TFocusFtdcVolumeType	AskVolume;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///����Ͽ�ƽ��־
	TFocusFtdcOffsetFlagType	BidOffsetFlag;
	///������ױ���־
	TFocusFtdcHedgeFlagType	BidHedgeFlag;
	///�򷽼۸�
	TFocusFtdcPriceType	BidPrice;
	///������Ͽ�ƽ��־
	TFocusFtdcOffsetFlagType	AskOffsetFlag;
	///��������ױ���־
	TFocusFtdcHedgeFlagType	AskHedgeFlag;
	///�����۸�
	TFocusFtdcPriceType	AskPrice;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///�Ƿ��Զ�����
	TFocusFtdcAutoTradeType	IsAuto;
	///����API�е����
	TFocusFtdcNumberType	APIID;
	///��ע
	TFocusFtdcRemarkType	Remark;
};

///���۲���
struct CFocusFtdcQuoteActionField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���۱��
	TFocusFtdcQuoteSysIDType	QuoteSysID;
	///���ر��۱��
	TFocusFtdcOrderLocalIDType	QuoteLocalID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����������־
	TFocusFtdcActionFlagType	ActionFlag;
	///��Ա����
	TFocusFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TFocusFtdcClientIDType	ClientID;
	///�������ر��
	TFocusFtdcOrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����API�е����
	TFocusFtdcNumberType	APIID;
};

///���۲�ѯ
struct CFocusFtdcQryQuoteField
{
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///ϵͳ���۱��
	TFocusFtdcQuoteSysIDType	QuoteSysID;
	///�ͻ�����
	TFocusFtdcClientIDType	ClientID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
};

///����
struct CFocusFtdcQuoteField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���زο����
	TFocusFtdcQuoteRefType	QuoteRef;
	///���ر��۱��
	TFocusFtdcOrderLocalIDType	QuoteLocalID;
	///�򱾵زο����۱��
	TFocusFtdcQuoteRefType	AskOrderRef;
	///�����زο����۱��
	TFocusFtdcQuoteRefType	BidOrderRef;
	///���۱��
	TFocusFtdcQuoteSysIDType	QuoteSysID;
	///Ӧ�۱��
	TFocusFtdcQuoteSysIDType	ForQuoteSysID;
	///��������
	TFocusFtdcVolumeType	BidVolume;
	///��������
	TFocusFtdcVolumeType	AskVolume;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///����Ͽ�ƽ��־
	TFocusFtdcOffsetFlagType	BidOffsetFlag;
	///������ױ���־
	TFocusFtdcHedgeFlagType	BidHedgeFlag;
	///�򷽼۸�
	TFocusFtdcPriceType	BidPrice;
	///������Ͽ�ƽ��־
	TFocusFtdcOffsetFlagType	AskOffsetFlag;
	///��������ױ���־
	TFocusFtdcHedgeFlagType	AskHedgeFlag;
	///�����۸�
	TFocusFtdcPriceType	AskPrice;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///�Ƿ��Զ�����
	TFocusFtdcAutoTradeType	IsAuto;
	///����API�е����
	TFocusFtdcNumberType	APIID;
	///��ע
	TFocusFtdcRemarkType	Remark;
	///����ʱ��
	TFocusFtdcTimeType	InsertTime;
	///����ʱ��
	TFocusFtdcTimeType	CancelTime;
	///�ɽ�ʱ��
	TFocusFtdcTimeType	TradeTime;
	///�򷽱������
	TFocusFtdcOrderSysIDType	BidOrderSysID;
	///�����������
	TFocusFtdcOrderSysIDType	AskOrderSysID;
	///����״̬
	TFocusFtdcQuoteStatusType	QuoteStatus;
	///�����ύ״̬
	TFocusFtdcQuoteStatusType	OrderSubmitStatus;
};

///ѯ��
struct CFocusFtdcInputReqForQuoteField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///ѯ�۱��
	TFocusFtdcQuoteSysIDType	ReqForQuoteID;
	///�ͻ�����
	TFocusFtdcClientIDType	ClientID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///ѯ��ʱ��
	TFocusFtdcTimeType	ReqForQuoteTime;
	///�û����ر�����
	TFocusFtdcOrderSysIDType	ForQuoteLocalID;
};

///����ѯ
struct CFocusFtdcQryOrderInsertFailedField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��¼���͹�˾���
	TFocusFtdcBrokerIDType	LogBrokerID;
	///��¼�û�����
	TFocusFtdcUserIDType	LogUserID;
};

///����
struct CFocusFtdcOrderInsertFailedField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Ʊί������(������ί����Ч)
	TFocusFtdcOrderSysIDType	BatchNum;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///��������
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///��Ч������
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD����
	TFocusFtdcDateType	GTDDate;
	///�ɽ�������
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TFocusFtdcVolumeType	MinVolume;
	///ֹ���
	TFocusFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TFocusFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TFocusFtdcBusinessTypeType	BusinessType;
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����ʱ��
	TFocusFtdcTimeType	InsertTime;
	///������Դ
	TFocusFtdcOrderSourceType	OrderSource;
	///����״̬
	TFocusFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TFocusFtdcTimeType	CancelTime;
	///�����û����
	TFocusFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TFocusFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TFocusFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TFocusFtdcVolumeType	VolumeCancled;
	///�������
	TFocusFtdcErrorIDType	ErrorID;
	///������Ϣ
	TFocusFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TFocusFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TFocusFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///������
	TFocusFtdcRequestIDType	RequestID;
	///ÿ��������
	TFocusFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TFocusFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TFocusFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TFocusFtdcBranchIDType	BranchID;
	///��¼���
	TFocusFtdcSequenceNoType	RecNum;
	///��Ա���
	TFocusFtdcParticipantIDType	ParticipantID;
	///�ͻ���
	TFocusFtdcClientIDType	ClientID;
	///�µ�ϯλ��
	TFocusFtdcSeatIDType	SeatID;
	///���ر������
	TFocusFtdcOrderLocalIDType	OrderLocalID;
	///���ʽ��ʺ�
	TFocusFtdcAccountIDType	SubAccountID;
	///�µ��û����
	TFocusFtdcUserIDType	OrderUserID;
	///��������
	TFocusFtdcTradeTypeType	TradeType;
	///�����־
	TFocusFtdcDealFlagType	DealFlag;
	///�ѳɽ�Ӷ��
	TFocusFtdcMoneyType	TradeCommision;
	///�ɽ����
	TFocusFtdcMoneyType	TradeAmnt;
	///ͨ�����ر������Ƴ�����Ͷ���߱��
	TFocusFtdcInvestorIDType	SubInvestorID;
	///Ͷ��������
	TFocusFtdcInvestorTypeType	InvestorType;
	///�ӱ������
	TFocusFtdcOrderSysIDType	SubOrderSysID;
	///��Ͷ���߱��
	TFocusFtdcCodeType	ParentInvestorCode;
	///ʹ���ĸ�ͨ���µ�
	TFocusFtdcNumberType	APIID;
	///ƽ�ֶ�������
	TFocusFtdcVolumeType	VolumeFrozenClosing;
	///��������
	TFocusFtdcVolumeType	VolumeFrozen;
	///�����������˶����ʽ�
	TFocusFtdcMoneyType	FrozenMoney;
	///�������������
	TFocusFtdcOrderSysIDType	AdviceOrderSysID;
	///֤ȯ�ĸ���Ʒ
	TFocusFtdcProductIDType	ProductID;
	///�����������˶���������
	TFocusFtdcMoneyType	FrozenFee;
	///�����������˶��ٹ�����
	TFocusFtdcMoneyType	FrozenTransferFee;
	///�����������˶���ӡ��˰
	TFocusFtdcMoneyType	FrozenStampTax;
	///����ֶ�������
	TFocusFtdcVolumeType	PurRedVolumeFrozen;
	///�������ֶ�������
	TFocusFtdcVolumeType	CloseVolumeFrozen;
	///��ע
	TFocusFtdcRemarkType	Remark;
};

///���ۺ�Լ�۲�
struct CFocusFtdcPriceSpreadField
{
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///�۲�
	TFocusFtdcPriceType	Spread;
	///�۲��Լ����
	TFocusFtdcInstrumentIDType	SpreadInstrumentId;
	///�۲����÷�ʽ
	TFocusFtdcPriceSpreadTypeType	PriceSpreadType;
};

///��ѯ��Լ�۲�
struct CFocusFtdcQryPriceSpreadField
{
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
};

///��ѯ���жԳ�
struct CFocusFtdcQryMarkerHedgeField
{
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
};

///������־��Ϣ
struct CFocusFtdcStrategyLogField
{
	///��־���
	TFocusFtdcNumberType	EventID;
	///��������
	TFocusFtdcTradingDayType	TradingDay;
	///�����¼�����
	TFocusFtdcEventTypeType	EventType;
	///�����¼�����
	TFocusFtdcSequenceNoType	EventCode;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��־����
	TFocusFtdcLargeErrorMsgType	Log_Content;
	///��������
	TFocusFtdcDateType	OperDate;
	///����ʱ��
	TFocusFtdcTimeType	OperTime;
};

///Ԥ��ָ������
struct CFocusFtdcAlertIndexSetParamField
{
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///Ͷ��������
	TFocusFtdcInvestorTypeType	InvestorType;
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///ָ����ϸ����
	TFocusFtdcAlertIndexTypeType	AlertIndexCode;
	///��ɫԤ������
	TFocusFtdcLargeVolumeType	MAX_L1;
	///��ɫԤ������
	TFocusFtdcLargeVolumeType	MIN_L1;
	///��ɫԤ������
	TFocusFtdcLargeVolumeType	MAX_L2;
	///��ɫԤ������
	TFocusFtdcLargeVolumeType	MIN_L2;
	///Ĭ��ʱ����
	TFocusFtdcNumberType	TimeAvail;
	///��ɫԤ������
	TFocusFtdcAlertActionTypeType	AlertAction;
};

///��ѯԤ��ָ������
struct CFocusFtdcQryAlertIndexSetParamField
{
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///Ͷ��������
	TFocusFtdcInvestorTypeType	InvestorType;
	///ָ����ϸ����
	TFocusFtdcAlertIndexTypeType	AlertIndexCode;
};

///Ԥ��ָ��ֵ
struct CFocusFtdcAlertIndexSetDataField
{
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///ָ����ϸ����
	TFocusFtdcAlertIndexTypeType	AlertIndexCode;
	///ָ����ϸֵ
	TFocusFtdcLargeVolumeType	IndexVolume;
	///��ɫԤ������
	TFocusFtdcLargeVolumeType	MAX_L1;
	///��ɫԤ������
	TFocusFtdcLargeVolumeType	MIN_L1;
	///��ɫԤ������
	TFocusFtdcLargeVolumeType	MAX_L2;
	///��ɫԤ������
	TFocusFtdcLargeVolumeType	MIN_L2;
	///Ԥ������
	TFocusFtdcAlertActionTypeType	AlertAction;
	///���ֵ����
	TFocusFtdcDateType	OperDate;
	///���ֵʱ��
	TFocusFtdcTimeType	OperTime;
};

///���б����ۼƳֲ�
struct CFocusFtdcQuoteTotalTradePositionField
{
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///�����ۼ���ɽ������ܿ�ƽ
	TFocusFtdcVolumeType	BuyVolume;
	///�����ۼ����ɽ������ܿ�ƽ
	TFocusFtdcVolumeType	SellVolume;
	///���վ��ɽ������ܿ�ƽ
	TFocusFtdcVolumeType	NetVolume;
	///������ֲ֣���ͷ�ֲ�
	TFocusFtdcVolumeType	BuyPosition;
	///�������ֲ֣���ͷ�ֲ�
	TFocusFtdcVolumeType	SellPosition;
	///���վ��ֲ�
	TFocusFtdcVolumeType	NetPosition;
};

///�������ݶȼ۲�
struct CFocusFtdcMarkerStepField
{
	///�ݶ�ģ��
	TFocusFtdcQuoteStepType	StepID;
	///�ݶ�����
	TFocusFtdcStepNameType	StepName;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�ݶ�����
	TFocusFtdcStepTypeType	StepType;
	///�ݶȵ�λ
	TFocusFtdcQuoteWidthTypeType	WidthType;
	///�۸�����
	TFocusFtdcPriceType	LowPrice;
	///�۸�����
	TFocusFtdcPriceType	UpPrice;
	///StepValue1
	TFocusFtdcPriceType	StepValue1;
	///StepValue2
	TFocusFtdcPriceType	StepValue2;
	///StepValue3
	TFocusFtdcPriceType	StepValue3;
	///value��ֵ
	TFocusFtdcNumberType	StepValueKey;
};

///���б����ƶ�����
struct CFocusFtdcQuoteMoveField
{
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///�ɽ�ͳ��ʱ�䣨�룩
	TFocusFtdcNumberType	SumVolumeTime;
	///�ɽ����������ɽ���������������
	TFocusFtdcNumberType	SumVolume;
	///����ƫ�ƣ��ٷֱȣ�
	TFocusFtdcRatioType	Move;
	///ά��ʱ�䣨�룩
	TFocusFtdcNumberType	KeepTime;
	///�����ɽ����۲���:0������ 1��˫��
	TFocusFtdcTakeOutType	TakeOut;
	///�رգ�0��������1
	TFocusFtdcSwitchFlagType	IsActive;
	///�ٽ�ִ�м�ƫ�ƣ��رգ�0��������1
	TFocusFtdcSwitchFlagType	NearStrikeMove;
	///�ٽ�ִ�м۲����ʲ�ֵ
	TFocusFtdcPriceType	NearStrikeVolSpread;
	///�ٽ�ִ�м��ƶ����ͣ�0�����ۼ۷��� 1�����ּ۷���
	TFocusFtdcOrderTypeType	NearMoveType;
	///�ٽ�ִ�м�ά��ʱ�䣨�룩
	TFocusFtdcVolumeType	NearKeepTime;
};

///�����ݶȼ۲���Ϣ
struct CFocusFtdcBaseMarkerStepField
{
	///�ݶ�ģ��
	TFocusFtdcQuoteStepType	StepID;
	///�ݶ�����
	TFocusFtdcStepNameType	StepName;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�ݶ�����
	TFocusFtdcStepTypeType	StepType;
	///�ݶȵ�λ
	TFocusFtdcQuoteWidthTypeType	WidthType;
};

///��̨���̽���״̬
struct CFocusFtdcFocusStatusField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///���̽���״̬
	TFocusFtdcIsActiveType	TradeStatus;
};

///ATM�۸�
struct CFocusFtdcATMPriceDataField
{
	///�û�����(����Ա)
	TFocusFtdcUserIDType	UserID;
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///��ļ۸񣬼������ۼۣ�Greeks�봫���
	TFocusFtdcPriceType	UnderlyingMid;
	///���Զ�ڼ۸�
	TFocusFtdcPriceType	AtmForword;
	///ʣ������
	TFocusFtdcTimeValueType	RemainDay;
	///V10D
	TFocusFtdcPriceType	V10D;
	///V10D
	TFocusFtdcPriceType	V25D;
	///V10D
	TFocusFtdcPriceType	V45D;
	///ATM ������
	TFocusFtdcPriceType	AtmVol;
	///V10D
	TFocusFtdcPriceType	V55D;
	///V10D
	TFocusFtdcPriceType	V75D;
	///V10D
	TFocusFtdcPriceType	V90D;
	///���ֵʱ��
	TFocusFtdcTimeType	OperTime;
};

///�ڻ������ܿ���
struct CFocusFtdcFutureMakerWholeSwitchField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����Ա�ܿ���
	TFocusFtdcSwitchFlagType	WholeSwitch;
};

///�ڻ����б��۲���
struct CFocusFtdcFutureMakerStrategyField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///һ������
	TFocusFtdcSwitchFlagType	FirstSwitch;
	///һ���ڻ����۷�ʽ
	TFocusFtdcFutureMakerFlagType	FirstFutureMakerFlag;
	///һ�����̶�
	TFocusFtdcVolumeType	FirstToler;
	///һ���µ���
	TFocusFtdcVolumeType	FirstAmount;
	///һ����ȣ�tick��
	TFocusFtdcVolumeType	FirstWidth;
	///��������
	TFocusFtdcSwitchFlagType	SecondSwitch;
	///�����ڻ����۷�ʽ
	TFocusFtdcFutureMakerFlagType	SecondFutureMakerFlag;
	///�������̶�
	TFocusFtdcVolumeType	SecondToler;
	///�����µ���
	TFocusFtdcVolumeType	SecondAmount;
	///������ȣ�tick��
	TFocusFtdcVolumeType	SecondWidth;
	///��������
	TFocusFtdcSwitchFlagType	ThirdSwitch;
	///�����ڻ����۷�ʽ
	TFocusFtdcFutureMakerFlagType	ThirdFutureMakerFlag;
	///�������̶�
	TFocusFtdcVolumeType	ThirdToler;
	///�����µ���
	TFocusFtdcVolumeType	ThirdAmount;
	///������ȣ�tick��
	TFocusFtdcVolumeType	ThirdWidth;
	///�ɽ�ͳ��ʱ�䣨�룩
	TFocusFtdcNumberType	SumVolumeTime;
	///�ɽ����������ɽ���������������
	TFocusFtdcNumberType	SumVolume;
	///ά��ʱ�䣨�룩
	TFocusFtdcNumberType	KeepTime;
	///�ڻ���ƽ��־
	TFocusFtdcOffsetFlagType	FutureOffsetFlag;
};

///�ڻ����ֶԳ����
struct CFocusFtdcSlefHedgeStrategyField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���ֱ������۷�ʽ
	TFocusFtdcHedgeFutureMakerFlagType	SlefHedgeFutureMakerFlag;
	///���ֱ�������tick
	TFocusFtdcVolumeType	SlefHedgeFutureMakerTick;
	///���ֱ���ƫ��tick���±���
	TFocusFtdcVolumeType	SlefHedgeDeviate;
	///���ֱ�����ʱ����
	TFocusFtdcVolumeType	SlefHedgeTimeAction;
	///����׷������
	TFocusFtdcVolumeType	SlefChaseTimes;
	///������
	TFocusFtdcVolumeType	MaxLossTick;
};

///�ڻ��Գ��Լ�Գ����
struct CFocusFtdcFutureHedgeStrategyField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///�Գ��Լ����������
	TFocusFtdcExchangeIDType	HedgeExchangeID;
	///�Գ��Լ����
	TFocusFtdcInstrumentIDType	HedgeInstrumentID;
	///�Գ��ʽ��˺�
	TFocusFtdcInvestorIDType	HedgeInvestorID;
	///�۲�
	TFocusFtdcPriceType	Spread;
	///�ڻ��Գ屨�۷�ʽ
	TFocusFtdcHedgeFutureMakerFlagType	HedgeFutureMakerFlag;
	///�ڻ��Գ����tick
	TFocusFtdcVolumeType	HedgeFutureMakerTick;
	///ƫ��tick���±���
	TFocusFtdcVolumeType	HedgeDeviate;
	///�ҵ���ʱ����
	TFocusFtdcVolumeType	HedgeTimeAction;
	///׷������
	TFocusFtdcVolumeType	HedgeChaseTimes;
	///�ڻ��Գ��Լ��ƽ��־
	TFocusFtdcOffsetFlagType	HedgeOffsetFlag;
};

///���б��۶����������
struct CFocusFtdcQuoteAdditionParmField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���ۼ۲���
	TFocusFtdcMoneyType	QuotePriceWidth;
	///���ۼ۲��
	TFocusFtdcLargeVolumeType	QuoteWidthRatio;
	///���ۿ�ȵ�λ
	TFocusFtdcQuoteWidthTypeType	QuoteWidthType;
	///���ļ����̶�
	TFocusFtdcVolumeType	TOL_TICK;
	///��ע
	TFocusFtdcRemarkType	Remark;
};

///�ڻ��Գ屨��״̬֪ͨ
struct CFocusFtdcFutureMakerHedgeStatusField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���ֱ���״̬��0.�ޱ�����1.�б���
	TFocusFtdcSwitchFlagType	SlefHedgeStatus;
	///���ֱ���״̬��0.�ޱ�����1.�б���
	TFocusFtdcSwitchFlagType	FutureHedgeStatus;
};

///һ�����������ڻ����жԳ嵥
struct CFocusFtdcStopAllFutureMakerHedgeOfferField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///0�����ֶԳ嵥��2�� �ڻ��Գ嵥  3. ȫ���Գ嵥
	TFocusFtdcRemarkType	HedgeOfferType;
};

///�ڻ����м�ֵ
struct CFocusFtdcFutureMakerIndexField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///��ѯ�ڻ����в���
struct CFocusFtdcAllFutureMakerStrategyField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����Ա�ܿ���
	TFocusFtdcSwitchFlagType	WholeSwitch;
	///һ������
	TFocusFtdcSwitchFlagType	FirstSwitch;
	///һ���ڻ����۷�ʽ
	TFocusFtdcFutureMakerFlagType	FirstFutureMakerFlag;
	///һ�����̶�
	TFocusFtdcVolumeType	FirstToler;
	///һ���µ���
	TFocusFtdcVolumeType	FirstAmount;
	///һ����ȣ�tick��
	TFocusFtdcVolumeType	FirstWidth;
	///��������
	TFocusFtdcSwitchFlagType	SecondSwitch;
	///�����ڻ����۷�ʽ
	TFocusFtdcFutureMakerFlagType	SecondFutureMakerFlag;
	///�������̶�
	TFocusFtdcVolumeType	SecondToler;
	///�����µ���
	TFocusFtdcVolumeType	SecondAmount;
	///������ȣ�tick��
	TFocusFtdcVolumeType	SecondWidth;
	///��������
	TFocusFtdcSwitchFlagType	ThirdSwitch;
	///�����ڻ����۷�ʽ
	TFocusFtdcFutureMakerFlagType	ThirdFutureMakerFlag;
	///�������̶�
	TFocusFtdcVolumeType	ThirdToler;
	///�����µ���
	TFocusFtdcVolumeType	ThirdAmount;
	///������ȣ�tick��
	TFocusFtdcVolumeType	ThirdWidth;
	///�ɽ�ͳ��ʱ�䣨�룩
	TFocusFtdcNumberType	SumVolumeTime;
	///�ɽ����������ɽ���������������
	TFocusFtdcNumberType	SumVolume;
	///ά��ʱ�䣨�룩
	TFocusFtdcNumberType	KeepTime;
	///�ڻ���ƽ��־
	TFocusFtdcOffsetFlagType	FutureOffsetFlag;
	///���ֱ������۷�ʽ
	TFocusFtdcHedgeFutureMakerFlagType	SlefHedgeFutureMakerFlag;
	///���ֱ�������tick
	TFocusFtdcVolumeType	SlefHedgeFutureMakerTick;
	///���ֱ���ƫ��tick���±���
	TFocusFtdcVolumeType	SlefHedgeDeviate;
	///���ֱ�����ʱ����
	TFocusFtdcVolumeType	SlefHedgeTimeAction;
	///����׷������
	TFocusFtdcVolumeType	SlefChaseTimes;
	///������
	TFocusFtdcVolumeType	MaxLossTick;
	///�Գ��Լ����������
	TFocusFtdcExchangeIDType	HedgeExchangeID;
	///�Գ��Լ����
	TFocusFtdcInstrumentIDType	HedgeInstrumentID;
	///�Գ��ʽ��˺�
	TFocusFtdcInvestorIDType	HedgeInvestorID;
	///�۲�
	TFocusFtdcPriceType	Spread;
	///�ڻ��Գ屨�۷�ʽ
	TFocusFtdcHedgeFutureMakerFlagType	HedgeFutureMakerFlag;
	///�ڻ��Գ����tick
	TFocusFtdcVolumeType	HedgeFutureMakerTick;
	///ƫ��tick���±���
	TFocusFtdcVolumeType	HedgeDeviate;
	///�ҵ���ʱ����
	TFocusFtdcVolumeType	HedgeTimeAction;
	///׷������
	TFocusFtdcVolumeType	HedgeChaseTimes;
	///�ڻ��Գ��Լ��ƽ��־
	TFocusFtdcOffsetFlagType	HedgeOffsetFlag;
};

///�ڲ���Ʊ��Ƶ���Ա�
struct CFocusFtdcInnerHighStockStrategyField
{
	///��������
	TFocusFtdcTradingDayType	TradingDay;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʊ��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///��Ʊ������
	TFocusFtdcStrategyNameType	StockStrategyName;
	///�������ͣ�����or���֣�����Ϊ0������Ϊ����0��
	TFocusFtdcVolumeType	StockStrategyType;
	///ÿ����ƱȨ��
	TFocusFtdcRatioType	Ratio;
	///ÿ������µ��������裩
	TFocusFtdcVolumeType	MaxVolume;
	///ÿ����С���������裬Ĭ��Ϊ100��
	TFocusFtdcVolumeType	MinVolume;
	///��Ʊÿ���µ�������%��
	TFocusFtdcRatioType	StockRatioAvail;
	///�г�ƽ�����Ͼ��۳ɽ���1
	TFocusFtdcVolumeType	AverMactchTradeVolume1;
	///�г�ƽ�����Ͼ��۳ɽ���2
	TFocusFtdcVolumeType	AverMactchTradeVolume2;
	///������
	TFocusFtdcPriceType	PreClosePrice;
	///��Ʊ�µ�����
	TFocusFtdcStockStrategyPriceType	StockPriceType;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����ί�е�
	TFocusFtdcOrderSysIDType	LastOrderSysID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��Ʊί������(������ί����Ч)
	TFocusFtdcOrderSysIDType	LastBatchNum;
	///���ճֲ�
	TFocusFtdcVolumeType	YPosition;
	///���ʼ��Ŀ��ֲ�
	TFocusFtdcVolumeType	StaticEndPosition;
	///��Ŀ��ֲ�
	TFocusFtdcVolumeType	EndPosition;
	///��ʵ��Ŀǰ�ֲ�
	TFocusFtdcVolumeType	NowPosition;
	///�ֲֿܳ�ƽ������
	TFocusFtdcVolumeType	PositionClose;
	///���տ�������(����������)
	TFocusFtdcVolumeType	OpenVolume;
	///����ƽ������(������ֲֵ�ƽ��,����������)
	TFocusFtdcVolumeType	CloseVolume;
	///AlphaĿ�������ֵ(�������)
	TFocusFtdcMoneyType	AlphaTargetValue;
	///Alpha��ǰ�������ʽ�(�������)
	TFocusFtdcMoneyType	AlphaCurrentTotalValue;
	///��ʼ����ʱ��
	TFocusFtdcTimeType	StartOperTime;
	///���²���ʱ��
	TFocusFtdcTimeType	LastOperTime;
	///������Ҫ��������
	TFocusFtdcVolumeType	LastNeedSendVolume;
	///���±��ļ۸�
	TFocusFtdcPriceType	LastSendPrice;
	///�����г��ܳɽ���
	TFocusFtdcVolumeType	PreMarketTradeVolume;
	///��Ʊƽ���ɽ���ͳ�Ƽ��������MA��
	TFocusFtdcNumberType	MAStockAvail;
	///���ʱ���ڵ��г���Ʊƽ���ɽ���
	TFocusFtdcVolumeType	GapVolume;
	///��ֻ��Ʊ��ǰ�Ƿ����ڽ���
	TFocusFtdcBoolType	StockIsTrading;
	///�ù��Ƿ��ǵͼ۹�
	TFocusFtdcBoolType	IsLowStock;
	///����֮ǰ������ɽ�����
	TFocusFtdcVolumeType	SignalHasBuyTotalPosition;
	///����֮ǰ�������ɽ�����
	TFocusFtdcVolumeType	SignalHasSellTotalPosition;
	///��������ɱ���
	TFocusFtdcMoneyType	SignalLastPer;
	///������ע
	TFocusFtdcDepositNoteType	Note;
	///����Ȩ
	TFocusFtdcDepositNoteType	Priority;
	///��������״̬
	TFocusFtdcDepositNoteType	StkOrderStatus;
	///���̼۸�
	TFocusFtdcPriceType	OpenPrice;
	///�ܳɽ������������������
	TFocusFtdcVolumeType	TotalTradeVolume;
	///�������ܳɱ�
	TFocusFtdcMoneyType	TotalBuyCostMoney;
	///�������ܳɱ�
	TFocusFtdcMoneyType	TotalSellCostMoney;
	///����ƽ���ɱ�
	TFocusFtdcMoneyType	AverCostMoney;
	///�ڼ��ֱ���
	TFocusFtdcVolumeType	TotalRoundAmount;
	///β�̲���֮ǰ�ܳɽ������������������
	TFocusFtdcVolumeType	AllAddTotalTradeVolume;
	///β�̲���֮ǰ�����ۻ����ܳɱ�
	TFocusFtdcMoneyType	AllAddTotalBuyCostMoney;
	///β�̲���֮ǰ�����ۻ����ܳɱ�
	TFocusFtdcMoneyType	AllAddTotalSellCostMoney;
	///β�̲���֮ǰ�����ۻ�ƽ���ɱ�
	TFocusFtdcMoneyType	AllAddAverCostMoney;
	///������list�ʼ��Ŀ��ֲ�
	TFocusFtdcVolumeType	AlphaListStaticEndPosition;
	///������listĿ��ֲ�
	TFocusFtdcVolumeType	AlphaListEndPosition;
	///������list���³ֲ�
	TFocusFtdcVolumeType	AlphaListNowPosition;
	///AlphaList����Ȩ
	TFocusFtdcDepositNoteType	AlphaListPriority;
	///��ֻ��ƱAlphaList��ǰ�Ƿ����ڽ���
	TFocusFtdcBoolType	AlphaListStockIsTrading;
	///������list�ʼ��Ŀ��ֲ�
	TFocusFtdcVolumeType	TZeroStaticEndPosition;
	///����list��Ŀ��ֲ�
	TFocusFtdcVolumeType	TZeroEndPosition;
	///����listʵ��Ŀǰ�ֲ�
	TFocusFtdcVolumeType	TZeroNowPosition;
	///t0��������ʱ��
	TFocusFtdcTimeType	TZeroLastOperTime;
	///TZero��Ҫ�ı�Ĺ���
	TFocusFtdcVolumeType	TZeroGapVolume;
	///TZero�������ʱ��
	TFocusFtdcTimeType	TZeroEndOperTime;
	///TZero�µ����޼۸�
	TFocusFtdcPriceType	TZeroUpperEndPrice;
	///TZero�µ����޼۸�
	TFocusFtdcPriceType	TZeroLowerEndPrice;
	///TZero��Ʊ�µ�����
	TFocusFtdcStockStrategyPriceType	TZeroStockPriceType;
	///TZero�ֲ֣��ܣ�
	TFocusFtdcVolumeType	TZeroAddPosition;
	///TZero�ܾ�̬������ֵ
	TFocusFtdcPriceType	T0StaticTotalMoney;
	///TZero��̬����
	TFocusFtdcPriceType	TZeroStaticRights;
	///TZeroƽ������
	TFocusFtdcPriceType	TZeroColseRights;
	///��Ȼ��Ҫ���׵���
	TFocusFtdcVolumeType	StillNeedSendPosition;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///�㷨������ע
	TFocusFtdcDepositNoteType	AlgoNote;
};

///��Ʊ���Կ���
struct CFocusFtdcWholeHighStockStrategySwitchField
{
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///�������ͣ�����or���֣�����Ϊ0������Ϊ����0��
	TFocusFtdcVolumeType	StockStrategyType;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///����Ա�ܿ���
	TFocusFtdcSwitchFlagType	StockWholeSwitch;
};

///��ѯ���Եļ�ֵ
struct CFocusFtdcQryWholeHighStockStrategyField
{
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///�������ͣ�����or���֣�����Ϊ0������Ϊ����0��
	TFocusFtdcVolumeType	StockStrategyType;
};

///��ѯ���Եĵ�����Ʊ�ļ�ֵ
struct CFocusFtdcQrySignalHighStockStrategyField
{
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///�������ͣ�����or���֣�����Ϊ0������Ϊ����0��
	TFocusFtdcVolumeType	StockStrategyType;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʊ��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///��ѯ���Եĵ�����Ʊ�ļ�ֵ
struct CFocusFtdcSignalHighStockStrategySwitchField
{
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///�������ͣ�����or���֣�����Ϊ0������Ϊ����0��
	TFocusFtdcVolumeType	StockStrategyType;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʊ��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Ʊ��������
	TFocusFtdcSwitchFlagType	StockWholeSwitch;
};

///��Ʊ��Ƶ���Ա�
struct CFocusFtdcAPIHighStockStrategyField
{
	///��������
	TFocusFtdcTradingDayType	TradingDay;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʊ��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///��Ʊ������
	TFocusFtdcStrategyNameType	StockStrategyName;
	///�������ͣ�����or���֣�����Ϊ0������Ϊ����0��
	TFocusFtdcVolumeType	StockStrategyType;
	///ÿ����ƱȨ��
	TFocusFtdcRatioType	Ratio;
	///ÿ������µ��������裩
	TFocusFtdcVolumeType	MaxVolume;
	///ÿ����С���������裬Ĭ��Ϊ100��
	TFocusFtdcVolumeType	MinVolume;
	///��Ʊÿ���µ�������%��
	TFocusFtdcRatioType	StockRatioAvail;
	///�г�ƽ�����Ͼ��۳ɽ���1
	TFocusFtdcVolumeType	AverMactchTradeVolume1;
	///�г�ƽ�����Ͼ��۳ɽ���2
	TFocusFtdcVolumeType	AverMactchTradeVolume2;
	///������
	TFocusFtdcPriceType	PreClosePrice;
	///��Ʊ�µ�����
	TFocusFtdcStockStrategyPriceType	StockPriceType;
};

///��Ʊ�ڻ��Գ��ϵ��
struct CFocusFtdcHighFutureStrategyRelationField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///�������ͣ�����or���֣�����Ϊ0������Ϊ����0��
	TFocusFtdcVolumeType	StockStrategyType;
	///��Ʊ���Ե�ǰ�Ƿ���
	TFocusFtdcBoolType	StockStrategyIsTrading;
	///��Ʊ��ѵ���ʱ�������룩
	TFocusFtdcNumberType	StockTimeAvail;
	///��Ʊƽ���ɽ���ͳ�Ƽ��������MA��
	TFocusFtdcNumberType	MAStockAvail;
	///������Ʊ�������̶ȣ������µ�ʱ�߼۹�#�ͼ۹�@����ʱ�߼۹�#�ͼ۹� J#A@A#A
	TFocusFtdcDepositNoteType	StockTolerRatio;
	///ֹͣ������Ʊ���������ƫ����ʣ�%��
	TFocusFtdcRatioType	StopDeviRatio;
	///�ָ���Ʊ���������ƫ����ʣ�%��
	TFocusFtdcRatioType	RrecovrDeviRatio;
	///��ʼ��Ԥ���任�����ʽ�
	TFocusFtdcMoneyType	TargetMoney;
	///ÿ���µ���ֵ�����ʽ�
	TFocusFtdcMoneyType	RoundMaxMoney;
	///�ڻ�����������
	TFocusFtdcExchangeIDType	FutureExchangeID;
	///�ڻ���Լ����
	TFocusFtdcInstrumentIDType	FutureInstrumentID;
	///�ڻ���������
	TFocusFtdcDirectionType	FutureDirection;
	///�ڻ���������
	TFocusFtdcStockStrategyPriceType	FuturePriceType;
	///��Ӧ�ڻ���ǰ�Ƿ��ף�����Ĭ�Ͽ�����Ч��
	TFocusFtdcBoolType	FutureIsTrading;
	///�ڻ��ʽ��˺�
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///�ڻ�Ĭ�ϼ��ʱ����
	TFocusFtdcNumberType	FutureTimeAvail;
	///�̶���ع����
	TFocusFtdcMoneyType	StaticRebuyMoney;
	///�Ƿ������ǵ�ͣ
	TFocusFtdcSwitchFlagType	BRNeedContinue;
	///��󻻲ֱ���
	TFocusFtdcRatioType	MaxTradePer;
	///�ڻ��㷨����
	TFocusFtdcVolumeType	FutureAlgoType;
	///ָ��������
	TFocusFtdcExchangeIDType	IndexExchangeID;
	///ָ����Լ
	TFocusFtdcInstrumentIDType	IndexInstrumentID;
	///����
	TFocusFtdcPriceType	SpreadPrice;
	///�ڻ��µ�����
	TFocusFtdcVolumeType	FutureAmount;
	///List��price�ļ۸�����
	TFocusFtdcListPriceTypeType	ListPriceType;
	///�����µ�ƥ���(0~1)
	TFocusFtdcRatioType	FuStockRelation;
	///�Ƿ�����ڻ��µ�
	TFocusFtdcBoolType	FlowerFuture;
	///�ڻ��������
	TFocusFtdcVolumeType	FutureAvailAmount;
	///��λȨ������
	TFocusFtdcPositionRatioTypeType	PositionRatioType;
	///��Ʊ�����㷨(0,���� 1 AlgoTwap 2. AlgoVwap)
	TFocusFtdcVolumeType	StockAlgoType;
	///���Կ�ʼʱ��(HH:mm:ss)
	TFocusFtdcTimeType	AlgoStrategyStartTime;
	///����ֹͣʱ��(HH:mm:ss)
	TFocusFtdcTimeType	AlgoStrategyEndTime;
};

///��Ʊ�ڻ��Գ��ϵ�ڲ���
struct CFocusFtdcHighInnerFutureStrategyRelationField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///�������ͣ�����or���֣�����Ϊ0������Ϊ����0��
	TFocusFtdcVolumeType	StockStrategyType;
	///��Ʊ���Ե�ǰ�Ƿ���
	TFocusFtdcBoolType	StockStrategyIsTrading;
	///��Ʊ��ѵ���ʱ�������룩
	TFocusFtdcNumberType	StockTimeAvail;
	///��Ʊƽ���ɽ���ͳ�Ƽ��������MA��
	TFocusFtdcNumberType	MAStockAvail;
	///������Ʊ�������̶ȣ������µ�ʱ�߼۹�#�ͼ۹�@����ʱ�߼۹�#�ͼ۹� J#A@A#A
	TFocusFtdcDepositNoteType	StockTolerRatio;
	///ֹͣ������Ʊ���������ƫ����ʣ�%��
	TFocusFtdcRatioType	StopDeviRatio;
	///�ָ���Ʊ���������ƫ����ʣ�%��
	TFocusFtdcRatioType	RrecovrDeviRatio;
	///��ʼ��Ԥ���任�����ʽ�
	TFocusFtdcMoneyType	TargetMoney;
	///ÿ���µ���ֵ�����ʽ�
	TFocusFtdcMoneyType	RoundMaxMoney;
	///�ڻ�����������
	TFocusFtdcExchangeIDType	FutureExchangeID;
	///�ڻ���Լ����
	TFocusFtdcInstrumentIDType	FutureInstrumentID;
	///�ڻ���������
	TFocusFtdcDirectionType	FutureDirection;
	///�ڻ���������
	TFocusFtdcStockStrategyPriceType	FuturePriceType;
	///��Ӧ�ڻ���ǰ�Ƿ��ף�����Ĭ�Ͽ�����Ч��
	TFocusFtdcBoolType	FutureIsTrading;
	///�ڻ��ʽ��˺�
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///�ڻ�Ĭ�ϼ��ʱ����
	TFocusFtdcNumberType	FutureTimeAvail;
	///�̶���ع����
	TFocusFtdcMoneyType	StaticRebuyMoney;
	///�Ƿ������ǵ�ͣ
	TFocusFtdcSwitchFlagType	BRNeedContinue;
	///��󻻲ֱ���
	TFocusFtdcRatioType	MaxTradePer;
	///�ڻ��㷨����
	TFocusFtdcVolumeType	FutureAlgoType;
	///ָ��������
	TFocusFtdcExchangeIDType	IndexExchangeID;
	///ָ����Լ
	TFocusFtdcInstrumentIDType	IndexInstrumentID;
	///����
	TFocusFtdcPriceType	SpreadPrice;
	///�ڻ��µ�����
	TFocusFtdcVolumeType	FutureAmount;
	///List��price�ļ۸�����
	TFocusFtdcListPriceTypeType	ListPriceType;
	///�����µ�ƥ���(0~1)
	TFocusFtdcRatioType	FuStockRelation;
	///�Ƿ�����ڻ��µ�
	TFocusFtdcBoolType	FlowerFuture;
	///�ڻ��������
	TFocusFtdcVolumeType	FutureAvailAmount;
	///��λȨ������
	TFocusFtdcPositionRatioTypeType	PositionRatioType;
	///��Ʊ�����㷨(0,���� 1 AlgoTwap 2. AlgoVwap)
	TFocusFtdcVolumeType	StockAlgoType;
	///���Կ�ʼʱ��(HH:mm:ss)
	TFocusFtdcTimeType	AlgoStrategyStartTime;
	///����ֹͣʱ��(HH:mm:ss)
	TFocusFtdcTimeType	AlgoStrategyEndTime;
	///������ע
	TFocusFtdcDepositNoteType	Note;
	///��������״̬
	TFocusFtdcDepositNoteType	RelationOrderStatus;
	///ʵ�ʷ������ʽ�
	TFocusFtdcMoneyType	RealTargetMoney;
	///�������ܳɽ�����
	TFocusFtdcMoneyType	LastTotalBuyMoney;
	///�������ܳɽ�����
	TFocusFtdcMoneyType	LastTotalSellMoney;
	///������Ҫ����ܽ��
	TFocusFtdcMoneyType	LastTotalNeedBuyMoney;
	///������Ҫ�����ܽ��
	TFocusFtdcMoneyType	LastTotalNeedSellMoney;
	///���¶�����ܽ��
	TFocusFtdcMoneyType	LastFrozenMoney;
	///����ɱ���
	TFocusFtdcMoneyType	LastBuyPer;
	///����ɱ���
	TFocusFtdcMoneyType	LastSellPer;
	///���²���ʱ��
	TFocusFtdcTimeType	LastOperTime;
	///�������ܳɱ�
	TFocusFtdcMoneyType	TotalBuyCostMoney;
	///�������ܳɱ�
	TFocusFtdcMoneyType	TotalSellCostMoney;
	///���������ѳɱ�
	TFocusFtdcMoneyType	TotalFeeCostMoney;
	///����ƽ���ɱ�
	TFocusFtdcMoneyType	AverCostMoney;
	///�Ƿ��������
	TFocusFtdcDepositNoteType	IsPerEqual;
	///�����۲�ֵ��������
	TFocusFtdcMoneyType	BuySellGapMoney;
	///β�������ܳɽ����
	TFocusFtdcMoneyType	CloseEndSellMoney;
	///����ɱ�
	TFocusFtdcMoneyType	TotalAverCostMoney;
	///�Ƿ��Զ���ع�
	TFocusFtdcSwitchFlagType	BRebuySwitch;
	///β�̲���֮ǰ�����ۻ��������ܳɽ�����
	TFocusFtdcMoneyType	AllAddLastTotalBuyMoney;
	///β�̲���֮ǰ�����ۻ��������ܳɽ�����
	TFocusFtdcMoneyType	AllAddLastTotalSellMoney;
	///β�̲���֮ǰ�����ۻ����ܳɱ�
	TFocusFtdcMoneyType	AllAddTotalBuyCostMoney;
	///β�̲���֮ǰ�����ۻ����ܳɱ�
	TFocusFtdcMoneyType	AllAddTotalSellCostMoney;
	///β�̲���֮ǰ�����ۻ��������ѳɱ�
	TFocusFtdcMoneyType	AllAddTotalFeeCostMoney;
	///β�̲���֮ǰ�����ۻ�ƽ���ɱ�
	TFocusFtdcMoneyType	AllAddAverCostMoney;
	///β�̲���֮ǰ�����ۻ�����ɱ�
	TFocusFtdcMoneyType	AllAddTotalAverCostMoney;
	///��ʱ����
	TFocusFtdcDepositNoteType	IndexDirSignal;
	///�����ڻ�����ʱ��
	TFocusFtdcTimeType	LastFuOperTime;
	///����ɶԳ��ܽ�����
	TFocusFtdcVolumeType	LastFuTarNetPosition;
	///�Գ������ע
	TFocusFtdcDepositNoteType	FutureNote;
	///�ڻ��۲�Գ��Ƿ���Ҫ���
	TFocusFtdcBoolType	FutureSpreadNeedCheck;
	///�����ǿ��ڻ��۸�
	TFocusFtdcPriceType	OpenFuInstrPrice;
	///�ϴ���ɵ��ܽ�����
	TFocusFtdcVolumeType	BeforeLastFuTarNetPosition;
	///�ֻ������ڻ�����
	TFocusFtdcRatioType	NetFuPosition;
	///ʵʱ����
	TFocusFtdcPriceType	RealTimeSpreadPrice;
	///ʵʱָ���۸�
	TFocusFtdcPriceType	RealIndexPrice;
	///ʵʱ�ڻ��۸�
	TFocusFtdcPriceType	RealFuturePrice;
	///�ڻ�������ע2
	TFocusFtdcDepositNoteType	FutureRelationNote;
	///�����ڻ��Գ����ʱ��
	TFocusFtdcTimeType	LastHedgeFuOperTime;
	///�㷨������ע
	TFocusFtdcDepositNoteType	AlgoNote;
};

///��ѯ���й�Ʊ�ڻ��Գ��ϵ��
struct CFocusFtdcQryAllHighFutureStrategyRelationField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
};

///��Ʊ���׽׶��µ���ʽ
struct CFocusFtdcStockMarketTradingPeriodStrategyField
{
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///��ʼʱ��
	TFocusFtdcTimeType	TpStart;
	///����ʱ��
	TFocusFtdcTimeType	TpEnd;
	///�������ͣ������µ�ʱ�߼۹�#�ͼ۹�@����ʱ�߼۹�#�ͼ۹� J#A@A#A��
	TFocusFtdcDepositNoteType	StockOrderType;
	///ֹͣ������Ʊ���������ƫ����ʣ�%��
	TFocusFtdcRatioType	StopDeviRatio;
	///�ָ���Ʊ���������ƫ����ʣ�%��
	TFocusFtdcRatioType	RrecovrDeviRatio;
	///ÿ���µ���ֵ�����ʽ�
	TFocusFtdcMoneyType	RoundMaxMoney;
	///��Ʊ��ѵ���ʱ�������룩
	TFocusFtdcNumberType	StockTimeAvail;
	///������Ʊ�������̶ȣ������µ�ʱ�߼۹�#�ͼ۹�@����ʱ�߼۹�#�ͼ۹� J#A@A#A
	TFocusFtdcDepositNoteType	StockTolerRatio;
	///�Ƿ����µ������ϴγ�����
	TFocusFtdcSwitchFlagType	NeedAddCancelVolumeSwitch;
	///ÿ���µ����ö�������ǰ������ƽ����ȡ��
	TFocusFtdcSwitchFlagType	NeedGetSideVolumeSwitch;
	///�Ƿ�MaxVolume��Ч
	TFocusFtdcSwitchFlagType	CheckMaxVolumeSwitch;
};

///��ع��Զ���������
struct CFocusFtdcRelationAutoReBuySwitchField
{
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��ع�����
	TFocusFtdcSwitchFlagType	RelationReBuySwitch;
};

///�ڻ��㷨����
struct CFocusFtdcFutureStrategyOrderField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///Ŀ�꾻�ֲ���
	TFocusFtdcVolumeType	TargetNetPosition;
	///���Կ�ʼִ��ʱ��
	TFocusFtdcTimeType	StartTradingTime;
	///�㷨����
	TFocusFtdcVolumeType	AlgoType;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///���Ե�ǰ�Ƿ���
	TFocusFtdcBoolType	StrategyIsTrading;
	///���Ա����۸�����
	TFocusFtdcStockStrategyPriceType	StrategyPrice;
	///β�̼��Ͼ�����Ҫ�µ���
	TFocusFtdcVolumeType	MactchTrdVol;
	///β�̼��Ͼ����µ���ʽ
	TFocusFtdcStockStrategyPriceType	MactchTrdPriceType;
	///Vwapÿ������µ���
	TFocusFtdcVolumeType	VwapMaxVolume;
	///�Ƿ�Ӳ�
	TFocusFtdcSwitchFlagType	IsAddPosi;
	///�µ���λ����
	TFocusFtdcAddPositionTypeType	AddPositionType;
	///�۸񴥷�����
	TFocusFtdcPriceDirectionType	PriceDirection;
	///�����۸�
	TFocusFtdcPriceType	TriggerPrice;
	///ĸ���㷨ʱ��ʱ����
	TFocusFtdcVolumeType	TotalTimeAvail;
};

///�㷨����
struct CFocusFtdcAlgoParmField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///���̶�(tick)
	TFocusFtdcVolumeType	TolerTick;
	///Twap��ʱ��(s)
	TFocusFtdcVolumeType	TwapTotalTime;
	///Twap�����Ŀ
	TFocusFtdcVolumeType	TwapSplitAmount;
	///Vwapͳ��ÿ��ƽ���ɽ�����ʱ����
	TFocusFtdcVolumeType	VwapTimeAvail;
	///Vwap���̼��ʱ��
	TFocusFtdcVolumeType	VwapTotalTime;
	///Vwap�����ܳɽ�����ʱ�������룩
	TFocusFtdcNumberType	VwapVolumeTotalTime;
	///���Ա����۸�����
	TFocusFtdcStockStrategyPriceType	StockStrategyPrice;
	///���Ŀ�꾻�ֲ�
	TFocusFtdcVolumeType	MaxNetPosition;
	///�����ϴε���С�䶯��λ
	TFocusFtdcVolumeType	MinChangePosition;
	///�Ƿ�Ƚ϶��������ٷֱ�ȡ��ֵ
	TFocusFtdcSwitchFlagType	NeedGetSideVolumeSwitch;
	///�������ı���
	TFocusFtdcRatioType	SideVolumePer;
};

///�ڻ��㷨��������
struct CFocusFtdcInnerFutureStrategyOrderField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///Ŀ�꾻�ֲ���
	TFocusFtdcVolumeType	TargetNetPosition;
	///���Կ�ʼִ��ʱ��
	TFocusFtdcTimeType	StartTradingTime;
	///�㷨����
	TFocusFtdcVolumeType	AlgoType;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///���Ե�ǰ�Ƿ���
	TFocusFtdcBoolType	StrategyIsTrading;
	///���Ա����۸�����
	TFocusFtdcStockStrategyPriceType	StrategyPrice;
	///β�̼��Ͼ�����Ҫ�µ���
	TFocusFtdcVolumeType	MactchTrdVol;
	///β�̼��Ͼ����µ���ʽ
	TFocusFtdcStockStrategyPriceType	MactchTrdPriceType;
	///Vwapÿ������µ���
	TFocusFtdcVolumeType	VwapMaxVolume;
	///�Ƿ�Ӳ�
	TFocusFtdcSwitchFlagType	IsAddPosi;
	///�µ���λ����
	TFocusFtdcAddPositionTypeType	AddPositionType;
	///�۸񴥷�����
	TFocusFtdcPriceDirectionType	PriceDirection;
	///�����۸�
	TFocusFtdcPriceType	TriggerPrice;
	///ĸ���㷨ʱ��ʱ����
	TFocusFtdcVolumeType	TotalTimeAvail;
	///���̶�(tick)
	TFocusFtdcVolumeType	TolerTick;
	///Twap��ʱ��(s)
	TFocusFtdcVolumeType	TwapTotalTime;
	///�����Ŀ
	TFocusFtdcVolumeType	TwapSplitAmount;
	///Vwapͳ��ʱ����
	TFocusFtdcVolumeType	VwapTimeAvail;
	///Vwap���̼��ʱ��
	TFocusFtdcVolumeType	VwapTotalTime;
	///Vwap�����ܳɽ�����ʱ�������룩
	TFocusFtdcNumberType	VwapVolumeTotalTime;
	///���Ա����۸�����
	TFocusFtdcStockStrategyPriceType	StockStrategyPrice;
	///���Ŀ�꾻�ֲ�
	TFocusFtdcVolumeType	MaxNetPosition;
	///�����ϴε���С�䶯��λ
	TFocusFtdcVolumeType	MinChangePosition;
	///�Ƿ�Ƚ϶��������ٷֱ�ȡ��ֵ
	TFocusFtdcSwitchFlagType	NeedGetSideVolumeSwitch;
	///�������ı���
	TFocusFtdcRatioType	SideVolumePer;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///�ֶβ���ʱ�䣨���룩
	TFocusFtdcLocalTimeType	GapMillisec;
	///С�ֶ���Ҫ���׵���
	TFocusFtdcVolumeType	SplitVolume;
	///С�ֶ���Ҫ���׵���(ԭʼ)
	TFocusFtdcVolumeType	OrginalSplitVolume;
	///ȫ����Ҫ�ɽ���
	TFocusFtdcVolumeType	StaticlTotalNeedTradeVolume;
	///���²���ʱ��(s)
	TFocusFtdcLocalTimeType	LastCurrOperTime;
	///���²���ʱ�䣨���룩
	TFocusFtdcLocalTimeType	LastCurrMillisec;
	///����ʱ������ms��
	TFocusFtdcNumberType	TolerTimeAvail;
	///����ɱ���
	TFocusFtdcMoneyType	SignalLastPer;
	///�Ƚϻ�׼���̼۸�
	TFocusFtdcPriceType	PreparPrice;
	///�ܳɱ�
	TFocusFtdcMoneyType	TotalCostMoney;
	///�������ѳɱ�
	TFocusFtdcMoneyType	TotalFeeCostMoney;
	///ƽ���ɱ�
	TFocusFtdcMoneyType	AverCostMoney;
	///������ע
	TFocusFtdcDepositNoteType	Note;
	///�������ѳɽ�����
	TFocusFtdcVolumeType	StrategyTradeVolume;
	///ʵ��Ŀǰ�ֲ�
	TFocusFtdcVolumeType	NowPosition;
	///�����½�����ʱ�䣨�룩
	TFocusFtdcTimeType	OrginRecvOrderTime;
	///����յ��ı䶩��ʱ�䣨�룩
	TFocusFtdcTimeType	LastRecvOrderTime;
	///���²���ʱ�䣨�룩
	TFocusFtdcTimeType	LastOperTime;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
};

///�ڻ��㷨���׶�����ֵ
struct CFocusFtdcFutureStrategyOrderIndexField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
};

///�����ź�
struct CFocusFtdcIndexDirSignalField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Ϣ����
	TFocusFtdcStrategyMessageTypeType	MessageType;
	///��ϢID���
	TFocusFtdcVolumeType	MessageID;
	///�Ƿ���Ҫת��
	TFocusFtdcBoolType	NeedNtfMessage;
	///����ʱ��
	TFocusFtdcTimeType	OperTime;
	///��Ϣ����
	TFocusFtdcStrategyMessageNoteType	Note;
};

///���ڲ��Զ�����ֵ
struct CFocusFtdcSpreadInstrStrategyIndexField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
};

///���ڲ���
struct CFocusFtdcSpreadInstrStrategyField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///������1����
	TFocusFtdcExchangeIDType	ExchangeIDLeg1;
	///��������1
	TFocusFtdcDirectionType	DirectionLeg1;
	///��1��Լ����
	TFocusFtdcInstrumentIDType	InstrLeg1;
	///������2����
	TFocusFtdcExchangeIDType	ExchangeIDLeg2;
	///��������2
	TFocusFtdcDirectionType	DirectionLeg2;
	///��2��Լ����
	TFocusFtdcInstrumentIDType	InstrLeg2;
	///��1��2����
	TFocusFtdcMoneyType	LegPer;
	///���Կ�ʼִ��ʱ��
	TFocusFtdcTimeType	StartTradingTime;
	///���Խ���ִ��ʱ��
	TFocusFtdcTimeType	EndTradingTime;
	///���ʱ����
	TFocusFtdcVolumeType	TimeAvail;
	///Ŀ�꽻����
	TFocusFtdcVolumeType	TargetTradeVolume;
	///��������
	TFocusFtdcStockStrategyPriceType	OrderPriceType;
	///�㷨����
	TFocusFtdcVolumeType	AlgoType;
	///�۲�
	TFocusFtdcPriceType	SpreadPrice;
	///ÿ���µ�����
	TFocusFtdcVolumeType	EachTrdvolume;
	///�Ƿ���
	TFocusFtdcBoolType	StrategyIsTrading;
	///ȱ�������Ա�ʶ
	TFocusFtdcVolumeType	LiquidLack;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///������ע
	TFocusFtdcDepositNoteType	Note;
};

///���ڲ��Զ�������
struct CFocusFtdcInnerSpreadInstrStrategyField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///������1����
	TFocusFtdcExchangeIDType	ExchangeIDLeg1;
	///��������1
	TFocusFtdcDirectionType	DirectionLeg1;
	///��1��Լ����
	TFocusFtdcInstrumentIDType	InstrLeg1;
	///������2����
	TFocusFtdcExchangeIDType	ExchangeIDLeg2;
	///��������2
	TFocusFtdcDirectionType	DirectionLeg2;
	///��2��Լ����
	TFocusFtdcInstrumentIDType	InstrLeg2;
	///��1��2����
	TFocusFtdcMoneyType	LegPer;
	///���Կ�ʼִ��ʱ��
	TFocusFtdcTimeType	StartTradingTime;
	///���Խ���ִ��ʱ��
	TFocusFtdcTimeType	EndTradingTime;
	///���ʱ����
	TFocusFtdcVolumeType	TimeAvail;
	///Ŀ�꽻����
	TFocusFtdcVolumeType	TargetTradeVolume;
	///��������
	TFocusFtdcStockStrategyPriceType	OrderPriceType;
	///�㷨����
	TFocusFtdcVolumeType	AlgoType;
	///�۲�
	TFocusFtdcPriceType	SpreadPrice;
	///ÿ���µ�����
	TFocusFtdcVolumeType	EachTrdvolume;
	///�Ƿ���
	TFocusFtdcBoolType	StrategyIsTrading;
	///ȱ�������Ա�ʶ
	TFocusFtdcVolumeType	LiquidLack;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///������ע
	TFocusFtdcDepositNoteType	Note;
	///���²���ʱ��
	TFocusFtdcTimeType	LastOperTime;
	///����ɱ���
	TFocusFtdcMoneyType	SignalLastPer;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
};

///����list������
struct CFocusFtdcTZeroHighStockStrategyField
{
	///��������
	TFocusFtdcTradingDayType	TradingDay;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʊ��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///TZero��Ҫ�ı�Ĺ���
	TFocusFtdcVolumeType	TZeroGapVolume;
	///��Ʊ�µ�����
	TFocusFtdcStockStrategyPriceType	TZeroStockPriceType;
	///TZero�������ʱ��
	TFocusFtdcTimeType	TZeroEndOperTime;
	///TZero�µ����޼۸�
	TFocusFtdcPriceType	TZeroUpperEndPrice;
	///TZero�µ����޼۸�
	TFocusFtdcPriceType	TZeroLowerEndPrice;
	///t0��������ʱ��
	TFocusFtdcTimeType	TZeroLastOperTime;
};

///�����ڻ���ʼ���ʽ�
struct CFocusFtdcFlowerFutureTargetMoneyField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��������
	TFocusFtdcTradingDayType	TradingDay;
	///���²���ʱ��
	TFocusFtdcTimeType	LastOperTime;
	///��ʼ��Ԥ���任�����ʽ�
	TFocusFtdcMoneyType	FlowerFutureTarMoney;
	///�Ƿ���Ч
	TFocusFtdcSwitchFlagType	WholeSwitch;
};

///ĸ����Ϣ
struct CFocusFtdcParentOrderField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///ĸ���ʽ����
	TFocusFtdcInvestorIDType	InvestorID;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///�㷨��������(Twap,11,Vwap 12)
	TFocusFtdcVolumeType	AlgoStrategyType;
	///���Կ�ʼ����(YYYYMMDD)
	TFocusFtdcTradingDayType	StrategyStartDay;
	///����ֹͣ����(YYYYMMDD)
	TFocusFtdcTradingDayType	StrategyEndDay;
	///���Կ�ʼʱ��(HH:mm:ss)
	TFocusFtdcTimeType	StrategyStartTime;
	///����ֹͣʱ��(HH:mm:ss)
	TFocusFtdcTimeType	StrategyEndTime;
	///����->���� 1--5
	TFocusFtdcNumberType	style;
	///����г�ռ�� TWAP/VWAP (0, 50]
	TFocusFtdcRatioType	maxVolumeP;
	///��С�ҵ�����Ĭ��Ϊ0
	TFocusFtdcVolumeType	minDisplaySize;
	///���ҵ�������һ��λ����Ĭ��Ϊ0
	TFocusFtdcVolumeType	displaySize;
	///����ͳ�ƿھ���Ĭ��Ϊ�޼��ڡ��޼��� - 0�� ȫ�г� - 1
	TFocusFtdcVolumeType	countVolInLimitPx;
	///����ʱ�������ȡ�true - 1, false - 0
	TFocusFtdcVolumeType	resetVolOnAmend;
	///�۸����ƣ�Ĭ��Ϊ0
	TFocusFtdcPriceType	limitPrice;
	///����޼ۻ�׼
	TFocusFtdcVolumeType	relativePriceLimitBase;
	///����޼�ƫ�Ƶ�λ
	TFocusFtdcVolumeType	relativePriceLimitType;
	///����޼�ƫ����
	TFocusFtdcPriceTickType	relativePriceLimitOffset;
	///�Ƿ���۲Ĭ�Ͻ��۲�
	TFocusFtdcVolumeType	stepSpread;
	///�ǵ�ͣ�������ǵ�ͣʱ����ͣ������
	TFocusFtdcVolumeType	optOnExtreme;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����
	TFocusFtdcDirectionType	Direction;
	///������
	TFocusFtdcVolumeType	orderQty;
	///�ܽ��
	TFocusFtdcMoneyType	orderAmt;
	///ĸ����������
	TFocusFtdcTradingDayType	TradingDay;
	///ĸ������ʱ��
	TFocusFtdcTimeType	LastOperTime;
	///�û��Զ�����(�����ֶ�)
	TFocusFtdcCustomType	UserCustom;
	///��ע(�����ֶ�)
	TFocusFtdcDepositNoteType	Note;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
};

///ĸ��������Ϣ
struct CFocusFtdcParentOrderActionField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///����ѡ��
	TFocusFtdcVolumeType	ActionOption;
};

///�޸�ĸ����Ϣ
struct CFocusFtdcAmendParentOrderField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///ĸ���ʽ����
	TFocusFtdcInvestorIDType	InvestorID;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///�㷨��������(Twap,11,Vwap 12)
	TFocusFtdcVolumeType	AlgoStrategyType;
	///���Կ�ʼ����(YYYYMMDD)
	TFocusFtdcTradingDayType	StrategyStartDay;
	///����ֹͣ����(YYYYMMDD)
	TFocusFtdcTradingDayType	StrategyEndDay;
	///���Կ�ʼʱ��(HH:mm:ss)
	TFocusFtdcTimeType	StrategyStartTime;
	///����ֹͣʱ��(HH:mm:ss)
	TFocusFtdcTimeType	StrategyEndTime;
	///����->���� 1--5
	TFocusFtdcNumberType	style;
	///����г�ռ�� TWAP/VWAP (0, 50]
	TFocusFtdcRatioType	maxVolumeP;
	///��С�ҵ�����Ĭ��Ϊ0
	TFocusFtdcVolumeType	minDisplaySize;
	///���ҵ�������һ��λ����Ĭ��Ϊ0
	TFocusFtdcVolumeType	displaySize;
	///����ͳ�ƿھ���Ĭ��Ϊ�޼��ڡ��޼��� - 0�� ȫ�г� - 1
	TFocusFtdcVolumeType	countVolInLimitPx;
	///����ʱ�������ȡ�true - 1, false - 0
	TFocusFtdcVolumeType	resetVolOnAmend;
	///�۸����ƣ�Ĭ��Ϊ0
	TFocusFtdcPriceType	limitPrice;
	///����޼ۻ�׼
	TFocusFtdcVolumeType	relativePriceLimitBase;
	///����޼�ƫ�Ƶ�λ
	TFocusFtdcVolumeType	relativePriceLimitType;
	///����޼�ƫ����
	TFocusFtdcPriceTickType	relativePriceLimitOffset;
	///�Ƿ���۲Ĭ�Ͻ��۲�
	TFocusFtdcVolumeType	stepSpread;
	///�ǵ�ͣ�������ǵ�ͣʱ����ͣ������
	TFocusFtdcVolumeType	optOnExtreme;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����
	TFocusFtdcDirectionType	Direction;
	///������
	TFocusFtdcVolumeType	orderQty;
	///�ܽ��
	TFocusFtdcMoneyType	orderAmt;
	///ĸ����������
	TFocusFtdcTradingDayType	TradingDay;
	///ĸ������ʱ��
	TFocusFtdcTimeType	LastOperTime;
	///�û��Զ�����(�����ֶ�)
	TFocusFtdcCustomType	UserCustom;
	///��ע(�����ֶ�)
	TFocusFtdcDepositNoteType	Note;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
};

///ĸ�������ֶ�������Ϣ
struct CFocusFtdcExtraManualParentOrderField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///ĸ���û�����
	TFocusFtdcInvestorIDType	InvestorID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///�˹�������
	TFocusFtdcVolumeType	sliceQty;
	///�˹����۸�
	TFocusFtdcPriceType	slicePrice;
	///�˹����ر�ע(�����ֶ�)
	TFocusFtdcCustomType	UserCustom;
};

///����ĸ����չ��ϸ��Ϣ
struct CFocusFtdcParentDetialUpdateMessageField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///��������
	TFocusFtdcTradingDayType	transactDay;
	///����ʱ��
	TFocusFtdcTimeType	transactTime;
	///����״̬
	TFocusFtdcVolumeType	strategyStatus;
	///��ͣԭ��
	TFocusFtdcStrategyMessageNoteType	pauseReason;
	///����
	TFocusFtdcDirectionType	Direction;
	///������
	TFocusFtdcVolumeType	orderQty;
	///�ɽ�����
	TFocusFtdcVolumeType	knockQty;
	///�ɽ����
	TFocusFtdcMoneyType	knockAmt;
	///������
	TFocusFtdcPriceType	knockAmtWithFee;
	///ĸ��״̬
	TFocusFtdcVolumeType	orderStatus;
	///ƽ���۸�
	TFocusFtdcPriceType	avgPrice;
	///�г�TWAP����
	TFocusFtdcPriceType	marketTwap;
	///�г�VWAP����
	TFocusFtdcPriceType	marketVwap;
	///����� 
	TFocusFtdcPriceType	arrivalPrice;
	///����ƫ��_T 
	TFocusFtdcRatioType	avgOffset_T;
	///����ƫ��_V 
	TFocusFtdcRatioType	avgOffset_V;
	///����ƫ��_A 
	TFocusFtdcRatioType	avgOffset_A;
	///��ʵ������ 
	TFocusFtdcRatioType	realParticipateRate;
	///������ 
	TFocusFtdcRatioType	cancelRate;
	///ƽ���ҵ�ʱ�� 
	TFocusFtdcTimeValueType	avgOpenTime;
	///�����ɽ��� 
	TFocusFtdcRatioType	passiveRate;
	///���к� 
	TFocusFtdcOrderLocalIDType	serialNum;
	///�ܾ�ԭ�� 
	TFocusFtdcErrorMsgType	failReason;
	///Ŀ����� 
	TFocusFtdcRatioType	targetProgress;
	///�ɽ����� 
	TFocusFtdcRatioType	knockPercent;
	///����ƫ�� 
	TFocusFtdcRatioType	progressOffset;
	///��Ҫ�� 
	TFocusFtdcVolumeType	pushFlag;
	///�������
	TFocusFtdcErrorIDType	ErrorID;
	///���ܺ�
	TFocusFtdcVolumeType	FunctionID;
	///���Կ�ʼʱ��(HH:mm:ss)
	TFocusFtdcTimeType	StrategyStartTime;
	///����ֹͣʱ��(HH:mm:ss)
	TFocusFtdcTimeType	StrategyEndTime;
};

///��Ʒ�����ѯ����
struct CFocusFtdcAPIQryMarketTradingTimeField
{
	///�г�id
	TFocusFtdcExchangeIDType	ExchangeID;
	///�г�����
	TFocusFtdcTimeType	ExchangeName;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
};

///�г�����ʱ�����Ϣ
struct CFocusFtdcMarketTradingPeriodInfoField
{
	///�г�id
	TFocusFtdcExchangeIDType	ExchangeID;
	///�г�����
	TFocusFtdcTimeType	ExchangeName;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��ʼʱ��
	TFocusFtdcTimeType	TpStart;
	///����ʱ��
	TFocusFtdcTimeType	TpEnd;
	///���ͱ�־
	TFocusFtdcTpFlagType	Flags;
};

///�㷨2��Ʊ�ڻ��Գ��ϵ��
struct CFocusFtdcFutureStrategyTotalSecondRelationField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///��Ʊ���Ե�ǰ�Ƿ���
	TFocusFtdcBoolType	StockStrategyIsTrading;
	///�ڻ�����������
	TFocusFtdcExchangeIDType	FutureExchangeID;
	///�ڻ���Լ����
	TFocusFtdcInstrumentIDType	FutureInstrumentID;
	///�ڻ���������
	TFocusFtdcDirectionType	FutureDirection;
	///�ڻ���������
	TFocusFtdcStockStrategyPriceType	FuturePriceType;
	///��Ӧ�ڻ���ǰ�Ƿ��ף�����Ĭ�Ͽ�����Ч��
	TFocusFtdcBoolType	FutureIsTrading;
	///�ڻ��ʽ��˺�
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///�ڻ�Ĭ�ϼ��ʱ����
	TFocusFtdcNumberType	FutureTimeAvail;
	///�ڻ��������
	TFocusFtdcVolumeType	FutureAvailAmount;
	///�ڻ��㷨����
	TFocusFtdcVolumeType	FutureAlgoType;
	///ָ��������
	TFocusFtdcExchangeIDType	IndexExchangeID;
	///ָ����Լ
	TFocusFtdcInstrumentIDType	IndexInstrumentID;
	///����
	TFocusFtdcPriceType	SpreadPrice;
	///�ڻ����µ�����
	TFocusFtdcVolumeType	FutureAmount;
	///List��price�ļ۸�����
	TFocusFtdcListPriceTypeType	ListPriceType;
	///�����µ�ƥ���(0~1)
	TFocusFtdcRatioType	FuStockRelation;
	///�Ӽ�����ʼʱ��
	TFocusFtdcTimeType	TpStart;
	///�Ӽ��ֽ���ʱ��
	TFocusFtdcTimeType	TpEnd;
};

///�㷨2��Ʊ�ڻ��Գ��ڲ�������
struct CFocusFtdcInnerFutureStrategyTotalSecondRelationField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�ù�Ʊ���ĸ��ʽ��˺�ȥ�µ�
	TFocusFtdcInvestorIDType	StockInvestorID;
	///��Ʊ����ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///��Ʊ���Ե�ǰ�Ƿ���
	TFocusFtdcBoolType	StockStrategyIsTrading;
	///�ڻ�����������
	TFocusFtdcExchangeIDType	FutureExchangeID;
	///�ڻ���Լ����
	TFocusFtdcInstrumentIDType	FutureInstrumentID;
	///�ڻ���������
	TFocusFtdcDirectionType	FutureDirection;
	///�ڻ���������
	TFocusFtdcStockStrategyPriceType	FuturePriceType;
	///��Ӧ�ڻ���ǰ�Ƿ��ף�����Ĭ�Ͽ�����Ч��
	TFocusFtdcBoolType	FutureIsTrading;
	///�ڻ��ʽ��˺�
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///�ڻ�Ĭ�ϼ��ʱ����
	TFocusFtdcNumberType	FutureTimeAvail;
	///�ڻ��������
	TFocusFtdcVolumeType	FutureAvailAmount;
	///�ڻ��㷨����
	TFocusFtdcVolumeType	FutureAlgoType;
	///ָ��������
	TFocusFtdcExchangeIDType	IndexExchangeID;
	///ָ����Լ
	TFocusFtdcInstrumentIDType	IndexInstrumentID;
	///����
	TFocusFtdcPriceType	SpreadPrice;
	///�ڻ����µ�����
	TFocusFtdcVolumeType	FutureAmount;
	///List��price�ļ۸�����
	TFocusFtdcListPriceTypeType	ListPriceType;
	///�����µ�ƥ���(0~1)
	TFocusFtdcRatioType	FuStockRelation;
	///�Ӽ�����ʼʱ��
	TFocusFtdcTimeType	TpStart;
	///�Ӽ��ֽ���ʱ��
	TFocusFtdcTimeType	TpEnd;
	///������ע
	TFocusFtdcDepositNoteType	Note;
	///�������ܳɽ�����
	TFocusFtdcMoneyType	LastTotalBuyMoney;
	///�������ܳɽ�����
	TFocusFtdcMoneyType	LastTotalSellMoney;
	///������Ҫ����ܽ��
	TFocusFtdcMoneyType	LastTotalNeedBuyMoney;
	///������Ҫ�����ܽ��
	TFocusFtdcMoneyType	LastTotalNeedSellMoney;
	///�����ڻ��Գ����ʱ��
	TFocusFtdcTimeType	LastFuOperTime;
	///����ɶԳ��ܽ�����
	TFocusFtdcVolumeType	LastFuTarNetPosition;
	///�Գ������ע
	TFocusFtdcDepositNoteType	FutureNote;
	///�ڻ��۲�Գ��Ƿ���Ҫ���
	TFocusFtdcBoolType	FutureSpreadNeedCheck;
	///�����ǿ��ڻ��۸�
	TFocusFtdcPriceType	OpenFuInstrPrice;
	///�ϴ���ɵ��ܽ�����
	TFocusFtdcVolumeType	BeforeLastFuTarNetPosition;
	///�ֻ������ڻ�����
	TFocusFtdcRatioType	NetFuPosition;
	///ʵʱ����
	TFocusFtdcPriceType	RealTimeSpreadPrice;
	///ʵʱָ���۸�
	TFocusFtdcPriceType	RealIndexPrice;
	///ʵʱ�ڻ��۸�
	TFocusFtdcPriceType	RealFuturePrice;
	///�����ڻ��Գ����ʱ��
	TFocusFtdcTimeType	LastHedgeFuOperTime;
	///�ڻ�ʵ��ƥ������
	TFocusFtdcRatioType	DoubleFutureAmount;
};

///�ڻ��㷨���׶�����ֵ
struct CFocusFtdcParentOrderIndexField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
};

///ĸ���㷨������Ϣ����
struct CFocusFtdcParentOrderStaticParamField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///����->���� 1--5
	TFocusFtdcNumberType	style;
	///����г�ռ�� TWAP/VWAP (0, 0.5]
	TFocusFtdcRatioType	maxVolumeP;
	///��С�ҵ�����Ĭ��Ϊ0
	TFocusFtdcVolumeType	minDisplaySize;
	///���ҵ�������һ��λ����Ĭ��Ϊ0
	TFocusFtdcVolumeType	displaySize;
	///����ͳ�ƿھ���Ĭ��Ϊ�޼��ڡ��޼��� - 0�� ȫ�г� - 1
	TFocusFtdcVolumeType	countVolInLimitPx;
	///����ʱ�������ȡ�true - 1, false - 0
	TFocusFtdcVolumeType	resetVolOnAmend;
	///�۸����ƣ�Ĭ��Ϊ0
	TFocusFtdcPriceType	limitPrice;
	///����޼ۻ�׼ 
	TFocusFtdcVolumeType	relativePriceLimitBase;
	///����޼�ƫ�Ƶ�λ ö���� 
	TFocusFtdcVolumeType	relativePriceLimitType;
	///����޼�ƫ����  double
	TFocusFtdcPriceTickType	relativePriceLimitOffset;
	///�Ƿ���۲Ĭ�Ͻ��۲� 0��������1 ��
	TFocusFtdcVolumeType	stepSpread;
	///�ǵ�ͣ�������ǵ�ͣʱ����ͣ�����٣�0��û������1�Ǽ��٣�2����ͣ
	TFocusFtdcVolumeType	optOnExtreme;
};

///�����˻���ϵ
struct CFocusFtdcFuSkAccountRelationField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�ֻ�Ͷ���߱��
	TFocusFtdcInvestorIDType	StockInvestorID;
	///�ڻ�Ͷ���߱��
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///�ڻ��ʽ�����
	TFocusFtdcPasswordType	FuturePasswd;
};

///��������¼��
struct CFocusFtdcBatchInputOrderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�����û����ر�����
	TFocusFtdcBatchUserOrderLocalIDType	UserOrderLocalID;
	///�����û��Զ�����
	TFocusFtdcBatchCustomType	UserCustom;
	///��������������
	TFocusFtdcBatchExchangeIDType	ExchangeID;
	///������Լ����
	TFocusFtdcBatchInstrumentIDType	InstrumentID;
	///������������
	TFocusFtdcBatchDirectionType	Direction;
	///������ƽ��־
	TFocusFtdcBatchOffsetFlagType	OffsetFlag;
	///�����۸�
	TFocusFtdcBatchPriceType	LimitPrice;
	///��������
	TFocusFtdcBatchVolumeType	Volume;
};

///������������
struct CFocusFtdcBatchOrderActionField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�����û����ر�����
	TFocusFtdcBatchUserOrderLocalIDType	UserOrderLocalID;
	///�����û��Զ�����
	TFocusFtdcBatchCustomType	UserCustom;
	///��������������
	TFocusFtdcBatchExchangeIDType	ExchangeID;
	///�����������(768)
	TFocusFtdcBatchOrderSysIDType	OrderSysID;
	///������Լ����
	TFocusFtdcBatchInstrumentIDType	InstrumentID;
	///�������γ��������ı��ر��
	TFocusFtdcBatchUserOrderLocalIDType	UserOrderActionLocalID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
};

///Ͷ�����˻�ϯλ������Ϣ
struct CFocusFtdcUserInvestorSeatBaseField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///�ɲ���Ա����
	TFocusFtdcPasswordType	OldUserPassword;
	///�²���Ա����
	TFocusFtdcPasswordType	NewUserPassword;
	///ϯλ����
	TFocusFtdcSeatIDType	SeatID;
	///��ϯλ����
	TFocusFtdcPasswordType	OldSeatPassword;
	///��ϯλ����
	TFocusFtdcPasswordType	NewSeatPassword;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���ʽ��˺�����
	TFocusFtdcPasswordType	OldInvestorPasswd;
	///���ʽ��˺�����
	TFocusFtdcPasswordType	NewInvestorPasswd;
};

///�ڻ����������㷨���׶�����ֵ
struct CFocusFtdcParentOrderDetialIndexField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
};

///δ���ĸ����Ϣ
struct CFocusFtdcUnFinshPutureOrderField
{
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����ID��
	TFocusFtdcStrategyIDType	StrategyID;
	///Ŀ�꾻�ֲ���
	TFocusFtdcVolumeType	TargetNetPosition;
	///ϵͳĸ���������(ĸ��ID,����,�ӵ�����)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
};



#endif
