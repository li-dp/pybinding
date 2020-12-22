# encoding: UTF-8

structDict = {}

#//////////////////////////////////////////////////////////////////////
#@system QuantDo Platform
#@company 山西证券股份有限公司
#@file QdFtdcUserApiStruct.h
#@brief 定义了客户端接口使用的业务数据结构
#@history 20190711 顾浩
#//////////////////////////////////////////////////////////////////////










#响应信息
CQdFtdcRspInfoField = {}
#错误代码
CQdFtdcRspInfoField["ErrorID"] = "int"
#错误信息
CQdFtdcRspInfoField["ErrorMsg"] = "string"
structDict['CQdFtdcRspInfoField'] = CQdFtdcRspInfoField


#Qdp响应信息
CQdFtdcQdpRspInfoField = {}
#错误代码
CQdFtdcQdpRspInfoField["ErrorID"] = "int"
#错误信息
CQdFtdcQdpRspInfoField["ErrorMsg"] = "string"
structDict['CQdFtdcQdpRspInfoField'] = CQdFtdcQdpRspInfoField


#系统用户登录请求
CQdFtdcReqUserLoginField = {}
#交易日
CQdFtdcReqUserLoginField["TradingDay"] = "string"
#交易用户代码
CQdFtdcReqUserLoginField["UserID"] = "string"
#经纪公司编号
CQdFtdcReqUserLoginField["BrokerID"] = "string"
#密码
CQdFtdcReqUserLoginField["Password"] = "string"
#用户端产品信息
CQdFtdcReqUserLoginField["UserProductInfo"] = "string"
#接口端产品信息
CQdFtdcReqUserLoginField["InterfaceProductInfo"] = "string"
#协议信息
CQdFtdcReqUserLoginField["ProtocolInfo"] = "string"
#IP地址
CQdFtdcReqUserLoginField["IPAddress"] = "string"
#Mac地址
CQdFtdcReqUserLoginField["MacAddress"] = "string"
#数据中心代码
CQdFtdcReqUserLoginField["DataCenterID"] = "int"
#动态密码
CQdFtdcReqUserLoginField["OneTimePassword"] = "string"
#终端IP地址
CQdFtdcReqUserLoginField["ClientIPAddress"] = "string"
#授权编码
CQdFtdcReqUserLoginField["AuthCode"] = "string"
structDict['CQdFtdcReqUserLoginField'] = CQdFtdcReqUserLoginField


#Qdp系统用户登录请求
CQdFtdcQdpReqUserLoginField = {}
#交易日
CQdFtdcQdpReqUserLoginField["TradingDay"] = "string"
#交易用户代码
CQdFtdcQdpReqUserLoginField["UserID"] = "string"
#经纪公司编号
CQdFtdcQdpReqUserLoginField["BrokerID"] = "string"
#密码
CQdFtdcQdpReqUserLoginField["Password"] = "string"
#用户端产品信息
CQdFtdcQdpReqUserLoginField["UserProductInfo"] = "string"
#接口端产品信息
CQdFtdcQdpReqUserLoginField["InterfaceProductInfo"] = "string"
#协议信息
CQdFtdcQdpReqUserLoginField["ProtocolInfo"] = "string"
#IP地址
CQdFtdcQdpReqUserLoginField["IPAddress"] = "string"
#Mac地址
CQdFtdcQdpReqUserLoginField["MacAddress"] = "string"
#数据中心代码
CQdFtdcQdpReqUserLoginField["DataCenterID"] = "int"
#动态密码
CQdFtdcQdpReqUserLoginField["OneTimePassword"] = "string"
#终端IP地址
CQdFtdcQdpReqUserLoginField["ClientIPAddress"] = "string"
structDict['CQdFtdcQdpReqUserLoginField'] = CQdFtdcQdpReqUserLoginField


#系统用户登录应答
CQdFtdcRspUserLoginField = {}
#交易日
CQdFtdcRspUserLoginField["TradingDay"] = "string"
#经纪公司编号
CQdFtdcRspUserLoginField["BrokerID"] = "string"
#交易用户代码
CQdFtdcRspUserLoginField["UserID"] = "string"
#登录成功时间
CQdFtdcRspUserLoginField["LoginTime"] = "string"
#用户最大本地报单号
CQdFtdcRspUserLoginField["MaxOrderLocalID"] = "string"
#交易系统名称
CQdFtdcRspUserLoginField["TradingSystemName"] = "string"
#数据中心代码
CQdFtdcRspUserLoginField["DataCenterID"] = "int"
#会员私有流当前长度
CQdFtdcRspUserLoginField["PrivateFlowSize"] = "int"
#交易员私有流当前长度
CQdFtdcRspUserLoginField["UserFlowSize"] = "int"
#登录附加信息
CQdFtdcRspUserLoginField["LoginInfo"] = "string"
#会话编号
CQdFtdcRspUserLoginField["SessionID"] = "int"
#前置编号
CQdFtdcRspUserLoginField["FrontID"] = "int"
structDict['CQdFtdcRspUserLoginField'] = CQdFtdcRspUserLoginField


#Qdp系统用户登录应答
CQdFtdcQdpRspUserLoginField = {}
#交易日
CQdFtdcQdpRspUserLoginField["TradingDay"] = "string"
#经纪公司编号
CQdFtdcQdpRspUserLoginField["BrokerID"] = "string"
#交易用户代码
CQdFtdcQdpRspUserLoginField["UserID"] = "string"
#登录成功时间
CQdFtdcQdpRspUserLoginField["LoginTime"] = "string"
#用户最大本地报单号
CQdFtdcQdpRspUserLoginField["MaxOrderLocalID"] = "string"
#交易系统名称
CQdFtdcQdpRspUserLoginField["TradingSystemName"] = "string"
#数据中心代码
CQdFtdcQdpRspUserLoginField["DataCenterID"] = "int"
#会员私有流当前长度
CQdFtdcQdpRspUserLoginField["PrivateFlowSize"] = "int"
#交易员私有流当前长度
CQdFtdcQdpRspUserLoginField["UserFlowSize"] = "int"
#会话编号
CQdFtdcQdpRspUserLoginField["SessionID"] = "int"
#前置编号
CQdFtdcQdpRspUserLoginField["FrontID"] = "int"
structDict['CQdFtdcQdpRspUserLoginField'] = CQdFtdcQdpRspUserLoginField


#用户登出请求
CQdFtdcReqUserLogoutField = {}
#经纪公司编号
CQdFtdcReqUserLogoutField["BrokerID"] = "string"
#交易用户代码
CQdFtdcReqUserLogoutField["UserID"] = "string"
structDict['CQdFtdcReqUserLogoutField'] = CQdFtdcReqUserLogoutField


#用户登出请求
CQdFtdcRspUserLogoutField = {}
#经纪公司编号
CQdFtdcRspUserLogoutField["BrokerID"] = "string"
#交易用户代码
CQdFtdcRspUserLogoutField["UserID"] = "string"
structDict['CQdFtdcRspUserLogoutField'] = CQdFtdcRspUserLogoutField


#行情基础属性
CQdFtdcMarketDataBaseField = {}
#交易日
CQdFtdcMarketDataBaseField["TradingDay"] = "string"
#昨结算
CQdFtdcMarketDataBaseField["PreSettlementPrice"] = "float"
#昨收盘
CQdFtdcMarketDataBaseField["PreClosePrice"] = "float"
#昨持仓量
CQdFtdcMarketDataBaseField["PreOpenInterest"] = "float"
#昨虚实度
CQdFtdcMarketDataBaseField["PreDelta"] = "float"
structDict['CQdFtdcMarketDataBaseField'] = CQdFtdcMarketDataBaseField


#Qdp行情基础属性
CQdFtdcQdpMarketDataBaseField = {}
#交易日
CQdFtdcQdpMarketDataBaseField["TradingDay"] = "string"
#结算组代码
CQdFtdcQdpMarketDataBaseField["SettlementGroupID"] = "string"
#结算编号
CQdFtdcQdpMarketDataBaseField["SettlementID"] = "int"
#昨结算
CQdFtdcQdpMarketDataBaseField["PreSettlementPrice"] = "float"
#昨收盘
CQdFtdcQdpMarketDataBaseField["PreClosePrice"] = "float"
#昨持仓量
CQdFtdcQdpMarketDataBaseField["PreOpenInterest"] = "float"
#昨虚实度
CQdFtdcQdpMarketDataBaseField["PreDelta"] = "float"
structDict['CQdFtdcQdpMarketDataBaseField'] = CQdFtdcQdpMarketDataBaseField


#行情静态属性
CQdFtdcMarketDataStaticField = {}
#今开盘
CQdFtdcMarketDataStaticField["OpenPrice"] = "float"
#最高价
CQdFtdcMarketDataStaticField["HighestPrice"] = "float"
#最低价
CQdFtdcMarketDataStaticField["LowestPrice"] = "float"
#今收盘
CQdFtdcMarketDataStaticField["ClosePrice"] = "float"
#涨停板价
CQdFtdcMarketDataStaticField["UpperLimitPrice"] = "float"
#跌停板价
CQdFtdcMarketDataStaticField["LowerLimitPrice"] = "float"
#今结算
CQdFtdcMarketDataStaticField["SettlementPrice"] = "float"
#今虚实度
CQdFtdcMarketDataStaticField["CurrDelta"] = "float"
structDict['CQdFtdcMarketDataStaticField'] = CQdFtdcMarketDataStaticField


#行情最新成交属性
CQdFtdcMarketDataLastMatchField = {}
#最新价
CQdFtdcMarketDataLastMatchField["LastPrice"] = "float"
#数量
CQdFtdcMarketDataLastMatchField["Volume"] = "int"
#成交笔数
CQdFtdcMarketDataLastMatchField["NumberVloume"] = "int"
#成交金额
CQdFtdcMarketDataLastMatchField["Turnover"] = "float"
#持仓量
CQdFtdcMarketDataLastMatchField["OpenInterest"] = "float"
structDict['CQdFtdcMarketDataLastMatchField'] = CQdFtdcMarketDataLastMatchField


#行情最优价属性
CQdFtdcMarketDataBestPriceField = {}
#申买价一
CQdFtdcMarketDataBestPriceField["BidPrice1"] = "float"
#申买量一
CQdFtdcMarketDataBestPriceField["BidVolume1"] = "int"
#申卖价一
CQdFtdcMarketDataBestPriceField["AskPrice1"] = "float"
#申卖量一
CQdFtdcMarketDataBestPriceField["AskVolume1"] = "int"
structDict['CQdFtdcMarketDataBestPriceField'] = CQdFtdcMarketDataBestPriceField


#行情申买二、三属性
CQdFtdcMarketDataBid23Field = {}
#申买价二
CQdFtdcMarketDataBid23Field["BidPrice2"] = "float"
#申买量二
CQdFtdcMarketDataBid23Field["BidVolume2"] = "int"
#申买价三
CQdFtdcMarketDataBid23Field["BidPrice3"] = "float"
#申买量三
CQdFtdcMarketDataBid23Field["BidVolume3"] = "int"
structDict['CQdFtdcMarketDataBid23Field'] = CQdFtdcMarketDataBid23Field


#行情申卖二、三属性
CQdFtdcMarketDataAsk23Field = {}
#申卖价二
CQdFtdcMarketDataAsk23Field["AskPrice2"] = "float"
#申卖量二
CQdFtdcMarketDataAsk23Field["AskVolume2"] = "int"
#申卖价三
CQdFtdcMarketDataAsk23Field["AskPrice3"] = "float"
#申卖量三
CQdFtdcMarketDataAsk23Field["AskVolume3"] = "int"
structDict['CQdFtdcMarketDataAsk23Field'] = CQdFtdcMarketDataAsk23Field


#行情申买四、五属性
CQdFtdcMarketDataBid45Field = {}
#申买价四
CQdFtdcMarketDataBid45Field["BidPrice4"] = "float"
#申买量四
CQdFtdcMarketDataBid45Field["BidVolume4"] = "int"
#申买价五
CQdFtdcMarketDataBid45Field["BidPrice5"] = "float"
#申买量五
CQdFtdcMarketDataBid45Field["BidVolume5"] = "int"
structDict['CQdFtdcMarketDataBid45Field'] = CQdFtdcMarketDataBid45Field


#行情申卖四、五属性
CQdFtdcMarketDataAsk45Field = {}
#申卖价四
CQdFtdcMarketDataAsk45Field["AskPrice4"] = "float"
#申卖量四
CQdFtdcMarketDataAsk45Field["AskVolume4"] = "int"
#申卖价五
CQdFtdcMarketDataAsk45Field["AskPrice5"] = "float"
#申卖量五
CQdFtdcMarketDataAsk45Field["AskVolume5"] = "int"
structDict['CQdFtdcMarketDataAsk45Field'] = CQdFtdcMarketDataAsk45Field


#行情更新时间属性
CQdFtdcMarketDataUpdateTimeField = {}
#合约代码
CQdFtdcMarketDataUpdateTimeField["InstrumentID"] = "string"
#最后修改时间
CQdFtdcMarketDataUpdateTimeField["UpdateTime"] = "string"
#最后修改毫秒
CQdFtdcMarketDataUpdateTimeField["UpdateMillisec"] = "int"
structDict['CQdFtdcMarketDataUpdateTimeField'] = CQdFtdcMarketDataUpdateTimeField


#深度行情
CQdFtdcDepthMarketDataField = {}
#交易日
CQdFtdcDepthMarketDataField["TradingDay"] = "string"
#昨结算
CQdFtdcDepthMarketDataField["PreSettlementPrice"] = "float"
#昨收盘
CQdFtdcDepthMarketDataField["PreClosePrice"] = "float"
#昨持仓量
CQdFtdcDepthMarketDataField["PreOpenInterest"] = "float"
#昨虚实度
CQdFtdcDepthMarketDataField["PreDelta"] = "float"
#今开盘
CQdFtdcDepthMarketDataField["OpenPrice"] = "float"
#最高价
CQdFtdcDepthMarketDataField["HighestPrice"] = "float"
#最低价
CQdFtdcDepthMarketDataField["LowestPrice"] = "float"
#今收盘
CQdFtdcDepthMarketDataField["ClosePrice"] = "float"
#涨停板价
CQdFtdcDepthMarketDataField["UpperLimitPrice"] = "float"
#跌停板价
CQdFtdcDepthMarketDataField["LowerLimitPrice"] = "float"
#今结算
CQdFtdcDepthMarketDataField["SettlementPrice"] = "float"
#今虚实度
CQdFtdcDepthMarketDataField["CurrDelta"] = "float"
#最新价
CQdFtdcDepthMarketDataField["LastPrice"] = "float"
#数量
CQdFtdcDepthMarketDataField["Volume"] = "int"
#成交笔数
CQdFtdcDepthMarketDataField["NumberVloume"] = "int"
#成交金额
CQdFtdcDepthMarketDataField["Turnover"] = "float"
#持仓量
CQdFtdcDepthMarketDataField["OpenInterest"] = "float"
#申买价一
CQdFtdcDepthMarketDataField["BidPrice1"] = "float"
#申买量一
CQdFtdcDepthMarketDataField["BidVolume1"] = "int"
#申卖价一
CQdFtdcDepthMarketDataField["AskPrice1"] = "float"
#申卖量一
CQdFtdcDepthMarketDataField["AskVolume1"] = "int"
#申买价二
CQdFtdcDepthMarketDataField["BidPrice2"] = "float"
#申买量二
CQdFtdcDepthMarketDataField["BidVolume2"] = "int"
#申买价三
CQdFtdcDepthMarketDataField["BidPrice3"] = "float"
#申买量三
CQdFtdcDepthMarketDataField["BidVolume3"] = "int"
#申卖价二
CQdFtdcDepthMarketDataField["AskPrice2"] = "float"
#申卖量二
CQdFtdcDepthMarketDataField["AskVolume2"] = "int"
#申卖价三
CQdFtdcDepthMarketDataField["AskPrice3"] = "float"
#申卖量三
CQdFtdcDepthMarketDataField["AskVolume3"] = "int"
#申买价四
CQdFtdcDepthMarketDataField["BidPrice4"] = "float"
#申买量四
CQdFtdcDepthMarketDataField["BidVolume4"] = "int"
#申买价五
CQdFtdcDepthMarketDataField["BidPrice5"] = "float"
#申买量五
CQdFtdcDepthMarketDataField["BidVolume5"] = "int"
#申卖价四
CQdFtdcDepthMarketDataField["AskPrice4"] = "float"
#申卖量四
CQdFtdcDepthMarketDataField["AskVolume4"] = "int"
#申卖价五
CQdFtdcDepthMarketDataField["AskPrice5"] = "float"
#申卖量五
CQdFtdcDepthMarketDataField["AskVolume5"] = "int"
#申买价六
CQdFtdcDepthMarketDataField["BidPrice6"] = "float"
#申买量六
CQdFtdcDepthMarketDataField["BidVolume6"] = "int"
#申买价七
CQdFtdcDepthMarketDataField["BidPrice7"] = "float"
#申买量七
CQdFtdcDepthMarketDataField["BidVolume7"] = "int"
#申卖价六
CQdFtdcDepthMarketDataField["AskPrice6"] = "float"
#申卖量六
CQdFtdcDepthMarketDataField["AskVolume6"] = "int"
#申卖价七
CQdFtdcDepthMarketDataField["AskPrice7"] = "float"
#申卖量七
CQdFtdcDepthMarketDataField["AskVolume7"] = "int"
#申买价八
CQdFtdcDepthMarketDataField["BidPrice8"] = "float"
#申买量八
CQdFtdcDepthMarketDataField["BidVolume8"] = "int"
#申买价九
CQdFtdcDepthMarketDataField["BidPrice9"] = "float"
#申买量九
CQdFtdcDepthMarketDataField["BidVolume9"] = "int"
#申卖价八
CQdFtdcDepthMarketDataField["AskPrice8"] = "float"
#申卖量八
CQdFtdcDepthMarketDataField["AskVolume8"] = "int"
#申卖价九
CQdFtdcDepthMarketDataField["AskPrice9"] = "float"
#申卖量九
CQdFtdcDepthMarketDataField["AskVolume9"] = "int"
#申买价十
CQdFtdcDepthMarketDataField["BidPrice10"] = "float"
#申买量十
CQdFtdcDepthMarketDataField["BidVolume10"] = "int"
#申卖价十
CQdFtdcDepthMarketDataField["AskPrice10"] = "float"
#申卖量十
CQdFtdcDepthMarketDataField["AskVolume10"] = "int"
#合约代码
CQdFtdcDepthMarketDataField["InstrumentID"] = "string"
#最后修改时间
CQdFtdcDepthMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CQdFtdcDepthMarketDataField["UpdateMillisec"] = "int"
#交易所代码
CQdFtdcDepthMarketDataField["ExchangeID"] = "string"
#总卖出数量
CQdFtdcDepthMarketDataField["VolumeAskLot"] = "int"
#总买入数量
CQdFtdcDepthMarketDataField["VolumeBidLot"] = "int"
#加权平均委买价格
CQdFtdcDepthMarketDataField["WeightAvgBidPx"] = "float"
#加权平均委卖价格
CQdFtdcDepthMarketDataField["WeightAvgSellPx"] = "float"
#合约状态
CQdFtdcDepthMarketDataField["InstrumentStatus"] = "char"
#当前日期
CQdFtdcDepthMarketDataField["CalendarDate"] = "string"
structDict['CQdFtdcDepthMarketDataField'] = CQdFtdcDepthMarketDataField


#深度行情
CQdFtdcQdpDepthMarketDataField = {}
#交易日
CQdFtdcQdpDepthMarketDataField["TradingDay"] = "string"
#结算组代码
CQdFtdcQdpDepthMarketDataField["SettlementGroupID"] = "string"
#结算编号
CQdFtdcQdpDepthMarketDataField["SettlementID"] = "int"
#昨结算
CQdFtdcQdpDepthMarketDataField["PreSettlementPrice"] = "float"
#昨收盘
CQdFtdcQdpDepthMarketDataField["PreClosePrice"] = "float"
#昨持仓量
CQdFtdcQdpDepthMarketDataField["PreOpenInterest"] = "float"
#昨虚实度
CQdFtdcQdpDepthMarketDataField["PreDelta"] = "float"
#今开盘
CQdFtdcQdpDepthMarketDataField["OpenPrice"] = "float"
#最高价
CQdFtdcQdpDepthMarketDataField["HighestPrice"] = "float"
#最低价
CQdFtdcQdpDepthMarketDataField["LowestPrice"] = "float"
#今收盘
CQdFtdcQdpDepthMarketDataField["ClosePrice"] = "float"
#涨停板价
CQdFtdcQdpDepthMarketDataField["UpperLimitPrice"] = "float"
#跌停板价
CQdFtdcQdpDepthMarketDataField["LowerLimitPrice"] = "float"
#今结算
CQdFtdcQdpDepthMarketDataField["SettlementPrice"] = "float"
#今虚实度
CQdFtdcQdpDepthMarketDataField["CurrDelta"] = "float"
#最新价
CQdFtdcQdpDepthMarketDataField["LastPrice"] = "float"
#数量
CQdFtdcQdpDepthMarketDataField["Volume"] = "int"
#成交笔数
CQdFtdcQdpDepthMarketDataField["NumberVloume"] = "int"
#成交金额
CQdFtdcQdpDepthMarketDataField["Turnover"] = "float"
#持仓量
CQdFtdcQdpDepthMarketDataField["OpenInterest"] = "float"
#申买价一
CQdFtdcQdpDepthMarketDataField["BidPrice1"] = "float"
#申买量一
CQdFtdcQdpDepthMarketDataField["BidVolume1"] = "int"
#申卖价一
CQdFtdcQdpDepthMarketDataField["AskPrice1"] = "float"
#申卖量一
CQdFtdcQdpDepthMarketDataField["AskVolume1"] = "int"
#申买价二
CQdFtdcQdpDepthMarketDataField["BidPrice2"] = "float"
#申买量二
CQdFtdcQdpDepthMarketDataField["BidVolume2"] = "int"
#申买价三
CQdFtdcQdpDepthMarketDataField["BidPrice3"] = "float"
#申买量三
CQdFtdcQdpDepthMarketDataField["BidVolume3"] = "int"
#申卖价二
CQdFtdcQdpDepthMarketDataField["AskPrice2"] = "float"
#申卖量二
CQdFtdcQdpDepthMarketDataField["AskVolume2"] = "int"
#申卖价三
CQdFtdcQdpDepthMarketDataField["AskPrice3"] = "float"
#申卖量三
CQdFtdcQdpDepthMarketDataField["AskVolume3"] = "int"
#申买价四
CQdFtdcQdpDepthMarketDataField["BidPrice4"] = "float"
#申买量四
CQdFtdcQdpDepthMarketDataField["BidVolume4"] = "int"
#申买价五
CQdFtdcQdpDepthMarketDataField["BidPrice5"] = "float"
#申买量五
CQdFtdcQdpDepthMarketDataField["BidVolume5"] = "int"
#申卖价四
CQdFtdcQdpDepthMarketDataField["AskPrice4"] = "float"
#申卖量四
CQdFtdcQdpDepthMarketDataField["AskVolume4"] = "int"
#申卖价五
CQdFtdcQdpDepthMarketDataField["AskPrice5"] = "float"
#申卖量五
CQdFtdcQdpDepthMarketDataField["AskVolume5"] = "int"
#合约代码
CQdFtdcQdpDepthMarketDataField["InstrumentID"] = "string"
#最后修改时间
CQdFtdcQdpDepthMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CQdFtdcQdpDepthMarketDataField["UpdateMillisec"] = "int"
#交易所代码
CQdFtdcQdpDepthMarketDataField["ExchangeID"] = "string"
structDict['CQdFtdcQdpDepthMarketDataField'] = CQdFtdcQdpDepthMarketDataField


#订阅合约的相关信息
CQdFtdcSpecificInstrumentField = {}
#合约代码
CQdFtdcSpecificInstrumentField["InstrumentID"] = "string"
structDict['CQdFtdcSpecificInstrumentField'] = CQdFtdcSpecificInstrumentField


#交易所代码
CQdFtdcMarketDataExchangeIDField = {}
#交易所代码
CQdFtdcMarketDataExchangeIDField["ExchangeID"] = "string"
structDict['CQdFtdcMarketDataExchangeIDField'] = CQdFtdcMarketDataExchangeIDField


#Qdp交易所代码
CQdFtdcQdpMarketDataExchangeIDField = {}
#交易所代码
CQdFtdcQdpMarketDataExchangeIDField["ExchangeID"] = "string"
structDict['CQdFtdcQdpMarketDataExchangeIDField'] = CQdFtdcQdpMarketDataExchangeIDField


#共享内存行情查询
CQdFtdcShmDepthMarketDataField = {}
#合约代码
CQdFtdcShmDepthMarketDataField["InstrumentID"] = "string"
#IP地址
CQdFtdcShmDepthMarketDataField["IPAddress"] = "string"
#订阅号
CQdFtdcShmDepthMarketDataField["TopicID"] = "int"
structDict['CQdFtdcShmDepthMarketDataField'] = CQdFtdcShmDepthMarketDataField


#TOPIC查询
CQdFtdcTopicSearchField = {}
#订阅号
CQdFtdcTopicSearchField["TopicID"] = "int"
structDict['CQdFtdcTopicSearchField'] = CQdFtdcTopicSearchField


#分价行情
CQdFtdcMBLMarketDataField = {}
#合约代码
CQdFtdcMBLMarketDataField["InstrumentID"] = "string"
#买卖方向
CQdFtdcMBLMarketDataField["Direction"] = "char"
#价格
CQdFtdcMBLMarketDataField["Price"] = "float"
#数量
CQdFtdcMBLMarketDataField["Volume"] = "int"
#最后修改时间
CQdFtdcMBLMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CQdFtdcMBLMarketDataField["UpdateMillisec"] = "int"
structDict['CQdFtdcMBLMarketDataField'] = CQdFtdcMBLMarketDataField


#套利合约买卖总量
CQdFtdcMarketDataCMBVolumeField = {}
#总卖出数量
CQdFtdcMarketDataCMBVolumeField["VolumeAskLot"] = "int"
#总买入数量
CQdFtdcMarketDataCMBVolumeField["VolumeBidLot"] = "int"
#加权平均委买价格
CQdFtdcMarketDataCMBVolumeField["WeightAvgBidPx"] = "float"
#加权平均委卖价格
CQdFtdcMarketDataCMBVolumeField["WeightAvgSellPx"] = "float"
structDict['CQdFtdcMarketDataCMBVolumeField'] = CQdFtdcMarketDataCMBVolumeField


#合约状态
CQdFtdcQmdInstrumentStateField = {}
#交易所代码
CQdFtdcQmdInstrumentStateField["ExchangeID"] = "string"
#合约代码
CQdFtdcQmdInstrumentStateField["InstrumentID"] = "string"
#合约交易状态
CQdFtdcQmdInstrumentStateField["InstrumentStatus"] = "char"
structDict['CQdFtdcQmdInstrumentStateField'] = CQdFtdcQmdInstrumentStateField


#行情合约状态
CQdFtdcMarketDataInstrumentStatusField = {}
#合约状态
CQdFtdcMarketDataInstrumentStatusField["InstrumentStatus"] = "char"
structDict['CQdFtdcMarketDataInstrumentStatusField'] = CQdFtdcMarketDataInstrumentStatusField


#信息分发
CQdFtdcDisseminationField = {}
#序列系列号
CQdFtdcDisseminationField["SequenceSeries"] = "int"
#序列号
CQdFtdcDisseminationField["SequenceNo"] = "int"
structDict['CQdFtdcDisseminationField'] = CQdFtdcDisseminationField


#Qdp信息分发
CQdFtdcQdpDisseminationField = {}
#序列系列号
CQdFtdcQdpDisseminationField["SequenceSeries"] = "int"
#序列号
CQdFtdcQdpDisseminationField["SequenceNo"] = "int"
structDict['CQdFtdcQdpDisseminationField'] = CQdFtdcQdpDisseminationField


#行情查询
CQdFtdcQryMarketDataField = {}
#交易所代码
CQdFtdcQryMarketDataField["ExchangeID"] = "string"
#合约代码
CQdFtdcQryMarketDataField["InstrumentID"] = "string"
structDict['CQdFtdcQryMarketDataField'] = CQdFtdcQryMarketDataField


#行情应答
CQdFtdcRspMarketDataField = {}
#交易所代码
CQdFtdcRspMarketDataField["ExchangeID"] = "string"
#交易日
CQdFtdcRspMarketDataField["TradingDay"] = "string"
#昨结算
CQdFtdcRspMarketDataField["PreSettlementPrice"] = "float"
#昨收盘
CQdFtdcRspMarketDataField["PreClosePrice"] = "float"
#昨持仓量
CQdFtdcRspMarketDataField["PreOpenInterest"] = "float"
#昨虚实度
CQdFtdcRspMarketDataField["PreDelta"] = "float"
#今开盘
CQdFtdcRspMarketDataField["OpenPrice"] = "float"
#最高价
CQdFtdcRspMarketDataField["HighestPrice"] = "float"
#最低价
CQdFtdcRspMarketDataField["LowestPrice"] = "float"
#今收盘
CQdFtdcRspMarketDataField["ClosePrice"] = "float"
#涨停板价
CQdFtdcRspMarketDataField["UpperLimitPrice"] = "float"
#跌停板价
CQdFtdcRspMarketDataField["LowerLimitPrice"] = "float"
#今结算
CQdFtdcRspMarketDataField["SettlementPrice"] = "float"
#今虚实度
CQdFtdcRspMarketDataField["CurrDelta"] = "float"
#最新价
CQdFtdcRspMarketDataField["LastPrice"] = "float"
#数量
CQdFtdcRspMarketDataField["Volume"] = "int"
#成交笔数
CQdFtdcRspMarketDataField["NumberVloume"] = "int"
#成交金额
CQdFtdcRspMarketDataField["Turnover"] = "float"
#持仓量
CQdFtdcRspMarketDataField["OpenInterest"] = "float"
#申买价一
CQdFtdcRspMarketDataField["BidPrice1"] = "float"
#申买量一
CQdFtdcRspMarketDataField["BidVolume1"] = "int"
#申卖价一
CQdFtdcRspMarketDataField["AskPrice1"] = "float"
#申卖量一
CQdFtdcRspMarketDataField["AskVolume1"] = "int"
#合约代码
CQdFtdcRspMarketDataField["InstrumentID"] = "string"
#最后修改时间
CQdFtdcRspMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CQdFtdcRspMarketDataField["UpdateMillisec"] = "int"
#合约状态
CQdFtdcRspMarketDataField["InstrumentStatus"] = "char"
structDict['CQdFtdcRspMarketDataField'] = CQdFtdcRspMarketDataField


#MDTen最优买属性
CQdFtdcMDTenBestBuyOrderField = {}
#最优买价格
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderPrice"] = "float"
#申买量一
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtyOne"] = "int"
#申买量二
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtyTwo"] = "int"
#申买量三
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtyThree"] = "int"
#申买量四
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtyFour"] = "int"
#申买量五
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtyFive"] = "int"
#申买量六
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtySix"] = "int"
#申买量七
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtySeven"] = "int"
#申买量八
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtyEight"] = "int"
#申买量九
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtyNine"] = "int"
#申买量十
CQdFtdcMDTenBestBuyOrderField["BestBuyOrderQtyTen"] = "int"
structDict['CQdFtdcMDTenBestBuyOrderField'] = CQdFtdcMDTenBestBuyOrderField


#MDTen最优卖属性
CQdFtdcMDTenBestSellOrderField = {}
#最优卖价格
CQdFtdcMDTenBestSellOrderField["BestSellOrderPrice"] = "float"
#申卖量一
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtyOne"] = "int"
#申卖量二
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtyTwo"] = "int"
#申卖量三
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtyThree"] = "int"
#申卖量四
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtyFour"] = "int"
#申卖量五
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtyFive"] = "int"
#申卖量六
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtySix"] = "int"
#申卖量七
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtySeven"] = "int"
#申卖量八
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtyEight"] = "int"
#申卖量九
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtyNine"] = "int"
#申卖量十
CQdFtdcMDTenBestSellOrderField["BestSellOrderQtyTen"] = "int"
structDict['CQdFtdcMDTenBestSellOrderField'] = CQdFtdcMDTenBestSellOrderField


#MDTen深度行情
CQdFtdcMDTenDepthMarketDataField = {}
#合约代码
CQdFtdcMDTenDepthMarketDataField["InstrumentID"] = "string"
#最后修改时间
CQdFtdcMDTenDepthMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CQdFtdcMDTenDepthMarketDataField["UpdateMillisec"] = "int"
#最优买价格
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderPrice"] = "float"
#申买量一
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtyOne"] = "int"
#申买量二
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtyTwo"] = "int"
#申买量三
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtyThree"] = "int"
#申买量四
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtyFour"] = "int"
#申买量五
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtyFive"] = "int"
#申买量六
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtySix"] = "int"
#申买量七
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtySeven"] = "int"
#申买量八
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtyEight"] = "int"
#申买量九
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtyNine"] = "int"
#申买量十
CQdFtdcMDTenDepthMarketDataField["BestBuyOrderQtyTen"] = "int"
#最优卖价格
CQdFtdcMDTenDepthMarketDataField["BestSellOrderPrice"] = "float"
#申卖量一
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtyOne"] = "int"
#申卖量二
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtyTwo"] = "int"
#申卖量三
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtyThree"] = "int"
#申卖量四
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtyFour"] = "int"
#申卖量五
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtyFive"] = "int"
#申卖量六
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtySix"] = "int"
#申卖量七
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtySeven"] = "int"
#申卖量八
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtyEight"] = "int"
#申卖量九
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtyNine"] = "int"
#申卖量十
CQdFtdcMDTenDepthMarketDataField["BestSellOrderQtyTen"] = "int"
#交易所代码
CQdFtdcMDTenDepthMarketDataField["ExchangeID"] = "string"
structDict['CQdFtdcMDTenDepthMarketDataField'] = CQdFtdcMDTenDepthMarketDataField


#期权静态属性
CQdFtdcOptionStaticField = {}
#交易所代码
CQdFtdcOptionStaticField["ExchangeID"] = "string"
#交易日
CQdFtdcOptionStaticField["TradingDay"] = "string"
#用户
CQdFtdcOptionStaticField["UserID"] = "string"
#客户端设置波动率
CQdFtdcOptionStaticField["IsManalSetVol"] = "char"
structDict['CQdFtdcOptionStaticField'] = CQdFtdcOptionStaticField


#期权最新价
CQdFtdcOptionLastpriceField = {}
#标的最新价
CQdFtdcOptionLastpriceField["UnderlyingLastPrice"] = "float"
#最新价
CQdFtdcOptionLastpriceField["LastPrice"] = "float"
#理论波动率
CQdFtdcOptionLastpriceField["TheoryVol"] = "float"
structDict['CQdFtdcOptionLastpriceField'] = CQdFtdcOptionLastpriceField


#期权买一价
CQdFtdcOptionBidpriceField = {}
#标的买1价
CQdFtdcOptionBidpriceField["UnderlyingBidPrice1"] = "float"
#买1价
CQdFtdcOptionBidpriceField["BidPrice1"] = "float"
structDict['CQdFtdcOptionBidpriceField'] = CQdFtdcOptionBidpriceField


#期权买一价
CQdFtdcOptionAskpriceField = {}
#标的卖1价
CQdFtdcOptionAskpriceField["UnderlyingAskPrice1"] = "float"
#卖1价
CQdFtdcOptionAskpriceField["AskPrice1"] = "float"
structDict['CQdFtdcOptionAskpriceField'] = CQdFtdcOptionAskpriceField


#期权希腊值
CQdFtdcOptionGreeksField = {}
#剩余天数
CQdFtdcOptionGreeksField["RemainDay"] = "float"
#卖1价波动率
CQdFtdcOptionGreeksField["AskVol"] = "float"
#买1价波动率
CQdFtdcOptionGreeksField["BidVol"] = "float"
#最新价波动率
CQdFtdcOptionGreeksField["LastVol"] = "float"
#中间价波动率
CQdFtdcOptionGreeksField["MidVol"] = "float"
#Delta
CQdFtdcOptionGreeksField["Delta"] = "float"
#Gamma
CQdFtdcOptionGreeksField["Gamma"] = "float"
#Vega
CQdFtdcOptionGreeksField["Vega"] = "float"
#Theta
CQdFtdcOptionGreeksField["Theta"] = "float"
#Rho
CQdFtdcOptionGreeksField["Rho"] = "float"
structDict['CQdFtdcOptionGreeksField'] = CQdFtdcOptionGreeksField


#期权行情
CQdFtdcOptionIndexDataField = {}
#合约代码
CQdFtdcOptionIndexDataField["InstrumentID"] = "string"
#最后修改时间
CQdFtdcOptionIndexDataField["UpdateTime"] = "string"
#最后修改毫秒
CQdFtdcOptionIndexDataField["UpdateMillisec"] = "int"
#交易所代码
CQdFtdcOptionIndexDataField["ExchangeID"] = "string"
#交易日
CQdFtdcOptionIndexDataField["TradingDay"] = "string"
#用户
CQdFtdcOptionIndexDataField["UserID"] = "string"
#客户端设置波动率
CQdFtdcOptionIndexDataField["IsManalSetVol"] = "char"
#标的最新价
CQdFtdcOptionIndexDataField["UnderlyingLastPrice"] = "float"
#最新价
CQdFtdcOptionIndexDataField["LastPrice"] = "float"
#理论波动率
CQdFtdcOptionIndexDataField["TheoryVol"] = "float"
#标的买1价
CQdFtdcOptionIndexDataField["UnderlyingBidPrice1"] = "float"
#买1价
CQdFtdcOptionIndexDataField["BidPrice1"] = "float"
#标的卖1价
CQdFtdcOptionIndexDataField["UnderlyingAskPrice1"] = "float"
#卖1价
CQdFtdcOptionIndexDataField["AskPrice1"] = "float"
#剩余天数
CQdFtdcOptionIndexDataField["RemainDay"] = "float"
#卖1价波动率
CQdFtdcOptionIndexDataField["AskVol"] = "float"
#买1价波动率
CQdFtdcOptionIndexDataField["BidVol"] = "float"
#最新价波动率
CQdFtdcOptionIndexDataField["LastVol"] = "float"
#中间价波动率
CQdFtdcOptionIndexDataField["MidVol"] = "float"
#Delta
CQdFtdcOptionIndexDataField["Delta"] = "float"
#Gamma
CQdFtdcOptionIndexDataField["Gamma"] = "float"
#Vega
CQdFtdcOptionIndexDataField["Vega"] = "float"
#Theta
CQdFtdcOptionIndexDataField["Theta"] = "float"
#Rho
CQdFtdcOptionIndexDataField["Rho"] = "float"
structDict['CQdFtdcOptionIndexDataField'] = CQdFtdcOptionIndexDataField


#当前日期
CQdFtdcMarketDataActionDayField = {}
#当前日期
CQdFtdcMarketDataActionDayField["CalendarDate"] = "string"
structDict['CQdFtdcMarketDataActionDayField'] = CQdFtdcMarketDataActionDayField


#分钟行情查询
CQdFtdcQryMinMarketDataField = {}
#交易所代码
CQdFtdcQryMinMarketDataField["ExchangeID"] = "string"
#合约代码
CQdFtdcQryMinMarketDataField["InstrumentID"] = "string"
#交易日
CQdFtdcQryMinMarketDataField["TradingDay"] = "string"
#起始时间
CQdFtdcQryMinMarketDataField["StartUpdateTime"] = "string"
#截止时间
CQdFtdcQryMinMarketDataField["EndUpdateTime"] = "string"
structDict['CQdFtdcQryMinMarketDataField'] = CQdFtdcQryMinMarketDataField


#分钟行情数据
CQdFtdcDeptMinMarketDataField = {}
#交易日
CQdFtdcDeptMinMarketDataField["TradingDay"] = "string"
#交易所代码
CQdFtdcDeptMinMarketDataField["ExchangeID"] = "string"
#合约代码
CQdFtdcDeptMinMarketDataField["InstrumentID"] = "string"
#前收盘
CQdFtdcDeptMinMarketDataField["PreClosePrice"] = "float"
#前持仓量
CQdFtdcDeptMinMarketDataField["PreOpenInterest"] = "float"
#开盘价
CQdFtdcDeptMinMarketDataField["OpenPrice"] = "float"
#最高价
CQdFtdcDeptMinMarketDataField["HighestPrice"] = "float"
#最低价
CQdFtdcDeptMinMarketDataField["LowestPrice"] = "float"
#最新价
CQdFtdcDeptMinMarketDataField["LastPrice"] = "float"
#收盘价
CQdFtdcDeptMinMarketDataField["ClosePrice"] = "float"
#成交量
CQdFtdcDeptMinMarketDataField["Volume"] = "int"
#成交金额
CQdFtdcDeptMinMarketDataField["Turnover"] = "float"
#持仓量
CQdFtdcDeptMinMarketDataField["OpenInterest"] = "float"
#涨停板价
CQdFtdcDeptMinMarketDataField["UpperLimitPrice"] = "float"
#跌停板价
CQdFtdcDeptMinMarketDataField["LowerLimitPrice"] = "float"
#最后修改时间
CQdFtdcDeptMinMarketDataField["UpdateTime"] = "string"
#tick今收盘
CQdFtdcDeptMinMarketDataField["TickOpenPrice"] = "float"
#tick昨收盘
CQdFtdcDeptMinMarketDataField["TickPreClosePrice"] = "float"
#最后收到Tick的时间
CQdFtdcDeptMinMarketDataField["TickUpdateTime"] = "string"
#合约状态
CQdFtdcDeptMinMarketDataField["InstrumentStatus"] = "char"
structDict['CQdFtdcDeptMinMarketDataField'] = CQdFtdcDeptMinMarketDataField


#分钟线内部详细信息
CQdFtdcDepthMinMarketDataTickField = {}
#交易日
CQdFtdcDepthMinMarketDataTickField["TradingDay"] = "string"
#昨结算
CQdFtdcDepthMinMarketDataTickField["PreSettlementPrice"] = "float"
#昨收盘
CQdFtdcDepthMinMarketDataTickField["PreClosePrice"] = "float"
#昨持仓量
CQdFtdcDepthMinMarketDataTickField["PreOpenInterest"] = "float"
#昨虚实度
CQdFtdcDepthMinMarketDataTickField["PreDelta"] = "float"
#今开盘
CQdFtdcDepthMinMarketDataTickField["OpenPrice"] = "float"
#最高价
CQdFtdcDepthMinMarketDataTickField["HighestPrice"] = "float"
#最低价
CQdFtdcDepthMinMarketDataTickField["LowestPrice"] = "float"
#今收盘
CQdFtdcDepthMinMarketDataTickField["ClosePrice"] = "float"
#涨停板价
CQdFtdcDepthMinMarketDataTickField["UpperLimitPrice"] = "float"
#跌停板价
CQdFtdcDepthMinMarketDataTickField["LowerLimitPrice"] = "float"
#今结算
CQdFtdcDepthMinMarketDataTickField["SettlementPrice"] = "float"
#今虚实度
CQdFtdcDepthMinMarketDataTickField["CurrDelta"] = "float"
#最新价
CQdFtdcDepthMinMarketDataTickField["LastPrice"] = "float"
#数量
CQdFtdcDepthMinMarketDataTickField["Volume"] = "int"
#成交笔数
CQdFtdcDepthMinMarketDataTickField["NumberVloume"] = "int"
#成交金额
CQdFtdcDepthMinMarketDataTickField["Turnover"] = "float"
#持仓量
CQdFtdcDepthMinMarketDataTickField["OpenInterest"] = "float"
#申买价一
CQdFtdcDepthMinMarketDataTickField["BidPrice1"] = "float"
#申买量一
CQdFtdcDepthMinMarketDataTickField["BidVolume1"] = "int"
#申卖价一
CQdFtdcDepthMinMarketDataTickField["AskPrice1"] = "float"
#申卖量一
CQdFtdcDepthMinMarketDataTickField["AskVolume1"] = "int"
#申买价二
CQdFtdcDepthMinMarketDataTickField["BidPrice2"] = "float"
#申买量二
CQdFtdcDepthMinMarketDataTickField["BidVolume2"] = "int"
#申买价三
CQdFtdcDepthMinMarketDataTickField["BidPrice3"] = "float"
#申买量三
CQdFtdcDepthMinMarketDataTickField["BidVolume3"] = "int"
#申卖价二
CQdFtdcDepthMinMarketDataTickField["AskPrice2"] = "float"
#申卖量二
CQdFtdcDepthMinMarketDataTickField["AskVolume2"] = "int"
#申卖价三
CQdFtdcDepthMinMarketDataTickField["AskPrice3"] = "float"
#申卖量三
CQdFtdcDepthMinMarketDataTickField["AskVolume3"] = "int"
#申买价四
CQdFtdcDepthMinMarketDataTickField["BidPrice4"] = "float"
#申买量四
CQdFtdcDepthMinMarketDataTickField["BidVolume4"] = "int"
#申买价五
CQdFtdcDepthMinMarketDataTickField["BidPrice5"] = "float"
#申买量五
CQdFtdcDepthMinMarketDataTickField["BidVolume5"] = "int"
#申卖价四
CQdFtdcDepthMinMarketDataTickField["AskPrice4"] = "float"
#申卖量四
CQdFtdcDepthMinMarketDataTickField["AskVolume4"] = "int"
#申卖价五
CQdFtdcDepthMinMarketDataTickField["AskPrice5"] = "float"
#申卖量五
CQdFtdcDepthMinMarketDataTickField["AskVolume5"] = "int"
#申买价六
CQdFtdcDepthMinMarketDataTickField["BidPrice6"] = "float"
#申买量六
CQdFtdcDepthMinMarketDataTickField["BidVolume6"] = "int"
#申买价七
CQdFtdcDepthMinMarketDataTickField["BidPrice7"] = "float"
#申买量七
CQdFtdcDepthMinMarketDataTickField["BidVolume7"] = "int"
#申卖价六
CQdFtdcDepthMinMarketDataTickField["AskPrice6"] = "float"
#申卖量六
CQdFtdcDepthMinMarketDataTickField["AskVolume6"] = "int"
#申卖价七
CQdFtdcDepthMinMarketDataTickField["AskPrice7"] = "float"
#申卖量七
CQdFtdcDepthMinMarketDataTickField["AskVolume7"] = "int"
#申买价八
CQdFtdcDepthMinMarketDataTickField["BidPrice8"] = "float"
#申买量八
CQdFtdcDepthMinMarketDataTickField["BidVolume8"] = "int"
#申买价九
CQdFtdcDepthMinMarketDataTickField["BidPrice9"] = "float"
#申买量九
CQdFtdcDepthMinMarketDataTickField["BidVolume9"] = "int"
#申卖价八
CQdFtdcDepthMinMarketDataTickField["AskPrice8"] = "float"
#申卖量八
CQdFtdcDepthMinMarketDataTickField["AskVolume8"] = "int"
#申卖价九
CQdFtdcDepthMinMarketDataTickField["AskPrice9"] = "float"
#申卖量九
CQdFtdcDepthMinMarketDataTickField["AskVolume9"] = "int"
#申买价十
CQdFtdcDepthMinMarketDataTickField["BidPrice10"] = "float"
#申买量十
CQdFtdcDepthMinMarketDataTickField["BidVolume10"] = "int"
#申卖价十
CQdFtdcDepthMinMarketDataTickField["AskPrice10"] = "float"
#申卖量十
CQdFtdcDepthMinMarketDataTickField["AskVolume10"] = "int"
#合约代码
CQdFtdcDepthMinMarketDataTickField["InstrumentID"] = "string"
#最后修改时间
CQdFtdcDepthMinMarketDataTickField["UpdateTime"] = "string"
#最后修改毫秒
CQdFtdcDepthMinMarketDataTickField["UpdateMillisec"] = "int"
#交易所代码
CQdFtdcDepthMinMarketDataTickField["ExchangeID"] = "string"
#总卖出数量
CQdFtdcDepthMinMarketDataTickField["VolumeAskLot"] = "int"
#总买入数量
CQdFtdcDepthMinMarketDataTickField["VolumeBidLot"] = "int"
#加权平均委买价格
CQdFtdcDepthMinMarketDataTickField["WeightAvgBidPx"] = "float"
#加权平均委卖价格
CQdFtdcDepthMinMarketDataTickField["WeightAvgSellPx"] = "float"
#合约状态
CQdFtdcDepthMinMarketDataTickField["InstrumentStatus"] = "char"
#当前日期
CQdFtdcDepthMinMarketDataTickField["CalendarDate"] = "string"
#tick今收盘
CQdFtdcDepthMinMarketDataTickField["TickOpenPrice"] = "float"
#tick昨收盘
CQdFtdcDepthMinMarketDataTickField["TickPreClosePrice"] = "float"
#最后收到Tick的时间
CQdFtdcDepthMinMarketDataTickField["TickUpdateTime"] = "string"
structDict['CQdFtdcDepthMinMarketDataTickField'] = CQdFtdcDepthMinMarketDataTickField


#逐笔成交数据
CQdFtdcDeptTradeMaketDataField = {}
#交易日
CQdFtdcDeptTradeMaketDataField["TradingDay"] = "string"
#交易所代码
CQdFtdcDeptTradeMaketDataField["ExchangeID"] = "string"
#合约代码
CQdFtdcDeptTradeMaketDataField["InstrumentID"] = "string"
#成交编号
CQdFtdcDeptTradeMaketDataField["TradeIndex"] = "int"
#成交价
CQdFtdcDeptTradeMaketDataField["TradePirce"] = "float"
#成交量
CQdFtdcDeptTradeMaketDataField["TradeVolume"] = "int"
#成交金额
CQdFtdcDeptTradeMaketDataField["TradeTurnover"] = "float"
#成交时间（s）
CQdFtdcDeptTradeMaketDataField["TradeTime"] = "string"
#成交时间（毫秒）
CQdFtdcDeptTradeMaketDataField["TradeMillisec"] = "int"
structDict['CQdFtdcDeptTradeMaketDataField'] = CQdFtdcDeptTradeMaketDataField


#逐笔委托数据
CQdFtdcDeptOrderMaketDataField = {}
#交易日
CQdFtdcDeptOrderMaketDataField["TradingDay"] = "string"
#交易所代码
CQdFtdcDeptOrderMaketDataField["ExchangeID"] = "string"
#合约代码
CQdFtdcDeptOrderMaketDataField["InstrumentID"] = "string"
#买卖方向
CQdFtdcDeptOrderMaketDataField["Direction"] = "char"
#订单类型
CQdFtdcDeptOrderMaketDataField["OrderTypeStr"] = "char"
#委托价格
CQdFtdcDeptOrderMaketDataField["OrderPirce"] = "float"
#成交量
CQdFtdcDeptOrderMaketDataField["TradeVolume"] = "int"
#委托时间（s）
CQdFtdcDeptOrderMaketDataField["OrderTime"] = "string"
#委托时间（毫秒）
CQdFtdcDeptOrderMaketDataField["OrderMillisec"] = "int"
structDict['CQdFtdcDeptOrderMaketDataField'] = CQdFtdcDeptOrderMaketDataField


#行情申买六、七属性
CQdFtdcMarketDataBid67Field = {}
#申买价六
CQdFtdcMarketDataBid67Field["BidPrice6"] = "float"
#申买量六
CQdFtdcMarketDataBid67Field["BidVolume6"] = "int"
#申买价七
CQdFtdcMarketDataBid67Field["BidPrice7"] = "float"
#申买量七
CQdFtdcMarketDataBid67Field["BidVolume7"] = "int"
structDict['CQdFtdcMarketDataBid67Field'] = CQdFtdcMarketDataBid67Field


#行情申卖六、七属性
CQdFtdcMarketDataAsk67Field = {}
#申卖价六
CQdFtdcMarketDataAsk67Field["AskPrice6"] = "float"
#申卖量六
CQdFtdcMarketDataAsk67Field["AskVolume6"] = "int"
#申卖价七
CQdFtdcMarketDataAsk67Field["AskPrice7"] = "float"
#申卖量七
CQdFtdcMarketDataAsk67Field["AskVolume7"] = "int"
structDict['CQdFtdcMarketDataAsk67Field'] = CQdFtdcMarketDataAsk67Field


#行情申买八、九属性
CQdFtdcMarketDataBid89Field = {}
#申买价八
CQdFtdcMarketDataBid89Field["BidPrice8"] = "float"
#申买量八
CQdFtdcMarketDataBid89Field["BidVolume8"] = "int"
#申买价九
CQdFtdcMarketDataBid89Field["BidPrice9"] = "float"
#申买量九
CQdFtdcMarketDataBid89Field["BidVolume9"] = "int"
structDict['CQdFtdcMarketDataBid89Field'] = CQdFtdcMarketDataBid89Field


#行情申卖八、九属性
CQdFtdcMarketDataAsk89Field = {}
#申卖价八
CQdFtdcMarketDataAsk89Field["AskPrice8"] = "float"
#申卖量八
CQdFtdcMarketDataAsk89Field["AskVolume8"] = "int"
#申卖价九
CQdFtdcMarketDataAsk89Field["AskPrice9"] = "float"
#申卖量九
CQdFtdcMarketDataAsk89Field["AskVolume9"] = "int"
structDict['CQdFtdcMarketDataAsk89Field'] = CQdFtdcMarketDataAsk89Field


#行情申买卖十属性
CQdFtdcMarketDataBidAsk10Field = {}
#申买价十
CQdFtdcMarketDataBidAsk10Field["BidPrice10"] = "float"
#申买量十
CQdFtdcMarketDataBidAsk10Field["BidVolume10"] = "int"
#申卖价十
CQdFtdcMarketDataBidAsk10Field["AskPrice10"] = "float"
#申卖量十
CQdFtdcMarketDataBidAsk10Field["AskVolume10"] = "int"
structDict['CQdFtdcMarketDataBidAsk10Field'] = CQdFtdcMarketDataBidAsk10Field


#买卖操作变化信息
CQdFtdcSellBuyChangeField = {}
#买入撤单笔数
CQdFtdcSellBuyChangeField["WithdrawBuyNumber"] = "int"
#卖出撤单笔数
CQdFtdcSellBuyChangeField["WithdrawSellNumber"] = "int"
#买入撤单数量
CQdFtdcSellBuyChangeField["WithdrawBuyAmount"] = "int"
#买入撤单金额
CQdFtdcSellBuyChangeField["WithdrawBuyMoney"] = "float"
#卖出撤单数量
CQdFtdcSellBuyChangeField["WithdrawSellAmount"] = "int"
#卖出撤单金额
CQdFtdcSellBuyChangeField["WithdrawSellMoney"] = "float"
#买入总笔数
CQdFtdcSellBuyChangeField["TotalBidNumber"] = "int"
#卖出总笔数
CQdFtdcSellBuyChangeField["TotalOfferNumber"] = "int"
#买入委托成交最大等待时间ms
CQdFtdcSellBuyChangeField["BidTradeMaxDuration"] = "int"
#卖出委托成交最大等待时间ms
CQdFtdcSellBuyChangeField["OfferTradeMaxDuration"] = "int"
structDict['CQdFtdcSellBuyChangeField'] = CQdFtdcSellBuyChangeField





