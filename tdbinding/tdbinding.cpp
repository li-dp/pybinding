// tdbinding.cpp : 定义 DLL 应用程序的导出函数。
//

#include "tdbinding.h"


///-------------------------------------------------------------------------------------
///从Python对象到C++类型转换用的函数
///-------------------------------------------------------------------------------------

void getInt(dict d, string key, int *value)
{
	if (d.has_key(key))		//检查字典中是否存在该键值
	{
		object o = d[key];	//获取该键值
		extract<int> x(o);	//创建提取器
		if (x.check())		//如果可以提取
		{
			*value = x();	//对目标整数指针赋值
		}
	}
}

void getDouble(dict d, string key, double *value)
{
	if (d.has_key(key))
	{
		object o = d[key];
		extract<double> x(o);
		if (x.check())
		{
			*value = x();
		}
	}
}

void getStr(dict d, string key, char *value)
{
	if (d.has_key(key))
	{
		object o = d[key];
		extract<string> x(o);
		if (x.check())
		{
			string s = x();
			const char *buffer = s.c_str();
			//对字符串指针赋值必须使用strcpy_s, vs2013使用strcpy编译通不过
			//+1应该是因为C++字符串的结尾符号？不是特别确定，不加这个1会出错
#ifdef _MSC_VER //WIN32
			strcpy_s(value, strlen(buffer) + 1, buffer);
#elif __GNUC__
			strncpy(value, buffer, strlen(buffer) + 1);
#endif
		}
	}
}

void getChar(dict d, string key, char *value)
{
	if (d.has_key(key))
	{
		object o = d[key];
		extract<string> x(o);
		if (x.check())
		{
			string s = x();
			const char *buffer = s.c_str();
			*value = *buffer;
		}
	}
}


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------
void TdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void TdApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nReason;
	this->task_queue.push(task);
};

void TdApi::OnHeartBeatWarning(int nTimeLapse)
{
	Task task = Task();
	task.task_name = ONHEARTBEATWARNING;
	task.task_id = nTimeLapse;
	this->task_queue.push(task);
};

void TdApi::OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPERROR;

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;

	if (pRspUserLogin)
	{
		task.task_data = *pRspUserLogin;
	}
	else
	{
		CFocusFtdcRspUserLoginField empty_data = CFocusFtdcRspUserLoginField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGOUT;

	if (pRspUserLogout)
	{
		task.task_data = *pRspUserLogout;
	}
	else
	{
		CFocusFtdcRspUserLogoutField empty_data = CFocusFtdcRspUserLogoutField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPORDERINSERT;

	if (pInputOrder)
	{
		task.task_data = *pInputOrder;
	}
	else
	{
		CFocusFtdcInputOrderField empty_data = CFocusFtdcInputOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;

	if (pOrderAction)
	{
		task.task_data = *pOrderAction;
	}
	else
	{
		CFocusFtdcOrderActionField empty_data = CFocusFtdcOrderActionField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnTrade(CFocusFtdcTradeField *pTrade) 
{
	Task task = Task();
	task.task_name = ONRTNTRADE;

	if (pTrade)
	{
		task.task_data = *pTrade;
	}
	else
	{
		CFocusFtdcTradeField empty_data = CFocusFtdcTradeField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(CFocusFtdcOrderField *pOrder) 
{
	Task task = Task();
	task.task_name = ONRTNORDER;

	if (pOrder)
	{
		task.task_data = *pOrder;
	}
	else
	{
		CFocusFtdcOrderField empty_data = CFocusFtdcOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) 
{
	Task task = Task();
	task.task_name = ONRTNINSTRUMENTSTATUS;

	if (pInstrumentStatus)
	{
		task.task_data = *pInstrumentStatus;
	}
	else
	{
		CFocusFtdcInstrumentStatusField empty_data = CFocusFtdcInstrumentStatusField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) 
{
	Task task = Task();
	task.task_name = ONRTNMESSAGENOTIFY;

	if (pMessageNotify)
	{
		task.task_data = *pMessageNotify;
	}
	else
	{
		CFocusFtdcMessageNotifyField empty_data = CFocusFtdcMessageNotifyField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;

	if (pOrder)
	{
		task.task_data = *pOrder;
	}
	else
	{
		CFocusFtdcOrderField empty_data = CFocusFtdcOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADE;

	if (pTrade)
	{
		task.task_data = *pTrade;
	}
	else
	{
		CFocusFtdcTradeField empty_data = CFocusFtdcTradeField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryInstrument(CFocusFtdcRspInstrumentField *pRspInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINSTRUMENT;

	if (pRspInstrument)
	{
		task.task_data = *pRspInstrument;
	}
	else
	{
		CFocusFtdcRspInstrumentField empty_data = CFocusFtdcRspInstrumentField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryExchange(CFocusFtdcRspExchangeField *pRspExchange, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGE;

	if (pRspExchange)
	{
		task.task_data = *pRspExchange;
	}
	else
	{
		CFocusFtdcRspExchangeField empty_data = CFocusFtdcRspExchangeField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORPOSITION;

	if (pRspInvestorPosition)
	{
		task.task_data = *pRspInvestorPosition;
	}
	else
	{
		CFocusFtdcRspInvestorPositionField empty_data = CFocusFtdcRspInvestorPositionField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSCRIBETOPIC;

	if (pDissemination)
	{
		task.task_data = *pDissemination;
	}
	else
	{
		CFocusFtdcDisseminationField empty_data = CFocusFtdcDisseminationField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTOPIC;

	if (pDissemination)
	{
		task.task_data = *pDissemination;
	}
	else
	{
		CFocusFtdcDisseminationField empty_data = CFocusFtdcDisseminationField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYPRODUCT;

	if (pRspProduct)
	{
		task.task_data = *pRspProduct;
	}
	else
	{
		CFocusFtdcRspProductField empty_data = CFocusFtdcRspProductField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnStrategyLog(CFocusFtdcStrategyLogField *pStrategyLog) 
{
	Task task = Task();
	task.task_name = ONRTNSTRATEGYLOG;

	if (pStrategyLog)
	{
		task.task_data = *pStrategyLog;
	}
	else
	{
		CFocusFtdcStrategyLogField empty_data = CFocusFtdcStrategyLogField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition) 
{
	Task task = Task();
	task.task_name = ONRTNINVESTORPOSITION;

	if (pRspInvestorPosition)
	{
		task.task_data = *pRspInvestorPosition;
	}
	else
	{
		CFocusFtdcRspInvestorPositionField empty_data = CFocusFtdcRspInvestorPositionField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnParentOrder(CFocusFtdcParentOrderField *pParentOrder) 
{
	Task task = Task();
	task.task_name = ONRTNPARENTORDER;

	if (pParentOrder)
	{
		task.task_data = *pParentOrder;
	}
	else
	{
		CFocusFtdcParentOrderField empty_data = CFocusFtdcParentOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnParentOrderAction(CFocusFtdcParentOrderActionField *pParentOrderAction) 
{
	Task task = Task();
	task.task_name = ONRTNPARENTORDERACTION;

	if (pParentOrderAction)
	{
		task.task_data = *pParentOrderAction;
	}
	else
	{
		CFocusFtdcParentOrderActionField empty_data = CFocusFtdcParentOrderActionField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnAmendParentOrder(CFocusFtdcAmendParentOrderField *pAmendParentOrder) 
{
	Task task = Task();
	task.task_name = ONRTNAMENDPARENTORDER;

	if (pAmendParentOrder)
	{
		task.task_data = *pAmendParentOrder;
	}
	else
	{
		CFocusFtdcAmendParentOrderField empty_data = CFocusFtdcAmendParentOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnExtraManualParentOrder(CFocusFtdcExtraManualParentOrderField *pExtraManualParentOrder) 
{
	Task task = Task();
	task.task_name = ONRTNEXTRAMANUALPARENTORDER;

	if (pExtraManualParentOrder)
	{
		task.task_data = *pExtraManualParentOrder;
	}
	else
	{
		CFocusFtdcExtraManualParentOrderField empty_data = CFocusFtdcExtraManualParentOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryMarketTradingTime(CFocusFtdcMarketTradingPeriodInfoField *pMarketTradingPeriodInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKETTRADINGTIME;

	if (pMarketTradingPeriodInfo)
	{
		task.task_data = *pMarketTradingPeriodInfo;
	}
	else
	{
		CFocusFtdcMarketTradingPeriodInfoField empty_data = CFocusFtdcMarketTradingPeriodInfoField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPBATCHORDERINSERT;

	if (pBatchInputOrder)
	{
		task.task_data = *pBatchInputOrder;
	}
	else
	{
		CFocusFtdcBatchInputOrderField empty_data = CFocusFtdcBatchInputOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPBATCHORDERACTION;

	if (pBatchOrderAction)
	{
		task.task_data = *pBatchOrderAction;
	}
	else
	{
		CFocusFtdcBatchOrderActionField empty_data = CFocusFtdcBatchOrderActionField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CFocusFtdcRspInfoField empty_error = CFocusFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) 
{
	Task task = Task();
	task.task_name = ONRTNSPREADINSTRSTRATEGY;

	if (pSpreadInstrStrategy)
	{
		task.task_data = *pSpreadInstrStrategy;
	}
	else
	{
		CFocusFtdcSpreadInstrStrategyField empty_data = CFocusFtdcSpreadInstrStrategyField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnAmendPSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) 
{
	Task task = Task();
	task.task_name = ONRTNAMENDPSPREADINSTRSTRATEGY;

	if (pSpreadInstrStrategy)
	{
		task.task_data = *pSpreadInstrStrategy;
	}
	else
	{
		CFocusFtdcSpreadInstrStrategyField empty_data = CFocusFtdcSpreadInstrStrategyField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};



///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void TdApi::processTask()
{
	while (1)
	{
		Task task = this->task_queue.wait_and_pop();

		switch (task.task_name)
		{
		case ONFRONTCONNECTED:
		{
			this->processFrontConnected(task);
			break;
		}

		case ONFRONTDISCONNECTED:
		{
			this->processFrontDisconnected(task);
			break;
		}

		case ONHEARTBEATWARNING:
		{
			this->processHeartBeatWarning(task);
			break;
		}

		case ONRSPERROR:
		{
			this->processRspError(task);
			break;
		}

		case ONRSPUSERLOGIN:
		{
			this->processRspUserLogin(task);
			break;
		}

		case ONRSPUSERLOGOUT:
		{
			this->processRspUserLogout(task);
			break;
		}

		case ONRSPORDERINSERT:
		{
			this->processRspOrderInsert(task);
			break;
		}

		case ONRSPORDERACTION:
		{
			this->processRspOrderAction(task);
			break;
		}

		case ONRTNTRADE:
		{
			this->processRtnTrade(task);
			break;
		}

		case ONRTNORDER:
		{
			this->processRtnOrder(task);
			break;
		}

		case ONRTNINSTRUMENTSTATUS:
		{
			this->processRtnInstrumentStatus(task);
			break;
		}

		case ONRTNMESSAGENOTIFY:
		{
			this->processRtnMessageNotify(task);
			break;
		}

		case ONRSPQRYORDER:
		{
			this->processRspQryOrder(task);
			break;
		}

		case ONRSPQRYTRADE:
		{
			this->processRspQryTrade(task);
			break;
		}

		case ONRSPQRYINSTRUMENT:
		{
			this->processRspQryInstrument(task);
			break;
		}

		case ONRSPQRYEXCHANGE:
		{
			this->processRspQryExchange(task);
			break;
		}

		case ONRSPQRYINVESTORPOSITION:
		{
			this->processRspQryInvestorPosition(task);
			break;
		}

		case ONRSPSUBSCRIBETOPIC:
		{
			this->processRspSubscribeTopic(task);
			break;
		}

		case ONRSPQRYTOPIC:
		{
			this->processRspQryTopic(task);
			break;
		}

		case ONRSPQRYPRODUCT:
		{
			this->processRspQryProduct(task);
			break;
		}

		case ONRTNSTRATEGYLOG:
		{
			this->processRtnStrategyLog(task);
			break;
		}

		case ONRTNINVESTORPOSITION:
		{
			this->processRtnInvestorPosition(task);
			break;
		}

		case ONRTNPARENTORDER:
		{
			this->processRtnParentOrder(task);
			break;
		}

		case ONRTNPARENTORDERACTION:
		{
			this->processRtnParentOrderAction(task);
			break;
		}

		case ONRTNAMENDPARENTORDER:
		{
			this->processRtnAmendParentOrder(task);
			break;
		}

		case ONRTNEXTRAMANUALPARENTORDER:
		{
			this->processRtnExtraManualParentOrder(task);
			break;
		}

		case ONRSPQRYMARKETTRADINGTIME:
		{
			this->processRspQryMarketTradingTime(task);
			break;
		}

		case ONRSPBATCHORDERINSERT:
		{
			this->processRspBatchOrderInsert(task);
			break;
		}

		case ONRSPBATCHORDERACTION:
		{
			this->processRspBatchOrderAction(task);
			break;
		}

		case ONRTNSPREADINSTRSTRATEGY:
		{
			this->processRtnSpreadInstrStrategy(task);
			break;
		}

		case ONRTNAMENDPSPREADINSTRSTRATEGY:
		{
			this->processRtnAmendPSpreadInstrStrategy(task);
			break;
		}


		}
	}
}

void TdApi::processFrontConnected(Task task)
{
	PyLock lock;
	this->onFrontConnected();
};

void TdApi::processFrontDisconnected(Task task)
{
	PyLock lock;
	this->onFrontDisconnected(task.task_id);
};

void TdApi::processHeartBeatWarning(Task task)
{
	PyLock lock;
	this->onHeartBeatWarning(task.task_id);
};

void TdApi::processRspError(Task task)
{
	PyLock lock;
	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspError(error, task.task_id, task.task_last);
};

void TdApi::processRspUserLogin(Task task)
{
	PyLock lock;
	CFocusFtdcRspUserLoginField task_data = any_cast<CFocusFtdcRspUserLoginField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = task_data.UserID;
	data["LoginTime"] = task_data.LoginTime;
	data["MaxOrderLocalID"] = task_data.MaxOrderLocalID;
	data["TradingSystemName"] = GBK_TO_UTF8(task_data.TradingSystemName);
	data["DataCenterID"] = task_data.DataCenterID;
	data["PrivateFlowSize"] = task_data.PrivateFlowSize;
	data["UserFlowSize"] = task_data.UserFlowSize;
	data["LoginInfo"] = task_data.LoginInfo;
	data["SessionID"] = task_data.SessionID;
	data["FrontID"] = task_data.FrontID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUserLogin(data, error, task.task_id, task.task_last);
};

void TdApi::processRspUserLogout(Task task)
{
	PyLock lock;
	CFocusFtdcRspUserLogoutField task_data = any_cast<CFocusFtdcRspUserLogoutField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = task_data.UserID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUserLogout(data, error, task.task_id, task.task_last);
};

void TdApi::processRspOrderInsert(Task task)
{
	PyLock lock;
	CFocusFtdcInputOrderField task_data = any_cast<CFocusFtdcInputOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = task_data.UserID;
	data["UserOrderLocalID"] = task_data.UserOrderLocalID;
	data["UserCustom"] = task_data.UserCustom;
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["OrderPriceType"] = task_data.OrderPriceType;
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["LimitPrice"] = task_data.LimitPrice;
	data["Volume"] = task_data.Volume;
	data["TimeCondition"] = task_data.TimeCondition;
	data["GTDDate"] = task_data.GTDDate;
	data["VolumeCondition"] = task_data.VolumeCondition;
	data["MinVolume"] = task_data.MinVolume;
	data["StopPrice"] = task_data.StopPrice;
	data["ForceCloseReason"] = task_data.ForceCloseReason;
	data["IsAutoSuspend"] = task_data.IsAutoSuspend;
	data["BusinessUnit"] = task_data.BusinessUnit;
	data["BusinessType"] = task_data.BusinessType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspOrderInsert(data, error, task.task_id, task.task_last);
};

void TdApi::processRspOrderAction(Task task)
{
	PyLock lock;
	CFocusFtdcOrderActionField task_data = any_cast<CFocusFtdcOrderActionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = task_data.UserID;
	data["UserOrderLocalID"] = task_data.UserOrderLocalID;
	data["UserCustom"] = task_data.UserCustom;
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = task_data.InstrumentID;
	data["UserOrderActionLocalID"] = task_data.UserOrderActionLocalID;
	data["ActionFlag"] = task_data.ActionFlag;
	data["LimitPrice"] = task_data.LimitPrice;
	data["VolumeChange"] = task_data.VolumeChange;
	data["FrontID"] = task_data.FrontID;
	data["SessionID"] = task_data.SessionID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspOrderAction(data, error, task.task_id, task.task_last);
};

void TdApi::processRtnTrade(Task task)
{
	PyLock lock;
	CFocusFtdcTradeField task_data = any_cast<CFocusFtdcTradeField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = task_data.UserID;
	data["UserOrderLocalID"] = task_data.UserOrderLocalID;
	data["UserCustom"] = task_data.UserCustom;
	data["ExchangeID"] = task_data.ExchangeID;
	data["TradeID"] = task_data.TradeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["TradePrice"] = task_data.TradePrice;
	data["TradeVolume"] = task_data.TradeVolume;
	data["TradeTime"] = task_data.TradeTime;
	data["MarketID"] = task_data.MarketID;
	data["TradeAmnt"] = task_data.TradeAmnt;
	data["TradeType"] = task_data.TradeType;
	data["AccountID"] = task_data.AccountID;

	this->onRtnTrade(data);
};

void TdApi::processRtnOrder(Task task)
{
	PyLock lock;
	CFocusFtdcOrderField task_data = any_cast<CFocusFtdcOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = task_data.UserID;
	data["UserOrderLocalID"] = task_data.UserOrderLocalID;
	data["UserCustom"] = task_data.UserCustom;
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["OrderPriceType"] = task_data.OrderPriceType;
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["LimitPrice"] = task_data.LimitPrice;
	data["Volume"] = task_data.Volume;
	data["TimeCondition"] = task_data.TimeCondition;
	data["GTDDate"] = task_data.GTDDate;
	data["VolumeCondition"] = task_data.VolumeCondition;
	data["MinVolume"] = task_data.MinVolume;
	data["StopPrice"] = task_data.StopPrice;
	data["ForceCloseReason"] = task_data.ForceCloseReason;
	data["IsAutoSuspend"] = task_data.IsAutoSuspend;
	data["BusinessUnit"] = task_data.BusinessUnit;
	data["BusinessType"] = task_data.BusinessType;
	data["TradingDay"] = task_data.TradingDay;
	data["InsertTime"] = task_data.InsertTime;
	data["OrderSource"] = task_data.OrderSource;
	data["OrderStatus"] = task_data.OrderStatus;
	data["CancelTime"] = task_data.CancelTime;
	data["CancelUserID"] = task_data.CancelUserID;
	data["VolumeTraded"] = task_data.VolumeTraded;
	data["VolumeRemain"] = task_data.VolumeRemain;
	data["VolumeCancled"] = task_data.VolumeCancled;
	data["ErrorID"] = task_data.ErrorID;
	data["ErrorMsg"] = GBK_TO_UTF8(task_data.ErrorMsg);
	data["VolumeIncCancled"] = task_data.VolumeIncCancled;
	data["VolumeIncTraded"] = task_data.VolumeIncTraded;
	data["AccountID"] = task_data.AccountID;
	data["FrontID"] = task_data.FrontID;
	data["SessionID"] = task_data.SessionID;
	data["RequestID"] = task_data.RequestID;
	data["EachFee"] = task_data.EachFee;
	data["EachMargin"] = task_data.EachMargin;
	data["EachPremium"] = task_data.EachPremium;
	data["IPAddress"] = task_data.IPAddress;
	data["MacAddress"] = task_data.MacAddress;
	data["BranchID"] = task_data.BranchID;
	data["RecNum"] = task_data.RecNum;

	this->onRtnOrder(data);
};

void TdApi::processRtnInstrumentStatus(Task task)
{
	PyLock lock;
	CFocusFtdcInstrumentStatusField task_data = any_cast<CFocusFtdcInstrumentStatusField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ProductID"] = task_data.ProductID;
	data["ProductName"] = GBK_TO_UTF8(task_data.ProductName);
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["DeliveryYear"] = task_data.DeliveryYear;
	data["DeliveryMonth"] = task_data.DeliveryMonth;
	data["MaxLimitOrderVolume"] = task_data.MaxLimitOrderVolume;
	data["MinLimitOrderVolume"] = task_data.MinLimitOrderVolume;
	data["MaxMarketOrderVolume"] = task_data.MaxMarketOrderVolume;
	data["MinMarketOrderVolume"] = task_data.MinMarketOrderVolume;
	data["MinStkBuyQty"] = task_data.MinStkBuyQty;
	data["MinStkSellQty"] = task_data.MinStkSellQty;
	data["VolumeMultiple"] = task_data.VolumeMultiple;
	data["PriceTick"] = task_data.PriceTick;
	data["Currency"] = task_data.Currency;
	data["LongPosLimit"] = task_data.LongPosLimit;
	data["ShortPosLimit"] = task_data.ShortPosLimit;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["InstrumentStatus"] = task_data.InstrumentStatus;
	data["CreateDate"] = task_data.CreateDate;
	data["OpenDate"] = task_data.OpenDate;
	data["ExpireDate"] = task_data.ExpireDate;
	data["StartDelivDate"] = task_data.StartDelivDate;
	data["EndDelivDate"] = task_data.EndDelivDate;
	data["BasisPrice"] = task_data.BasisPrice;
	data["IsTrading"] = task_data.IsTrading;
	data["UnderlyingInstrID"] = task_data.UnderlyingInstrID;
	data["UnderlyingMultiple"] = task_data.UnderlyingMultiple;
	data["PositionType"] = task_data.PositionType;
	data["StrikePrice"] = task_data.StrikePrice;
	data["OptionsType"] = task_data.OptionsType;
	data["ExchangeRate"] = task_data.ExchangeRate;
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["ProductClass"] = task_data.ProductClass;
	data["OptionsMode"] = task_data.OptionsMode;
	data["MarginCombType"] = task_data.MarginCombType;

	this->onRtnInstrumentStatus(data);
};

void TdApi::processRtnMessageNotify(Task task)
{
	PyLock lock;
	CFocusFtdcMessageNotifyField task_data = any_cast<CFocusFtdcMessageNotifyField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = task_data.UserID;
	data["InvestorID"] = task_data.InvestorID;
	data["Nums"] = task_data.Nums;
	data["WarnLevel"] = task_data.WarnLevel;
	data["WarnID"] = task_data.WarnID;
	data["WarnMsg"] = GBK_TO_UTF8(task_data.WarnMsg);
	data["WarnTime"] = task_data.WarnTime;

	this->onRtnMessageNotify(data);
};

void TdApi::processRspQryOrder(Task task)
{
	PyLock lock;
	CFocusFtdcOrderField task_data = any_cast<CFocusFtdcOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = task_data.UserID;
	data["UserOrderLocalID"] = task_data.UserOrderLocalID;
	data["UserCustom"] = task_data.UserCustom;
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["OrderPriceType"] = task_data.OrderPriceType;
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["LimitPrice"] = task_data.LimitPrice;
	data["Volume"] = task_data.Volume;
	data["TimeCondition"] = task_data.TimeCondition;
	data["GTDDate"] = task_data.GTDDate;
	data["VolumeCondition"] = task_data.VolumeCondition;
	data["MinVolume"] = task_data.MinVolume;
	data["StopPrice"] = task_data.StopPrice;
	data["ForceCloseReason"] = task_data.ForceCloseReason;
	data["IsAutoSuspend"] = task_data.IsAutoSuspend;
	data["BusinessUnit"] = task_data.BusinessUnit;
	data["BusinessType"] = task_data.BusinessType;
	data["TradingDay"] = task_data.TradingDay;
	data["InsertTime"] = task_data.InsertTime;
	data["OrderSource"] = task_data.OrderSource;
	data["OrderStatus"] = task_data.OrderStatus;
	data["CancelTime"] = task_data.CancelTime;
	data["CancelUserID"] = task_data.CancelUserID;
	data["VolumeTraded"] = task_data.VolumeTraded;
	data["VolumeRemain"] = task_data.VolumeRemain;
	data["VolumeCancled"] = task_data.VolumeCancled;
	data["ErrorID"] = task_data.ErrorID;
	data["ErrorMsg"] = GBK_TO_UTF8(task_data.ErrorMsg);
	data["VolumeIncCancled"] = task_data.VolumeIncCancled;
	data["VolumeIncTraded"] = task_data.VolumeIncTraded;
	data["AccountID"] = task_data.AccountID;
	data["FrontID"] = task_data.FrontID;
	data["SessionID"] = task_data.SessionID;
	data["RequestID"] = task_data.RequestID;
	data["EachFee"] = task_data.EachFee;
	data["EachMargin"] = task_data.EachMargin;
	data["EachPremium"] = task_data.EachPremium;
	data["IPAddress"] = task_data.IPAddress;
	data["MacAddress"] = task_data.MacAddress;
	data["BranchID"] = task_data.BranchID;
	data["RecNum"] = task_data.RecNum;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryOrder(data, error, task.task_id, task.task_last);
};

void TdApi::processRspQryTrade(Task task)
{
	PyLock lock;
	CFocusFtdcTradeField task_data = any_cast<CFocusFtdcTradeField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = task_data.UserID;
	data["UserOrderLocalID"] = task_data.UserOrderLocalID;
	data["UserCustom"] = task_data.UserCustom;
	data["ExchangeID"] = task_data.ExchangeID;
	data["TradeID"] = task_data.TradeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["TradePrice"] = task_data.TradePrice;
	data["TradeVolume"] = task_data.TradeVolume;
	data["TradeTime"] = task_data.TradeTime;
	data["MarketID"] = task_data.MarketID;
	data["TradeAmnt"] = task_data.TradeAmnt;
	data["TradeType"] = task_data.TradeType;
	data["AccountID"] = task_data.AccountID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryTrade(data, error, task.task_id, task.task_last);
};

void TdApi::processRspQryInstrument(Task task)
{
	PyLock lock;
	CFocusFtdcRspInstrumentField task_data = any_cast<CFocusFtdcRspInstrumentField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ProductID"] = task_data.ProductID;
	data["ProductName"] = GBK_TO_UTF8(task_data.ProductName);
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["DeliveryYear"] = task_data.DeliveryYear;
	data["DeliveryMonth"] = task_data.DeliveryMonth;
	data["MaxLimitOrderVolume"] = task_data.MaxLimitOrderVolume;
	data["MinLimitOrderVolume"] = task_data.MinLimitOrderVolume;
	data["MaxMarketOrderVolume"] = task_data.MaxMarketOrderVolume;
	data["MinMarketOrderVolume"] = task_data.MinMarketOrderVolume;
	data["MinStkBuyQty"] = task_data.MinStkBuyQty;
	data["MinStkSellQty"] = task_data.MinStkSellQty;
	data["VolumeMultiple"] = task_data.VolumeMultiple;
	data["PriceTick"] = task_data.PriceTick;
	data["Currency"] = task_data.Currency;
	data["LongPosLimit"] = task_data.LongPosLimit;
	data["ShortPosLimit"] = task_data.ShortPosLimit;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["InstrumentStatus"] = task_data.InstrumentStatus;
	data["CreateDate"] = task_data.CreateDate;
	data["OpenDate"] = task_data.OpenDate;
	data["ExpireDate"] = task_data.ExpireDate;
	data["StartDelivDate"] = task_data.StartDelivDate;
	data["EndDelivDate"] = task_data.EndDelivDate;
	data["BasisPrice"] = task_data.BasisPrice;
	data["IsTrading"] = task_data.IsTrading;
	data["UnderlyingInstrID"] = task_data.UnderlyingInstrID;
	data["UnderlyingMultiple"] = task_data.UnderlyingMultiple;
	data["PositionType"] = task_data.PositionType;
	data["StrikePrice"] = task_data.StrikePrice;
	data["OptionsType"] = task_data.OptionsType;
	data["ExchangeRate"] = task_data.ExchangeRate;
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["ProductClass"] = task_data.ProductClass;
	data["OptionsMode"] = task_data.OptionsMode;
	data["MarginCombType"] = task_data.MarginCombType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInstrument(data, error, task.task_id, task.task_last);
};

void TdApi::processRspQryExchange(Task task)
{
	PyLock lock;
	CFocusFtdcRspExchangeField task_data = any_cast<CFocusFtdcRspExchangeField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ExchangeName"] = GBK_TO_UTF8(task_data.ExchangeName);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryExchange(data, error, task.task_id, task.task_last);
};

void TdApi::processRspQryInvestorPosition(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorPositionField task_data = any_cast<CFocusFtdcRspInvestorPositionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["Direction"] = task_data.Direction;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["UsedMargin"] = task_data.UsedMargin;
	data["Position"] = task_data.Position;
	data["PositionCost"] = task_data.PositionCost;
	data["YdPosition"] = task_data.YdPosition;
	data["YdPositionCost"] = task_data.YdPositionCost;
	data["FrozenMargin"] = task_data.FrozenMargin;
	data["FrozenPosition"] = task_data.FrozenPosition;
	data["FrozenClosing"] = task_data.FrozenClosing;
	data["PositionProfit"] = task_data.PositionProfit;
	data["FrozenPremium"] = task_data.FrozenPremium;
	data["LastTradeID"] = task_data.LastTradeID;
	data["LastOrderLocalID"] = task_data.LastOrderLocalID;
	data["PositionClose"] = task_data.PositionClose;
	data["YdPositionClose"] = task_data.YdPositionClose;
	data["YdFrozenClosing"] = task_data.YdFrozenClosing;
	data["OpenVolume"] = task_data.OpenVolume;
	data["CloseVolume"] = task_data.CloseVolume;
	data["CloseProfit"] = task_data.CloseProfit;
	data["PurRedVolume"] = task_data.PurRedVolume;
	data["FrozenPurRedVolume"] = task_data.FrozenPurRedVolume;
	data["FrozenOpenVolume"] = task_data.FrozenOpenVolume;
	data["CurrentStkValue"] = task_data.CurrentStkValue;
	data["OrderUnit"] = task_data.OrderUnit;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInvestorPosition(data, error, task.task_id, task.task_last);
};

void TdApi::processRspSubscribeTopic(Task task)
{
	PyLock lock;
	CFocusFtdcDisseminationField task_data = any_cast<CFocusFtdcDisseminationField>(task.task_data);
	dict data;
	data["SequenceSeries"] = task_data.SequenceSeries;
	data["SequenceNo"] = task_data.SequenceNo;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSubscribeTopic(data, error, task.task_id, task.task_last);
};

void TdApi::processRspQryTopic(Task task)
{
	PyLock lock;
	CFocusFtdcDisseminationField task_data = any_cast<CFocusFtdcDisseminationField>(task.task_data);
	dict data;
	data["SequenceSeries"] = task_data.SequenceSeries;
	data["SequenceNo"] = task_data.SequenceNo;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryTopic(data, error, task.task_id, task.task_last);
};

void TdApi::processRspQryProduct(Task task)
{
	PyLock lock;
	CFocusFtdcRspProductField task_data = any_cast<CFocusFtdcRspProductField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ProductID"] = task_data.ProductID;
	data["ProductName"] = GBK_TO_UTF8(task_data.ProductName);
	data["Currency"] = task_data.Currency;
	data["ExchangeRate"] = task_data.ExchangeRate;
	data["ProductClass"] = task_data.ProductClass;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryProduct(data, error, task.task_id, task.task_last);
};

void TdApi::processRtnStrategyLog(Task task)
{
	PyLock lock;
	CFocusFtdcStrategyLogField task_data = any_cast<CFocusFtdcStrategyLogField>(task.task_data);
	dict data;
	data["EventID"] = task_data.EventID;
	data["TradingDay"] = task_data.TradingDay;
	data["EventType"] = task_data.EventType;
	data["EventCode"] = task_data.EventCode;
	data["UserID"] = task_data.UserID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["Log_Content"] = task_data.Log_Content;
	data["OperDate"] = task_data.OperDate;
	data["OperTime"] = task_data.OperTime;

	this->onRtnStrategyLog(data);
};

void TdApi::processRtnInvestorPosition(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorPositionField task_data = any_cast<CFocusFtdcRspInvestorPositionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentName"] = GBK_TO_UTF8(task_data.InstrumentName);
	data["Direction"] = task_data.Direction;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["UsedMargin"] = task_data.UsedMargin;
	data["Position"] = task_data.Position;
	data["PositionCost"] = task_data.PositionCost;
	data["YdPosition"] = task_data.YdPosition;
	data["YdPositionCost"] = task_data.YdPositionCost;
	data["FrozenMargin"] = task_data.FrozenMargin;
	data["FrozenPosition"] = task_data.FrozenPosition;
	data["FrozenClosing"] = task_data.FrozenClosing;
	data["PositionProfit"] = task_data.PositionProfit;
	data["FrozenPremium"] = task_data.FrozenPremium;
	data["LastTradeID"] = task_data.LastTradeID;
	data["LastOrderLocalID"] = task_data.LastOrderLocalID;
	data["PositionClose"] = task_data.PositionClose;
	data["YdPositionClose"] = task_data.YdPositionClose;
	data["YdFrozenClosing"] = task_data.YdFrozenClosing;
	data["OpenVolume"] = task_data.OpenVolume;
	data["CloseVolume"] = task_data.CloseVolume;
	data["CloseProfit"] = task_data.CloseProfit;
	data["PurRedVolume"] = task_data.PurRedVolume;
	data["FrozenPurRedVolume"] = task_data.FrozenPurRedVolume;
	data["FrozenOpenVolume"] = task_data.FrozenOpenVolume;
	data["CurrentStkValue"] = task_data.CurrentStkValue;
	data["OrderUnit"] = task_data.OrderUnit;

	this->onRtnInvestorPosition(data);
};

void TdApi::processRtnParentOrder(Task task)
{
	PyLock lock;
	CFocusFtdcParentOrderField task_data = any_cast<CFocusFtdcParentOrderField>(task.task_data);
	dict data;
	data["UserID"] = task_data.UserID;
	data["InvestorID"] = task_data.InvestorID;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["AlgoStrategyType"] = task_data.AlgoStrategyType;
	data["StrategyStartDay"] = task_data.StrategyStartDay;
	data["StrategyEndDay"] = task_data.StrategyEndDay;
	data["StrategyStartTime"] = task_data.StrategyStartTime;
	data["StrategyEndTime"] = task_data.StrategyEndTime;
	data["style"] = task_data.style;
	data["maxVolumeP"] = task_data.maxVolumeP;
	data["minDisplaySize"] = task_data.minDisplaySize;
	data["displaySize"] = task_data.displaySize;
	data["countVolInLimitPx"] = task_data.countVolInLimitPx;
	data["resetVolOnAmend"] = task_data.resetVolOnAmend;
	data["limitPrice"] = task_data.limitPrice;
	data["relativePriceLimitBase"] = task_data.relativePriceLimitBase;
	data["relativePriceLimitType"] = task_data.relativePriceLimitType;
	data["relativePriceLimitOffset"] = task_data.relativePriceLimitOffset;
	data["stepSpread"] = task_data.stepSpread;
	data["optOnExtreme"] = task_data.optOnExtreme;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["Direction"] = task_data.Direction;
	data["orderQty"] = task_data.orderQty;
	data["orderAmt"] = task_data.orderAmt;
	data["TradingDay"] = task_data.TradingDay;
	data["LastOperTime"] = task_data.LastOperTime;
	data["UserCustom"] = task_data.UserCustom;
	data["Note"] = task_data.Note;
	data["StrategyID"] = task_data.StrategyID;

	this->onRtnParentOrder(data);
};

void TdApi::processRtnParentOrderAction(Task task)
{
	PyLock lock;
	CFocusFtdcParentOrderActionField task_data = any_cast<CFocusFtdcParentOrderActionField>(task.task_data);
	dict data;
	data["UserID"] = task_data.UserID;
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["StrategyID"] = task_data.StrategyID;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["ActionOption"] = task_data.ActionOption;

	this->onRtnParentOrderAction(data);
};

void TdApi::processRtnAmendParentOrder(Task task)
{
	PyLock lock;
	CFocusFtdcAmendParentOrderField task_data = any_cast<CFocusFtdcAmendParentOrderField>(task.task_data);
	dict data;
	data["UserID"] = task_data.UserID;
	data["InvestorID"] = task_data.InvestorID;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["AlgoStrategyType"] = task_data.AlgoStrategyType;
	data["StrategyStartDay"] = task_data.StrategyStartDay;
	data["StrategyEndDay"] = task_data.StrategyEndDay;
	data["StrategyStartTime"] = task_data.StrategyStartTime;
	data["StrategyEndTime"] = task_data.StrategyEndTime;
	data["style"] = task_data.style;
	data["maxVolumeP"] = task_data.maxVolumeP;
	data["minDisplaySize"] = task_data.minDisplaySize;
	data["displaySize"] = task_data.displaySize;
	data["countVolInLimitPx"] = task_data.countVolInLimitPx;
	data["resetVolOnAmend"] = task_data.resetVolOnAmend;
	data["limitPrice"] = task_data.limitPrice;
	data["relativePriceLimitBase"] = task_data.relativePriceLimitBase;
	data["relativePriceLimitType"] = task_data.relativePriceLimitType;
	data["relativePriceLimitOffset"] = task_data.relativePriceLimitOffset;
	data["stepSpread"] = task_data.stepSpread;
	data["optOnExtreme"] = task_data.optOnExtreme;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["Direction"] = task_data.Direction;
	data["orderQty"] = task_data.orderQty;
	data["orderAmt"] = task_data.orderAmt;
	data["TradingDay"] = task_data.TradingDay;
	data["LastOperTime"] = task_data.LastOperTime;
	data["UserCustom"] = task_data.UserCustom;
	data["Note"] = task_data.Note;
	data["StrategyID"] = task_data.StrategyID;

	this->onRtnAmendParentOrder(data);
};

void TdApi::processRtnExtraManualParentOrder(Task task)
{
	PyLock lock;
	CFocusFtdcExtraManualParentOrderField task_data = any_cast<CFocusFtdcExtraManualParentOrderField>(task.task_data);
	dict data;
	data["UserID"] = task_data.UserID;
	data["InvestorID"] = task_data.InvestorID;
	data["StrategyID"] = task_data.StrategyID;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["sliceQty"] = task_data.sliceQty;
	data["slicePrice"] = task_data.slicePrice;
	data["UserCustom"] = task_data.UserCustom;

	this->onRtnExtraManualParentOrder(data);
};

void TdApi::processRspQryMarketTradingTime(Task task)
{
	PyLock lock;
	CFocusFtdcMarketTradingPeriodInfoField task_data = any_cast<CFocusFtdcMarketTradingPeriodInfoField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ExchangeName"] = GBK_TO_UTF8(task_data.ExchangeName);
	data["ProductID"] = task_data.ProductID;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;
	data["Flags"] = task_data.Flags;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMarketTradingTime(data, error, task.task_id, task.task_last);
};

void TdApi::processRspBatchOrderInsert(Task task)
{
	PyLock lock;
	CFocusFtdcBatchInputOrderField task_data = any_cast<CFocusFtdcBatchInputOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = task_data.UserID;
	data["UserOrderLocalID"] = task_data.UserOrderLocalID;
	data["UserCustom"] = task_data.UserCustom;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["LimitPrice"] = task_data.LimitPrice;
	data["Volume"] = task_data.Volume;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspBatchOrderInsert(data, error, task.task_id, task.task_last);
};

void TdApi::processRspBatchOrderAction(Task task)
{
	PyLock lock;
	CFocusFtdcBatchOrderActionField task_data = any_cast<CFocusFtdcBatchOrderActionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = task_data.UserID;
	data["UserOrderLocalID"] = task_data.UserOrderLocalID;
	data["UserCustom"] = task_data.UserCustom;
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["UserOrderActionLocalID"] = task_data.UserOrderActionLocalID;
	data["FrontID"] = task_data.FrontID;
	data["SessionID"] = task_data.SessionID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspBatchOrderAction(data, error, task.task_id, task.task_last);
};

void TdApi::processRtnSpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcSpreadInstrStrategyField task_data = any_cast<CFocusFtdcSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = task_data.UserID;
	data["InvestorID"] = task_data.InvestorID;
	data["StrategyID"] = task_data.StrategyID;
	data["ExchangeIDLeg1"] = task_data.ExchangeIDLeg1;
	data["DirectionLeg1"] = task_data.DirectionLeg1;
	data["InstrLeg1"] = task_data.InstrLeg1;
	data["ExchangeIDLeg2"] = task_data.ExchangeIDLeg2;
	data["DirectionLeg2"] = task_data.DirectionLeg2;
	data["InstrLeg2"] = task_data.InstrLeg2;
	data["LegPer"] = task_data.LegPer;
	data["StartTradingTime"] = task_data.StartTradingTime;
	data["EndTradingTime"] = task_data.EndTradingTime;
	data["TimeAvail"] = task_data.TimeAvail;
	data["TargetTradeVolume"] = task_data.TargetTradeVolume;
	data["OrderPriceType"] = task_data.OrderPriceType;
	data["AlgoType"] = task_data.AlgoType;
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["EachTrdvolume"] = task_data.EachTrdvolume;
	data["StrategyIsTrading"] = task_data.StrategyIsTrading;
	data["LiquidLack"] = task_data.LiquidLack;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["Note"] = task_data.Note;

	this->onRtnSpreadInstrStrategy(data);
};

void TdApi::processRtnAmendPSpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcSpreadInstrStrategyField task_data = any_cast<CFocusFtdcSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = task_data.UserID;
	data["InvestorID"] = task_data.InvestorID;
	data["StrategyID"] = task_data.StrategyID;
	data["ExchangeIDLeg1"] = task_data.ExchangeIDLeg1;
	data["DirectionLeg1"] = task_data.DirectionLeg1;
	data["InstrLeg1"] = task_data.InstrLeg1;
	data["ExchangeIDLeg2"] = task_data.ExchangeIDLeg2;
	data["DirectionLeg2"] = task_data.DirectionLeg2;
	data["InstrLeg2"] = task_data.InstrLeg2;
	data["LegPer"] = task_data.LegPer;
	data["StartTradingTime"] = task_data.StartTradingTime;
	data["EndTradingTime"] = task_data.EndTradingTime;
	data["TimeAvail"] = task_data.TimeAvail;
	data["TargetTradeVolume"] = task_data.TargetTradeVolume;
	data["OrderPriceType"] = task_data.OrderPriceType;
	data["AlgoType"] = task_data.AlgoType;
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["EachTrdvolume"] = task_data.EachTrdvolume;
	data["StrategyIsTrading"] = task_data.StrategyIsTrading;
	data["LiquidLack"] = task_data.LiquidLack;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["Note"] = task_data.Note;

	this->onRtnAmendPSpreadInstrStrategy(data);
};





///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void TdApi::createFtdcTraderApi(string pszFlowPath)
{
	this->api = CFocusFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
};

void TdApi::release()
{
	this->api->Release();
};

void TdApi::init()
{
	this->api->Init();
};

int TdApi::join()
{
	int i = this->api->Join();
	return i;
};

int TdApi::exit()
{
	//该函数在原生API里没有，用于安全退出API用，原生的join似乎不太稳定
	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

string TdApi::getTradingDay()
{
	string day = this->api->GetTradingDay();
	return day;
};

void TdApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};

void TdApi::subscribePrivateTopic(int nType)
{
	//该函数为手动编写
	FOCUS_TE_RESUME_TYPE type;

	switch (nType)
	{
	case 0:
	{
		type = FOCUS_TERT_RESTART;
		break;
	};

	case 1:
	{
		type = FOCUS_TERT_RESUME;
		break;
	};

	case 2:
	{
		type = FOCUS_TERT_QUICK;
		break;
	};
	}

	this->api->SubscribePrivateTopic(type);
};

void TdApi::subscribePublicTopic(int nType)
{
	//该函数为手动编写
	FOCUS_TE_RESUME_TYPE type;

	switch (nType)
	{
	case 0:
	{
		type = FOCUS_TERT_RESTART;
		break;
	};

	case 1:
	{
		type = FOCUS_TERT_RESUME;
		break;
	};

	case 2:
	{
		type = FOCUS_TERT_QUICK;
		break;
	};
	}

	this->api->SubscribePublicTopic(type);
};

int TdApi::reqUserLogin(dict req, int nRequestID)
{
	CFocusFtdcReqUserLoginField myreq = CFocusFtdcReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "Password", myreq.Password);
	getStr(req, "UserProductInfo", myreq.UserProductInfo);
	getStr(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getStr(req, "ProtocolInfo", myreq.ProtocolInfo);
	getStr(req, "IPAddress", myreq.IPAddress);
	getStr(req, "MacAddress", myreq.MacAddress);
	getInt(req, "DataCenterID", &myreq.DataCenterID);
	getStr(req, "OneTimePassword", myreq.OneTimePassword);
	getStr(req, "ClientIPAddress", myreq.ClientIPAddress);
	getStr(req, "AuthCode", myreq.AuthCode);
	int i = this->api->ReqUserLogin(&myreq, nRequestID);
	return i;
};

int TdApi::reqUserLogout(dict req, int nRequestID)
{
	CFocusFtdcReqUserLogoutField myreq = CFocusFtdcReqUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int TdApi::reqOrderInsert(dict req, int nRequestID)
{
	CFocusFtdcInputOrderField myreq = CFocusFtdcInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "UserOrderLocalID", myreq.UserOrderLocalID);
	getStr(req, "UserCustom", myreq.UserCustom);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "OrderSysID", myreq.OrderSysID);
	getStr(req, "BatchNum", myreq.BatchNum);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "InstrumentName", myreq.InstrumentName);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "Volume", &myreq.Volume);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getStr(req, "GTDDate", myreq.GTDDate);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getDouble(req, "StopPrice", &myreq.StopPrice);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getInt(req, "IsAutoSuspend", &myreq.IsAutoSuspend);
	getStr(req, "BusinessUnit", myreq.BusinessUnit);
	getChar(req, "BusinessType", &myreq.BusinessType);
	int i = this->api->ReqOrderInsert(&myreq, nRequestID);
	return i;
};

int TdApi::reqOrderAction(dict req, int nRequestID)
{
	CFocusFtdcOrderActionField myreq = CFocusFtdcOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "UserOrderLocalID", myreq.UserOrderLocalID);
	getStr(req, "UserCustom", myreq.UserCustom);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "OrderSysID", myreq.OrderSysID);
	getStr(req, "BatchNum", myreq.BatchNum);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "UserOrderActionLocalID", myreq.UserOrderActionLocalID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeChange", &myreq.VolumeChange);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	int i = this->api->ReqOrderAction(&myreq, nRequestID);
	return i;
};

int TdApi::reqQryOrder(dict req, int nRequestID)
{
	CFocusFtdcQryOrderField myreq = CFocusFtdcQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "OrderSysID", myreq.OrderSysID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOrder(&myreq, nRequestID);
	return i;
};

int TdApi::reqQryTrade(dict req, int nRequestID)
{
	CFocusFtdcQryTradeField myreq = CFocusFtdcQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "TradeID", myreq.TradeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryTrade(&myreq, nRequestID);
	return i;
};

int TdApi::reqQryInstrument(dict req, int nRequestID)
{
	CFocusFtdcQryInstrumentField myreq = CFocusFtdcQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrument(&myreq, nRequestID);
	return i;
};

int TdApi::reqQryExchange(dict req, int nRequestID)
{
	CFocusFtdcQryExchangeField myreq = CFocusFtdcQryExchangeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQryExchange(&myreq, nRequestID);
	return i;
};

int TdApi::reqQryInvestorPosition(dict req, int nRequestID)
{
	CFocusFtdcQryInvestorPositionField myreq = CFocusFtdcQryInvestorPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorPosition(&myreq, nRequestID);
	return i;
};

int TdApi::reqSubscribeTopic(dict req, int nRequestID)
{
	CFocusFtdcDisseminationField myreq = CFocusFtdcDisseminationField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "SequenceSeries", &myreq.SequenceSeries);
	getInt(req, "SequenceNo", &myreq.SequenceNo);
	int i = this->api->ReqSubscribeTopic(&myreq, nRequestID);
	return i;
};

int TdApi::reqQryTopic(dict req, int nRequestID)
{
	CFocusFtdcDisseminationField myreq = CFocusFtdcDisseminationField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "SequenceSeries", &myreq.SequenceSeries);
	getInt(req, "SequenceNo", &myreq.SequenceNo);
	int i = this->api->ReqQryTopic(&myreq, nRequestID);
	return i;
};

int TdApi::reqQryProduct(dict req, int nRequestID)
{
	CFocusFtdcQryProductField myreq = CFocusFtdcQryProductField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryProduct(&myreq, nRequestID);
	return i;
};

int TdApi::reqSetParentDetialUpdateMessage(dict req, int nRequestID)
{
	CFocusFtdcParentDetialUpdateMessageField myreq = CFocusFtdcParentDetialUpdateMessageField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	getStr(req, "AlgoParentOrderSysID", myreq.AlgoParentOrderSysID);
	getStr(req, "transactDay", myreq.transactDay);
	getStr(req, "transactTime", myreq.transactTime);
	getInt(req, "strategyStatus", &myreq.strategyStatus);
	getStr(req, "pauseReason", myreq.pauseReason);
	getChar(req, "Direction", &myreq.Direction);
	getInt(req, "orderQty", &myreq.orderQty);
	getInt(req, "knockQty", &myreq.knockQty);
	getDouble(req, "knockAmt", &myreq.knockAmt);
	getDouble(req, "knockAmtWithFee", &myreq.knockAmtWithFee);
	getInt(req, "orderStatus", &myreq.orderStatus);
	getDouble(req, "avgPrice", &myreq.avgPrice);
	getDouble(req, "marketTwap", &myreq.marketTwap);
	getDouble(req, "marketVwap", &myreq.marketVwap);
	getDouble(req, "arrivalPrice", &myreq.arrivalPrice);
	getDouble(req, "avgOffset_T", &myreq.avgOffset_T);
	getDouble(req, "avgOffset_V", &myreq.avgOffset_V);
	getDouble(req, "avgOffset_A", &myreq.avgOffset_A);
	getDouble(req, "realParticipateRate", &myreq.realParticipateRate);
	getDouble(req, "cancelRate", &myreq.cancelRate);
	getDouble(req, "avgOpenTime", &myreq.avgOpenTime);
	getDouble(req, "passiveRate", &myreq.passiveRate);
	getStr(req, "serialNum", myreq.serialNum);
	getStr(req, "failReason", myreq.failReason);
	getDouble(req, "targetProgress", &myreq.targetProgress);
	getDouble(req, "knockPercent", &myreq.knockPercent);
	getDouble(req, "progressOffset", &myreq.progressOffset);
	getInt(req, "pushFlag", &myreq.pushFlag);
	getInt(req, "ErrorID", &myreq.ErrorID);
	getInt(req, "FunctionID", &myreq.FunctionID);
	getStr(req, "StrategyStartTime", myreq.StrategyStartTime);
	getStr(req, "StrategyEndTime", myreq.StrategyEndTime);
	int i = this->api->ReqSetParentDetialUpdateMessage(&myreq, nRequestID);
	return i;
};

int TdApi::reqQryMarketTradingTime(dict req, int nRequestID)
{
	CFocusFtdcAPIQryMarketTradingTimeField myreq = CFocusFtdcAPIQryMarketTradingTimeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "ExchangeName", myreq.ExchangeName);
	getStr(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryMarketTradingTime(&myreq, nRequestID);
	return i;
};

int TdApi::reqSetJavaAlgoStatus(dict req, int nRequestID)
{
	CFocusFtdcFocusStatusField myreq = CFocusFtdcFocusStatusField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "TradeStatus", &myreq.TradeStatus);
	int i = this->api->ReqSetJavaAlgoStatus(&myreq, nRequestID);
	return i;
};

int TdApi::reqBatchOrderInsert(dict req, int nRequestID)
{
	CFocusFtdcBatchInputOrderField myreq = CFocusFtdcBatchInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "UserOrderLocalID", myreq.UserOrderLocalID);
	getStr(req, "UserCustom", myreq.UserCustom);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "Direction", myreq.Direction);
	getStr(req, "OffsetFlag", myreq.OffsetFlag);
	getStr(req, "LimitPrice", myreq.LimitPrice);
	getStr(req, "Volume", myreq.Volume);
	int i = this->api->ReqBatchOrderInsert(&myreq, nRequestID);
	return i;
};

int TdApi::reqBatchOrderAction(dict req, int nRequestID)
{
	CFocusFtdcBatchOrderActionField myreq = CFocusFtdcBatchOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "UserOrderLocalID", myreq.UserOrderLocalID);
	getStr(req, "UserCustom", myreq.UserCustom);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "OrderSysID", myreq.OrderSysID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "UserOrderActionLocalID", myreq.UserOrderActionLocalID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	int i = this->api->ReqBatchOrderAction(&myreq, nRequestID);
	return i;
};



///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

struct TdApiWrap : TdApi, wrapper < TdApi >
{
	virtual void onFrontConnected()
	{
			PyLock lock;
		try
		{
			this->get_override("onFrontConnected")();
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onFrontDisconnected(int i)
	{
			PyLock lock;
		try
		{
			this->get_override("onFrontDisconnected")(i);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onHeartBeatWarning(int i)
	{
			PyLock lock;
		try
		{
			this->get_override("onHeartBeatWarning")(i);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspError(dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspError")(error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspUserLogin(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspUserLogin")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspUserLogout(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspUserLogout")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspOrderInsert(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspOrderInsert")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspOrderAction(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspOrderAction")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnTrade(dict data)
	{
		try
		{
			this->get_override("onRtnTrade")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnOrder(dict data)
	{
		try
		{
			this->get_override("onRtnOrder")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnInstrumentStatus(dict data)
	{
		try
		{
			this->get_override("onRtnInstrumentStatus")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnMessageNotify(dict data)
	{
		try
		{
			this->get_override("onRtnMessageNotify")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryOrder(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryOrder")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryTrade(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryTrade")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInstrument(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInstrument")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryExchange(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryExchange")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInvestorPosition(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInvestorPosition")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSubscribeTopic(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSubscribeTopic")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryTopic(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryTopic")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryProduct(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryProduct")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnStrategyLog(dict data)
	{
		try
		{
			this->get_override("onRtnStrategyLog")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnInvestorPosition(dict data)
	{
		try
		{
			this->get_override("onRtnInvestorPosition")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnParentOrder(dict data)
	{
		try
		{
			this->get_override("onRtnParentOrder")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnParentOrderAction(dict data)
	{
		try
		{
			this->get_override("onRtnParentOrderAction")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnAmendParentOrder(dict data)
	{
		try
		{
			this->get_override("onRtnAmendParentOrder")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnExtraManualParentOrder(dict data)
	{
		try
		{
			this->get_override("onRtnExtraManualParentOrder")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryMarketTradingTime(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryMarketTradingTime")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspBatchOrderInsert(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspBatchOrderInsert")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspBatchOrderAction(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspBatchOrderAction")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnSpreadInstrStrategy(dict data)
	{
		try
		{
			this->get_override("onRtnSpreadInstrStrategy")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnAmendPSpreadInstrStrategy(dict data)
	{
		try
		{
			this->get_override("onRtnAmendPSpreadInstrStrategy")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};


};

BOOST_PYTHON_MODULE(vnfemastd)
{
	PyEval_InitThreads();	//导入时运行，保证先创建GIL

	class_<TdApiWrap, boost::noncopyable>("TdApi")
		.def("createFtdcTraderApi", &TdApiWrap::createFtdcTraderApi)
		.def("release", &TdApiWrap::release)
		.def("init", &TdApiWrap::init)
		.def("join", &TdApiWrap::join)
		.def("exit", &TdApiWrap::exit)
		.def("getTradingDay", &TdApiWrap::getTradingDay)
		.def("registerFront", &TdApiWrap::registerFront)
		.def("subscribePrivateTopic", &TdApiWrap::subscribePrivateTopic)
		.def("subscribePublicTopic", &TdApiWrap::subscribePublicTopic)
		.def("onFrontConnected", pure_virtual(&TdApiWrap::onFrontConnected))
		.def("onFrontDisconnected", pure_virtual(&TdApiWrap::onFrontDisconnected))
		.def("onHeartBeatWarning", pure_virtual(&TdApiWrap::onHeartBeatWarning))
		.def("onRspError", pure_virtual(&TdApiWrap::onRspError))
		.def("onRspUserLogin", pure_virtual(&TdApiWrap::onRspUserLogin))
		.def("onRspUserLogout", pure_virtual(&TdApiWrap::onRspUserLogout))
		.def("onRspOrderInsert", pure_virtual(&TdApiWrap::onRspOrderInsert))
		.def("onRspOrderAction", pure_virtual(&TdApiWrap::onRspOrderAction))
		.def("onRtnTrade", pure_virtual(&TdApiWrap::onRtnTrade))
		.def("onRtnOrder", pure_virtual(&TdApiWrap::onRtnOrder))
		.def("onRtnInstrumentStatus", pure_virtual(&TdApiWrap::onRtnInstrumentStatus))
		.def("onRtnMessageNotify", pure_virtual(&TdApiWrap::onRtnMessageNotify))
		.def("onRspQryOrder", pure_virtual(&TdApiWrap::onRspQryOrder))
		.def("onRspQryTrade", pure_virtual(&TdApiWrap::onRspQryTrade))
		.def("onRspQryInstrument", pure_virtual(&TdApiWrap::onRspQryInstrument))
		.def("onRspQryExchange", pure_virtual(&TdApiWrap::onRspQryExchange))
		.def("onRspQryInvestorPosition", pure_virtual(&TdApiWrap::onRspQryInvestorPosition))
		.def("onRspSubscribeTopic", pure_virtual(&TdApiWrap::onRspSubscribeTopic))
		.def("onRspQryTopic", pure_virtual(&TdApiWrap::onRspQryTopic))
		.def("onRspQryProduct", pure_virtual(&TdApiWrap::onRspQryProduct))
		.def("onRtnStrategyLog", pure_virtual(&TdApiWrap::onRtnStrategyLog))
		.def("onRtnInvestorPosition", pure_virtual(&TdApiWrap::onRtnInvestorPosition))
		.def("onRtnParentOrder", pure_virtual(&TdApiWrap::onRtnParentOrder))
		.def("onRtnParentOrderAction", pure_virtual(&TdApiWrap::onRtnParentOrderAction))
		.def("onRtnAmendParentOrder", pure_virtual(&TdApiWrap::onRtnAmendParentOrder))
		.def("onRtnExtraManualParentOrder", pure_virtual(&TdApiWrap::onRtnExtraManualParentOrder))
		.def("onRspQryMarketTradingTime", pure_virtual(&TdApiWrap::onRspQryMarketTradingTime))
		.def("onRspBatchOrderInsert", pure_virtual(&TdApiWrap::onRspBatchOrderInsert))
		.def("onRspBatchOrderAction", pure_virtual(&TdApiWrap::onRspBatchOrderAction))
		.def("onRtnSpreadInstrStrategy", pure_virtual(&TdApiWrap::onRtnSpreadInstrStrategy))
		.def("onRtnAmendPSpreadInstrStrategy", pure_virtual(&TdApiWrap::onRtnAmendPSpreadInstrStrategy))
		.def("reqUserLogin", &TdApiWrap::reqUserLogin)
		.def("reqUserLogout", &TdApiWrap::reqUserLogout)
		.def("reqOrderInsert", &TdApiWrap::reqOrderInsert)
		.def("reqOrderAction", &TdApiWrap::reqOrderAction)
		.def("reqQryOrder", &TdApiWrap::reqQryOrder)
		.def("reqQryTrade", &TdApiWrap::reqQryTrade)
		.def("reqQryInstrument", &TdApiWrap::reqQryInstrument)
		.def("reqQryExchange", &TdApiWrap::reqQryExchange)
		.def("reqQryInvestorPosition", &TdApiWrap::reqQryInvestorPosition)
		.def("reqSubscribeTopic", &TdApiWrap::reqSubscribeTopic)
		.def("reqQryTopic", &TdApiWrap::reqQryTopic)
		.def("reqQryProduct", &TdApiWrap::reqQryProduct)
		.def("reqSetParentDetialUpdateMessage", &TdApiWrap::reqSetParentDetialUpdateMessage)
		.def("reqQryMarketTradingTime", &TdApiWrap::reqQryMarketTradingTime)
		.def("reqSetJavaAlgoStatus", &TdApiWrap::reqSetJavaAlgoStatus)
		.def("reqBatchOrderInsert", &TdApiWrap::reqBatchOrderInsert)
		.def("reqBatchOrderAction", &TdApiWrap::reqBatchOrderAction)

		;
}
