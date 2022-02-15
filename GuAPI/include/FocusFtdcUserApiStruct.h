/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company 山西证券股份有限公司  金融衍生产品部
///@author 顾浩
///@file FocusFtdcUserApiStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(Focus_FTDCSTRUCT_H)
#define Focus_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FocusFtdcUserApiDataType.h"

///响应信息
struct CFocusFtdcRspInfoField
{
	///错误代码
	TFocusFtdcErrorIDType	ErrorID;
	///错误信息
	TFocusFtdcErrorMsgType	ErrorMsg;
};

///系统用户登录请求
struct CFocusFtdcReqUserLoginField
{
	///交易日
	TFocusFtdcDateType	TradingDay;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///密码
	TFocusFtdcPasswordType	Password;
	///用户端产品信息
	TFocusFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TFocusFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TFocusFtdcProtocolInfoType	ProtocolInfo;
	///IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///Mac地址
	TFocusFtdcMacAddressType	MacAddress;
	///数据中心代码
	TFocusFtdcDataCenterIDType	DataCenterID;
	///动态密码
	TFocusFtdcPasswordType	OneTimePassword;
	///终端IP地址
	TFocusFtdcIPAddressType	ClientIPAddress;
	///授权编码
	TFocusFtdcAuthCodeType	AuthCode;
};

///系统用户登录应答
struct CFocusFtdcRspUserLoginField
{
	///交易日
	TFocusFtdcDateType	TradingDay;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///登录成功时间
	TFocusFtdcTimeType	LoginTime;
	///用户最大本地报单号
	TFocusFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///交易系统名称
	TFocusFtdcTradingSystemNameType	TradingSystemName;
	///数据中心代码
	TFocusFtdcDataCenterIDType	DataCenterID;
	///会员私有流当前长度
	TFocusFtdcSequenceNoType	PrivateFlowSize;
	///交易员私有流当前长度
	TFocusFtdcSequenceNoType	UserFlowSize;
	///登录附加信息
	TFocusFtdcLoginInfoType	LoginInfo;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
};

///用户登出请求
struct CFocusFtdcReqUserLogoutField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
};

///用户登出请求
struct CFocusFtdcRspUserLogoutField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
};

///强制用户退出
struct CFocusFtdcForceUserExitField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
};

///用户口令修改
struct CFocusFtdcUserPasswordUpdateField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///旧密码
	TFocusFtdcPasswordType	OldPassword;
	///新密码
	TFocusFtdcPasswordType	NewPassword;
};

///输入报单
struct CFocusFtdcInputOrderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///股票委托批号(仅批量委托有效)
	TFocusFtdcOrderSysIDType	BatchNum;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///报单类型
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///有效期类型
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TFocusFtdcDateType	GTDDate;
	///成交量类型
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TFocusFtdcVolumeType	MinVolume;
	///止损价
	TFocusFtdcPriceType	StopPrice;
	///强平原因
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TFocusFtdcBoolType	IsAutoSuspend;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TFocusFtdcBusinessTypeType	BusinessType;
};

///报单操作
struct CFocusFtdcOrderActionField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///股票委托批号(仅批量委托有效)
	TFocusFtdcOrderSysIDType	BatchNum;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///本次撤单操作的本地编号
	TFocusFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///报单操作标志
	TFocusFtdcActionFlagType	ActionFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量变化
	TFocusFtdcVolumeType	VolumeChange;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
};

///内存表导出
struct CFocusFtdcMemDBField
{
	///内存表名
	TFocusFtdcMemTableNameType	MemTableName;
};

///投资者资金帐户出入金请求
struct CFocusFtdcReqAccountDepositField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///资金流水号
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///金额
	TFocusFtdcMoneyType	Amount;
	///出入金方向
	TFocusFtdcAccountDirectionType	AmountDirection;
	///出入金日期
	TFocusFtdcDateType	Date;
	///出入金时间
	TFocusFtdcTimeType	Time;
	///出入金备注
	TFocusFtdcDepositNoteType	Note;
	///是否成功
	TFocusFtdcBoolType	isSuccess;
	///用户代码
	TFocusFtdcUserIDType	UserID;
};

///投资者资金帐户出入金应答
struct CFocusFtdcRspAccountDepositField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///资金流水号
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///金额
	TFocusFtdcMoneyType	Amount;
	///出入金方向
	TFocusFtdcAccountDirectionType	AmountDirection;
	///可用资金
	TFocusFtdcMoneyType	Available;
	///结算准备金
	TFocusFtdcMoneyType	Balance;
	///用户代码
	TFocusFtdcUserIDType	UserID;
};

///实时上场
struct CFocusFtdcTBCommandField
{
	///DB命令序号
	TFocusFtdcCommandNoType	CommandNo;
	///操作日期
	TFocusFtdcDateType	CommandDate;
	///操作时间
	TFocusFtdcTimeType	CommandTime;
	///DB命令类型
	TFocusFtdcCommandTypeType	CommandType;
	///字段名
	TFocusFtdcFieldNameType	FieldName;
	///字段内容
	TFocusFtdcFieldContentType	FieldContent;
};

///出入金结果
struct CFocusFtdcInvestorAccountDepositResField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///资金流水号
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///金额
	TFocusFtdcMoneyType	Amount;
	///出入金方向
	TFocusFtdcAccountDirectionType	AmountDirection;
	///可用资金
	TFocusFtdcMoneyType	Available;
	///结算准备金
	TFocusFtdcMoneyType	Balance;
	///用户代码
	TFocusFtdcUserIDType	UserID;
};

///合约状态
struct CFocusFtdcInstrumentStatusField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///品种代码
	TFocusFtdcProductIDType	ProductID;
	///品种名称
	TFocusFtdcProductNameType	ProductName;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TFocusFtdcYearType	DeliveryYear;
	///交割月
	TFocusFtdcMonthType	DeliveryMonth;
	///限价单最大下单量
	TFocusFtdcLargeVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TFocusFtdcLargeVolumeType	MinLimitOrderVolume;
	///市价单最大下单量
	TFocusFtdcLargeVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TFocusFtdcLargeVolumeType	MinMarketOrderVolume;
	///股票每次最少买入量
	TFocusFtdcLargeVolumeType	MinStkBuyQty;
	///股票每次最少卖出量
	TFocusFtdcLargeVolumeType	MinStkSellQty;
	///数量乘数
	TFocusFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TFocusFtdcPriceTickType	PriceTick;
	///币种
	TFocusFtdcCurrencyType	Currency;
	///多头限仓
	TFocusFtdcLargeVolumeType	LongPosLimit;
	///空头限仓
	TFocusFtdcLargeVolumeType	ShortPosLimit;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///合约交易状态
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///创建日
	TFocusFtdcDateType	CreateDate;
	///上市日
	TFocusFtdcDateType	OpenDate;
	///到期日
	TFocusFtdcDateType	ExpireDate;
	///开始交割日
	TFocusFtdcDateType	StartDelivDate;
	///最后交割日
	TFocusFtdcDateType	EndDelivDate;
	///挂牌基准价
	TFocusFtdcPriceType	BasisPrice;
	///当前是否交易
	TFocusFtdcBoolType	IsTrading;
	///基础商品代码
	TFocusFtdcInstrumentIDType	UnderlyingInstrID;
	///基础商品乘数
	TFocusFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///持仓类型
	TFocusFtdcPositionTypeType	PositionType;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///期权类型
	TFocusFtdcOptionsTypeType	OptionsType;
	///汇率
	TFocusFtdcRatioType	ExchangeRate;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///产品类型
	TFocusFtdcProductClassType	ProductClass;
	///期权行权方式
	TFocusFtdcOptionsModeType	OptionsMode;
	///保证金算法类型
	TFocusFtdcMarginCombTypeType	MarginCombType;
};

///审批模式设置请求
struct CFocusFtdcAdviceRunModeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///自动或者手动
	TFocusFtdcAdviceRunModeType	RunMode;
};

///订阅合约状态
struct CFocusFtdcSubInstrumentStatusField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///进入本状态时间
	TFocusFtdcTimeType	EnterTime;
	///进入本状态原因
	TFocusFtdcEnterReasonType	EnterReason;
};

///行情基础属性
struct CFocusFtdcMarketDataBaseField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TFocusFtdcPriceType	PreClosePrice;
	///昨持仓量
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TFocusFtdcRatioType	PreDelta;
	///证券交易状态
	TFocusFtdcStkOrderStatusType	StkOrderStatus;
};

///行情静态属性
struct CFocusFtdcMarketDataStaticField
{
	///今开盘
	TFocusFtdcPriceType	OpenPrice;
	///最高价
	TFocusFtdcPriceType	HighestPrice;
	///最低价
	TFocusFtdcPriceType	LowestPrice;
	///今收盘
	TFocusFtdcPriceType	ClosePrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///今结算
	TFocusFtdcPriceType	SettlementPrice;
	///今虚实度
	TFocusFtdcRatioType	CurrDelta;
};

///行情最新成交属性
struct CFocusFtdcMarketDataLastMatchField
{
	///最新价
	TFocusFtdcPriceType	LastPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///成交金额
	TFocusFtdcMoneyType	Turnover;
	///持仓量
	TFocusFtdcLargeVolumeType	OpenInterest;
};

///行情最优价属性
struct CFocusFtdcMarketDataBestPriceField
{
	///申买价一
	TFocusFtdcPriceType	BidPrice1;
	///申买量一
	TFocusFtdcVolumeType	BidVolume1;
	///申卖价一
	TFocusFtdcPriceType	AskPrice1;
	///申卖量一
	TFocusFtdcVolumeType	AskVolume1;
};

///行情申买二、三属性
struct CFocusFtdcMarketDataBid23Field
{
	///申买价二
	TFocusFtdcPriceType	BidPrice2;
	///申买量二
	TFocusFtdcVolumeType	BidVolume2;
	///申买价三
	TFocusFtdcPriceType	BidPrice3;
	///申买量三
	TFocusFtdcVolumeType	BidVolume3;
};

///行情申卖二、三属性
struct CFocusFtdcMarketDataAsk23Field
{
	///申卖价二
	TFocusFtdcPriceType	AskPrice2;
	///申卖量二
	TFocusFtdcVolumeType	AskVolume2;
	///申卖价三
	TFocusFtdcPriceType	AskPrice3;
	///申卖量三
	TFocusFtdcVolumeType	AskVolume3;
};

///行情申买四、五属性
struct CFocusFtdcMarketDataBid45Field
{
	///申买价四
	TFocusFtdcPriceType	BidPrice4;
	///申买量四
	TFocusFtdcVolumeType	BidVolume4;
	///申买价五
	TFocusFtdcPriceType	BidPrice5;
	///申买量五
	TFocusFtdcVolumeType	BidVolume5;
};

///行情申卖四、五属性
struct CFocusFtdcMarketDataAsk45Field
{
	///申卖价四
	TFocusFtdcPriceType	AskPrice4;
	///申卖量四
	TFocusFtdcVolumeType	AskVolume4;
	///申卖价五
	TFocusFtdcPriceType	AskPrice5;
	///申卖量五
	TFocusFtdcVolumeType	AskVolume5;
};

///行情更新时间属性
struct CFocusFtdcMarketDataUpdateTimeField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TFocusFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TFocusFtdcMillisecType	UpdateMillisec;
};

///深度行情
struct CFocusFtdcDepthMarketDataField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TFocusFtdcPriceType	PreClosePrice;
	///昨持仓量
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TFocusFtdcRatioType	PreDelta;
	///证券交易状态
	TFocusFtdcStkOrderStatusType	StkOrderStatus;
	///今开盘
	TFocusFtdcPriceType	OpenPrice;
	///最高价
	TFocusFtdcPriceType	HighestPrice;
	///最低价
	TFocusFtdcPriceType	LowestPrice;
	///今收盘
	TFocusFtdcPriceType	ClosePrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///今结算
	TFocusFtdcPriceType	SettlementPrice;
	///今虚实度
	TFocusFtdcRatioType	CurrDelta;
	///最新价
	TFocusFtdcPriceType	LastPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///成交金额
	TFocusFtdcMoneyType	Turnover;
	///持仓量
	TFocusFtdcLargeVolumeType	OpenInterest;
	///申买价一
	TFocusFtdcPriceType	BidPrice1;
	///申买量一
	TFocusFtdcVolumeType	BidVolume1;
	///申卖价一
	TFocusFtdcPriceType	AskPrice1;
	///申卖量一
	TFocusFtdcVolumeType	AskVolume1;
	///申买价二
	TFocusFtdcPriceType	BidPrice2;
	///申买量二
	TFocusFtdcVolumeType	BidVolume2;
	///申买价三
	TFocusFtdcPriceType	BidPrice3;
	///申买量三
	TFocusFtdcVolumeType	BidVolume3;
	///申卖价二
	TFocusFtdcPriceType	AskPrice2;
	///申卖量二
	TFocusFtdcVolumeType	AskVolume2;
	///申卖价三
	TFocusFtdcPriceType	AskPrice3;
	///申卖量三
	TFocusFtdcVolumeType	AskVolume3;
	///申买价四
	TFocusFtdcPriceType	BidPrice4;
	///申买量四
	TFocusFtdcVolumeType	BidVolume4;
	///申买价五
	TFocusFtdcPriceType	BidPrice5;
	///申买量五
	TFocusFtdcVolumeType	BidVolume5;
	///申卖价四
	TFocusFtdcPriceType	AskPrice4;
	///申卖量四
	TFocusFtdcVolumeType	AskVolume4;
	///申卖价五
	TFocusFtdcPriceType	AskPrice5;
	///申卖量五
	TFocusFtdcVolumeType	AskVolume5;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TFocusFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TFocusFtdcMillisecType	UpdateMillisec;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///总卖出数量
	TFocusFtdcVolumeType	VolumeAskLot;
	///总买入数量
	TFocusFtdcVolumeType	VolumeBidLot;
};

///订阅合约的相关信息
struct CFocusFtdcSpecificInstrumentField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///投资者权限
struct CFocusFtdcInvestorRightField
{
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///是否使用净持仓报单,投顾账户有效
	TFocusFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TFocusFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TFocusFtdcTradingRightType	TradingRight;
	///是否检查资金
	TFocusFtdcBoolType	CheckAccount;
	///是否检查持仓
	TFocusFtdcBoolType	CheckPosition;
	///报单是否报警
	TFocusFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TFocusFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TFocusFtdcDistributeTypeType	DistributeType;
};

///交易所代码
struct CFocusFtdcMarketDataExchangeIDField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
};

///共享内存行情查询
struct CFocusFtdcShmDepthMarketDataField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///订阅号
	TFocusFtdcTopicIDType	TopicID;
};

///TOPIC查询
struct CFocusFtdcTopicSearchField
{
	///订阅号
	TFocusFtdcTopicIDType	TopicID;
};

///分价行情
struct CFocusFtdcMBLMarketDataField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///价格
	TFocusFtdcPriceType	Price;
	///数量
	TFocusFtdcVolumeType	Volume;
	///最后修改时间
	TFocusFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TFocusFtdcMillisecType	UpdateMillisec;
};

///套利合约买卖总量
struct CFocusFtdcMarketDataCMBVolumeField
{
	///总卖出数量
	TFocusFtdcVolumeType	VolumeAskLot;
	///总买入数量
	TFocusFtdcVolumeType	VolumeBidLot;
};

///合约状态
struct CFocusFtdcQmdInstrumentStateField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
};

///订阅合约的相关信息
struct CFocusFtdcSubSpecificInstrumentField
{
	///合约代码
	TFocusFtdcSubInstrumentIDType	InstrumentID;
};

///成交
struct CFocusFtdcTradeField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///成交编号
	TFocusFtdcTradeIDType	TradeID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///成交价格
	TFocusFtdcPriceType	TradePrice;
	///成交数量
	TFocusFtdcVolumeType	TradeVolume;
	///成交时间
	TFocusFtdcTimeType	TradeTime;
	///市场代码
	TFocusFtdcMarketIDType	MarketID;
	///成交金额
	TFocusFtdcMoneyType	TradeAmnt;
	///交易类型
	TFocusFtdcTradeTypeType	TradeType;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
};

///报单
struct CFocusFtdcOrderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///股票委托批号(仅批量委托有效)
	TFocusFtdcOrderSysIDType	BatchNum;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///报单类型
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///有效期类型
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TFocusFtdcDateType	GTDDate;
	///成交量类型
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TFocusFtdcVolumeType	MinVolume;
	///止损价
	TFocusFtdcPriceType	StopPrice;
	///强平原因
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TFocusFtdcBoolType	IsAutoSuspend;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TFocusFtdcBusinessTypeType	BusinessType;
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///插入时间
	TFocusFtdcTimeType	InsertTime;
	///报单来源
	TFocusFtdcOrderSourceType	OrderSource;
	///报单状态
	TFocusFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TFocusFtdcTimeType	CancelTime;
	///撤单用户编号
	TFocusFtdcUserIDType	CancelUserID;
	///已经成交数量
	TFocusFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TFocusFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TFocusFtdcVolumeType	VolumeCancled;
	///错误代码
	TFocusFtdcErrorIDType	ErrorID;
	///错误信息
	TFocusFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TFocusFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TFocusFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///请求编号
	TFocusFtdcRequestIDType	RequestID;
	///每手手续费
	TFocusFtdcMoneyType	EachFee;
	///每手保证金
	TFocusFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TFocusFtdcMoneyType	EachPremium;
	///下单IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TFocusFtdcMacAddressType	MacAddress;
	///营业部代码
	TFocusFtdcBranchIDType	BranchID;
	///记录编号
	TFocusFtdcSequenceNoType	RecNum;
};

///数据流回退
struct CFocusFtdcFlowMessageCancelField
{
	///序列系列号
	TFocusFtdcSequenceSeriesType	SequenceSeries;
	///交易日
	TFocusFtdcDateType	TradingDay;
	///数据中心代码
	TFocusFtdcDataCenterIDType	DataCenterID;
	///回退起始序列号
	TFocusFtdcSequenceNoType	StartSequenceNo;
	///回退结束序列号
	TFocusFtdcSequenceNoType	EndSequenceNo;
};

///信息分发
struct CFocusFtdcDisseminationField
{
	///序列系列号
	TFocusFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	TFocusFtdcSequenceNoType	SequenceNo;
};

///警告消息通知
struct CFocusFtdcMessageNotifyField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///修改用户编号
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///累加次数
	TFocusFtdcTotalNumsType	Nums;
	///警告级别
	TFocusFtdcErrorLevelType	WarnLevel;
	///警告编号
	TFocusFtdcErrorIDType	WarnID;
	///警告信息
	TFocusFtdcLargeErrorMsgType	WarnMsg;
	///警告时间
	TFocusFtdcTimeType	WarnTime;
};

///工作流指令通知
struct CFocusFtdcAdviceOrderField
{
	///投顾用户代码
	TFocusFtdcUserIDType	InvestorAdvicer;
	///投资经理
	TFocusFtdcUserIDType	InvestorManager;
	///交易员
	TFocusFtdcUserIDType	UserTrader;
	///冻结数量
	TFocusFtdcVolumeType	VolumeFrozen;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///股票委托批号(仅批量委托有效)
	TFocusFtdcOrderSysIDType	BatchNum;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///报单类型
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///有效期类型
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TFocusFtdcDateType	GTDDate;
	///成交量类型
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TFocusFtdcVolumeType	MinVolume;
	///止损价
	TFocusFtdcPriceType	StopPrice;
	///强平原因
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TFocusFtdcBoolType	IsAutoSuspend;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TFocusFtdcBusinessTypeType	BusinessType;
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///插入时间
	TFocusFtdcTimeType	InsertTime;
	///报单来源
	TFocusFtdcOrderSourceType	OrderSource;
	///报单状态
	TFocusFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TFocusFtdcTimeType	CancelTime;
	///撤单用户编号
	TFocusFtdcUserIDType	CancelUserID;
	///已经成交数量
	TFocusFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TFocusFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TFocusFtdcVolumeType	VolumeCancled;
	///错误代码
	TFocusFtdcErrorIDType	ErrorID;
	///错误信息
	TFocusFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TFocusFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TFocusFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///请求编号
	TFocusFtdcRequestIDType	RequestID;
	///每手手续费
	TFocusFtdcMoneyType	EachFee;
	///每手保证金
	TFocusFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TFocusFtdcMoneyType	EachPremium;
	///下单IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TFocusFtdcMacAddressType	MacAddress;
	///营业部代码
	TFocusFtdcBranchIDType	BranchID;
	///记录编号
	TFocusFtdcSequenceNoType	RecNum;
	///指令单用户信息
	TFocusFtdcAdviceUserInfoType	AdviceUserInfo;
};

///报单查询
struct CFocusFtdcQryOrderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///成交查询
struct CFocusFtdcQryTradeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///成交编号
	TFocusFtdcTradeIDType	TradeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///合约查询
struct CFocusFtdcQryInstrumentField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///合约查询应答
struct CFocusFtdcRspInstrumentField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///品种代码
	TFocusFtdcProductIDType	ProductID;
	///品种名称
	TFocusFtdcProductNameType	ProductName;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TFocusFtdcYearType	DeliveryYear;
	///交割月
	TFocusFtdcMonthType	DeliveryMonth;
	///限价单最大下单量
	TFocusFtdcLargeVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TFocusFtdcLargeVolumeType	MinLimitOrderVolume;
	///市价单最大下单量
	TFocusFtdcLargeVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TFocusFtdcLargeVolumeType	MinMarketOrderVolume;
	///股票每次最少买入量
	TFocusFtdcLargeVolumeType	MinStkBuyQty;
	///股票每次最少卖出量
	TFocusFtdcLargeVolumeType	MinStkSellQty;
	///数量乘数
	TFocusFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TFocusFtdcPriceTickType	PriceTick;
	///币种
	TFocusFtdcCurrencyType	Currency;
	///多头限仓
	TFocusFtdcLargeVolumeType	LongPosLimit;
	///空头限仓
	TFocusFtdcLargeVolumeType	ShortPosLimit;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///合约交易状态
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///创建日
	TFocusFtdcDateType	CreateDate;
	///上市日
	TFocusFtdcDateType	OpenDate;
	///到期日
	TFocusFtdcDateType	ExpireDate;
	///开始交割日
	TFocusFtdcDateType	StartDelivDate;
	///最后交割日
	TFocusFtdcDateType	EndDelivDate;
	///挂牌基准价
	TFocusFtdcPriceType	BasisPrice;
	///当前是否交易
	TFocusFtdcBoolType	IsTrading;
	///基础商品代码
	TFocusFtdcInstrumentIDType	UnderlyingInstrID;
	///基础商品乘数
	TFocusFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///持仓类型
	TFocusFtdcPositionTypeType	PositionType;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///期权类型
	TFocusFtdcOptionsTypeType	OptionsType;
	///汇率
	TFocusFtdcRatioType	ExchangeRate;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///产品类型
	TFocusFtdcProductClassType	ProductClass;
	///期权行权方式
	TFocusFtdcOptionsModeType	OptionsMode;
	///保证金算法类型
	TFocusFtdcMarginCombTypeType	MarginCombType;
};

///投资者资金查询
struct CFocusFtdcQryInvestorAccountField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///投资者资金应答
struct CFocusFtdcRspInvestorAccountField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///资金密码
	TFocusFtdcPasswordType	InvestorPasswd;
	///上次结算准备金
	TFocusFtdcMoneyType	PreBalance;
	///上日可用资金
	TFocusFtdcMoneyType	PreAvailable;
	///入金金额
	TFocusFtdcMoneyType	Deposit;
	///出金金额
	TFocusFtdcMoneyType	Withdraw;
	///占用保证金
	TFocusFtdcMoneyType	Margin;
	///期权权利金收支
	TFocusFtdcMoneyType	Premium;
	///手续费
	TFocusFtdcMoneyType	Fee;
	///冻结的保证金
	TFocusFtdcMoneyType	FrozenMargin;
	///冻结权利金
	TFocusFtdcMoneyType	FrozenPremium;
	///冻结手续费
	TFocusFtdcMoneyType	FrozenFee;
	///平仓盈亏
	TFocusFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TFocusFtdcMoneyType	PositionProfit;
	///可用资金
	TFocusFtdcMoneyType	Available;
	///结算准备金
	TFocusFtdcMoneyType	Balance;
	///多头占用保证金
	TFocusFtdcMoneyType	LongMargin;
	///空头占用保证金
	TFocusFtdcMoneyType	ShortMargin;
	///多头冻结的保证金
	TFocusFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TFocusFtdcMoneyType	ShortFrozenMargin;
	///动态权益
	TFocusFtdcMoneyType	DynamicRights;
	///风险度
	TFocusFtdcRatioType	Risk;
	///其他费用
	TFocusFtdcMoneyType	OtherFee;
	///质押金额
	TFocusFtdcMoneyType	Mortgage;
	///币种
	TFocusFtdcCurrencyType	Currency;
	///可取资金
	TFocusFtdcMoneyType	WithdrawQuota;
	///过户费
	TFocusFtdcMoneyType	TransferFee;
	///冻结的过户费
	TFocusFtdcMoneyType	FrozenTransferFee;
	///印花税
	TFocusFtdcMoneyType	StampTax;
	///冻结的印花税
	TFocusFtdcMoneyType	FrozenStampTax;
};

///可用投资者查询
struct CFocusFtdcQryUserInvestorField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
};

///可用投资者应答
struct CFocusFtdcRspUserInvestorField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///默认用户代码
	TFocusFtdcUserIDType	NextUserID;
	///是否可下单
	TFocusFtdcAdviceUserOrderModeType	OrderMode;
	///自动或者手动
	TFocusFtdcAdviceRunModeType	RunMode;
	///工作流断线处理标示符
	TFocusFtdcAdviceSwitchFlagType	AdviceSwitchFlag;
};

///投资者关系查询
struct CFocusFtdcQryInvestorRelationField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///投资者关系应答
struct CFocusFtdcRspInvestorRelationField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///父投资者编号
	TFocusFtdcInvestorIDType	ParentInvestorID;
};

///交易所查询请求
struct CFocusFtdcQryExchangeField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
};

///交易所查询应答
struct CFocusFtdcRspExchangeField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///交易所名称
	TFocusFtdcExchangeNameType	ExchangeName;
};

///投资者持仓查询请求
struct CFocusFtdcQryInvestorPositionField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///投资者持仓查询应答
struct CFocusFtdcRspInvestorPositionField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///占用保证金
	TFocusFtdcMoneyType	UsedMargin;
	///总持仓量
	TFocusFtdcVolumeType	Position;
	///总持仓成本
	TFocusFtdcPriceType	PositionCost;
	///初始昨持仓量(当日不变)
	TFocusFtdcVolumeType	YdPosition;
	///初始昨日持仓成本(当日不变)
	TFocusFtdcMoneyType	YdPositionCost;
	///冻结的保证金
	TFocusFtdcMoneyType	FrozenMargin;
	///开仓冻结持仓
	TFocusFtdcVolumeType	FrozenPosition;
	///平仓冻结持仓
	TFocusFtdcVolumeType	FrozenClosing;
	///持仓盈亏
	TFocusFtdcMoneyType	PositionProfit;
	///冻结的权利金
	TFocusFtdcMoneyType	FrozenPremium;
	///最后一笔成交编号
	TFocusFtdcTradeIDType	LastTradeID;
	///最后一笔本地报单编号
	TFocusFtdcOrderLocalIDType	LastOrderLocalID;
	///总持仓可平仓数量(包括平仓冻结持仓)
	TFocusFtdcVolumeType	PositionClose;
	///昨持仓可平仓数量(包括平仓冻结持仓)
	TFocusFtdcVolumeType	YdPositionClose;
	///昨持仓平仓冻结持仓
	TFocusFtdcVolumeType	YdFrozenClosing;
	///今日开仓数量(不包括冻结)
	TFocusFtdcVolumeType	OpenVolume;
	///今日平仓数量(包括昨持仓的平仓,不包括冻结)
	TFocusFtdcVolumeType	CloseVolume;
	///平仓盈亏
	TFocusFtdcMoneyType	CloseProfit;
	///申购赎回数量
	TFocusFtdcVolumeType	PurRedVolume;
	///申购赎回冻结数量
	TFocusFtdcVolumeType	FrozenPurRedVolume;
	///今日开仓冻结数量
	TFocusFtdcVolumeType	FrozenOpenVolume;
	///证券最新市值
	TFocusFtdcMoneyType	CurrentStkValue;
	///证券委托单位，0-股，1-手
	TFocusFtdcOrderUnitType	OrderUnit;
};

///用户查询
struct CFocusFtdcQryUserField
{
	///交易用户代码
	TFocusFtdcUserIDType	StartUserID;
	///交易用户代码
	TFocusFtdcUserIDType	EndUserID;
};

///用户
struct CFocusFtdcRspUserField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户登录密码
	TFocusFtdcPasswordType	Password;
	///投资者组编号
	TFocusFtdcInvestorIDType	GroupID;
	///投资者组名
	TFocusFtdcInvestorNameType	GroupName;
	///是否活跃
	TFocusFtdcIsActiveType	IsActive;
	///用户名称
	TFocusFtdcUserNameType	UserName;
	///用户类型
	TFocusFtdcUserTypeType	UserType;
	///营业部
	TFocusFtdcDepartmentType	Department;
	///授权功能集
	TFocusFtdcGrantFuncSetType	GrantFuncSet;
	///最大在线数
	TFocusFtdcNumberType	MaxOnline;
	///IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///是否检查连接产品
	TFocusFtdcBoolType	CheckProductInfo;
	///Mac地址
	TFocusFtdcMacAddressType	MacAddress;
	///是否检查IP和MAC
	TFocusFtdcBoolType	CheckIPMacAddr;
	///错误登陆次数限制
	TFocusFtdcNumberType	LoginErrorLimit;
	///目前错误登陆次数
	TFocusFtdcNumberType	LoginErrorCount;
};

///投资者手续费率查询
struct CFocusFtdcQryInvestorFeeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///投资者手续费率
struct CFocusFtdcRspInvestorFeeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///开仓手续费按比例
	TFocusFtdcRatioType	OpenFeeRate;
	///开仓手续费按手数
	TFocusFtdcRatioType	OpenFeeAmt;
	///平仓手续费按比例
	TFocusFtdcRatioType	OffsetFeeRate;
	///平仓手续费按手数
	TFocusFtdcRatioType	OffsetFeeAmt;
	///平今仓手续费按比例
	TFocusFtdcRatioType	OTFeeRate;
	///平今仓手续费按手数
	TFocusFtdcRatioType	OTFeeAmt;
};

///投资者保证金率查询
struct CFocusFtdcQryInvestorMarginField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
};

///投资者保证金率
struct CFocusFtdcRspInvestorMarginField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///多头占用保证金按比例
	TFocusFtdcRatioType	LongMarginRate;
	///多头保证金按手数
	TFocusFtdcRatioType	LongMarginAmt;
	///空头占用保证金按比例
	TFocusFtdcRatioType	ShortMarginRate;
	///空头保证金按手数
	TFocusFtdcRatioType	ShortMarginAmt;
};

///投资者查询
struct CFocusFtdcQryInvestorField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///投资者应答
struct CFocusFtdcRspInvestorField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金密码
	TFocusFtdcPasswordType	InvestorPasswd;
	///投资者名称
	TFocusFtdcInvestorNameType	InvestorName;
	///投资者类型
	TFocusFtdcInvestorTypeType	InvestorType;
	///客户类型
	TFocusFtdcClientTypeType	ClientType;
	///上海股东代码(根网特殊用)
	TFocusFtdcInvestorIDType	SSERegId;
	///深圳股东代码(根网特殊用)
	TFocusFtdcInvestorIDType	SZSERegId;
	///上期所交易编码(根网特殊用)
	TFocusFtdcInvestorIDType	SHFERegId;
	///郑商所交编码(根网特殊用)
	TFocusFtdcInvestorIDType	ZCERegId;
	///大商所编码(根网特殊用)
	TFocusFtdcInvestorIDType	DCERegId;
	///投资者组编号
	TFocusFtdcInvestorIDType	GroupID;
	///投资者组名
	TFocusFtdcInvestorNameType	GroupName;
	///别名
	TFocusFtdcAliasType	Alias;
	///连接类型
	TFocusFtdcLinkTypeType	LinkType;
	///终端信息ID（穿透式监管里需要用到的）
	TFocusFtdcCustomType	F_TerminalId;
	///资金账户编号
	TFocusFtdcInvestorIDType	ParentInvestorID;
	///登录次数
	TFocusFtdcNumberType	LoginStatus;
	///是否使用净持仓报单,投顾账户有效
	TFocusFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TFocusFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TFocusFtdcTradingRightType	TradingRight;
	///是否检查资金
	TFocusFtdcBoolType	CheckAccount;
	///是否检查持仓
	TFocusFtdcBoolType	CheckPosition;
	///报单是否报警
	TFocusFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TFocusFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TFocusFtdcDistributeTypeType	DistributeType;
};

///账号风险状况查询
struct CFocusFtdcQryAccountRiskField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///账号风险状况应答
struct CFocusFtdcRspAccountRiskField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///设置准备金
	TFocusFtdcMoneyType	SetBalance;
	///开仓红线
	TFocusFtdcMoneyType	OpenAvailable;
	///平仓红线
	TFocusFtdcMoneyType	OffsetAvailable;
	///账户状态
	TFocusFtdcAccountStatusType	AccountStatus;
	///动态权益
	TFocusFtdcMoneyType	DynamicRights;
	///账户权限
	TFocusFtdcTradingRightType	TradingRight;
};

///交易用户会话查询
struct CFocusFtdcQryUserSessionField
{
	///交易用户代码
	TFocusFtdcUserIDType	StartUserID;
	///交易用户代码
	TFocusFtdcUserIDType	EndUserID;
};

///交易用户会话应答
struct CFocusFtdcRspUserSessionField
{
	///经纪公司代码
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///交易用户类型
	TFocusFtdcUserTypeType	UserType;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///登录时间
	TFocusFtdcTimeType	LoginTime;
	///IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///Mac地址
	TFocusFtdcMacAddressType	MacAddress;
	///用户端产品信息
	TFocusFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TFocusFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TFocusFtdcProtocolInfoType	ProtocolInfo;
};

///行情查询
struct CFocusFtdcQryMarketDataField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///行情应答
struct CFocusFtdcRspMarketDataField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TFocusFtdcPriceType	PreClosePrice;
	///昨持仓量
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TFocusFtdcRatioType	PreDelta;
	///证券交易状态
	TFocusFtdcStkOrderStatusType	StkOrderStatus;
	///今开盘
	TFocusFtdcPriceType	OpenPrice;
	///最高价
	TFocusFtdcPriceType	HighestPrice;
	///最低价
	TFocusFtdcPriceType	LowestPrice;
	///今收盘
	TFocusFtdcPriceType	ClosePrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///今结算
	TFocusFtdcPriceType	SettlementPrice;
	///今虚实度
	TFocusFtdcRatioType	CurrDelta;
	///最新价
	TFocusFtdcPriceType	LastPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///成交金额
	TFocusFtdcMoneyType	Turnover;
	///持仓量
	TFocusFtdcLargeVolumeType	OpenInterest;
	///申买价一
	TFocusFtdcPriceType	BidPrice1;
	///申买量一
	TFocusFtdcVolumeType	BidVolume1;
	///申卖价一
	TFocusFtdcPriceType	AskPrice1;
	///申卖量一
	TFocusFtdcVolumeType	AskVolume1;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TFocusFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TFocusFtdcMillisecType	UpdateMillisec;
};

///产品查询
struct CFocusFtdcQryProductField
{
	///产品代码
	TFocusFtdcProductIDType	ProductID;
};

///产品应答
struct CFocusFtdcRspProductField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///投资者发行的产品名称
	TFocusFtdcProductNameType	ProductName;
	///币种
	TFocusFtdcCurrencyType	Currency;
	///汇率
	TFocusFtdcRatioType	ExchangeRate;
	///产品类型
	TFocusFtdcProductClassType	ProductClass;
};

///内部来回消息
struct CFocusFtdcPingPongField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///修改用户编号
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///编号
	TFocusFtdcSequenceNoType	SequenceNo;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
};

///最大可交易数量查询请求
struct CFocusFtdcQryMaxVolumeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
};

///最大可交易数量查询应答
struct CFocusFtdcRspMaxVolumeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
};

///工作流交易员查询请求
struct CFocusFtdcQryAdviceTraderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///登录经纪公司编号
	TFocusFtdcBrokerIDType	LogBrokerID;
	///登录用户代码
	TFocusFtdcUserIDType	LogUserID;
};

///工作流交易员查询应答
struct CFocusFtdcRspAdviceTraderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///关联用户代码
	TFocusFtdcUserIDType	RelationUserID;
	///关联用户名称
	TFocusFtdcUserNameType	RelationUserName;
};

///组合持仓明细查询请求
struct CFocusFtdcQryCmbPositionDetailField
{
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///组合持仓明细查询应答
struct CFocusFtdcRspCmbPositionDetailField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///单腿合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///单腿合约代码
	TFocusFtdcInstrumentIDType	CmbInstrumentID;
	///成交编号
	TFocusFtdcTradeIDType	TradeID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///持仓量
	TFocusFtdcVolumeType	Position;
	///单腿编号
	TFocusFtdcNumberType	LegQty;
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
};

///投资者结算结果查询请求
struct CFocusFtdcQrySettlementInfoField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
};

///投资者结算结果查询应答
struct CFocusFtdcRspSettlementInfoField
{
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///序号
	TFocusFtdcSequenceNoType	SequenceNo;
	///消息正文
	TFocusFtdcContentType	Content;
};

///查询结果集分页
struct CFocusFtdcQryResultPageField
{
	///结果集编号
	TFocusFtdcSessionIDType	ResultID;
	///总记录数
	TFocusFtdcNumberType	Count;
	///总页数
	TFocusFtdcNumberType	Pages;
	///剩余页数
	TFocusFtdcNumberType	Remain;
};

///查询持仓明细请求
struct CFocusFtdcQryPositionDetailField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///单腿合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///查询持仓明细应答
struct CFocusFtdcRspPositionDetailField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开仓日期
	TFocusFtdcDateType	OpenDate;
	///成交编号
	TFocusFtdcTradeIDType	TradeID;
	///数量
	TFocusFtdcVolumeType	Volume;
	///开仓价
	TFocusFtdcMoneyType	OpenPrice;
	///交易日
	TFocusFtdcDateType	TradingDay;
	///交易类型
	TFocusFtdcTradeTypeType	TradeType;
	///组合合约代码
	TFocusFtdcInstrumentIDType	CombInstrumentID;
	///逐日盯市平仓盈亏
	TFocusFtdcMoneyType	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	TFocusFtdcMoneyType	CloseProfitByTrade;
	///逐日盯市持仓盈亏
	TFocusFtdcMoneyType	PositionProfitByDate;
	///逐笔对冲持仓盈亏
	TFocusFtdcMoneyType	PositionProfitByTrade;
	///投资者保证金
	TFocusFtdcMoneyType	Margin;
	///交易所保证金
	TFocusFtdcMoneyType	ExchMargin;
	///保证金率
	TFocusFtdcMoneyType	MarginRateByMoney;
	///保证金率(按手数)
	TFocusFtdcMoneyType	MarginRateByVolume;
	///昨结算价
	TFocusFtdcPriceType	LastSettlementPrice;
	///结算价
	TFocusFtdcPriceType	SettlementPrice;
	///平仓量
	TFocusFtdcVolumeType	CloseVolume;
	///平仓金额
	TFocusFtdcMoneyType	CloseAmount;
};

///理论价行情
struct CFocusFtdcTheoryPriceDataField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///理论价
	TFocusFtdcPriceType	TheoryPrice;
	///理论波动率
	TFocusFtdcVolatilityType	TheoryVol;
	///标的最新价
	TFocusFtdcPriceType	UnderlyingLastPrice;
	///标的买1价
	TFocusFtdcPriceType	UnderlyingBidPrice1;
	///标的卖1价
	TFocusFtdcPriceType	UnderlyingAskPrice1;
	///剩余时间
	TFocusFtdcTimeValueType	RemainDay;
};

///期权指标行情
struct CFocusFtdcOptionIndexDataField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///合约代码
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
	///买1价波动率
	TFocusFtdcVolatilityType	BidVol;
	///卖1价波动率
	TFocusFtdcVolatilityType	AskVol;
	///中间价波动率
	TFocusFtdcVolatilityType	MidVol;
	///最新价波动率
	TFocusFtdcVolatilityType	LastVol;
	///最新价
	TFocusFtdcPriceType	LastPrice;
	///买1价
	TFocusFtdcPriceType	BidPrice1;
	///卖1价
	TFocusFtdcPriceType	AskPrice1;
	///理论波动率
	TFocusFtdcVolatilityType	TheoryVol;
	///标的最新价
	TFocusFtdcPriceType	UnderlyingLastPrice;
	///标的买1价
	TFocusFtdcPriceType	UnderlyingBidPrice1;
	///标的卖1价
	TFocusFtdcPriceType	UnderlyingAskPrice1;
	///剩余天数
	TFocusFtdcTimeValueType	RemainDay;
	///是否是客户端设置的波动率
	TFocusFtdcYesOrNoType	IsManalSetVol;
	///AtmVol波动率
	TFocusFtdcVolatilityType	AtmVol;
};

///定价参数
struct CFocusFtdcPricingParamField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///标的代码
	TFocusFtdcInstrumentIDType	UnderlyingId;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///一级价格
	TFocusFtdcPriceTypeType	PriceLevel1;
	///二级价格
	TFocusFtdcPriceTypeType	PriceLevel2;
	///三级价格
	TFocusFtdcPriceTypeType	PriceLevel3;
	///计算日历
	TFocusFtdcDateTypeType	CalcDayType;
	///年总天数
	TFocusFtdcVolumeType	YearTotalDay;
	///计时方式
	TFocusFtdcTimingPatternType	CalcTimeType;
	///无风险利率
	TFocusFtdcRatioType	RiskFreeRate;
	///股息率
	TFocusFtdcRatioType	Dividend;
	///定价模型
	TFocusFtdcPricingMethodType	PricingEngine;
	///行权方式
	TFocusFtdcExerciseTypeType	ExerciseType;
	///波动率精度
	TFocusFtdcToleranceType	VolTolerance;
	///波动率类型
	TFocusFtdcVolTypeType	VolType;
};

///期权理论波动率
struct CFocusFtdcOptionTheoryVolField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///理论波动率
	TFocusFtdcVolatilityType	TheoryVol;
};

///定价基本参数
struct CFocusFtdcBasePricingParamField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///计算目标
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///行权方式
	TFocusFtdcExerciseTypeType	ExerciseType;
	///期权类型
	TFocusFtdcOptionsTypeType	OptionsType;
	///标的价格
	TFocusFtdcPriceType	UnderlyingPrice;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///无风险利率
	TFocusFtdcRatioType	RiskFreeRate;
	///股息率
	TFocusFtdcRatioType	Dividend;
	///剩余天数
	TFocusFtdcTimeValueType	RemainDay;
	///交易日
	TFocusFtdcDateType	TradingDate;
	///到期日
	TFocusFtdcDateType	ExpireDate;
	///波动率
	TFocusFtdcVolatilityType	Vol;
	///定价模型
	TFocusFtdcPricingMethodType	PricingModel;
	///期权价值
	TFocusFtdcPriceType	OptionPrice;
	///重置频率
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

///双障碍期权定价参数
struct CFocusFtdcDoubleBarrierPricingParamField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///计算目标
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///行权方式
	TFocusFtdcExerciseTypeType	ExerciseType;
	///期权类型
	TFocusFtdcOptionsTypeType	OptionsType;
	///标的价格
	TFocusFtdcPriceType	UnderlyingPrice;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///无风险利率
	TFocusFtdcRatioType	RiskFreeRate;
	///股息率
	TFocusFtdcRatioType	Dividend;
	///剩余天数
	TFocusFtdcTimeValueType	RemainDay;
	///交易日
	TFocusFtdcDateType	TradingDate;
	///到期日
	TFocusFtdcDateType	ExpireDate;
	///波动率
	TFocusFtdcVolatilityType	Vol;
	///定价模型
	TFocusFtdcPricingMethodType	PricingModel;
	///期权价值
	TFocusFtdcPriceType	OptionPrice;
	///重置频率
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
	///障碍类型
	TFocusFtdcBarrierTypeType	BarrierType;
	///障碍下沿值
	TFocusFtdcRatioType	LowerBarrierRate;
	///障碍上沿值
	TFocusFtdcRatioType	UpperBarrierRate;
};

///波动率拟合参数
struct CFocusFtdcVolatilityFittingField
{
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///剩余天数
	TFocusFtdcTimeValueType	RemainDay;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///波动率
	TFocusFtdcVolatilityType	Vol;
};

///Wing模型参数
struct CFocusFtdcWingModelParamField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///品种编号
	TFocusFtdcProductIDType	ProductID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///拟合时选用的模型
	TFocusFtdcFitModelTypeType	FitModel;
	///wing模型参数类型
	TFocusFtdcWingParamTypeType	WingParamType;
	///交易日
	TFocusFtdcDateType	TradingDay;
	///插入时间
	TFocusFtdcTimeType	InsertTime;
	///ATM
	TFocusFtdcPriceType	Atm;
	///Days
	TFocusFtdcPriceType	Days;
	///参考价格
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

///Wing模型参数查询请求
struct CFocusFtdcQryWingModelParamField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///wing模型参数类型
	TFocusFtdcWingParamTypeType	WingParamType;
	///拟合时选用的模型
	TFocusFtdcFitModelTypeType	FitModel;
};

///做市报价累计价格
struct CFocusFtdcQuoteTotalTradePriceField
{
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///当前卖成交量，交易员设置，不管开平
	TFocusFtdcVolumeType	AskTradeVolume;
	///当前买成交量，交易员设置，不管开平
	TFocusFtdcVolumeType	BidTradeVolume;
	///当前报价实际报买价
	TFocusFtdcPriceType	BidQuotePrice;
	///当前报价实际报买量
	TFocusFtdcVolumeType	BidQuoteAmount;
	///当前报价实际报卖价
	TFocusFtdcPriceType	AskQuotePrice;
	///当前报价实际报卖量
	TFocusFtdcVolumeType	AskQuoteAmount;
	///今日实际回应询价数量
	TFocusFtdcVolumeType	ForQuoteSendAmount;
	///今日收到询价请求数量
	TFocusFtdcVolumeType	ForQuoteTotalAmount;
	///当前询价回应实际报买价
	TFocusFtdcPriceType	BidForQuotePrice;
	///当前询价回应实际报买量
	TFocusFtdcVolumeType	BidForQuoteAmount;
	///当前询价回应实际报卖价
	TFocusFtdcPriceType	AskForQuotePrice;
	///当前询价回应实际报卖量
	TFocusFtdcVolumeType	AskForQuoteAmount;
	///移动报价方向
	TFocusFtdcFowardDirectionType	FowardDirection;
};

///做市策略
struct CFocusFtdcMarkerStrategyField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///自动报价
	TFocusFtdcIsActiveType	AutoOffer;
	///自动回应询价
	TFocusFtdcIsActiveType	AutoRespAsking;
	///报价报买量
	TFocusFtdcVolumeType	BidAmount;
	///报价报卖量
	TFocusFtdcVolumeType	AskAmount;
	///询价报买量
	TFocusFtdcVolumeType	ForQuoteBidAmount;
	///询价报卖量
	TFocusFtdcVolumeType	ForQuoteAskAmount;
	///买量上限
	TFocusFtdcVolumeType	BidMax;
	///卖量上限
	TFocusFtdcVolumeType	AskMax;
	///价差类型
	TFocusFtdcSpreadTypeType	SpreadType;
	///报价价差宽度
	TFocusFtdcMoneyType	QuotePriceWidth;
	///报价价差比
	TFocusFtdcLargeVolumeType	QuoteWidthRatio;
	///询价价差宽度
	TFocusFtdcMoneyType	ForQuotePriceWidth;
	///询价价差比
	TFocusFtdcLargeVolumeType	ForQuoteWidthRatio;
	///是否有效
	TFocusFtdcIsActiveType	IsActive;
	///备注
	TFocusFtdcRemarkType	Remark;
	///报价方式
	TFocusFtdcQuoteRightPriceTypeType	OfferType;
	///中心价容忍度
	TFocusFtdcVolumeType	TOL_TICK;
	///询价回应报价方式
	TFocusFtdcQuoteRightPriceTypeType	ForQuoteOfferType;
	///报价宽度单位
	TFocusFtdcQuoteWidthTypeType	QuoteWidthType;
	///询价回应宽度单位
	TFocusFtdcQuoteWidthTypeType	ForQuoteWidthType;
	///合约单边市停止报价
	TFocusFtdcYesOrNoType	InstrumentOneSide;
	///标的单边市停止报价
	TFocusFtdcYesOrNoType	UnderlyingOneSide;
	///合约低于协定价停止报价
	TFocusFtdcMoneyType	MinPrice;
	///报价价宽模板
	TFocusFtdcQuoteStepType	QuoteStepID;
	///报价Delta价宽模板
	TFocusFtdcQuoteStepType	QuoteDeltaStepID;
	///报价Vega价宽模板
	TFocusFtdcQuoteStepType	QuoteVegaStepID;
	///询价回应价宽模板
	TFocusFtdcQuoteStepType	ForQuoteStepID;
	///询价回应Delta价宽模板
	TFocusFtdcQuoteStepType	ForQuoteDeltaStepID;
	///询价回应Vega价宽模板
	TFocusFtdcQuoteStepType	ForQuoteVegaStepID;
};

///用户开关
struct CFocusFtdcUserSwitchField
{
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///交易员总开关
	TFocusFtdcSwitchFlagType	WholeSwitch;
	///自动报价
	TFocusFtdcSwitchFlagType	WholeOffer;
	///自动回应询价
	TFocusFtdcSwitchFlagType	WholeRespAsking;
	///自动对冲
	TFocusFtdcSwitchFlagType	WholeHedge;
};

///做市对冲
struct CFocusFtdcMarkerHedgeField
{
	///对冲标的
	TFocusFtdcInstrumentIDType	UnderlyingId;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///期权系列
	TFocusFtdcContentType	OptionSeriesId;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///自动对冲
	TFocusFtdcIsActiveType	AutoHedge;
	///对冲报价类型
	TFocusFtdcHedgePriceTypeType	HedgePriceType;
	///对冲算法
	TFocusFtdcHdegeTypeType	HdegeType;
	///对冲周期
	TFocusFtdcVolumeType	HedgePeriod;
	///Delta上限
	TFocusFtdcPriceType	DeltaMax;
	///Delta下限
	TFocusFtdcPriceType	DelatMin;
	///最后对冲时间
	TFocusFtdcTimeType	LastHedgeTime;
	///默认下单时的冲击成本
	TFocusFtdcVolumeType	OrderPriceSlip;
};

///拟合参数
struct CFocusFtdcFittingParamField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///拟合模型
	TFocusFtdcFitModelTypeType	FitModel;
	///CallBid开关
	TFocusFtdcSwitchFlagType	CallBidFlag;
	///CallAsk开关
	TFocusFtdcSwitchFlagType	CallAskFlag;
	///PutBid开关
	TFocusFtdcSwitchFlagType	PutBidFlag;
	///PutAsk开关
	TFocusFtdcSwitchFlagType	PutAskFlag;
	///CallMid开关
	TFocusFtdcSwitchFlagType	CallMidFlag;
	///PutMid开关
	TFocusFtdcSwitchFlagType	PutMidFlag;
	///OTM开关
	TFocusFtdcSwitchFlagType	OTMFlag;
	///自动剔除异常值
	TFocusFtdcSwitchFlagType	AutoRemoveOutlier;
	///有效区间上限
	TFocusFtdcValidIntervalTypeType	ValidIntervalMax;
	///有效区间下限
	TFocusFtdcValidIntervalTypeType	ValidIntervalMin;
	///自动拟合
	TFocusFtdcSwitchFlagType	AutoFit;
	///自动拟合间隔时间
	TFocusFtdcNumberType	AUTO_FIT_TIME;
};

///拟合参数查询请求
struct CFocusFtdcQryFittingParamField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
};

///查询价格参数设置
struct CFocusFtdcQryPricingParamField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
};

///查询期权理论波动率设置
struct CFocusFtdcQryOptionTheoryVolField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///输入报价
struct CFocusFtdcInputQuoteField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///本地参考编号
	TFocusFtdcQuoteRefType	QuoteRef;
	///本地报价编号
	TFocusFtdcOrderLocalIDType	QuoteLocalID;
	///买本地参考报价编号
	TFocusFtdcQuoteRefType	AskOrderRef;
	///卖本地参考报价编号
	TFocusFtdcQuoteRefType	BidOrderRef;
	///报价编号
	TFocusFtdcQuoteSysIDType	QuoteSysID;
	///应价编号
	TFocusFtdcQuoteSysIDType	ForQuoteSysID;
	///买入数量
	TFocusFtdcVolumeType	BidVolume;
	///卖出数量
	TFocusFtdcVolumeType	AskVolume;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///买方组合开平标志
	TFocusFtdcOffsetFlagType	BidOffsetFlag;
	///买方组合套保标志
	TFocusFtdcHedgeFlagType	BidHedgeFlag;
	///买方价格
	TFocusFtdcPriceType	BidPrice;
	///卖方组合开平标志
	TFocusFtdcOffsetFlagType	AskOffsetFlag;
	///卖方组合套保标志
	TFocusFtdcHedgeFlagType	AskHedgeFlag;
	///卖方价格
	TFocusFtdcPriceType	AskPrice;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///是否自动交易
	TFocusFtdcAutoTradeType	IsAuto;
	///交易API中的序号
	TFocusFtdcNumberType	APIID;
	///备注
	TFocusFtdcRemarkType	Remark;
};

///报价操作
struct CFocusFtdcQuoteActionField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///报价编号
	TFocusFtdcQuoteSysIDType	QuoteSysID;
	///本地报价编号
	TFocusFtdcOrderLocalIDType	QuoteLocalID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///报单操作标志
	TFocusFtdcActionFlagType	ActionFlag;
	///会员代码
	TFocusFtdcParticipantIDType	ParticipantID;
	///客户代码
	TFocusFtdcClientIDType	ClientID;
	///操作本地编号
	TFocusFtdcOrderLocalIDType	ActionLocalID;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易API中的序号
	TFocusFtdcNumberType	APIID;
};

///报价查询
struct CFocusFtdcQryQuoteField
{
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///系统报价编号
	TFocusFtdcQuoteSysIDType	QuoteSysID;
	///客户代码
	TFocusFtdcClientIDType	ClientID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
};

///报价
struct CFocusFtdcQuoteField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///本地参考编号
	TFocusFtdcQuoteRefType	QuoteRef;
	///本地报价编号
	TFocusFtdcOrderLocalIDType	QuoteLocalID;
	///买本地参考报价编号
	TFocusFtdcQuoteRefType	AskOrderRef;
	///卖本地参考报价编号
	TFocusFtdcQuoteRefType	BidOrderRef;
	///报价编号
	TFocusFtdcQuoteSysIDType	QuoteSysID;
	///应价编号
	TFocusFtdcQuoteSysIDType	ForQuoteSysID;
	///买入数量
	TFocusFtdcVolumeType	BidVolume;
	///卖出数量
	TFocusFtdcVolumeType	AskVolume;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///买方组合开平标志
	TFocusFtdcOffsetFlagType	BidOffsetFlag;
	///买方组合套保标志
	TFocusFtdcHedgeFlagType	BidHedgeFlag;
	///买方价格
	TFocusFtdcPriceType	BidPrice;
	///卖方组合开平标志
	TFocusFtdcOffsetFlagType	AskOffsetFlag;
	///卖方组合套保标志
	TFocusFtdcHedgeFlagType	AskHedgeFlag;
	///卖方价格
	TFocusFtdcPriceType	AskPrice;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///是否自动交易
	TFocusFtdcAutoTradeType	IsAuto;
	///交易API中的序号
	TFocusFtdcNumberType	APIID;
	///备注
	TFocusFtdcRemarkType	Remark;
	///插入时间
	TFocusFtdcTimeType	InsertTime;
	///撤销时间
	TFocusFtdcTimeType	CancelTime;
	///成交时间
	TFocusFtdcTimeType	TradeTime;
	///买方报单编号
	TFocusFtdcOrderSysIDType	BidOrderSysID;
	///卖方报单编号
	TFocusFtdcOrderSysIDType	AskOrderSysID;
	///报单状态
	TFocusFtdcQuoteStatusType	QuoteStatus;
	///报单提交状态
	TFocusFtdcQuoteStatusType	OrderSubmitStatus;
};

///询价
struct CFocusFtdcInputReqForQuoteField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///询价编号
	TFocusFtdcQuoteSysIDType	ReqForQuoteID;
	///客户代码
	TFocusFtdcClientIDType	ClientID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///询价时间
	TFocusFtdcTimeType	ReqForQuoteTime;
	///用户本地报单号
	TFocusFtdcOrderSysIDType	ForQuoteLocalID;
};

///错单查询
struct CFocusFtdcQryOrderInsertFailedField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///登录经纪公司编号
	TFocusFtdcBrokerIDType	LogBrokerID;
	///登录用户代码
	TFocusFtdcUserIDType	LogUserID;
};

///错单表
struct CFocusFtdcOrderInsertFailedField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///股票委托批号(仅批量委托有效)
	TFocusFtdcOrderSysIDType	BatchNum;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///报单类型
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///有效期类型
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TFocusFtdcDateType	GTDDate;
	///成交量类型
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TFocusFtdcVolumeType	MinVolume;
	///止损价
	TFocusFtdcPriceType	StopPrice;
	///强平原因
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TFocusFtdcBoolType	IsAutoSuspend;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TFocusFtdcBusinessTypeType	BusinessType;
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///插入时间
	TFocusFtdcTimeType	InsertTime;
	///报单来源
	TFocusFtdcOrderSourceType	OrderSource;
	///报单状态
	TFocusFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TFocusFtdcTimeType	CancelTime;
	///撤单用户编号
	TFocusFtdcUserIDType	CancelUserID;
	///已经成交数量
	TFocusFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TFocusFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TFocusFtdcVolumeType	VolumeCancled;
	///错误代码
	TFocusFtdcErrorIDType	ErrorID;
	///错误信息
	TFocusFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TFocusFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TFocusFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///请求编号
	TFocusFtdcRequestIDType	RequestID;
	///每手手续费
	TFocusFtdcMoneyType	EachFee;
	///每手保证金
	TFocusFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TFocusFtdcMoneyType	EachPremium;
	///下单IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TFocusFtdcMacAddressType	MacAddress;
	///营业部代码
	TFocusFtdcBranchIDType	BranchID;
	///记录编号
	TFocusFtdcSequenceNoType	RecNum;
	///会员编号
	TFocusFtdcParticipantIDType	ParticipantID;
	///客户号
	TFocusFtdcClientIDType	ClientID;
	///下单席位号
	TFocusFtdcSeatIDType	SeatID;
	///本地报单编号
	TFocusFtdcOrderLocalIDType	OrderLocalID;
	///子资金帐号
	TFocusFtdcAccountIDType	SubAccountID;
	///下单用户编号
	TFocusFtdcUserIDType	OrderUserID;
	///交易类型
	TFocusFtdcTradeTypeType	TradeType;
	///处理标志
	TFocusFtdcDealFlagType	DealFlag;
	///已成交佣金
	TFocusFtdcMoneyType	TradeCommision;
	///成交金额
	TFocusFtdcMoneyType	TradeAmnt;
	///通过本地报单号推出的子投资者编号
	TFocusFtdcInvestorIDType	SubInvestorID;
	///投资者类型
	TFocusFtdcInvestorTypeType	InvestorType;
	///子报单编号
	TFocusFtdcOrderSysIDType	SubOrderSysID;
	///父投资者编号
	TFocusFtdcCodeType	ParentInvestorCode;
	///使用哪个通道下单
	TFocusFtdcNumberType	APIID;
	///平仓冻结数量
	TFocusFtdcVolumeType	VolumeFrozenClosing;
	///冻结数量
	TFocusFtdcVolumeType	VolumeFrozen;
	///本报单冻结了多少资金
	TFocusFtdcMoneyType	FrozenMoney;
	///工作流报单编号
	TFocusFtdcOrderSysIDType	AdviceOrderSysID;
	///证券哪个产品
	TFocusFtdcProductIDType	ProductID;
	///本报单冻结了多少手续费
	TFocusFtdcMoneyType	FrozenFee;
	///本报单冻结了多少过户费
	TFocusFtdcMoneyType	FrozenTransferFee;
	///本报单冻结了多少印花税
	TFocusFtdcMoneyType	FrozenStampTax;
	///申赎仓冻结数量
	TFocusFtdcVolumeType	PurRedVolumeFrozen;
	///今买卖仓冻结数量
	TFocusFtdcVolumeType	CloseVolumeFrozen;
	///备注
	TFocusFtdcRemarkType	Remark;
};

///定价合约价差
struct CFocusFtdcPriceSpreadField
{
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///价差
	TFocusFtdcPriceType	Spread;
	///价差合约代码
	TFocusFtdcInstrumentIDType	SpreadInstrumentId;
	///价差设置方式
	TFocusFtdcPriceSpreadTypeType	PriceSpreadType;
};

///查询合约价差
struct CFocusFtdcQryPriceSpreadField
{
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
};

///查询做市对冲
struct CFocusFtdcQryMarkerHedgeField
{
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
};

///做市日志信息
struct CFocusFtdcStrategyLogField
{
	///日志编号
	TFocusFtdcNumberType	EventID;
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
	///做市事件类型
	TFocusFtdcEventTypeType	EventType;
	///做市事件代码
	TFocusFtdcSequenceNoType	EventCode;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///日志内容
	TFocusFtdcLargeErrorMsgType	Log_Content;
	///操作日期
	TFocusFtdcDateType	OperDate;
	///操作时间
	TFocusFtdcTimeType	OperTime;
};

///预警指标设置
struct CFocusFtdcAlertIndexSetParamField
{
	///产品名称
	TFocusFtdcProductIDType	ProductID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///投资者类型
	TFocusFtdcInvestorTypeType	InvestorType;
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///指标明细代码
	TFocusFtdcAlertIndexTypeType	AlertIndexCode;
	///黄色预警上限
	TFocusFtdcLargeVolumeType	MAX_L1;
	///黄色预警下限
	TFocusFtdcLargeVolumeType	MIN_L1;
	///红色预警上限
	TFocusFtdcLargeVolumeType	MAX_L2;
	///红色预警下限
	TFocusFtdcLargeVolumeType	MIN_L2;
	///默认时间间隔
	TFocusFtdcNumberType	TimeAvail;
	///红色预警操作
	TFocusFtdcAlertActionTypeType	AlertAction;
};

///查询预警指标设置
struct CFocusFtdcQryAlertIndexSetParamField
{
	///产品名称
	TFocusFtdcProductIDType	ProductID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///投资者类型
	TFocusFtdcInvestorTypeType	InvestorType;
	///指标明细代码
	TFocusFtdcAlertIndexTypeType	AlertIndexCode;
};

///预警指标值
struct CFocusFtdcAlertIndexSetDataField
{
	///产品名称
	TFocusFtdcProductIDType	ProductID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///指标明细代码
	TFocusFtdcAlertIndexTypeType	AlertIndexCode;
	///指标明细值
	TFocusFtdcLargeVolumeType	IndexVolume;
	///黄色预警上限
	TFocusFtdcLargeVolumeType	MAX_L1;
	///黄色预警下限
	TFocusFtdcLargeVolumeType	MIN_L1;
	///红色预警上限
	TFocusFtdcLargeVolumeType	MAX_L2;
	///红色预警下限
	TFocusFtdcLargeVolumeType	MIN_L2;
	///预警操作
	TFocusFtdcAlertActionTypeType	AlertAction;
	///输出值日期
	TFocusFtdcDateType	OperDate;
	///输出值时间
	TFocusFtdcTimeType	OperTime;
};

///做市报价累计持仓
struct CFocusFtdcQuoteTotalTradePositionField
{
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///当日累计买成交，不管开平
	TFocusFtdcVolumeType	BuyVolume;
	///当日累计卖成交，不管开平
	TFocusFtdcVolumeType	SellVolume;
	///当日净成交，不管开平
	TFocusFtdcVolumeType	NetVolume;
	///当日买持仓，多头持仓
	TFocusFtdcVolumeType	BuyPosition;
	///当日卖持仓，空头持仓
	TFocusFtdcVolumeType	SellPosition;
	///当日净持仓
	TFocusFtdcVolumeType	NetPosition;
};

///交易所梯度价差
struct CFocusFtdcMarkerStepField
{
	///梯度模板
	TFocusFtdcQuoteStepType	StepID;
	///梯度名称
	TFocusFtdcStepNameType	StepName;
	///产品名称
	TFocusFtdcProductIDType	ProductID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///梯度类型
	TFocusFtdcStepTypeType	StepType;
	///梯度单位
	TFocusFtdcQuoteWidthTypeType	WidthType;
	///价格下限
	TFocusFtdcPriceType	LowPrice;
	///价格上限
	TFocusFtdcPriceType	UpPrice;
	///StepValue1
	TFocusFtdcPriceType	StepValue1;
	///StepValue2
	TFocusFtdcPriceType	StepValue2;
	///StepValue3
	TFocusFtdcPriceType	StepValue3;
	///value键值
	TFocusFtdcNumberType	StepValueKey;
};

///做市报价移动策略
struct CFocusFtdcQuoteMoveField
{
	///产品名称
	TFocusFtdcProductIDType	ProductID;
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///成交统计时间（秒）
	TFocusFtdcNumberType	SumVolumeTime;
	///成交数量（净成交，不区分正负）
	TFocusFtdcNumberType	SumVolume;
	///报价偏移（百分比）
	TFocusFtdcRatioType	Move;
	///维持时间（秒）
	TFocusFtdcNumberType	KeepTime;
	///立即成交报价策略:0：单边 1：双边
	TFocusFtdcTakeOutType	TakeOut;
	///关闭：0，开启：1
	TFocusFtdcSwitchFlagType	IsActive;
	///临近执行价偏移：关闭：0，开启：1
	TFocusFtdcSwitchFlagType	NearStrikeMove;
	///临近执行价波动率差值
	TFocusFtdcPriceType	NearStrikeVolSpread;
	///临近执行价移动类型：0：理论价反手 1：对手价反手
	TFocusFtdcOrderTypeType	NearMoveType;
	///临近执行价维持时间（秒）
	TFocusFtdcVolumeType	NearKeepTime;
};

///基础梯度价差信息
struct CFocusFtdcBaseMarkerStepField
{
	///梯度模板
	TFocusFtdcQuoteStepType	StepID;
	///梯度名称
	TFocusFtdcStepNameType	StepName;
	///产品名称
	TFocusFtdcProductIDType	ProductID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///梯度类型
	TFocusFtdcStepTypeType	StepType;
	///梯度单位
	TFocusFtdcQuoteWidthTypeType	WidthType;
};

///后台进程交易状态
struct CFocusFtdcFocusStatusField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///进程交易状态
	TFocusFtdcIsActiveType	TradeStatus;
};

///ATM价格
struct CFocusFtdcATMPriceDataField
{
	///用户代码(交易员)
	TFocusFtdcUserIDType	UserID;
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///标的价格，计算理论价，Greeks请传这个
	TFocusFtdcPriceType	UnderlyingMid;
	///标的远期价格
	TFocusFtdcPriceType	AtmForword;
	///剩余天数
	TFocusFtdcTimeValueType	RemainDay;
	///V10D
	TFocusFtdcPriceType	V10D;
	///V10D
	TFocusFtdcPriceType	V25D;
	///V10D
	TFocusFtdcPriceType	V45D;
	///ATM 波动率
	TFocusFtdcPriceType	AtmVol;
	///V10D
	TFocusFtdcPriceType	V55D;
	///V10D
	TFocusFtdcPriceType	V75D;
	///V10D
	TFocusFtdcPriceType	V90D;
	///输出值时间
	TFocusFtdcTimeType	OperTime;
};

///期货做市总开关
struct CFocusFtdcFutureMakerWholeSwitchField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///交易员总开关
	TFocusFtdcSwitchFlagType	WholeSwitch;
};

///期货做市报价参数
struct CFocusFtdcFutureMakerStrategyField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///一档开关
	TFocusFtdcSwitchFlagType	FirstSwitch;
	///一档期货报价方式
	TFocusFtdcFutureMakerFlagType	FirstFutureMakerFlag;
	///一档容忍度
	TFocusFtdcVolumeType	FirstToler;
	///一档下单量
	TFocusFtdcVolumeType	FirstAmount;
	///一档宽度（tick）
	TFocusFtdcVolumeType	FirstWidth;
	///二档开关
	TFocusFtdcSwitchFlagType	SecondSwitch;
	///二档期货报价方式
	TFocusFtdcFutureMakerFlagType	SecondFutureMakerFlag;
	///二档容忍度
	TFocusFtdcVolumeType	SecondToler;
	///二档下单量
	TFocusFtdcVolumeType	SecondAmount;
	///二档宽度（tick）
	TFocusFtdcVolumeType	SecondWidth;
	///三档开关
	TFocusFtdcSwitchFlagType	ThirdSwitch;
	///三档期货报价方式
	TFocusFtdcFutureMakerFlagType	ThirdFutureMakerFlag;
	///三档容忍度
	TFocusFtdcVolumeType	ThirdToler;
	///三档下单量
	TFocusFtdcVolumeType	ThirdAmount;
	///三档宽度（tick）
	TFocusFtdcVolumeType	ThirdWidth;
	///成交统计时间（秒）
	TFocusFtdcNumberType	SumVolumeTime;
	///成交数量（净成交，不区分正负）
	TFocusFtdcNumberType	SumVolume;
	///维持时间（秒）
	TFocusFtdcNumberType	KeepTime;
	///期货开平标志
	TFocusFtdcOffsetFlagType	FutureOffsetFlag;
};

///期货反手对冲参数
struct CFocusFtdcSlefHedgeStrategyField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///反手报单报价方式
	TFocusFtdcHedgeFutureMakerFlagType	SlefHedgeFutureMakerFlag;
	///反手报单调整tick
	TFocusFtdcVolumeType	SlefHedgeFutureMakerTick;
	///反手报单偏离tick重新报单
	TFocusFtdcVolumeType	SlefHedgeDeviate;
	///反手报单超时撤单
	TFocusFtdcVolumeType	SlefHedgeTimeAction;
	///反手追单次数
	TFocusFtdcVolumeType	SlefChaseTimes;
	///最大亏损
	TFocusFtdcVolumeType	MaxLossTick;
};

///期货对冲合约对冲参数
struct CFocusFtdcFutureHedgeStrategyField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///对冲合约交易所代码
	TFocusFtdcExchangeIDType	HedgeExchangeID;
	///对冲合约代码
	TFocusFtdcInstrumentIDType	HedgeInstrumentID;
	///对冲资金账号
	TFocusFtdcInvestorIDType	HedgeInvestorID;
	///价差
	TFocusFtdcPriceType	Spread;
	///期货对冲报价方式
	TFocusFtdcHedgeFutureMakerFlagType	HedgeFutureMakerFlag;
	///期货对冲调整tick
	TFocusFtdcVolumeType	HedgeFutureMakerTick;
	///偏离tick重新报单
	TFocusFtdcVolumeType	HedgeDeviate;
	///挂单超时撤单
	TFocusFtdcVolumeType	HedgeTimeAction;
	///追单次数
	TFocusFtdcVolumeType	HedgeChaseTimes;
	///期货对冲合约开平标志
	TFocusFtdcOffsetFlagType	HedgeOffsetFlag;
};

///做市报价额外参数设置
struct CFocusFtdcQuoteAdditionParmField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///报价价差宽度
	TFocusFtdcMoneyType	QuotePriceWidth;
	///报价价差比
	TFocusFtdcLargeVolumeType	QuoteWidthRatio;
	///报价宽度单位
	TFocusFtdcQuoteWidthTypeType	QuoteWidthType;
	///中心价容忍度
	TFocusFtdcVolumeType	TOL_TICK;
	///备注
	TFocusFtdcRemarkType	Remark;
};

///期货对冲报价状态通知
struct CFocusFtdcFutureMakerHedgeStatusField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///反手报单状态，0.无报单，1.有报单
	TFocusFtdcSwitchFlagType	SlefHedgeStatus;
	///反手报单状态，0.无报单，1.有报单
	TFocusFtdcSwitchFlagType	FutureHedgeStatus;
};

///一键撤销所有期货做市对冲单
struct CFocusFtdcStopAllFutureMakerHedgeOfferField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///0，反手对冲单，2， 期货对冲单  3. 全部对冲单
	TFocusFtdcRemarkType	HedgeOfferType;
};

///期货做市键值
struct CFocusFtdcFutureMakerIndexField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///查询期货做市参数
struct CFocusFtdcAllFutureMakerStrategyField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///交易员总开关
	TFocusFtdcSwitchFlagType	WholeSwitch;
	///一档开关
	TFocusFtdcSwitchFlagType	FirstSwitch;
	///一档期货报价方式
	TFocusFtdcFutureMakerFlagType	FirstFutureMakerFlag;
	///一档容忍度
	TFocusFtdcVolumeType	FirstToler;
	///一档下单量
	TFocusFtdcVolumeType	FirstAmount;
	///一档宽度（tick）
	TFocusFtdcVolumeType	FirstWidth;
	///二档开关
	TFocusFtdcSwitchFlagType	SecondSwitch;
	///二档期货报价方式
	TFocusFtdcFutureMakerFlagType	SecondFutureMakerFlag;
	///二档容忍度
	TFocusFtdcVolumeType	SecondToler;
	///二档下单量
	TFocusFtdcVolumeType	SecondAmount;
	///二档宽度（tick）
	TFocusFtdcVolumeType	SecondWidth;
	///三档开关
	TFocusFtdcSwitchFlagType	ThirdSwitch;
	///三档期货报价方式
	TFocusFtdcFutureMakerFlagType	ThirdFutureMakerFlag;
	///三档容忍度
	TFocusFtdcVolumeType	ThirdToler;
	///三档下单量
	TFocusFtdcVolumeType	ThirdAmount;
	///三档宽度（tick）
	TFocusFtdcVolumeType	ThirdWidth;
	///成交统计时间（秒）
	TFocusFtdcNumberType	SumVolumeTime;
	///成交数量（净成交，不区分正负）
	TFocusFtdcNumberType	SumVolume;
	///维持时间（秒）
	TFocusFtdcNumberType	KeepTime;
	///期货开平标志
	TFocusFtdcOffsetFlagType	FutureOffsetFlag;
	///反手报单报价方式
	TFocusFtdcHedgeFutureMakerFlagType	SlefHedgeFutureMakerFlag;
	///反手报单调整tick
	TFocusFtdcVolumeType	SlefHedgeFutureMakerTick;
	///反手报单偏离tick重新报单
	TFocusFtdcVolumeType	SlefHedgeDeviate;
	///反手报单超时撤单
	TFocusFtdcVolumeType	SlefHedgeTimeAction;
	///反手追单次数
	TFocusFtdcVolumeType	SlefChaseTimes;
	///最大亏损
	TFocusFtdcVolumeType	MaxLossTick;
	///对冲合约交易所代码
	TFocusFtdcExchangeIDType	HedgeExchangeID;
	///对冲合约代码
	TFocusFtdcInstrumentIDType	HedgeInstrumentID;
	///对冲资金账号
	TFocusFtdcInvestorIDType	HedgeInvestorID;
	///价差
	TFocusFtdcPriceType	Spread;
	///期货对冲报价方式
	TFocusFtdcHedgeFutureMakerFlagType	HedgeFutureMakerFlag;
	///期货对冲调整tick
	TFocusFtdcVolumeType	HedgeFutureMakerTick;
	///偏离tick重新报单
	TFocusFtdcVolumeType	HedgeDeviate;
	///挂单超时撤单
	TFocusFtdcVolumeType	HedgeTimeAction;
	///追单次数
	TFocusFtdcVolumeType	HedgeChaseTimes;
	///期货对冲合约开平标志
	TFocusFtdcOffsetFlagType	HedgeOffsetFlag;
};

///内部股票高频策略表
struct CFocusFtdcInnerHighStockStrategyField
{
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///股票合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///股票策略名
	TFocusFtdcStrategyNameType	StockStrategyName;
	///策略类型（增仓or换仓，换仓为0，其余为大于0）
	TFocusFtdcVolumeType	StockStrategyType;
	///每个股票权重
	TFocusFtdcRatioType	Ratio;
	///每次最大下单数（如需）
	TFocusFtdcVolumeType	MaxVolume;
	///每次最小单数（如需，默认为100）
	TFocusFtdcVolumeType	MinVolume;
	///股票每次下单比例（%）
	TFocusFtdcRatioType	StockRatioAvail;
	///市场平均集合竞价成交量1
	TFocusFtdcVolumeType	AverMactchTradeVolume1;
	///市场平均集合竞价成交量2
	TFocusFtdcVolumeType	AverMactchTradeVolume2;
	///昨收盘
	TFocusFtdcPriceType	PreClosePrice;
	///股票下单类型
	TFocusFtdcStockStrategyPriceType	StockPriceType;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///最新委托的
	TFocusFtdcOrderSysIDType	LastOrderSysID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///股票委托批号(仅批量委托有效)
	TFocusFtdcOrderSysIDType	LastBatchNum;
	///昨日持仓
	TFocusFtdcVolumeType	YPosition;
	///总最开始的目标持仓
	TFocusFtdcVolumeType	StaticEndPosition;
	///总目标持仓
	TFocusFtdcVolumeType	EndPosition;
	///总实际目前持仓
	TFocusFtdcVolumeType	NowPosition;
	///总持仓可平仓数量
	TFocusFtdcVolumeType	PositionClose;
	///今日开仓数量(不包括冻结)
	TFocusFtdcVolumeType	OpenVolume;
	///今日平仓数量(包括昨持仓的平仓,不包括冻结)
	TFocusFtdcVolumeType	CloseVolume;
	///Alpha目标个股市值(以昨结算)
	TFocusFtdcMoneyType	AlphaTargetValue;
	///Alpha当前买入总资金(以昨结算)
	TFocusFtdcMoneyType	AlphaCurrentTotalValue;
	///开始操作时间
	TFocusFtdcTimeType	StartOperTime;
	///最新操作时间
	TFocusFtdcTimeType	LastOperTime;
	///最新需要报的数量
	TFocusFtdcVolumeType	LastNeedSendVolume;
	///最新报的价格
	TFocusFtdcPriceType	LastSendPrice;
	///最新市场总成交量
	TFocusFtdcVolumeType	PreMarketTradeVolume;
	///股票平均成交量统计间隔次数（MA）
	TFocusFtdcNumberType	MAStockAvail;
	///间隔时间内的市场股票平均成交量
	TFocusFtdcVolumeType	GapVolume;
	///该只股票当前是否正在交易
	TFocusFtdcBoolType	StockIsTrading;
	///该股是否是低价股
	TFocusFtdcBoolType	IsLowStock;
	///启动之前最新买成交总量
	TFocusFtdcVolumeType	SignalHasBuyTotalPosition;
	///启动之前最新卖成交总量
	TFocusFtdcVolumeType	SignalHasSellTotalPosition;
	///个股买完成比例
	TFocusFtdcMoneyType	SignalLastPer;
	///操作备注
	TFocusFtdcDepositNoteType	Note;
	///优先权
	TFocusFtdcDepositNoteType	Priority;
	///个股行情状态
	TFocusFtdcDepositNoteType	StkOrderStatus;
	///开盘价格
	TFocusFtdcPriceType	OpenPrice;
	///总成交量（包括了买和卖）
	TFocusFtdcVolumeType	TotalTradeVolume;
	///今日买总成本
	TFocusFtdcMoneyType	TotalBuyCostMoney;
	///今日卖总成本
	TFocusFtdcMoneyType	TotalSellCostMoney;
	///今日平均成本
	TFocusFtdcMoneyType	AverCostMoney;
	///第几轮报单
	TFocusFtdcVolumeType	TotalRoundAmount;
	///尾盘策略之前总成交量（包括了买和卖）
	TFocusFtdcVolumeType	AllAddTotalTradeVolume;
	///尾盘策略之前今日累积买总成本
	TFocusFtdcMoneyType	AllAddTotalBuyCostMoney;
	///尾盘策略之前今日累积卖总成本
	TFocusFtdcMoneyType	AllAddTotalSellCostMoney;
	///尾盘策略之前今日累积平均成本
	TFocusFtdcMoneyType	AllAddAverCostMoney;
	///多因子list最开始的目标持仓
	TFocusFtdcVolumeType	AlphaListStaticEndPosition;
	///多因子list目标持仓
	TFocusFtdcVolumeType	AlphaListEndPosition;
	///多因子list最新持仓
	TFocusFtdcVolumeType	AlphaListNowPosition;
	///AlphaList优先权
	TFocusFtdcDepositNoteType	AlphaListPriority;
	///该只股票AlphaList当前是否正在交易
	TFocusFtdcBoolType	AlphaListStockIsTrading;
	///多因子list最开始的目标持仓
	TFocusFtdcVolumeType	TZeroStaticEndPosition;
	///盘中list总目标持仓
	TFocusFtdcVolumeType	TZeroEndPosition;
	///盘中list实际目前持仓
	TFocusFtdcVolumeType	TZeroNowPosition;
	///t0最新设置时间
	TFocusFtdcTimeType	TZeroLastOperTime;
	///TZero需要改变的股数
	TFocusFtdcVolumeType	TZeroGapVolume;
	///TZero最晚结束时间
	TFocusFtdcTimeType	TZeroEndOperTime;
	///TZero下单上限价格
	TFocusFtdcPriceType	TZeroUpperEndPrice;
	///TZero下单下限价格
	TFocusFtdcPriceType	TZeroLowerEndPrice;
	///TZero股票下单类型
	TFocusFtdcStockStrategyPriceType	TZeroStockPriceType;
	///TZero持仓（总）
	TFocusFtdcVolumeType	TZeroAddPosition;
	///TZero总静态开仓市值
	TFocusFtdcPriceType	T0StaticTotalMoney;
	///TZero静态收益
	TFocusFtdcPriceType	TZeroStaticRights;
	///TZero平仓收益
	TFocusFtdcPriceType	TZeroColseRights;
	///任然需要交易的量
	TFocusFtdcVolumeType	StillNeedSendPosition;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///算法操作备注
	TFocusFtdcDepositNoteType	AlgoNote;
};

///股票策略开关
struct CFocusFtdcWholeHighStockStrategySwitchField
{
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///策略类型（增仓or换仓，换仓为0，其余为大于0）
	TFocusFtdcVolumeType	StockStrategyType;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///交易员总开关
	TFocusFtdcSwitchFlagType	StockWholeSwitch;
};

///查询策略的键值
struct CFocusFtdcQryWholeHighStockStrategyField
{
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///策略类型（增仓or换仓，换仓为0，其余为大于0）
	TFocusFtdcVolumeType	StockStrategyType;
};

///查询策略的单个股票的键值
struct CFocusFtdcQrySignalHighStockStrategyField
{
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///策略类型（增仓or换仓，换仓为0，其余为大于0）
	TFocusFtdcVolumeType	StockStrategyType;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///股票合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///查询策略的单个股票的键值
struct CFocusFtdcSignalHighStockStrategySwitchField
{
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///策略类型（增仓or换仓，换仓为0，其余为大于0）
	TFocusFtdcVolumeType	StockStrategyType;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///股票合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///股票单个开关
	TFocusFtdcSwitchFlagType	StockWholeSwitch;
};

///股票高频策略表
struct CFocusFtdcAPIHighStockStrategyField
{
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///股票合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///股票策略名
	TFocusFtdcStrategyNameType	StockStrategyName;
	///策略类型（增仓or换仓，换仓为0，其余为大于0）
	TFocusFtdcVolumeType	StockStrategyType;
	///每个股票权重
	TFocusFtdcRatioType	Ratio;
	///每次最大下单数（如需）
	TFocusFtdcVolumeType	MaxVolume;
	///每次最小单数（如需，默认为100）
	TFocusFtdcVolumeType	MinVolume;
	///股票每次下单比例（%）
	TFocusFtdcRatioType	StockRatioAvail;
	///市场平均集合竞价成交量1
	TFocusFtdcVolumeType	AverMactchTradeVolume1;
	///市场平均集合竞价成交量2
	TFocusFtdcVolumeType	AverMactchTradeVolume2;
	///昨收盘
	TFocusFtdcPriceType	PreClosePrice;
	///股票下单类型
	TFocusFtdcStockStrategyPriceType	StockPriceType;
};

///股票期货对冲关系表
struct CFocusFtdcHighFutureStrategyRelationField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///策略类型（增仓or换仓，换仓为0，其余为大于0）
	TFocusFtdcVolumeType	StockStrategyType;
	///股票策略当前是否交易
	TFocusFtdcBoolType	StockStrategyIsTrading;
	///股票轮训检查时间间隔（秒）
	TFocusFtdcNumberType	StockTimeAvail;
	///股票平均成交量统计间隔次数（MA）
	TFocusFtdcNumberType	MAStockAvail;
	///单个股票报价容忍度，正常下单时高价股#低价股@单边时高价股#低价股 J#A@A#A
	TFocusFtdcDepositNoteType	StockTolerRatio;
	///停止报单股票总买卖金额偏离比率（%）
	TFocusFtdcRatioType	StopDeviRatio;
	///恢复股票总买卖金额偏离比率（%）
	TFocusFtdcRatioType	RrecovrDeviRatio;
	///初始化预分配换仓总资金
	TFocusFtdcMoneyType	TargetMoney;
	///每轮下单市值上限资金
	TFocusFtdcMoneyType	RoundMaxMoney;
	///期货交易所代码
	TFocusFtdcExchangeIDType	FutureExchangeID;
	///期货合约代码
	TFocusFtdcInstrumentIDType	FutureInstrumentID;
	///期货买卖方向
	TFocusFtdcDirectionType	FutureDirection;
	///期货报单类型
	TFocusFtdcStockStrategyPriceType	FuturePriceType;
	///对应期货当前是否交易（换仓默认开关无效）
	TFocusFtdcBoolType	FutureIsTrading;
	///期货资金账号
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///期货默认检查时间间隔
	TFocusFtdcNumberType	FutureTimeAvail;
	///固定逆回购金额
	TFocusFtdcMoneyType	StaticRebuyMoney;
	///是否延续涨跌停
	TFocusFtdcSwitchFlagType	BRNeedContinue;
	///最大换仓比例
	TFocusFtdcRatioType	MaxTradePer;
	///期货算法类型
	TFocusFtdcVolumeType	FutureAlgoType;
	///指数交易所
	TFocusFtdcExchangeIDType	IndexExchangeID;
	///指数合约
	TFocusFtdcInstrumentIDType	IndexInstrumentID;
	///基差
	TFocusFtdcPriceType	SpreadPrice;
	///期货下单手数
	TFocusFtdcVolumeType	FutureAmount;
	///List中price的价格类型
	TFocusFtdcListPriceTypeType	ListPriceType;
	///期现下单匹配度(0~1)
	TFocusFtdcRatioType	FuStockRelation;
	///是否跟随期货下单
	TFocusFtdcBoolType	FlowerFuture;
	///期货间隔手数
	TFocusFtdcVolumeType	FutureAvailAmount;
	///仓位权重类型
	TFocusFtdcPositionRatioTypeType	PositionRatioType;
	///股票换仓算法(0,自有 1 AlgoTwap 2. AlgoVwap)
	TFocusFtdcVolumeType	StockAlgoType;
	///策略开始时间(HH:mm:ss)
	TFocusFtdcTimeType	AlgoStrategyStartTime;
	///策略停止时间(HH:mm:ss)
	TFocusFtdcTimeType	AlgoStrategyEndTime;
};

///股票期货对冲关系内部表
struct CFocusFtdcHighInnerFutureStrategyRelationField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///策略类型（增仓or换仓，换仓为0，其余为大于0）
	TFocusFtdcVolumeType	StockStrategyType;
	///股票策略当前是否交易
	TFocusFtdcBoolType	StockStrategyIsTrading;
	///股票轮训检查时间间隔（秒）
	TFocusFtdcNumberType	StockTimeAvail;
	///股票平均成交量统计间隔次数（MA）
	TFocusFtdcNumberType	MAStockAvail;
	///单个股票报价容忍度，正常下单时高价股#低价股@单边时高价股#低价股 J#A@A#A
	TFocusFtdcDepositNoteType	StockTolerRatio;
	///停止报单股票总买卖金额偏离比率（%）
	TFocusFtdcRatioType	StopDeviRatio;
	///恢复股票总买卖金额偏离比率（%）
	TFocusFtdcRatioType	RrecovrDeviRatio;
	///初始化预分配换仓总资金
	TFocusFtdcMoneyType	TargetMoney;
	///每轮下单市值上限资金
	TFocusFtdcMoneyType	RoundMaxMoney;
	///期货交易所代码
	TFocusFtdcExchangeIDType	FutureExchangeID;
	///期货合约代码
	TFocusFtdcInstrumentIDType	FutureInstrumentID;
	///期货买卖方向
	TFocusFtdcDirectionType	FutureDirection;
	///期货报单类型
	TFocusFtdcStockStrategyPriceType	FuturePriceType;
	///对应期货当前是否交易（换仓默认开关无效）
	TFocusFtdcBoolType	FutureIsTrading;
	///期货资金账号
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///期货默认检查时间间隔
	TFocusFtdcNumberType	FutureTimeAvail;
	///固定逆回购金额
	TFocusFtdcMoneyType	StaticRebuyMoney;
	///是否延续涨跌停
	TFocusFtdcSwitchFlagType	BRNeedContinue;
	///最大换仓比例
	TFocusFtdcRatioType	MaxTradePer;
	///期货算法类型
	TFocusFtdcVolumeType	FutureAlgoType;
	///指数交易所
	TFocusFtdcExchangeIDType	IndexExchangeID;
	///指数合约
	TFocusFtdcInstrumentIDType	IndexInstrumentID;
	///基差
	TFocusFtdcPriceType	SpreadPrice;
	///期货下单手数
	TFocusFtdcVolumeType	FutureAmount;
	///List中price的价格类型
	TFocusFtdcListPriceTypeType	ListPriceType;
	///期现下单匹配度(0~1)
	TFocusFtdcRatioType	FuStockRelation;
	///是否跟随期货下单
	TFocusFtdcBoolType	FlowerFuture;
	///期货间隔手数
	TFocusFtdcVolumeType	FutureAvailAmount;
	///仓位权重类型
	TFocusFtdcPositionRatioTypeType	PositionRatioType;
	///股票换仓算法(0,自有 1 AlgoTwap 2. AlgoVwap)
	TFocusFtdcVolumeType	StockAlgoType;
	///策略开始时间(HH:mm:ss)
	TFocusFtdcTimeType	AlgoStrategyStartTime;
	///策略停止时间(HH:mm:ss)
	TFocusFtdcTimeType	AlgoStrategyEndTime;
	///操作备注
	TFocusFtdcDepositNoteType	Note;
	///策略行情状态
	TFocusFtdcDepositNoteType	RelationOrderStatus;
	///实际分配总资金
	TFocusFtdcMoneyType	RealTargetMoney;
	///最新买总成交总量
	TFocusFtdcMoneyType	LastTotalBuyMoney;
	///最新卖总成交总量
	TFocusFtdcMoneyType	LastTotalSellMoney;
	///最新需要买的总金额
	TFocusFtdcMoneyType	LastTotalNeedBuyMoney;
	///最新需要卖的总金额
	TFocusFtdcMoneyType	LastTotalNeedSellMoney;
	///最新冻结的总金额
	TFocusFtdcMoneyType	LastFrozenMoney;
	///买完成比例
	TFocusFtdcMoneyType	LastBuyPer;
	///卖完成比例
	TFocusFtdcMoneyType	LastSellPer;
	///最新操作时间
	TFocusFtdcTimeType	LastOperTime;
	///今日买总成本
	TFocusFtdcMoneyType	TotalBuyCostMoney;
	///今日卖总成本
	TFocusFtdcMoneyType	TotalSellCostMoney;
	///今日手续费成本
	TFocusFtdcMoneyType	TotalFeeCostMoney;
	///今日平均成本
	TFocusFtdcMoneyType	AverCostMoney;
	///是否买卖相等
	TFocusFtdcDepositNoteType	IsPerEqual;
	///买卖价差值（正数）
	TFocusFtdcMoneyType	BuySellGapMoney;
	///尾盘卖出总成交金额
	TFocusFtdcMoneyType	CloseEndSellMoney;
	///整体成本
	TFocusFtdcMoneyType	TotalAverCostMoney;
	///是否自动逆回购
	TFocusFtdcSwitchFlagType	BRebuySwitch;
	///尾盘策略之前今日累积最新买总成交总量
	TFocusFtdcMoneyType	AllAddLastTotalBuyMoney;
	///尾盘策略之前今日累积最新卖总成交总量
	TFocusFtdcMoneyType	AllAddLastTotalSellMoney;
	///尾盘策略之前今日累积买总成本
	TFocusFtdcMoneyType	AllAddTotalBuyCostMoney;
	///尾盘策略之前今日累积卖总成本
	TFocusFtdcMoneyType	AllAddTotalSellCostMoney;
	///尾盘策略之前今日累积卖手续费成本
	TFocusFtdcMoneyType	AllAddTotalFeeCostMoney;
	///尾盘策略之前今日累积平均成本
	TFocusFtdcMoneyType	AllAddAverCostMoney;
	///尾盘策略之前今日累积整体成本
	TFocusFtdcMoneyType	AllAddTotalAverCostMoney;
	///择时方向
	TFocusFtdcDepositNoteType	IndexDirSignal;
	///最新期货操作时间
	TFocusFtdcTimeType	LastFuOperTime;
	///已完成对冲总交易量
	TFocusFtdcVolumeType	LastFuTarNetPosition;
	///对冲操作备注
	TFocusFtdcDepositNoteType	FutureNote;
	///期货价差对冲是否需要检查
	TFocusFtdcBoolType	FutureSpreadNeedCheck;
	///开仓那刻期货价格
	TFocusFtdcPriceType	OpenFuInstrPrice;
	///上次完成的总交易量
	TFocusFtdcVolumeType	BeforeLastFuTarNetPosition;
	///现货对于期货手数
	TFocusFtdcRatioType	NetFuPosition;
	///实时基差
	TFocusFtdcPriceType	RealTimeSpreadPrice;
	///实时指数价格
	TFocusFtdcPriceType	RealIndexPrice;
	///实时期货价格
	TFocusFtdcPriceType	RealFuturePrice;
	///期货操作备注2
	TFocusFtdcDepositNoteType	FutureRelationNote;
	///最新期货对冲操作时间
	TFocusFtdcTimeType	LastHedgeFuOperTime;
	///算法操作备注
	TFocusFtdcDepositNoteType	AlgoNote;
};

///查询所有股票期货对冲关系表
struct CFocusFtdcQryAllHighFutureStrategyRelationField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
};

///股票交易阶段下单方式
struct CFocusFtdcStockMarketTradingPeriodStrategyField
{
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///起始时间
	TFocusFtdcTimeType	TpStart;
	///结束时间
	TFocusFtdcTimeType	TpEnd;
	///交易类型（正常下单时高价股#低价股@单边时高价股#低价股 J#A@A#A）
	TFocusFtdcDepositNoteType	StockOrderType;
	///停止报单股票总买卖金额偏离比率（%）
	TFocusFtdcRatioType	StopDeviRatio;
	///恢复股票总买卖金额偏离比率（%）
	TFocusFtdcRatioType	RrecovrDeviRatio;
	///每轮下单市值上限资金
	TFocusFtdcMoneyType	RoundMaxMoney;
	///股票轮训检查时间间隔（秒）
	TFocusFtdcNumberType	StockTimeAvail;
	///单个股票报价容忍度，正常下单时高价股#低价股@单边时高价股#低价股 J#A@A#A
	TFocusFtdcDepositNoteType	StockTolerRatio;
	///是否新下单加上上次撤单量
	TFocusFtdcSwitchFlagType	NeedAddCancelVolumeSwitch;
	///每次下单量用对手量和前几次量平均量取大
	TFocusFtdcSwitchFlagType	NeedGetSideVolumeSwitch;
	///是否MaxVolume生效
	TFocusFtdcSwitchFlagType	CheckMaxVolumeSwitch;
};

///逆回购自动卖出开关
struct CFocusFtdcRelationAutoReBuySwitchField
{
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///逆回购开关
	TFocusFtdcSwitchFlagType	RelationReBuySwitch;
};

///期货算法订单
struct CFocusFtdcFutureStrategyOrderField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///目标净持仓量
	TFocusFtdcVolumeType	TargetNetPosition;
	///策略开始执行时间
	TFocusFtdcTimeType	StartTradingTime;
	///算法类型
	TFocusFtdcVolumeType	AlgoType;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///策略当前是否交易
	TFocusFtdcBoolType	StrategyIsTrading;
	///策略报单价格条件
	TFocusFtdcStockStrategyPriceType	StrategyPrice;
	///尾盘集合竞价需要下单量
	TFocusFtdcVolumeType	MactchTrdVol;
	///尾盘集合竞价下单方式
	TFocusFtdcStockStrategyPriceType	MactchTrdPriceType;
	///Vwap每轮最大下单量
	TFocusFtdcVolumeType	VwapMaxVolume;
	///是否加仓
	TFocusFtdcSwitchFlagType	IsAddPosi;
	///下单仓位类型
	TFocusFtdcAddPositionTypeType	AddPositionType;
	///价格触发条件
	TFocusFtdcPriceDirectionType	PriceDirection;
	///触发价格
	TFocusFtdcPriceType	TriggerPrice;
	///母单算法时的时间间隔
	TFocusFtdcVolumeType	TotalTimeAvail;
};

///算法参数
struct CFocusFtdcAlgoParmField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///容忍度(tick)
	TFocusFtdcVolumeType	TolerTick;
	///Twap总时间(s)
	TFocusFtdcVolumeType	TwapTotalTime;
	///Twap拆分数目
	TFocusFtdcVolumeType	TwapSplitAmount;
	///Vwap统计每秒平均成交量的时间间隔
	TFocusFtdcVolumeType	VwapTimeAvail;
	///Vwap容忍间隔时间
	TFocusFtdcVolumeType	VwapTotalTime;
	///Vwap计算总成交量的时间间隔（秒）
	TFocusFtdcNumberType	VwapVolumeTotalTime;
	///策略报单价格条件
	TFocusFtdcStockStrategyPriceType	StockStrategyPrice;
	///最大目标净持仓
	TFocusFtdcVolumeType	MaxNetPosition;
	///距离上次的最小变动仓位
	TFocusFtdcVolumeType	MinChangePosition;
	///是否比较对手量，百分比取大值
	TFocusFtdcSwitchFlagType	NeedGetSideVolumeSwitch;
	///对手量的比例
	TFocusFtdcRatioType	SideVolumePer;
};

///期货算法订单详情
struct CFocusFtdcInnerFutureStrategyOrderField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///目标净持仓量
	TFocusFtdcVolumeType	TargetNetPosition;
	///策略开始执行时间
	TFocusFtdcTimeType	StartTradingTime;
	///算法类型
	TFocusFtdcVolumeType	AlgoType;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///策略当前是否交易
	TFocusFtdcBoolType	StrategyIsTrading;
	///策略报单价格条件
	TFocusFtdcStockStrategyPriceType	StrategyPrice;
	///尾盘集合竞价需要下单量
	TFocusFtdcVolumeType	MactchTrdVol;
	///尾盘集合竞价下单方式
	TFocusFtdcStockStrategyPriceType	MactchTrdPriceType;
	///Vwap每轮最大下单量
	TFocusFtdcVolumeType	VwapMaxVolume;
	///是否加仓
	TFocusFtdcSwitchFlagType	IsAddPosi;
	///下单仓位类型
	TFocusFtdcAddPositionTypeType	AddPositionType;
	///价格触发条件
	TFocusFtdcPriceDirectionType	PriceDirection;
	///触发价格
	TFocusFtdcPriceType	TriggerPrice;
	///母单算法时的时间间隔
	TFocusFtdcVolumeType	TotalTimeAvail;
	///容忍度(tick)
	TFocusFtdcVolumeType	TolerTick;
	///Twap总时间(s)
	TFocusFtdcVolumeType	TwapTotalTime;
	///拆分数目
	TFocusFtdcVolumeType	TwapSplitAmount;
	///Vwap统计时间间隔
	TFocusFtdcVolumeType	VwapTimeAvail;
	///Vwap容忍间隔时间
	TFocusFtdcVolumeType	VwapTotalTime;
	///Vwap计算总成交量的时间间隔（秒）
	TFocusFtdcNumberType	VwapVolumeTotalTime;
	///策略报单价格条件
	TFocusFtdcStockStrategyPriceType	StockStrategyPrice;
	///最大目标净持仓
	TFocusFtdcVolumeType	MaxNetPosition;
	///距离上次的最小变动仓位
	TFocusFtdcVolumeType	MinChangePosition;
	///是否比较对手量，百分比取大值
	TFocusFtdcSwitchFlagType	NeedGetSideVolumeSwitch;
	///对手量的比例
	TFocusFtdcRatioType	SideVolumePer;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///分段操作时间（毫秒）
	TFocusFtdcLocalTimeType	GapMillisec;
	///小分段需要交易的量
	TFocusFtdcVolumeType	SplitVolume;
	///小分段需要交易的量(原始)
	TFocusFtdcVolumeType	OrginalSplitVolume;
	///全天需要成交量
	TFocusFtdcVolumeType	StaticlTotalNeedTradeVolume;
	///最新操作时间(s)
	TFocusFtdcLocalTimeType	LastCurrOperTime;
	///最新操作时间（毫秒）
	TFocusFtdcLocalTimeType	LastCurrMillisec;
	///容忍时间间隔（ms）
	TFocusFtdcNumberType	TolerTimeAvail;
	///买完成比例
	TFocusFtdcMoneyType	SignalLastPer;
	///比较基准开盘价格
	TFocusFtdcPriceType	PreparPrice;
	///总成本
	TFocusFtdcMoneyType	TotalCostMoney;
	///卖手续费成本
	TFocusFtdcMoneyType	TotalFeeCostMoney;
	///平均成本
	TFocusFtdcMoneyType	AverCostMoney;
	///操作备注
	TFocusFtdcDepositNoteType	Note;
	///本策略已成交数量
	TFocusFtdcVolumeType	StrategyTradeVolume;
	///实际目前持仓
	TFocusFtdcVolumeType	NowPosition;
	///最早新建订单时间（秒）
	TFocusFtdcTimeType	OrginRecvOrderTime;
	///最后收到改变订单时间（秒）
	TFocusFtdcTimeType	LastRecvOrderTime;
	///最新操作时间（秒）
	TFocusFtdcTimeType	LastOperTime;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
};

///期货算法交易订单键值
struct CFocusFtdcFutureStrategyOrderIndexField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
};

///大盘信号
struct CFocusFtdcIndexDirSignalField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///消息类型
	TFocusFtdcStrategyMessageTypeType	MessageType;
	///消息ID编号
	TFocusFtdcVolumeType	MessageID;
	///是否需要转发
	TFocusFtdcBoolType	NeedNtfMessage;
	///操作时间
	TFocusFtdcTimeType	OperTime;
	///消息内容
	TFocusFtdcStrategyMessageNoteType	Note;
};

///跨期策略订单键值
struct CFocusFtdcSpreadInstrStrategyIndexField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
};

///跨期策略
struct CFocusFtdcSpreadInstrStrategyField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///交易所1代码
	TFocusFtdcExchangeIDType	ExchangeIDLeg1;
	///买卖方向1
	TFocusFtdcDirectionType	DirectionLeg1;
	///腿1合约代码
	TFocusFtdcInstrumentIDType	InstrLeg1;
	///交易所2代码
	TFocusFtdcExchangeIDType	ExchangeIDLeg2;
	///买卖方向2
	TFocusFtdcDirectionType	DirectionLeg2;
	///腿2合约代码
	TFocusFtdcInstrumentIDType	InstrLeg2;
	///腿1腿2比例
	TFocusFtdcMoneyType	LegPer;
	///策略开始执行时间
	TFocusFtdcTimeType	StartTradingTime;
	///策略结束执行时间
	TFocusFtdcTimeType	EndTradingTime;
	///检查时间间隔
	TFocusFtdcVolumeType	TimeAvail;
	///目标交易量
	TFocusFtdcVolumeType	TargetTradeVolume;
	///报单类型
	TFocusFtdcStockStrategyPriceType	OrderPriceType;
	///算法类型
	TFocusFtdcVolumeType	AlgoType;
	///价差
	TFocusFtdcPriceType	SpreadPrice;
	///每次下单数量
	TFocusFtdcVolumeType	EachTrdvolume;
	///是否交易
	TFocusFtdcBoolType	StrategyIsTrading;
	///缺乏流动性标识
	TFocusFtdcVolumeType	LiquidLack;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///操作备注
	TFocusFtdcDepositNoteType	Note;
};

///跨期策略订单详情
struct CFocusFtdcInnerSpreadInstrStrategyField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///交易所1代码
	TFocusFtdcExchangeIDType	ExchangeIDLeg1;
	///买卖方向1
	TFocusFtdcDirectionType	DirectionLeg1;
	///腿1合约代码
	TFocusFtdcInstrumentIDType	InstrLeg1;
	///交易所2代码
	TFocusFtdcExchangeIDType	ExchangeIDLeg2;
	///买卖方向2
	TFocusFtdcDirectionType	DirectionLeg2;
	///腿2合约代码
	TFocusFtdcInstrumentIDType	InstrLeg2;
	///腿1腿2比例
	TFocusFtdcMoneyType	LegPer;
	///策略开始执行时间
	TFocusFtdcTimeType	StartTradingTime;
	///策略结束执行时间
	TFocusFtdcTimeType	EndTradingTime;
	///检查时间间隔
	TFocusFtdcVolumeType	TimeAvail;
	///目标交易量
	TFocusFtdcVolumeType	TargetTradeVolume;
	///报单类型
	TFocusFtdcStockStrategyPriceType	OrderPriceType;
	///算法类型
	TFocusFtdcVolumeType	AlgoType;
	///价差
	TFocusFtdcPriceType	SpreadPrice;
	///每次下单数量
	TFocusFtdcVolumeType	EachTrdvolume;
	///是否交易
	TFocusFtdcBoolType	StrategyIsTrading;
	///缺乏流动性标识
	TFocusFtdcVolumeType	LiquidLack;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///操作备注
	TFocusFtdcDepositNoteType	Note;
	///最新操作时间
	TFocusFtdcTimeType	LastOperTime;
	///买完成比例
	TFocusFtdcMoneyType	SignalLastPer;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
};

///盘中list请求域
struct CFocusFtdcTZeroHighStockStrategyField
{
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///股票合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///TZero需要改变的股数
	TFocusFtdcVolumeType	TZeroGapVolume;
	///股票下单类型
	TFocusFtdcStockStrategyPriceType	TZeroStockPriceType;
	///TZero最晚结束时间
	TFocusFtdcTimeType	TZeroEndOperTime;
	///TZero下单上限价格
	TFocusFtdcPriceType	TZeroUpperEndPrice;
	///TZero下单下限价格
	TFocusFtdcPriceType	TZeroLowerEndPrice;
	///t0最新设置时间
	TFocusFtdcTimeType	TZeroLastOperTime;
};

///跟随期货初始总资金
struct CFocusFtdcFlowerFutureTargetMoneyField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
	///最新操作时间
	TFocusFtdcTimeType	LastOperTime;
	///初始化预分配换仓总资金
	TFocusFtdcMoneyType	FlowerFutureTarMoney;
	///是否生效
	TFocusFtdcSwitchFlagType	WholeSwitch;
};

///母单信息
struct CFocusFtdcParentOrderField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///母单资金代码
	TFocusFtdcInvestorIDType	InvestorID;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///算法策略类型(Twap,11,Vwap 12)
	TFocusFtdcVolumeType	AlgoStrategyType;
	///策略开始日期(YYYYMMDD)
	TFocusFtdcTradingDayType	StrategyStartDay;
	///策略停止日期(YYYYMMDD)
	TFocusFtdcTradingDayType	StrategyEndDay;
	///策略开始时间(HH:mm:ss)
	TFocusFtdcTimeType	StrategyStartTime;
	///策略停止时间(HH:mm:ss)
	TFocusFtdcTimeType	StrategyEndTime;
	///保守->激进 1--5
	TFocusFtdcNumberType	style;
	///最大市场占比 TWAP/VWAP (0, 50]
	TFocusFtdcRatioType	maxVolumeP;
	///最小挂单量，默认为0
	TFocusFtdcVolumeType	minDisplaySize;
	///最大挂单量（单一档位），默认为0
	TFocusFtdcVolumeType	displaySize;
	///量比统计口径，默认为限价内。限价内 - 0， 全市场 - 1
	TFocusFtdcVolumeType	countVolInLimitPx;
	///重启时重置量比。true - 1, false - 0
	TFocusFtdcVolumeType	resetVolOnAmend;
	///价格限制，默认为0
	TFocusFtdcPriceType	limitPrice;
	///相对限价基准
	TFocusFtdcVolumeType	relativePriceLimitBase;
	///相对限价偏移单位
	TFocusFtdcVolumeType	relativePriceLimitType;
	///相对限价偏移量
	TFocusFtdcPriceTickType	relativePriceLimitOffset;
	///是否进价差，默认进价差
	TFocusFtdcVolumeType	stepSpread;
	///涨跌停动作，涨跌停时可暂停、加速
	TFocusFtdcVolumeType	optOnExtreme;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///方向
	TFocusFtdcDirectionType	Direction;
	///总数量
	TFocusFtdcVolumeType	orderQty;
	///总金额
	TFocusFtdcMoneyType	orderAmt;
	///母单推送日期
	TFocusFtdcTradingDayType	TradingDay;
	///母单推送时间
	TFocusFtdcTimeType	LastOperTime;
	///用户自定义域(保留字段)
	TFocusFtdcCustomType	UserCustom;
	///备注(保留字段)
	TFocusFtdcDepositNoteType	Note;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
};

///母单操作信息
struct CFocusFtdcParentOrderActionField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///操作选项
	TFocusFtdcVolumeType	ActionOption;
};

///修改母单信息
struct CFocusFtdcAmendParentOrderField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///母单资金代码
	TFocusFtdcInvestorIDType	InvestorID;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///算法策略类型(Twap,11,Vwap 12)
	TFocusFtdcVolumeType	AlgoStrategyType;
	///策略开始日期(YYYYMMDD)
	TFocusFtdcTradingDayType	StrategyStartDay;
	///策略停止日期(YYYYMMDD)
	TFocusFtdcTradingDayType	StrategyEndDay;
	///策略开始时间(HH:mm:ss)
	TFocusFtdcTimeType	StrategyStartTime;
	///策略停止时间(HH:mm:ss)
	TFocusFtdcTimeType	StrategyEndTime;
	///保守->激进 1--5
	TFocusFtdcNumberType	style;
	///最大市场占比 TWAP/VWAP (0, 50]
	TFocusFtdcRatioType	maxVolumeP;
	///最小挂单量，默认为0
	TFocusFtdcVolumeType	minDisplaySize;
	///最大挂单量（单一档位），默认为0
	TFocusFtdcVolumeType	displaySize;
	///量比统计口径，默认为限价内。限价内 - 0， 全市场 - 1
	TFocusFtdcVolumeType	countVolInLimitPx;
	///重启时重置量比。true - 1, false - 0
	TFocusFtdcVolumeType	resetVolOnAmend;
	///价格限制，默认为0
	TFocusFtdcPriceType	limitPrice;
	///相对限价基准
	TFocusFtdcVolumeType	relativePriceLimitBase;
	///相对限价偏移单位
	TFocusFtdcVolumeType	relativePriceLimitType;
	///相对限价偏移量
	TFocusFtdcPriceTickType	relativePriceLimitOffset;
	///是否进价差，默认进价差
	TFocusFtdcVolumeType	stepSpread;
	///涨跌停动作，涨跌停时可暂停、加速
	TFocusFtdcVolumeType	optOnExtreme;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///方向
	TFocusFtdcDirectionType	Direction;
	///总数量
	TFocusFtdcVolumeType	orderQty;
	///总金额
	TFocusFtdcMoneyType	orderAmt;
	///母单推送日期
	TFocusFtdcTradingDayType	TradingDay;
	///母单推送时间
	TFocusFtdcTimeType	LastOperTime;
	///用户自定义域(保留字段)
	TFocusFtdcCustomType	UserCustom;
	///备注(保留字段)
	TFocusFtdcDepositNoteType	Note;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
};

///母单操作手动操作信息
struct CFocusFtdcExtraManualParentOrderField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///母单用户代码
	TFocusFtdcInvestorIDType	InvestorID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///人工单数量
	TFocusFtdcVolumeType	sliceQty;
	///人工单价格
	TFocusFtdcPriceType	slicePrice;
	///人工单特别备注(保留字段)
	TFocusFtdcCustomType	UserCustom;
};

///发送母单进展详细信息
struct CFocusFtdcParentDetialUpdateMessageField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
	///更新日期
	TFocusFtdcTradingDayType	transactDay;
	///更新时间
	TFocusFtdcTimeType	transactTime;
	///策略状态
	TFocusFtdcVolumeType	strategyStatus;
	///暂停原因
	TFocusFtdcStrategyMessageNoteType	pauseReason;
	///方向
	TFocusFtdcDirectionType	Direction;
	///总数量
	TFocusFtdcVolumeType	orderQty;
	///成交数量
	TFocusFtdcVolumeType	knockQty;
	///成交金额
	TFocusFtdcMoneyType	knockAmt;
	///清算金额
	TFocusFtdcPriceType	knockAmtWithFee;
	///母单状态
	TFocusFtdcVolumeType	orderStatus;
	///平均价格
	TFocusFtdcPriceType	avgPrice;
	///市场TWAP均价
	TFocusFtdcPriceType	marketTwap;
	///市场VWAP均价
	TFocusFtdcPriceType	marketVwap;
	///到达价 
	TFocusFtdcPriceType	arrivalPrice;
	///均价偏差_T 
	TFocusFtdcRatioType	avgOffset_T;
	///均价偏差_V 
	TFocusFtdcRatioType	avgOffset_V;
	///均价偏差_A 
	TFocusFtdcRatioType	avgOffset_A;
	///真实参与率 
	TFocusFtdcRatioType	realParticipateRate;
	///撤单率 
	TFocusFtdcRatioType	cancelRate;
	///平均挂单时长 
	TFocusFtdcTimeValueType	avgOpenTime;
	///被动成交率 
	TFocusFtdcRatioType	passiveRate;
	///序列号 
	TFocusFtdcOrderLocalIDType	serialNum;
	///拒绝原因 
	TFocusFtdcErrorMsgType	failReason;
	///目标进度 
	TFocusFtdcRatioType	targetProgress;
	///成交比例 
	TFocusFtdcRatioType	knockPercent;
	///进度偏差 
	TFocusFtdcRatioType	progressOffset;
	///重要性 
	TFocusFtdcVolumeType	pushFlag;
	///错误代码
	TFocusFtdcErrorIDType	ErrorID;
	///功能号
	TFocusFtdcVolumeType	FunctionID;
	///策略开始时间(HH:mm:ss)
	TFocusFtdcTimeType	StrategyStartTime;
	///策略停止时间(HH:mm:ss)
	TFocusFtdcTimeType	StrategyEndTime;
};

///产品代码查询请求
struct CFocusFtdcAPIQryMarketTradingTimeField
{
	///市场id
	TFocusFtdcExchangeIDType	ExchangeID;
	///市场名称
	TFocusFtdcTimeType	ExchangeName;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
};

///市场交易时间段信息
struct CFocusFtdcMarketTradingPeriodInfoField
{
	///市场id
	TFocusFtdcExchangeIDType	ExchangeID;
	///市场名称
	TFocusFtdcTimeType	ExchangeName;
	///产品名称
	TFocusFtdcProductIDType	ProductID;
	///起始时间
	TFocusFtdcTimeType	TpStart;
	///结束时间
	TFocusFtdcTimeType	TpEnd;
	///类型标志
	TFocusFtdcTpFlagType	Flags;
};

///算法2股票期货对冲关系表
struct CFocusFtdcFutureStrategyTotalSecondRelationField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///股票策略当前是否交易
	TFocusFtdcBoolType	StockStrategyIsTrading;
	///期货交易所代码
	TFocusFtdcExchangeIDType	FutureExchangeID;
	///期货合约代码
	TFocusFtdcInstrumentIDType	FutureInstrumentID;
	///期货买卖方向
	TFocusFtdcDirectionType	FutureDirection;
	///期货报单类型
	TFocusFtdcStockStrategyPriceType	FuturePriceType;
	///对应期货当前是否交易（换仓默认开关无效）
	TFocusFtdcBoolType	FutureIsTrading;
	///期货资金账号
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///期货默认检查时间间隔
	TFocusFtdcNumberType	FutureTimeAvail;
	///期货间隔手数
	TFocusFtdcVolumeType	FutureAvailAmount;
	///期货算法类型
	TFocusFtdcVolumeType	FutureAlgoType;
	///指数交易所
	TFocusFtdcExchangeIDType	IndexExchangeID;
	///指数合约
	TFocusFtdcInstrumentIDType	IndexInstrumentID;
	///基差
	TFocusFtdcPriceType	SpreadPrice;
	///期货总下单手数
	TFocusFtdcVolumeType	FutureAmount;
	///List中price的价格类型
	TFocusFtdcListPriceTypeType	ListPriceType;
	///期现下单匹配度(0~1)
	TFocusFtdcRatioType	FuStockRelation;
	///加减仓起始时间
	TFocusFtdcTimeType	TpStart;
	///加减仓结束时间
	TFocusFtdcTimeType	TpEnd;
};

///算法2股票期货对冲内部表详情
struct CFocusFtdcInnerFutureStrategyTotalSecondRelationField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///该股票用哪个资金账号去下单
	TFocusFtdcInvestorIDType	StockInvestorID;
	///股票策略ID
	TFocusFtdcStrategyIDType	StockStrategyID;
	///股票策略当前是否交易
	TFocusFtdcBoolType	StockStrategyIsTrading;
	///期货交易所代码
	TFocusFtdcExchangeIDType	FutureExchangeID;
	///期货合约代码
	TFocusFtdcInstrumentIDType	FutureInstrumentID;
	///期货买卖方向
	TFocusFtdcDirectionType	FutureDirection;
	///期货报单类型
	TFocusFtdcStockStrategyPriceType	FuturePriceType;
	///对应期货当前是否交易（换仓默认开关无效）
	TFocusFtdcBoolType	FutureIsTrading;
	///期货资金账号
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///期货默认检查时间间隔
	TFocusFtdcNumberType	FutureTimeAvail;
	///期货间隔手数
	TFocusFtdcVolumeType	FutureAvailAmount;
	///期货算法类型
	TFocusFtdcVolumeType	FutureAlgoType;
	///指数交易所
	TFocusFtdcExchangeIDType	IndexExchangeID;
	///指数合约
	TFocusFtdcInstrumentIDType	IndexInstrumentID;
	///基差
	TFocusFtdcPriceType	SpreadPrice;
	///期货总下单手数
	TFocusFtdcVolumeType	FutureAmount;
	///List中price的价格类型
	TFocusFtdcListPriceTypeType	ListPriceType;
	///期现下单匹配度(0~1)
	TFocusFtdcRatioType	FuStockRelation;
	///加减仓起始时间
	TFocusFtdcTimeType	TpStart;
	///加减仓结束时间
	TFocusFtdcTimeType	TpEnd;
	///操作备注
	TFocusFtdcDepositNoteType	Note;
	///最新买总成交总量
	TFocusFtdcMoneyType	LastTotalBuyMoney;
	///最新卖总成交总量
	TFocusFtdcMoneyType	LastTotalSellMoney;
	///最新需要买的总金额
	TFocusFtdcMoneyType	LastTotalNeedBuyMoney;
	///最新需要卖的总金额
	TFocusFtdcMoneyType	LastTotalNeedSellMoney;
	///最新期货对冲操作时间
	TFocusFtdcTimeType	LastFuOperTime;
	///已完成对冲总交易量
	TFocusFtdcVolumeType	LastFuTarNetPosition;
	///对冲操作备注
	TFocusFtdcDepositNoteType	FutureNote;
	///期货价差对冲是否需要检查
	TFocusFtdcBoolType	FutureSpreadNeedCheck;
	///开仓那刻期货价格
	TFocusFtdcPriceType	OpenFuInstrPrice;
	///上次完成的总交易量
	TFocusFtdcVolumeType	BeforeLastFuTarNetPosition;
	///现货对于期货手数
	TFocusFtdcRatioType	NetFuPosition;
	///实时基差
	TFocusFtdcPriceType	RealTimeSpreadPrice;
	///实时指数价格
	TFocusFtdcPriceType	RealIndexPrice;
	///实时期货价格
	TFocusFtdcPriceType	RealFuturePrice;
	///最新期货对冲操作时间
	TFocusFtdcTimeType	LastHedgeFuOperTime;
	///期货实际匹配数量
	TFocusFtdcRatioType	DoubleFutureAmount;
};

///期货算法交易订单键值
struct CFocusFtdcParentOrderIndexField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
};

///母单算法基本信息参数
struct CFocusFtdcParentOrderStaticParamField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///保守->激进 1--5
	TFocusFtdcNumberType	style;
	///最大市场占比 TWAP/VWAP (0, 0.5]
	TFocusFtdcRatioType	maxVolumeP;
	///最小挂单量，默认为0
	TFocusFtdcVolumeType	minDisplaySize;
	///最大挂单量（单一档位），默认为0
	TFocusFtdcVolumeType	displaySize;
	///量比统计口径，默认为限价内。限价内 - 0， 全市场 - 1
	TFocusFtdcVolumeType	countVolInLimitPx;
	///重启时重置量比。true - 1, false - 0
	TFocusFtdcVolumeType	resetVolOnAmend;
	///价格限制，默认为0
	TFocusFtdcPriceType	limitPrice;
	///相对限价基准 
	TFocusFtdcVolumeType	relativePriceLimitBase;
	///相对限价偏移单位 枚举型 
	TFocusFtdcVolumeType	relativePriceLimitType;
	///相对限价偏移量  double
	TFocusFtdcPriceTickType	relativePriceLimitOffset;
	///是否进价差，默认进价差 0，不进，1 进
	TFocusFtdcVolumeType	stepSpread;
	///涨跌停动作，涨跌停时可暂停、加速，0是没动作，1是加速，2是暂停
	TFocusFtdcVolumeType	optOnExtreme;
};

///期现账户关系
struct CFocusFtdcFuSkAccountRelationField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///现货投资者编号
	TFocusFtdcInvestorIDType	StockInvestorID;
	///期货投资者编号
	TFocusFtdcInvestorIDType	FutureInvestorID;
	///期货资金密码
	TFocusFtdcPasswordType	FuturePasswd;
};

///批量报单录入
struct CFocusFtdcBatchInputOrderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///批量用户本地报单号
	TFocusFtdcBatchUserOrderLocalIDType	UserOrderLocalID;
	///批量用户自定义域
	TFocusFtdcBatchCustomType	UserCustom;
	///批量交易所代码
	TFocusFtdcBatchExchangeIDType	ExchangeID;
	///批量合约代码
	TFocusFtdcBatchInstrumentIDType	InstrumentID;
	///批量买卖方向
	TFocusFtdcBatchDirectionType	Direction;
	///批量开平标志
	TFocusFtdcBatchOffsetFlagType	OffsetFlag;
	///批量价格
	TFocusFtdcBatchPriceType	LimitPrice;
	///批量数量
	TFocusFtdcBatchVolumeType	Volume;
};

///批量报单操作
struct CFocusFtdcBatchOrderActionField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///批量用户本地报单号
	TFocusFtdcBatchUserOrderLocalIDType	UserOrderLocalID;
	///批量用户自定义域
	TFocusFtdcBatchCustomType	UserCustom;
	///批量交易所代码
	TFocusFtdcBatchExchangeIDType	ExchangeID;
	///批量报单编号(768)
	TFocusFtdcBatchOrderSysIDType	OrderSysID;
	///批量合约代码
	TFocusFtdcBatchInstrumentIDType	InstrumentID;
	///批量本次撤单操作的本地编号
	TFocusFtdcBatchUserOrderLocalIDType	UserOrderActionLocalID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
};

///投资者账户席位基本信息
struct CFocusFtdcUserInvestorSeatBaseField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///旧操作员密码
	TFocusFtdcPasswordType	OldUserPassword;
	///新操作员密码
	TFocusFtdcPasswordType	NewUserPassword;
	///席位代码
	TFocusFtdcSeatIDType	SeatID;
	///旧席位密码
	TFocusFtdcPasswordType	OldSeatPassword;
	///新席位密码
	TFocusFtdcPasswordType	NewSeatPassword;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///旧资金账号密码
	TFocusFtdcPasswordType	OldInvestorPasswd;
	///新资金账号密码
	TFocusFtdcPasswordType	NewInvestorPasswd;
};

///期货交易详情算法交易订单键值
struct CFocusFtdcParentOrderDetialIndexField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
};

///未完成母单信息
struct CFocusFtdcUnFinshPutureOrderField
{
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///策略ID号
	TFocusFtdcStrategyIDType	StrategyID;
	///目标净持仓量
	TFocusFtdcVolumeType	TargetNetPosition;
	///系统母单报单编号(母单ID,主键,子单带回)
	TFocusFtdcOrderLocalIDType	AlgoParentOrderSysID;
};



#endif
