# encoding: UTF-8

structDict = {}

#//////////////////////////////////////////////////////////////////////
#@system QuantDo Platform
#@company 山西证券股份有限公司  金融衍生产品部
#@author 顾浩
#@file FocusFtdcUserApiStruct.h
#@brief 定义了客户端接口使用的业务数据结构
#@history 
#//////////////////////////////////////////////////////////////////////










#响应信息
CFocusFtdcRspInfoField = {}
#错误代码
CFocusFtdcRspInfoField["ErrorID"] = "int"
#错误信息
CFocusFtdcRspInfoField["ErrorMsg"] = "string"
structDict['CFocusFtdcRspInfoField'] = CFocusFtdcRspInfoField


#系统用户登录请求
CFocusFtdcReqUserLoginField = {}
#交易日
CFocusFtdcReqUserLoginField["TradingDay"] = "string"
#交易用户代码
CFocusFtdcReqUserLoginField["UserID"] = "string"
#经纪公司编号
CFocusFtdcReqUserLoginField["BrokerID"] = "string"
#密码
CFocusFtdcReqUserLoginField["Password"] = "string"
#用户端产品信息
CFocusFtdcReqUserLoginField["UserProductInfo"] = "string"
#接口端产品信息
CFocusFtdcReqUserLoginField["InterfaceProductInfo"] = "string"
#协议信息
CFocusFtdcReqUserLoginField["ProtocolInfo"] = "string"
#IP地址
CFocusFtdcReqUserLoginField["IPAddress"] = "string"
#Mac地址
CFocusFtdcReqUserLoginField["MacAddress"] = "string"
#数据中心代码
CFocusFtdcReqUserLoginField["DataCenterID"] = "int"
#动态密码
CFocusFtdcReqUserLoginField["OneTimePassword"] = "string"
#终端IP地址
CFocusFtdcReqUserLoginField["ClientIPAddress"] = "string"
#授权编码
CFocusFtdcReqUserLoginField["AuthCode"] = "string"
structDict['CFocusFtdcReqUserLoginField'] = CFocusFtdcReqUserLoginField


#系统用户登录应答
CFocusFtdcRspUserLoginField = {}
#交易日
CFocusFtdcRspUserLoginField["TradingDay"] = "string"
#经纪公司编号
CFocusFtdcRspUserLoginField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcRspUserLoginField["UserID"] = "string"
#登录成功时间
CFocusFtdcRspUserLoginField["LoginTime"] = "string"
#用户最大本地报单号
CFocusFtdcRspUserLoginField["MaxOrderLocalID"] = "string"
#交易系统名称
CFocusFtdcRspUserLoginField["TradingSystemName"] = "string"
#数据中心代码
CFocusFtdcRspUserLoginField["DataCenterID"] = "int"
#会员私有流当前长度
CFocusFtdcRspUserLoginField["PrivateFlowSize"] = "int"
#交易员私有流当前长度
CFocusFtdcRspUserLoginField["UserFlowSize"] = "int"
#登录附加信息
CFocusFtdcRspUserLoginField["LoginInfo"] = "string"
#会话编号
CFocusFtdcRspUserLoginField["SessionID"] = "int"
#前置编号
CFocusFtdcRspUserLoginField["FrontID"] = "int"
structDict['CFocusFtdcRspUserLoginField'] = CFocusFtdcRspUserLoginField


#用户登出请求
CFocusFtdcReqUserLogoutField = {}
#经纪公司编号
CFocusFtdcReqUserLogoutField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcReqUserLogoutField["UserID"] = "string"
structDict['CFocusFtdcReqUserLogoutField'] = CFocusFtdcReqUserLogoutField


#用户登出请求
CFocusFtdcRspUserLogoutField = {}
#经纪公司编号
CFocusFtdcRspUserLogoutField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcRspUserLogoutField["UserID"] = "string"
structDict['CFocusFtdcRspUserLogoutField'] = CFocusFtdcRspUserLogoutField


#强制用户退出
CFocusFtdcForceUserExitField = {}
#经纪公司编号
CFocusFtdcForceUserExitField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcForceUserExitField["UserID"] = "string"
structDict['CFocusFtdcForceUserExitField'] = CFocusFtdcForceUserExitField


#用户口令修改
CFocusFtdcUserPasswordUpdateField = {}
#经纪公司编号
CFocusFtdcUserPasswordUpdateField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcUserPasswordUpdateField["UserID"] = "string"
#旧密码
CFocusFtdcUserPasswordUpdateField["OldPassword"] = "string"
#新密码
CFocusFtdcUserPasswordUpdateField["NewPassword"] = "string"
structDict['CFocusFtdcUserPasswordUpdateField'] = CFocusFtdcUserPasswordUpdateField


#输入报单
CFocusFtdcInputOrderField = {}
#经纪公司编号
CFocusFtdcInputOrderField["BrokerID"] = "string"
#投资者编号
CFocusFtdcInputOrderField["InvestorID"] = "string"
#用户代码
CFocusFtdcInputOrderField["UserID"] = "string"
#用户本地报单号
CFocusFtdcInputOrderField["UserOrderLocalID"] = "string"
#用户自定义域
CFocusFtdcInputOrderField["UserCustom"] = "string"
#交易所代码
CFocusFtdcInputOrderField["ExchangeID"] = "string"
#系统报单编号
CFocusFtdcInputOrderField["OrderSysID"] = "string"
#股票委托批号(仅批量委托有效)
CFocusFtdcInputOrderField["BatchNum"] = "string"
#合约代码
CFocusFtdcInputOrderField["InstrumentID"] = "string"
#合约名称
CFocusFtdcInputOrderField["InstrumentName"] = "string"
#报单类型
CFocusFtdcInputOrderField["OrderPriceType"] = "char"
#买卖方向
CFocusFtdcInputOrderField["Direction"] = "char"
#开平标志
CFocusFtdcInputOrderField["OffsetFlag"] = "char"
#投机套保标志
CFocusFtdcInputOrderField["HedgeFlag"] = "char"
#价格
CFocusFtdcInputOrderField["LimitPrice"] = "float"
#数量
CFocusFtdcInputOrderField["Volume"] = "int"
#有效期类型
CFocusFtdcInputOrderField["TimeCondition"] = "char"
#GTD日期
CFocusFtdcInputOrderField["GTDDate"] = "string"
#成交量类型
CFocusFtdcInputOrderField["VolumeCondition"] = "char"
#最小成交量
CFocusFtdcInputOrderField["MinVolume"] = "int"
#止损价
CFocusFtdcInputOrderField["StopPrice"] = "float"
#强平原因
CFocusFtdcInputOrderField["ForceCloseReason"] = "char"
#自动挂起标志
CFocusFtdcInputOrderField["IsAutoSuspend"] = "int"
#业务单元
CFocusFtdcInputOrderField["BusinessUnit"] = "string"
#业务类别
CFocusFtdcInputOrderField["BusinessType"] = "char"
structDict['CFocusFtdcInputOrderField'] = CFocusFtdcInputOrderField


#报单操作
CFocusFtdcOrderActionField = {}
#经纪公司编号
CFocusFtdcOrderActionField["BrokerID"] = "string"
#投资者编号
CFocusFtdcOrderActionField["InvestorID"] = "string"
#用户代码
CFocusFtdcOrderActionField["UserID"] = "string"
#用户本地报单号
CFocusFtdcOrderActionField["UserOrderLocalID"] = "string"
#用户自定义域
CFocusFtdcOrderActionField["UserCustom"] = "string"
#交易所代码
CFocusFtdcOrderActionField["ExchangeID"] = "string"
#报单编号
CFocusFtdcOrderActionField["OrderSysID"] = "string"
#股票委托批号(仅批量委托有效)
CFocusFtdcOrderActionField["BatchNum"] = "string"
#合约代码
CFocusFtdcOrderActionField["InstrumentID"] = "string"
#本次撤单操作的本地编号
CFocusFtdcOrderActionField["UserOrderActionLocalID"] = "string"
#报单操作标志
CFocusFtdcOrderActionField["ActionFlag"] = "char"
#价格
CFocusFtdcOrderActionField["LimitPrice"] = "float"
#数量变化
CFocusFtdcOrderActionField["VolumeChange"] = "int"
#前置编号
CFocusFtdcOrderActionField["FrontID"] = "int"
#会话编号
CFocusFtdcOrderActionField["SessionID"] = "int"
structDict['CFocusFtdcOrderActionField'] = CFocusFtdcOrderActionField


#内存表导出
CFocusFtdcMemDBField = {}
#内存表名
CFocusFtdcMemDBField["MemTableName"] = "string"
structDict['CFocusFtdcMemDBField'] = CFocusFtdcMemDBField


#投资者资金帐户出入金请求
CFocusFtdcReqAccountDepositField = {}
#经纪公司编号
CFocusFtdcReqAccountDepositField["BrokerID"] = "string"
#资金流水号
CFocusFtdcReqAccountDepositField["AccountSeqNo"] = "string"
#资金帐号
CFocusFtdcReqAccountDepositField["AccountID"] = "string"
#投资者编号
CFocusFtdcReqAccountDepositField["InvestorID"] = "string"
#金额
CFocusFtdcReqAccountDepositField["Amount"] = "float"
#出入金方向
CFocusFtdcReqAccountDepositField["AmountDirection"] = "char"
#出入金日期
CFocusFtdcReqAccountDepositField["Date"] = "string"
#出入金时间
CFocusFtdcReqAccountDepositField["Time"] = "string"
#出入金备注
CFocusFtdcReqAccountDepositField["Note"] = "string"
#是否成功
CFocusFtdcReqAccountDepositField["isSuccess"] = "int"
#用户代码
CFocusFtdcReqAccountDepositField["UserID"] = "string"
structDict['CFocusFtdcReqAccountDepositField'] = CFocusFtdcReqAccountDepositField


#投资者资金帐户出入金应答
CFocusFtdcRspAccountDepositField = {}
#经纪公司编号
CFocusFtdcRspAccountDepositField["BrokerID"] = "string"
#投资者编号
CFocusFtdcRspAccountDepositField["InvestorID"] = "string"
#资金帐号
CFocusFtdcRspAccountDepositField["AccountID"] = "string"
#资金流水号
CFocusFtdcRspAccountDepositField["AccountSeqNo"] = "string"
#金额
CFocusFtdcRspAccountDepositField["Amount"] = "float"
#出入金方向
CFocusFtdcRspAccountDepositField["AmountDirection"] = "char"
#可用资金
CFocusFtdcRspAccountDepositField["Available"] = "float"
#结算准备金
CFocusFtdcRspAccountDepositField["Balance"] = "float"
#用户代码
CFocusFtdcRspAccountDepositField["UserID"] = "string"
structDict['CFocusFtdcRspAccountDepositField'] = CFocusFtdcRspAccountDepositField


#实时上场
CFocusFtdcTBCommandField = {}
#DB命令序号
CFocusFtdcTBCommandField["CommandNo"] = "int"
#操作日期
CFocusFtdcTBCommandField["CommandDate"] = "string"
#操作时间
CFocusFtdcTBCommandField["CommandTime"] = "string"
#DB命令类型
CFocusFtdcTBCommandField["CommandType"] = "string"
#字段名
CFocusFtdcTBCommandField["FieldName"] = "string"
#字段内容
CFocusFtdcTBCommandField["FieldContent"] = "string"
structDict['CFocusFtdcTBCommandField'] = CFocusFtdcTBCommandField


#出入金结果
CFocusFtdcInvestorAccountDepositResField = {}
#经纪公司编号
CFocusFtdcInvestorAccountDepositResField["BrokerID"] = "string"
#投资者编号
CFocusFtdcInvestorAccountDepositResField["InvestorID"] = "string"
#资金帐号
CFocusFtdcInvestorAccountDepositResField["AccountID"] = "string"
#资金流水号
CFocusFtdcInvestorAccountDepositResField["AccountSeqNo"] = "string"
#金额
CFocusFtdcInvestorAccountDepositResField["Amount"] = "float"
#出入金方向
CFocusFtdcInvestorAccountDepositResField["AmountDirection"] = "char"
#可用资金
CFocusFtdcInvestorAccountDepositResField["Available"] = "float"
#结算准备金
CFocusFtdcInvestorAccountDepositResField["Balance"] = "float"
#用户代码
CFocusFtdcInvestorAccountDepositResField["UserID"] = "string"
structDict['CFocusFtdcInvestorAccountDepositResField'] = CFocusFtdcInvestorAccountDepositResField


#合约状态
CFocusFtdcInstrumentStatusField = {}
#交易所代码
CFocusFtdcInstrumentStatusField["ExchangeID"] = "string"
#品种代码
CFocusFtdcInstrumentStatusField["ProductID"] = "string"
#品种名称
CFocusFtdcInstrumentStatusField["ProductName"] = "string"
#合约代码
CFocusFtdcInstrumentStatusField["InstrumentID"] = "string"
#合约名称
CFocusFtdcInstrumentStatusField["InstrumentName"] = "string"
#交割年份
CFocusFtdcInstrumentStatusField["DeliveryYear"] = "int"
#交割月
CFocusFtdcInstrumentStatusField["DeliveryMonth"] = "int"
#限价单最大下单量
CFocusFtdcInstrumentStatusField["MaxLimitOrderVolume"] = "float"
#限价单最小下单量
CFocusFtdcInstrumentStatusField["MinLimitOrderVolume"] = "float"
#市价单最大下单量
CFocusFtdcInstrumentStatusField["MaxMarketOrderVolume"] = "float"
#市价单最小下单量
CFocusFtdcInstrumentStatusField["MinMarketOrderVolume"] = "float"
#股票每次最少买入量
CFocusFtdcInstrumentStatusField["MinStkBuyQty"] = "float"
#股票每次最少卖出量
CFocusFtdcInstrumentStatusField["MinStkSellQty"] = "float"
#数量乘数
CFocusFtdcInstrumentStatusField["VolumeMultiple"] = "int"
#报价单位
CFocusFtdcInstrumentStatusField["PriceTick"] = "float"
#币种
CFocusFtdcInstrumentStatusField["Currency"] = "string"
#多头限仓
CFocusFtdcInstrumentStatusField["LongPosLimit"] = "float"
#空头限仓
CFocusFtdcInstrumentStatusField["ShortPosLimit"] = "float"
#跌停板价
CFocusFtdcInstrumentStatusField["LowerLimitPrice"] = "float"
#涨停板价
CFocusFtdcInstrumentStatusField["UpperLimitPrice"] = "float"
#昨结算
CFocusFtdcInstrumentStatusField["PreSettlementPrice"] = "float"
#合约交易状态
CFocusFtdcInstrumentStatusField["InstrumentStatus"] = "char"
#创建日
CFocusFtdcInstrumentStatusField["CreateDate"] = "string"
#上市日
CFocusFtdcInstrumentStatusField["OpenDate"] = "string"
#到期日
CFocusFtdcInstrumentStatusField["ExpireDate"] = "string"
#开始交割日
CFocusFtdcInstrumentStatusField["StartDelivDate"] = "string"
#最后交割日
CFocusFtdcInstrumentStatusField["EndDelivDate"] = "string"
#挂牌基准价
CFocusFtdcInstrumentStatusField["BasisPrice"] = "float"
#当前是否交易
CFocusFtdcInstrumentStatusField["IsTrading"] = "int"
#基础商品代码
CFocusFtdcInstrumentStatusField["UnderlyingInstrID"] = "string"
#基础商品乘数
CFocusFtdcInstrumentStatusField["UnderlyingMultiple"] = "int"
#持仓类型
CFocusFtdcInstrumentStatusField["PositionType"] = "char"
#执行价
CFocusFtdcInstrumentStatusField["StrikePrice"] = "float"
#期权类型
CFocusFtdcInstrumentStatusField["OptionsType"] = "char"
#汇率
CFocusFtdcInstrumentStatusField["ExchangeRate"] = "float"
#期权系列
CFocusFtdcInstrumentStatusField["OptionSeriesId"] = "string"
#产品类型
CFocusFtdcInstrumentStatusField["ProductClass"] = "char"
#期权行权方式
CFocusFtdcInstrumentStatusField["OptionsMode"] = "char"
#保证金算法类型
CFocusFtdcInstrumentStatusField["MarginCombType"] = "char"
structDict['CFocusFtdcInstrumentStatusField'] = CFocusFtdcInstrumentStatusField


#审批模式设置请求
CFocusFtdcAdviceRunModeField = {}
#经纪公司编号
CFocusFtdcAdviceRunModeField["BrokerID"] = "string"
#投资者编号
CFocusFtdcAdviceRunModeField["InvestorID"] = "string"
#用户代码
CFocusFtdcAdviceRunModeField["UserID"] = "string"
#自动或者手动
CFocusFtdcAdviceRunModeField["RunMode"] = "char"
structDict['CFocusFtdcAdviceRunModeField'] = CFocusFtdcAdviceRunModeField


#订阅合约状态
CFocusFtdcSubInstrumentStatusField = {}
#交易所代码
CFocusFtdcSubInstrumentStatusField["ExchangeID"] = "string"
#合约代码
CFocusFtdcSubInstrumentStatusField["InstrumentID"] = "string"
#合约交易状态
CFocusFtdcSubInstrumentStatusField["InstrumentStatus"] = "char"
#进入本状态时间
CFocusFtdcSubInstrumentStatusField["EnterTime"] = "string"
#进入本状态原因
CFocusFtdcSubInstrumentStatusField["EnterReason"] = "char"
structDict['CFocusFtdcSubInstrumentStatusField'] = CFocusFtdcSubInstrumentStatusField


#行情基础属性
CFocusFtdcMarketDataBaseField = {}
#交易日
CFocusFtdcMarketDataBaseField["TradingDay"] = "string"
#昨结算
CFocusFtdcMarketDataBaseField["PreSettlementPrice"] = "float"
#昨收盘
CFocusFtdcMarketDataBaseField["PreClosePrice"] = "float"
#昨持仓量
CFocusFtdcMarketDataBaseField["PreOpenInterest"] = "float"
#昨虚实度
CFocusFtdcMarketDataBaseField["PreDelta"] = "float"
#证券交易状态
CFocusFtdcMarketDataBaseField["StkOrderStatus"] = "char"
structDict['CFocusFtdcMarketDataBaseField'] = CFocusFtdcMarketDataBaseField


#行情静态属性
CFocusFtdcMarketDataStaticField = {}
#今开盘
CFocusFtdcMarketDataStaticField["OpenPrice"] = "float"
#最高价
CFocusFtdcMarketDataStaticField["HighestPrice"] = "float"
#最低价
CFocusFtdcMarketDataStaticField["LowestPrice"] = "float"
#今收盘
CFocusFtdcMarketDataStaticField["ClosePrice"] = "float"
#涨停板价
CFocusFtdcMarketDataStaticField["UpperLimitPrice"] = "float"
#跌停板价
CFocusFtdcMarketDataStaticField["LowerLimitPrice"] = "float"
#今结算
CFocusFtdcMarketDataStaticField["SettlementPrice"] = "float"
#今虚实度
CFocusFtdcMarketDataStaticField["CurrDelta"] = "float"
structDict['CFocusFtdcMarketDataStaticField'] = CFocusFtdcMarketDataStaticField


#行情最新成交属性
CFocusFtdcMarketDataLastMatchField = {}
#最新价
CFocusFtdcMarketDataLastMatchField["LastPrice"] = "float"
#数量
CFocusFtdcMarketDataLastMatchField["Volume"] = "int"
#成交金额
CFocusFtdcMarketDataLastMatchField["Turnover"] = "float"
#持仓量
CFocusFtdcMarketDataLastMatchField["OpenInterest"] = "float"
structDict['CFocusFtdcMarketDataLastMatchField'] = CFocusFtdcMarketDataLastMatchField


#行情最优价属性
CFocusFtdcMarketDataBestPriceField = {}
#申买价一
CFocusFtdcMarketDataBestPriceField["BidPrice1"] = "float"
#申买量一
CFocusFtdcMarketDataBestPriceField["BidVolume1"] = "int"
#申卖价一
CFocusFtdcMarketDataBestPriceField["AskPrice1"] = "float"
#申卖量一
CFocusFtdcMarketDataBestPriceField["AskVolume1"] = "int"
structDict['CFocusFtdcMarketDataBestPriceField'] = CFocusFtdcMarketDataBestPriceField


#行情申买二、三属性
CFocusFtdcMarketDataBid23Field = {}
#申买价二
CFocusFtdcMarketDataBid23Field["BidPrice2"] = "float"
#申买量二
CFocusFtdcMarketDataBid23Field["BidVolume2"] = "int"
#申买价三
CFocusFtdcMarketDataBid23Field["BidPrice3"] = "float"
#申买量三
CFocusFtdcMarketDataBid23Field["BidVolume3"] = "int"
structDict['CFocusFtdcMarketDataBid23Field'] = CFocusFtdcMarketDataBid23Field


#行情申卖二、三属性
CFocusFtdcMarketDataAsk23Field = {}
#申卖价二
CFocusFtdcMarketDataAsk23Field["AskPrice2"] = "float"
#申卖量二
CFocusFtdcMarketDataAsk23Field["AskVolume2"] = "int"
#申卖价三
CFocusFtdcMarketDataAsk23Field["AskPrice3"] = "float"
#申卖量三
CFocusFtdcMarketDataAsk23Field["AskVolume3"] = "int"
structDict['CFocusFtdcMarketDataAsk23Field'] = CFocusFtdcMarketDataAsk23Field


#行情申买四、五属性
CFocusFtdcMarketDataBid45Field = {}
#申买价四
CFocusFtdcMarketDataBid45Field["BidPrice4"] = "float"
#申买量四
CFocusFtdcMarketDataBid45Field["BidVolume4"] = "int"
#申买价五
CFocusFtdcMarketDataBid45Field["BidPrice5"] = "float"
#申买量五
CFocusFtdcMarketDataBid45Field["BidVolume5"] = "int"
structDict['CFocusFtdcMarketDataBid45Field'] = CFocusFtdcMarketDataBid45Field


#行情申卖四、五属性
CFocusFtdcMarketDataAsk45Field = {}
#申卖价四
CFocusFtdcMarketDataAsk45Field["AskPrice4"] = "float"
#申卖量四
CFocusFtdcMarketDataAsk45Field["AskVolume4"] = "int"
#申卖价五
CFocusFtdcMarketDataAsk45Field["AskPrice5"] = "float"
#申卖量五
CFocusFtdcMarketDataAsk45Field["AskVolume5"] = "int"
structDict['CFocusFtdcMarketDataAsk45Field'] = CFocusFtdcMarketDataAsk45Field


#行情更新时间属性
CFocusFtdcMarketDataUpdateTimeField = {}
#合约代码
CFocusFtdcMarketDataUpdateTimeField["InstrumentID"] = "string"
#最后修改时间
CFocusFtdcMarketDataUpdateTimeField["UpdateTime"] = "string"
#最后修改毫秒
CFocusFtdcMarketDataUpdateTimeField["UpdateMillisec"] = "int"
structDict['CFocusFtdcMarketDataUpdateTimeField'] = CFocusFtdcMarketDataUpdateTimeField


#深度行情
CFocusFtdcDepthMarketDataField = {}
#交易日
CFocusFtdcDepthMarketDataField["TradingDay"] = "string"
#昨结算
CFocusFtdcDepthMarketDataField["PreSettlementPrice"] = "float"
#昨收盘
CFocusFtdcDepthMarketDataField["PreClosePrice"] = "float"
#昨持仓量
CFocusFtdcDepthMarketDataField["PreOpenInterest"] = "float"
#昨虚实度
CFocusFtdcDepthMarketDataField["PreDelta"] = "float"
#证券交易状态
CFocusFtdcDepthMarketDataField["StkOrderStatus"] = "char"
#今开盘
CFocusFtdcDepthMarketDataField["OpenPrice"] = "float"
#最高价
CFocusFtdcDepthMarketDataField["HighestPrice"] = "float"
#最低价
CFocusFtdcDepthMarketDataField["LowestPrice"] = "float"
#今收盘
CFocusFtdcDepthMarketDataField["ClosePrice"] = "float"
#涨停板价
CFocusFtdcDepthMarketDataField["UpperLimitPrice"] = "float"
#跌停板价
CFocusFtdcDepthMarketDataField["LowerLimitPrice"] = "float"
#今结算
CFocusFtdcDepthMarketDataField["SettlementPrice"] = "float"
#今虚实度
CFocusFtdcDepthMarketDataField["CurrDelta"] = "float"
#最新价
CFocusFtdcDepthMarketDataField["LastPrice"] = "float"
#数量
CFocusFtdcDepthMarketDataField["Volume"] = "int"
#成交金额
CFocusFtdcDepthMarketDataField["Turnover"] = "float"
#持仓量
CFocusFtdcDepthMarketDataField["OpenInterest"] = "float"
#申买价一
CFocusFtdcDepthMarketDataField["BidPrice1"] = "float"
#申买量一
CFocusFtdcDepthMarketDataField["BidVolume1"] = "int"
#申卖价一
CFocusFtdcDepthMarketDataField["AskPrice1"] = "float"
#申卖量一
CFocusFtdcDepthMarketDataField["AskVolume1"] = "int"
#申买价二
CFocusFtdcDepthMarketDataField["BidPrice2"] = "float"
#申买量二
CFocusFtdcDepthMarketDataField["BidVolume2"] = "int"
#申买价三
CFocusFtdcDepthMarketDataField["BidPrice3"] = "float"
#申买量三
CFocusFtdcDepthMarketDataField["BidVolume3"] = "int"
#申卖价二
CFocusFtdcDepthMarketDataField["AskPrice2"] = "float"
#申卖量二
CFocusFtdcDepthMarketDataField["AskVolume2"] = "int"
#申卖价三
CFocusFtdcDepthMarketDataField["AskPrice3"] = "float"
#申卖量三
CFocusFtdcDepthMarketDataField["AskVolume3"] = "int"
#申买价四
CFocusFtdcDepthMarketDataField["BidPrice4"] = "float"
#申买量四
CFocusFtdcDepthMarketDataField["BidVolume4"] = "int"
#申买价五
CFocusFtdcDepthMarketDataField["BidPrice5"] = "float"
#申买量五
CFocusFtdcDepthMarketDataField["BidVolume5"] = "int"
#申卖价四
CFocusFtdcDepthMarketDataField["AskPrice4"] = "float"
#申卖量四
CFocusFtdcDepthMarketDataField["AskVolume4"] = "int"
#申卖价五
CFocusFtdcDepthMarketDataField["AskPrice5"] = "float"
#申卖量五
CFocusFtdcDepthMarketDataField["AskVolume5"] = "int"
#合约代码
CFocusFtdcDepthMarketDataField["InstrumentID"] = "string"
#最后修改时间
CFocusFtdcDepthMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CFocusFtdcDepthMarketDataField["UpdateMillisec"] = "int"
#交易所代码
CFocusFtdcDepthMarketDataField["ExchangeID"] = "string"
#总卖出数量
CFocusFtdcDepthMarketDataField["VolumeAskLot"] = "int"
#总买入数量
CFocusFtdcDepthMarketDataField["VolumeBidLot"] = "int"
structDict['CFocusFtdcDepthMarketDataField'] = CFocusFtdcDepthMarketDataField


#订阅合约的相关信息
CFocusFtdcSpecificInstrumentField = {}
#合约代码
CFocusFtdcSpecificInstrumentField["InstrumentID"] = "string"
structDict['CFocusFtdcSpecificInstrumentField'] = CFocusFtdcSpecificInstrumentField


#投资者权限
CFocusFtdcInvestorRightField = {}
#投资者编号
CFocusFtdcInvestorRightField["InvestorID"] = "string"
#是否使用净持仓报单,投顾账户有效
CFocusFtdcInvestorRightField["PositionType"] = "char"
#自成交处理方式,资金账户有效
CFocusFtdcInvestorRightField["SelfTradeAvoidType"] = "char"
#交易权限
CFocusFtdcInvestorRightField["TradingRight"] = "char"
#是否检查资金
CFocusFtdcInvestorRightField["CheckAccount"] = "int"
#是否检查持仓
CFocusFtdcInvestorRightField["CheckPosition"] = "int"
#报单是否报警
CFocusFtdcInvestorRightField["OrderWarning"] = "int"
#资金持仓是否上查
CFocusFtdcInvestorRightField["QryUpAccPosi"] = "int"
#投顾选择资金账户类型
CFocusFtdcInvestorRightField["DistributeType"] = "char"
structDict['CFocusFtdcInvestorRightField'] = CFocusFtdcInvestorRightField


#交易所代码
CFocusFtdcMarketDataExchangeIDField = {}
#交易所代码
CFocusFtdcMarketDataExchangeIDField["ExchangeID"] = "string"
structDict['CFocusFtdcMarketDataExchangeIDField'] = CFocusFtdcMarketDataExchangeIDField


#共享内存行情查询
CFocusFtdcShmDepthMarketDataField = {}
#合约代码
CFocusFtdcShmDepthMarketDataField["InstrumentID"] = "string"
#IP地址
CFocusFtdcShmDepthMarketDataField["IPAddress"] = "string"
#订阅号
CFocusFtdcShmDepthMarketDataField["TopicID"] = "int"
structDict['CFocusFtdcShmDepthMarketDataField'] = CFocusFtdcShmDepthMarketDataField


#TOPIC查询
CFocusFtdcTopicSearchField = {}
#订阅号
CFocusFtdcTopicSearchField["TopicID"] = "int"
structDict['CFocusFtdcTopicSearchField'] = CFocusFtdcTopicSearchField


#分价行情
CFocusFtdcMBLMarketDataField = {}
#合约代码
CFocusFtdcMBLMarketDataField["InstrumentID"] = "string"
#买卖方向
CFocusFtdcMBLMarketDataField["Direction"] = "char"
#价格
CFocusFtdcMBLMarketDataField["Price"] = "float"
#数量
CFocusFtdcMBLMarketDataField["Volume"] = "int"
#最后修改时间
CFocusFtdcMBLMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CFocusFtdcMBLMarketDataField["UpdateMillisec"] = "int"
structDict['CFocusFtdcMBLMarketDataField'] = CFocusFtdcMBLMarketDataField


#套利合约买卖总量
CFocusFtdcMarketDataCMBVolumeField = {}
#总卖出数量
CFocusFtdcMarketDataCMBVolumeField["VolumeAskLot"] = "int"
#总买入数量
CFocusFtdcMarketDataCMBVolumeField["VolumeBidLot"] = "int"
structDict['CFocusFtdcMarketDataCMBVolumeField'] = CFocusFtdcMarketDataCMBVolumeField


#合约状态
CFocusFtdcQmdInstrumentStateField = {}
#交易所代码
CFocusFtdcQmdInstrumentStateField["ExchangeID"] = "string"
#合约代码
CFocusFtdcQmdInstrumentStateField["InstrumentID"] = "string"
#合约交易状态
CFocusFtdcQmdInstrumentStateField["InstrumentStatus"] = "char"
structDict['CFocusFtdcQmdInstrumentStateField'] = CFocusFtdcQmdInstrumentStateField


#订阅合约的相关信息
CFocusFtdcSubSpecificInstrumentField = {}
#合约代码
CFocusFtdcSubSpecificInstrumentField["InstrumentID"] = "string"
structDict['CFocusFtdcSubSpecificInstrumentField'] = CFocusFtdcSubSpecificInstrumentField


#成交
CFocusFtdcTradeField = {}
#交易日
CFocusFtdcTradeField["TradingDay"] = "string"
#经纪公司编号
CFocusFtdcTradeField["BrokerID"] = "string"
#投资者编号
CFocusFtdcTradeField["InvestorID"] = "string"
#用户代码
CFocusFtdcTradeField["UserID"] = "string"
#用户本地报单号
CFocusFtdcTradeField["UserOrderLocalID"] = "string"
#用户自定义域
CFocusFtdcTradeField["UserCustom"] = "string"
#交易所代码
CFocusFtdcTradeField["ExchangeID"] = "string"
#成交编号
CFocusFtdcTradeField["TradeID"] = "string"
#报单编号
CFocusFtdcTradeField["OrderSysID"] = "string"
#合约代码
CFocusFtdcTradeField["InstrumentID"] = "string"
#合约名称
CFocusFtdcTradeField["InstrumentName"] = "string"
#买卖方向
CFocusFtdcTradeField["Direction"] = "char"
#开平标志
CFocusFtdcTradeField["OffsetFlag"] = "char"
#投机套保标志
CFocusFtdcTradeField["HedgeFlag"] = "char"
#成交价格
CFocusFtdcTradeField["TradePrice"] = "float"
#成交数量
CFocusFtdcTradeField["TradeVolume"] = "int"
#成交时间
CFocusFtdcTradeField["TradeTime"] = "string"
#市场代码
CFocusFtdcTradeField["MarketID"] = "string"
#成交金额
CFocusFtdcTradeField["TradeAmnt"] = "float"
#交易类型
CFocusFtdcTradeField["TradeType"] = "char"
#资金帐号
CFocusFtdcTradeField["AccountID"] = "string"
structDict['CFocusFtdcTradeField'] = CFocusFtdcTradeField


#报单
CFocusFtdcOrderField = {}
#经纪公司编号
CFocusFtdcOrderField["BrokerID"] = "string"
#投资者编号
CFocusFtdcOrderField["InvestorID"] = "string"
#用户代码
CFocusFtdcOrderField["UserID"] = "string"
#用户本地报单号
CFocusFtdcOrderField["UserOrderLocalID"] = "string"
#用户自定义域
CFocusFtdcOrderField["UserCustom"] = "string"
#交易所代码
CFocusFtdcOrderField["ExchangeID"] = "string"
#系统报单编号
CFocusFtdcOrderField["OrderSysID"] = "string"
#股票委托批号(仅批量委托有效)
CFocusFtdcOrderField["BatchNum"] = "string"
#合约代码
CFocusFtdcOrderField["InstrumentID"] = "string"
#合约名称
CFocusFtdcOrderField["InstrumentName"] = "string"
#报单类型
CFocusFtdcOrderField["OrderPriceType"] = "char"
#买卖方向
CFocusFtdcOrderField["Direction"] = "char"
#开平标志
CFocusFtdcOrderField["OffsetFlag"] = "char"
#投机套保标志
CFocusFtdcOrderField["HedgeFlag"] = "char"
#价格
CFocusFtdcOrderField["LimitPrice"] = "float"
#数量
CFocusFtdcOrderField["Volume"] = "int"
#有效期类型
CFocusFtdcOrderField["TimeCondition"] = "char"
#GTD日期
CFocusFtdcOrderField["GTDDate"] = "string"
#成交量类型
CFocusFtdcOrderField["VolumeCondition"] = "char"
#最小成交量
CFocusFtdcOrderField["MinVolume"] = "int"
#止损价
CFocusFtdcOrderField["StopPrice"] = "float"
#强平原因
CFocusFtdcOrderField["ForceCloseReason"] = "char"
#自动挂起标志
CFocusFtdcOrderField["IsAutoSuspend"] = "int"
#业务单元
CFocusFtdcOrderField["BusinessUnit"] = "string"
#业务类别
CFocusFtdcOrderField["BusinessType"] = "char"
#交易日
CFocusFtdcOrderField["TradingDay"] = "string"
#插入时间
CFocusFtdcOrderField["InsertTime"] = "string"
#报单来源
CFocusFtdcOrderField["OrderSource"] = "char"
#报单状态
CFocusFtdcOrderField["OrderStatus"] = "char"
#撤销时间
CFocusFtdcOrderField["CancelTime"] = "string"
#撤单用户编号
CFocusFtdcOrderField["CancelUserID"] = "string"
#已经成交数量
CFocusFtdcOrderField["VolumeTraded"] = "int"
#队列剩余数量
CFocusFtdcOrderField["VolumeRemain"] = "int"
#已经撤单数量
CFocusFtdcOrderField["VolumeCancled"] = "int"
#错误代码
CFocusFtdcOrderField["ErrorID"] = "int"
#错误信息
CFocusFtdcOrderField["ErrorMsg"] = "string"
#比上次增加的撤单数量
CFocusFtdcOrderField["VolumeIncCancled"] = "int"
#比上次增加的成交数量
CFocusFtdcOrderField["VolumeIncTraded"] = "int"
#资金帐号
CFocusFtdcOrderField["AccountID"] = "string"
#前置编号
CFocusFtdcOrderField["FrontID"] = "int"
#会话编号
CFocusFtdcOrderField["SessionID"] = "int"
#请求编号
CFocusFtdcOrderField["RequestID"] = "int"
#每手手续费
CFocusFtdcOrderField["EachFee"] = "float"
#每手保证金
CFocusFtdcOrderField["EachMargin"] = "float"
#每手期权权利金收支
CFocusFtdcOrderField["EachPremium"] = "float"
#下单IP地址
CFocusFtdcOrderField["IPAddress"] = "string"
#下单MAC地址
CFocusFtdcOrderField["MacAddress"] = "string"
#营业部代码
CFocusFtdcOrderField["BranchID"] = "string"
#记录编号
CFocusFtdcOrderField["RecNum"] = "int"
structDict['CFocusFtdcOrderField'] = CFocusFtdcOrderField


#数据流回退
CFocusFtdcFlowMessageCancelField = {}
#序列系列号
CFocusFtdcFlowMessageCancelField["SequenceSeries"] = "int"
#交易日
CFocusFtdcFlowMessageCancelField["TradingDay"] = "string"
#数据中心代码
CFocusFtdcFlowMessageCancelField["DataCenterID"] = "int"
#回退起始序列号
CFocusFtdcFlowMessageCancelField["StartSequenceNo"] = "int"
#回退结束序列号
CFocusFtdcFlowMessageCancelField["EndSequenceNo"] = "int"
structDict['CFocusFtdcFlowMessageCancelField'] = CFocusFtdcFlowMessageCancelField


#信息分发
CFocusFtdcDisseminationField = {}
#序列系列号
CFocusFtdcDisseminationField["SequenceSeries"] = "int"
#序列号
CFocusFtdcDisseminationField["SequenceNo"] = "int"
structDict['CFocusFtdcDisseminationField'] = CFocusFtdcDisseminationField


#警告消息通知
CFocusFtdcMessageNotifyField = {}
#经纪公司编号
CFocusFtdcMessageNotifyField["BrokerID"] = "string"
#修改用户编号
CFocusFtdcMessageNotifyField["UserID"] = "string"
#投资者编号
CFocusFtdcMessageNotifyField["InvestorID"] = "string"
#累加次数
CFocusFtdcMessageNotifyField["Nums"] = "int"
#警告级别
CFocusFtdcMessageNotifyField["WarnLevel"] = "char"
#警告编号
CFocusFtdcMessageNotifyField["WarnID"] = "int"
#警告信息
CFocusFtdcMessageNotifyField["WarnMsg"] = "string"
#警告时间
CFocusFtdcMessageNotifyField["WarnTime"] = "string"
structDict['CFocusFtdcMessageNotifyField'] = CFocusFtdcMessageNotifyField


#工作流指令通知
CFocusFtdcAdviceOrderField = {}
#投顾用户代码
CFocusFtdcAdviceOrderField["InvestorAdvicer"] = "string"
#投资经理
CFocusFtdcAdviceOrderField["InvestorManager"] = "string"
#交易员
CFocusFtdcAdviceOrderField["UserTrader"] = "string"
#冻结数量
CFocusFtdcAdviceOrderField["VolumeFrozen"] = "int"
#经纪公司编号
CFocusFtdcAdviceOrderField["BrokerID"] = "string"
#投资者编号
CFocusFtdcAdviceOrderField["InvestorID"] = "string"
#用户代码
CFocusFtdcAdviceOrderField["UserID"] = "string"
#用户本地报单号
CFocusFtdcAdviceOrderField["UserOrderLocalID"] = "string"
#用户自定义域
CFocusFtdcAdviceOrderField["UserCustom"] = "string"
#交易所代码
CFocusFtdcAdviceOrderField["ExchangeID"] = "string"
#系统报单编号
CFocusFtdcAdviceOrderField["OrderSysID"] = "string"
#股票委托批号(仅批量委托有效)
CFocusFtdcAdviceOrderField["BatchNum"] = "string"
#合约代码
CFocusFtdcAdviceOrderField["InstrumentID"] = "string"
#合约名称
CFocusFtdcAdviceOrderField["InstrumentName"] = "string"
#报单类型
CFocusFtdcAdviceOrderField["OrderPriceType"] = "char"
#买卖方向
CFocusFtdcAdviceOrderField["Direction"] = "char"
#开平标志
CFocusFtdcAdviceOrderField["OffsetFlag"] = "char"
#投机套保标志
CFocusFtdcAdviceOrderField["HedgeFlag"] = "char"
#价格
CFocusFtdcAdviceOrderField["LimitPrice"] = "float"
#数量
CFocusFtdcAdviceOrderField["Volume"] = "int"
#有效期类型
CFocusFtdcAdviceOrderField["TimeCondition"] = "char"
#GTD日期
CFocusFtdcAdviceOrderField["GTDDate"] = "string"
#成交量类型
CFocusFtdcAdviceOrderField["VolumeCondition"] = "char"
#最小成交量
CFocusFtdcAdviceOrderField["MinVolume"] = "int"
#止损价
CFocusFtdcAdviceOrderField["StopPrice"] = "float"
#强平原因
CFocusFtdcAdviceOrderField["ForceCloseReason"] = "char"
#自动挂起标志
CFocusFtdcAdviceOrderField["IsAutoSuspend"] = "int"
#业务单元
CFocusFtdcAdviceOrderField["BusinessUnit"] = "string"
#业务类别
CFocusFtdcAdviceOrderField["BusinessType"] = "char"
#交易日
CFocusFtdcAdviceOrderField["TradingDay"] = "string"
#插入时间
CFocusFtdcAdviceOrderField["InsertTime"] = "string"
#报单来源
CFocusFtdcAdviceOrderField["OrderSource"] = "char"
#报单状态
CFocusFtdcAdviceOrderField["OrderStatus"] = "char"
#撤销时间
CFocusFtdcAdviceOrderField["CancelTime"] = "string"
#撤单用户编号
CFocusFtdcAdviceOrderField["CancelUserID"] = "string"
#已经成交数量
CFocusFtdcAdviceOrderField["VolumeTraded"] = "int"
#队列剩余数量
CFocusFtdcAdviceOrderField["VolumeRemain"] = "int"
#已经撤单数量
CFocusFtdcAdviceOrderField["VolumeCancled"] = "int"
#错误代码
CFocusFtdcAdviceOrderField["ErrorID"] = "int"
#错误信息
CFocusFtdcAdviceOrderField["ErrorMsg"] = "string"
#比上次增加的撤单数量
CFocusFtdcAdviceOrderField["VolumeIncCancled"] = "int"
#比上次增加的成交数量
CFocusFtdcAdviceOrderField["VolumeIncTraded"] = "int"
#资金帐号
CFocusFtdcAdviceOrderField["AccountID"] = "string"
#前置编号
CFocusFtdcAdviceOrderField["FrontID"] = "int"
#会话编号
CFocusFtdcAdviceOrderField["SessionID"] = "int"
#请求编号
CFocusFtdcAdviceOrderField["RequestID"] = "int"
#每手手续费
CFocusFtdcAdviceOrderField["EachFee"] = "float"
#每手保证金
CFocusFtdcAdviceOrderField["EachMargin"] = "float"
#每手期权权利金收支
CFocusFtdcAdviceOrderField["EachPremium"] = "float"
#下单IP地址
CFocusFtdcAdviceOrderField["IPAddress"] = "string"
#下单MAC地址
CFocusFtdcAdviceOrderField["MacAddress"] = "string"
#营业部代码
CFocusFtdcAdviceOrderField["BranchID"] = "string"
#记录编号
CFocusFtdcAdviceOrderField["RecNum"] = "int"
#指令单用户信息
CFocusFtdcAdviceOrderField["AdviceUserInfo"] = "string"
structDict['CFocusFtdcAdviceOrderField'] = CFocusFtdcAdviceOrderField


#报单查询
CFocusFtdcQryOrderField = {}
#经纪公司编号
CFocusFtdcQryOrderField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryOrderField["UserID"] = "string"
#交易所代码
CFocusFtdcQryOrderField["ExchangeID"] = "string"
#投资者编号
CFocusFtdcQryOrderField["InvestorID"] = "string"
#报单编号
CFocusFtdcQryOrderField["OrderSysID"] = "string"
#合约代码
CFocusFtdcQryOrderField["InstrumentID"] = "string"
structDict['CFocusFtdcQryOrderField'] = CFocusFtdcQryOrderField


#成交查询
CFocusFtdcQryTradeField = {}
#经纪公司编号
CFocusFtdcQryTradeField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryTradeField["UserID"] = "string"
#交易所代码
CFocusFtdcQryTradeField["ExchangeID"] = "string"
#投资者编号
CFocusFtdcQryTradeField["InvestorID"] = "string"
#成交编号
CFocusFtdcQryTradeField["TradeID"] = "string"
#合约代码
CFocusFtdcQryTradeField["InstrumentID"] = "string"
structDict['CFocusFtdcQryTradeField'] = CFocusFtdcQryTradeField


#合约查询
CFocusFtdcQryInstrumentField = {}
#交易所代码
CFocusFtdcQryInstrumentField["ExchangeID"] = "string"
#产品代码
CFocusFtdcQryInstrumentField["ProductID"] = "string"
#合约代码
CFocusFtdcQryInstrumentField["InstrumentID"] = "string"
structDict['CFocusFtdcQryInstrumentField'] = CFocusFtdcQryInstrumentField


#合约查询应答
CFocusFtdcRspInstrumentField = {}
#交易所代码
CFocusFtdcRspInstrumentField["ExchangeID"] = "string"
#品种代码
CFocusFtdcRspInstrumentField["ProductID"] = "string"
#品种名称
CFocusFtdcRspInstrumentField["ProductName"] = "string"
#合约代码
CFocusFtdcRspInstrumentField["InstrumentID"] = "string"
#合约名称
CFocusFtdcRspInstrumentField["InstrumentName"] = "string"
#交割年份
CFocusFtdcRspInstrumentField["DeliveryYear"] = "int"
#交割月
CFocusFtdcRspInstrumentField["DeliveryMonth"] = "int"
#限价单最大下单量
CFocusFtdcRspInstrumentField["MaxLimitOrderVolume"] = "float"
#限价单最小下单量
CFocusFtdcRspInstrumentField["MinLimitOrderVolume"] = "float"
#市价单最大下单量
CFocusFtdcRspInstrumentField["MaxMarketOrderVolume"] = "float"
#市价单最小下单量
CFocusFtdcRspInstrumentField["MinMarketOrderVolume"] = "float"
#股票每次最少买入量
CFocusFtdcRspInstrumentField["MinStkBuyQty"] = "float"
#股票每次最少卖出量
CFocusFtdcRspInstrumentField["MinStkSellQty"] = "float"
#数量乘数
CFocusFtdcRspInstrumentField["VolumeMultiple"] = "int"
#报价单位
CFocusFtdcRspInstrumentField["PriceTick"] = "float"
#币种
CFocusFtdcRspInstrumentField["Currency"] = "string"
#多头限仓
CFocusFtdcRspInstrumentField["LongPosLimit"] = "float"
#空头限仓
CFocusFtdcRspInstrumentField["ShortPosLimit"] = "float"
#跌停板价
CFocusFtdcRspInstrumentField["LowerLimitPrice"] = "float"
#涨停板价
CFocusFtdcRspInstrumentField["UpperLimitPrice"] = "float"
#昨结算
CFocusFtdcRspInstrumentField["PreSettlementPrice"] = "float"
#合约交易状态
CFocusFtdcRspInstrumentField["InstrumentStatus"] = "char"
#创建日
CFocusFtdcRspInstrumentField["CreateDate"] = "string"
#上市日
CFocusFtdcRspInstrumentField["OpenDate"] = "string"
#到期日
CFocusFtdcRspInstrumentField["ExpireDate"] = "string"
#开始交割日
CFocusFtdcRspInstrumentField["StartDelivDate"] = "string"
#最后交割日
CFocusFtdcRspInstrumentField["EndDelivDate"] = "string"
#挂牌基准价
CFocusFtdcRspInstrumentField["BasisPrice"] = "float"
#当前是否交易
CFocusFtdcRspInstrumentField["IsTrading"] = "int"
#基础商品代码
CFocusFtdcRspInstrumentField["UnderlyingInstrID"] = "string"
#基础商品乘数
CFocusFtdcRspInstrumentField["UnderlyingMultiple"] = "int"
#持仓类型
CFocusFtdcRspInstrumentField["PositionType"] = "char"
#执行价
CFocusFtdcRspInstrumentField["StrikePrice"] = "float"
#期权类型
CFocusFtdcRspInstrumentField["OptionsType"] = "char"
#汇率
CFocusFtdcRspInstrumentField["ExchangeRate"] = "float"
#期权系列
CFocusFtdcRspInstrumentField["OptionSeriesId"] = "string"
#产品类型
CFocusFtdcRspInstrumentField["ProductClass"] = "char"
#期权行权方式
CFocusFtdcRspInstrumentField["OptionsMode"] = "char"
#保证金算法类型
CFocusFtdcRspInstrumentField["MarginCombType"] = "char"
structDict['CFocusFtdcRspInstrumentField'] = CFocusFtdcRspInstrumentField


#投资者资金查询
CFocusFtdcQryInvestorAccountField = {}
#经纪公司编号
CFocusFtdcQryInvestorAccountField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryInvestorAccountField["UserID"] = "string"
#投资者编号
CFocusFtdcQryInvestorAccountField["InvestorID"] = "string"
structDict['CFocusFtdcQryInvestorAccountField'] = CFocusFtdcQryInvestorAccountField


#投资者资金应答
CFocusFtdcRspInvestorAccountField = {}
#经纪公司编号
CFocusFtdcRspInvestorAccountField["BrokerID"] = "string"
#投资者编号
CFocusFtdcRspInvestorAccountField["InvestorID"] = "string"
#资金帐号
CFocusFtdcRspInvestorAccountField["AccountID"] = "string"
#资金密码
CFocusFtdcRspInvestorAccountField["InvestorPasswd"] = "string"
#上次结算准备金
CFocusFtdcRspInvestorAccountField["PreBalance"] = "float"
#上日可用资金
CFocusFtdcRspInvestorAccountField["PreAvailable"] = "float"
#入金金额
CFocusFtdcRspInvestorAccountField["Deposit"] = "float"
#出金金额
CFocusFtdcRspInvestorAccountField["Withdraw"] = "float"
#占用保证金
CFocusFtdcRspInvestorAccountField["Margin"] = "float"
#期权权利金收支
CFocusFtdcRspInvestorAccountField["Premium"] = "float"
#手续费
CFocusFtdcRspInvestorAccountField["Fee"] = "float"
#冻结的保证金
CFocusFtdcRspInvestorAccountField["FrozenMargin"] = "float"
#冻结权利金
CFocusFtdcRspInvestorAccountField["FrozenPremium"] = "float"
#冻结手续费
CFocusFtdcRspInvestorAccountField["FrozenFee"] = "float"
#平仓盈亏
CFocusFtdcRspInvestorAccountField["CloseProfit"] = "float"
#持仓盈亏
CFocusFtdcRspInvestorAccountField["PositionProfit"] = "float"
#可用资金
CFocusFtdcRspInvestorAccountField["Available"] = "float"
#结算准备金
CFocusFtdcRspInvestorAccountField["Balance"] = "float"
#多头占用保证金
CFocusFtdcRspInvestorAccountField["LongMargin"] = "float"
#空头占用保证金
CFocusFtdcRspInvestorAccountField["ShortMargin"] = "float"
#多头冻结的保证金
CFocusFtdcRspInvestorAccountField["LongFrozenMargin"] = "float"
#空头冻结的保证金
CFocusFtdcRspInvestorAccountField["ShortFrozenMargin"] = "float"
#动态权益
CFocusFtdcRspInvestorAccountField["DynamicRights"] = "float"
#风险度
CFocusFtdcRspInvestorAccountField["Risk"] = "float"
#其他费用
CFocusFtdcRspInvestorAccountField["OtherFee"] = "float"
#质押金额
CFocusFtdcRspInvestorAccountField["Mortgage"] = "float"
#币种
CFocusFtdcRspInvestorAccountField["Currency"] = "string"
#可取资金
CFocusFtdcRspInvestorAccountField["WithdrawQuota"] = "float"
#过户费
CFocusFtdcRspInvestorAccountField["TransferFee"] = "float"
#冻结的过户费
CFocusFtdcRspInvestorAccountField["FrozenTransferFee"] = "float"
#印花税
CFocusFtdcRspInvestorAccountField["StampTax"] = "float"
#冻结的印花税
CFocusFtdcRspInvestorAccountField["FrozenStampTax"] = "float"
structDict['CFocusFtdcRspInvestorAccountField'] = CFocusFtdcRspInvestorAccountField


#可用投资者查询
CFocusFtdcQryUserInvestorField = {}
#经纪公司编号
CFocusFtdcQryUserInvestorField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryUserInvestorField["UserID"] = "string"
structDict['CFocusFtdcQryUserInvestorField'] = CFocusFtdcQryUserInvestorField


#可用投资者应答
CFocusFtdcRspUserInvestorField = {}
#经纪公司编号
CFocusFtdcRspUserInvestorField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcRspUserInvestorField["UserID"] = "string"
#投资者编号
CFocusFtdcRspUserInvestorField["InvestorID"] = "string"
#默认用户代码
CFocusFtdcRspUserInvestorField["NextUserID"] = "string"
#是否可下单
CFocusFtdcRspUserInvestorField["OrderMode"] = "char"
#自动或者手动
CFocusFtdcRspUserInvestorField["RunMode"] = "char"
#工作流断线处理标示符
CFocusFtdcRspUserInvestorField["AdviceSwitchFlag"] = "char"
structDict['CFocusFtdcRspUserInvestorField'] = CFocusFtdcRspUserInvestorField


#投资者关系查询
CFocusFtdcQryInvestorRelationField = {}
#经纪公司编号
CFocusFtdcQryInvestorRelationField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryInvestorRelationField["UserID"] = "string"
#投资者编号
CFocusFtdcQryInvestorRelationField["InvestorID"] = "string"
structDict['CFocusFtdcQryInvestorRelationField'] = CFocusFtdcQryInvestorRelationField


#投资者关系应答
CFocusFtdcRspInvestorRelationField = {}
#经纪公司编号
CFocusFtdcRspInvestorRelationField["BrokerID"] = "string"
#投资者编号
CFocusFtdcRspInvestorRelationField["InvestorID"] = "string"
#父投资者编号
CFocusFtdcRspInvestorRelationField["ParentInvestorID"] = "string"
structDict['CFocusFtdcRspInvestorRelationField'] = CFocusFtdcRspInvestorRelationField


#交易所查询请求
CFocusFtdcQryExchangeField = {}
#交易所代码
CFocusFtdcQryExchangeField["ExchangeID"] = "string"
structDict['CFocusFtdcQryExchangeField'] = CFocusFtdcQryExchangeField


#交易所查询应答
CFocusFtdcRspExchangeField = {}
#交易日
CFocusFtdcRspExchangeField["TradingDay"] = "string"
#交易所代码
CFocusFtdcRspExchangeField["ExchangeID"] = "string"
#交易所名称
CFocusFtdcRspExchangeField["ExchangeName"] = "string"
structDict['CFocusFtdcRspExchangeField'] = CFocusFtdcRspExchangeField


#投资者持仓查询请求
CFocusFtdcQryInvestorPositionField = {}
#经纪公司编号
CFocusFtdcQryInvestorPositionField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryInvestorPositionField["UserID"] = "string"
#交易所代码
CFocusFtdcQryInvestorPositionField["ExchangeID"] = "string"
#投资者编号
CFocusFtdcQryInvestorPositionField["InvestorID"] = "string"
#合约代码
CFocusFtdcQryInvestorPositionField["InstrumentID"] = "string"
structDict['CFocusFtdcQryInvestorPositionField'] = CFocusFtdcQryInvestorPositionField


#投资者持仓查询应答
CFocusFtdcRspInvestorPositionField = {}
#经纪公司编号
CFocusFtdcRspInvestorPositionField["BrokerID"] = "string"
#交易所代码
CFocusFtdcRspInvestorPositionField["ExchangeID"] = "string"
#投资者编号
CFocusFtdcRspInvestorPositionField["InvestorID"] = "string"
#合约代码
CFocusFtdcRspInvestorPositionField["InstrumentID"] = "string"
#合约名称
CFocusFtdcRspInvestorPositionField["InstrumentName"] = "string"
#买卖方向
CFocusFtdcRspInvestorPositionField["Direction"] = "char"
#投机套保标志
CFocusFtdcRspInvestorPositionField["HedgeFlag"] = "char"
#占用保证金
CFocusFtdcRspInvestorPositionField["UsedMargin"] = "float"
#总持仓量
CFocusFtdcRspInvestorPositionField["Position"] = "int"
#总持仓成本
CFocusFtdcRspInvestorPositionField["PositionCost"] = "float"
#初始昨持仓量(当日不变)
CFocusFtdcRspInvestorPositionField["YdPosition"] = "int"
#初始昨日持仓成本(当日不变)
CFocusFtdcRspInvestorPositionField["YdPositionCost"] = "float"
#冻结的保证金
CFocusFtdcRspInvestorPositionField["FrozenMargin"] = "float"
#开仓冻结持仓
CFocusFtdcRspInvestorPositionField["FrozenPosition"] = "int"
#平仓冻结持仓
CFocusFtdcRspInvestorPositionField["FrozenClosing"] = "int"
#持仓盈亏
CFocusFtdcRspInvestorPositionField["PositionProfit"] = "float"
#冻结的权利金
CFocusFtdcRspInvestorPositionField["FrozenPremium"] = "float"
#最后一笔成交编号
CFocusFtdcRspInvestorPositionField["LastTradeID"] = "string"
#最后一笔本地报单编号
CFocusFtdcRspInvestorPositionField["LastOrderLocalID"] = "string"
#总持仓可平仓数量(包括平仓冻结持仓)
CFocusFtdcRspInvestorPositionField["PositionClose"] = "int"
#昨持仓可平仓数量(包括平仓冻结持仓)
CFocusFtdcRspInvestorPositionField["YdPositionClose"] = "int"
#昨持仓平仓冻结持仓
CFocusFtdcRspInvestorPositionField["YdFrozenClosing"] = "int"
#今日开仓数量(不包括冻结)
CFocusFtdcRspInvestorPositionField["OpenVolume"] = "int"
#今日平仓数量(包括昨持仓的平仓,不包括冻结)
CFocusFtdcRspInvestorPositionField["CloseVolume"] = "int"
#平仓盈亏
CFocusFtdcRspInvestorPositionField["CloseProfit"] = "float"
#申购赎回数量
CFocusFtdcRspInvestorPositionField["PurRedVolume"] = "int"
#申购赎回冻结数量
CFocusFtdcRspInvestorPositionField["FrozenPurRedVolume"] = "int"
#今日开仓冻结数量
CFocusFtdcRspInvestorPositionField["FrozenOpenVolume"] = "int"
#证券最新市值
CFocusFtdcRspInvestorPositionField["CurrentStkValue"] = "float"
#证券委托单位，0-股，1-手
CFocusFtdcRspInvestorPositionField["OrderUnit"] = "char"
structDict['CFocusFtdcRspInvestorPositionField'] = CFocusFtdcRspInvestorPositionField


#用户查询
CFocusFtdcQryUserField = {}
#交易用户代码
CFocusFtdcQryUserField["StartUserID"] = "string"
#交易用户代码
CFocusFtdcQryUserField["EndUserID"] = "string"
structDict['CFocusFtdcQryUserField'] = CFocusFtdcQryUserField


#用户
CFocusFtdcRspUserField = {}
#经纪公司编号
CFocusFtdcRspUserField["BrokerID"] = "string"
#用户代码
CFocusFtdcRspUserField["UserID"] = "string"
#用户登录密码
CFocusFtdcRspUserField["Password"] = "string"
#投资者组编号
CFocusFtdcRspUserField["GroupID"] = "string"
#投资者组名
CFocusFtdcRspUserField["GroupName"] = "string"
#是否活跃
CFocusFtdcRspUserField["IsActive"] = "char"
#用户名称
CFocusFtdcRspUserField["UserName"] = "string"
#用户类型
CFocusFtdcRspUserField["UserType"] = "char"
#营业部
CFocusFtdcRspUserField["Department"] = "string"
#授权功能集
CFocusFtdcRspUserField["GrantFuncSet"] = "string"
#最大在线数
CFocusFtdcRspUserField["MaxOnline"] = "int"
#IP地址
CFocusFtdcRspUserField["IPAddress"] = "string"
#是否检查连接产品
CFocusFtdcRspUserField["CheckProductInfo"] = "int"
#Mac地址
CFocusFtdcRspUserField["MacAddress"] = "string"
#是否检查IP和MAC
CFocusFtdcRspUserField["CheckIPMacAddr"] = "int"
#错误登陆次数限制
CFocusFtdcRspUserField["LoginErrorLimit"] = "int"
#目前错误登陆次数
CFocusFtdcRspUserField["LoginErrorCount"] = "int"
structDict['CFocusFtdcRspUserField'] = CFocusFtdcRspUserField


#投资者手续费率查询
CFocusFtdcQryInvestorFeeField = {}
#经纪公司编号
CFocusFtdcQryInvestorFeeField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryInvestorFeeField["UserID"] = "string"
#投资者编号
CFocusFtdcQryInvestorFeeField["InvestorID"] = "string"
#交易所代码
CFocusFtdcQryInvestorFeeField["ExchangeID"] = "string"
#合约代码
CFocusFtdcQryInvestorFeeField["InstrumentID"] = "string"
structDict['CFocusFtdcQryInvestorFeeField'] = CFocusFtdcQryInvestorFeeField


#投资者手续费率
CFocusFtdcRspInvestorFeeField = {}
#经纪公司编号
CFocusFtdcRspInvestorFeeField["BrokerID"] = "string"
#交易所代码
CFocusFtdcRspInvestorFeeField["ExchangeID"] = "string"
#投资者编码
CFocusFtdcRspInvestorFeeField["InvestorID"] = "string"
#合约代码
CFocusFtdcRspInvestorFeeField["InstrumentID"] = "string"
#开仓手续费按比例
CFocusFtdcRspInvestorFeeField["OpenFeeRate"] = "float"
#开仓手续费按手数
CFocusFtdcRspInvestorFeeField["OpenFeeAmt"] = "float"
#平仓手续费按比例
CFocusFtdcRspInvestorFeeField["OffsetFeeRate"] = "float"
#平仓手续费按手数
CFocusFtdcRspInvestorFeeField["OffsetFeeAmt"] = "float"
#平今仓手续费按比例
CFocusFtdcRspInvestorFeeField["OTFeeRate"] = "float"
#平今仓手续费按手数
CFocusFtdcRspInvestorFeeField["OTFeeAmt"] = "float"
structDict['CFocusFtdcRspInvestorFeeField'] = CFocusFtdcRspInvestorFeeField


#投资者保证金率查询
CFocusFtdcQryInvestorMarginField = {}
#经纪公司编号
CFocusFtdcQryInvestorMarginField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryInvestorMarginField["UserID"] = "string"
#投资者编号
CFocusFtdcQryInvestorMarginField["InvestorID"] = "string"
#交易所代码
CFocusFtdcQryInvestorMarginField["ExchangeID"] = "string"
#合约代码
CFocusFtdcQryInvestorMarginField["InstrumentID"] = "string"
#投机套保标志
CFocusFtdcQryInvestorMarginField["HedgeFlag"] = "char"
structDict['CFocusFtdcQryInvestorMarginField'] = CFocusFtdcQryInvestorMarginField


#投资者保证金率
CFocusFtdcRspInvestorMarginField = {}
#经纪公司编号
CFocusFtdcRspInvestorMarginField["BrokerID"] = "string"
#交易所代码
CFocusFtdcRspInvestorMarginField["ExchangeID"] = "string"
#投资者编码
CFocusFtdcRspInvestorMarginField["InvestorID"] = "string"
#合约代码
CFocusFtdcRspInvestorMarginField["InstrumentID"] = "string"
#投机套保标志
CFocusFtdcRspInvestorMarginField["HedgeFlag"] = "char"
#多头占用保证金按比例
CFocusFtdcRspInvestorMarginField["LongMarginRate"] = "float"
#多头保证金按手数
CFocusFtdcRspInvestorMarginField["LongMarginAmt"] = "float"
#空头占用保证金按比例
CFocusFtdcRspInvestorMarginField["ShortMarginRate"] = "float"
#空头保证金按手数
CFocusFtdcRspInvestorMarginField["ShortMarginAmt"] = "float"
structDict['CFocusFtdcRspInvestorMarginField'] = CFocusFtdcRspInvestorMarginField


#投资者查询
CFocusFtdcQryInvestorField = {}
#经纪公司编号
CFocusFtdcQryInvestorField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryInvestorField["UserID"] = "string"
#投资者编号
CFocusFtdcQryInvestorField["InvestorID"] = "string"
structDict['CFocusFtdcQryInvestorField'] = CFocusFtdcQryInvestorField


#投资者应答
CFocusFtdcRspInvestorField = {}
#经纪公司编号
CFocusFtdcRspInvestorField["BrokerID"] = "string"
#投资者编号
CFocusFtdcRspInvestorField["InvestorID"] = "string"
#资金密码
CFocusFtdcRspInvestorField["InvestorPasswd"] = "string"
#投资者名称
CFocusFtdcRspInvestorField["InvestorName"] = "string"
#投资者类型
CFocusFtdcRspInvestorField["InvestorType"] = "char"
#客户类型
CFocusFtdcRspInvestorField["ClientType"] = "char"
#上海股东代码(根网特殊用)
CFocusFtdcRspInvestorField["SSERegId"] = "string"
#深圳股东代码(根网特殊用)
CFocusFtdcRspInvestorField["SZSERegId"] = "string"
#上期所交易编码(根网特殊用)
CFocusFtdcRspInvestorField["SHFERegId"] = "string"
#郑商所交编码(根网特殊用)
CFocusFtdcRspInvestorField["ZCERegId"] = "string"
#大商所编码(根网特殊用)
CFocusFtdcRspInvestorField["DCERegId"] = "string"
#投资者组编号
CFocusFtdcRspInvestorField["GroupID"] = "string"
#投资者组名
CFocusFtdcRspInvestorField["GroupName"] = "string"
#别名
CFocusFtdcRspInvestorField["Alias"] = "string"
#连接类型
CFocusFtdcRspInvestorField["LinkType"] = "char"
#终端信息ID（穿透式监管里需要用到的）
CFocusFtdcRspInvestorField["F_TerminalId"] = "string"
#资金账户编号
CFocusFtdcRspInvestorField["ParentInvestorID"] = "string"
#登录次数
CFocusFtdcRspInvestorField["LoginStatus"] = "int"
#是否使用净持仓报单,投顾账户有效
CFocusFtdcRspInvestorField["PositionType"] = "char"
#自成交处理方式,资金账户有效
CFocusFtdcRspInvestorField["SelfTradeAvoidType"] = "char"
#交易权限
CFocusFtdcRspInvestorField["TradingRight"] = "char"
#是否检查资金
CFocusFtdcRspInvestorField["CheckAccount"] = "int"
#是否检查持仓
CFocusFtdcRspInvestorField["CheckPosition"] = "int"
#报单是否报警
CFocusFtdcRspInvestorField["OrderWarning"] = "int"
#资金持仓是否上查
CFocusFtdcRspInvestorField["QryUpAccPosi"] = "int"
#投顾选择资金账户类型
CFocusFtdcRspInvestorField["DistributeType"] = "char"
structDict['CFocusFtdcRspInvestorField'] = CFocusFtdcRspInvestorField


#账号风险状况查询
CFocusFtdcQryAccountRiskField = {}
#经纪公司编号
CFocusFtdcQryAccountRiskField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryAccountRiskField["UserID"] = "string"
#投资者编号
CFocusFtdcQryAccountRiskField["InvestorID"] = "string"
structDict['CFocusFtdcQryAccountRiskField'] = CFocusFtdcQryAccountRiskField


#账号风险状况应答
CFocusFtdcRspAccountRiskField = {}
#经纪公司编号
CFocusFtdcRspAccountRiskField["BrokerID"] = "string"
#投资者编号
CFocusFtdcRspAccountRiskField["InvestorID"] = "string"
#资金帐号
CFocusFtdcRspAccountRiskField["AccountID"] = "string"
#设置准备金
CFocusFtdcRspAccountRiskField["SetBalance"] = "float"
#开仓红线
CFocusFtdcRspAccountRiskField["OpenAvailable"] = "float"
#平仓红线
CFocusFtdcRspAccountRiskField["OffsetAvailable"] = "float"
#账户状态
CFocusFtdcRspAccountRiskField["AccountStatus"] = "char"
#动态权益
CFocusFtdcRspAccountRiskField["DynamicRights"] = "float"
#账户权限
CFocusFtdcRspAccountRiskField["TradingRight"] = "char"
structDict['CFocusFtdcRspAccountRiskField'] = CFocusFtdcRspAccountRiskField


#交易用户会话查询
CFocusFtdcQryUserSessionField = {}
#交易用户代码
CFocusFtdcQryUserSessionField["StartUserID"] = "string"
#交易用户代码
CFocusFtdcQryUserSessionField["EndUserID"] = "string"
structDict['CFocusFtdcQryUserSessionField'] = CFocusFtdcQryUserSessionField


#交易用户会话应答
CFocusFtdcRspUserSessionField = {}
#经纪公司代码
CFocusFtdcRspUserSessionField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcRspUserSessionField["UserID"] = "string"
#交易用户类型
CFocusFtdcRspUserSessionField["UserType"] = "char"
#会话编号
CFocusFtdcRspUserSessionField["SessionID"] = "int"
#前置编号
CFocusFtdcRspUserSessionField["FrontID"] = "int"
#登录时间
CFocusFtdcRspUserSessionField["LoginTime"] = "string"
#IP地址
CFocusFtdcRspUserSessionField["IPAddress"] = "string"
#Mac地址
CFocusFtdcRspUserSessionField["MacAddress"] = "string"
#用户端产品信息
CFocusFtdcRspUserSessionField["UserProductInfo"] = "string"
#接口端产品信息
CFocusFtdcRspUserSessionField["InterfaceProductInfo"] = "string"
#协议信息
CFocusFtdcRspUserSessionField["ProtocolInfo"] = "string"
structDict['CFocusFtdcRspUserSessionField'] = CFocusFtdcRspUserSessionField


#行情查询
CFocusFtdcQryMarketDataField = {}
#交易所代码
CFocusFtdcQryMarketDataField["ExchangeID"] = "string"
#合约代码
CFocusFtdcQryMarketDataField["InstrumentID"] = "string"
structDict['CFocusFtdcQryMarketDataField'] = CFocusFtdcQryMarketDataField


#行情应答
CFocusFtdcRspMarketDataField = {}
#交易所代码
CFocusFtdcRspMarketDataField["ExchangeID"] = "string"
#交易日
CFocusFtdcRspMarketDataField["TradingDay"] = "string"
#昨结算
CFocusFtdcRspMarketDataField["PreSettlementPrice"] = "float"
#昨收盘
CFocusFtdcRspMarketDataField["PreClosePrice"] = "float"
#昨持仓量
CFocusFtdcRspMarketDataField["PreOpenInterest"] = "float"
#昨虚实度
CFocusFtdcRspMarketDataField["PreDelta"] = "float"
#证券交易状态
CFocusFtdcRspMarketDataField["StkOrderStatus"] = "char"
#今开盘
CFocusFtdcRspMarketDataField["OpenPrice"] = "float"
#最高价
CFocusFtdcRspMarketDataField["HighestPrice"] = "float"
#最低价
CFocusFtdcRspMarketDataField["LowestPrice"] = "float"
#今收盘
CFocusFtdcRspMarketDataField["ClosePrice"] = "float"
#涨停板价
CFocusFtdcRspMarketDataField["UpperLimitPrice"] = "float"
#跌停板价
CFocusFtdcRspMarketDataField["LowerLimitPrice"] = "float"
#今结算
CFocusFtdcRspMarketDataField["SettlementPrice"] = "float"
#今虚实度
CFocusFtdcRspMarketDataField["CurrDelta"] = "float"
#最新价
CFocusFtdcRspMarketDataField["LastPrice"] = "float"
#数量
CFocusFtdcRspMarketDataField["Volume"] = "int"
#成交金额
CFocusFtdcRspMarketDataField["Turnover"] = "float"
#持仓量
CFocusFtdcRspMarketDataField["OpenInterest"] = "float"
#申买价一
CFocusFtdcRspMarketDataField["BidPrice1"] = "float"
#申买量一
CFocusFtdcRspMarketDataField["BidVolume1"] = "int"
#申卖价一
CFocusFtdcRspMarketDataField["AskPrice1"] = "float"
#申卖量一
CFocusFtdcRspMarketDataField["AskVolume1"] = "int"
#合约代码
CFocusFtdcRspMarketDataField["InstrumentID"] = "string"
#最后修改时间
CFocusFtdcRspMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CFocusFtdcRspMarketDataField["UpdateMillisec"] = "int"
structDict['CFocusFtdcRspMarketDataField'] = CFocusFtdcRspMarketDataField


#产品查询
CFocusFtdcQryProductField = {}
#产品代码
CFocusFtdcQryProductField["ProductID"] = "string"
structDict['CFocusFtdcQryProductField'] = CFocusFtdcQryProductField


#产品应答
CFocusFtdcRspProductField = {}
#交易所代码
CFocusFtdcRspProductField["ExchangeID"] = "string"
#产品代码
CFocusFtdcRspProductField["ProductID"] = "string"
#投资者发行的产品名称
CFocusFtdcRspProductField["ProductName"] = "string"
#币种
CFocusFtdcRspProductField["Currency"] = "string"
#汇率
CFocusFtdcRspProductField["ExchangeRate"] = "float"
#产品类型
CFocusFtdcRspProductField["ProductClass"] = "char"
structDict['CFocusFtdcRspProductField'] = CFocusFtdcRspProductField


#内部来回消息
CFocusFtdcPingPongField = {}
#经纪公司编号
CFocusFtdcPingPongField["BrokerID"] = "string"
#修改用户编号
CFocusFtdcPingPongField["UserID"] = "string"
#投资者编号
CFocusFtdcPingPongField["InvestorID"] = "string"
#编号
CFocusFtdcPingPongField["SequenceNo"] = "int"
#用户自定义域
CFocusFtdcPingPongField["UserCustom"] = "string"
structDict['CFocusFtdcPingPongField'] = CFocusFtdcPingPongField


#最大可交易数量查询请求
CFocusFtdcQryMaxVolumeField = {}
#经纪公司编号
CFocusFtdcQryMaxVolumeField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryMaxVolumeField["UserID"] = "string"
#投资者编号
CFocusFtdcQryMaxVolumeField["InvestorID"] = "string"
#交易所代码
CFocusFtdcQryMaxVolumeField["ExchangeID"] = "string"
#合约代码
CFocusFtdcQryMaxVolumeField["InstrumentID"] = "string"
#买卖方向
CFocusFtdcQryMaxVolumeField["Direction"] = "char"
#开平标志
CFocusFtdcQryMaxVolumeField["OffsetFlag"] = "char"
#投机套保标志
CFocusFtdcQryMaxVolumeField["HedgeFlag"] = "char"
#价格
CFocusFtdcQryMaxVolumeField["LimitPrice"] = "float"
structDict['CFocusFtdcQryMaxVolumeField'] = CFocusFtdcQryMaxVolumeField


#最大可交易数量查询应答
CFocusFtdcRspMaxVolumeField = {}
#经纪公司编号
CFocusFtdcRspMaxVolumeField["BrokerID"] = "string"
#用户代码
CFocusFtdcRspMaxVolumeField["UserID"] = "string"
#投资者编号
CFocusFtdcRspMaxVolumeField["InvestorID"] = "string"
#交易所代码
CFocusFtdcRspMaxVolumeField["ExchangeID"] = "string"
#合约代码
CFocusFtdcRspMaxVolumeField["InstrumentID"] = "string"
#买卖方向
CFocusFtdcRspMaxVolumeField["Direction"] = "char"
#开平标志
CFocusFtdcRspMaxVolumeField["OffsetFlag"] = "char"
#投机套保标志
CFocusFtdcRspMaxVolumeField["HedgeFlag"] = "char"
#价格
CFocusFtdcRspMaxVolumeField["LimitPrice"] = "float"
#数量
CFocusFtdcRspMaxVolumeField["Volume"] = "int"
structDict['CFocusFtdcRspMaxVolumeField'] = CFocusFtdcRspMaxVolumeField


#工作流交易员查询请求
CFocusFtdcQryAdviceTraderField = {}
#经纪公司编号
CFocusFtdcQryAdviceTraderField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryAdviceTraderField["UserID"] = "string"
#投资者编号
CFocusFtdcQryAdviceTraderField["InvestorID"] = "string"
#登录经纪公司编号
CFocusFtdcQryAdviceTraderField["LogBrokerID"] = "string"
#登录用户代码
CFocusFtdcQryAdviceTraderField["LogUserID"] = "string"
structDict['CFocusFtdcQryAdviceTraderField'] = CFocusFtdcQryAdviceTraderField


#工作流交易员查询应答
CFocusFtdcRspAdviceTraderField = {}
#经纪公司编号
CFocusFtdcRspAdviceTraderField["BrokerID"] = "string"
#投资者编号
CFocusFtdcRspAdviceTraderField["InvestorID"] = "string"
#用户代码
CFocusFtdcRspAdviceTraderField["UserID"] = "string"
#关联用户代码
CFocusFtdcRspAdviceTraderField["RelationUserID"] = "string"
#关联用户名称
CFocusFtdcRspAdviceTraderField["RelationUserName"] = "string"
structDict['CFocusFtdcRspAdviceTraderField'] = CFocusFtdcRspAdviceTraderField


#组合持仓明细查询请求
CFocusFtdcQryCmbPositionDetailField = {}
#投资者编号
CFocusFtdcQryCmbPositionDetailField["InvestorID"] = "string"
structDict['CFocusFtdcQryCmbPositionDetailField'] = CFocusFtdcQryCmbPositionDetailField


#组合持仓明细查询应答
CFocusFtdcRspCmbPositionDetailField = {}
#经纪公司编号
CFocusFtdcRspCmbPositionDetailField["BrokerID"] = "string"
#交易所代码
CFocusFtdcRspCmbPositionDetailField["ExchangeID"] = "string"
#投资者编号
CFocusFtdcRspCmbPositionDetailField["InvestorID"] = "string"
#单腿合约代码
CFocusFtdcRspCmbPositionDetailField["InstrumentID"] = "string"
#单腿合约代码
CFocusFtdcRspCmbPositionDetailField["CmbInstrumentID"] = "string"
#成交编号
CFocusFtdcRspCmbPositionDetailField["TradeID"] = "string"
#报单编号
CFocusFtdcRspCmbPositionDetailField["OrderSysID"] = "string"
#买卖方向
CFocusFtdcRspCmbPositionDetailField["Direction"] = "char"
#投机套保标志
CFocusFtdcRspCmbPositionDetailField["HedgeFlag"] = "char"
#持仓量
CFocusFtdcRspCmbPositionDetailField["Position"] = "int"
#单腿编号
CFocusFtdcRspCmbPositionDetailField["LegQty"] = "int"
#交易日期
CFocusFtdcRspCmbPositionDetailField["TradingDay"] = "string"
structDict['CFocusFtdcRspCmbPositionDetailField'] = CFocusFtdcRspCmbPositionDetailField


#投资者结算结果查询请求
CFocusFtdcQrySettlementInfoField = {}
#经纪公司编号
CFocusFtdcQrySettlementInfoField["BrokerID"] = "string"
#投资者编号
CFocusFtdcQrySettlementInfoField["InvestorID"] = "string"
#交易日期
CFocusFtdcQrySettlementInfoField["TradingDay"] = "string"
structDict['CFocusFtdcQrySettlementInfoField'] = CFocusFtdcQrySettlementInfoField


#投资者结算结果查询应答
CFocusFtdcRspSettlementInfoField = {}
#交易日期
CFocusFtdcRspSettlementInfoField["TradingDay"] = "string"
#经纪公司编号
CFocusFtdcRspSettlementInfoField["BrokerID"] = "string"
#投资者编号
CFocusFtdcRspSettlementInfoField["InvestorID"] = "string"
#序号
CFocusFtdcRspSettlementInfoField["SequenceNo"] = "int"
#消息正文
CFocusFtdcRspSettlementInfoField["Content"] = "string"
structDict['CFocusFtdcRspSettlementInfoField'] = CFocusFtdcRspSettlementInfoField


#查询结果集分页
CFocusFtdcQryResultPageField = {}
#结果集编号
CFocusFtdcQryResultPageField["ResultID"] = "int"
#总记录数
CFocusFtdcQryResultPageField["Count"] = "int"
#总页数
CFocusFtdcQryResultPageField["Pages"] = "int"
#剩余页数
CFocusFtdcQryResultPageField["Remain"] = "int"
structDict['CFocusFtdcQryResultPageField'] = CFocusFtdcQryResultPageField


#查询持仓明细请求
CFocusFtdcQryPositionDetailField = {}
#经纪公司编号
CFocusFtdcQryPositionDetailField["BrokerID"] = "string"
#交易所代码
CFocusFtdcQryPositionDetailField["ExchangeID"] = "string"
#投资者编号
CFocusFtdcQryPositionDetailField["InvestorID"] = "string"
#单腿合约代码
CFocusFtdcQryPositionDetailField["InstrumentID"] = "string"
structDict['CFocusFtdcQryPositionDetailField'] = CFocusFtdcQryPositionDetailField


#查询持仓明细应答
CFocusFtdcRspPositionDetailField = {}
#经纪公司编号
CFocusFtdcRspPositionDetailField["BrokerID"] = "string"
#交易所代码
CFocusFtdcRspPositionDetailField["ExchangeID"] = "string"
#投资者编号
CFocusFtdcRspPositionDetailField["InvestorID"] = "string"
#合约代码
CFocusFtdcRspPositionDetailField["InstrumentID"] = "string"
#投机套保标志
CFocusFtdcRspPositionDetailField["HedgeFlag"] = "char"
#买卖方向
CFocusFtdcRspPositionDetailField["Direction"] = "char"
#开仓日期
CFocusFtdcRspPositionDetailField["OpenDate"] = "string"
#成交编号
CFocusFtdcRspPositionDetailField["TradeID"] = "string"
#数量
CFocusFtdcRspPositionDetailField["Volume"] = "int"
#开仓价
CFocusFtdcRspPositionDetailField["OpenPrice"] = "float"
#交易日
CFocusFtdcRspPositionDetailField["TradingDay"] = "string"
#交易类型
CFocusFtdcRspPositionDetailField["TradeType"] = "char"
#组合合约代码
CFocusFtdcRspPositionDetailField["CombInstrumentID"] = "string"
#逐日盯市平仓盈亏
CFocusFtdcRspPositionDetailField["CloseProfitByDate"] = "float"
#逐笔对冲平仓盈亏
CFocusFtdcRspPositionDetailField["CloseProfitByTrade"] = "float"
#逐日盯市持仓盈亏
CFocusFtdcRspPositionDetailField["PositionProfitByDate"] = "float"
#逐笔对冲持仓盈亏
CFocusFtdcRspPositionDetailField["PositionProfitByTrade"] = "float"
#投资者保证金
CFocusFtdcRspPositionDetailField["Margin"] = "float"
#交易所保证金
CFocusFtdcRspPositionDetailField["ExchMargin"] = "float"
#保证金率
CFocusFtdcRspPositionDetailField["MarginRateByMoney"] = "float"
#保证金率(按手数)
CFocusFtdcRspPositionDetailField["MarginRateByVolume"] = "float"
#昨结算价
CFocusFtdcRspPositionDetailField["LastSettlementPrice"] = "float"
#结算价
CFocusFtdcRspPositionDetailField["SettlementPrice"] = "float"
#平仓量
CFocusFtdcRspPositionDetailField["CloseVolume"] = "int"
#平仓金额
CFocusFtdcRspPositionDetailField["CloseAmount"] = "float"
structDict['CFocusFtdcRspPositionDetailField'] = CFocusFtdcRspPositionDetailField


#理论价行情
CFocusFtdcTheoryPriceDataField = {}
#交易日
CFocusFtdcTheoryPriceDataField["TradingDay"] = "string"
#用户代码
CFocusFtdcTheoryPriceDataField["UserID"] = "string"
#合约代码
CFocusFtdcTheoryPriceDataField["InstrumentID"] = "string"
#理论价
CFocusFtdcTheoryPriceDataField["TheoryPrice"] = "float"
#理论波动率
CFocusFtdcTheoryPriceDataField["TheoryVol"] = "float"
#标的最新价
CFocusFtdcTheoryPriceDataField["UnderlyingLastPrice"] = "float"
#标的买1价
CFocusFtdcTheoryPriceDataField["UnderlyingBidPrice1"] = "float"
#标的卖1价
CFocusFtdcTheoryPriceDataField["UnderlyingAskPrice1"] = "float"
#剩余时间
CFocusFtdcTheoryPriceDataField["RemainDay"] = "float"
structDict['CFocusFtdcTheoryPriceDataField'] = CFocusFtdcTheoryPriceDataField


#期权指标行情
CFocusFtdcOptionIndexDataField = {}
#交易日
CFocusFtdcOptionIndexDataField["TradingDay"] = "string"
#用户代码
CFocusFtdcOptionIndexDataField["UserID"] = "string"
#合约代码
CFocusFtdcOptionIndexDataField["InstrumentID"] = "string"
#Delta
CFocusFtdcOptionIndexDataField["Delta"] = "float"
#Gamma
CFocusFtdcOptionIndexDataField["Gamma"] = "float"
#Vega
CFocusFtdcOptionIndexDataField["Vega"] = "float"
#Theta
CFocusFtdcOptionIndexDataField["Theta"] = "float"
#Rho
CFocusFtdcOptionIndexDataField["Rho"] = "float"
#买1价波动率
CFocusFtdcOptionIndexDataField["BidVol"] = "float"
#卖1价波动率
CFocusFtdcOptionIndexDataField["AskVol"] = "float"
#中间价波动率
CFocusFtdcOptionIndexDataField["MidVol"] = "float"
#最新价波动率
CFocusFtdcOptionIndexDataField["LastVol"] = "float"
#最新价
CFocusFtdcOptionIndexDataField["LastPrice"] = "float"
#买1价
CFocusFtdcOptionIndexDataField["BidPrice1"] = "float"
#卖1价
CFocusFtdcOptionIndexDataField["AskPrice1"] = "float"
#理论波动率
CFocusFtdcOptionIndexDataField["TheoryVol"] = "float"
#标的最新价
CFocusFtdcOptionIndexDataField["UnderlyingLastPrice"] = "float"
#标的买1价
CFocusFtdcOptionIndexDataField["UnderlyingBidPrice1"] = "float"
#标的卖1价
CFocusFtdcOptionIndexDataField["UnderlyingAskPrice1"] = "float"
#剩余天数
CFocusFtdcOptionIndexDataField["RemainDay"] = "float"
#是否是客户端设置的波动率
CFocusFtdcOptionIndexDataField["IsManalSetVol"] = "char"
#AtmVol波动率
CFocusFtdcOptionIndexDataField["AtmVol"] = "float"
structDict['CFocusFtdcOptionIndexDataField'] = CFocusFtdcOptionIndexDataField


#定价参数
CFocusFtdcPricingParamField = {}
#用户代码
CFocusFtdcPricingParamField["UserID"] = "string"
#标的代码
CFocusFtdcPricingParamField["UnderlyingId"] = "string"
#期权系列
CFocusFtdcPricingParamField["OptionSeriesId"] = "string"
#一级价格
CFocusFtdcPricingParamField["PriceLevel1"] = "char"
#二级价格
CFocusFtdcPricingParamField["PriceLevel2"] = "char"
#三级价格
CFocusFtdcPricingParamField["PriceLevel3"] = "char"
#计算日历
CFocusFtdcPricingParamField["CalcDayType"] = "char"
#年总天数
CFocusFtdcPricingParamField["YearTotalDay"] = "int"
#计时方式
CFocusFtdcPricingParamField["CalcTimeType"] = "char"
#无风险利率
CFocusFtdcPricingParamField["RiskFreeRate"] = "float"
#股息率
CFocusFtdcPricingParamField["Dividend"] = "float"
#定价模型
CFocusFtdcPricingParamField["PricingEngine"] = "char"
#行权方式
CFocusFtdcPricingParamField["ExerciseType"] = "char"
#波动率精度
CFocusFtdcPricingParamField["VolTolerance"] = "float"
#波动率类型
CFocusFtdcPricingParamField["VolType"] = "char"
structDict['CFocusFtdcPricingParamField'] = CFocusFtdcPricingParamField


#期权理论波动率
CFocusFtdcOptionTheoryVolField = {}
#用户代码
CFocusFtdcOptionTheoryVolField["UserID"] = "string"
#合约代码
CFocusFtdcOptionTheoryVolField["InstrumentID"] = "string"
#理论波动率
CFocusFtdcOptionTheoryVolField["TheoryVol"] = "float"
structDict['CFocusFtdcOptionTheoryVolField'] = CFocusFtdcOptionTheoryVolField


#定价基本参数
CFocusFtdcBasePricingParamField = {}
#合约代码
CFocusFtdcBasePricingParamField["InstrumentID"] = "string"
#计算目标
CFocusFtdcBasePricingParamField["CalculateTarget"] = "char"
#行权方式
CFocusFtdcBasePricingParamField["ExerciseType"] = "char"
#期权类型
CFocusFtdcBasePricingParamField["OptionsType"] = "char"
#标的价格
CFocusFtdcBasePricingParamField["UnderlyingPrice"] = "float"
#执行价
CFocusFtdcBasePricingParamField["StrikePrice"] = "float"
#无风险利率
CFocusFtdcBasePricingParamField["RiskFreeRate"] = "float"
#股息率
CFocusFtdcBasePricingParamField["Dividend"] = "float"
#剩余天数
CFocusFtdcBasePricingParamField["RemainDay"] = "float"
#交易日
CFocusFtdcBasePricingParamField["TradingDate"] = "string"
#到期日
CFocusFtdcBasePricingParamField["ExpireDate"] = "string"
#波动率
CFocusFtdcBasePricingParamField["Vol"] = "float"
#定价模型
CFocusFtdcBasePricingParamField["PricingModel"] = "char"
#期权价值
CFocusFtdcBasePricingParamField["OptionPrice"] = "float"
#重置频率
CFocusFtdcBasePricingParamField["ResetFrequency"] = "int"
#Delta
CFocusFtdcBasePricingParamField["Delta"] = "float"
#Gamma
CFocusFtdcBasePricingParamField["Gamma"] = "float"
#Vega
CFocusFtdcBasePricingParamField["Vega"] = "float"
#Theta
CFocusFtdcBasePricingParamField["Theta"] = "float"
#Rho
CFocusFtdcBasePricingParamField["Rho"] = "float"
#Vanna
CFocusFtdcBasePricingParamField["Vanna"] = "float"
#Volga
CFocusFtdcBasePricingParamField["Volga"] = "float"
structDict['CFocusFtdcBasePricingParamField'] = CFocusFtdcBasePricingParamField


#双障碍期权定价参数
CFocusFtdcDoubleBarrierPricingParamField = {}
#合约代码
CFocusFtdcDoubleBarrierPricingParamField["InstrumentID"] = "string"
#计算目标
CFocusFtdcDoubleBarrierPricingParamField["CalculateTarget"] = "char"
#行权方式
CFocusFtdcDoubleBarrierPricingParamField["ExerciseType"] = "char"
#期权类型
CFocusFtdcDoubleBarrierPricingParamField["OptionsType"] = "char"
#标的价格
CFocusFtdcDoubleBarrierPricingParamField["UnderlyingPrice"] = "float"
#执行价
CFocusFtdcDoubleBarrierPricingParamField["StrikePrice"] = "float"
#无风险利率
CFocusFtdcDoubleBarrierPricingParamField["RiskFreeRate"] = "float"
#股息率
CFocusFtdcDoubleBarrierPricingParamField["Dividend"] = "float"
#剩余天数
CFocusFtdcDoubleBarrierPricingParamField["RemainDay"] = "float"
#交易日
CFocusFtdcDoubleBarrierPricingParamField["TradingDate"] = "string"
#到期日
CFocusFtdcDoubleBarrierPricingParamField["ExpireDate"] = "string"
#波动率
CFocusFtdcDoubleBarrierPricingParamField["Vol"] = "float"
#定价模型
CFocusFtdcDoubleBarrierPricingParamField["PricingModel"] = "char"
#期权价值
CFocusFtdcDoubleBarrierPricingParamField["OptionPrice"] = "float"
#重置频率
CFocusFtdcDoubleBarrierPricingParamField["ResetFrequency"] = "int"
#Delta
CFocusFtdcDoubleBarrierPricingParamField["Delta"] = "float"
#Gamma
CFocusFtdcDoubleBarrierPricingParamField["Gamma"] = "float"
#Vega
CFocusFtdcDoubleBarrierPricingParamField["Vega"] = "float"
#Theta
CFocusFtdcDoubleBarrierPricingParamField["Theta"] = "float"
#Rho
CFocusFtdcDoubleBarrierPricingParamField["Rho"] = "float"
#Vanna
CFocusFtdcDoubleBarrierPricingParamField["Vanna"] = "float"
#Volga
CFocusFtdcDoubleBarrierPricingParamField["Volga"] = "float"
#障碍类型
CFocusFtdcDoubleBarrierPricingParamField["BarrierType"] = "char"
#障碍下沿值
CFocusFtdcDoubleBarrierPricingParamField["LowerBarrierRate"] = "float"
#障碍上沿值
CFocusFtdcDoubleBarrierPricingParamField["UpperBarrierRate"] = "float"
structDict['CFocusFtdcDoubleBarrierPricingParamField'] = CFocusFtdcDoubleBarrierPricingParamField


#波动率拟合参数
CFocusFtdcVolatilityFittingField = {}
#产品代码
CFocusFtdcVolatilityFittingField["ProductID"] = "string"
#剩余天数
CFocusFtdcVolatilityFittingField["RemainDay"] = "float"
#执行价
CFocusFtdcVolatilityFittingField["StrikePrice"] = "float"
#波动率
CFocusFtdcVolatilityFittingField["Vol"] = "float"
structDict['CFocusFtdcVolatilityFittingField'] = CFocusFtdcVolatilityFittingField


#Wing模型参数
CFocusFtdcWingModelParamField = {}
#用户代码
CFocusFtdcWingModelParamField["UserID"] = "string"
#品种编号
CFocusFtdcWingModelParamField["ProductID"] = "string"
#期权系列
CFocusFtdcWingModelParamField["OptionSeriesId"] = "string"
#拟合时选用的模型
CFocusFtdcWingModelParamField["FitModel"] = "char"
#wing模型参数类型
CFocusFtdcWingModelParamField["WingParamType"] = "char"
#交易日
CFocusFtdcWingModelParamField["TradingDay"] = "string"
#插入时间
CFocusFtdcWingModelParamField["InsertTime"] = "string"
#ATM
CFocusFtdcWingModelParamField["Atm"] = "float"
#Days
CFocusFtdcWingModelParamField["Days"] = "float"
#参考价格
CFocusFtdcWingModelParamField["ref"] = "float"
#ssr
CFocusFtdcWingModelParamField["ssr"] = "float"
#vcr
CFocusFtdcWingModelParamField["vcr"] = "float"
#scr
CFocusFtdcWingModelParamField["scr"] = "float"
#cc
CFocusFtdcWingModelParamField["cc"] = "float"
#uc
CFocusFtdcWingModelParamField["uc"] = "float"
#usm
CFocusFtdcWingModelParamField["usm"] = "float"
#pc
CFocusFtdcWingModelParamField["pc"] = "float"
#dc
CFocusFtdcWingModelParamField["dc"] = "float"
#dsm
CFocusFtdcWingModelParamField["dsm"] = "float"
#vr
CFocusFtdcWingModelParamField["vr"] = "float"
#sr
CFocusFtdcWingModelParamField["sr"] = "float"
#vc
CFocusFtdcWingModelParamField["vc"] = "float"
#sc
CFocusFtdcWingModelParamField["sc"] = "float"
structDict['CFocusFtdcWingModelParamField'] = CFocusFtdcWingModelParamField


#Wing模型参数查询请求
CFocusFtdcQryWingModelParamField = {}
#用户代码
CFocusFtdcQryWingModelParamField["UserID"] = "string"
#产品代码
CFocusFtdcQryWingModelParamField["ProductID"] = "string"
#期权系列
CFocusFtdcQryWingModelParamField["OptionSeriesId"] = "string"
#wing模型参数类型
CFocusFtdcQryWingModelParamField["WingParamType"] = "char"
#拟合时选用的模型
CFocusFtdcQryWingModelParamField["FitModel"] = "char"
structDict['CFocusFtdcQryWingModelParamField'] = CFocusFtdcQryWingModelParamField


#做市报价累计价格
CFocusFtdcQuoteTotalTradePriceField = {}
#用户代码(交易员)
CFocusFtdcQuoteTotalTradePriceField["UserID"] = "string"
#投资者编号
CFocusFtdcQuoteTotalTradePriceField["InvestorID"] = "string"
#合约代码
CFocusFtdcQuoteTotalTradePriceField["InstrumentID"] = "string"
#当前卖成交量，交易员设置，不管开平
CFocusFtdcQuoteTotalTradePriceField["AskTradeVolume"] = "int"
#当前买成交量，交易员设置，不管开平
CFocusFtdcQuoteTotalTradePriceField["BidTradeVolume"] = "int"
#当前报价实际报买价
CFocusFtdcQuoteTotalTradePriceField["BidQuotePrice"] = "float"
#当前报价实际报买量
CFocusFtdcQuoteTotalTradePriceField["BidQuoteAmount"] = "int"
#当前报价实际报卖价
CFocusFtdcQuoteTotalTradePriceField["AskQuotePrice"] = "float"
#当前报价实际报卖量
CFocusFtdcQuoteTotalTradePriceField["AskQuoteAmount"] = "int"
#今日实际回应询价数量
CFocusFtdcQuoteTotalTradePriceField["ForQuoteSendAmount"] = "int"
#今日收到询价请求数量
CFocusFtdcQuoteTotalTradePriceField["ForQuoteTotalAmount"] = "int"
#当前询价回应实际报买价
CFocusFtdcQuoteTotalTradePriceField["BidForQuotePrice"] = "float"
#当前询价回应实际报买量
CFocusFtdcQuoteTotalTradePriceField["BidForQuoteAmount"] = "int"
#当前询价回应实际报卖价
CFocusFtdcQuoteTotalTradePriceField["AskForQuotePrice"] = "float"
#当前询价回应实际报卖量
CFocusFtdcQuoteTotalTradePriceField["AskForQuoteAmount"] = "int"
#移动报价方向
CFocusFtdcQuoteTotalTradePriceField["FowardDirection"] = "char"
structDict['CFocusFtdcQuoteTotalTradePriceField'] = CFocusFtdcQuoteTotalTradePriceField


#做市策略
CFocusFtdcMarkerStrategyField = {}
#合约代码
CFocusFtdcMarkerStrategyField["InstrumentID"] = "string"
#交易用户代码
CFocusFtdcMarkerStrategyField["UserID"] = "string"
#投资者编号
CFocusFtdcMarkerStrategyField["InvestorID"] = "string"
#自动报价
CFocusFtdcMarkerStrategyField["AutoOffer"] = "char"
#自动回应询价
CFocusFtdcMarkerStrategyField["AutoRespAsking"] = "char"
#报价报买量
CFocusFtdcMarkerStrategyField["BidAmount"] = "int"
#报价报卖量
CFocusFtdcMarkerStrategyField["AskAmount"] = "int"
#询价报买量
CFocusFtdcMarkerStrategyField["ForQuoteBidAmount"] = "int"
#询价报卖量
CFocusFtdcMarkerStrategyField["ForQuoteAskAmount"] = "int"
#买量上限
CFocusFtdcMarkerStrategyField["BidMax"] = "int"
#卖量上限
CFocusFtdcMarkerStrategyField["AskMax"] = "int"
#价差类型
CFocusFtdcMarkerStrategyField["SpreadType"] = "char"
#报价价差宽度
CFocusFtdcMarkerStrategyField["QuotePriceWidth"] = "float"
#报价价差比
CFocusFtdcMarkerStrategyField["QuoteWidthRatio"] = "float"
#询价价差宽度
CFocusFtdcMarkerStrategyField["ForQuotePriceWidth"] = "float"
#询价价差比
CFocusFtdcMarkerStrategyField["ForQuoteWidthRatio"] = "float"
#是否有效
CFocusFtdcMarkerStrategyField["IsActive"] = "char"
#备注
CFocusFtdcMarkerStrategyField["Remark"] = "string"
#报价方式
CFocusFtdcMarkerStrategyField["OfferType"] = "char"
#中心价容忍度
CFocusFtdcMarkerStrategyField["TOL_TICK"] = "int"
#询价回应报价方式
CFocusFtdcMarkerStrategyField["ForQuoteOfferType"] = "char"
#报价宽度单位
CFocusFtdcMarkerStrategyField["QuoteWidthType"] = "char"
#询价回应宽度单位
CFocusFtdcMarkerStrategyField["ForQuoteWidthType"] = "char"
#合约单边市停止报价
CFocusFtdcMarkerStrategyField["InstrumentOneSide"] = "char"
#标的单边市停止报价
CFocusFtdcMarkerStrategyField["UnderlyingOneSide"] = "char"
#合约低于协定价停止报价
CFocusFtdcMarkerStrategyField["MinPrice"] = "float"
#报价价宽模板
CFocusFtdcMarkerStrategyField["QuoteStepID"] = "string"
#报价Delta价宽模板
CFocusFtdcMarkerStrategyField["QuoteDeltaStepID"] = "string"
#报价Vega价宽模板
CFocusFtdcMarkerStrategyField["QuoteVegaStepID"] = "string"
#询价回应价宽模板
CFocusFtdcMarkerStrategyField["ForQuoteStepID"] = "string"
#询价回应Delta价宽模板
CFocusFtdcMarkerStrategyField["ForQuoteDeltaStepID"] = "string"
#询价回应Vega价宽模板
CFocusFtdcMarkerStrategyField["ForQuoteVegaStepID"] = "string"
structDict['CFocusFtdcMarkerStrategyField'] = CFocusFtdcMarkerStrategyField


#用户开关
CFocusFtdcUserSwitchField = {}
#用户代码(交易员)
CFocusFtdcUserSwitchField["UserID"] = "string"
#交易员总开关
CFocusFtdcUserSwitchField["WholeSwitch"] = "char"
#自动报价
CFocusFtdcUserSwitchField["WholeOffer"] = "char"
#自动回应询价
CFocusFtdcUserSwitchField["WholeRespAsking"] = "char"
#自动对冲
CFocusFtdcUserSwitchField["WholeHedge"] = "char"
structDict['CFocusFtdcUserSwitchField'] = CFocusFtdcUserSwitchField


#做市对冲
CFocusFtdcMarkerHedgeField = {}
#对冲标的
CFocusFtdcMarkerHedgeField["UnderlyingId"] = "string"
#产品代码
CFocusFtdcMarkerHedgeField["ProductID"] = "string"
#投资者编号
CFocusFtdcMarkerHedgeField["InvestorID"] = "string"
#期权系列
CFocusFtdcMarkerHedgeField["OptionSeriesId"] = "string"
#用户代码
CFocusFtdcMarkerHedgeField["UserID"] = "string"
#自动对冲
CFocusFtdcMarkerHedgeField["AutoHedge"] = "char"
#对冲报价类型
CFocusFtdcMarkerHedgeField["HedgePriceType"] = "char"
#对冲算法
CFocusFtdcMarkerHedgeField["HdegeType"] = "char"
#对冲周期
CFocusFtdcMarkerHedgeField["HedgePeriod"] = "int"
#Delta上限
CFocusFtdcMarkerHedgeField["DeltaMax"] = "float"
#Delta下限
CFocusFtdcMarkerHedgeField["DelatMin"] = "float"
#最后对冲时间
CFocusFtdcMarkerHedgeField["LastHedgeTime"] = "string"
#默认下单时的冲击成本
CFocusFtdcMarkerHedgeField["OrderPriceSlip"] = "int"
structDict['CFocusFtdcMarkerHedgeField'] = CFocusFtdcMarkerHedgeField


#拟合参数
CFocusFtdcFittingParamField = {}
#用户代码
CFocusFtdcFittingParamField["UserID"] = "string"
#产品代码
CFocusFtdcFittingParamField["ProductID"] = "string"
#期权系列
CFocusFtdcFittingParamField["OptionSeriesId"] = "string"
#拟合模型
CFocusFtdcFittingParamField["FitModel"] = "char"
#CallBid开关
CFocusFtdcFittingParamField["CallBidFlag"] = "char"
#CallAsk开关
CFocusFtdcFittingParamField["CallAskFlag"] = "char"
#PutBid开关
CFocusFtdcFittingParamField["PutBidFlag"] = "char"
#PutAsk开关
CFocusFtdcFittingParamField["PutAskFlag"] = "char"
#CallMid开关
CFocusFtdcFittingParamField["CallMidFlag"] = "char"
#PutMid开关
CFocusFtdcFittingParamField["PutMidFlag"] = "char"
#OTM开关
CFocusFtdcFittingParamField["OTMFlag"] = "char"
#自动剔除异常值
CFocusFtdcFittingParamField["AutoRemoveOutlier"] = "char"
#有效区间上限
CFocusFtdcFittingParamField["ValidIntervalMax"] = "float"
#有效区间下限
CFocusFtdcFittingParamField["ValidIntervalMin"] = "float"
#自动拟合
CFocusFtdcFittingParamField["AutoFit"] = "char"
#自动拟合间隔时间
CFocusFtdcFittingParamField["AUTO_FIT_TIME"] = "int"
structDict['CFocusFtdcFittingParamField'] = CFocusFtdcFittingParamField


#拟合参数查询请求
CFocusFtdcQryFittingParamField = {}
#用户代码
CFocusFtdcQryFittingParamField["UserID"] = "string"
#产品代码
CFocusFtdcQryFittingParamField["ProductID"] = "string"
#期权系列
CFocusFtdcQryFittingParamField["OptionSeriesId"] = "string"
structDict['CFocusFtdcQryFittingParamField'] = CFocusFtdcQryFittingParamField


#查询价格参数设置
CFocusFtdcQryPricingParamField = {}
#用户代码
CFocusFtdcQryPricingParamField["UserID"] = "string"
#期权系列
CFocusFtdcQryPricingParamField["OptionSeriesId"] = "string"
structDict['CFocusFtdcQryPricingParamField'] = CFocusFtdcQryPricingParamField


#查询期权理论波动率设置
CFocusFtdcQryOptionTheoryVolField = {}
#用户代码
CFocusFtdcQryOptionTheoryVolField["UserID"] = "string"
#合约代码
CFocusFtdcQryOptionTheoryVolField["InstrumentID"] = "string"
structDict['CFocusFtdcQryOptionTheoryVolField'] = CFocusFtdcQryOptionTheoryVolField


#输入报价
CFocusFtdcInputQuoteField = {}
#交易日
CFocusFtdcInputQuoteField["TradingDay"] = "string"
#交易所代码
CFocusFtdcInputQuoteField["ExchangeID"] = "string"
#经纪公司编号
CFocusFtdcInputQuoteField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcInputQuoteField["UserID"] = "string"
#资金帐号
CFocusFtdcInputQuoteField["AccountID"] = "string"
#投资者编号
CFocusFtdcInputQuoteField["InvestorID"] = "string"
#本地参考编号
CFocusFtdcInputQuoteField["QuoteRef"] = "string"
#本地报价编号
CFocusFtdcInputQuoteField["QuoteLocalID"] = "string"
#买本地参考报价编号
CFocusFtdcInputQuoteField["AskOrderRef"] = "string"
#卖本地参考报价编号
CFocusFtdcInputQuoteField["BidOrderRef"] = "string"
#报价编号
CFocusFtdcInputQuoteField["QuoteSysID"] = "string"
#应价编号
CFocusFtdcInputQuoteField["ForQuoteSysID"] = "string"
#买入数量
CFocusFtdcInputQuoteField["BidVolume"] = "int"
#卖出数量
CFocusFtdcInputQuoteField["AskVolume"] = "int"
#合约代码
CFocusFtdcInputQuoteField["InstrumentID"] = "string"
#业务单元
CFocusFtdcInputQuoteField["BusinessUnit"] = "string"
#买方组合开平标志
CFocusFtdcInputQuoteField["BidOffsetFlag"] = "char"
#买方组合套保标志
CFocusFtdcInputQuoteField["BidHedgeFlag"] = "char"
#买方价格
CFocusFtdcInputQuoteField["BidPrice"] = "float"
#卖方组合开平标志
CFocusFtdcInputQuoteField["AskOffsetFlag"] = "char"
#卖方组合套保标志
CFocusFtdcInputQuoteField["AskHedgeFlag"] = "char"
#卖方价格
CFocusFtdcInputQuoteField["AskPrice"] = "float"
#用户自定义域
CFocusFtdcInputQuoteField["UserCustom"] = "string"
#是否自动交易
CFocusFtdcInputQuoteField["IsAuto"] = "char"
#交易API中的序号
CFocusFtdcInputQuoteField["APIID"] = "int"
#备注
CFocusFtdcInputQuoteField["Remark"] = "string"
structDict['CFocusFtdcInputQuoteField'] = CFocusFtdcInputQuoteField


#报价操作
CFocusFtdcQuoteActionField = {}
#交易日
CFocusFtdcQuoteActionField["TradingDay"] = "string"
#交易所代码
CFocusFtdcQuoteActionField["ExchangeID"] = "string"
#经纪公司编号
CFocusFtdcQuoteActionField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcQuoteActionField["UserID"] = "string"
#资金帐号
CFocusFtdcQuoteActionField["AccountID"] = "string"
#投资者编号
CFocusFtdcQuoteActionField["InvestorID"] = "string"
#报价编号
CFocusFtdcQuoteActionField["QuoteSysID"] = "string"
#本地报价编号
CFocusFtdcQuoteActionField["QuoteLocalID"] = "string"
#合约代码
CFocusFtdcQuoteActionField["InstrumentID"] = "string"
#报单操作标志
CFocusFtdcQuoteActionField["ActionFlag"] = "char"
#会员代码
CFocusFtdcQuoteActionField["ParticipantID"] = "string"
#客户代码
CFocusFtdcQuoteActionField["ClientID"] = "string"
#操作本地编号
CFocusFtdcQuoteActionField["ActionLocalID"] = "string"
#业务单元
CFocusFtdcQuoteActionField["BusinessUnit"] = "string"
#用户自定义域
CFocusFtdcQuoteActionField["UserCustom"] = "string"
#交易API中的序号
CFocusFtdcQuoteActionField["APIID"] = "int"
structDict['CFocusFtdcQuoteActionField'] = CFocusFtdcQuoteActionField


#报价查询
CFocusFtdcQryQuoteField = {}
#投资者编号
CFocusFtdcQryQuoteField["InvestorID"] = "string"
#系统报价编号
CFocusFtdcQryQuoteField["QuoteSysID"] = "string"
#客户代码
CFocusFtdcQryQuoteField["ClientID"] = "string"
#合约代码
CFocusFtdcQryQuoteField["InstrumentID"] = "string"
#交易用户代码
CFocusFtdcQryQuoteField["UserID"] = "string"
structDict['CFocusFtdcQryQuoteField'] = CFocusFtdcQryQuoteField


#报价
CFocusFtdcQuoteField = {}
#交易日
CFocusFtdcQuoteField["TradingDay"] = "string"
#交易所代码
CFocusFtdcQuoteField["ExchangeID"] = "string"
#经纪公司编号
CFocusFtdcQuoteField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcQuoteField["UserID"] = "string"
#资金帐号
CFocusFtdcQuoteField["AccountID"] = "string"
#投资者编号
CFocusFtdcQuoteField["InvestorID"] = "string"
#本地参考编号
CFocusFtdcQuoteField["QuoteRef"] = "string"
#本地报价编号
CFocusFtdcQuoteField["QuoteLocalID"] = "string"
#买本地参考报价编号
CFocusFtdcQuoteField["AskOrderRef"] = "string"
#卖本地参考报价编号
CFocusFtdcQuoteField["BidOrderRef"] = "string"
#报价编号
CFocusFtdcQuoteField["QuoteSysID"] = "string"
#应价编号
CFocusFtdcQuoteField["ForQuoteSysID"] = "string"
#买入数量
CFocusFtdcQuoteField["BidVolume"] = "int"
#卖出数量
CFocusFtdcQuoteField["AskVolume"] = "int"
#合约代码
CFocusFtdcQuoteField["InstrumentID"] = "string"
#业务单元
CFocusFtdcQuoteField["BusinessUnit"] = "string"
#买方组合开平标志
CFocusFtdcQuoteField["BidOffsetFlag"] = "char"
#买方组合套保标志
CFocusFtdcQuoteField["BidHedgeFlag"] = "char"
#买方价格
CFocusFtdcQuoteField["BidPrice"] = "float"
#卖方组合开平标志
CFocusFtdcQuoteField["AskOffsetFlag"] = "char"
#卖方组合套保标志
CFocusFtdcQuoteField["AskHedgeFlag"] = "char"
#卖方价格
CFocusFtdcQuoteField["AskPrice"] = "float"
#用户自定义域
CFocusFtdcQuoteField["UserCustom"] = "string"
#是否自动交易
CFocusFtdcQuoteField["IsAuto"] = "char"
#交易API中的序号
CFocusFtdcQuoteField["APIID"] = "int"
#备注
CFocusFtdcQuoteField["Remark"] = "string"
#插入时间
CFocusFtdcQuoteField["InsertTime"] = "string"
#撤销时间
CFocusFtdcQuoteField["CancelTime"] = "string"
#成交时间
CFocusFtdcQuoteField["TradeTime"] = "string"
#买方报单编号
CFocusFtdcQuoteField["BidOrderSysID"] = "string"
#卖方报单编号
CFocusFtdcQuoteField["AskOrderSysID"] = "string"
#报单状态
CFocusFtdcQuoteField["QuoteStatus"] = "char"
#报单提交状态
CFocusFtdcQuoteField["OrderSubmitStatus"] = "char"
structDict['CFocusFtdcQuoteField'] = CFocusFtdcQuoteField


#询价
CFocusFtdcInputReqForQuoteField = {}
#交易日
CFocusFtdcInputReqForQuoteField["TradingDay"] = "string"
#交易所代码
CFocusFtdcInputReqForQuoteField["ExchangeID"] = "string"
#经纪公司编号
CFocusFtdcInputReqForQuoteField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcInputReqForQuoteField["UserID"] = "string"
#资金帐号
CFocusFtdcInputReqForQuoteField["AccountID"] = "string"
#投资者编号
CFocusFtdcInputReqForQuoteField["InvestorID"] = "string"
#询价编号
CFocusFtdcInputReqForQuoteField["ReqForQuoteID"] = "string"
#客户代码
CFocusFtdcInputReqForQuoteField["ClientID"] = "string"
#合约代码
CFocusFtdcInputReqForQuoteField["InstrumentID"] = "string"
#询价时间
CFocusFtdcInputReqForQuoteField["ReqForQuoteTime"] = "string"
#用户本地报单号
CFocusFtdcInputReqForQuoteField["ForQuoteLocalID"] = "string"
structDict['CFocusFtdcInputReqForQuoteField'] = CFocusFtdcInputReqForQuoteField


#错单查询
CFocusFtdcQryOrderInsertFailedField = {}
#经纪公司编号
CFocusFtdcQryOrderInsertFailedField["BrokerID"] = "string"
#用户代码
CFocusFtdcQryOrderInsertFailedField["UserID"] = "string"
#交易所代码
CFocusFtdcQryOrderInsertFailedField["ExchangeID"] = "string"
#投资者编号
CFocusFtdcQryOrderInsertFailedField["InvestorID"] = "string"
#报单编号
CFocusFtdcQryOrderInsertFailedField["OrderSysID"] = "string"
#合约代码
CFocusFtdcQryOrderInsertFailedField["InstrumentID"] = "string"
#登录经纪公司编号
CFocusFtdcQryOrderInsertFailedField["LogBrokerID"] = "string"
#登录用户代码
CFocusFtdcQryOrderInsertFailedField["LogUserID"] = "string"
structDict['CFocusFtdcQryOrderInsertFailedField'] = CFocusFtdcQryOrderInsertFailedField


#错单表
CFocusFtdcOrderInsertFailedField = {}
#经纪公司编号
CFocusFtdcOrderInsertFailedField["BrokerID"] = "string"
#投资者编号
CFocusFtdcOrderInsertFailedField["InvestorID"] = "string"
#用户代码
CFocusFtdcOrderInsertFailedField["UserID"] = "string"
#用户本地报单号
CFocusFtdcOrderInsertFailedField["UserOrderLocalID"] = "string"
#用户自定义域
CFocusFtdcOrderInsertFailedField["UserCustom"] = "string"
#交易所代码
CFocusFtdcOrderInsertFailedField["ExchangeID"] = "string"
#系统报单编号
CFocusFtdcOrderInsertFailedField["OrderSysID"] = "string"
#股票委托批号(仅批量委托有效)
CFocusFtdcOrderInsertFailedField["BatchNum"] = "string"
#合约代码
CFocusFtdcOrderInsertFailedField["InstrumentID"] = "string"
#合约名称
CFocusFtdcOrderInsertFailedField["InstrumentName"] = "string"
#报单类型
CFocusFtdcOrderInsertFailedField["OrderPriceType"] = "char"
#买卖方向
CFocusFtdcOrderInsertFailedField["Direction"] = "char"
#开平标志
CFocusFtdcOrderInsertFailedField["OffsetFlag"] = "char"
#投机套保标志
CFocusFtdcOrderInsertFailedField["HedgeFlag"] = "char"
#价格
CFocusFtdcOrderInsertFailedField["LimitPrice"] = "float"
#数量
CFocusFtdcOrderInsertFailedField["Volume"] = "int"
#有效期类型
CFocusFtdcOrderInsertFailedField["TimeCondition"] = "char"
#GTD日期
CFocusFtdcOrderInsertFailedField["GTDDate"] = "string"
#成交量类型
CFocusFtdcOrderInsertFailedField["VolumeCondition"] = "char"
#最小成交量
CFocusFtdcOrderInsertFailedField["MinVolume"] = "int"
#止损价
CFocusFtdcOrderInsertFailedField["StopPrice"] = "float"
#强平原因
CFocusFtdcOrderInsertFailedField["ForceCloseReason"] = "char"
#自动挂起标志
CFocusFtdcOrderInsertFailedField["IsAutoSuspend"] = "int"
#业务单元
CFocusFtdcOrderInsertFailedField["BusinessUnit"] = "string"
#业务类别
CFocusFtdcOrderInsertFailedField["BusinessType"] = "char"
#交易日
CFocusFtdcOrderInsertFailedField["TradingDay"] = "string"
#插入时间
CFocusFtdcOrderInsertFailedField["InsertTime"] = "string"
#报单来源
CFocusFtdcOrderInsertFailedField["OrderSource"] = "char"
#报单状态
CFocusFtdcOrderInsertFailedField["OrderStatus"] = "char"
#撤销时间
CFocusFtdcOrderInsertFailedField["CancelTime"] = "string"
#撤单用户编号
CFocusFtdcOrderInsertFailedField["CancelUserID"] = "string"
#已经成交数量
CFocusFtdcOrderInsertFailedField["VolumeTraded"] = "int"
#队列剩余数量
CFocusFtdcOrderInsertFailedField["VolumeRemain"] = "int"
#已经撤单数量
CFocusFtdcOrderInsertFailedField["VolumeCancled"] = "int"
#错误代码
CFocusFtdcOrderInsertFailedField["ErrorID"] = "int"
#错误信息
CFocusFtdcOrderInsertFailedField["ErrorMsg"] = "string"
#比上次增加的撤单数量
CFocusFtdcOrderInsertFailedField["VolumeIncCancled"] = "int"
#比上次增加的成交数量
CFocusFtdcOrderInsertFailedField["VolumeIncTraded"] = "int"
#资金帐号
CFocusFtdcOrderInsertFailedField["AccountID"] = "string"
#前置编号
CFocusFtdcOrderInsertFailedField["FrontID"] = "int"
#会话编号
CFocusFtdcOrderInsertFailedField["SessionID"] = "int"
#请求编号
CFocusFtdcOrderInsertFailedField["RequestID"] = "int"
#每手手续费
CFocusFtdcOrderInsertFailedField["EachFee"] = "float"
#每手保证金
CFocusFtdcOrderInsertFailedField["EachMargin"] = "float"
#每手期权权利金收支
CFocusFtdcOrderInsertFailedField["EachPremium"] = "float"
#下单IP地址
CFocusFtdcOrderInsertFailedField["IPAddress"] = "string"
#下单MAC地址
CFocusFtdcOrderInsertFailedField["MacAddress"] = "string"
#营业部代码
CFocusFtdcOrderInsertFailedField["BranchID"] = "string"
#记录编号
CFocusFtdcOrderInsertFailedField["RecNum"] = "int"
#会员编号
CFocusFtdcOrderInsertFailedField["ParticipantID"] = "string"
#客户号
CFocusFtdcOrderInsertFailedField["ClientID"] = "string"
#下单席位号
CFocusFtdcOrderInsertFailedField["SeatID"] = "string"
#本地报单编号
CFocusFtdcOrderInsertFailedField["OrderLocalID"] = "string"
#子资金帐号
CFocusFtdcOrderInsertFailedField["SubAccountID"] = "string"
#下单用户编号
CFocusFtdcOrderInsertFailedField["OrderUserID"] = "string"
#交易类型
CFocusFtdcOrderInsertFailedField["TradeType"] = "char"
#处理标志
CFocusFtdcOrderInsertFailedField["DealFlag"] = "char"
#已成交佣金
CFocusFtdcOrderInsertFailedField["TradeCommision"] = "float"
#成交金额
CFocusFtdcOrderInsertFailedField["TradeAmnt"] = "float"
#通过本地报单号推出的子投资者编号
CFocusFtdcOrderInsertFailedField["SubInvestorID"] = "string"
#投资者类型
CFocusFtdcOrderInsertFailedField["InvestorType"] = "char"
#子报单编号
CFocusFtdcOrderInsertFailedField["SubOrderSysID"] = "string"
#父投资者编号
CFocusFtdcOrderInsertFailedField["ParentInvestorCode"] = "char"
#使用哪个通道下单
CFocusFtdcOrderInsertFailedField["APIID"] = "int"
#平仓冻结数量
CFocusFtdcOrderInsertFailedField["VolumeFrozenClosing"] = "int"
#冻结数量
CFocusFtdcOrderInsertFailedField["VolumeFrozen"] = "int"
#本报单冻结了多少资金
CFocusFtdcOrderInsertFailedField["FrozenMoney"] = "float"
#工作流报单编号
CFocusFtdcOrderInsertFailedField["AdviceOrderSysID"] = "string"
#证券哪个产品
CFocusFtdcOrderInsertFailedField["ProductID"] = "string"
#本报单冻结了多少手续费
CFocusFtdcOrderInsertFailedField["FrozenFee"] = "float"
#本报单冻结了多少过户费
CFocusFtdcOrderInsertFailedField["FrozenTransferFee"] = "float"
#本报单冻结了多少印花税
CFocusFtdcOrderInsertFailedField["FrozenStampTax"] = "float"
#申赎仓冻结数量
CFocusFtdcOrderInsertFailedField["PurRedVolumeFrozen"] = "int"
#今买卖仓冻结数量
CFocusFtdcOrderInsertFailedField["CloseVolumeFrozen"] = "int"
#备注
CFocusFtdcOrderInsertFailedField["Remark"] = "string"
structDict['CFocusFtdcOrderInsertFailedField'] = CFocusFtdcOrderInsertFailedField


#定价合约价差
CFocusFtdcPriceSpreadField = {}
#用户代码(交易员)
CFocusFtdcPriceSpreadField["UserID"] = "string"
#期权系列
CFocusFtdcPriceSpreadField["OptionSeriesId"] = "string"
#价差
CFocusFtdcPriceSpreadField["Spread"] = "float"
#价差合约代码
CFocusFtdcPriceSpreadField["SpreadInstrumentId"] = "string"
#价差设置方式
CFocusFtdcPriceSpreadField["PriceSpreadType"] = "char"
structDict['CFocusFtdcPriceSpreadField'] = CFocusFtdcPriceSpreadField


#查询合约价差
CFocusFtdcQryPriceSpreadField = {}
#用户代码(交易员)
CFocusFtdcQryPriceSpreadField["UserID"] = "string"
#期权系列
CFocusFtdcQryPriceSpreadField["OptionSeriesId"] = "string"
structDict['CFocusFtdcQryPriceSpreadField'] = CFocusFtdcQryPriceSpreadField


#查询做市对冲
CFocusFtdcQryMarkerHedgeField = {}
#投资者编号
CFocusFtdcQryMarkerHedgeField["InvestorID"] = "string"
#用户代码
CFocusFtdcQryMarkerHedgeField["UserID"] = "string"
#期权系列
CFocusFtdcQryMarkerHedgeField["OptionSeriesId"] = "string"
structDict['CFocusFtdcQryMarkerHedgeField'] = CFocusFtdcQryMarkerHedgeField


#做市日志信息
CFocusFtdcStrategyLogField = {}
#日志编号
CFocusFtdcStrategyLogField["EventID"] = "int"
#交易日期
CFocusFtdcStrategyLogField["TradingDay"] = "string"
#做市事件类型
CFocusFtdcStrategyLogField["EventType"] = "char"
#做市事件代码
CFocusFtdcStrategyLogField["EventCode"] = "int"
#用户代码
CFocusFtdcStrategyLogField["UserID"] = "string"
#投资者编号
CFocusFtdcStrategyLogField["InvestorID"] = "string"
#合约代码
CFocusFtdcStrategyLogField["InstrumentID"] = "string"
#日志内容
CFocusFtdcStrategyLogField["Log_Content"] = "string"
#操作日期
CFocusFtdcStrategyLogField["OperDate"] = "string"
#操作时间
CFocusFtdcStrategyLogField["OperTime"] = "string"
structDict['CFocusFtdcStrategyLogField'] = CFocusFtdcStrategyLogField


#预警指标设置
CFocusFtdcAlertIndexSetParamField = {}
#产品名称
CFocusFtdcAlertIndexSetParamField["ProductID"] = "string"
#期权系列
CFocusFtdcAlertIndexSetParamField["OptionSeriesId"] = "string"
#投资者编号
CFocusFtdcAlertIndexSetParamField["InvestorID"] = "string"
#投资者类型
CFocusFtdcAlertIndexSetParamField["InvestorType"] = "char"
#用户代码(交易员)
CFocusFtdcAlertIndexSetParamField["UserID"] = "string"
#指标明细代码
CFocusFtdcAlertIndexSetParamField["AlertIndexCode"] = "char"
#黄色预警上限
CFocusFtdcAlertIndexSetParamField["MAX_L1"] = "float"
#黄色预警下限
CFocusFtdcAlertIndexSetParamField["MIN_L1"] = "float"
#红色预警上限
CFocusFtdcAlertIndexSetParamField["MAX_L2"] = "float"
#红色预警下限
CFocusFtdcAlertIndexSetParamField["MIN_L2"] = "float"
#默认时间间隔
CFocusFtdcAlertIndexSetParamField["TimeAvail"] = "int"
#红色预警操作
CFocusFtdcAlertIndexSetParamField["AlertAction"] = "char"
structDict['CFocusFtdcAlertIndexSetParamField'] = CFocusFtdcAlertIndexSetParamField


#查询预警指标设置
CFocusFtdcQryAlertIndexSetParamField = {}
#产品名称
CFocusFtdcQryAlertIndexSetParamField["ProductID"] = "string"
#期权系列
CFocusFtdcQryAlertIndexSetParamField["OptionSeriesId"] = "string"
#投资者编号
CFocusFtdcQryAlertIndexSetParamField["InvestorID"] = "string"
#用户代码(交易员)
CFocusFtdcQryAlertIndexSetParamField["UserID"] = "string"
#投资者类型
CFocusFtdcQryAlertIndexSetParamField["InvestorType"] = "char"
#指标明细代码
CFocusFtdcQryAlertIndexSetParamField["AlertIndexCode"] = "char"
structDict['CFocusFtdcQryAlertIndexSetParamField'] = CFocusFtdcQryAlertIndexSetParamField


#预警指标值
CFocusFtdcAlertIndexSetDataField = {}
#产品名称
CFocusFtdcAlertIndexSetDataField["ProductID"] = "string"
#期权系列
CFocusFtdcAlertIndexSetDataField["OptionSeriesId"] = "string"
#投资者编号
CFocusFtdcAlertIndexSetDataField["InvestorID"] = "string"
#用户代码(交易员)
CFocusFtdcAlertIndexSetDataField["UserID"] = "string"
#指标明细代码
CFocusFtdcAlertIndexSetDataField["AlertIndexCode"] = "char"
#指标明细值
CFocusFtdcAlertIndexSetDataField["IndexVolume"] = "float"
#黄色预警上限
CFocusFtdcAlertIndexSetDataField["MAX_L1"] = "float"
#黄色预警下限
CFocusFtdcAlertIndexSetDataField["MIN_L1"] = "float"
#红色预警上限
CFocusFtdcAlertIndexSetDataField["MAX_L2"] = "float"
#红色预警下限
CFocusFtdcAlertIndexSetDataField["MIN_L2"] = "float"
#预警操作
CFocusFtdcAlertIndexSetDataField["AlertAction"] = "char"
#输出值日期
CFocusFtdcAlertIndexSetDataField["OperDate"] = "string"
#输出值时间
CFocusFtdcAlertIndexSetDataField["OperTime"] = "string"
structDict['CFocusFtdcAlertIndexSetDataField'] = CFocusFtdcAlertIndexSetDataField


#做市报价累计持仓
CFocusFtdcQuoteTotalTradePositionField = {}
#用户代码(交易员)
CFocusFtdcQuoteTotalTradePositionField["UserID"] = "string"
#投资者编号
CFocusFtdcQuoteTotalTradePositionField["InvestorID"] = "string"
#合约代码
CFocusFtdcQuoteTotalTradePositionField["InstrumentID"] = "string"
#当日累计买成交，不管开平
CFocusFtdcQuoteTotalTradePositionField["BuyVolume"] = "int"
#当日累计卖成交，不管开平
CFocusFtdcQuoteTotalTradePositionField["SellVolume"] = "int"
#当日净成交，不管开平
CFocusFtdcQuoteTotalTradePositionField["NetVolume"] = "int"
#当日买持仓，多头持仓
CFocusFtdcQuoteTotalTradePositionField["BuyPosition"] = "int"
#当日卖持仓，空头持仓
CFocusFtdcQuoteTotalTradePositionField["SellPosition"] = "int"
#当日净持仓
CFocusFtdcQuoteTotalTradePositionField["NetPosition"] = "int"
structDict['CFocusFtdcQuoteTotalTradePositionField'] = CFocusFtdcQuoteTotalTradePositionField


#交易所梯度价差
CFocusFtdcMarkerStepField = {}
#梯度模板
CFocusFtdcMarkerStepField["StepID"] = "string"
#梯度名称
CFocusFtdcMarkerStepField["StepName"] = "string"
#产品名称
CFocusFtdcMarkerStepField["ProductID"] = "string"
#用户代码
CFocusFtdcMarkerStepField["UserID"] = "string"
#梯度类型
CFocusFtdcMarkerStepField["StepType"] = "char"
#梯度单位
CFocusFtdcMarkerStepField["WidthType"] = "char"
#价格下限
CFocusFtdcMarkerStepField["LowPrice"] = "float"
#价格上限
CFocusFtdcMarkerStepField["UpPrice"] = "float"
#StepValue1
CFocusFtdcMarkerStepField["StepValue1"] = "float"
#StepValue2
CFocusFtdcMarkerStepField["StepValue2"] = "float"
#StepValue3
CFocusFtdcMarkerStepField["StepValue3"] = "float"
#value键值
CFocusFtdcMarkerStepField["StepValueKey"] = "int"
structDict['CFocusFtdcMarkerStepField'] = CFocusFtdcMarkerStepField


#做市报价移动策略
CFocusFtdcQuoteMoveField = {}
#产品名称
CFocusFtdcQuoteMoveField["ProductID"] = "string"
#用户代码(交易员)
CFocusFtdcQuoteMoveField["UserID"] = "string"
#期权系列
CFocusFtdcQuoteMoveField["OptionSeriesId"] = "string"
#成交统计时间（秒）
CFocusFtdcQuoteMoveField["SumVolumeTime"] = "int"
#成交数量（净成交，不区分正负）
CFocusFtdcQuoteMoveField["SumVolume"] = "int"
#报价偏移（百分比）
CFocusFtdcQuoteMoveField["Move"] = "float"
#维持时间（秒）
CFocusFtdcQuoteMoveField["KeepTime"] = "int"
#立即成交报价策略:0：单边 1：双边
CFocusFtdcQuoteMoveField["TakeOut"] = "char"
#关闭：0，开启：1
CFocusFtdcQuoteMoveField["IsActive"] = "char"
#临近执行价偏移：关闭：0，开启：1
CFocusFtdcQuoteMoveField["NearStrikeMove"] = "char"
#临近执行价波动率差值
CFocusFtdcQuoteMoveField["NearStrikeVolSpread"] = "float"
#临近执行价移动类型：0：理论价反手 1：对手价反手
CFocusFtdcQuoteMoveField["NearMoveType"] = "char"
#临近执行价维持时间（秒）
CFocusFtdcQuoteMoveField["NearKeepTime"] = "int"
structDict['CFocusFtdcQuoteMoveField'] = CFocusFtdcQuoteMoveField


#基础梯度价差信息
CFocusFtdcBaseMarkerStepField = {}
#梯度模板
CFocusFtdcBaseMarkerStepField["StepID"] = "string"
#梯度名称
CFocusFtdcBaseMarkerStepField["StepName"] = "string"
#产品名称
CFocusFtdcBaseMarkerStepField["ProductID"] = "string"
#用户代码
CFocusFtdcBaseMarkerStepField["UserID"] = "string"
#梯度类型
CFocusFtdcBaseMarkerStepField["StepType"] = "char"
#梯度单位
CFocusFtdcBaseMarkerStepField["WidthType"] = "char"
structDict['CFocusFtdcBaseMarkerStepField'] = CFocusFtdcBaseMarkerStepField


#后台进程交易状态
CFocusFtdcFocusStatusField = {}
#用户代码
CFocusFtdcFocusStatusField["UserID"] = "string"
#进程交易状态
CFocusFtdcFocusStatusField["TradeStatus"] = "char"
structDict['CFocusFtdcFocusStatusField'] = CFocusFtdcFocusStatusField


#ATM价格
CFocusFtdcATMPriceDataField = {}
#用户代码(交易员)
CFocusFtdcATMPriceDataField["UserID"] = "string"
#期权系列
CFocusFtdcATMPriceDataField["OptionSeriesId"] = "string"
#标的价格，计算理论价，Greeks请传这个
CFocusFtdcATMPriceDataField["UnderlyingMid"] = "float"
#标的远期价格
CFocusFtdcATMPriceDataField["AtmForword"] = "float"
#剩余天数
CFocusFtdcATMPriceDataField["RemainDay"] = "float"
#V10D
CFocusFtdcATMPriceDataField["V10D"] = "float"
#V10D
CFocusFtdcATMPriceDataField["V25D"] = "float"
#V10D
CFocusFtdcATMPriceDataField["V45D"] = "float"
#ATM 波动率
CFocusFtdcATMPriceDataField["AtmVol"] = "float"
#V10D
CFocusFtdcATMPriceDataField["V55D"] = "float"
#V10D
CFocusFtdcATMPriceDataField["V75D"] = "float"
#V10D
CFocusFtdcATMPriceDataField["V90D"] = "float"
#输出值时间
CFocusFtdcATMPriceDataField["OperTime"] = "string"
structDict['CFocusFtdcATMPriceDataField'] = CFocusFtdcATMPriceDataField


#期货做市总开关
CFocusFtdcFutureMakerWholeSwitchField = {}
#用户代码
CFocusFtdcFutureMakerWholeSwitchField["UserID"] = "string"
#投资者编号
CFocusFtdcFutureMakerWholeSwitchField["InvestorID"] = "string"
#交易所代码
CFocusFtdcFutureMakerWholeSwitchField["ExchangeID"] = "string"
#合约代码
CFocusFtdcFutureMakerWholeSwitchField["InstrumentID"] = "string"
#交易员总开关
CFocusFtdcFutureMakerWholeSwitchField["WholeSwitch"] = "char"
structDict['CFocusFtdcFutureMakerWholeSwitchField'] = CFocusFtdcFutureMakerWholeSwitchField


#期货做市报价参数
CFocusFtdcFutureMakerStrategyField = {}
#用户代码
CFocusFtdcFutureMakerStrategyField["UserID"] = "string"
#投资者编号
CFocusFtdcFutureMakerStrategyField["InvestorID"] = "string"
#交易所代码
CFocusFtdcFutureMakerStrategyField["ExchangeID"] = "string"
#合约代码
CFocusFtdcFutureMakerStrategyField["InstrumentID"] = "string"
#一档开关
CFocusFtdcFutureMakerStrategyField["FirstSwitch"] = "char"
#一档期货报价方式
CFocusFtdcFutureMakerStrategyField["FirstFutureMakerFlag"] = "char"
#一档容忍度
CFocusFtdcFutureMakerStrategyField["FirstToler"] = "int"
#一档下单量
CFocusFtdcFutureMakerStrategyField["FirstAmount"] = "int"
#一档宽度（tick）
CFocusFtdcFutureMakerStrategyField["FirstWidth"] = "int"
#二档开关
CFocusFtdcFutureMakerStrategyField["SecondSwitch"] = "char"
#二档期货报价方式
CFocusFtdcFutureMakerStrategyField["SecondFutureMakerFlag"] = "char"
#二档容忍度
CFocusFtdcFutureMakerStrategyField["SecondToler"] = "int"
#二档下单量
CFocusFtdcFutureMakerStrategyField["SecondAmount"] = "int"
#二档宽度（tick）
CFocusFtdcFutureMakerStrategyField["SecondWidth"] = "int"
#三档开关
CFocusFtdcFutureMakerStrategyField["ThirdSwitch"] = "char"
#三档期货报价方式
CFocusFtdcFutureMakerStrategyField["ThirdFutureMakerFlag"] = "char"
#三档容忍度
CFocusFtdcFutureMakerStrategyField["ThirdToler"] = "int"
#三档下单量
CFocusFtdcFutureMakerStrategyField["ThirdAmount"] = "int"
#三档宽度（tick）
CFocusFtdcFutureMakerStrategyField["ThirdWidth"] = "int"
#成交统计时间（秒）
CFocusFtdcFutureMakerStrategyField["SumVolumeTime"] = "int"
#成交数量（净成交，不区分正负）
CFocusFtdcFutureMakerStrategyField["SumVolume"] = "int"
#维持时间（秒）
CFocusFtdcFutureMakerStrategyField["KeepTime"] = "int"
#期货开平标志
CFocusFtdcFutureMakerStrategyField["FutureOffsetFlag"] = "char"
structDict['CFocusFtdcFutureMakerStrategyField'] = CFocusFtdcFutureMakerStrategyField


#期货反手对冲参数
CFocusFtdcSlefHedgeStrategyField = {}
#用户代码
CFocusFtdcSlefHedgeStrategyField["UserID"] = "string"
#投资者编号
CFocusFtdcSlefHedgeStrategyField["InvestorID"] = "string"
#交易所代码
CFocusFtdcSlefHedgeStrategyField["ExchangeID"] = "string"
#合约代码
CFocusFtdcSlefHedgeStrategyField["InstrumentID"] = "string"
#反手报单报价方式
CFocusFtdcSlefHedgeStrategyField["SlefHedgeFutureMakerFlag"] = "char"
#反手报单调整tick
CFocusFtdcSlefHedgeStrategyField["SlefHedgeFutureMakerTick"] = "int"
#反手报单偏离tick重新报单
CFocusFtdcSlefHedgeStrategyField["SlefHedgeDeviate"] = "int"
#反手报单超时撤单
CFocusFtdcSlefHedgeStrategyField["SlefHedgeTimeAction"] = "int"
#反手追单次数
CFocusFtdcSlefHedgeStrategyField["SlefChaseTimes"] = "int"
#最大亏损
CFocusFtdcSlefHedgeStrategyField["MaxLossTick"] = "int"
structDict['CFocusFtdcSlefHedgeStrategyField'] = CFocusFtdcSlefHedgeStrategyField


#期货对冲合约对冲参数
CFocusFtdcFutureHedgeStrategyField = {}
#用户代码
CFocusFtdcFutureHedgeStrategyField["UserID"] = "string"
#投资者编号
CFocusFtdcFutureHedgeStrategyField["InvestorID"] = "string"
#交易所代码
CFocusFtdcFutureHedgeStrategyField["ExchangeID"] = "string"
#合约代码
CFocusFtdcFutureHedgeStrategyField["InstrumentID"] = "string"
#对冲合约交易所代码
CFocusFtdcFutureHedgeStrategyField["HedgeExchangeID"] = "string"
#对冲合约代码
CFocusFtdcFutureHedgeStrategyField["HedgeInstrumentID"] = "string"
#对冲资金账号
CFocusFtdcFutureHedgeStrategyField["HedgeInvestorID"] = "string"
#价差
CFocusFtdcFutureHedgeStrategyField["Spread"] = "float"
#期货对冲报价方式
CFocusFtdcFutureHedgeStrategyField["HedgeFutureMakerFlag"] = "char"
#期货对冲调整tick
CFocusFtdcFutureHedgeStrategyField["HedgeFutureMakerTick"] = "int"
#偏离tick重新报单
CFocusFtdcFutureHedgeStrategyField["HedgeDeviate"] = "int"
#挂单超时撤单
CFocusFtdcFutureHedgeStrategyField["HedgeTimeAction"] = "int"
#追单次数
CFocusFtdcFutureHedgeStrategyField["HedgeChaseTimes"] = "int"
#期货对冲合约开平标志
CFocusFtdcFutureHedgeStrategyField["HedgeOffsetFlag"] = "char"
structDict['CFocusFtdcFutureHedgeStrategyField'] = CFocusFtdcFutureHedgeStrategyField


#做市报价额外参数设置
CFocusFtdcQuoteAdditionParmField = {}
#合约代码
CFocusFtdcQuoteAdditionParmField["InstrumentID"] = "string"
#交易用户代码
CFocusFtdcQuoteAdditionParmField["UserID"] = "string"
#投资者编号
CFocusFtdcQuoteAdditionParmField["InvestorID"] = "string"
#报价价差宽度
CFocusFtdcQuoteAdditionParmField["QuotePriceWidth"] = "float"
#报价价差比
CFocusFtdcQuoteAdditionParmField["QuoteWidthRatio"] = "float"
#报价宽度单位
CFocusFtdcQuoteAdditionParmField["QuoteWidthType"] = "char"
#中心价容忍度
CFocusFtdcQuoteAdditionParmField["TOL_TICK"] = "int"
#备注
CFocusFtdcQuoteAdditionParmField["Remark"] = "string"
structDict['CFocusFtdcQuoteAdditionParmField'] = CFocusFtdcQuoteAdditionParmField


#期货对冲报价状态通知
CFocusFtdcFutureMakerHedgeStatusField = {}
#用户代码
CFocusFtdcFutureMakerHedgeStatusField["UserID"] = "string"
#投资者编号
CFocusFtdcFutureMakerHedgeStatusField["InvestorID"] = "string"
#交易所代码
CFocusFtdcFutureMakerHedgeStatusField["ExchangeID"] = "string"
#合约代码
CFocusFtdcFutureMakerHedgeStatusField["InstrumentID"] = "string"
#反手报单状态，0.无报单，1.有报单
CFocusFtdcFutureMakerHedgeStatusField["SlefHedgeStatus"] = "char"
#反手报单状态，0.无报单，1.有报单
CFocusFtdcFutureMakerHedgeStatusField["FutureHedgeStatus"] = "char"
structDict['CFocusFtdcFutureMakerHedgeStatusField'] = CFocusFtdcFutureMakerHedgeStatusField


#一键撤销所有期货做市对冲单
CFocusFtdcStopAllFutureMakerHedgeOfferField = {}
#用户代码
CFocusFtdcStopAllFutureMakerHedgeOfferField["UserID"] = "string"
#投资者编号
CFocusFtdcStopAllFutureMakerHedgeOfferField["InvestorID"] = "string"
#交易所代码
CFocusFtdcStopAllFutureMakerHedgeOfferField["ExchangeID"] = "string"
#合约代码
CFocusFtdcStopAllFutureMakerHedgeOfferField["InstrumentID"] = "string"
#0，反手对冲单，2， 期货对冲单  3. 全部对冲单
CFocusFtdcStopAllFutureMakerHedgeOfferField["HedgeOfferType"] = "string"
structDict['CFocusFtdcStopAllFutureMakerHedgeOfferField'] = CFocusFtdcStopAllFutureMakerHedgeOfferField


#期货做市键值
CFocusFtdcFutureMakerIndexField = {}
#用户代码
CFocusFtdcFutureMakerIndexField["UserID"] = "string"
#投资者编号
CFocusFtdcFutureMakerIndexField["InvestorID"] = "string"
#交易所代码
CFocusFtdcFutureMakerIndexField["ExchangeID"] = "string"
#合约代码
CFocusFtdcFutureMakerIndexField["InstrumentID"] = "string"
structDict['CFocusFtdcFutureMakerIndexField'] = CFocusFtdcFutureMakerIndexField


#查询期货做市参数
CFocusFtdcAllFutureMakerStrategyField = {}
#用户代码
CFocusFtdcAllFutureMakerStrategyField["UserID"] = "string"
#投资者编号
CFocusFtdcAllFutureMakerStrategyField["InvestorID"] = "string"
#交易所代码
CFocusFtdcAllFutureMakerStrategyField["ExchangeID"] = "string"
#合约代码
CFocusFtdcAllFutureMakerStrategyField["InstrumentID"] = "string"
#交易员总开关
CFocusFtdcAllFutureMakerStrategyField["WholeSwitch"] = "char"
#一档开关
CFocusFtdcAllFutureMakerStrategyField["FirstSwitch"] = "char"
#一档期货报价方式
CFocusFtdcAllFutureMakerStrategyField["FirstFutureMakerFlag"] = "char"
#一档容忍度
CFocusFtdcAllFutureMakerStrategyField["FirstToler"] = "int"
#一档下单量
CFocusFtdcAllFutureMakerStrategyField["FirstAmount"] = "int"
#一档宽度（tick）
CFocusFtdcAllFutureMakerStrategyField["FirstWidth"] = "int"
#二档开关
CFocusFtdcAllFutureMakerStrategyField["SecondSwitch"] = "char"
#二档期货报价方式
CFocusFtdcAllFutureMakerStrategyField["SecondFutureMakerFlag"] = "char"
#二档容忍度
CFocusFtdcAllFutureMakerStrategyField["SecondToler"] = "int"
#二档下单量
CFocusFtdcAllFutureMakerStrategyField["SecondAmount"] = "int"
#二档宽度（tick）
CFocusFtdcAllFutureMakerStrategyField["SecondWidth"] = "int"
#三档开关
CFocusFtdcAllFutureMakerStrategyField["ThirdSwitch"] = "char"
#三档期货报价方式
CFocusFtdcAllFutureMakerStrategyField["ThirdFutureMakerFlag"] = "char"
#三档容忍度
CFocusFtdcAllFutureMakerStrategyField["ThirdToler"] = "int"
#三档下单量
CFocusFtdcAllFutureMakerStrategyField["ThirdAmount"] = "int"
#三档宽度（tick）
CFocusFtdcAllFutureMakerStrategyField["ThirdWidth"] = "int"
#成交统计时间（秒）
CFocusFtdcAllFutureMakerStrategyField["SumVolumeTime"] = "int"
#成交数量（净成交，不区分正负）
CFocusFtdcAllFutureMakerStrategyField["SumVolume"] = "int"
#维持时间（秒）
CFocusFtdcAllFutureMakerStrategyField["KeepTime"] = "int"
#期货开平标志
CFocusFtdcAllFutureMakerStrategyField["FutureOffsetFlag"] = "char"
#反手报单报价方式
CFocusFtdcAllFutureMakerStrategyField["SlefHedgeFutureMakerFlag"] = "char"
#反手报单调整tick
CFocusFtdcAllFutureMakerStrategyField["SlefHedgeFutureMakerTick"] = "int"
#反手报单偏离tick重新报单
CFocusFtdcAllFutureMakerStrategyField["SlefHedgeDeviate"] = "int"
#反手报单超时撤单
CFocusFtdcAllFutureMakerStrategyField["SlefHedgeTimeAction"] = "int"
#反手追单次数
CFocusFtdcAllFutureMakerStrategyField["SlefChaseTimes"] = "int"
#最大亏损
CFocusFtdcAllFutureMakerStrategyField["MaxLossTick"] = "int"
#对冲合约交易所代码
CFocusFtdcAllFutureMakerStrategyField["HedgeExchangeID"] = "string"
#对冲合约代码
CFocusFtdcAllFutureMakerStrategyField["HedgeInstrumentID"] = "string"
#对冲资金账号
CFocusFtdcAllFutureMakerStrategyField["HedgeInvestorID"] = "string"
#价差
CFocusFtdcAllFutureMakerStrategyField["Spread"] = "float"
#期货对冲报价方式
CFocusFtdcAllFutureMakerStrategyField["HedgeFutureMakerFlag"] = "char"
#期货对冲调整tick
CFocusFtdcAllFutureMakerStrategyField["HedgeFutureMakerTick"] = "int"
#偏离tick重新报单
CFocusFtdcAllFutureMakerStrategyField["HedgeDeviate"] = "int"
#挂单超时撤单
CFocusFtdcAllFutureMakerStrategyField["HedgeTimeAction"] = "int"
#追单次数
CFocusFtdcAllFutureMakerStrategyField["HedgeChaseTimes"] = "int"
#期货对冲合约开平标志
CFocusFtdcAllFutureMakerStrategyField["HedgeOffsetFlag"] = "char"
structDict['CFocusFtdcAllFutureMakerStrategyField'] = CFocusFtdcAllFutureMakerStrategyField


#内部股票高频策略表
CFocusFtdcInnerHighStockStrategyField = {}
#交易日期
CFocusFtdcInnerHighStockStrategyField["TradingDay"] = "string"
#交易所代码
CFocusFtdcInnerHighStockStrategyField["ExchangeID"] = "string"
#股票合约代码
CFocusFtdcInnerHighStockStrategyField["InstrumentID"] = "string"
#该股票用哪个资金账号去下单
CFocusFtdcInnerHighStockStrategyField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcInnerHighStockStrategyField["StockStrategyID"] = "string"
#股票策略名
CFocusFtdcInnerHighStockStrategyField["StockStrategyName"] = "string"
#策略类型（增仓or换仓，换仓为0，其余为大于0）
CFocusFtdcInnerHighStockStrategyField["StockStrategyType"] = "int"
#每个股票权重
CFocusFtdcInnerHighStockStrategyField["Ratio"] = "float"
#每次最大下单数（如需）
CFocusFtdcInnerHighStockStrategyField["MaxVolume"] = "int"
#每次最小单数（如需，默认为100）
CFocusFtdcInnerHighStockStrategyField["MinVolume"] = "int"
#股票每次下单比例（%）
CFocusFtdcInnerHighStockStrategyField["StockRatioAvail"] = "float"
#市场平均集合竞价成交量1
CFocusFtdcInnerHighStockStrategyField["AverMactchTradeVolume1"] = "int"
#市场平均集合竞价成交量2
CFocusFtdcInnerHighStockStrategyField["AverMactchTradeVolume2"] = "int"
#昨收盘
CFocusFtdcInnerHighStockStrategyField["PreClosePrice"] = "float"
#股票下单类型
CFocusFtdcInnerHighStockStrategyField["StockPriceType"] = "char"
#用户代码
CFocusFtdcInnerHighStockStrategyField["UserID"] = "string"
#最新委托的
CFocusFtdcInnerHighStockStrategyField["LastOrderSysID"] = "string"
#买卖方向
CFocusFtdcInnerHighStockStrategyField["Direction"] = "char"
#股票委托批号(仅批量委托有效)
CFocusFtdcInnerHighStockStrategyField["LastBatchNum"] = "string"
#昨日持仓
CFocusFtdcInnerHighStockStrategyField["YPosition"] = "int"
#总最开始的目标持仓
CFocusFtdcInnerHighStockStrategyField["StaticEndPosition"] = "int"
#总目标持仓
CFocusFtdcInnerHighStockStrategyField["EndPosition"] = "int"
#总实际目前持仓
CFocusFtdcInnerHighStockStrategyField["NowPosition"] = "int"
#总持仓可平仓数量
CFocusFtdcInnerHighStockStrategyField["PositionClose"] = "int"
#今日开仓数量(不包括冻结)
CFocusFtdcInnerHighStockStrategyField["OpenVolume"] = "int"
#今日平仓数量(包括昨持仓的平仓,不包括冻结)
CFocusFtdcInnerHighStockStrategyField["CloseVolume"] = "int"
#Alpha目标个股市值(以昨结算)
CFocusFtdcInnerHighStockStrategyField["AlphaTargetValue"] = "float"
#Alpha当前买入总资金(以昨结算)
CFocusFtdcInnerHighStockStrategyField["AlphaCurrentTotalValue"] = "float"
#开始操作时间
CFocusFtdcInnerHighStockStrategyField["StartOperTime"] = "string"
#最新操作时间
CFocusFtdcInnerHighStockStrategyField["LastOperTime"] = "string"
#最新需要报的数量
CFocusFtdcInnerHighStockStrategyField["LastNeedSendVolume"] = "int"
#最新报的价格
CFocusFtdcInnerHighStockStrategyField["LastSendPrice"] = "float"
#最新市场总成交量
CFocusFtdcInnerHighStockStrategyField["PreMarketTradeVolume"] = "int"
#股票平均成交量统计间隔次数（MA）
CFocusFtdcInnerHighStockStrategyField["MAStockAvail"] = "int"
#间隔时间内的市场股票平均成交量
CFocusFtdcInnerHighStockStrategyField["GapVolume"] = "int"
#该只股票当前是否正在交易
CFocusFtdcInnerHighStockStrategyField["StockIsTrading"] = "int"
#该股是否是低价股
CFocusFtdcInnerHighStockStrategyField["IsLowStock"] = "int"
#启动之前最新买成交总量
CFocusFtdcInnerHighStockStrategyField["SignalHasBuyTotalPosition"] = "int"
#启动之前最新卖成交总量
CFocusFtdcInnerHighStockStrategyField["SignalHasSellTotalPosition"] = "int"
#个股买完成比例
CFocusFtdcInnerHighStockStrategyField["SignalLastPer"] = "float"
#操作备注
CFocusFtdcInnerHighStockStrategyField["Note"] = "string"
#优先权
CFocusFtdcInnerHighStockStrategyField["Priority"] = "string"
#个股行情状态
CFocusFtdcInnerHighStockStrategyField["StkOrderStatus"] = "string"
#开盘价格
CFocusFtdcInnerHighStockStrategyField["OpenPrice"] = "float"
#总成交量（包括了买和卖）
CFocusFtdcInnerHighStockStrategyField["TotalTradeVolume"] = "int"
#今日买总成本
CFocusFtdcInnerHighStockStrategyField["TotalBuyCostMoney"] = "float"
#今日卖总成本
CFocusFtdcInnerHighStockStrategyField["TotalSellCostMoney"] = "float"
#今日平均成本
CFocusFtdcInnerHighStockStrategyField["AverCostMoney"] = "float"
#第几轮报单
CFocusFtdcInnerHighStockStrategyField["TotalRoundAmount"] = "int"
#尾盘策略之前总成交量（包括了买和卖）
CFocusFtdcInnerHighStockStrategyField["AllAddTotalTradeVolume"] = "int"
#尾盘策略之前今日累积买总成本
CFocusFtdcInnerHighStockStrategyField["AllAddTotalBuyCostMoney"] = "float"
#尾盘策略之前今日累积卖总成本
CFocusFtdcInnerHighStockStrategyField["AllAddTotalSellCostMoney"] = "float"
#尾盘策略之前今日累积平均成本
CFocusFtdcInnerHighStockStrategyField["AllAddAverCostMoney"] = "float"
#多因子list最开始的目标持仓
CFocusFtdcInnerHighStockStrategyField["AlphaListStaticEndPosition"] = "int"
#多因子list目标持仓
CFocusFtdcInnerHighStockStrategyField["AlphaListEndPosition"] = "int"
#多因子list最新持仓
CFocusFtdcInnerHighStockStrategyField["AlphaListNowPosition"] = "int"
#AlphaList优先权
CFocusFtdcInnerHighStockStrategyField["AlphaListPriority"] = "string"
#该只股票AlphaList当前是否正在交易
CFocusFtdcInnerHighStockStrategyField["AlphaListStockIsTrading"] = "int"
#多因子list最开始的目标持仓
CFocusFtdcInnerHighStockStrategyField["TZeroStaticEndPosition"] = "int"
#盘中list总目标持仓
CFocusFtdcInnerHighStockStrategyField["TZeroEndPosition"] = "int"
#盘中list实际目前持仓
CFocusFtdcInnerHighStockStrategyField["TZeroNowPosition"] = "int"
#t0最新设置时间
CFocusFtdcInnerHighStockStrategyField["TZeroLastOperTime"] = "string"
#TZero需要改变的股数
CFocusFtdcInnerHighStockStrategyField["TZeroGapVolume"] = "int"
#TZero最晚结束时间
CFocusFtdcInnerHighStockStrategyField["TZeroEndOperTime"] = "string"
#TZero下单上限价格
CFocusFtdcInnerHighStockStrategyField["TZeroUpperEndPrice"] = "float"
#TZero下单下限价格
CFocusFtdcInnerHighStockStrategyField["TZeroLowerEndPrice"] = "float"
#TZero股票下单类型
CFocusFtdcInnerHighStockStrategyField["TZeroStockPriceType"] = "char"
#TZero持仓（总）
CFocusFtdcInnerHighStockStrategyField["TZeroAddPosition"] = "int"
#TZero总静态开仓市值
CFocusFtdcInnerHighStockStrategyField["T0StaticTotalMoney"] = "float"
#TZero静态收益
CFocusFtdcInnerHighStockStrategyField["TZeroStaticRights"] = "float"
#TZero平仓收益
CFocusFtdcInnerHighStockStrategyField["TZeroColseRights"] = "float"
#任然需要交易的量
CFocusFtdcInnerHighStockStrategyField["StillNeedSendPosition"] = "int"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcInnerHighStockStrategyField["AlgoParentOrderSysID"] = "string"
#算法操作备注
CFocusFtdcInnerHighStockStrategyField["AlgoNote"] = "string"
structDict['CFocusFtdcInnerHighStockStrategyField'] = CFocusFtdcInnerHighStockStrategyField


#股票策略开关
CFocusFtdcWholeHighStockStrategySwitchField = {}
#该股票用哪个资金账号去下单
CFocusFtdcWholeHighStockStrategySwitchField["StockInvestorID"] = "string"
#策略类型（增仓or换仓，换仓为0，其余为大于0）
CFocusFtdcWholeHighStockStrategySwitchField["StockStrategyType"] = "int"
#股票策略ID
CFocusFtdcWholeHighStockStrategySwitchField["StockStrategyID"] = "string"
#交易员总开关
CFocusFtdcWholeHighStockStrategySwitchField["StockWholeSwitch"] = "char"
structDict['CFocusFtdcWholeHighStockStrategySwitchField'] = CFocusFtdcWholeHighStockStrategySwitchField


#查询策略的键值
CFocusFtdcQryWholeHighStockStrategyField = {}
#该股票用哪个资金账号去下单
CFocusFtdcQryWholeHighStockStrategyField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcQryWholeHighStockStrategyField["StockStrategyID"] = "string"
#策略类型（增仓or换仓，换仓为0，其余为大于0）
CFocusFtdcQryWholeHighStockStrategyField["StockStrategyType"] = "int"
structDict['CFocusFtdcQryWholeHighStockStrategyField'] = CFocusFtdcQryWholeHighStockStrategyField


#查询策略的单个股票的键值
CFocusFtdcQrySignalHighStockStrategyField = {}
#该股票用哪个资金账号去下单
CFocusFtdcQrySignalHighStockStrategyField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcQrySignalHighStockStrategyField["StockStrategyID"] = "string"
#策略类型（增仓or换仓，换仓为0，其余为大于0）
CFocusFtdcQrySignalHighStockStrategyField["StockStrategyType"] = "int"
#交易所代码
CFocusFtdcQrySignalHighStockStrategyField["ExchangeID"] = "string"
#股票合约代码
CFocusFtdcQrySignalHighStockStrategyField["InstrumentID"] = "string"
structDict['CFocusFtdcQrySignalHighStockStrategyField'] = CFocusFtdcQrySignalHighStockStrategyField


#查询策略的单个股票的键值
CFocusFtdcSignalHighStockStrategySwitchField = {}
#该股票用哪个资金账号去下单
CFocusFtdcSignalHighStockStrategySwitchField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcSignalHighStockStrategySwitchField["StockStrategyID"] = "string"
#策略类型（增仓or换仓，换仓为0，其余为大于0）
CFocusFtdcSignalHighStockStrategySwitchField["StockStrategyType"] = "int"
#交易所代码
CFocusFtdcSignalHighStockStrategySwitchField["ExchangeID"] = "string"
#股票合约代码
CFocusFtdcSignalHighStockStrategySwitchField["InstrumentID"] = "string"
#股票单个开关
CFocusFtdcSignalHighStockStrategySwitchField["StockWholeSwitch"] = "char"
structDict['CFocusFtdcSignalHighStockStrategySwitchField'] = CFocusFtdcSignalHighStockStrategySwitchField


#股票高频策略表
CFocusFtdcAPIHighStockStrategyField = {}
#交易日期
CFocusFtdcAPIHighStockStrategyField["TradingDay"] = "string"
#交易所代码
CFocusFtdcAPIHighStockStrategyField["ExchangeID"] = "string"
#股票合约代码
CFocusFtdcAPIHighStockStrategyField["InstrumentID"] = "string"
#该股票用哪个资金账号去下单
CFocusFtdcAPIHighStockStrategyField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcAPIHighStockStrategyField["StockStrategyID"] = "string"
#股票策略名
CFocusFtdcAPIHighStockStrategyField["StockStrategyName"] = "string"
#策略类型（增仓or换仓，换仓为0，其余为大于0）
CFocusFtdcAPIHighStockStrategyField["StockStrategyType"] = "int"
#每个股票权重
CFocusFtdcAPIHighStockStrategyField["Ratio"] = "float"
#每次最大下单数（如需）
CFocusFtdcAPIHighStockStrategyField["MaxVolume"] = "int"
#每次最小单数（如需，默认为100）
CFocusFtdcAPIHighStockStrategyField["MinVolume"] = "int"
#股票每次下单比例（%）
CFocusFtdcAPIHighStockStrategyField["StockRatioAvail"] = "float"
#市场平均集合竞价成交量1
CFocusFtdcAPIHighStockStrategyField["AverMactchTradeVolume1"] = "int"
#市场平均集合竞价成交量2
CFocusFtdcAPIHighStockStrategyField["AverMactchTradeVolume2"] = "int"
#昨收盘
CFocusFtdcAPIHighStockStrategyField["PreClosePrice"] = "float"
#股票下单类型
CFocusFtdcAPIHighStockStrategyField["StockPriceType"] = "char"
structDict['CFocusFtdcAPIHighStockStrategyField'] = CFocusFtdcAPIHighStockStrategyField


#股票期货对冲关系表
CFocusFtdcHighFutureStrategyRelationField = {}
#用户代码
CFocusFtdcHighFutureStrategyRelationField["UserID"] = "string"
#该股票用哪个资金账号去下单
CFocusFtdcHighFutureStrategyRelationField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcHighFutureStrategyRelationField["StockStrategyID"] = "string"
#策略类型（增仓or换仓，换仓为0，其余为大于0）
CFocusFtdcHighFutureStrategyRelationField["StockStrategyType"] = "int"
#股票策略当前是否交易
CFocusFtdcHighFutureStrategyRelationField["StockStrategyIsTrading"] = "int"
#股票轮训检查时间间隔（秒）
CFocusFtdcHighFutureStrategyRelationField["StockTimeAvail"] = "int"
#股票平均成交量统计间隔次数（MA）
CFocusFtdcHighFutureStrategyRelationField["MAStockAvail"] = "int"
#单个股票报价容忍度，正常下单时高价股#低价股@单边时高价股#低价股 J#A@A#A
CFocusFtdcHighFutureStrategyRelationField["StockTolerRatio"] = "string"
#停止报单股票总买卖金额偏离比率（%）
CFocusFtdcHighFutureStrategyRelationField["StopDeviRatio"] = "float"
#恢复股票总买卖金额偏离比率（%）
CFocusFtdcHighFutureStrategyRelationField["RrecovrDeviRatio"] = "float"
#初始化预分配换仓总资金
CFocusFtdcHighFutureStrategyRelationField["TargetMoney"] = "float"
#每轮下单市值上限资金
CFocusFtdcHighFutureStrategyRelationField["RoundMaxMoney"] = "float"
#期货交易所代码
CFocusFtdcHighFutureStrategyRelationField["FutureExchangeID"] = "string"
#期货合约代码
CFocusFtdcHighFutureStrategyRelationField["FutureInstrumentID"] = "string"
#期货买卖方向
CFocusFtdcHighFutureStrategyRelationField["FutureDirection"] = "char"
#期货报单类型
CFocusFtdcHighFutureStrategyRelationField["FuturePriceType"] = "char"
#对应期货当前是否交易（换仓默认开关无效）
CFocusFtdcHighFutureStrategyRelationField["FutureIsTrading"] = "int"
#期货资金账号
CFocusFtdcHighFutureStrategyRelationField["FutureInvestorID"] = "string"
#期货默认检查时间间隔
CFocusFtdcHighFutureStrategyRelationField["FutureTimeAvail"] = "int"
#固定逆回购金额
CFocusFtdcHighFutureStrategyRelationField["StaticRebuyMoney"] = "float"
#是否延续涨跌停
CFocusFtdcHighFutureStrategyRelationField["BRNeedContinue"] = "char"
#最大换仓比例
CFocusFtdcHighFutureStrategyRelationField["MaxTradePer"] = "float"
#期货算法类型
CFocusFtdcHighFutureStrategyRelationField["FutureAlgoType"] = "int"
#指数交易所
CFocusFtdcHighFutureStrategyRelationField["IndexExchangeID"] = "string"
#指数合约
CFocusFtdcHighFutureStrategyRelationField["IndexInstrumentID"] = "string"
#基差
CFocusFtdcHighFutureStrategyRelationField["SpreadPrice"] = "float"
#期货下单手数
CFocusFtdcHighFutureStrategyRelationField["FutureAmount"] = "int"
#List中price的价格类型
CFocusFtdcHighFutureStrategyRelationField["ListPriceType"] = "char"
#期现下单匹配度(0~1)
CFocusFtdcHighFutureStrategyRelationField["FuStockRelation"] = "float"
#是否跟随期货下单
CFocusFtdcHighFutureStrategyRelationField["FlowerFuture"] = "int"
#期货间隔手数
CFocusFtdcHighFutureStrategyRelationField["FutureAvailAmount"] = "int"
#仓位权重类型
CFocusFtdcHighFutureStrategyRelationField["PositionRatioType"] = "char"
#股票换仓算法(0,自有 1 AlgoTwap 2. AlgoVwap)
CFocusFtdcHighFutureStrategyRelationField["StockAlgoType"] = "int"
#策略开始时间(HH:mm:ss)
CFocusFtdcHighFutureStrategyRelationField["AlgoStrategyStartTime"] = "string"
#策略停止时间(HH:mm:ss)
CFocusFtdcHighFutureStrategyRelationField["AlgoStrategyEndTime"] = "string"
structDict['CFocusFtdcHighFutureStrategyRelationField'] = CFocusFtdcHighFutureStrategyRelationField


#股票期货对冲关系内部表
CFocusFtdcHighInnerFutureStrategyRelationField = {}
#用户代码
CFocusFtdcHighInnerFutureStrategyRelationField["UserID"] = "string"
#该股票用哪个资金账号去下单
CFocusFtdcHighInnerFutureStrategyRelationField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcHighInnerFutureStrategyRelationField["StockStrategyID"] = "string"
#策略类型（增仓or换仓，换仓为0，其余为大于0）
CFocusFtdcHighInnerFutureStrategyRelationField["StockStrategyType"] = "int"
#股票策略当前是否交易
CFocusFtdcHighInnerFutureStrategyRelationField["StockStrategyIsTrading"] = "int"
#股票轮训检查时间间隔（秒）
CFocusFtdcHighInnerFutureStrategyRelationField["StockTimeAvail"] = "int"
#股票平均成交量统计间隔次数（MA）
CFocusFtdcHighInnerFutureStrategyRelationField["MAStockAvail"] = "int"
#单个股票报价容忍度，正常下单时高价股#低价股@单边时高价股#低价股 J#A@A#A
CFocusFtdcHighInnerFutureStrategyRelationField["StockTolerRatio"] = "string"
#停止报单股票总买卖金额偏离比率（%）
CFocusFtdcHighInnerFutureStrategyRelationField["StopDeviRatio"] = "float"
#恢复股票总买卖金额偏离比率（%）
CFocusFtdcHighInnerFutureStrategyRelationField["RrecovrDeviRatio"] = "float"
#初始化预分配换仓总资金
CFocusFtdcHighInnerFutureStrategyRelationField["TargetMoney"] = "float"
#每轮下单市值上限资金
CFocusFtdcHighInnerFutureStrategyRelationField["RoundMaxMoney"] = "float"
#期货交易所代码
CFocusFtdcHighInnerFutureStrategyRelationField["FutureExchangeID"] = "string"
#期货合约代码
CFocusFtdcHighInnerFutureStrategyRelationField["FutureInstrumentID"] = "string"
#期货买卖方向
CFocusFtdcHighInnerFutureStrategyRelationField["FutureDirection"] = "char"
#期货报单类型
CFocusFtdcHighInnerFutureStrategyRelationField["FuturePriceType"] = "char"
#对应期货当前是否交易（换仓默认开关无效）
CFocusFtdcHighInnerFutureStrategyRelationField["FutureIsTrading"] = "int"
#期货资金账号
CFocusFtdcHighInnerFutureStrategyRelationField["FutureInvestorID"] = "string"
#期货默认检查时间间隔
CFocusFtdcHighInnerFutureStrategyRelationField["FutureTimeAvail"] = "int"
#固定逆回购金额
CFocusFtdcHighInnerFutureStrategyRelationField["StaticRebuyMoney"] = "float"
#是否延续涨跌停
CFocusFtdcHighInnerFutureStrategyRelationField["BRNeedContinue"] = "char"
#最大换仓比例
CFocusFtdcHighInnerFutureStrategyRelationField["MaxTradePer"] = "float"
#期货算法类型
CFocusFtdcHighInnerFutureStrategyRelationField["FutureAlgoType"] = "int"
#指数交易所
CFocusFtdcHighInnerFutureStrategyRelationField["IndexExchangeID"] = "string"
#指数合约
CFocusFtdcHighInnerFutureStrategyRelationField["IndexInstrumentID"] = "string"
#基差
CFocusFtdcHighInnerFutureStrategyRelationField["SpreadPrice"] = "float"
#期货下单手数
CFocusFtdcHighInnerFutureStrategyRelationField["FutureAmount"] = "int"
#List中price的价格类型
CFocusFtdcHighInnerFutureStrategyRelationField["ListPriceType"] = "char"
#期现下单匹配度(0~1)
CFocusFtdcHighInnerFutureStrategyRelationField["FuStockRelation"] = "float"
#是否跟随期货下单
CFocusFtdcHighInnerFutureStrategyRelationField["FlowerFuture"] = "int"
#期货间隔手数
CFocusFtdcHighInnerFutureStrategyRelationField["FutureAvailAmount"] = "int"
#仓位权重类型
CFocusFtdcHighInnerFutureStrategyRelationField["PositionRatioType"] = "char"
#股票换仓算法(0,自有 1 AlgoTwap 2. AlgoVwap)
CFocusFtdcHighInnerFutureStrategyRelationField["StockAlgoType"] = "int"
#策略开始时间(HH:mm:ss)
CFocusFtdcHighInnerFutureStrategyRelationField["AlgoStrategyStartTime"] = "string"
#策略停止时间(HH:mm:ss)
CFocusFtdcHighInnerFutureStrategyRelationField["AlgoStrategyEndTime"] = "string"
#操作备注
CFocusFtdcHighInnerFutureStrategyRelationField["Note"] = "string"
#策略行情状态
CFocusFtdcHighInnerFutureStrategyRelationField["RelationOrderStatus"] = "string"
#实际分配总资金
CFocusFtdcHighInnerFutureStrategyRelationField["RealTargetMoney"] = "float"
#最新买总成交总量
CFocusFtdcHighInnerFutureStrategyRelationField["LastTotalBuyMoney"] = "float"
#最新卖总成交总量
CFocusFtdcHighInnerFutureStrategyRelationField["LastTotalSellMoney"] = "float"
#最新需要买的总金额
CFocusFtdcHighInnerFutureStrategyRelationField["LastTotalNeedBuyMoney"] = "float"
#最新需要卖的总金额
CFocusFtdcHighInnerFutureStrategyRelationField["LastTotalNeedSellMoney"] = "float"
#最新冻结的总金额
CFocusFtdcHighInnerFutureStrategyRelationField["LastFrozenMoney"] = "float"
#买完成比例
CFocusFtdcHighInnerFutureStrategyRelationField["LastBuyPer"] = "float"
#卖完成比例
CFocusFtdcHighInnerFutureStrategyRelationField["LastSellPer"] = "float"
#最新操作时间
CFocusFtdcHighInnerFutureStrategyRelationField["LastOperTime"] = "string"
#今日买总成本
CFocusFtdcHighInnerFutureStrategyRelationField["TotalBuyCostMoney"] = "float"
#今日卖总成本
CFocusFtdcHighInnerFutureStrategyRelationField["TotalSellCostMoney"] = "float"
#今日手续费成本
CFocusFtdcHighInnerFutureStrategyRelationField["TotalFeeCostMoney"] = "float"
#今日平均成本
CFocusFtdcHighInnerFutureStrategyRelationField["AverCostMoney"] = "float"
#是否买卖相等
CFocusFtdcHighInnerFutureStrategyRelationField["IsPerEqual"] = "string"
#买卖价差值（正数）
CFocusFtdcHighInnerFutureStrategyRelationField["BuySellGapMoney"] = "float"
#尾盘卖出总成交金额
CFocusFtdcHighInnerFutureStrategyRelationField["CloseEndSellMoney"] = "float"
#整体成本
CFocusFtdcHighInnerFutureStrategyRelationField["TotalAverCostMoney"] = "float"
#是否自动逆回购
CFocusFtdcHighInnerFutureStrategyRelationField["BRebuySwitch"] = "char"
#尾盘策略之前今日累积最新买总成交总量
CFocusFtdcHighInnerFutureStrategyRelationField["AllAddLastTotalBuyMoney"] = "float"
#尾盘策略之前今日累积最新卖总成交总量
CFocusFtdcHighInnerFutureStrategyRelationField["AllAddLastTotalSellMoney"] = "float"
#尾盘策略之前今日累积买总成本
CFocusFtdcHighInnerFutureStrategyRelationField["AllAddTotalBuyCostMoney"] = "float"
#尾盘策略之前今日累积卖总成本
CFocusFtdcHighInnerFutureStrategyRelationField["AllAddTotalSellCostMoney"] = "float"
#尾盘策略之前今日累积卖手续费成本
CFocusFtdcHighInnerFutureStrategyRelationField["AllAddTotalFeeCostMoney"] = "float"
#尾盘策略之前今日累积平均成本
CFocusFtdcHighInnerFutureStrategyRelationField["AllAddAverCostMoney"] = "float"
#尾盘策略之前今日累积整体成本
CFocusFtdcHighInnerFutureStrategyRelationField["AllAddTotalAverCostMoney"] = "float"
#择时方向
CFocusFtdcHighInnerFutureStrategyRelationField["IndexDirSignal"] = "string"
#最新期货操作时间
CFocusFtdcHighInnerFutureStrategyRelationField["LastFuOperTime"] = "string"
#已完成对冲总交易量
CFocusFtdcHighInnerFutureStrategyRelationField["LastFuTarNetPosition"] = "int"
#对冲操作备注
CFocusFtdcHighInnerFutureStrategyRelationField["FutureNote"] = "string"
#期货价差对冲是否需要检查
CFocusFtdcHighInnerFutureStrategyRelationField["FutureSpreadNeedCheck"] = "int"
#开仓那刻期货价格
CFocusFtdcHighInnerFutureStrategyRelationField["OpenFuInstrPrice"] = "float"
#上次完成的总交易量
CFocusFtdcHighInnerFutureStrategyRelationField["BeforeLastFuTarNetPosition"] = "int"
#现货对于期货手数
CFocusFtdcHighInnerFutureStrategyRelationField["NetFuPosition"] = "float"
#实时基差
CFocusFtdcHighInnerFutureStrategyRelationField["RealTimeSpreadPrice"] = "float"
#实时指数价格
CFocusFtdcHighInnerFutureStrategyRelationField["RealIndexPrice"] = "float"
#实时期货价格
CFocusFtdcHighInnerFutureStrategyRelationField["RealFuturePrice"] = "float"
#期货操作备注2
CFocusFtdcHighInnerFutureStrategyRelationField["FutureRelationNote"] = "string"
#最新期货对冲操作时间
CFocusFtdcHighInnerFutureStrategyRelationField["LastHedgeFuOperTime"] = "string"
#算法操作备注
CFocusFtdcHighInnerFutureStrategyRelationField["AlgoNote"] = "string"
structDict['CFocusFtdcHighInnerFutureStrategyRelationField'] = CFocusFtdcHighInnerFutureStrategyRelationField


#查询所有股票期货对冲关系表
CFocusFtdcQryAllHighFutureStrategyRelationField = {}
#用户代码
CFocusFtdcQryAllHighFutureStrategyRelationField["UserID"] = "string"
#该股票用哪个资金账号去下单
CFocusFtdcQryAllHighFutureStrategyRelationField["StockInvestorID"] = "string"
structDict['CFocusFtdcQryAllHighFutureStrategyRelationField'] = CFocusFtdcQryAllHighFutureStrategyRelationField


#股票交易阶段下单方式
CFocusFtdcStockMarketTradingPeriodStrategyField = {}
#该股票用哪个资金账号去下单
CFocusFtdcStockMarketTradingPeriodStrategyField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcStockMarketTradingPeriodStrategyField["StockStrategyID"] = "string"
#起始时间
CFocusFtdcStockMarketTradingPeriodStrategyField["TpStart"] = "string"
#结束时间
CFocusFtdcStockMarketTradingPeriodStrategyField["TpEnd"] = "string"
#交易类型（正常下单时高价股#低价股@单边时高价股#低价股 J#A@A#A）
CFocusFtdcStockMarketTradingPeriodStrategyField["StockOrderType"] = "string"
#停止报单股票总买卖金额偏离比率（%）
CFocusFtdcStockMarketTradingPeriodStrategyField["StopDeviRatio"] = "float"
#恢复股票总买卖金额偏离比率（%）
CFocusFtdcStockMarketTradingPeriodStrategyField["RrecovrDeviRatio"] = "float"
#每轮下单市值上限资金
CFocusFtdcStockMarketTradingPeriodStrategyField["RoundMaxMoney"] = "float"
#股票轮训检查时间间隔（秒）
CFocusFtdcStockMarketTradingPeriodStrategyField["StockTimeAvail"] = "int"
#单个股票报价容忍度，正常下单时高价股#低价股@单边时高价股#低价股 J#A@A#A
CFocusFtdcStockMarketTradingPeriodStrategyField["StockTolerRatio"] = "string"
#是否新下单加上上次撤单量
CFocusFtdcStockMarketTradingPeriodStrategyField["NeedAddCancelVolumeSwitch"] = "char"
#每次下单量用对手量和前几次量平均量取大
CFocusFtdcStockMarketTradingPeriodStrategyField["NeedGetSideVolumeSwitch"] = "char"
#是否MaxVolume生效
CFocusFtdcStockMarketTradingPeriodStrategyField["CheckMaxVolumeSwitch"] = "char"
structDict['CFocusFtdcStockMarketTradingPeriodStrategyField'] = CFocusFtdcStockMarketTradingPeriodStrategyField


#逆回购自动卖出开关
CFocusFtdcRelationAutoReBuySwitchField = {}
#该股票用哪个资金账号去下单
CFocusFtdcRelationAutoReBuySwitchField["StockInvestorID"] = "string"
#逆回购开关
CFocusFtdcRelationAutoReBuySwitchField["RelationReBuySwitch"] = "char"
structDict['CFocusFtdcRelationAutoReBuySwitchField'] = CFocusFtdcRelationAutoReBuySwitchField


#期货算法订单
CFocusFtdcFutureStrategyOrderField = {}
#用户代码
CFocusFtdcFutureStrategyOrderField["UserID"] = "string"
#投资者编号
CFocusFtdcFutureStrategyOrderField["InvestorID"] = "string"
#交易所代码
CFocusFtdcFutureStrategyOrderField["ExchangeID"] = "string"
#合约代码
CFocusFtdcFutureStrategyOrderField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcFutureStrategyOrderField["StrategyID"] = "string"
#目标净持仓量
CFocusFtdcFutureStrategyOrderField["TargetNetPosition"] = "int"
#策略开始执行时间
CFocusFtdcFutureStrategyOrderField["StartTradingTime"] = "string"
#算法类型
CFocusFtdcFutureStrategyOrderField["AlgoType"] = "int"
#用户自定义域
CFocusFtdcFutureStrategyOrderField["UserCustom"] = "string"
#策略当前是否交易
CFocusFtdcFutureStrategyOrderField["StrategyIsTrading"] = "int"
#策略报单价格条件
CFocusFtdcFutureStrategyOrderField["StrategyPrice"] = "char"
#尾盘集合竞价需要下单量
CFocusFtdcFutureStrategyOrderField["MactchTrdVol"] = "int"
#尾盘集合竞价下单方式
CFocusFtdcFutureStrategyOrderField["MactchTrdPriceType"] = "char"
#Vwap每轮最大下单量
CFocusFtdcFutureStrategyOrderField["VwapMaxVolume"] = "int"
#是否加仓
CFocusFtdcFutureStrategyOrderField["IsAddPosi"] = "char"
#下单仓位类型
CFocusFtdcFutureStrategyOrderField["AddPositionType"] = "char"
#价格触发条件
CFocusFtdcFutureStrategyOrderField["PriceDirection"] = "char"
#触发价格
CFocusFtdcFutureStrategyOrderField["TriggerPrice"] = "float"
#母单算法时的时间间隔
CFocusFtdcFutureStrategyOrderField["TotalTimeAvail"] = "int"
structDict['CFocusFtdcFutureStrategyOrderField'] = CFocusFtdcFutureStrategyOrderField


#算法参数
CFocusFtdcAlgoParmField = {}
#用户代码
CFocusFtdcAlgoParmField["UserID"] = "string"
#投资者编号
CFocusFtdcAlgoParmField["InvestorID"] = "string"
#交易所代码
CFocusFtdcAlgoParmField["ExchangeID"] = "string"
#合约代码
CFocusFtdcAlgoParmField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcAlgoParmField["StrategyID"] = "string"
#容忍度(tick)
CFocusFtdcAlgoParmField["TolerTick"] = "int"
#Twap总时间(s)
CFocusFtdcAlgoParmField["TwapTotalTime"] = "int"
#Twap拆分数目
CFocusFtdcAlgoParmField["TwapSplitAmount"] = "int"
#Vwap统计每秒平均成交量的时间间隔
CFocusFtdcAlgoParmField["VwapTimeAvail"] = "int"
#Vwap容忍间隔时间
CFocusFtdcAlgoParmField["VwapTotalTime"] = "int"
#Vwap计算总成交量的时间间隔（秒）
CFocusFtdcAlgoParmField["VwapVolumeTotalTime"] = "int"
#策略报单价格条件
CFocusFtdcAlgoParmField["StockStrategyPrice"] = "char"
#最大目标净持仓
CFocusFtdcAlgoParmField["MaxNetPosition"] = "int"
#距离上次的最小变动仓位
CFocusFtdcAlgoParmField["MinChangePosition"] = "int"
#是否比较对手量，百分比取大值
CFocusFtdcAlgoParmField["NeedGetSideVolumeSwitch"] = "char"
#对手量的比例
CFocusFtdcAlgoParmField["SideVolumePer"] = "float"
structDict['CFocusFtdcAlgoParmField'] = CFocusFtdcAlgoParmField


#期货算法订单详情
CFocusFtdcInnerFutureStrategyOrderField = {}
#用户代码
CFocusFtdcInnerFutureStrategyOrderField["UserID"] = "string"
#投资者编号
CFocusFtdcInnerFutureStrategyOrderField["InvestorID"] = "string"
#交易所代码
CFocusFtdcInnerFutureStrategyOrderField["ExchangeID"] = "string"
#合约代码
CFocusFtdcInnerFutureStrategyOrderField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcInnerFutureStrategyOrderField["StrategyID"] = "string"
#目标净持仓量
CFocusFtdcInnerFutureStrategyOrderField["TargetNetPosition"] = "int"
#策略开始执行时间
CFocusFtdcInnerFutureStrategyOrderField["StartTradingTime"] = "string"
#算法类型
CFocusFtdcInnerFutureStrategyOrderField["AlgoType"] = "int"
#用户自定义域
CFocusFtdcInnerFutureStrategyOrderField["UserCustom"] = "string"
#策略当前是否交易
CFocusFtdcInnerFutureStrategyOrderField["StrategyIsTrading"] = "int"
#策略报单价格条件
CFocusFtdcInnerFutureStrategyOrderField["StrategyPrice"] = "char"
#尾盘集合竞价需要下单量
CFocusFtdcInnerFutureStrategyOrderField["MactchTrdVol"] = "int"
#尾盘集合竞价下单方式
CFocusFtdcInnerFutureStrategyOrderField["MactchTrdPriceType"] = "char"
#Vwap每轮最大下单量
CFocusFtdcInnerFutureStrategyOrderField["VwapMaxVolume"] = "int"
#是否加仓
CFocusFtdcInnerFutureStrategyOrderField["IsAddPosi"] = "char"
#下单仓位类型
CFocusFtdcInnerFutureStrategyOrderField["AddPositionType"] = "char"
#价格触发条件
CFocusFtdcInnerFutureStrategyOrderField["PriceDirection"] = "char"
#触发价格
CFocusFtdcInnerFutureStrategyOrderField["TriggerPrice"] = "float"
#母单算法时的时间间隔
CFocusFtdcInnerFutureStrategyOrderField["TotalTimeAvail"] = "int"
#容忍度(tick)
CFocusFtdcInnerFutureStrategyOrderField["TolerTick"] = "int"
#Twap总时间(s)
CFocusFtdcInnerFutureStrategyOrderField["TwapTotalTime"] = "int"
#拆分数目
CFocusFtdcInnerFutureStrategyOrderField["TwapSplitAmount"] = "int"
#Vwap统计时间间隔
CFocusFtdcInnerFutureStrategyOrderField["VwapTimeAvail"] = "int"
#Vwap容忍间隔时间
CFocusFtdcInnerFutureStrategyOrderField["VwapTotalTime"] = "int"
#Vwap计算总成交量的时间间隔（秒）
CFocusFtdcInnerFutureStrategyOrderField["VwapVolumeTotalTime"] = "int"
#策略报单价格条件
CFocusFtdcInnerFutureStrategyOrderField["StockStrategyPrice"] = "char"
#最大目标净持仓
CFocusFtdcInnerFutureStrategyOrderField["MaxNetPosition"] = "int"
#距离上次的最小变动仓位
CFocusFtdcInnerFutureStrategyOrderField["MinChangePosition"] = "int"
#是否比较对手量，百分比取大值
CFocusFtdcInnerFutureStrategyOrderField["NeedGetSideVolumeSwitch"] = "char"
#对手量的比例
CFocusFtdcInnerFutureStrategyOrderField["SideVolumePer"] = "float"
#买卖方向
CFocusFtdcInnerFutureStrategyOrderField["Direction"] = "char"
#开平标志
CFocusFtdcInnerFutureStrategyOrderField["OffsetFlag"] = "char"
#分段操作时间（毫秒）
CFocusFtdcInnerFutureStrategyOrderField["GapMillisec"] = "int"
#小分段需要交易的量
CFocusFtdcInnerFutureStrategyOrderField["SplitVolume"] = "int"
#小分段需要交易的量(原始)
CFocusFtdcInnerFutureStrategyOrderField["OrginalSplitVolume"] = "int"
#全天需要成交量
CFocusFtdcInnerFutureStrategyOrderField["StaticlTotalNeedTradeVolume"] = "int"
#最新操作时间(s)
CFocusFtdcInnerFutureStrategyOrderField["LastCurrOperTime"] = "int"
#最新操作时间（毫秒）
CFocusFtdcInnerFutureStrategyOrderField["LastCurrMillisec"] = "int"
#容忍时间间隔（ms）
CFocusFtdcInnerFutureStrategyOrderField["TolerTimeAvail"] = "int"
#买完成比例
CFocusFtdcInnerFutureStrategyOrderField["SignalLastPer"] = "float"
#比较基准开盘价格
CFocusFtdcInnerFutureStrategyOrderField["PreparPrice"] = "float"
#总成本
CFocusFtdcInnerFutureStrategyOrderField["TotalCostMoney"] = "float"
#卖手续费成本
CFocusFtdcInnerFutureStrategyOrderField["TotalFeeCostMoney"] = "float"
#平均成本
CFocusFtdcInnerFutureStrategyOrderField["AverCostMoney"] = "float"
#操作备注
CFocusFtdcInnerFutureStrategyOrderField["Note"] = "string"
#本策略已成交数量
CFocusFtdcInnerFutureStrategyOrderField["StrategyTradeVolume"] = "int"
#实际目前持仓
CFocusFtdcInnerFutureStrategyOrderField["NowPosition"] = "int"
#最早新建订单时间（秒）
CFocusFtdcInnerFutureStrategyOrderField["OrginRecvOrderTime"] = "string"
#最后收到改变订单时间（秒）
CFocusFtdcInnerFutureStrategyOrderField["LastRecvOrderTime"] = "string"
#最新操作时间（秒）
CFocusFtdcInnerFutureStrategyOrderField["LastOperTime"] = "string"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcInnerFutureStrategyOrderField["AlgoParentOrderSysID"] = "string"
structDict['CFocusFtdcInnerFutureStrategyOrderField'] = CFocusFtdcInnerFutureStrategyOrderField


#期货算法交易订单键值
CFocusFtdcFutureStrategyOrderIndexField = {}
#用户代码
CFocusFtdcFutureStrategyOrderIndexField["UserID"] = "string"
#投资者编号
CFocusFtdcFutureStrategyOrderIndexField["InvestorID"] = "string"
#交易所代码
CFocusFtdcFutureStrategyOrderIndexField["ExchangeID"] = "string"
#合约代码
CFocusFtdcFutureStrategyOrderIndexField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcFutureStrategyOrderIndexField["StrategyID"] = "string"
structDict['CFocusFtdcFutureStrategyOrderIndexField'] = CFocusFtdcFutureStrategyOrderIndexField


#大盘信号
CFocusFtdcIndexDirSignalField = {}
#用户代码
CFocusFtdcIndexDirSignalField["UserID"] = "string"
#投资者编号
CFocusFtdcIndexDirSignalField["InvestorID"] = "string"
#消息类型
CFocusFtdcIndexDirSignalField["MessageType"] = "char"
#消息ID编号
CFocusFtdcIndexDirSignalField["MessageID"] = "int"
#是否需要转发
CFocusFtdcIndexDirSignalField["NeedNtfMessage"] = "int"
#操作时间
CFocusFtdcIndexDirSignalField["OperTime"] = "string"
#消息内容
CFocusFtdcIndexDirSignalField["Note"] = "string"
structDict['CFocusFtdcIndexDirSignalField'] = CFocusFtdcIndexDirSignalField


#跨期策略订单键值
CFocusFtdcSpreadInstrStrategyIndexField = {}
#用户代码
CFocusFtdcSpreadInstrStrategyIndexField["UserID"] = "string"
#投资者编号
CFocusFtdcSpreadInstrStrategyIndexField["InvestorID"] = "string"
#策略ID号
CFocusFtdcSpreadInstrStrategyIndexField["StrategyID"] = "string"
structDict['CFocusFtdcSpreadInstrStrategyIndexField'] = CFocusFtdcSpreadInstrStrategyIndexField


#跨期策略
CFocusFtdcSpreadInstrStrategyField = {}
#用户代码
CFocusFtdcSpreadInstrStrategyField["UserID"] = "string"
#投资者编号
CFocusFtdcSpreadInstrStrategyField["InvestorID"] = "string"
#策略ID号
CFocusFtdcSpreadInstrStrategyField["StrategyID"] = "string"
#交易所1代码
CFocusFtdcSpreadInstrStrategyField["ExchangeIDLeg1"] = "string"
#买卖方向1
CFocusFtdcSpreadInstrStrategyField["DirectionLeg1"] = "char"
#腿1合约代码
CFocusFtdcSpreadInstrStrategyField["InstrLeg1"] = "string"
#交易所2代码
CFocusFtdcSpreadInstrStrategyField["ExchangeIDLeg2"] = "string"
#买卖方向2
CFocusFtdcSpreadInstrStrategyField["DirectionLeg2"] = "char"
#腿2合约代码
CFocusFtdcSpreadInstrStrategyField["InstrLeg2"] = "string"
#腿1腿2比例
CFocusFtdcSpreadInstrStrategyField["LegPer"] = "float"
#策略开始执行时间
CFocusFtdcSpreadInstrStrategyField["StartTradingTime"] = "string"
#策略结束执行时间
CFocusFtdcSpreadInstrStrategyField["EndTradingTime"] = "string"
#检查时间间隔
CFocusFtdcSpreadInstrStrategyField["TimeAvail"] = "int"
#目标交易量
CFocusFtdcSpreadInstrStrategyField["TargetTradeVolume"] = "int"
#报单类型
CFocusFtdcSpreadInstrStrategyField["OrderPriceType"] = "char"
#算法类型
CFocusFtdcSpreadInstrStrategyField["AlgoType"] = "int"
#价差
CFocusFtdcSpreadInstrStrategyField["SpreadPrice"] = "float"
#每次下单数量
CFocusFtdcSpreadInstrStrategyField["EachTrdvolume"] = "int"
#是否交易
CFocusFtdcSpreadInstrStrategyField["StrategyIsTrading"] = "int"
#缺乏流动性标识
CFocusFtdcSpreadInstrStrategyField["LiquidLack"] = "int"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcSpreadInstrStrategyField["AlgoParentOrderSysID"] = "string"
#操作备注
CFocusFtdcSpreadInstrStrategyField["Note"] = "string"
structDict['CFocusFtdcSpreadInstrStrategyField'] = CFocusFtdcSpreadInstrStrategyField


#跨期策略订单详情
CFocusFtdcInnerSpreadInstrStrategyField = {}
#用户代码
CFocusFtdcInnerSpreadInstrStrategyField["UserID"] = "string"
#投资者编号
CFocusFtdcInnerSpreadInstrStrategyField["InvestorID"] = "string"
#策略ID号
CFocusFtdcInnerSpreadInstrStrategyField["StrategyID"] = "string"
#交易所1代码
CFocusFtdcInnerSpreadInstrStrategyField["ExchangeIDLeg1"] = "string"
#买卖方向1
CFocusFtdcInnerSpreadInstrStrategyField["DirectionLeg1"] = "char"
#腿1合约代码
CFocusFtdcInnerSpreadInstrStrategyField["InstrLeg1"] = "string"
#交易所2代码
CFocusFtdcInnerSpreadInstrStrategyField["ExchangeIDLeg2"] = "string"
#买卖方向2
CFocusFtdcInnerSpreadInstrStrategyField["DirectionLeg2"] = "char"
#腿2合约代码
CFocusFtdcInnerSpreadInstrStrategyField["InstrLeg2"] = "string"
#腿1腿2比例
CFocusFtdcInnerSpreadInstrStrategyField["LegPer"] = "float"
#策略开始执行时间
CFocusFtdcInnerSpreadInstrStrategyField["StartTradingTime"] = "string"
#策略结束执行时间
CFocusFtdcInnerSpreadInstrStrategyField["EndTradingTime"] = "string"
#检查时间间隔
CFocusFtdcInnerSpreadInstrStrategyField["TimeAvail"] = "int"
#目标交易量
CFocusFtdcInnerSpreadInstrStrategyField["TargetTradeVolume"] = "int"
#报单类型
CFocusFtdcInnerSpreadInstrStrategyField["OrderPriceType"] = "char"
#算法类型
CFocusFtdcInnerSpreadInstrStrategyField["AlgoType"] = "int"
#价差
CFocusFtdcInnerSpreadInstrStrategyField["SpreadPrice"] = "float"
#每次下单数量
CFocusFtdcInnerSpreadInstrStrategyField["EachTrdvolume"] = "int"
#是否交易
CFocusFtdcInnerSpreadInstrStrategyField["StrategyIsTrading"] = "int"
#缺乏流动性标识
CFocusFtdcInnerSpreadInstrStrategyField["LiquidLack"] = "int"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcInnerSpreadInstrStrategyField["AlgoParentOrderSysID"] = "string"
#操作备注
CFocusFtdcInnerSpreadInstrStrategyField["Note"] = "string"
#最新操作时间
CFocusFtdcInnerSpreadInstrStrategyField["LastOperTime"] = "string"
#买完成比例
CFocusFtdcInnerSpreadInstrStrategyField["SignalLastPer"] = "float"
#用户自定义域
CFocusFtdcInnerSpreadInstrStrategyField["UserCustom"] = "string"
structDict['CFocusFtdcInnerSpreadInstrStrategyField'] = CFocusFtdcInnerSpreadInstrStrategyField


#盘中list请求域
CFocusFtdcTZeroHighStockStrategyField = {}
#交易日期
CFocusFtdcTZeroHighStockStrategyField["TradingDay"] = "string"
#用户代码
CFocusFtdcTZeroHighStockStrategyField["UserID"] = "string"
#交易所代码
CFocusFtdcTZeroHighStockStrategyField["ExchangeID"] = "string"
#股票合约代码
CFocusFtdcTZeroHighStockStrategyField["InstrumentID"] = "string"
#该股票用哪个资金账号去下单
CFocusFtdcTZeroHighStockStrategyField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcTZeroHighStockStrategyField["StockStrategyID"] = "string"
#TZero需要改变的股数
CFocusFtdcTZeroHighStockStrategyField["TZeroGapVolume"] = "int"
#股票下单类型
CFocusFtdcTZeroHighStockStrategyField["TZeroStockPriceType"] = "char"
#TZero最晚结束时间
CFocusFtdcTZeroHighStockStrategyField["TZeroEndOperTime"] = "string"
#TZero下单上限价格
CFocusFtdcTZeroHighStockStrategyField["TZeroUpperEndPrice"] = "float"
#TZero下单下限价格
CFocusFtdcTZeroHighStockStrategyField["TZeroLowerEndPrice"] = "float"
#t0最新设置时间
CFocusFtdcTZeroHighStockStrategyField["TZeroLastOperTime"] = "string"
structDict['CFocusFtdcTZeroHighStockStrategyField'] = CFocusFtdcTZeroHighStockStrategyField


#跟随期货初始总资金
CFocusFtdcFlowerFutureTargetMoneyField = {}
#用户代码
CFocusFtdcFlowerFutureTargetMoneyField["UserID"] = "string"
#投资者编号
CFocusFtdcFlowerFutureTargetMoneyField["InvestorID"] = "string"
#交易日期
CFocusFtdcFlowerFutureTargetMoneyField["TradingDay"] = "string"
#最新操作时间
CFocusFtdcFlowerFutureTargetMoneyField["LastOperTime"] = "string"
#初始化预分配换仓总资金
CFocusFtdcFlowerFutureTargetMoneyField["FlowerFutureTarMoney"] = "float"
#是否生效
CFocusFtdcFlowerFutureTargetMoneyField["WholeSwitch"] = "char"
structDict['CFocusFtdcFlowerFutureTargetMoneyField'] = CFocusFtdcFlowerFutureTargetMoneyField


#母单信息
CFocusFtdcParentOrderField = {}
#用户代码
CFocusFtdcParentOrderField["UserID"] = "string"
#母单资金代码
CFocusFtdcParentOrderField["InvestorID"] = "string"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcParentOrderField["AlgoParentOrderSysID"] = "string"
#算法策略类型(Twap,11,Vwap 12)
CFocusFtdcParentOrderField["AlgoStrategyType"] = "int"
#策略开始日期(YYYYMMDD)
CFocusFtdcParentOrderField["StrategyStartDay"] = "string"
#策略停止日期(YYYYMMDD)
CFocusFtdcParentOrderField["StrategyEndDay"] = "string"
#策略开始时间(HH:mm:ss)
CFocusFtdcParentOrderField["StrategyStartTime"] = "string"
#策略停止时间(HH:mm:ss)
CFocusFtdcParentOrderField["StrategyEndTime"] = "string"
#保守->激进 1--5
CFocusFtdcParentOrderField["style"] = "int"
#最大市场占比 TWAP/VWAP (0, 50]
CFocusFtdcParentOrderField["maxVolumeP"] = "float"
#最小挂单量，默认为0
CFocusFtdcParentOrderField["minDisplaySize"] = "int"
#最大挂单量（单一档位），默认为0
CFocusFtdcParentOrderField["displaySize"] = "int"
#量比统计口径，默认为限价内。限价内 - 0， 全市场 - 1
CFocusFtdcParentOrderField["countVolInLimitPx"] = "int"
#重启时重置量比。true - 1, false - 0
CFocusFtdcParentOrderField["resetVolOnAmend"] = "int"
#价格限制，默认为0
CFocusFtdcParentOrderField["limitPrice"] = "float"
#相对限价基准
CFocusFtdcParentOrderField["relativePriceLimitBase"] = "int"
#相对限价偏移单位
CFocusFtdcParentOrderField["relativePriceLimitType"] = "int"
#相对限价偏移量
CFocusFtdcParentOrderField["relativePriceLimitOffset"] = "float"
#是否进价差，默认进价差
CFocusFtdcParentOrderField["stepSpread"] = "int"
#涨跌停动作，涨跌停时可暂停、加速
CFocusFtdcParentOrderField["optOnExtreme"] = "int"
#交易所代码
CFocusFtdcParentOrderField["ExchangeID"] = "string"
#合约代码
CFocusFtdcParentOrderField["InstrumentID"] = "string"
#方向
CFocusFtdcParentOrderField["Direction"] = "char"
#总数量
CFocusFtdcParentOrderField["orderQty"] = "int"
#总金额
CFocusFtdcParentOrderField["orderAmt"] = "float"
#母单推送日期
CFocusFtdcParentOrderField["TradingDay"] = "string"
#母单推送时间
CFocusFtdcParentOrderField["LastOperTime"] = "string"
#用户自定义域(保留字段)
CFocusFtdcParentOrderField["UserCustom"] = "string"
#备注(保留字段)
CFocusFtdcParentOrderField["Note"] = "string"
#策略ID号
CFocusFtdcParentOrderField["StrategyID"] = "string"
structDict['CFocusFtdcParentOrderField'] = CFocusFtdcParentOrderField


#母单操作信息
CFocusFtdcParentOrderActionField = {}
#用户代码
CFocusFtdcParentOrderActionField["UserID"] = "string"
#投资者编号
CFocusFtdcParentOrderActionField["InvestorID"] = "string"
#交易所代码
CFocusFtdcParentOrderActionField["ExchangeID"] = "string"
#合约代码
CFocusFtdcParentOrderActionField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcParentOrderActionField["StrategyID"] = "string"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcParentOrderActionField["AlgoParentOrderSysID"] = "string"
#操作选项
CFocusFtdcParentOrderActionField["ActionOption"] = "int"
structDict['CFocusFtdcParentOrderActionField'] = CFocusFtdcParentOrderActionField


#修改母单信息
CFocusFtdcAmendParentOrderField = {}
#用户代码
CFocusFtdcAmendParentOrderField["UserID"] = "string"
#母单资金代码
CFocusFtdcAmendParentOrderField["InvestorID"] = "string"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcAmendParentOrderField["AlgoParentOrderSysID"] = "string"
#算法策略类型(Twap,11,Vwap 12)
CFocusFtdcAmendParentOrderField["AlgoStrategyType"] = "int"
#策略开始日期(YYYYMMDD)
CFocusFtdcAmendParentOrderField["StrategyStartDay"] = "string"
#策略停止日期(YYYYMMDD)
CFocusFtdcAmendParentOrderField["StrategyEndDay"] = "string"
#策略开始时间(HH:mm:ss)
CFocusFtdcAmendParentOrderField["StrategyStartTime"] = "string"
#策略停止时间(HH:mm:ss)
CFocusFtdcAmendParentOrderField["StrategyEndTime"] = "string"
#保守->激进 1--5
CFocusFtdcAmendParentOrderField["style"] = "int"
#最大市场占比 TWAP/VWAP (0, 50]
CFocusFtdcAmendParentOrderField["maxVolumeP"] = "float"
#最小挂单量，默认为0
CFocusFtdcAmendParentOrderField["minDisplaySize"] = "int"
#最大挂单量（单一档位），默认为0
CFocusFtdcAmendParentOrderField["displaySize"] = "int"
#量比统计口径，默认为限价内。限价内 - 0， 全市场 - 1
CFocusFtdcAmendParentOrderField["countVolInLimitPx"] = "int"
#重启时重置量比。true - 1, false - 0
CFocusFtdcAmendParentOrderField["resetVolOnAmend"] = "int"
#价格限制，默认为0
CFocusFtdcAmendParentOrderField["limitPrice"] = "float"
#相对限价基准
CFocusFtdcAmendParentOrderField["relativePriceLimitBase"] = "int"
#相对限价偏移单位
CFocusFtdcAmendParentOrderField["relativePriceLimitType"] = "int"
#相对限价偏移量
CFocusFtdcAmendParentOrderField["relativePriceLimitOffset"] = "float"
#是否进价差，默认进价差
CFocusFtdcAmendParentOrderField["stepSpread"] = "int"
#涨跌停动作，涨跌停时可暂停、加速
CFocusFtdcAmendParentOrderField["optOnExtreme"] = "int"
#交易所代码
CFocusFtdcAmendParentOrderField["ExchangeID"] = "string"
#合约代码
CFocusFtdcAmendParentOrderField["InstrumentID"] = "string"
#方向
CFocusFtdcAmendParentOrderField["Direction"] = "char"
#总数量
CFocusFtdcAmendParentOrderField["orderQty"] = "int"
#总金额
CFocusFtdcAmendParentOrderField["orderAmt"] = "float"
#母单推送日期
CFocusFtdcAmendParentOrderField["TradingDay"] = "string"
#母单推送时间
CFocusFtdcAmendParentOrderField["LastOperTime"] = "string"
#用户自定义域(保留字段)
CFocusFtdcAmendParentOrderField["UserCustom"] = "string"
#备注(保留字段)
CFocusFtdcAmendParentOrderField["Note"] = "string"
#策略ID号
CFocusFtdcAmendParentOrderField["StrategyID"] = "string"
structDict['CFocusFtdcAmendParentOrderField'] = CFocusFtdcAmendParentOrderField


#母单操作手动操作信息
CFocusFtdcExtraManualParentOrderField = {}
#用户代码
CFocusFtdcExtraManualParentOrderField["UserID"] = "string"
#母单用户代码
CFocusFtdcExtraManualParentOrderField["InvestorID"] = "string"
#策略ID号
CFocusFtdcExtraManualParentOrderField["StrategyID"] = "string"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcExtraManualParentOrderField["AlgoParentOrderSysID"] = "string"
#人工单数量
CFocusFtdcExtraManualParentOrderField["sliceQty"] = "int"
#人工单价格
CFocusFtdcExtraManualParentOrderField["slicePrice"] = "float"
#人工单特别备注(保留字段)
CFocusFtdcExtraManualParentOrderField["UserCustom"] = "string"
structDict['CFocusFtdcExtraManualParentOrderField'] = CFocusFtdcExtraManualParentOrderField


#发送母单进展详细信息
CFocusFtdcParentDetialUpdateMessageField = {}
#用户代码
CFocusFtdcParentDetialUpdateMessageField["UserID"] = "string"
#投资者编号
CFocusFtdcParentDetialUpdateMessageField["InvestorID"] = "string"
#交易所代码
CFocusFtdcParentDetialUpdateMessageField["ExchangeID"] = "string"
#合约代码
CFocusFtdcParentDetialUpdateMessageField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcParentDetialUpdateMessageField["StrategyID"] = "string"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcParentDetialUpdateMessageField["AlgoParentOrderSysID"] = "string"
#更新日期
CFocusFtdcParentDetialUpdateMessageField["transactDay"] = "string"
#更新时间
CFocusFtdcParentDetialUpdateMessageField["transactTime"] = "string"
#策略状态
CFocusFtdcParentDetialUpdateMessageField["strategyStatus"] = "int"
#暂停原因
CFocusFtdcParentDetialUpdateMessageField["pauseReason"] = "string"
#方向
CFocusFtdcParentDetialUpdateMessageField["Direction"] = "char"
#总数量
CFocusFtdcParentDetialUpdateMessageField["orderQty"] = "int"
#成交数量
CFocusFtdcParentDetialUpdateMessageField["knockQty"] = "int"
#成交金额
CFocusFtdcParentDetialUpdateMessageField["knockAmt"] = "float"
#清算金额
CFocusFtdcParentDetialUpdateMessageField["knockAmtWithFee"] = "float"
#母单状态
CFocusFtdcParentDetialUpdateMessageField["orderStatus"] = "int"
#平均价格
CFocusFtdcParentDetialUpdateMessageField["avgPrice"] = "float"
#市场TWAP均价
CFocusFtdcParentDetialUpdateMessageField["marketTwap"] = "float"
#市场VWAP均价
CFocusFtdcParentDetialUpdateMessageField["marketVwap"] = "float"
#到达价 
CFocusFtdcParentDetialUpdateMessageField["arrivalPrice"] = "float"
#均价偏差_T 
CFocusFtdcParentDetialUpdateMessageField["avgOffset_T"] = "float"
#均价偏差_V 
CFocusFtdcParentDetialUpdateMessageField["avgOffset_V"] = "float"
#均价偏差_A 
CFocusFtdcParentDetialUpdateMessageField["avgOffset_A"] = "float"
#真实参与率 
CFocusFtdcParentDetialUpdateMessageField["realParticipateRate"] = "float"
#撤单率 
CFocusFtdcParentDetialUpdateMessageField["cancelRate"] = "float"
#平均挂单时长 
CFocusFtdcParentDetialUpdateMessageField["avgOpenTime"] = "float"
#被动成交率 
CFocusFtdcParentDetialUpdateMessageField["passiveRate"] = "float"
#序列号 
CFocusFtdcParentDetialUpdateMessageField["serialNum"] = "string"
#拒绝原因 
CFocusFtdcParentDetialUpdateMessageField["failReason"] = "string"
#目标进度 
CFocusFtdcParentDetialUpdateMessageField["targetProgress"] = "float"
#成交比例 
CFocusFtdcParentDetialUpdateMessageField["knockPercent"] = "float"
#进度偏差 
CFocusFtdcParentDetialUpdateMessageField["progressOffset"] = "float"
#重要性 
CFocusFtdcParentDetialUpdateMessageField["pushFlag"] = "int"
#错误代码
CFocusFtdcParentDetialUpdateMessageField["ErrorID"] = "int"
#功能号
CFocusFtdcParentDetialUpdateMessageField["FunctionID"] = "int"
#策略开始时间(HH:mm:ss)
CFocusFtdcParentDetialUpdateMessageField["StrategyStartTime"] = "string"
#策略停止时间(HH:mm:ss)
CFocusFtdcParentDetialUpdateMessageField["StrategyEndTime"] = "string"
structDict['CFocusFtdcParentDetialUpdateMessageField'] = CFocusFtdcParentDetialUpdateMessageField


#产品代码查询请求
CFocusFtdcAPIQryMarketTradingTimeField = {}
#市场id
CFocusFtdcAPIQryMarketTradingTimeField["ExchangeID"] = "string"
#市场名称
CFocusFtdcAPIQryMarketTradingTimeField["ExchangeName"] = "string"
#产品代码
CFocusFtdcAPIQryMarketTradingTimeField["ProductID"] = "string"
structDict['CFocusFtdcAPIQryMarketTradingTimeField'] = CFocusFtdcAPIQryMarketTradingTimeField


#市场交易时间段信息
CFocusFtdcMarketTradingPeriodInfoField = {}
#市场id
CFocusFtdcMarketTradingPeriodInfoField["ExchangeID"] = "string"
#市场名称
CFocusFtdcMarketTradingPeriodInfoField["ExchangeName"] = "string"
#产品名称
CFocusFtdcMarketTradingPeriodInfoField["ProductID"] = "string"
#起始时间
CFocusFtdcMarketTradingPeriodInfoField["TpStart"] = "string"
#结束时间
CFocusFtdcMarketTradingPeriodInfoField["TpEnd"] = "string"
#类型标志
CFocusFtdcMarketTradingPeriodInfoField["Flags"] = "char"
structDict['CFocusFtdcMarketTradingPeriodInfoField'] = CFocusFtdcMarketTradingPeriodInfoField


#算法2股票期货对冲关系表
CFocusFtdcFutureStrategyTotalSecondRelationField = {}
#用户代码
CFocusFtdcFutureStrategyTotalSecondRelationField["UserID"] = "string"
#该股票用哪个资金账号去下单
CFocusFtdcFutureStrategyTotalSecondRelationField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcFutureStrategyTotalSecondRelationField["StockStrategyID"] = "string"
#股票策略当前是否交易
CFocusFtdcFutureStrategyTotalSecondRelationField["StockStrategyIsTrading"] = "int"
#期货交易所代码
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureExchangeID"] = "string"
#期货合约代码
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureInstrumentID"] = "string"
#期货买卖方向
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureDirection"] = "char"
#期货报单类型
CFocusFtdcFutureStrategyTotalSecondRelationField["FuturePriceType"] = "char"
#对应期货当前是否交易（换仓默认开关无效）
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureIsTrading"] = "int"
#期货资金账号
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureInvestorID"] = "string"
#期货默认检查时间间隔
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureTimeAvail"] = "int"
#期货间隔手数
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureAvailAmount"] = "int"
#期货算法类型
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureAlgoType"] = "int"
#指数交易所
CFocusFtdcFutureStrategyTotalSecondRelationField["IndexExchangeID"] = "string"
#指数合约
CFocusFtdcFutureStrategyTotalSecondRelationField["IndexInstrumentID"] = "string"
#基差
CFocusFtdcFutureStrategyTotalSecondRelationField["SpreadPrice"] = "float"
#期货总下单手数
CFocusFtdcFutureStrategyTotalSecondRelationField["FutureAmount"] = "int"
#List中price的价格类型
CFocusFtdcFutureStrategyTotalSecondRelationField["ListPriceType"] = "char"
#期现下单匹配度(0~1)
CFocusFtdcFutureStrategyTotalSecondRelationField["FuStockRelation"] = "float"
#加减仓起始时间
CFocusFtdcFutureStrategyTotalSecondRelationField["TpStart"] = "string"
#加减仓结束时间
CFocusFtdcFutureStrategyTotalSecondRelationField["TpEnd"] = "string"
structDict['CFocusFtdcFutureStrategyTotalSecondRelationField'] = CFocusFtdcFutureStrategyTotalSecondRelationField


#算法2股票期货对冲内部表详情
CFocusFtdcInnerFutureStrategyTotalSecondRelationField = {}
#用户代码
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["UserID"] = "string"
#该股票用哪个资金账号去下单
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["StockInvestorID"] = "string"
#股票策略ID
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["StockStrategyID"] = "string"
#股票策略当前是否交易
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["StockStrategyIsTrading"] = "int"
#期货交易所代码
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureExchangeID"] = "string"
#期货合约代码
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureInstrumentID"] = "string"
#期货买卖方向
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureDirection"] = "char"
#期货报单类型
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FuturePriceType"] = "char"
#对应期货当前是否交易（换仓默认开关无效）
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureIsTrading"] = "int"
#期货资金账号
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureInvestorID"] = "string"
#期货默认检查时间间隔
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureTimeAvail"] = "int"
#期货间隔手数
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureAvailAmount"] = "int"
#期货算法类型
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureAlgoType"] = "int"
#指数交易所
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["IndexExchangeID"] = "string"
#指数合约
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["IndexInstrumentID"] = "string"
#基差
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["SpreadPrice"] = "float"
#期货总下单手数
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureAmount"] = "int"
#List中price的价格类型
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["ListPriceType"] = "char"
#期现下单匹配度(0~1)
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FuStockRelation"] = "float"
#加减仓起始时间
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["TpStart"] = "string"
#加减仓结束时间
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["TpEnd"] = "string"
#操作备注
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["Note"] = "string"
#最新买总成交总量
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["LastTotalBuyMoney"] = "float"
#最新卖总成交总量
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["LastTotalSellMoney"] = "float"
#最新需要买的总金额
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["LastTotalNeedBuyMoney"] = "float"
#最新需要卖的总金额
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["LastTotalNeedSellMoney"] = "float"
#最新期货对冲操作时间
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["LastFuOperTime"] = "string"
#已完成对冲总交易量
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["LastFuTarNetPosition"] = "int"
#对冲操作备注
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureNote"] = "string"
#期货价差对冲是否需要检查
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["FutureSpreadNeedCheck"] = "int"
#开仓那刻期货价格
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["OpenFuInstrPrice"] = "float"
#上次完成的总交易量
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["BeforeLastFuTarNetPosition"] = "int"
#现货对于期货手数
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["NetFuPosition"] = "float"
#实时基差
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["RealTimeSpreadPrice"] = "float"
#实时指数价格
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["RealIndexPrice"] = "float"
#实时期货价格
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["RealFuturePrice"] = "float"
#最新期货对冲操作时间
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["LastHedgeFuOperTime"] = "string"
#期货实际匹配数量
CFocusFtdcInnerFutureStrategyTotalSecondRelationField["DoubleFutureAmount"] = "float"
structDict['CFocusFtdcInnerFutureStrategyTotalSecondRelationField'] = CFocusFtdcInnerFutureStrategyTotalSecondRelationField


#期货算法交易订单键值
CFocusFtdcParentOrderIndexField = {}
#用户代码
CFocusFtdcParentOrderIndexField["UserID"] = "string"
#投资者编号
CFocusFtdcParentOrderIndexField["InvestorID"] = "string"
#交易所代码
CFocusFtdcParentOrderIndexField["ExchangeID"] = "string"
#合约代码
CFocusFtdcParentOrderIndexField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcParentOrderIndexField["StrategyID"] = "string"
structDict['CFocusFtdcParentOrderIndexField'] = CFocusFtdcParentOrderIndexField


#母单算法基本信息参数
CFocusFtdcParentOrderStaticParamField = {}
#用户代码
CFocusFtdcParentOrderStaticParamField["UserID"] = "string"
#投资者编号
CFocusFtdcParentOrderStaticParamField["InvestorID"] = "string"
#交易所代码
CFocusFtdcParentOrderStaticParamField["ExchangeID"] = "string"
#合约代码
CFocusFtdcParentOrderStaticParamField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcParentOrderStaticParamField["StrategyID"] = "string"
#保守->激进 1--5
CFocusFtdcParentOrderStaticParamField["style"] = "int"
#最大市场占比 TWAP/VWAP (0, 0.5]
CFocusFtdcParentOrderStaticParamField["maxVolumeP"] = "float"
#最小挂单量，默认为0
CFocusFtdcParentOrderStaticParamField["minDisplaySize"] = "int"
#最大挂单量（单一档位），默认为0
CFocusFtdcParentOrderStaticParamField["displaySize"] = "int"
#量比统计口径，默认为限价内。限价内 - 0， 全市场 - 1
CFocusFtdcParentOrderStaticParamField["countVolInLimitPx"] = "int"
#重启时重置量比。true - 1, false - 0
CFocusFtdcParentOrderStaticParamField["resetVolOnAmend"] = "int"
#价格限制，默认为0
CFocusFtdcParentOrderStaticParamField["limitPrice"] = "float"
#相对限价基准 
CFocusFtdcParentOrderStaticParamField["relativePriceLimitBase"] = "int"
#相对限价偏移单位 枚举型 
CFocusFtdcParentOrderStaticParamField["relativePriceLimitType"] = "int"
#相对限价偏移量  double
CFocusFtdcParentOrderStaticParamField["relativePriceLimitOffset"] = "float"
#是否进价差，默认进价差 0，不进，1 进
CFocusFtdcParentOrderStaticParamField["stepSpread"] = "int"
#涨跌停动作，涨跌停时可暂停、加速，0是没动作，1是加速，2是暂停
CFocusFtdcParentOrderStaticParamField["optOnExtreme"] = "int"
structDict['CFocusFtdcParentOrderStaticParamField'] = CFocusFtdcParentOrderStaticParamField


#期现账户关系
CFocusFtdcFuSkAccountRelationField = {}
#经纪公司编号
CFocusFtdcFuSkAccountRelationField["BrokerID"] = "string"
#用户代码
CFocusFtdcFuSkAccountRelationField["UserID"] = "string"
#现货投资者编号
CFocusFtdcFuSkAccountRelationField["StockInvestorID"] = "string"
#期货投资者编号
CFocusFtdcFuSkAccountRelationField["FutureInvestorID"] = "string"
#期货资金密码
CFocusFtdcFuSkAccountRelationField["FuturePasswd"] = "string"
structDict['CFocusFtdcFuSkAccountRelationField'] = CFocusFtdcFuSkAccountRelationField


#批量报单录入
CFocusFtdcBatchInputOrderField = {}
#经纪公司编号
CFocusFtdcBatchInputOrderField["BrokerID"] = "string"
#投资者编号
CFocusFtdcBatchInputOrderField["InvestorID"] = "string"
#用户代码
CFocusFtdcBatchInputOrderField["UserID"] = "string"
#批量用户本地报单号
CFocusFtdcBatchInputOrderField["UserOrderLocalID"] = "string"
#批量用户自定义域
CFocusFtdcBatchInputOrderField["UserCustom"] = "string"
#批量交易所代码
CFocusFtdcBatchInputOrderField["ExchangeID"] = "string"
#批量合约代码
CFocusFtdcBatchInputOrderField["InstrumentID"] = "string"
#批量买卖方向
CFocusFtdcBatchInputOrderField["Direction"] = "string"
#批量开平标志
CFocusFtdcBatchInputOrderField["OffsetFlag"] = "string"
#批量价格
CFocusFtdcBatchInputOrderField["LimitPrice"] = "string"
#批量数量
CFocusFtdcBatchInputOrderField["Volume"] = "string"
structDict['CFocusFtdcBatchInputOrderField'] = CFocusFtdcBatchInputOrderField


#批量报单操作
CFocusFtdcBatchOrderActionField = {}
#经纪公司编号
CFocusFtdcBatchOrderActionField["BrokerID"] = "string"
#投资者编号
CFocusFtdcBatchOrderActionField["InvestorID"] = "string"
#用户代码
CFocusFtdcBatchOrderActionField["UserID"] = "string"
#批量用户本地报单号
CFocusFtdcBatchOrderActionField["UserOrderLocalID"] = "string"
#批量用户自定义域
CFocusFtdcBatchOrderActionField["UserCustom"] = "string"
#批量交易所代码
CFocusFtdcBatchOrderActionField["ExchangeID"] = "string"
#批量报单编号(768)
CFocusFtdcBatchOrderActionField["OrderSysID"] = "string"
#批量合约代码
CFocusFtdcBatchOrderActionField["InstrumentID"] = "string"
#批量本次撤单操作的本地编号
CFocusFtdcBatchOrderActionField["UserOrderActionLocalID"] = "string"
#前置编号
CFocusFtdcBatchOrderActionField["FrontID"] = "int"
#会话编号
CFocusFtdcBatchOrderActionField["SessionID"] = "int"
structDict['CFocusFtdcBatchOrderActionField'] = CFocusFtdcBatchOrderActionField


#投资者账户席位基本信息
CFocusFtdcUserInvestorSeatBaseField = {}
#经纪公司编号
CFocusFtdcUserInvestorSeatBaseField["BrokerID"] = "string"
#交易用户代码
CFocusFtdcUserInvestorSeatBaseField["UserID"] = "string"
#旧操作员密码
CFocusFtdcUserInvestorSeatBaseField["OldUserPassword"] = "string"
#新操作员密码
CFocusFtdcUserInvestorSeatBaseField["NewUserPassword"] = "string"
#席位代码
CFocusFtdcUserInvestorSeatBaseField["SeatID"] = "string"
#旧席位密码
CFocusFtdcUserInvestorSeatBaseField["OldSeatPassword"] = "string"
#新席位密码
CFocusFtdcUserInvestorSeatBaseField["NewSeatPassword"] = "string"
#投资者编号
CFocusFtdcUserInvestorSeatBaseField["InvestorID"] = "string"
#旧资金账号密码
CFocusFtdcUserInvestorSeatBaseField["OldInvestorPasswd"] = "string"
#新资金账号密码
CFocusFtdcUserInvestorSeatBaseField["NewInvestorPasswd"] = "string"
structDict['CFocusFtdcUserInvestorSeatBaseField'] = CFocusFtdcUserInvestorSeatBaseField


#期货交易详情算法交易订单键值
CFocusFtdcParentOrderDetialIndexField = {}
#用户代码
CFocusFtdcParentOrderDetialIndexField["UserID"] = "string"
#投资者编号
CFocusFtdcParentOrderDetialIndexField["InvestorID"] = "string"
#交易所代码
CFocusFtdcParentOrderDetialIndexField["ExchangeID"] = "string"
#合约代码
CFocusFtdcParentOrderDetialIndexField["InstrumentID"] = "string"
#策略ID号
CFocusFtdcParentOrderDetialIndexField["StrategyID"] = "string"
#系统母单报单编号(母单ID,主键,子单带回)
CFocusFtdcParentOrderDetialIndexField["AlgoParentOrderSysID"] = "string"
structDict['CFocusFtdcParentOrderDetialIndexField'] = CFocusFtdcParentOrderDetialIndexField





