# encoding: UTF-8

structDict = {}

#//////////////////////////////////////////////////////////////////////
#@system 风控前置系统
#@company CFFEX
#@file USTPFtdcUserApiStruct.h
#@brief 定义了客户端接口使用的业务数据结构
#@history 
#//////////////////////////////////////////////////////////////////////










#响应信息
CUstpFtdcRspInfoField = {}
#错误代码
CUstpFtdcRspInfoField["ErrorID"] = "int"
#错误信息
CUstpFtdcRspInfoField["ErrorMsg"] = "string"
structDict['CUstpFtdcRspInfoField'] = CUstpFtdcRspInfoField

#信息分发
CUstpFtdcDisseminationField = {}
#序列系列号
CUstpFtdcDisseminationField["SequenceSeries"] = "int"
#序列号
CUstpFtdcDisseminationField["SequenceNo"] = "int"
structDict['CUstpFtdcDisseminationField'] = CUstpFtdcDisseminationField

#内存表导出
CUstpFtdcReqDumpMemDbField = {}
#内存表名
CUstpFtdcReqDumpMemDbField["MemTableName"] = "string"
structDict['CUstpFtdcReqDumpMemDbField'] = CUstpFtdcReqDumpMemDbField

#登录请求
CUstpFtdcReqUserLoginField = {}
#用户代码
CUstpFtdcReqUserLoginField["UserID"] = "string"
#密码
CUstpFtdcReqUserLoginField["Password"] = "string"
#用户端产品信息
CUstpFtdcReqUserLoginField["UserProductInfo"] = "string"
#IP地址
CUstpFtdcReqUserLoginField["IPAddress"] = "string"
#Mac地址
CUstpFtdcReqUserLoginField["MacAddress"] = "string"
#硬盘序列号
CUstpFtdcReqUserLoginField["DiskSerialNumber"] = "string"
#用户自定义域
CUstpFtdcReqUserLoginField["UserCustom"] = "string"
#接口端产品信息
CUstpFtdcReqUserLoginField["InterfaceProductInfo"] = "string"
#协议信息
CUstpFtdcReqUserLoginField["ProtocolInfo"] = "string"
#交易日
CUstpFtdcReqUserLoginField["TradingDay"] = "string"
#数据中心代码
CUstpFtdcReqUserLoginField["DataCenterID"] = "int"
structDict['CUstpFtdcReqUserLoginField'] = CUstpFtdcReqUserLoginField

#登录应答
CUstpFtdcRspUserLoginField = {}
#交易日
CUstpFtdcRspUserLoginField["TradingDay"] = "string"
#用户代码
CUstpFtdcRspUserLoginField["UserID"] = "string"
#用户类型
CUstpFtdcRspUserLoginField["UserType"] = "char"
#登录成功时间
CUstpFtdcRspUserLoginField["LoginTime"] = "string"
#交易系统名称
CUstpFtdcRspUserLoginField["TradingSystemName"] = "string"
#业务发生日期
CUstpFtdcRspUserLoginField["ActionDay"] = "string"
#数据中心代码
CUstpFtdcRspUserLoginField["DataCenterID"] = "int"
#会员私有流当前长度
CUstpFtdcRspUserLoginField["PrivateFlowSize"] = "int"
#交易员私有流当前长度
CUstpFtdcRspUserLoginField["UserFlowSize"] = "int"
#最大报单本地编号
CUstpFtdcRspUserLoginField["MaxUserOrderLocalID"] = "int"
#每秒最大报单量
CUstpFtdcRspUserLoginField["MaxOrderPerSecond"] = "int"
#最大在途报单量
CUstpFtdcRspUserLoginField["MaxUnFinishedOrder"] = "int"
#每秒最大查询量
CUstpFtdcRspUserLoginField["MaxQueryPerSecond"] = "int"
#最大在途查询量
CUstpFtdcRspUserLoginField["MaxUnFinishedQuery"] = "int"
structDict['CUstpFtdcRspUserLoginField'] = CUstpFtdcRspUserLoginField

#登出请求
CUstpFtdcReqUserLogoutField = {}
#用户代码
CUstpFtdcReqUserLogoutField["UserID"] = "string"
structDict['CUstpFtdcReqUserLogoutField'] = CUstpFtdcReqUserLogoutField

#登出应答
CUstpFtdcRspUserLogoutField = {}
#用户代码
CUstpFtdcRspUserLogoutField["UserID"] = "string"
structDict['CUstpFtdcRspUserLogoutField'] = CUstpFtdcRspUserLogoutField

#修改用户密码请求
CUstpFtdcReqPasswordUpdateField = {}
#旧密码
CUstpFtdcReqPasswordUpdateField["OldPassword"] = "string"
#新密码
CUstpFtdcReqPasswordUpdateField["NewPassword"] = "string"
structDict['CUstpFtdcReqPasswordUpdateField'] = CUstpFtdcReqPasswordUpdateField

#修改用户密码应答
CUstpFtdcRspPasswordUpdateField = {}
#报单用户代码
CUstpFtdcRspPasswordUpdateField["ReqUserID"] = "string"
#旧密码
CUstpFtdcRspPasswordUpdateField["OldPassword"] = "string"
#新密码
CUstpFtdcRspPasswordUpdateField["NewPassword"] = "string"
structDict['CUstpFtdcRspPasswordUpdateField'] = CUstpFtdcRspPasswordUpdateField

#报单请求
CUstpFtdcReqOrderInsertField = {}
#用户自定义域
CUstpFtdcReqOrderInsertField["UserCustom"] = "string"
#投资者编号
CUstpFtdcReqOrderInsertField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqOrderInsertField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqOrderInsertField["StockCode"] = "string"
#委托类型
CUstpFtdcReqOrderInsertField["OrderType"] = "char"
#委托价格类型
CUstpFtdcReqOrderInsertField["PriceType"] = "char"
#子账号序号（主账号为0）
CUstpFtdcReqOrderInsertField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcReqOrderInsertField["UserOrderLocalID"] = "int"
#数量
CUstpFtdcReqOrderInsertField["Volume"] = "int"
#价格
CUstpFtdcReqOrderInsertField["Price"] = "float"
structDict['CUstpFtdcReqOrderInsertField'] = CUstpFtdcReqOrderInsertField

#报单应答
CUstpFtdcRspOrderInsertField = {}
#用户自定义域
CUstpFtdcRspOrderInsertField["UserCustom"] = "string"
#投资者编号
CUstpFtdcRspOrderInsertField["InvestorID"] = "string"
#委托时间
CUstpFtdcRspOrderInsertField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspOrderInsertField["OrderLocalID"] = "string"
#用户报单编号
CUstpFtdcRspOrderInsertField["UserOrderLocalID"] = "int"
structDict['CUstpFtdcRspOrderInsertField'] = CUstpFtdcRspOrderInsertField

#撤单请求
CUstpFtdcReqOrderActionField = {}
#用户自定义域
CUstpFtdcReqOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcReqOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcReqOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcReqOrderActionField["UserOrderActionRef"] = "int"
structDict['CUstpFtdcReqOrderActionField'] = CUstpFtdcReqOrderActionField

#撤单应答
CUstpFtdcRspOrderActionField = {}
#用户自定义域
CUstpFtdcRspOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcRspOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcRspOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcRspOrderActionField["UserOrderActionRef"] = "int"
#委托时间
CUstpFtdcRspOrderActionField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspOrderActionField["OrderLocalID"] = "string"
structDict['CUstpFtdcRspOrderActionField'] = CUstpFtdcRspOrderActionField

#行权请求
CUstpFtdcReqExeOrderInsertField = {}
#用户自定义域
CUstpFtdcReqExeOrderInsertField["UserCustom"] = "string"
#投资者编号
CUstpFtdcReqExeOrderInsertField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqExeOrderInsertField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqExeOrderInsertField["StockCode"] = "string"
#子账号序号（主账号为0）
CUstpFtdcReqExeOrderInsertField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcReqExeOrderInsertField["UserOrderLocalID"] = "int"
#数量
CUstpFtdcReqExeOrderInsertField["Volume"] = "int"
structDict['CUstpFtdcReqExeOrderInsertField'] = CUstpFtdcReqExeOrderInsertField

#行权应答
CUstpFtdcRspExeOrderInsertField = {}
#用户自定义域
CUstpFtdcRspExeOrderInsertField["UserCustom"] = "string"
#投资者编号
CUstpFtdcRspExeOrderInsertField["InvestorID"] = "string"
#委托时间
CUstpFtdcRspExeOrderInsertField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspExeOrderInsertField["OrderLocalID"] = "string"
#用户报单编号
CUstpFtdcRspExeOrderInsertField["UserOrderLocalID"] = "int"
structDict['CUstpFtdcRspExeOrderInsertField'] = CUstpFtdcRspExeOrderInsertField

#行权撤销请求
CUstpFtdcReqExeOrderActionField = {}
#用户自定义域
CUstpFtdcReqExeOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcReqExeOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcReqExeOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcReqExeOrderActionField["UserOrderActionRef"] = "int"
structDict['CUstpFtdcReqExeOrderActionField'] = CUstpFtdcReqExeOrderActionField

#行权撤销应答
CUstpFtdcRspExeOrderActionField = {}
#用户自定义域
CUstpFtdcRspExeOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcRspExeOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcRspExeOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcRspExeOrderActionField["UserOrderActionRef"] = "int"
#委托时间
CUstpFtdcRspExeOrderActionField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspExeOrderActionField["OrderLocalID"] = "string"
structDict['CUstpFtdcRspExeOrderActionField'] = CUstpFtdcRspExeOrderActionField

#备兑请求
CUstpFtdcReqCoverInsertField = {}
#委托类型
CUstpFtdcReqCoverInsertField["OrderType"] = "char"
#用户自定义域
CUstpFtdcReqCoverInsertField["UserCustom"] = "string"
#投资者编号
CUstpFtdcReqCoverInsertField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqCoverInsertField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqCoverInsertField["StockCode"] = "string"
#子账号序号（主账号为0）
CUstpFtdcReqCoverInsertField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcReqCoverInsertField["UserOrderLocalID"] = "int"
#数量
CUstpFtdcReqCoverInsertField["Volume"] = "int"
structDict['CUstpFtdcReqCoverInsertField'] = CUstpFtdcReqCoverInsertField

#备兑应答
CUstpFtdcRspCoverInsertField = {}
#用户自定义域
CUstpFtdcRspCoverInsertField["UserCustom"] = "string"
#投资者编号
CUstpFtdcRspCoverInsertField["InvestorID"] = "string"
#委托时间
CUstpFtdcRspCoverInsertField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspCoverInsertField["OrderLocalID"] = "string"
#用户报单编号
CUstpFtdcRspCoverInsertField["UserOrderLocalID"] = "int"
structDict['CUstpFtdcRspCoverInsertField'] = CUstpFtdcRspCoverInsertField

#报价请求
CUstpFtdcReqQuoteField = {}
#用户自定义域
CUstpFtdcReqQuoteField["UserCustom"] = "string"
#投资者编号
CUstpFtdcReqQuoteField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQuoteField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqQuoteField["StockCode"] = "string"
#此报价回应的询价请求ID
CUstpFtdcReqQuoteField["ReplyInquiryReqID"] = "string"
#买委托类型
CUstpFtdcReqQuoteField["BidOrderType"] = "char"
#卖委托类型
CUstpFtdcReqQuoteField["OfferOrderType"] = "char"
#子账号序号（主账号为0）
CUstpFtdcReqQuoteField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcReqQuoteField["UserOrderLocalID"] = "int"
#买数量
CUstpFtdcReqQuoteField["BidVolume"] = "int"
#卖数量
CUstpFtdcReqQuoteField["OfferVolume"] = "int"
#买价格
CUstpFtdcReqQuoteField["BidPrice"] = "float"
#卖价格
CUstpFtdcReqQuoteField["OfferPrice"] = "float"
structDict['CUstpFtdcReqQuoteField'] = CUstpFtdcReqQuoteField

#报价应答
CUstpFtdcRspQuoteField = {}
#用户自定义域
CUstpFtdcRspQuoteField["UserCustom"] = "string"
#投资者编号
CUstpFtdcRspQuoteField["InvestorID"] = "string"
#委托时间
CUstpFtdcRspQuoteField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspQuoteField["OrderLocalID"] = "string"
#用户报单编号
CUstpFtdcRspQuoteField["UserOrderLocalID"] = "int"
structDict['CUstpFtdcRspQuoteField'] = CUstpFtdcRspQuoteField

#询价请求
CUstpFtdcReqInquiryField = {}
#用户自定义域
CUstpFtdcReqInquiryField["UserCustom"] = "string"
#投资者编号
CUstpFtdcReqInquiryField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqInquiryField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqInquiryField["StockCode"] = "string"
#子账号序号（主账号为0）
CUstpFtdcReqInquiryField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcReqInquiryField["UserOrderLocalID"] = "int"
structDict['CUstpFtdcReqInquiryField'] = CUstpFtdcReqInquiryField

#询价应答
CUstpFtdcRspInquiryField = {}
#用户自定义域
CUstpFtdcRspInquiryField["UserCustom"] = "string"
#投资者编号
CUstpFtdcRspInquiryField["InvestorID"] = "string"
#委托时间
CUstpFtdcRspInquiryField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspInquiryField["OrderLocalID"] = "string"
#用户报单编号
CUstpFtdcRspInquiryField["UserOrderLocalID"] = "int"
structDict['CUstpFtdcRspInquiryField'] = CUstpFtdcRspInquiryField

#报单回报
CUstpFtdcOrderField = {}
#用户自定义域
CUstpFtdcOrderField["UserCustom"] = "string"
#投资者编号
CUstpFtdcOrderField["InvestorID"] = "string"
#交易所代码
CUstpFtdcOrderField["ExchangeID"] = "char"
#合约编码
CUstpFtdcOrderField["StockCode"] = "string"
#委托类型
CUstpFtdcOrderField["OrderType"] = "char"
#委托价格类型
CUstpFtdcOrderField["PriceType"] = "char"
#子账号序号（主账号为0）
CUstpFtdcOrderField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcOrderField["UserOrderLocalID"] = "int"
#数量
CUstpFtdcOrderField["Volume"] = "int"
#价格
CUstpFtdcOrderField["Price"] = "float"
#报单用户代码
CUstpFtdcOrderField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcOrderField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcOrderField["OrderSource"] = "char"
#报单状态
CUstpFtdcOrderField["OrderStatus"] = "char"
#委托时间
CUstpFtdcOrderField["InsertTime"] = "string"
#撤销时间
CUstpFtdcOrderField["CancelTime"] = "string"
#最后更新时间
CUstpFtdcOrderField["UpdateTime"] = "string"
#撤单数量
CUstpFtdcOrderField["CancelVolume"] = "int"
#剩余数量
CUstpFtdcOrderField["VolumeRemain"] = "int"
#成交数量
CUstpFtdcOrderField["VolumeTraded"] = "int"
#冻结金额
CUstpFtdcOrderField["FrozenAmnt"] = "float"
#冻结权利金
CUstpFtdcOrderField["FrozenPremium"] = "float"
#冻结手续费
CUstpFtdcOrderField["FrozenFee"] = "float"
#冻结保证金
CUstpFtdcOrderField["FrozenMargin"] = "float"
structDict['CUstpFtdcOrderField'] = CUstpFtdcOrderField

#成交回报
CUstpFtdcTradeField = {}
#交易所代码
CUstpFtdcTradeField["ExchangeID"] = "char"
#下单席位号
CUstpFtdcTradeField["SeatID"] = "string"
#投资者编号
CUstpFtdcTradeField["InvestorID"] = "string"
#报单用户代码
CUstpFtdcTradeField["ReqUserID"] = "string"
#报单来源
CUstpFtdcTradeField["OrderSource"] = "char"
#用户报单编号
CUstpFtdcTradeField["UserOrderLocalID"] = "int"
#成交数量
CUstpFtdcTradeField["TradeVolume"] = "int"
#成交价格
CUstpFtdcTradeField["TradePrice"] = "float"
#成交金额
CUstpFtdcTradeField["TradeAmnt"] = "float"
#系统报单编号
CUstpFtdcTradeField["OrderLocalID"] = "string"
#成交编号
CUstpFtdcTradeField["TradeID"] = "string"
#合约编码
CUstpFtdcTradeField["StockCode"] = "string"
#委托类型
CUstpFtdcTradeField["OrderType"] = "char"
#成交时间
CUstpFtdcTradeField["TradeTime"] = "string"
#成交类型
CUstpFtdcTradeField["TradeType"] = "char"
#成交流水号
CUstpFtdcTradeField["SequenceNo"] = "int"
#佣金
CUstpFtdcTradeField["Commision"] = "float"
#印花税
CUstpFtdcTradeField["StampTax"] = "float"
#过户费
CUstpFtdcTradeField["TransferFee"] = "float"
#经手费
CUstpFtdcTradeField["BrokerageFee"] = "float"
#证管费
CUstpFtdcTradeField["SecAdminFee"] = "float"
#结算费
CUstpFtdcTradeField["SettlementFee"] = "float"
#权利金
CUstpFtdcTradeField["Premium"] = "float"
#保证金
CUstpFtdcTradeField["Margin"] = "float"
structDict['CUstpFtdcTradeField'] = CUstpFtdcTradeField

#撤单回报
CUstpFtdcOrderActionField = {}
#用户自定义域
CUstpFtdcOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcOrderActionField["UserOrderActionRef"] = "int"
#报单用户代码
CUstpFtdcOrderActionField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcOrderActionField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcOrderActionField["OrderSource"] = "char"
#报单状态
CUstpFtdcOrderActionField["OrderStatus"] = "char"
#撤销时间
CUstpFtdcOrderActionField["CancelTime"] = "string"
#撤单数量
CUstpFtdcOrderActionField["CancelVolume"] = "int"
structDict['CUstpFtdcOrderActionField'] = CUstpFtdcOrderActionField

#行权回报
CUstpFtdcExeOrderField = {}
#用户自定义域
CUstpFtdcExeOrderField["UserCustom"] = "string"
#投资者编号
CUstpFtdcExeOrderField["InvestorID"] = "string"
#交易所代码
CUstpFtdcExeOrderField["ExchangeID"] = "char"
#合约编码
CUstpFtdcExeOrderField["StockCode"] = "string"
#子账号序号（主账号为0）
CUstpFtdcExeOrderField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcExeOrderField["UserOrderLocalID"] = "int"
#数量
CUstpFtdcExeOrderField["Volume"] = "int"
#报单用户代码
CUstpFtdcExeOrderField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcExeOrderField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcExeOrderField["OrderSource"] = "char"
#报单状态
CUstpFtdcExeOrderField["OrderStatus"] = "char"
#最后更新时间
CUstpFtdcExeOrderField["UpdateTime"] = "string"
structDict['CUstpFtdcExeOrderField'] = CUstpFtdcExeOrderField

#行权撤销回报
CUstpFtdcExeOrderActionField = {}
#用户自定义域
CUstpFtdcExeOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcExeOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcExeOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcExeOrderActionField["UserOrderActionRef"] = "int"
#报单用户代码
CUstpFtdcExeOrderActionField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcExeOrderActionField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcExeOrderActionField["OrderSource"] = "char"
#报单状态
CUstpFtdcExeOrderActionField["OrderStatus"] = "char"
#撤销时间
CUstpFtdcExeOrderActionField["CancelTime"] = "string"
#撤单数量
CUstpFtdcExeOrderActionField["CancelVolume"] = "int"
structDict['CUstpFtdcExeOrderActionField'] = CUstpFtdcExeOrderActionField

#备兑回报
CUstpFtdcCoverField = {}
#委托类型
CUstpFtdcCoverField["OrderType"] = "char"
#用户自定义域
CUstpFtdcCoverField["UserCustom"] = "string"
#投资者编号
CUstpFtdcCoverField["InvestorID"] = "string"
#交易所代码
CUstpFtdcCoverField["ExchangeID"] = "char"
#合约编码
CUstpFtdcCoverField["StockCode"] = "string"
#子账号序号（主账号为0）
CUstpFtdcCoverField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcCoverField["UserOrderLocalID"] = "int"
#数量
CUstpFtdcCoverField["Volume"] = "int"
#报单用户代码
CUstpFtdcCoverField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcCoverField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcCoverField["OrderSource"] = "char"
#报单状态
CUstpFtdcCoverField["OrderStatus"] = "char"
#最后更新时间
CUstpFtdcCoverField["UpdateTime"] = "string"
structDict['CUstpFtdcCoverField'] = CUstpFtdcCoverField

#报价回报
CUstpFtdcQuoteField = {}
#用户自定义域
CUstpFtdcQuoteField["UserCustom"] = "string"
#投资者编号
CUstpFtdcQuoteField["InvestorID"] = "string"
#交易所代码
CUstpFtdcQuoteField["ExchangeID"] = "char"
#合约编码
CUstpFtdcQuoteField["StockCode"] = "string"
#此报价回应的询价请求ID
CUstpFtdcQuoteField["ReplyInquiryReqID"] = "string"
#买委托类型
CUstpFtdcQuoteField["BidOrderType"] = "char"
#卖委托类型
CUstpFtdcQuoteField["OfferOrderType"] = "char"
#子账号序号（主账号为0）
CUstpFtdcQuoteField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcQuoteField["UserOrderLocalID"] = "int"
#买数量
CUstpFtdcQuoteField["BidVolume"] = "int"
#卖数量
CUstpFtdcQuoteField["OfferVolume"] = "int"
#买价格
CUstpFtdcQuoteField["BidPrice"] = "float"
#卖价格
CUstpFtdcQuoteField["OfferPrice"] = "float"
#报单用户代码
CUstpFtdcQuoteField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcQuoteField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcQuoteField["OrderSource"] = "char"
#报单状态
CUstpFtdcQuoteField["OrderStatus"] = "char"
#买报单状态
CUstpFtdcQuoteField["BidOrderStatus"] = "char"
#卖报单状态
CUstpFtdcQuoteField["OfferOrderStatus"] = "char"
#最后更新时间
CUstpFtdcQuoteField["UpdateTime"] = "string"
structDict['CUstpFtdcQuoteField'] = CUstpFtdcQuoteField

#询价回报
CUstpFtdcInquiryField = {}
#用户自定义域
CUstpFtdcInquiryField["UserCustom"] = "string"
#投资者编号
CUstpFtdcInquiryField["InvestorID"] = "string"
#交易所代码
CUstpFtdcInquiryField["ExchangeID"] = "char"
#合约编码
CUstpFtdcInquiryField["StockCode"] = "string"
#子账号序号（主账号为0）
CUstpFtdcInquiryField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcInquiryField["UserOrderLocalID"] = "int"
#报单用户代码
CUstpFtdcInquiryField["ReqUserID"] = "string"
#请求席位号
CUstpFtdcInquiryField["ReqSeatID"] = "string"
#询价请求ID
CUstpFtdcInquiryField["ReqID"] = "string"
#系统报单编号
CUstpFtdcInquiryField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcInquiryField["OrderSource"] = "char"
#报单状态
CUstpFtdcInquiryField["OrderStatus"] = "char"
#最后更新时间
CUstpFtdcInquiryField["UpdateTime"] = "string"
structDict['CUstpFtdcInquiryField'] = CUstpFtdcInquiryField

#出入金明细回报
CUstpFtdcInvestorAccountAdjustmentField = {}
#交易日
CUstpFtdcInvestorAccountAdjustmentField["TradingDay"] = "string"
#出入金流水号
CUstpFtdcInvestorAccountAdjustmentField["SeqNo"] = "string"
#投资者编号
CUstpFtdcInvestorAccountAdjustmentField["InvestorID"] = "string"
#资金帐号
CUstpFtdcInvestorAccountAdjustmentField["AccountID"] = "string"
#子账户序号
CUstpFtdcInvestorAccountAdjustmentField["SubAcctNo"] = "int"
#金额
CUstpFtdcInvestorAccountAdjustmentField["AdjustAmount"] = "float"
#出入金方向
CUstpFtdcInvestorAccountAdjustmentField["AdjustDirection"] = "char"
#修改用户编号
CUstpFtdcInvestorAccountAdjustmentField["SetUserID"] = "string"
#操作日期
CUstpFtdcInvestorAccountAdjustmentField["CommandDate"] = "string"
#操作时间
CUstpFtdcInvestorAccountAdjustmentField["CommandTime"] = "string"
#可用资金
CUstpFtdcInvestorAccountAdjustmentField["Available"] = "float"
structDict['CUstpFtdcInvestorAccountAdjustmentField'] = CUstpFtdcInvestorAccountAdjustmentField

#期权品种查询请求
CUstpFtdcReqQryProductField = {}
#交易所代码
CUstpFtdcReqQryProductField["ExchangeID"] = "char"
#一级分类
CUstpFtdcReqQryProductField["ProductClass1"] = "char"
#二级分类
CUstpFtdcReqQryProductField["ProductClass2"] = "char"
structDict['CUstpFtdcReqQryProductField'] = CUstpFtdcReqQryProductField

#期权品种查询应答
CUstpFtdcProductField = {}
#交易所代码
CUstpFtdcProductField["ExchangeID"] = "char"
#一级分类
CUstpFtdcProductField["ProductClass1"] = "char"
#二级分类
CUstpFtdcProductField["ProductClass2"] = "char"
#品种代码
CUstpFtdcProductField["ProductID"] = "string"
#品种名称
CUstpFtdcProductField["ProductName"] = "string"
#币种
CUstpFtdcProductField["Currency"] = "char"
#标的证券代码
CUstpFtdcProductField["UnderlyStockCode"] = "string"
#标的证券名称
CUstpFtdcProductField["UnderlyStockName"] = "string"
#合约乘数
CUstpFtdcProductField["Multiplier"] = "int"
#最小变动价位
CUstpFtdcProductField["PriceTick"] = "float"
#行权方式
CUstpFtdcProductField["ExerciseType"] = "char"
#交割方式
CUstpFtdcProductField["DeliveryType"] = "char"
structDict['CUstpFtdcProductField'] = CUstpFtdcProductField

#期权合约查询请求
CUstpFtdcReqQryStockField = {}
#交易所代码
CUstpFtdcReqQryStockField["ExchangeID"] = "char"
#一级分类
CUstpFtdcReqQryStockField["ProductClass1"] = "char"
#二级分类
CUstpFtdcReqQryStockField["ProductClass2"] = "char"
#品种代码
CUstpFtdcReqQryStockField["ProductID"] = "string"
#合约编码
CUstpFtdcReqQryStockField["StockCode"] = "string"
structDict['CUstpFtdcReqQryStockField'] = CUstpFtdcReqQryStockField

#期权合约查询应答
CUstpFtdcStockField = {}
#交易所代码
CUstpFtdcStockField["ExchangeID"] = "char"
#一级分类
CUstpFtdcStockField["ProductClass1"] = "char"
#二级分类
CUstpFtdcStockField["ProductClass2"] = "char"
#品种代码
CUstpFtdcStockField["ProductID"] = "string"
#合约编码
CUstpFtdcStockField["StockCode"] = "string"
#证券名称/期权名称
CUstpFtdcStockField["StockName"] = "string"
#合约交易代码（如601398C1309M00380）
CUstpFtdcStockField["TradeStockCode"] = "string"
#标的合约编码
CUstpFtdcStockField["UnderlyStockCode"] = "string"
#期权类型
CUstpFtdcStockField["OptionType"] = "char"
#合约乘数
CUstpFtdcStockField["Multiplier"] = "int"
#跌停板价
CUstpFtdcStockField["LowerLimitPrice"] = "float"
#涨停板价
CUstpFtdcStockField["UpperLimitPrice"] = "float"
#单位保证金
CUstpFtdcStockField["MarginUnit"] = "float"
#股票状态
CUstpFtdcStockField["StockStatus"] = "char"
#允许的委托类型集合
CUstpFtdcStockField["AllowOrderTypes"] = "string"
#标的交易所代码
CUstpFtdcStockField["UnderlyExchangeID"] = "char"
#标的证券名称
CUstpFtdcStockField["UnderlyStockName"] = "string"
#最小变动价位
CUstpFtdcStockField["PriceTick"] = "float"
#行权方式
CUstpFtdcStockField["ExerciseType"] = "char"
#交割方式
CUstpFtdcStockField["DeliveryType"] = "char"
#期权行权价
CUstpFtdcStockField["ExercisePrice"] = "float"
#期权行权日
CUstpFtdcStockField["ExerciseDate"] = "string"
#行权交割日
CUstpFtdcStockField["DeliveryDate"] = "string"
#当前合约未平仓数
CUstpFtdcStockField["TotalLongPosition"] = "int"
#昨结算价，如遇除权除息则为调整后的结算价
CUstpFtdcStockField["PreSettlementPrice"] = "float"
#标的证券前收盘,期权标的证券除权除息调整后的前收盘价格
CUstpFtdcStockField["UnderlyPreClosePrice"] = "float"
#保证金计算比例参数一
CUstpFtdcStockField["MarginRatioParam1"] = "float"
#保证金计算比例参数二
CUstpFtdcStockField["MarginRatioParam2"] = "float"
#买数量单位
CUstpFtdcStockField["BuyUnit"] = "int"
#卖数量单位
CUstpFtdcStockField["SellUnit"] = "int"
#新挂牌的合约标识
CUstpFtdcStockField["NewContrIndc"] = "char"
#近5个交易日内合约发生过调整标识
CUstpFtdcStockField["ContrAdjIndc"] = "char"
#涨跌幅限制类型
CUstpFtdcStockField["LimitPriceType"] = "char"
#前收盘价
CUstpFtdcStockField["PreClosePrice"] = "float"
#限价单最大下单量
CUstpFtdcStockField["MaxLimitOrderVolume"] = "int"
#限价单最小下单量
CUstpFtdcStockField["MinLimitOrderVolume"] = "int"
#市价单最大下单量
CUstpFtdcStockField["MaxMarketOrderVolume"] = "int"
#市价单最小下单量
CUstpFtdcStockField["MinMarketOrderVolume"] = "int"
#币种
CUstpFtdcStockField["Currency"] = "char"
#上市日
CUstpFtdcStockField["OpenDate"] = "string"
#最后交易日期
CUstpFtdcStockField["ExpireDate"] = "string"
#更新时间
CUstpFtdcStockField["UpdateTime"] = "string"
structDict['CUstpFtdcStockField'] = CUstpFtdcStockField

#报单查询请求
CUstpFtdcReqQryOrderField = {}
#投资者编号
CUstpFtdcReqQryOrderField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryOrderField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqQryOrderField["StockCode"] = "string"
#系统报单编号
CUstpFtdcReqQryOrderField["OrderLocalID"] = "string"
#委托查询方式
CUstpFtdcReqQryOrderField["OrderQryType"] = "char"
structDict['CUstpFtdcReqQryOrderField'] = CUstpFtdcReqQryOrderField

#成交查询请求
CUstpFtdcReqQryTradeField = {}
#投资者编号
CUstpFtdcReqQryTradeField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryTradeField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqQryTradeField["StockCode"] = "string"
#成交编号
CUstpFtdcReqQryTradeField["TradeID"] = "string"
structDict['CUstpFtdcReqQryTradeField'] = CUstpFtdcReqQryTradeField

#行权查询请求
CUstpFtdcReqQryExeOrderField = {}
#投资者编号
CUstpFtdcReqQryExeOrderField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryExeOrderField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqQryExeOrderField["StockCode"] = "string"
#系统报单编号
CUstpFtdcReqQryExeOrderField["OrderLocalID"] = "string"
structDict['CUstpFtdcReqQryExeOrderField'] = CUstpFtdcReqQryExeOrderField

#备兑查询请求
CUstpFtdcReqQryCoverField = {}
#投资者编号
CUstpFtdcReqQryCoverField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryCoverField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqQryCoverField["StockCode"] = "string"
#系统报单编号
CUstpFtdcReqQryCoverField["OrderLocalID"] = "string"
structDict['CUstpFtdcReqQryCoverField'] = CUstpFtdcReqQryCoverField

#报价查询请求
CUstpFtdcReqQryQuoteField = {}
#投资者编号
CUstpFtdcReqQryQuoteField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryQuoteField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqQryQuoteField["StockCode"] = "string"
#系统报单编号
CUstpFtdcReqQryQuoteField["OrderLocalID"] = "string"
structDict['CUstpFtdcReqQryQuoteField'] = CUstpFtdcReqQryQuoteField

#询价查询请求
CUstpFtdcReqQryInquiryField = {}
#投资者编号
CUstpFtdcReqQryInquiryField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryInquiryField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqQryInquiryField["StockCode"] = "string"
#系统报单编号
CUstpFtdcReqQryInquiryField["OrderLocalID"] = "string"
structDict['CUstpFtdcReqQryInquiryField'] = CUstpFtdcReqQryInquiryField

#合并行权查询请求
CUstpFtdcReqQryCombExeOrderField = {}
#投资者编号
CUstpFtdcReqQryCombExeOrderField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryCombExeOrderField["ExchangeID"] = "char"
#看涨合约编码
CUstpFtdcReqQryCombExeOrderField["CallStockCode"] = "string"
#看跌合约编码
CUstpFtdcReqQryCombExeOrderField["PutStockCode"] = "string"
#系统报单编号
CUstpFtdcReqQryCombExeOrderField["OrderLocalID"] = "string"
structDict['CUstpFtdcReqQryCombExeOrderField'] = CUstpFtdcReqQryCombExeOrderField

#投资者账户查询请求
CUstpFtdcReqQryUserInvestorField = {}
#用户代码
CUstpFtdcReqQryUserInvestorField["UserID"] = "string"
structDict['CUstpFtdcReqQryUserInvestorField'] = CUstpFtdcReqQryUserInvestorField

#投资者账户查询应答
CUstpFtdcUserInvestorField = {}
#用户代码
CUstpFtdcUserInvestorField["UserID"] = "string"
#投资者编号
CUstpFtdcUserInvestorField["InvestorID"] = "string"
#子账号序号（主账号为0）
CUstpFtdcUserInvestorField["SubAcctNo"] = "int"
structDict['CUstpFtdcUserInvestorField'] = CUstpFtdcUserInvestorField

#投资者资金查询请求
CUstpFtdcReqQryInvestorAccountField = {}
#投资者编号
CUstpFtdcReqQryInvestorAccountField["InvestorID"] = "string"
#资金帐户类别
CUstpFtdcReqQryInvestorAccountField["AccountType"] = "char"
structDict['CUstpFtdcReqQryInvestorAccountField'] = CUstpFtdcReqQryInvestorAccountField

#投资者资金查询应答
CUstpFtdcInvestorAccountField = {}
#投资者编号
CUstpFtdcInvestorAccountField["InvestorID"] = "string"
#资金帐户类别
CUstpFtdcInvestorAccountField["AccountType"] = "char"
#资金帐号
CUstpFtdcInvestorAccountField["AccountID"] = "string"
#子账号序号（主账号为0）
CUstpFtdcInvestorAccountField["SubAcctNo"] = "int"
#账号资金状态
CUstpFtdcInvestorAccountField["AcctStatus"] = "char"
#上一交易日资金总额
CUstpFtdcInvestorAccountField["YdBalance"] = "float"
#可用余额
CUstpFtdcInvestorAccountField["Available"] = "float"
#上一交易日保证金占用
CUstpFtdcInvestorAccountField["YdMarginOccupation"] = "float"
#保证金占用
CUstpFtdcInvestorAccountField["MarginOccupation"] = "float"
#费用冻结
CUstpFtdcInvestorAccountField["FrozenFees"] = "float"
#保证金冻结
CUstpFtdcInvestorAccountField["FrozenMargin"] = "float"
#组合保证金占用
CUstpFtdcInvestorAccountField["CombMarginOccupation"] = "float"
#组合交易所保证金占用
CUstpFtdcInvestorAccountField["CombExMarginOccupation"] = "float"
#权利金冻结
CUstpFtdcInvestorAccountField["FrozenPremium"] = "float"
#权利金收入
CUstpFtdcInvestorAccountField["PremiumIn"] = "float"
#权利金支出
CUstpFtdcInvestorAccountField["PremiumOut"] = "float"
#入金
CUstpFtdcInvestorAccountField["Deposit"] = "float"
#出金
CUstpFtdcInvestorAccountField["Withdraw"] = "float"
#费用支出
CUstpFtdcInvestorAccountField["Fees"] = "float"
#平仓盈亏
CUstpFtdcInvestorAccountField["CloseProfit"] = "float"
#持仓浮盈
CUstpFtdcInvestorAccountField["FloatingProfit"] = "float"
#昨日市值权益
CUstpFtdcInvestorAccountField["YdMarketValue"] = "float"
#市值权益
CUstpFtdcInvestorAccountField["MarketValue"] = "float"
#可取资金
CUstpFtdcInvestorAccountField["CanWithdraw"] = "float"
#其他冻结资金
CUstpFtdcInvestorAccountField["OtherFrozen"] = "float"
#当日释放保证金
CUstpFtdcInvestorAccountField["ReleaseMargin"] = "float"
#总冻结金额
CUstpFtdcInvestorAccountField["TotalFrozenAmnt"] = "float"
#应计利息
CUstpFtdcInvestorAccountField["AccruedInterest"] = "float"
#保证金风险度标签
CUstpFtdcInvestorAccountField["MarginRiskFlag"] = "char"
structDict['CUstpFtdcInvestorAccountField'] = CUstpFtdcInvestorAccountField

#投资者持仓查询请求
CUstpFtdcReqQryInvestorPositionField = {}
#交易所代码
CUstpFtdcReqQryInvestorPositionField["ExchangeID"] = "char"
#投资者编号
CUstpFtdcReqQryInvestorPositionField["InvestorID"] = "string"
#合约编码
CUstpFtdcReqQryInvestorPositionField["StockCode"] = "string"
structDict['CUstpFtdcReqQryInvestorPositionField'] = CUstpFtdcReqQryInvestorPositionField

#投资者持仓查询应答
CUstpFtdcInvestorPositionField = {}
#交易所代码
CUstpFtdcInvestorPositionField["ExchangeID"] = "char"
#投资者编号
CUstpFtdcInvestorPositionField["InvestorID"] = "string"
#合约编码
CUstpFtdcInvestorPositionField["StockCode"] = "string"
#股东代码
CUstpFtdcInvestorPositionField["ClientID"] = "string"
#子账号序号（主账号为0）
CUstpFtdcInvestorPositionField["SubAcctNo"] = "int"
#持仓方向
CUstpFtdcInvestorPositionField["PositionDirection"] = "char"
#是否备兑
CUstpFtdcInvestorPositionField["IsCovered"] = "char"
#期权类型
CUstpFtdcInvestorPositionField["OptionsType"] = "char"
#上一交易日持仓
CUstpFtdcInvestorPositionField["YdPosition"] = "int"
#今开仓
CUstpFtdcInvestorPositionField["OpenPosition"] = "int"
#总持仓
CUstpFtdcInvestorPositionField["TotalPosition"] = "int"
#可用持仓
CUstpFtdcInvestorPositionField["AvailPosition"] = "int"
#冻结持仓
CUstpFtdcInvestorPositionField["FrozenPosition"] = "int"
#行权占用
CUstpFtdcInvestorPositionField["ExerciseOccupation"] = "int"
#组合持仓占用量
CUstpFtdcInvestorPositionField["PortfolioPositionOccupation"] = "int"
#持仓保证金占用
CUstpFtdcInvestorPositionField["MarginOccupation"] = "float"
#上一交易日累计开仓量
CUstpFtdcInvestorPositionField["YdCumulativeOpenPosition"] = "int"
#上一交易日累计平仓量
CUstpFtdcInvestorPositionField["YdCumulativeClosePosition"] = "int"
#累计开仓量
CUstpFtdcInvestorPositionField["CumulativeOpenPosition"] = "int"
#累计平仓量
CUstpFtdcInvestorPositionField["CumulativeClosePosition"] = "int"
#上一交易日累计开仓成本
CUstpFtdcInvestorPositionField["YdCumulativeOpenCost"] = "float"
#上一交易日累计平仓成本
CUstpFtdcInvestorPositionField["YdCumulativeCloseCost"] = "float"
#累计开仓成本
CUstpFtdcInvestorPositionField["CumulativeOpenCost"] = "float"
#累计平仓成本
CUstpFtdcInvestorPositionField["CumulativeCloseCost"] = "float"
#开仓均价
CUstpFtdcInvestorPositionField["OpenAverage"] = "float"
#持仓均价
CUstpFtdcInvestorPositionField["HoldAverage"] = "float"
#其他冻结
CUstpFtdcInvestorPositionField["OtherFrozen"] = "int"
#红冲蓝补
CUstpFtdcInvestorPositionField["RedAndBlue"] = "int"
structDict['CUstpFtdcInvestorPositionField'] = CUstpFtdcInvestorPositionField

#手续费率查询请求
CUstpFtdcReqQryInvestorFeeField = {}
#投资者编号
CUstpFtdcReqQryInvestorFeeField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryInvestorFeeField["ExchangeID"] = "char"
#品种代码
CUstpFtdcReqQryInvestorFeeField["ProductID"] = "string"
#合约编码
CUstpFtdcReqQryInvestorFeeField["StockCode"] = "string"
structDict['CUstpFtdcReqQryInvestorFeeField'] = CUstpFtdcReqQryInvestorFeeField

#手续费率查询应答
CUstpFtdcInvestorFeeField = {}
#投资者编号
CUstpFtdcInvestorFeeField["InvestorID"] = "string"
#手续费率模板号
CUstpFtdcInvestorFeeField["FeeTemplateNo"] = "string"
#交易所代码
CUstpFtdcInvestorFeeField["ExchangeID"] = "char"
#品种代码
CUstpFtdcInvestorFeeField["ProductID"] = "string"
#合约编码
CUstpFtdcInvestorFeeField["StockCode"] = "string"
#委托类型
CUstpFtdcInvestorFeeField["OrderType"] = "char"
#费用种类
CUstpFtdcInvestorFeeField["FeeType"] = "char"
#收费方式
CUstpFtdcInvestorFeeField["ChargingMethod"] = "char"
#单位费用
CUstpFtdcInvestorFeeField["UnitFee"] = "float"
#最高费用
CUstpFtdcInvestorFeeField["MaxFee"] = "float"
#最低费用
CUstpFtdcInvestorFeeField["MinFee"] = "float"
structDict['CUstpFtdcInvestorFeeField'] = CUstpFtdcInvestorFeeField

#保证金率查询请求
CUstpFtdcReqQryInvestorMarginField = {}
#投资者编号
CUstpFtdcReqQryInvestorMarginField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryInvestorMarginField["ExchangeID"] = "char"
#品种代码
CUstpFtdcReqQryInvestorMarginField["ProductID"] = "string"
#合约编码
CUstpFtdcReqQryInvestorMarginField["StockCode"] = "string"
structDict['CUstpFtdcReqQryInvestorMarginField'] = CUstpFtdcReqQryInvestorMarginField

#保证金率查询应答
CUstpFtdcInvestorMarginField = {}
#投资者编号
CUstpFtdcInvestorMarginField["InvestorID"] = "string"
#交易所代码
CUstpFtdcInvestorMarginField["ExchangeID"] = "char"
#品种代码
CUstpFtdcInvestorMarginField["ProductID"] = "string"
#合约编码
CUstpFtdcInvestorMarginField["StockCode"] = "string"
#保证金调整比例
CUstpFtdcInvestorMarginField["MarginAdjustRate"] = "float"
structDict['CUstpFtdcInvestorMarginField'] = CUstpFtdcInvestorMarginField

#限仓额度查询请求
CUstpFtdcReqQryPositionLimitField = {}
#投资者编号
CUstpFtdcReqQryPositionLimitField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryPositionLimitField["ExchangeID"] = "char"
#品种代码
CUstpFtdcReqQryPositionLimitField["ProductID"] = "string"
structDict['CUstpFtdcReqQryPositionLimitField'] = CUstpFtdcReqQryPositionLimitField

#限仓额度查询应答
CUstpFtdcPositionLimitField = {}
#投资者编号
CUstpFtdcPositionLimitField["InvestorID"] = "string"
#交易所代码
CUstpFtdcPositionLimitField["ExchangeID"] = "char"
#品种代码
CUstpFtdcPositionLimitField["ProductID"] = "string"
#限仓类型
CUstpFtdcPositionLimitField["LimitType"] = "char"
#总额度
CUstpFtdcPositionLimitField["Total"] = "int"
#可用额度
CUstpFtdcPositionLimitField["Avail"] = "int"
#冻结额度
CUstpFtdcPositionLimitField["Frozen"] = "int"
#已用额度
CUstpFtdcPositionLimitField["Used"] = "int"
structDict['CUstpFtdcPositionLimitField'] = CUstpFtdcPositionLimitField

#限购额度查询请求
CUstpFtdcReqQryBuyLimitField = {}
#投资者编号
CUstpFtdcReqQryBuyLimitField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryBuyLimitField["ExchangeID"] = "char"
#品种代码
CUstpFtdcReqQryBuyLimitField["ProductID"] = "string"
structDict['CUstpFtdcReqQryBuyLimitField'] = CUstpFtdcReqQryBuyLimitField

#限购额度查询应答
CUstpFtdcBuyLimitField = {}
#投资者编号
CUstpFtdcBuyLimitField["InvestorID"] = "string"
#交易所代码
CUstpFtdcBuyLimitField["ExchangeID"] = "char"
#品种代码
CUstpFtdcBuyLimitField["ProductID"] = "string"
#限购类型
CUstpFtdcBuyLimitField["LimitType"] = "char"
#总额度
CUstpFtdcBuyLimitField["Total"] = "float"
#可用额度
CUstpFtdcBuyLimitField["Avail"] = "float"
#冻结额度
CUstpFtdcBuyLimitField["Frozen"] = "float"
#已用额度
CUstpFtdcBuyLimitField["Used"] = "float"
structDict['CUstpFtdcBuyLimitField'] = CUstpFtdcBuyLimitField

#备兑情况查询请求
CUstpFtdcReqQryCoverInfoField = {}
#投资者编号
CUstpFtdcReqQryCoverInfoField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryCoverInfoField["ExchangeID"] = "char"
#合约编码
CUstpFtdcReqQryCoverInfoField["StockCode"] = "string"
structDict['CUstpFtdcReqQryCoverInfoField'] = CUstpFtdcReqQryCoverInfoField

#备兑情况查询应答
CUstpFtdcCoverInfoField = {}
#投资者编号
CUstpFtdcCoverInfoField["InvestorID"] = "string"
#交易所代码
CUstpFtdcCoverInfoField["ExchangeID"] = "char"
#合约编码
CUstpFtdcCoverInfoField["StockCode"] = "string"
#标的可用量
CUstpFtdcCoverInfoField["UnderlyAvailVolume"] = "int"
#标的冻结量
CUstpFtdcCoverInfoField["UnderlyFrozenVolume"] = "int"
#初始额度
CUstpFtdcCoverInfoField["AvailVolume"] = "int"
#冻结额度
CUstpFtdcCoverInfoField["FrozenVolume"] = "int"
#已用额度
CUstpFtdcCoverInfoField["UsedVolume"] = "int"
structDict['CUstpFtdcCoverInfoField'] = CUstpFtdcCoverInfoField

#交易所费率查询请求
CUstpFtdcReqQryExchangeFeeField = {}
#交易所代码
CUstpFtdcReqQryExchangeFeeField["ExchangeID"] = "char"
#品种代码
CUstpFtdcReqQryExchangeFeeField["ProductID"] = "string"
#合约编码
CUstpFtdcReqQryExchangeFeeField["StockCode"] = "string"
structDict['CUstpFtdcReqQryExchangeFeeField'] = CUstpFtdcReqQryExchangeFeeField

#交易所费率查询应答
CUstpFtdcExchangeFeeField = {}
#交易所代码
CUstpFtdcExchangeFeeField["ExchangeID"] = "char"
#品种代码
CUstpFtdcExchangeFeeField["ProductID"] = "string"
#合约编码
CUstpFtdcExchangeFeeField["StockCode"] = "string"
#委托类型
CUstpFtdcExchangeFeeField["OrderType"] = "char"
#费用种类
CUstpFtdcExchangeFeeField["FeeType"] = "char"
#收费方式
CUstpFtdcExchangeFeeField["ChargingMethod"] = "char"
#单位费用
CUstpFtdcExchangeFeeField["UnitFee"] = "float"
#最高费用
CUstpFtdcExchangeFeeField["MaxFee"] = "float"
#最低费用
CUstpFtdcExchangeFeeField["MinFee"] = "float"
structDict['CUstpFtdcExchangeFeeField'] = CUstpFtdcExchangeFeeField

#行情订阅请求
CUstpFtdcSubMarketDataField = {}
#交易所代码
CUstpFtdcSubMarketDataField["ExchangeID"] = "char"
#合约编码
CUstpFtdcSubMarketDataField["StockCode"] = "string"
structDict['CUstpFtdcSubMarketDataField'] = CUstpFtdcSubMarketDataField

#深度行情
CUstpFtdcDepthMarketDataField = {}
#交易日
CUstpFtdcDepthMarketDataField["TradingDay"] = "string"
#交易所代码
CUstpFtdcDepthMarketDataField["ExchangeID"] = "char"
#合约编码
CUstpFtdcDepthMarketDataField["StockCode"] = "string"
#证券名称
CUstpFtdcDepthMarketDataField["StockName"] = "string"
#今开盘
CUstpFtdcDepthMarketDataField["OpenPrice"] = "float"
#申卖价一
CUstpFtdcDepthMarketDataField["AskPrice1"] = "float"
#申卖量一
CUstpFtdcDepthMarketDataField["AskVolume1"] = "int"
#申买价一
CUstpFtdcDepthMarketDataField["BidPrice1"] = "float"
#申买量一
CUstpFtdcDepthMarketDataField["Bidvolume1"] = "int"
#最高价
CUstpFtdcDepthMarketDataField["HighestPrice"] = "float"
#最低价
CUstpFtdcDepthMarketDataField["LowestPrice"] = "float"
#最新价
CUstpFtdcDepthMarketDataField["LastPrice"] = "float"
#持仓量
CUstpFtdcDepthMarketDataField["OpenInterest"] = "int"
#成交数量
CUstpFtdcDepthMarketDataField["TradeVolume"] = "int"
#成交金额
CUstpFtdcDepthMarketDataField["TradeAmnt"] = "float"
#昨收盘
CUstpFtdcDepthMarketDataField["PreClosePrice"] = "float"
#今收盘价
CUstpFtdcDepthMarketDataField["ClosePrice"] = "float"
#市盈率1
CUstpFtdcDepthMarketDataField["PriceEarningRatio1"] = "float"
#市盈率2
CUstpFtdcDepthMarketDataField["PriceEarningRatio2"] = "float"
#最后修改时间
CUstpFtdcDepthMarketDataField["UpdateTime"] = "string"
#最后修改毫秒
CUstpFtdcDepthMarketDataField["UpdateMillisec"] = "int"
#股票状态
CUstpFtdcDepthMarketDataField["StockStatus"] = "char"
#市场状态
CUstpFtdcDepthMarketDataField["MarketStatus"] = "char"
#申买价二
CUstpFtdcDepthMarketDataField["BidPrice2"] = "float"
#申买量二
CUstpFtdcDepthMarketDataField["BidVolume2"] = "int"
#申买价三
CUstpFtdcDepthMarketDataField["BidPrice3"] = "float"
#申买量三
CUstpFtdcDepthMarketDataField["BidVolume3"] = "int"
#申买价四
CUstpFtdcDepthMarketDataField["BidPrice4"] = "float"
#申买量四
CUstpFtdcDepthMarketDataField["BidVolume4"] = "int"
#申买价五
CUstpFtdcDepthMarketDataField["BidPrice5"] = "float"
#申买量五
CUstpFtdcDepthMarketDataField["BidVolume5"] = "int"
#申卖价二
CUstpFtdcDepthMarketDataField["AskPrice2"] = "float"
#申卖量二
CUstpFtdcDepthMarketDataField["AskVolume2"] = "int"
#申卖价三
CUstpFtdcDepthMarketDataField["AskPrice3"] = "float"
#申卖量三
CUstpFtdcDepthMarketDataField["AskVolume3"] = "int"
#申卖价四
CUstpFtdcDepthMarketDataField["AskPrice4"] = "float"
#申卖量四
CUstpFtdcDepthMarketDataField["AskVolume4"] = "int"
#申卖价五
CUstpFtdcDepthMarketDataField["AskPrice5"] = "float"
#申卖量五
CUstpFtdcDepthMarketDataField["AskVolume5"] = "int"
#相对于上一笔成交的价格涨跌值
CUstpFtdcDepthMarketDataField["PriceDelte1"] = "float"
#相对于昨收盘的价格涨跌值
CUstpFtdcDepthMarketDataField["PriceDelte2"] = "float"
#当前合约未平仓数量
CUstpFtdcDepthMarketDataField["TotalLongPosition"] = "int"
#动态参考价格
CUstpFtdcDepthMarketDataField["AuctionPrice"] = "float"
#虚拟匹配数量
CUstpFtdcDepthMarketDataField["AuctionQty"] = "int"
structDict['CUstpFtdcDepthMarketDataField'] = CUstpFtdcDepthMarketDataField

#组合保证金请求
CUstpFtdcReqCombMarginField = {}
#用户自定义域
CUstpFtdcReqCombMarginField["UserCustom"] = "string"
#投资者编号
CUstpFtdcReqCombMarginField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqCombMarginField["ExchangeID"] = "char"
#组合策略类型
CUstpFtdcReqCombMarginField["CombStrategyType"] = "char"
#组合方向
CUstpFtdcReqCombMarginField["CombDirectionType"] = "char"
#组合编号
CUstpFtdcReqCombMarginField["CombID"] = "string"
#腿一合约编码
CUstpFtdcReqCombMarginField["LegStockCode1"] = "string"
#腿二合约编码
CUstpFtdcReqCombMarginField["LegStockCode2"] = "string"
#用户报单编号
CUstpFtdcReqCombMarginField["UserOrderLocalID"] = "int"
#组合数量
CUstpFtdcReqCombMarginField["CombVolume"] = "int"
#子账号序号（主账号为0）
CUstpFtdcReqCombMarginField["SubAcctNo"] = "int"
structDict['CUstpFtdcReqCombMarginField'] = CUstpFtdcReqCombMarginField

#组合保证金应答
CUstpFtdcRspCombMarginField = {}
#用户自定义域
CUstpFtdcRspCombMarginField["UserCustom"] = "string"
#投资者编号
CUstpFtdcRspCombMarginField["InvestorID"] = "string"
#委托时间
CUstpFtdcRspCombMarginField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspCombMarginField["OrderLocalID"] = "string"
#用户报单编号
CUstpFtdcRspCombMarginField["UserOrderLocalID"] = "int"
structDict['CUstpFtdcRspCombMarginField'] = CUstpFtdcRspCombMarginField

#组合保证金查询请求
CUstpFtdcReqQryCombMarginField = {}
#投资者编号
CUstpFtdcReqQryCombMarginField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryCombMarginField["ExchangeID"] = "char"
#系统报单编号
CUstpFtdcReqQryCombMarginField["OrderLocalID"] = "string"
structDict['CUstpFtdcReqQryCombMarginField'] = CUstpFtdcReqQryCombMarginField

#组合保证金回报
CUstpFtdcCombMarginField = {}
#用户自定义域
CUstpFtdcCombMarginField["UserCustom"] = "string"
#投资者编号
CUstpFtdcCombMarginField["InvestorID"] = "string"
#交易所代码
CUstpFtdcCombMarginField["ExchangeID"] = "char"
#组合策略类型
CUstpFtdcCombMarginField["CombStrategyType"] = "char"
#组合方向
CUstpFtdcCombMarginField["CombDirectionType"] = "char"
#组合编号
CUstpFtdcCombMarginField["CombID"] = "string"
#腿一合约编码
CUstpFtdcCombMarginField["LegStockCode1"] = "string"
#腿二合约编码
CUstpFtdcCombMarginField["LegStockCode2"] = "string"
#用户报单编号
CUstpFtdcCombMarginField["UserOrderLocalID"] = "int"
#组合数量
CUstpFtdcCombMarginField["CombVolume"] = "int"
#子账号序号（主账号为0）
CUstpFtdcCombMarginField["SubAcctNo"] = "int"
#报单用户代码
CUstpFtdcCombMarginField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcCombMarginField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcCombMarginField["OrderSource"] = "char"
#报单状态
CUstpFtdcCombMarginField["OrderStatus"] = "char"
#委托时间
CUstpFtdcCombMarginField["InsertTime"] = "string"
#最后更新时间
CUstpFtdcCombMarginField["UpdateTime"] = "string"
#冻结费用
CUstpFtdcCombMarginField["FrozenFee"] = "float"
#拆组合时冻结的保证金
CUstpFtdcCombMarginField["ExtraFrozenMargin"] = "float"
structDict['CUstpFtdcCombMarginField'] = CUstpFtdcCombMarginField

#投资者组合持仓查询请求
CUstpFtdcReqQryCombPositionField = {}
#交易所代码
CUstpFtdcReqQryCombPositionField["ExchangeID"] = "char"
#投资者编号
CUstpFtdcReqQryCombPositionField["InvestorID"] = "string"
#组合策略类型
CUstpFtdcReqQryCombPositionField["CombStrategyType"] = "char"
#腿一合约编码
CUstpFtdcReqQryCombPositionField["LegStockCode1"] = "string"
#腿二合约编码
CUstpFtdcReqQryCombPositionField["LegStockCode2"] = "string"
structDict['CUstpFtdcReqQryCombPositionField'] = CUstpFtdcReqQryCombPositionField

#投资者组合持仓查询应答
CUstpFtdcCombPositionField = {}
#交易所代码
CUstpFtdcCombPositionField["ExchangeID"] = "char"
#投资者编号
CUstpFtdcCombPositionField["InvestorID"] = "string"
#组合策略类型
CUstpFtdcCombPositionField["CombStrategyType"] = "char"
#腿一合约编码
CUstpFtdcCombPositionField["LegStockCode1"] = "string"
#腿二合约编码
CUstpFtdcCombPositionField["LegStockCode2"] = "string"
#股东代码
CUstpFtdcCombPositionField["ClientID"] = "string"
#子账号序号（主账号为0）
CUstpFtdcCombPositionField["SubAcctNo"] = "int"
#组合持仓可用数量
CUstpFtdcCombPositionField["CombAvailablePosition"] = "int"
#冻结组合持仓
CUstpFtdcCombPositionField["CombFrozenPosition"] = "int"
#组合交易所保证金占用
CUstpFtdcCombPositionField["CombExMarginOccupation"] = "float"
#组合保证金占用
CUstpFtdcCombPositionField["CombMarginOccupation"] = "float"
#组合交易所释放的保证金
CUstpFtdcCombPositionField["CombExReleaseMargin"] = "float"
#组合释放的保证金
CUstpFtdcCombPositionField["CombReleaseMargin"] = "float"
#成分合约个数
CUstpFtdcCombPositionField["NoLegs"] = "int"
#腿一方向
CUstpFtdcCombPositionField["LegSide1"] = "char"
#腿一合约数量
CUstpFtdcCombPositionField["LegQty1"] = "int"
#腿一交易所保证金占用
CUstpFtdcCombPositionField["LegExMarginOccupation1"] = "float"
#腿一保证金占用
CUstpFtdcCombPositionField["LegMarginOccupation1"] = "float"
#腿二方向
CUstpFtdcCombPositionField["LegSide2"] = "char"
#腿二合约数量
CUstpFtdcCombPositionField["LegQty2"] = "int"
#腿二交易所保证金占用
CUstpFtdcCombPositionField["LegExMarginOccupation2"] = "float"
#腿二保证金占用
CUstpFtdcCombPositionField["LegMarginOccupation2"] = "float"
structDict['CUstpFtdcCombPositionField'] = CUstpFtdcCombPositionField

#投资者组合持仓明细查询请求
CUstpFtdcReqQryCombPositionDetailField = {}
#交易所代码
CUstpFtdcReqQryCombPositionDetailField["ExchangeID"] = "char"
#投资者编号
CUstpFtdcReqQryCombPositionDetailField["InvestorID"] = "string"
#组合策略类型
CUstpFtdcReqQryCombPositionDetailField["CombStrategyType"] = "char"
#腿一合约编码
CUstpFtdcReqQryCombPositionDetailField["LegStockCode1"] = "string"
#腿二合约编码
CUstpFtdcReqQryCombPositionDetailField["LegStockCode2"] = "string"
structDict['CUstpFtdcReqQryCombPositionDetailField'] = CUstpFtdcReqQryCombPositionDetailField

#投资者组合持仓明细查询应答
CUstpFtdcCombPositionDetailField = {}
#交易所代码
CUstpFtdcCombPositionDetailField["ExchangeID"] = "char"
#投资者编号
CUstpFtdcCombPositionDetailField["InvestorID"] = "string"
#组合策略类型
CUstpFtdcCombPositionDetailField["CombStrategyType"] = "char"
#腿一合约编码
CUstpFtdcCombPositionDetailField["LegStockCode1"] = "string"
#腿二合约编码
CUstpFtdcCombPositionDetailField["LegStockCode2"] = "string"
#股东代码
CUstpFtdcCombPositionDetailField["ClientID"] = "string"
#子账号序号（主账号为0）
CUstpFtdcCombPositionDetailField["SubAcctNo"] = "int"
#组合持仓可用数量
CUstpFtdcCombPositionDetailField["CombAvailablePosition"] = "int"
#冻结组合持仓
CUstpFtdcCombPositionDetailField["CombFrozenPosition"] = "int"
#组合交易所保证金占用
CUstpFtdcCombPositionDetailField["CombExMarginOccupation"] = "float"
#组合保证金占用
CUstpFtdcCombPositionDetailField["CombMarginOccupation"] = "float"
#组合交易所释放的保证金
CUstpFtdcCombPositionDetailField["CombExReleaseMargin"] = "float"
#组合释放的保证金
CUstpFtdcCombPositionDetailField["CombReleaseMargin"] = "float"
#成分合约个数
CUstpFtdcCombPositionDetailField["NoLegs"] = "int"
#腿一方向
CUstpFtdcCombPositionDetailField["LegSide1"] = "char"
#腿一合约数量
CUstpFtdcCombPositionDetailField["LegQty1"] = "int"
#腿一交易所保证金占用
CUstpFtdcCombPositionDetailField["LegExMarginOccupation1"] = "float"
#腿一保证金占用
CUstpFtdcCombPositionDetailField["LegMarginOccupation1"] = "float"
#腿二方向
CUstpFtdcCombPositionDetailField["LegSide2"] = "char"
#腿二合约数量
CUstpFtdcCombPositionDetailField["LegQty2"] = "int"
#腿二交易所保证金占用
CUstpFtdcCombPositionDetailField["LegExMarginOccupation2"] = "float"
#腿二保证金占用
CUstpFtdcCombPositionDetailField["LegMarginOccupation2"] = "float"
#初始组合持仓
CUstpFtdcCombPositionDetailField["CombPosition"] = "int"
#组合编号
CUstpFtdcCombPositionDetailField["CombID"] = "string"
structDict['CUstpFtdcCombPositionDetailField'] = CUstpFtdcCombPositionDetailField

#组合策略信息查询请求
CUstpFtdcReqQryCombStrategyInfoField = {}
#交易所代码
CUstpFtdcReqQryCombStrategyInfoField["ExchangeID"] = "char"
#组合策略类型
CUstpFtdcReqQryCombStrategyInfoField["CombStrategyType"] = "char"
structDict['CUstpFtdcReqQryCombStrategyInfoField'] = CUstpFtdcReqQryCombStrategyInfoField

#组合策略信息查询应答
CUstpFtdcCombStrategyInfoField = {}
#交易所代码
CUstpFtdcCombStrategyInfoField["ExchangeID"] = "char"
#组合策略类型
CUstpFtdcCombStrategyInfoField["CombStrategyType"] = "char"
#组合策略名称
CUstpFtdcCombStrategyInfoField["CombName"] = "string"
#组合自动解除日
CUstpFtdcCombStrategyInfoField["CombSplitDay"] = "int"
#成分合约到期日要求
CUstpFtdcCombStrategyInfoField["LastTradeDayCheckType"] = "char"
#成分合约标的要求
CUstpFtdcCombStrategyInfoField["UnderlyCheckType"] = "char"
#是否使用非标合约
CUstpFtdcCombStrategyInfoField["NonStandardOption"] = "char"
#成分合约个数
CUstpFtdcCombStrategyInfoField["NoLegs"] = "int"
#腿一认购或认沽
CUstpFtdcCombStrategyInfoField["LegOptionType1"] = "char"
#腿一持仓类型
CUstpFtdcCombStrategyInfoField["LegSide1"] = "char"
#腿一合约张数
CUstpFtdcCombStrategyInfoField["LegPositionQty1"] = "int"
#腿一行权价高低顺序
CUstpFtdcCombStrategyInfoField["LegExePriceSeq1"] = "int"
#腿一到期日顺序
CUstpFtdcCombStrategyInfoField["LegLastTradeDaySeq1"] = "int"
#腿二认购或认沽
CUstpFtdcCombStrategyInfoField["LegOptionType2"] = "char"
#腿二持仓类型
CUstpFtdcCombStrategyInfoField["LegSide2"] = "char"
#腿二合约张数
CUstpFtdcCombStrategyInfoField["LegPositionQty2"] = "int"
#腿二行权价高低顺序
CUstpFtdcCombStrategyInfoField["LegExePriceSeq2"] = "int"
#腿二到期日顺序
CUstpFtdcCombStrategyInfoField["LegLastTradeDaySeq2"] = "int"
structDict['CUstpFtdcCombStrategyInfoField'] = CUstpFtdcCombStrategyInfoField

#组合保证金率查询请求
CUstpFtdcReqQryInvestorCombMarginField = {}
#投资者编号
CUstpFtdcReqQryInvestorCombMarginField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqQryInvestorCombMarginField["ExchangeID"] = "char"
#组合策略类型
CUstpFtdcReqQryInvestorCombMarginField["CombStrategyType"] = "char"
#品种代码
CUstpFtdcReqQryInvestorCombMarginField["ProductID"] = "string"
structDict['CUstpFtdcReqQryInvestorCombMarginField'] = CUstpFtdcReqQryInvestorCombMarginField

#组合保证金率查询应答
CUstpFtdcInvestorCombMarginField = {}
#投资者编号
CUstpFtdcInvestorCombMarginField["InvestorID"] = "string"
#交易所代码
CUstpFtdcInvestorCombMarginField["ExchangeID"] = "char"
#组合策略类型
CUstpFtdcInvestorCombMarginField["CombStrategyType"] = "char"
#品种代码
CUstpFtdcInvestorCombMarginField["ProductID"] = "string"
#保证金调整比例
CUstpFtdcInvestorCombMarginField["MarginAdjustRate"] = "float"
structDict['CUstpFtdcInvestorCombMarginField'] = CUstpFtdcInvestorCombMarginField

#组合成交回报
CUstpFtdcCombMarginTradeField = {}
#用户自定义域
CUstpFtdcCombMarginTradeField["UserCustom"] = "string"
#投资者编号
CUstpFtdcCombMarginTradeField["InvestorID"] = "string"
#交易所代码
CUstpFtdcCombMarginTradeField["ExchangeID"] = "char"
#组合策略类型
CUstpFtdcCombMarginTradeField["CombStrategyType"] = "char"
#组合方向
CUstpFtdcCombMarginTradeField["CombDirectionType"] = "char"
#组合编号
CUstpFtdcCombMarginTradeField["CombID"] = "string"
#腿一合约编码
CUstpFtdcCombMarginTradeField["LegStockCode1"] = "string"
#腿二合约编码
CUstpFtdcCombMarginTradeField["LegStockCode2"] = "string"
#用户报单编号
CUstpFtdcCombMarginTradeField["UserOrderLocalID"] = "int"
#组合数量
CUstpFtdcCombMarginTradeField["CombVolume"] = "int"
#子账号序号（主账号为0）
CUstpFtdcCombMarginTradeField["SubAcctNo"] = "int"
#报单用户代码
CUstpFtdcCombMarginTradeField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcCombMarginTradeField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcCombMarginTradeField["OrderSource"] = "char"
#委托时间
CUstpFtdcCombMarginTradeField["InsertTime"] = "string"
#最后更新时间
CUstpFtdcCombMarginTradeField["UpdateTime"] = "string"
#费用
CUstpFtdcCombMarginTradeField["Fee"] = "float"
#组合占用保证金
CUstpFtdcCombMarginTradeField["OccupMargin"] = "float"
#单腿占用总保证金
CUstpFtdcCombMarginTradeField["LegsOccupMargin"] = "float"
#组合释放保证金
CUstpFtdcCombMarginTradeField["ReleasedMargin"] = "float"
structDict['CUstpFtdcCombMarginTradeField'] = CUstpFtdcCombMarginTradeField

#合并行权请求
CUstpFtdcReqCombExeOrderInsertField = {}
#用户自定义域
CUstpFtdcReqCombExeOrderInsertField["UserCustom"] = "string"
#投资者编号
CUstpFtdcReqCombExeOrderInsertField["InvestorID"] = "string"
#交易所代码
CUstpFtdcReqCombExeOrderInsertField["ExchangeID"] = "char"
#看涨合约编码
CUstpFtdcReqCombExeOrderInsertField["CallStockCode"] = "string"
#看跌合约编码
CUstpFtdcReqCombExeOrderInsertField["PutStockCode"] = "string"
#子账号序号（主账号为0）
CUstpFtdcReqCombExeOrderInsertField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcReqCombExeOrderInsertField["UserOrderLocalID"] = "int"
#数量
CUstpFtdcReqCombExeOrderInsertField["Volume"] = "int"
structDict['CUstpFtdcReqCombExeOrderInsertField'] = CUstpFtdcReqCombExeOrderInsertField

#合并行权应答
CUstpFtdcRspCombExeOrderInsertField = {}
#用户自定义域
CUstpFtdcRspCombExeOrderInsertField["UserCustom"] = "string"
#投资者编号
CUstpFtdcRspCombExeOrderInsertField["InvestorID"] = "string"
#委托时间
CUstpFtdcRspCombExeOrderInsertField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspCombExeOrderInsertField["OrderLocalID"] = "string"
#用户报单编号
CUstpFtdcRspCombExeOrderInsertField["UserOrderLocalID"] = "int"
structDict['CUstpFtdcRspCombExeOrderInsertField'] = CUstpFtdcRspCombExeOrderInsertField

#合并行权撤销请求
CUstpFtdcReqCombExeOrderActionField = {}
#用户自定义域
CUstpFtdcReqCombExeOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcReqCombExeOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcReqCombExeOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcReqCombExeOrderActionField["UserOrderActionRef"] = "int"
structDict['CUstpFtdcReqCombExeOrderActionField'] = CUstpFtdcReqCombExeOrderActionField

#合并行权撤销应答
CUstpFtdcRspCombExeOrderActionField = {}
#用户自定义域
CUstpFtdcRspCombExeOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcRspCombExeOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcRspCombExeOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcRspCombExeOrderActionField["UserOrderActionRef"] = "int"
#委托时间
CUstpFtdcRspCombExeOrderActionField["InsertTime"] = "string"
#系统报单编号
CUstpFtdcRspCombExeOrderActionField["OrderLocalID"] = "string"
structDict['CUstpFtdcRspCombExeOrderActionField'] = CUstpFtdcRspCombExeOrderActionField

#合并行权回报
CUstpFtdcCombExeOrderField = {}
#用户自定义域
CUstpFtdcCombExeOrderField["UserCustom"] = "string"
#投资者编号
CUstpFtdcCombExeOrderField["InvestorID"] = "string"
#交易所代码
CUstpFtdcCombExeOrderField["ExchangeID"] = "char"
#看涨合约编码
CUstpFtdcCombExeOrderField["CallStockCode"] = "string"
#看跌合约编码
CUstpFtdcCombExeOrderField["PutStockCode"] = "string"
#子账号序号（主账号为0）
CUstpFtdcCombExeOrderField["SubAcctNo"] = "int"
#用户报单编号
CUstpFtdcCombExeOrderField["UserOrderLocalID"] = "int"
#数量
CUstpFtdcCombExeOrderField["Volume"] = "int"
#报单用户代码
CUstpFtdcCombExeOrderField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcCombExeOrderField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcCombExeOrderField["OrderSource"] = "char"
#报单状态
CUstpFtdcCombExeOrderField["OrderStatus"] = "char"
#最后更新时间
CUstpFtdcCombExeOrderField["UpdateTime"] = "string"
structDict['CUstpFtdcCombExeOrderField'] = CUstpFtdcCombExeOrderField

#合并行权撤销回报
CUstpFtdcCombExeOrderActionField = {}
#用户自定义域
CUstpFtdcCombExeOrderActionField["UserCustom"] = "string"
#被撤系统报单编号
CUstpFtdcCombExeOrderActionField["OrderActionRef"] = "string"
#用户报单编号
CUstpFtdcCombExeOrderActionField["UserOrderLocalID"] = "int"
#被撤用户报单编号
CUstpFtdcCombExeOrderActionField["UserOrderActionRef"] = "int"
#报单用户代码
CUstpFtdcCombExeOrderActionField["ReqUserID"] = "string"
#系统报单编号
CUstpFtdcCombExeOrderActionField["OrderLocalID"] = "string"
#报单来源
CUstpFtdcCombExeOrderActionField["OrderSource"] = "char"
#报单状态
CUstpFtdcCombExeOrderActionField["OrderStatus"] = "char"
#撤销时间
CUstpFtdcCombExeOrderActionField["CancelTime"] = "string"
#撤单数量
CUstpFtdcCombExeOrderActionField["CancelVolume"] = "int"
structDict['CUstpFtdcCombExeOrderActionField'] = CUstpFtdcCombExeOrderActionField

#穿透监管客户信息
CUstpFtdcDSUserInfoField = {}
#用户AppID
CUstpFtdcDSUserInfoField["AppID"] = "string"
#用户授权码
CUstpFtdcDSUserInfoField["AuthCode"] = "string"
#密钥加密类型
CUstpFtdcDSUserInfoField["EncryptType"] = "char"
structDict['CUstpFtdcDSUserInfoField'] = CUstpFtdcDSUserInfoField

#穿透监管客户认证请求信息
CUstpFtdcDSUserCertReqDataField = {}
#用户AppID
CUstpFtdcDSUserCertReqDataField["AppID"] = "string"
#用户认证请求信息
CUstpFtdcDSUserCertReqDataField["UserCertReqData"] = "string"
#用户证书信息分片的总片数
CUstpFtdcDSUserCertReqDataField["TotalNum"] = "int"
#用户证书信息分片的第几片
CUstpFtdcDSUserCertReqDataField["CurrentNum"] = "int"
structDict['CUstpFtdcDSUserCertReqDataField'] = CUstpFtdcDSUserCertReqDataField

#穿透监管客户认证响应信息
CUstpFtdcDSUserCertRspDataField = {}
#AppID
CUstpFtdcDSUserCertRspDataField["AppID"] = "string"
#AppID类型
CUstpFtdcDSUserCertRspDataField["AppIDType"] = "char"
#用户认证返回信息
CUstpFtdcDSUserCertRspDataField["UserCertRspData"] = "string"
#用户证书返回信息分片的总片数
CUstpFtdcDSUserCertRspDataField["TotalNum"] = "int"
#用户证书返回信息分片的第几片
CUstpFtdcDSUserCertRspDataField["CurrentNum"] = "int"
structDict['CUstpFtdcDSUserCertRspDataField'] = CUstpFtdcDSUserCertRspDataField

#穿透监管客户信息采集信息
CUstpFtdcDSLocalSystemDataField = {}
#用户AppID
CUstpFtdcDSLocalSystemDataField["AppID"] = "string"
#异常标识
CUstpFtdcDSLocalSystemDataField["ExceptionFlag"] = "char"
#用户信息采集结果
CUstpFtdcDSLocalSystemDataField["LocalSystemData"] = "string"
structDict['CUstpFtdcDSLocalSystemDataField'] = CUstpFtdcDSLocalSystemDataField

#穿透监管中继验证客户信息
CUstpFtdcDSProxyCheckUserInfoField = {}
#用户AppID
CUstpFtdcDSProxyCheckUserInfoField["AppID"] = "string"
#用户授权码
CUstpFtdcDSProxyCheckUserInfoField["AuthCode"] = "string"
#密钥加密类型
CUstpFtdcDSProxyCheckUserInfoField["EncryptType"] = "char"
structDict['CUstpFtdcDSProxyCheckUserInfoField'] = CUstpFtdcDSProxyCheckUserInfoField

#穿透监管中继处接收到的终端认证信息
CUstpFtdcDSProxyUserCertInField = {}
#
CUstpFtdcDSProxyUserCertInField["UserCertReqInfo"] = "string"
structDict['CUstpFtdcDSProxyUserCertInField'] = CUstpFtdcDSProxyUserCertInField

#穿透监管中继处接终端认证返回信息
CUstpFtdcDSProxyUserCertOutField = {}
#
CUstpFtdcDSProxyUserCertOutField["UserCertRspInfo"] = "string"
#
CUstpFtdcDSProxyUserCertOutField["UserCertRspInfoLen"] = "int"
structDict['CUstpFtdcDSProxyUserCertOutField'] = CUstpFtdcDSProxyUserCertOutField

#穿透监管中继提交信息
CUstpFtdcDSProxySubmitDataField = {}
#AppID
CUstpFtdcDSProxySubmitDataField["AppID"] = "string"
#客户终端公网IP
CUstpFtdcDSProxySubmitDataField["TerminalPubNetIP"] = "string"
#客户终端公网端口号
CUstpFtdcDSProxySubmitDataField["TerminalPubNetPort"] = "string"
#客户终端登入时间
CUstpFtdcDSProxySubmitDataField["TerminalLoginTime"] = "string"
#异常标识
CUstpFtdcDSProxySubmitDataField["ExceptionFlag"] = "char"
#RealyID
CUstpFtdcDSProxySubmitDataField["RelayID"] = "string"
#终端采集信息
CUstpFtdcDSProxySubmitDataField["TerminalSystemData"] = "string"
structDict['CUstpFtdcDSProxySubmitDataField'] = CUstpFtdcDSProxySubmitDataField

#穿透监管线下委托客户信息
CUstpFtdcDSOfflineInfoField = {}
#AppID
CUstpFtdcDSOfflineInfoField["AppID"] = "string"
#投资者编号
CUstpFtdcDSOfflineInfoField["InvestorID"] = "string"
#投资者手机号
CUstpFtdcDSOfflineInfoField["InvestorTel"] = "string"
structDict['CUstpFtdcDSOfflineInfoField'] = CUstpFtdcDSOfflineInfoField




