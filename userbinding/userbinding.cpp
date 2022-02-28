// userbinding.cpp : 定义 DLL 应用程序的导出函数。
//

#include "userbinding.h"


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
void UserApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void UserApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nReason;
	this->task_queue.push(task);
};

void UserApi::OnHeartBeatWarning(int nTimeLapse)
{
	Task task = Task();
	task.task_name = ONHEARTBEATWARNING;
	task.task_id = nTimeLapse;
	this->task_queue.push(task);
};

void UserApi::OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUSERPASSWORDUPDATE;

	if (pUserPasswordUpdate)
	{
		task.task_data = *pUserPasswordUpdate;
	}
	else
	{
		CFocusFtdcUserPasswordUpdateField empty_data = CFocusFtdcUserPasswordUpdateField();
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

void UserApi::OnRspForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPFORCEUSEREXIT;

	if (pForceUserExit)
	{
		task.task_data = *pForceUserExit;
	}
	else
	{
		CFocusFtdcForceUserExitField empty_data = CFocusFtdcForceUserExitField();
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

void UserApi::OnRspForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPFORCEUSERLOGOUT;

	if (pForceUserExit)
	{
		task.task_data = *pForceUserExit;
	}
	else
	{
		CFocusFtdcForceUserExitField empty_data = CFocusFtdcForceUserExitField();
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

void UserApi::OnRspDumpMemDB(CFocusFtdcMemDBField *pMemDB, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDUMPMEMDB;

	if (pMemDB)
	{
		task.task_data = *pMemDB;
	}
	else
	{
		CFocusFtdcMemDBField empty_data = CFocusFtdcMemDBField();
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

void UserApi::OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspAccountDeposit(CFocusFtdcRspAccountDepositField *pRspAccountDeposit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPACCOUNTDEPOSIT;

	if (pRspAccountDeposit)
	{
		task.task_data = *pRspAccountDeposit;
	}
	else
	{
		CFocusFtdcRspAccountDepositField empty_data = CFocusFtdcRspAccountDepositField();
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

void UserApi::OnRspInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPINVESTORRIGHT;

	if (pInvestorRight)
	{
		task.task_data = *pInvestorRight;
	}
	else
	{
		CFocusFtdcInvestorRightField empty_data = CFocusFtdcInvestorRightField();
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

void UserApi::OnRspTBCommand(CFocusFtdcTBCommandField *pTBCommand, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPTBCOMMAND;

	if (pTBCommand)
	{
		task.task_data = *pTBCommand;
	}
	else
	{
		CFocusFtdcTBCommandField empty_data = CFocusFtdcTBCommandField();
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

void UserApi::OnRspPingPong(CFocusFtdcPingPongField *pPingPong, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPPINGPONG;

	if (pPingPong)
	{
		task.task_data = *pPingPong;
	}
	else
	{
		CFocusFtdcPingPongField empty_data = CFocusFtdcPingPongField();
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

void UserApi::OnRspSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETADVICERUNMODE;

	if (pAdviceRunMode)
	{
		task.task_data = *pAdviceRunMode;
	}
	else
	{
		CFocusFtdcAdviceRunModeField empty_data = CFocusFtdcAdviceRunModeField();
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

void UserApi::OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNDEPTHMARKETDATA;

	if (pDepthMarketData)
	{
		task.task_data = *pDepthMarketData;
	}
	else
	{
		CFocusFtdcDepthMarketDataField empty_data = CFocusFtdcDepthMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnMultiDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNMULTIDEPTHMARKETDATA;

	if (pDepthMarketData)
	{
		task.task_data = *pDepthMarketData;
	}
	else
	{
		CFocusFtdcDepthMarketDataField empty_data = CFocusFtdcDepthMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSUBMARKETDATA;

	if (pSpecificInstrument)
	{
		task.task_data = *pSpecificInstrument;
	}
	else
	{
		CFocusFtdcSpecificInstrumentField empty_data = CFocusFtdcSpecificInstrumentField();
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

void UserApi::OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBMARKETDATA;

	if (pSpecificInstrument)
	{
		task.task_data = *pSpecificInstrument;
	}
	else
	{
		CFocusFtdcSpecificInstrumentField empty_data = CFocusFtdcSpecificInstrumentField();
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

void UserApi::OnRspTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPTOPICSEARCH;

	if (pTopicSearch)
	{
		task.task_data = *pTopicSearch;
	}
	else
	{
		CFocusFtdcTopicSearchField empty_data = CFocusFtdcTopicSearchField();
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

void UserApi::OnRtnMBLMarketData(CFocusFtdcMBLMarketDataField *pMBLMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNMBLMARKETDATA;

	if (pMBLMarketData)
	{
		task.task_data = *pMBLMarketData;
	}
	else
	{
		CFocusFtdcMBLMarketDataField empty_data = CFocusFtdcMBLMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnQmdInstrumentStatu(CFocusFtdcQmdInstrumentStateField *pQmdInstrumentState) 
{
	Task task = Task();
	task.task_name = ONRTNQMDINSTRUMENTSTATU;

	if (pQmdInstrumentState)
	{
		task.task_data = *pQmdInstrumentState;
	}
	else
	{
		CFocusFtdcQmdInstrumentStateField empty_data = CFocusFtdcQmdInstrumentStateField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnFlowMessageCancel(CFocusFtdcFlowMessageCancelField *pFlowMessageCancel) 
{
	Task task = Task();
	task.task_name = ONRTNFLOWMESSAGECANCEL;

	if (pFlowMessageCancel)
	{
		task.task_data = *pFlowMessageCancel;
	}
	else
	{
		CFocusFtdcFlowMessageCancelField empty_data = CFocusFtdcFlowMessageCancelField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnTrade(CFocusFtdcTradeField *pTrade) 
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

void UserApi::OnRtnOrder(CFocusFtdcOrderField *pOrder) 
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

void UserApi::OnErrRtnOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo) 
{
	Task task = Task();
	task.task_name = ONERRRTNORDERINSERT;

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
	this->task_queue.push(task);
};

void UserApi::OnErrRtnOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo) 
{
	Task task = Task();
	task.task_name = ONERRRTNORDERACTION;

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
	this->task_queue.push(task);
};

void UserApi::OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) 
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

void UserApi::OnRtnInvestorAccountDeposit(CFocusFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) 
{
	Task task = Task();
	task.task_name = ONRTNINVESTORACCOUNTDEPOSIT;

	if (pInvestorAccountDepositRes)
	{
		task.task_data = *pInvestorAccountDepositRes;
	}
	else
	{
		CFocusFtdcInvestorAccountDepositResField empty_data = CFocusFtdcInvestorAccountDepositResField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) 
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

void UserApi::OnRtnAdviceOrder(CFocusFtdcAdviceOrderField *pAdviceOrder) 
{
	Task task = Task();
	task.task_name = ONRTNADVICEORDER;

	if (pAdviceOrder)
	{
		task.task_data = *pAdviceOrder;
	}
	else
	{
		CFocusFtdcAdviceOrderField empty_data = CFocusFtdcAdviceOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnSubInstrumentStatus(CFocusFtdcSubInstrumentStatusField *pSubInstrumentStatus) 
{
	Task task = Task();
	task.task_name = ONRTNSUBINSTRUMENTSTATUS;

	if (pSubInstrumentStatus)
	{
		task.task_data = *pSubInstrumentStatus;
	}
	else
	{
		CFocusFtdcSubInstrumentStatusField empty_data = CFocusFtdcSubInstrumentStatusField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspQryUserInvestor(CFocusFtdcRspUserInvestorField *pRspUserInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYUSERINVESTOR;

	if (pRspUserInvestor)
	{
		task.task_data = *pRspUserInvestor;
	}
	else
	{
		CFocusFtdcRspUserInvestorField empty_data = CFocusFtdcRspUserInvestorField();
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

void UserApi::OnRspQryInvestorAccount(CFocusFtdcRspInvestorAccountField *pRspInvestorAccount, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORACCOUNT;

	if (pRspInvestorAccount)
	{
		task.task_data = *pRspInvestorAccount;
	}
	else
	{
		CFocusFtdcRspInvestorAccountField empty_data = CFocusFtdcRspInvestorAccountField();
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

void UserApi::OnRspQryInstrument(CFocusFtdcRspInstrumentField *pRspInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspQryExchange(CFocusFtdcRspExchangeField *pRspExchange, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspQryInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspQryUser(CFocusFtdcRspUserField *pRspUser, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYUSER;

	if (pRspUser)
	{
		task.task_data = *pRspUser;
	}
	else
	{
		CFocusFtdcRspUserField empty_data = CFocusFtdcRspUserField();
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

void UserApi::OnRspQryInvestorFee(CFocusFtdcRspInvestorFeeField *pRspInvestorFee, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORFEE;

	if (pRspInvestorFee)
	{
		task.task_data = *pRspInvestorFee;
	}
	else
	{
		CFocusFtdcRspInvestorFeeField empty_data = CFocusFtdcRspInvestorFeeField();
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

void UserApi::OnRspQryInvestorMargin(CFocusFtdcRspInvestorMarginField *pRspInvestorMargin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORMARGIN;

	if (pRspInvestorMargin)
	{
		task.task_data = *pRspInvestorMargin;
	}
	else
	{
		CFocusFtdcRspInvestorMarginField empty_data = CFocusFtdcRspInvestorMarginField();
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

void UserApi::OnRspQryInvestor(CFocusFtdcRspInvestorField *pRspInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTOR;

	if (pRspInvestor)
	{
		task.task_data = *pRspInvestor;
	}
	else
	{
		CFocusFtdcRspInvestorField empty_data = CFocusFtdcRspInvestorField();
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

void UserApi::OnRspQryAccountRisk(CFocusFtdcRspAccountRiskField *pRspAccountRisk, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTRISK;

	if (pRspAccountRisk)
	{
		task.task_data = *pRspAccountRisk;
	}
	else
	{
		CFocusFtdcRspAccountRiskField empty_data = CFocusFtdcRspAccountRiskField();
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

void UserApi::OnRspQryUserSession(CFocusFtdcRspUserSessionField *pRspUserSession, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYUSERSESSION;

	if (pRspUserSession)
	{
		task.task_data = *pRspUserSession;
	}
	else
	{
		CFocusFtdcRspUserSessionField empty_data = CFocusFtdcRspUserSessionField();
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

void UserApi::OnRspQryMarketData(CFocusFtdcRspMarketDataField *pRspMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKETDATA;

	if (pRspMarketData)
	{
		task.task_data = *pRspMarketData;
	}
	else
	{
		CFocusFtdcRspMarketDataField empty_data = CFocusFtdcRspMarketDataField();
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

void UserApi::OnRspQryInvestorRelation(CFocusFtdcRspInvestorRelationField *pRspInvestorRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORRELATION;

	if (pRspInvestorRelation)
	{
		task.task_data = *pRspInvestorRelation;
	}
	else
	{
		CFocusFtdcRspInvestorRelationField empty_data = CFocusFtdcRspInvestorRelationField();
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

void UserApi::OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspQryAdviceTrader(CFocusFtdcRspAdviceTraderField *pRspAdviceTrader, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYADVICETRADER;

	if (pRspAdviceTrader)
	{
		task.task_data = *pRspAdviceTrader;
	}
	else
	{
		CFocusFtdcRspAdviceTraderField empty_data = CFocusFtdcRspAdviceTraderField();
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

void UserApi::OnRspQryMaxVolume(CFocusFtdcRspMaxVolumeField *pRspMaxVolume, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMAXVOLUME;

	if (pRspMaxVolume)
	{
		task.task_data = *pRspMaxVolume;
	}
	else
	{
		CFocusFtdcRspMaxVolumeField empty_data = CFocusFtdcRspMaxVolumeField();
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

void UserApi::OnRspQryCmbPositionDetail(CFocusFtdcRspCmbPositionDetailField *pRspCmbPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYCMBPOSITIONDETAIL;

	if (pRspCmbPositionDetail)
	{
		task.task_data = *pRspCmbPositionDetail;
	}
	else
	{
		CFocusFtdcRspCmbPositionDetailField empty_data = CFocusFtdcRspCmbPositionDetailField();
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

void UserApi::OnRspQrySettlementInfo(CFocusFtdcRspSettlementInfoField *pRspSettlementInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYSETTLEMENTINFO;

	if (pRspSettlementInfo)
	{
		task.task_data = *pRspSettlementInfo;
	}
	else
	{
		CFocusFtdcRspSettlementInfoField empty_data = CFocusFtdcRspSettlementInfoField();
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

void UserApi::OnRspSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSUBINSTRUMENT;

	if (pSubSpecificInstrument)
	{
		task.task_data = *pSubSpecificInstrument;
	}
	else
	{
		CFocusFtdcSubSpecificInstrumentField empty_data = CFocusFtdcSubSpecificInstrumentField();
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

void UserApi::OnRspUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBINSTRUMENT;

	if (pSubSpecificInstrument)
	{
		task.task_data = *pSubSpecificInstrument;
	}
	else
	{
		CFocusFtdcSubSpecificInstrumentField empty_data = CFocusFtdcSubSpecificInstrumentField();
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

void UserApi::OnRspQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYRESULTPAGE;

	if (pQryResultPage)
	{
		task.task_data = *pQryResultPage;
	}
	else
	{
		CFocusFtdcQryResultPageField empty_data = CFocusFtdcQryResultPageField();
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

void UserApi::OnRspQryInvestorPositionDetail(CFocusFtdcRspPositionDetailField *pRspPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORPOSITIONDETAIL;

	if (pRspPositionDetail)
	{
		task.task_data = *pRspPositionDetail;
	}
	else
	{
		CFocusFtdcRspPositionDetailField empty_data = CFocusFtdcRspPositionDetailField();
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

void UserApi::OnRtnTheoryPriceData(CFocusFtdcTheoryPriceDataField *pTheoryPriceData) 
{
	Task task = Task();
	task.task_name = ONRTNTHEORYPRICEDATA;

	if (pTheoryPriceData)
	{
		task.task_data = *pTheoryPriceData;
	}
	else
	{
		CFocusFtdcTheoryPriceDataField empty_data = CFocusFtdcTheoryPriceDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnOptionIndexData(CFocusFtdcOptionIndexDataField *pOptionIndexData) 
{
	Task task = Task();
	task.task_name = ONRTNOPTIONINDEXDATA;

	if (pOptionIndexData)
	{
		task.task_data = *pOptionIndexData;
	}
	else
	{
		CFocusFtdcOptionIndexDataField empty_data = CFocusFtdcOptionIndexDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETPRICINGPARAM;

	if (pPricingParam)
	{
		task.task_data = *pPricingParam;
	}
	else
	{
		CFocusFtdcPricingParamField empty_data = CFocusFtdcPricingParamField();
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

void UserApi::OnRspSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETOPTIONTHEORYVOL;

	if (pOptionTheoryVol)
	{
		task.task_data = *pOptionTheoryVol;
	}
	else
	{
		CFocusFtdcOptionTheoryVolField empty_data = CFocusFtdcOptionTheoryVolField();
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

void UserApi::OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPCALCONEOPTION;

	if (pBasePricingParam)
	{
		task.task_data = *pBasePricingParam;
	}
	else
	{
		CFocusFtdcBasePricingParamField empty_data = CFocusFtdcBasePricingParamField();
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

void UserApi::OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPCALCBARRIEROPTION;

	if (pDoubleBarrierPricingParam)
	{
		task.task_data = *pDoubleBarrierPricingParam;
	}
	else
	{
		CFocusFtdcDoubleBarrierPricingParamField empty_data = CFocusFtdcDoubleBarrierPricingParamField();
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

void UserApi::OnRspVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPVOLATILITYFITTING;

	if (pVolatilityFitting)
	{
		task.task_data = *pVolatilityFitting;
	}
	else
	{
		CFocusFtdcVolatilityFittingField empty_data = CFocusFtdcVolatilityFittingField();
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

void UserApi::OnRspQryWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYWINGMODELPARAM;

	if (pWingModelParam)
	{
		task.task_data = *pWingModelParam;
	}
	else
	{
		CFocusFtdcWingModelParamField empty_data = CFocusFtdcWingModelParamField();
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

void UserApi::OnRspSetWingModelParam(CFocusFtdcWingModelParamField *pWingModelParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETWINGMODELPARAM;

	if (pWingModelParam)
	{
		task.task_data = *pWingModelParam;
	}
	else
	{
		CFocusFtdcWingModelParamField empty_data = CFocusFtdcWingModelParamField();
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

void UserApi::OnRtnQuoteTotalTradePrice(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice) 
{
	Task task = Task();
	task.task_name = ONRTNQUOTETOTALTRADEPRICE;

	if (pQuoteTotalTradePrice)
	{
		task.task_data = *pQuoteTotalTradePrice;
	}
	else
	{
		CFocusFtdcQuoteTotalTradePriceField empty_data = CFocusFtdcQuoteTotalTradePriceField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspQryMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKERSTRATEGYSET;

	if (pMarkerStrategy)
	{
		task.task_data = *pMarkerStrategy;
	}
	else
	{
		CFocusFtdcMarkerStrategyField empty_data = CFocusFtdcMarkerStrategyField();
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

void UserApi::OnRspUpMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUPMARKERSTRATEGYSET;

	if (pMarkerStrategy)
	{
		task.task_data = *pMarkerStrategy;
	}
	else
	{
		CFocusFtdcMarkerStrategyField empty_data = CFocusFtdcMarkerStrategyField();
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

void UserApi::OnRspQryUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYUSERSWITCH;

	if (pUserSwitch)
	{
		task.task_data = *pUserSwitch;
	}
	else
	{
		CFocusFtdcUserSwitchField empty_data = CFocusFtdcUserSwitchField();
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

void UserApi::OnRspUserSwitch(CFocusFtdcUserSwitchField *pUserSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUSERSWITCH;

	if (pUserSwitch)
	{
		task.task_data = *pUserSwitch;
	}
	else
	{
		CFocusFtdcUserSwitchField empty_data = CFocusFtdcUserSwitchField();
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

void UserApi::OnRspQryMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKERHEDGE;

	if (pMarkerHedge)
	{
		task.task_data = *pMarkerHedge;
	}
	else
	{
		CFocusFtdcMarkerHedgeField empty_data = CFocusFtdcMarkerHedgeField();
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

void UserApi::OnRspUpMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUPMARKERHEDGE;

	if (pMarkerHedge)
	{
		task.task_data = *pMarkerHedge;
	}
	else
	{
		CFocusFtdcMarkerHedgeField empty_data = CFocusFtdcMarkerHedgeField();
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

void UserApi::OnRspQryFittingParam(CFocusFtdcFittingParamField *pFittingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYFITTINGPARAM;

	if (pFittingParam)
	{
		task.task_data = *pFittingParam;
	}
	else
	{
		CFocusFtdcFittingParamField empty_data = CFocusFtdcFittingParamField();
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

void UserApi::OnRspSetFittingParam(CFocusFtdcFittingParamField *pFittingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETFITTINGPARAM;

	if (pFittingParam)
	{
		task.task_data = *pFittingParam;
	}
	else
	{
		CFocusFtdcFittingParamField empty_data = CFocusFtdcFittingParamField();
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

void UserApi::OnRspQryPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYPRICINGPARAM;

	if (pPricingParam)
	{
		task.task_data = *pPricingParam;
	}
	else
	{
		CFocusFtdcPricingParamField empty_data = CFocusFtdcPricingParamField();
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

void UserApi::OnRspQryOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTIONTHEORYVOL;

	if (pOptionTheoryVol)
	{
		task.task_data = *pOptionTheoryVol;
	}
	else
	{
		CFocusFtdcOptionTheoryVolField empty_data = CFocusFtdcOptionTheoryVolField();
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

void UserApi::OnRspQuoteInsert(CFocusFtdcInputQuoteField *pInputQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQUOTEINSERT;

	if (pInputQuote)
	{
		task.task_data = *pInputQuote;
	}
	else
	{
		CFocusFtdcInputQuoteField empty_data = CFocusFtdcInputQuoteField();
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

void UserApi::OnRspQuoteAction(CFocusFtdcQuoteActionField *pQuoteAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQUOTEACTION;

	if (pQuoteAction)
	{
		task.task_data = *pQuoteAction;
	}
	else
	{
		CFocusFtdcQuoteActionField empty_data = CFocusFtdcQuoteActionField();
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

void UserApi::OnRspQryQuote(CFocusFtdcQuoteField *pQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYQUOTE;

	if (pQuote)
	{
		task.task_data = *pQuote;
	}
	else
	{
		CFocusFtdcQuoteField empty_data = CFocusFtdcQuoteField();
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

void UserApi::OnRtnQuote(CFocusFtdcQuoteField *pQuote) 
{
	Task task = Task();
	task.task_name = ONRTNQUOTE;

	if (pQuote)
	{
		task.task_data = *pQuote;
	}
	else
	{
		CFocusFtdcQuoteField empty_data = CFocusFtdcQuoteField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPFORQUOTE;

	if (pInputReqForQuote)
	{
		task.task_data = *pInputReqForQuote;
	}
	else
	{
		CFocusFtdcInputReqForQuoteField empty_data = CFocusFtdcInputReqForQuoteField();
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

void UserApi::OnRtnForQuote(CFocusFtdcInputReqForQuoteField *pInputReqForQuote) 
{
	Task task = Task();
	task.task_name = ONRTNFORQUOTE;

	if (pInputReqForQuote)
	{
		task.task_data = *pInputReqForQuote;
	}
	else
	{
		CFocusFtdcInputReqForQuoteField empty_data = CFocusFtdcInputReqForQuoteField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspQryOrderInsertFailed(CFocusFtdcOrderInsertFailedField *pOrderInsertFailed, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERINSERTFAILED;

	if (pOrderInsertFailed)
	{
		task.task_data = *pOrderInsertFailed;
	}
	else
	{
		CFocusFtdcOrderInsertFailedField empty_data = CFocusFtdcOrderInsertFailedField();
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

void UserApi::OnRspCleanQuoteThresHold(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPCLEANQUOTETHRESHOLD;

	if (pQuoteTotalTradePrice)
	{
		task.task_data = *pQuoteTotalTradePrice;
	}
	else
	{
		CFocusFtdcQuoteTotalTradePriceField empty_data = CFocusFtdcQuoteTotalTradePriceField();
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

void UserApi::OnRspSetPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETPRICESPREAD;

	if (pPriceSpread)
	{
		task.task_data = *pPriceSpread;
	}
	else
	{
		CFocusFtdcPriceSpreadField empty_data = CFocusFtdcPriceSpreadField();
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

void UserApi::OnRspQryPriceSpread(CFocusFtdcPriceSpreadField *pPriceSpread, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYPRICESPREAD;

	if (pPriceSpread)
	{
		task.task_data = *pPriceSpread;
	}
	else
	{
		CFocusFtdcPriceSpreadField empty_data = CFocusFtdcPriceSpreadField();
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

void UserApi::OnRspDelPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELPRICINGPARAM;

	if (pPricingParam)
	{
		task.task_data = *pPricingParam;
	}
	else
	{
		CFocusFtdcPricingParamField empty_data = CFocusFtdcPricingParamField();
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

void UserApi::OnRspDelMarkerStrategySet(CFocusFtdcMarkerStrategyField *pMarkerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELMARKERSTRATEGYSET;

	if (pMarkerStrategy)
	{
		task.task_data = *pMarkerStrategy;
	}
	else
	{
		CFocusFtdcMarkerStrategyField empty_data = CFocusFtdcMarkerStrategyField();
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

void UserApi::OnRspSetAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETALERTPARAM;

	if (pAlertIndexSetParam)
	{
		task.task_data = *pAlertIndexSetParam;
	}
	else
	{
		CFocusFtdcAlertIndexSetParamField empty_data = CFocusFtdcAlertIndexSetParamField();
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

void UserApi::OnRspQryAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALERTPARAM;

	if (pAlertIndexSetParam)
	{
		task.task_data = *pAlertIndexSetParam;
	}
	else
	{
		CFocusFtdcAlertIndexSetParamField empty_data = CFocusFtdcAlertIndexSetParamField();
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

void UserApi::OnRspQryAlertData(CFocusFtdcAlertIndexSetDataField *pAlertIndexSetData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALERTDATA;

	if (pAlertIndexSetData)
	{
		task.task_data = *pAlertIndexSetData;
	}
	else
	{
		CFocusFtdcAlertIndexSetDataField empty_data = CFocusFtdcAlertIndexSetDataField();
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

void UserApi::OnRtnAlertData(CFocusFtdcAlertIndexSetDataField *pAlertIndexSetData) 
{
	Task task = Task();
	task.task_name = ONRTNALERTDATA;

	if (pAlertIndexSetData)
	{
		task.task_data = *pAlertIndexSetData;
	}
	else
	{
		CFocusFtdcAlertIndexSetDataField empty_data = CFocusFtdcAlertIndexSetDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnStrategyLog(CFocusFtdcStrategyLogField *pStrategyLog) 
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

void UserApi::OnRtnQuoteTotalTradePosition(CFocusFtdcQuoteTotalTradePositionField *pQuoteTotalTradePosition) 
{
	Task task = Task();
	task.task_name = ONRTNQUOTETOTALTRADEPOSITION;

	if (pQuoteTotalTradePosition)
	{
		task.task_data = *pQuoteTotalTradePosition;
	}
	else
	{
		CFocusFtdcQuoteTotalTradePositionField empty_data = CFocusFtdcQuoteTotalTradePositionField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspDelOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELOPTIONTHEORYVOL;

	if (pOptionTheoryVol)
	{
		task.task_data = *pOptionTheoryVol;
	}
	else
	{
		CFocusFtdcOptionTheoryVolField empty_data = CFocusFtdcOptionTheoryVolField();
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

void UserApi::OnRspDelMarkerHedge(CFocusFtdcMarkerHedgeField *pMarkerHedge, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELMARKERHEDGE;

	if (pMarkerHedge)
	{
		task.task_data = *pMarkerHedge;
	}
	else
	{
		CFocusFtdcMarkerHedgeField empty_data = CFocusFtdcMarkerHedgeField();
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

void UserApi::OnRspSetMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETMARKERSTEP;

	if (pMarkerStep)
	{
		task.task_data = *pMarkerStep;
	}
	else
	{
		CFocusFtdcMarkerStepField empty_data = CFocusFtdcMarkerStepField();
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

void UserApi::OnRspDelMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELMARKERSTEP;

	if (pMarkerStep)
	{
		task.task_data = *pMarkerStep;
	}
	else
	{
		CFocusFtdcMarkerStepField empty_data = CFocusFtdcMarkerStepField();
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

void UserApi::OnRspDelAlertParam(CFocusFtdcAlertIndexSetParamField *pAlertIndexSetParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELALERTPARAM;

	if (pAlertIndexSetParam)
	{
		task.task_data = *pAlertIndexSetParam;
	}
	else
	{
		CFocusFtdcAlertIndexSetParamField empty_data = CFocusFtdcAlertIndexSetParamField();
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

void UserApi::OnRspSetQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETQUOTEMOVE;

	if (pQuoteMove)
	{
		task.task_data = *pQuoteMove;
	}
	else
	{
		CFocusFtdcQuoteMoveField empty_data = CFocusFtdcQuoteMoveField();
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

void UserApi::OnRspDelQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELQUOTEMOVE;

	if (pQuoteMove)
	{
		task.task_data = *pQuoteMove;
	}
	else
	{
		CFocusFtdcQuoteMoveField empty_data = CFocusFtdcQuoteMoveField();
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

void UserApi::OnRspRebackQuote(CFocusFtdcQuoteTotalTradePriceField *pQuoteTotalTradePrice, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPREBACKQUOTE;

	if (pQuoteTotalTradePrice)
	{
		task.task_data = *pQuoteTotalTradePrice;
	}
	else
	{
		CFocusFtdcQuoteTotalTradePriceField empty_data = CFocusFtdcQuoteTotalTradePriceField();
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

void UserApi::OnRspQryDepMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYDEPMARKETDATA;

	if (pDepthMarketData)
	{
		task.task_data = *pDepthMarketData;
	}
	else
	{
		CFocusFtdcDepthMarketDataField empty_data = CFocusFtdcDepthMarketDataField();
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

void UserApi::OnRspQryQuoteMove(CFocusFtdcQuoteMoveField *pQuoteMove, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYQUOTEMOVE;

	if (pQuoteMove)
	{
		task.task_data = *pQuoteMove;
	}
	else
	{
		CFocusFtdcQuoteMoveField empty_data = CFocusFtdcQuoteMoveField();
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

void UserApi::OnRspQryBaseMarkerStep(CFocusFtdcBaseMarkerStepField *pBaseMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYBASEMARKERSTEP;

	if (pBaseMarkerStep)
	{
		task.task_data = *pBaseMarkerStep;
	}
	else
	{
		CFocusFtdcBaseMarkerStepField empty_data = CFocusFtdcBaseMarkerStepField();
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

void UserApi::OnRspQryMarkerStep(CFocusFtdcMarkerStepField *pMarkerStep, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKERSTEP;

	if (pMarkerStep)
	{
		task.task_data = *pMarkerStep;
	}
	else
	{
		CFocusFtdcMarkerStepField empty_data = CFocusFtdcMarkerStepField();
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

void UserApi::OnRspFocusStatus(CFocusFtdcFocusStatusField *pFocusStatus, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPFOCUSSTATUS;

	if (pFocusStatus)
	{
		task.task_data = *pFocusStatus;
	}
	else
	{
		CFocusFtdcFocusStatusField empty_data = CFocusFtdcFocusStatusField();
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

void UserApi::OnRtnATMPriceData(CFocusFtdcATMPriceDataField *pATMPriceData) 
{
	Task task = Task();
	task.task_name = ONRTNATMPRICEDATA;

	if (pATMPriceData)
	{
		task.task_data = *pATMPriceData;
	}
	else
	{
		CFocusFtdcATMPriceDataField empty_data = CFocusFtdcATMPriceDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspSetFutureMakerWholeSwitch(CFocusFtdcFutureMakerWholeSwitchField *pFutureMakerWholeSwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETFUTUREMAKERWHOLESWITCH;

	if (pFutureMakerWholeSwitch)
	{
		task.task_data = *pFutureMakerWholeSwitch;
	}
	else
	{
		CFocusFtdcFutureMakerWholeSwitchField empty_data = CFocusFtdcFutureMakerWholeSwitchField();
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

void UserApi::OnRspSetFutureMakerStrategy(CFocusFtdcFutureMakerStrategyField *pFutureMakerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETFUTUREMAKERSTRATEGY;

	if (pFutureMakerStrategy)
	{
		task.task_data = *pFutureMakerStrategy;
	}
	else
	{
		CFocusFtdcFutureMakerStrategyField empty_data = CFocusFtdcFutureMakerStrategyField();
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

void UserApi::OnRspSetSlefHedgeStrategy(CFocusFtdcSlefHedgeStrategyField *pSlefHedgeStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETSLEFHEDGESTRATEGY;

	if (pSlefHedgeStrategy)
	{
		task.task_data = *pSlefHedgeStrategy;
	}
	else
	{
		CFocusFtdcSlefHedgeStrategyField empty_data = CFocusFtdcSlefHedgeStrategyField();
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

void UserApi::OnRspSetFutureHedgeStrategy(CFocusFtdcFutureHedgeStrategyField *pFutureHedgeStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETFUTUREHEDGESTRATEGY;

	if (pFutureHedgeStrategy)
	{
		task.task_data = *pFutureHedgeStrategy;
	}
	else
	{
		CFocusFtdcFutureHedgeStrategyField empty_data = CFocusFtdcFutureHedgeStrategyField();
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

void UserApi::OnRspSetQuoteAdditionParm(CFocusFtdcQuoteAdditionParmField *pQuoteAdditionParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETQUOTEADDITIONPARM;

	if (pQuoteAdditionParm)
	{
		task.task_data = *pQuoteAdditionParm;
	}
	else
	{
		CFocusFtdcQuoteAdditionParmField empty_data = CFocusFtdcQuoteAdditionParmField();
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

void UserApi::OnRtnMarkerStrategyChange(CFocusFtdcMarkerStrategyField *pMarkerStrategy) 
{
	Task task = Task();
	task.task_name = ONRTNMARKERSTRATEGYCHANGE;

	if (pMarkerStrategy)
	{
		task.task_data = *pMarkerStrategy;
	}
	else
	{
		CFocusFtdcMarkerStrategyField empty_data = CFocusFtdcMarkerStrategyField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspStopAllFutureMakerHedgeOffer(CFocusFtdcStopAllFutureMakerHedgeOfferField *pStopAllFutureMakerHedgeOffer, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSTOPALLFUTUREMAKERHEDGEOFFER;

	if (pStopAllFutureMakerHedgeOffer)
	{
		task.task_data = *pStopAllFutureMakerHedgeOffer;
	}
	else
	{
		CFocusFtdcStopAllFutureMakerHedgeOfferField empty_data = CFocusFtdcStopAllFutureMakerHedgeOfferField();
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

void UserApi::OnRtnFutureMakerHedgeStatus(CFocusFtdcFutureMakerHedgeStatusField *pFutureMakerHedgeStatus) 
{
	Task task = Task();
	task.task_name = ONRTNFUTUREMAKERHEDGESTATUS;

	if (pFutureMakerHedgeStatus)
	{
		task.task_data = *pFutureMakerHedgeStatus;
	}
	else
	{
		CFocusFtdcFutureMakerHedgeStatusField empty_data = CFocusFtdcFutureMakerHedgeStatusField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRtnInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition) 
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

void UserApi::OnRspQryFutureMakerStrategy(CFocusFtdcAllFutureMakerStrategyField *pAllFutureMakerStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYFUTUREMAKERSTRATEGY;

	if (pAllFutureMakerStrategy)
	{
		task.task_data = *pAllFutureMakerStrategy;
	}
	else
	{
		CFocusFtdcAllFutureMakerStrategyField empty_data = CFocusFtdcAllFutureMakerStrategyField();
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

void UserApi::OnRspQryAllInnerHighStockStrategy(CFocusFtdcInnerHighStockStrategyField *pInnerHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALLINNERHIGHSTOCKSTRATEGY;

	if (pInnerHighStockStrategy)
	{
		task.task_data = *pInnerHighStockStrategy;
	}
	else
	{
		CFocusFtdcInnerHighStockStrategyField empty_data = CFocusFtdcInnerHighStockStrategyField();
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

void UserApi::OnRtnInnerHighStockStrategy(CFocusFtdcInnerHighStockStrategyField *pInnerHighStockStrategy) 
{
	Task task = Task();
	task.task_name = ONRTNINNERHIGHSTOCKSTRATEGY;

	if (pInnerHighStockStrategy)
	{
		task.task_data = *pInnerHighStockStrategy;
	}
	else
	{
		CFocusFtdcInnerHighStockStrategyField empty_data = CFocusFtdcInnerHighStockStrategyField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspSetHighStockStrategySwitch(CFocusFtdcWholeHighStockStrategySwitchField *pWholeHighStockStrategySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETHIGHSTOCKSTRATEGYSWITCH;

	if (pWholeHighStockStrategySwitch)
	{
		task.task_data = *pWholeHighStockStrategySwitch;
	}
	else
	{
		CFocusFtdcWholeHighStockStrategySwitchField empty_data = CFocusFtdcWholeHighStockStrategySwitchField();
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

void UserApi::OnRspQryAPIHighStockStrategy(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYAPIHIGHSTOCKSTRATEGY;

	if (pAPIHighStockStrategy)
	{
		task.task_data = *pAPIHighStockStrategy;
	}
	else
	{
		CFocusFtdcAPIHighStockStrategyField empty_data = CFocusFtdcAPIHighStockStrategyField();
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

void UserApi::OnRspQrySignalPIHighStockStrategy(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYSIGNALPIHIGHSTOCKSTRATEGY;

	if (pAPIHighStockStrategy)
	{
		task.task_data = *pAPIHighStockStrategy;
	}
	else
	{
		CFocusFtdcAPIHighStockStrategyField empty_data = CFocusFtdcAPIHighStockStrategyField();
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

void UserApi::OnRspSetSignalHighStockStrategySwitch(CFocusFtdcSignalHighStockStrategySwitchField *pSignalHighStockStrategySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETSIGNALHIGHSTOCKSTRATEGYSWITCH;

	if (pSignalHighStockStrategySwitch)
	{
		task.task_data = *pSignalHighStockStrategySwitch;
	}
	else
	{
		CFocusFtdcSignalHighStockStrategySwitchField empty_data = CFocusFtdcSignalHighStockStrategySwitchField();
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

void UserApi::OnRspSetHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETHIGHSTOCKSTRATEGYRELATIONPARAM;

	if (pHighFutureStrategyRelation)
	{
		task.task_data = *pHighFutureStrategyRelation;
	}
	else
	{
		CFocusFtdcHighFutureStrategyRelationField empty_data = CFocusFtdcHighFutureStrategyRelationField();
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

void UserApi::OnRtnHighInnerFutureStrategyRelation(CFocusFtdcHighInnerFutureStrategyRelationField *pHighInnerFutureStrategyRelation) 
{
	Task task = Task();
	task.task_name = ONRTNHIGHINNERFUTURESTRATEGYRELATION;

	if (pHighInnerFutureStrategyRelation)
	{
		task.task_data = *pHighInnerFutureStrategyRelation;
	}
	else
	{
		CFocusFtdcHighInnerFutureStrategyRelationField empty_data = CFocusFtdcHighInnerFutureStrategyRelationField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspQryAllStrategyRelation(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALLSTRATEGYRELATION;

	if (pHighFutureStrategyRelation)
	{
		task.task_data = *pHighFutureStrategyRelation;
	}
	else
	{
		CFocusFtdcHighFutureStrategyRelationField empty_data = CFocusFtdcHighFutureStrategyRelationField();
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

void UserApi::OnRspSetAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETAPIHIGHSTOCKSTRATEGYPARAM;

	if (pAPIHighStockStrategy)
	{
		task.task_data = *pAPIHighStockStrategy;
	}
	else
	{
		CFocusFtdcAPIHighStockStrategyField empty_data = CFocusFtdcAPIHighStockStrategyField();
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

void UserApi::OnRspDelHighStockStrategyRelationParam(CFocusFtdcHighFutureStrategyRelationField *pHighFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELHIGHSTOCKSTRATEGYRELATIONPARAM;

	if (pHighFutureStrategyRelation)
	{
		task.task_data = *pHighFutureStrategyRelation;
	}
	else
	{
		CFocusFtdcHighFutureStrategyRelationField empty_data = CFocusFtdcHighFutureStrategyRelationField();
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

void UserApi::OnRspDelAPIHighStockStrategyParam(CFocusFtdcAPIHighStockStrategyField *pAPIHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELAPIHIGHSTOCKSTRATEGYPARAM;

	if (pAPIHighStockStrategy)
	{
		task.task_data = *pAPIHighStockStrategy;
	}
	else
	{
		CFocusFtdcAPIHighStockStrategyField empty_data = CFocusFtdcAPIHighStockStrategyField();
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

void UserApi::OnRspQryAllTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALLTRADINGPERIODSTRATEGY;

	if (pStockMarketTradingPeriodStrategy)
	{
		task.task_data = *pStockMarketTradingPeriodStrategy;
	}
	else
	{
		CFocusFtdcStockMarketTradingPeriodStrategyField empty_data = CFocusFtdcStockMarketTradingPeriodStrategyField();
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

void UserApi::OnRspSetTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETTRADINGPERIODSTRATEGY;

	if (pStockMarketTradingPeriodStrategy)
	{
		task.task_data = *pStockMarketTradingPeriodStrategy;
	}
	else
	{
		CFocusFtdcStockMarketTradingPeriodStrategyField empty_data = CFocusFtdcStockMarketTradingPeriodStrategyField();
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

void UserApi::OnRspDelTradingPeriodStrategy(CFocusFtdcStockMarketTradingPeriodStrategyField *pStockMarketTradingPeriodStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELTRADINGPERIODSTRATEGY;

	if (pStockMarketTradingPeriodStrategy)
	{
		task.task_data = *pStockMarketTradingPeriodStrategy;
	}
	else
	{
		CFocusFtdcStockMarketTradingPeriodStrategyField empty_data = CFocusFtdcStockMarketTradingPeriodStrategyField();
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

void UserApi::OnRspQryAllInnerStrategyRelation(CFocusFtdcHighInnerFutureStrategyRelationField *pHighInnerFutureStrategyRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALLINNERSTRATEGYRELATION;

	if (pHighInnerFutureStrategyRelation)
	{
		task.task_data = *pHighInnerFutureStrategyRelation;
	}
	else
	{
		CFocusFtdcHighInnerFutureStrategyRelationField empty_data = CFocusFtdcHighInnerFutureStrategyRelationField();
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

void UserApi::OnRspCancelAllStrategyRelationOrder(CFocusFtdcQryWholeHighStockStrategyField *pQryWholeHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPCANCELALLSTRATEGYRELATIONORDER;

	if (pQryWholeHighStockStrategy)
	{
		task.task_data = *pQryWholeHighStockStrategy;
	}
	else
	{
		CFocusFtdcQryWholeHighStockStrategyField empty_data = CFocusFtdcQryWholeHighStockStrategyField();
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

void UserApi::OnRspSetAutoReBuySwitch(CFocusFtdcRelationAutoReBuySwitchField *pRelationAutoReBuySwitch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETAUTOREBUYSWITCH;

	if (pRelationAutoReBuySwitch)
	{
		task.task_data = *pRelationAutoReBuySwitch;
	}
	else
	{
		CFocusFtdcRelationAutoReBuySwitchField empty_data = CFocusFtdcRelationAutoReBuySwitchField();
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

void UserApi::OnRspSendFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSENDFUTURESTRATEGYORDER;

	if (pFutureStrategyOrder)
	{
		task.task_data = *pFutureStrategyOrder;
	}
	else
	{
		CFocusFtdcFutureStrategyOrderField empty_data = CFocusFtdcFutureStrategyOrderField();
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

void UserApi::OnRspSetAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETALGOPARM;

	if (pAlgoParm)
	{
		task.task_data = *pAlgoParm;
	}
	else
	{
		CFocusFtdcAlgoParmField empty_data = CFocusFtdcAlgoParmField();
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

void UserApi::OnRtnInnerFutureStrategyOrder(CFocusFtdcInnerFutureStrategyOrderField *pInnerFutureStrategyOrder) 
{
	Task task = Task();
	task.task_name = ONRTNINNERFUTURESTRATEGYORDER;

	if (pInnerFutureStrategyOrder)
	{
		task.task_data = *pInnerFutureStrategyOrder;
	}
	else
	{
		CFocusFtdcInnerFutureStrategyOrderField empty_data = CFocusFtdcInnerFutureStrategyOrderField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspQryAlgoParm(CFocusFtdcAlgoParmField *pAlgoParm, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALGOPARM;

	if (pAlgoParm)
	{
		task.task_data = *pAlgoParm;
	}
	else
	{
		CFocusFtdcAlgoParmField empty_data = CFocusFtdcAlgoParmField();
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

void UserApi::OnRspQryFutureStrategyOrder(CFocusFtdcFutureStrategyOrderField *pFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYFUTURESTRATEGYORDER;

	if (pFutureStrategyOrder)
	{
		task.task_data = *pFutureStrategyOrder;
	}
	else
	{
		CFocusFtdcFutureStrategyOrderField empty_data = CFocusFtdcFutureStrategyOrderField();
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

void UserApi::OnRspQryInnerFutureStrategyOrder(CFocusFtdcInnerFutureStrategyOrderField *pInnerFutureStrategyOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINNERFUTURESTRATEGYORDER;

	if (pInnerFutureStrategyOrder)
	{
		task.task_data = *pInnerFutureStrategyOrder;
	}
	else
	{
		CFocusFtdcInnerFutureStrategyOrderField empty_data = CFocusFtdcInnerFutureStrategyOrderField();
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

void UserApi::OnRspSetStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETSTRAGEDYMESSAGE;

	if (pIndexDirSignal)
	{
		task.task_data = *pIndexDirSignal;
	}
	else
	{
		CFocusFtdcIndexDirSignalField empty_data = CFocusFtdcIndexDirSignalField();
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

void UserApi::OnRspQryIndexDirSignal(CFocusFtdcIndexDirSignalField *pIndexDirSignal, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINDEXDIRSIGNAL;

	if (pIndexDirSignal)
	{
		task.task_data = *pIndexDirSignal;
	}
	else
	{
		CFocusFtdcIndexDirSignalField empty_data = CFocusFtdcIndexDirSignalField();
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

void UserApi::OnRspDelFutureStrategyOrder(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELFUTURESTRATEGYORDER;

	if (pFutureStrategyOrderIndex)
	{
		task.task_data = *pFutureStrategyOrderIndex;
	}
	else
	{
		CFocusFtdcFutureStrategyOrderIndexField empty_data = CFocusFtdcFutureStrategyOrderIndexField();
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

void UserApi::OnRspDelAlgoParm(CFocusFtdcFutureStrategyOrderIndexField *pFutureStrategyOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELALGOPARM;

	if (pFutureStrategyOrderIndex)
	{
		task.task_data = *pFutureStrategyOrderIndex;
	}
	else
	{
		CFocusFtdcFutureStrategyOrderIndexField empty_data = CFocusFtdcFutureStrategyOrderIndexField();
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

void UserApi::OnRspSetSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETSPREADINSTRSTRATEGY;

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

void UserApi::OnRspQrySpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYSPREADINSTRSTRATEGY;

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

void UserApi::OnRspDelSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELSPREADINSTRSTRATEGY;

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

void UserApi::OnRspQryInnerSpreadInstrStrategy(CFocusFtdcInnerSpreadInstrStrategyField *pInnerSpreadInstrStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINNERSPREADINSTRSTRATEGY;

	if (pInnerSpreadInstrStrategy)
	{
		task.task_data = *pInnerSpreadInstrStrategy;
	}
	else
	{
		CFocusFtdcInnerSpreadInstrStrategyField empty_data = CFocusFtdcInnerSpreadInstrStrategyField();
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

void UserApi::OnRtnInnerSpreadInstrStrategy(CFocusFtdcInnerSpreadInstrStrategyField *pInnerSpreadInstrStrategy) 
{
	Task task = Task();
	task.task_name = ONRTNINNERSPREADINSTRSTRATEGY;

	if (pInnerSpreadInstrStrategy)
	{
		task.task_data = *pInnerSpreadInstrStrategy;
	}
	else
	{
		CFocusFtdcInnerSpreadInstrStrategyField empty_data = CFocusFtdcInnerSpreadInstrStrategyField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspSetTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETTZEROHIGHSTOCKSTRATEGY;

	if (pTZeroHighStockStrategy)
	{
		task.task_data = *pTZeroHighStockStrategy;
	}
	else
	{
		CFocusFtdcTZeroHighStockStrategyField empty_data = CFocusFtdcTZeroHighStockStrategyField();
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

void UserApi::OnRspQryTZeroHighStockStrategy(CFocusFtdcTZeroHighStockStrategyField *pTZeroHighStockStrategy, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTZEROHIGHSTOCKSTRATEGY;

	if (pTZeroHighStockStrategy)
	{
		task.task_data = *pTZeroHighStockStrategy;
	}
	else
	{
		CFocusFtdcTZeroHighStockStrategyField empty_data = CFocusFtdcTZeroHighStockStrategyField();
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

void UserApi::OnRtnStragedyMessage(CFocusFtdcIndexDirSignalField *pIndexDirSignal) 
{
	Task task = Task();
	task.task_name = ONRTNSTRAGEDYMESSAGE;

	if (pIndexDirSignal)
	{
		task.task_data = *pIndexDirSignal;
	}
	else
	{
		CFocusFtdcIndexDirSignalField empty_data = CFocusFtdcIndexDirSignalField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspSetfutruetradeinstr(CFocusFtdcQryInstrumentField *pQryInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETFUTRUETRADEINSTR;

	if (pQryInstrument)
	{
		task.task_data = *pQryInstrument;
	}
	else
	{
		CFocusFtdcQryInstrumentField empty_data = CFocusFtdcQryInstrumentField();
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

void UserApi::OnRspQryFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYFLOWERFUTURETARGETMONEY;

	if (pFlowerFutureTargetMoney)
	{
		task.task_data = *pFlowerFutureTargetMoney;
	}
	else
	{
		CFocusFtdcFlowerFutureTargetMoneyField empty_data = CFocusFtdcFlowerFutureTargetMoneyField();
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

void UserApi::OnRspSetFlowerFutureTargetMoney(CFocusFtdcFlowerFutureTargetMoneyField *pFlowerFutureTargetMoney, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETFLOWERFUTURETARGETMONEY;

	if (pFlowerFutureTargetMoney)
	{
		task.task_data = *pFlowerFutureTargetMoney;
	}
	else
	{
		CFocusFtdcFlowerFutureTargetMoneyField empty_data = CFocusFtdcFlowerFutureTargetMoneyField();
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

void UserApi::OnRtnParentOrder(CFocusFtdcParentOrderField *pParentOrder) 
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

void UserApi::OnRtnParentOrderAction(CFocusFtdcParentOrderActionField *pParentOrderAction) 
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

void UserApi::OnRtnAmendParentOrder(CFocusFtdcAmendParentOrderField *pAmendParentOrder) 
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

void UserApi::OnRtnExtraManualParentOrder(CFocusFtdcExtraManualParentOrderField *pExtraManualParentOrder) 
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

void UserApi::OnRspQryMarketTradingTime(CFocusFtdcMarketTradingPeriodInfoField *pMarketTradingPeriodInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspSetFutureStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETFUTURESTRATEGYTOTALSECONDRELATIONPARAM;

	if (pFutureStrategyTotalSecondRelation)
	{
		task.task_data = *pFutureStrategyTotalSecondRelation;
	}
	else
	{
		CFocusFtdcFutureStrategyTotalSecondRelationField empty_data = CFocusFtdcFutureStrategyTotalSecondRelationField();
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

void UserApi::OnRtnHighInnerFutureStrategyTotalSecondRelation(CFocusFtdcInnerFutureStrategyTotalSecondRelationField *pInnerFutureStrategyTotalSecondRelation) 
{
	Task task = Task();
	task.task_name = ONRTNHIGHINNERFUTURESTRATEGYTOTALSECONDRELATION;

	if (pInnerFutureStrategyTotalSecondRelation)
	{
		task.task_data = *pInnerFutureStrategyTotalSecondRelation;
	}
	else
	{
		CFocusFtdcInnerFutureStrategyTotalSecondRelationField empty_data = CFocusFtdcInnerFutureStrategyTotalSecondRelationField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspQryAllTotalSecondStrategyRelation(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALLTOTALSECONDSTRATEGYRELATION;

	if (pFutureStrategyTotalSecondRelation)
	{
		task.task_data = *pFutureStrategyTotalSecondRelation;
	}
	else
	{
		CFocusFtdcFutureStrategyTotalSecondRelationField empty_data = CFocusFtdcFutureStrategyTotalSecondRelationField();
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

void UserApi::OnRspDelHighStockStrategyTotalSecondRelationParam(CFocusFtdcFutureStrategyTotalSecondRelationField *pFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELHIGHSTOCKSTRATEGYTOTALSECONDRELATIONPARAM;

	if (pFutureStrategyTotalSecondRelation)
	{
		task.task_data = *pFutureStrategyTotalSecondRelation;
	}
	else
	{
		CFocusFtdcFutureStrategyTotalSecondRelationField empty_data = CFocusFtdcFutureStrategyTotalSecondRelationField();
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

void UserApi::OnRspQryAllInnerTotalSecondStrategyRelation(CFocusFtdcInnerFutureStrategyTotalSecondRelationField *pInnerFutureStrategyTotalSecondRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYALLINNERTOTALSECONDSTRATEGYRELATION;

	if (pInnerFutureStrategyTotalSecondRelation)
	{
		task.task_data = *pInnerFutureStrategyTotalSecondRelation;
	}
	else
	{
		CFocusFtdcInnerFutureStrategyTotalSecondRelationField empty_data = CFocusFtdcInnerFutureStrategyTotalSecondRelationField();
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

void UserApi::OnRspQryParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYPARENTDETIALUPDATEMESSAGE;

	if (pParentDetialUpdateMessage)
	{
		task.task_data = *pParentDetialUpdateMessage;
	}
	else
	{
		CFocusFtdcParentDetialUpdateMessageField empty_data = CFocusFtdcParentDetialUpdateMessageField();
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

void UserApi::OnRspQryParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYPARENTORDERSTATICPARAM;

	if (pParentOrderStaticParam)
	{
		task.task_data = *pParentOrderStaticParam;
	}
	else
	{
		CFocusFtdcParentOrderStaticParamField empty_data = CFocusFtdcParentOrderStaticParamField();
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

void UserApi::OnRtnParentDetialUpdateMessage(CFocusFtdcParentDetialUpdateMessageField *pParentDetialUpdateMessage) 
{
	Task task = Task();
	task.task_name = ONRTNPARENTDETIALUPDATEMESSAGE;

	if (pParentDetialUpdateMessage)
	{
		task.task_data = *pParentDetialUpdateMessage;
	}
	else
	{
		CFocusFtdcParentDetialUpdateMessageField empty_data = CFocusFtdcParentDetialUpdateMessageField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspSetParentOrderStaticParam(CFocusFtdcParentOrderStaticParamField *pParentOrderStaticParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETPARENTORDERSTATICPARAM;

	if (pParentOrderStaticParam)
	{
		task.task_data = *pParentOrderStaticParam;
	}
	else
	{
		CFocusFtdcParentOrderStaticParamField empty_data = CFocusFtdcParentOrderStaticParamField();
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

void UserApi::OnRspDelParentOrderStaticParam(CFocusFtdcParentOrderIndexField *pParentOrderIndex, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPDELPARENTORDERSTATICPARAM;

	if (pParentOrderIndex)
	{
		task.task_data = *pParentOrderIndex;
	}
	else
	{
		CFocusFtdcParentOrderIndexField empty_data = CFocusFtdcParentOrderIndexField();
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

void UserApi::OnRspQryJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYJAVAALGOSTATUS;

	if (pFocusStatus)
	{
		task.task_data = *pFocusStatus;
	}
	else
	{
		CFocusFtdcFocusStatusField empty_data = CFocusFtdcFocusStatusField();
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

void UserApi::OnRtnJavaAlgoStatus(CFocusFtdcFocusStatusField *pFocusStatus) 
{
	Task task = Task();
	task.task_name = ONRTNJAVAALGOSTATUS;

	if (pFocusStatus)
	{
		task.task_data = *pFocusStatus;
	}
	else
	{
		CFocusFtdcFocusStatusField empty_data = CFocusFtdcFocusStatusField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void UserApi::OnRspQryFuSkAccountRelation(CFocusFtdcFuSkAccountRelationField *pFuSkAccountRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYFUSKACCOUNTRELATION;

	if (pFuSkAccountRelation)
	{
		task.task_data = *pFuSkAccountRelation;
	}
	else
	{
		CFocusFtdcFuSkAccountRelationField empty_data = CFocusFtdcFuSkAccountRelationField();
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

void UserApi::OnRspBatchOrderInsert(CFocusFtdcBatchInputOrderField *pBatchInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspBatchOrderAction(CFocusFtdcBatchOrderActionField *pBatchOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void UserApi::OnRspSetUserInvestorSeatBasePasswd(CFocusFtdcUserInvestorSeatBaseField *pUserInvestorSeatBase, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSETUSERINVESTORSEATBASEPASSWD;

	if (pUserInvestorSeatBase)
	{
		task.task_data = *pUserInvestorSeatBase;
	}
	else
	{
		CFocusFtdcUserInvestorSeatBaseField empty_data = CFocusFtdcUserInvestorSeatBaseField();
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

void UserApi::OnRtnSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) 
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

void UserApi::OnRtnAmendPSpreadInstrStrategy(CFocusFtdcSpreadInstrStrategyField *pSpreadInstrStrategy) 
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

void UserApi::OnRspQryUnFinshPutureOrder(CFocusFtdcUnFinshPutureOrderField *pUnFinshPutureOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYUNFINSHPUTUREORDER;

	if (pUnFinshPutureOrder)
	{
		task.task_data = *pUnFinshPutureOrder;
	}
	else
	{
		CFocusFtdcUnFinshPutureOrderField empty_data = CFocusFtdcUnFinshPutureOrderField();
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

void UserApi::OnRspQryTodayTayoutDetails(CFocusFtdcTodayTayoutDetailsField *pTodayTayoutDetails, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTODAYTAYOUTDETAILS;

	if (pTodayTayoutDetails)
	{
		task.task_data = *pTodayTayoutDetails;
	}
	else
	{
		CFocusFtdcTodayTayoutDetailsField empty_data = CFocusFtdcTodayTayoutDetailsField();
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



///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void UserApi::processTask()
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

		case ONRSPUSERPASSWORDUPDATE:
		{
			this->processRspUserPasswordUpdate(task);
			break;
		}

		case ONRSPFORCEUSEREXIT:
		{
			this->processRspForceUserExit(task);
			break;
		}

		case ONRSPFORCEUSERLOGOUT:
		{
			this->processRspForceUserLogout(task);
			break;
		}

		case ONRSPDUMPMEMDB:
		{
			this->processRspDumpMemDB(task);
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

		case ONRSPACCOUNTDEPOSIT:
		{
			this->processRspAccountDeposit(task);
			break;
		}

		case ONRSPINVESTORRIGHT:
		{
			this->processRspInvestorRight(task);
			break;
		}

		case ONRSPTBCOMMAND:
		{
			this->processRspTBCommand(task);
			break;
		}

		case ONRSPPINGPONG:
		{
			this->processRspPingPong(task);
			break;
		}

		case ONRSPSETADVICERUNMODE:
		{
			this->processRspSetAdviceRunMode(task);
			break;
		}

		case ONRTNDEPTHMARKETDATA:
		{
			this->processRtnDepthMarketData(task);
			break;
		}

		case ONRTNMULTIDEPTHMARKETDATA:
		{
			this->processRtnMultiDepthMarketData(task);
			break;
		}

		case ONRSPSUBMARKETDATA:
		{
			this->processRspSubMarketData(task);
			break;
		}

		case ONRSPUNSUBMARKETDATA:
		{
			this->processRspUnSubMarketData(task);
			break;
		}

		case ONRSPTOPICSEARCH:
		{
			this->processRspTopicSearch(task);
			break;
		}

		case ONRTNMBLMARKETDATA:
		{
			this->processRtnMBLMarketData(task);
			break;
		}

		case ONRTNQMDINSTRUMENTSTATU:
		{
			this->processRtnQmdInstrumentStatu(task);
			break;
		}

		case ONRTNFLOWMESSAGECANCEL:
		{
			this->processRtnFlowMessageCancel(task);
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

		case ONERRRTNORDERINSERT:
		{
			this->processErrRtnOrderInsert(task);
			break;
		}

		case ONERRRTNORDERACTION:
		{
			this->processErrRtnOrderAction(task);
			break;
		}

		case ONRTNINSTRUMENTSTATUS:
		{
			this->processRtnInstrumentStatus(task);
			break;
		}

		case ONRTNINVESTORACCOUNTDEPOSIT:
		{
			this->processRtnInvestorAccountDeposit(task);
			break;
		}

		case ONRTNMESSAGENOTIFY:
		{
			this->processRtnMessageNotify(task);
			break;
		}

		case ONRTNADVICEORDER:
		{
			this->processRtnAdviceOrder(task);
			break;
		}

		case ONRTNSUBINSTRUMENTSTATUS:
		{
			this->processRtnSubInstrumentStatus(task);
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

		case ONRSPQRYUSERINVESTOR:
		{
			this->processRspQryUserInvestor(task);
			break;
		}

		case ONRSPQRYINVESTORACCOUNT:
		{
			this->processRspQryInvestorAccount(task);
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

		case ONRSPQRYUSER:
		{
			this->processRspQryUser(task);
			break;
		}

		case ONRSPQRYINVESTORFEE:
		{
			this->processRspQryInvestorFee(task);
			break;
		}

		case ONRSPQRYINVESTORMARGIN:
		{
			this->processRspQryInvestorMargin(task);
			break;
		}

		case ONRSPQRYINVESTOR:
		{
			this->processRspQryInvestor(task);
			break;
		}

		case ONRSPQRYACCOUNTRISK:
		{
			this->processRspQryAccountRisk(task);
			break;
		}

		case ONRSPQRYUSERSESSION:
		{
			this->processRspQryUserSession(task);
			break;
		}

		case ONRSPQRYMARKETDATA:
		{
			this->processRspQryMarketData(task);
			break;
		}

		case ONRSPQRYINVESTORRELATION:
		{
			this->processRspQryInvestorRelation(task);
			break;
		}

		case ONRSPQRYPRODUCT:
		{
			this->processRspQryProduct(task);
			break;
		}

		case ONRSPQRYADVICETRADER:
		{
			this->processRspQryAdviceTrader(task);
			break;
		}

		case ONRSPQRYMAXVOLUME:
		{
			this->processRspQryMaxVolume(task);
			break;
		}

		case ONRSPQRYCMBPOSITIONDETAIL:
		{
			this->processRspQryCmbPositionDetail(task);
			break;
		}

		case ONRSPQRYSETTLEMENTINFO:
		{
			this->processRspQrySettlementInfo(task);
			break;
		}

		case ONRSPSUBINSTRUMENT:
		{
			this->processRspSubInstrument(task);
			break;
		}

		case ONRSPUNSUBINSTRUMENT:
		{
			this->processRspUnSubInstrument(task);
			break;
		}

		case ONRSPQRYRESULTPAGE:
		{
			this->processRspQryResultPage(task);
			break;
		}

		case ONRSPQRYINVESTORPOSITIONDETAIL:
		{
			this->processRspQryInvestorPositionDetail(task);
			break;
		}

		case ONRTNTHEORYPRICEDATA:
		{
			this->processRtnTheoryPriceData(task);
			break;
		}

		case ONRTNOPTIONINDEXDATA:
		{
			this->processRtnOptionIndexData(task);
			break;
		}

		case ONRSPSETPRICINGPARAM:
		{
			this->processRspSetPricingParam(task);
			break;
		}

		case ONRSPSETOPTIONTHEORYVOL:
		{
			this->processRspSetOptionTheoryVol(task);
			break;
		}

		case ONRSPCALCONEOPTION:
		{
			this->processRspCalcOneOption(task);
			break;
		}

		case ONRSPCALCBARRIEROPTION:
		{
			this->processRspCalcBarrierOption(task);
			break;
		}

		case ONRSPVOLATILITYFITTING:
		{
			this->processRspVolatilityFitting(task);
			break;
		}

		case ONRSPQRYWINGMODELPARAM:
		{
			this->processRspQryWingModelParam(task);
			break;
		}

		case ONRSPSETWINGMODELPARAM:
		{
			this->processRspSetWingModelParam(task);
			break;
		}

		case ONRTNQUOTETOTALTRADEPRICE:
		{
			this->processRtnQuoteTotalTradePrice(task);
			break;
		}

		case ONRSPQRYMARKERSTRATEGYSET:
		{
			this->processRspQryMarkerStrategySet(task);
			break;
		}

		case ONRSPUPMARKERSTRATEGYSET:
		{
			this->processRspUpMarkerStrategySet(task);
			break;
		}

		case ONRSPQRYUSERSWITCH:
		{
			this->processRspQryUserSwitch(task);
			break;
		}

		case ONRSPUSERSWITCH:
		{
			this->processRspUserSwitch(task);
			break;
		}

		case ONRSPQRYMARKERHEDGE:
		{
			this->processRspQryMarkerHedge(task);
			break;
		}

		case ONRSPUPMARKERHEDGE:
		{
			this->processRspUpMarkerHedge(task);
			break;
		}

		case ONRSPQRYFITTINGPARAM:
		{
			this->processRspQryFittingParam(task);
			break;
		}

		case ONRSPSETFITTINGPARAM:
		{
			this->processRspSetFittingParam(task);
			break;
		}

		case ONRSPQRYPRICINGPARAM:
		{
			this->processRspQryPricingParam(task);
			break;
		}

		case ONRSPQRYOPTIONTHEORYVOL:
		{
			this->processRspQryOptionTheoryVol(task);
			break;
		}

		case ONRSPQUOTEINSERT:
		{
			this->processRspQuoteInsert(task);
			break;
		}

		case ONRSPQUOTEACTION:
		{
			this->processRspQuoteAction(task);
			break;
		}

		case ONRSPQRYQUOTE:
		{
			this->processRspQryQuote(task);
			break;
		}

		case ONRTNQUOTE:
		{
			this->processRtnQuote(task);
			break;
		}

		case ONRSPFORQUOTE:
		{
			this->processRspForQuote(task);
			break;
		}

		case ONRTNFORQUOTE:
		{
			this->processRtnForQuote(task);
			break;
		}

		case ONRSPQRYORDERINSERTFAILED:
		{
			this->processRspQryOrderInsertFailed(task);
			break;
		}

		case ONRSPCLEANQUOTETHRESHOLD:
		{
			this->processRspCleanQuoteThresHold(task);
			break;
		}

		case ONRSPSETPRICESPREAD:
		{
			this->processRspSetPriceSpread(task);
			break;
		}

		case ONRSPQRYPRICESPREAD:
		{
			this->processRspQryPriceSpread(task);
			break;
		}

		case ONRSPDELPRICINGPARAM:
		{
			this->processRspDelPricingParam(task);
			break;
		}

		case ONRSPDELMARKERSTRATEGYSET:
		{
			this->processRspDelMarkerStrategySet(task);
			break;
		}

		case ONRSPSETALERTPARAM:
		{
			this->processRspSetAlertParam(task);
			break;
		}

		case ONRSPQRYALERTPARAM:
		{
			this->processRspQryAlertParam(task);
			break;
		}

		case ONRSPQRYALERTDATA:
		{
			this->processRspQryAlertData(task);
			break;
		}

		case ONRTNALERTDATA:
		{
			this->processRtnAlertData(task);
			break;
		}

		case ONRTNSTRATEGYLOG:
		{
			this->processRtnStrategyLog(task);
			break;
		}

		case ONRTNQUOTETOTALTRADEPOSITION:
		{
			this->processRtnQuoteTotalTradePosition(task);
			break;
		}

		case ONRSPDELOPTIONTHEORYVOL:
		{
			this->processRspDelOptionTheoryVol(task);
			break;
		}

		case ONRSPDELMARKERHEDGE:
		{
			this->processRspDelMarkerHedge(task);
			break;
		}

		case ONRSPSETMARKERSTEP:
		{
			this->processRspSetMarkerStep(task);
			break;
		}

		case ONRSPDELMARKERSTEP:
		{
			this->processRspDelMarkerStep(task);
			break;
		}

		case ONRSPDELALERTPARAM:
		{
			this->processRspDelAlertParam(task);
			break;
		}

		case ONRSPSETQUOTEMOVE:
		{
			this->processRspSetQuoteMove(task);
			break;
		}

		case ONRSPDELQUOTEMOVE:
		{
			this->processRspDelQuoteMove(task);
			break;
		}

		case ONRSPREBACKQUOTE:
		{
			this->processRspRebackQuote(task);
			break;
		}

		case ONRSPQRYDEPMARKETDATA:
		{
			this->processRspQryDepMarketData(task);
			break;
		}

		case ONRSPQRYQUOTEMOVE:
		{
			this->processRspQryQuoteMove(task);
			break;
		}

		case ONRSPQRYBASEMARKERSTEP:
		{
			this->processRspQryBaseMarkerStep(task);
			break;
		}

		case ONRSPQRYMARKERSTEP:
		{
			this->processRspQryMarkerStep(task);
			break;
		}

		case ONRSPFOCUSSTATUS:
		{
			this->processRspFocusStatus(task);
			break;
		}

		case ONRTNATMPRICEDATA:
		{
			this->processRtnATMPriceData(task);
			break;
		}

		case ONRSPSETFUTUREMAKERWHOLESWITCH:
		{
			this->processRspSetFutureMakerWholeSwitch(task);
			break;
		}

		case ONRSPSETFUTUREMAKERSTRATEGY:
		{
			this->processRspSetFutureMakerStrategy(task);
			break;
		}

		case ONRSPSETSLEFHEDGESTRATEGY:
		{
			this->processRspSetSlefHedgeStrategy(task);
			break;
		}

		case ONRSPSETFUTUREHEDGESTRATEGY:
		{
			this->processRspSetFutureHedgeStrategy(task);
			break;
		}

		case ONRSPSETQUOTEADDITIONPARM:
		{
			this->processRspSetQuoteAdditionParm(task);
			break;
		}

		case ONRTNMARKERSTRATEGYCHANGE:
		{
			this->processRtnMarkerStrategyChange(task);
			break;
		}

		case ONRSPSTOPALLFUTUREMAKERHEDGEOFFER:
		{
			this->processRspStopAllFutureMakerHedgeOffer(task);
			break;
		}

		case ONRTNFUTUREMAKERHEDGESTATUS:
		{
			this->processRtnFutureMakerHedgeStatus(task);
			break;
		}

		case ONRTNINVESTORPOSITION:
		{
			this->processRtnInvestorPosition(task);
			break;
		}

		case ONRSPQRYFUTUREMAKERSTRATEGY:
		{
			this->processRspQryFutureMakerStrategy(task);
			break;
		}

		case ONRSPQRYALLINNERHIGHSTOCKSTRATEGY:
		{
			this->processRspQryAllInnerHighStockStrategy(task);
			break;
		}

		case ONRTNINNERHIGHSTOCKSTRATEGY:
		{
			this->processRtnInnerHighStockStrategy(task);
			break;
		}

		case ONRSPSETHIGHSTOCKSTRATEGYSWITCH:
		{
			this->processRspSetHighStockStrategySwitch(task);
			break;
		}

		case ONRSPQRYAPIHIGHSTOCKSTRATEGY:
		{
			this->processRspQryAPIHighStockStrategy(task);
			break;
		}

		case ONRSPQRYSIGNALPIHIGHSTOCKSTRATEGY:
		{
			this->processRspQrySignalPIHighStockStrategy(task);
			break;
		}

		case ONRSPSETSIGNALHIGHSTOCKSTRATEGYSWITCH:
		{
			this->processRspSetSignalHighStockStrategySwitch(task);
			break;
		}

		case ONRSPSETHIGHSTOCKSTRATEGYRELATIONPARAM:
		{
			this->processRspSetHighStockStrategyRelationParam(task);
			break;
		}

		case ONRTNHIGHINNERFUTURESTRATEGYRELATION:
		{
			this->processRtnHighInnerFutureStrategyRelation(task);
			break;
		}

		case ONRSPQRYALLSTRATEGYRELATION:
		{
			this->processRspQryAllStrategyRelation(task);
			break;
		}

		case ONRSPSETAPIHIGHSTOCKSTRATEGYPARAM:
		{
			this->processRspSetAPIHighStockStrategyParam(task);
			break;
		}

		case ONRSPDELHIGHSTOCKSTRATEGYRELATIONPARAM:
		{
			this->processRspDelHighStockStrategyRelationParam(task);
			break;
		}

		case ONRSPDELAPIHIGHSTOCKSTRATEGYPARAM:
		{
			this->processRspDelAPIHighStockStrategyParam(task);
			break;
		}

		case ONRSPQRYALLTRADINGPERIODSTRATEGY:
		{
			this->processRspQryAllTradingPeriodStrategy(task);
			break;
		}

		case ONRSPSETTRADINGPERIODSTRATEGY:
		{
			this->processRspSetTradingPeriodStrategy(task);
			break;
		}

		case ONRSPDELTRADINGPERIODSTRATEGY:
		{
			this->processRspDelTradingPeriodStrategy(task);
			break;
		}

		case ONRSPQRYALLINNERSTRATEGYRELATION:
		{
			this->processRspQryAllInnerStrategyRelation(task);
			break;
		}

		case ONRSPCANCELALLSTRATEGYRELATIONORDER:
		{
			this->processRspCancelAllStrategyRelationOrder(task);
			break;
		}

		case ONRSPSETAUTOREBUYSWITCH:
		{
			this->processRspSetAutoReBuySwitch(task);
			break;
		}

		case ONRSPSENDFUTURESTRATEGYORDER:
		{
			this->processRspSendFutureStrategyOrder(task);
			break;
		}

		case ONRSPSETALGOPARM:
		{
			this->processRspSetAlgoParm(task);
			break;
		}

		case ONRTNINNERFUTURESTRATEGYORDER:
		{
			this->processRtnInnerFutureStrategyOrder(task);
			break;
		}

		case ONRSPQRYALGOPARM:
		{
			this->processRspQryAlgoParm(task);
			break;
		}

		case ONRSPQRYFUTURESTRATEGYORDER:
		{
			this->processRspQryFutureStrategyOrder(task);
			break;
		}

		case ONRSPQRYINNERFUTURESTRATEGYORDER:
		{
			this->processRspQryInnerFutureStrategyOrder(task);
			break;
		}

		case ONRSPSETSTRAGEDYMESSAGE:
		{
			this->processRspSetStragedyMessage(task);
			break;
		}

		case ONRSPQRYINDEXDIRSIGNAL:
		{
			this->processRspQryIndexDirSignal(task);
			break;
		}

		case ONRSPDELFUTURESTRATEGYORDER:
		{
			this->processRspDelFutureStrategyOrder(task);
			break;
		}

		case ONRSPDELALGOPARM:
		{
			this->processRspDelAlgoParm(task);
			break;
		}

		case ONRSPSETSPREADINSTRSTRATEGY:
		{
			this->processRspSetSpreadInstrStrategy(task);
			break;
		}

		case ONRSPQRYSPREADINSTRSTRATEGY:
		{
			this->processRspQrySpreadInstrStrategy(task);
			break;
		}

		case ONRSPDELSPREADINSTRSTRATEGY:
		{
			this->processRspDelSpreadInstrStrategy(task);
			break;
		}

		case ONRSPQRYINNERSPREADINSTRSTRATEGY:
		{
			this->processRspQryInnerSpreadInstrStrategy(task);
			break;
		}

		case ONRTNINNERSPREADINSTRSTRATEGY:
		{
			this->processRtnInnerSpreadInstrStrategy(task);
			break;
		}

		case ONRSPSETTZEROHIGHSTOCKSTRATEGY:
		{
			this->processRspSetTZeroHighStockStrategy(task);
			break;
		}

		case ONRSPQRYTZEROHIGHSTOCKSTRATEGY:
		{
			this->processRspQryTZeroHighStockStrategy(task);
			break;
		}

		case ONRTNSTRAGEDYMESSAGE:
		{
			this->processRtnStragedyMessage(task);
			break;
		}

		case ONRSPSETFUTRUETRADEINSTR:
		{
			this->processRspSetfutruetradeinstr(task);
			break;
		}

		case ONRSPQRYFLOWERFUTURETARGETMONEY:
		{
			this->processRspQryFlowerFutureTargetMoney(task);
			break;
		}

		case ONRSPSETFLOWERFUTURETARGETMONEY:
		{
			this->processRspSetFlowerFutureTargetMoney(task);
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

		case ONRSPSETFUTURESTRATEGYTOTALSECONDRELATIONPARAM:
		{
			this->processRspSetFutureStrategyTotalSecondRelationParam(task);
			break;
		}

		case ONRTNHIGHINNERFUTURESTRATEGYTOTALSECONDRELATION:
		{
			this->processRtnHighInnerFutureStrategyTotalSecondRelation(task);
			break;
		}

		case ONRSPQRYALLTOTALSECONDSTRATEGYRELATION:
		{
			this->processRspQryAllTotalSecondStrategyRelation(task);
			break;
		}

		case ONRSPDELHIGHSTOCKSTRATEGYTOTALSECONDRELATIONPARAM:
		{
			this->processRspDelHighStockStrategyTotalSecondRelationParam(task);
			break;
		}

		case ONRSPQRYALLINNERTOTALSECONDSTRATEGYRELATION:
		{
			this->processRspQryAllInnerTotalSecondStrategyRelation(task);
			break;
		}

		case ONRSPQRYPARENTDETIALUPDATEMESSAGE:
		{
			this->processRspQryParentDetialUpdateMessage(task);
			break;
		}

		case ONRSPQRYPARENTORDERSTATICPARAM:
		{
			this->processRspQryParentOrderStaticParam(task);
			break;
		}

		case ONRTNPARENTDETIALUPDATEMESSAGE:
		{
			this->processRtnParentDetialUpdateMessage(task);
			break;
		}

		case ONRSPSETPARENTORDERSTATICPARAM:
		{
			this->processRspSetParentOrderStaticParam(task);
			break;
		}

		case ONRSPDELPARENTORDERSTATICPARAM:
		{
			this->processRspDelParentOrderStaticParam(task);
			break;
		}

		case ONRSPQRYJAVAALGOSTATUS:
		{
			this->processRspQryJavaAlgoStatus(task);
			break;
		}

		case ONRTNJAVAALGOSTATUS:
		{
			this->processRtnJavaAlgoStatus(task);
			break;
		}

		case ONRSPQRYFUSKACCOUNTRELATION:
		{
			this->processRspQryFuSkAccountRelation(task);
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

		case ONRSPSETUSERINVESTORSEATBASEPASSWD:
		{
			this->processRspSetUserInvestorSeatBasePasswd(task);
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

		case ONRSPQRYUNFINSHPUTUREORDER:
		{
			this->processRspQryUnFinshPutureOrder(task);
			break;
		}

		case ONRSPQRYTODAYTAYOUTDETAILS:
		{
			this->processRspQryTodayTayoutDetails(task);
			break;
		}


		}
	}
}

void UserApi::processFrontConnected(Task task)
{
	PyLock lock;
	this->onFrontConnected();
};

void UserApi::processFrontDisconnected(Task task)
{
	PyLock lock;
	this->onFrontDisconnected(task.task_id);
};

void UserApi::processHeartBeatWarning(Task task)
{
	PyLock lock;
	this->onHeartBeatWarning(task.task_id);
};

void UserApi::processRspError(Task task)
{
	PyLock lock;
	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspError(error, task.task_id, task.task_last);
};

void UserApi::processRspUserLogin(Task task)
{
	PyLock lock;
	CFocusFtdcRspUserLoginField task_data = any_cast<CFocusFtdcRspUserLoginField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["LoginTime"] = task_data.LoginTime;
	data["MaxOrderLocalID"] = GBK_TO_UTF8(task_data.MaxOrderLocalID);
	data["TradingSystemName"] = GBK_TO_UTF8(task_data.TradingSystemName);
	data["DataCenterID"] = task_data.DataCenterID;
	data["PrivateFlowSize"] = task_data.PrivateFlowSize;
	data["UserFlowSize"] = task_data.UserFlowSize;
	data["LoginInfo"] = GBK_TO_UTF8(task_data.LoginInfo);
	data["SessionID"] = task_data.SessionID;
	data["FrontID"] = task_data.FrontID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUserLogin(data, error, task.task_id, task.task_last);
};

void UserApi::processRspUserLogout(Task task)
{
	PyLock lock;
	CFocusFtdcRspUserLogoutField task_data = any_cast<CFocusFtdcRspUserLogoutField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUserLogout(data, error, task.task_id, task.task_last);
};

void UserApi::processRspUserPasswordUpdate(Task task)
{
	PyLock lock;
	CFocusFtdcUserPasswordUpdateField task_data = any_cast<CFocusFtdcUserPasswordUpdateField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["OldPassword"] = task_data.OldPassword;
	data["NewPassword"] = task_data.NewPassword;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUserPasswordUpdate(data, error, task.task_id, task.task_last);
};

void UserApi::processRspForceUserExit(Task task)
{
	PyLock lock;
	CFocusFtdcForceUserExitField task_data = any_cast<CFocusFtdcForceUserExitField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspForceUserExit(data, error, task.task_id, task.task_last);
};

void UserApi::processRspForceUserLogout(Task task)
{
	PyLock lock;
	CFocusFtdcForceUserExitField task_data = any_cast<CFocusFtdcForceUserExitField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspForceUserLogout(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDumpMemDB(Task task)
{
	PyLock lock;
	CFocusFtdcMemDBField task_data = any_cast<CFocusFtdcMemDBField>(task.task_data);
	dict data;
	data["MemTableName"] = GBK_TO_UTF8(task_data.MemTableName);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDumpMemDB(data, error, task.task_id, task.task_last);
};

void UserApi::processRspOrderInsert(Task task)
{
	PyLock lock;
	CFocusFtdcInputOrderField task_data = any_cast<CFocusFtdcInputOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BusinessType"] = task_data.BusinessType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspOrderInsert(data, error, task.task_id, task.task_last);
};

void UserApi::processRspOrderAction(Task task)
{
	PyLock lock;
	CFocusFtdcOrderActionField task_data = any_cast<CFocusFtdcOrderActionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UserOrderActionLocalID"] = GBK_TO_UTF8(task_data.UserOrderActionLocalID);
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

void UserApi::processRspAccountDeposit(Task task)
{
	PyLock lock;
	CFocusFtdcRspAccountDepositField task_data = any_cast<CFocusFtdcRspAccountDepositField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["AccountID"] = task_data.AccountID;
	data["AccountSeqNo"] = task_data.AccountSeqNo;
	data["Amount"] = task_data.Amount;
	data["AmountDirection"] = task_data.AmountDirection;
	data["Available"] = task_data.Available;
	data["Balance"] = task_data.Balance;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspAccountDeposit(data, error, task.task_id, task.task_last);
};

void UserApi::processRspInvestorRight(Task task)
{
	PyLock lock;
	CFocusFtdcInvestorRightField task_data = any_cast<CFocusFtdcInvestorRightField>(task.task_data);
	dict data;
	data["InvestorID"] = task_data.InvestorID;
	data["PositionType"] = task_data.PositionType;
	data["SelfTradeAvoidType"] = task_data.SelfTradeAvoidType;
	data["TradingRight"] = task_data.TradingRight;
	data["CheckAccount"] = task_data.CheckAccount;
	data["CheckPosition"] = task_data.CheckPosition;
	data["OrderWarning"] = task_data.OrderWarning;
	data["QryUpAccPosi"] = task_data.QryUpAccPosi;
	data["DistributeType"] = task_data.DistributeType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspInvestorRight(data, error, task.task_id, task.task_last);
};

void UserApi::processRspTBCommand(Task task)
{
	PyLock lock;
	CFocusFtdcTBCommandField task_data = any_cast<CFocusFtdcTBCommandField>(task.task_data);
	dict data;
	data["CommandNo"] = task_data.CommandNo;
	data["CommandDate"] = task_data.CommandDate;
	data["CommandTime"] = task_data.CommandTime;
	data["CommandType"] = task_data.CommandType;
	data["FieldName"] = GBK_TO_UTF8(task_data.FieldName);
	data["FieldContent"] = task_data.FieldContent;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspTBCommand(data, error, task.task_id, task.task_last);
};

void UserApi::processRspPingPong(Task task)
{
	PyLock lock;
	CFocusFtdcPingPongField task_data = any_cast<CFocusFtdcPingPongField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["SequenceNo"] = task_data.SequenceNo;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspPingPong(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetAdviceRunMode(Task task)
{
	PyLock lock;
	CFocusFtdcAdviceRunModeField task_data = any_cast<CFocusFtdcAdviceRunModeField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["RunMode"] = task_data.RunMode;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetAdviceRunMode(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnDepthMarketData(Task task)
{
	PyLock lock;
	CFocusFtdcDepthMarketDataField task_data = any_cast<CFocusFtdcDepthMarketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["PreDelta"] = task_data.PreDelta;
	data["StkOrderStatus"] = task_data.StkOrderStatus;
	data["OpenPrice"] = task_data.OpenPrice;
	data["HighestPrice"] = task_data.HighestPrice;
	data["LowestPrice"] = task_data.LowestPrice;
	data["ClosePrice"] = task_data.ClosePrice;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["SettlementPrice"] = task_data.SettlementPrice;
	data["CurrDelta"] = task_data.CurrDelta;
	data["LastPrice"] = task_data.LastPrice;
	data["Volume"] = task_data.Volume;
	data["Turnover"] = task_data.Turnover;
	data["OpenInterest"] = task_data.OpenInterest;
	data["BidPrice1"] = task_data.BidPrice1;
	data["BidVolume1"] = task_data.BidVolume1;
	data["AskPrice1"] = task_data.AskPrice1;
	data["AskVolume1"] = task_data.AskVolume1;
	data["BidPrice2"] = task_data.BidPrice2;
	data["BidVolume2"] = task_data.BidVolume2;
	data["BidPrice3"] = task_data.BidPrice3;
	data["BidVolume3"] = task_data.BidVolume3;
	data["AskPrice2"] = task_data.AskPrice2;
	data["AskVolume2"] = task_data.AskVolume2;
	data["AskPrice3"] = task_data.AskPrice3;
	data["AskVolume3"] = task_data.AskVolume3;
	data["BidPrice4"] = task_data.BidPrice4;
	data["BidVolume4"] = task_data.BidVolume4;
	data["BidPrice5"] = task_data.BidPrice5;
	data["BidVolume5"] = task_data.BidVolume5;
	data["AskPrice4"] = task_data.AskPrice4;
	data["AskVolume4"] = task_data.AskVolume4;
	data["AskPrice5"] = task_data.AskPrice5;
	data["AskVolume5"] = task_data.AskVolume5;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;
	data["ExchangeID"] = task_data.ExchangeID;
	data["VolumeAskLot"] = task_data.VolumeAskLot;
	data["VolumeBidLot"] = task_data.VolumeBidLot;

	this->onRtnDepthMarketData(data);
};

void UserApi::processRtnMultiDepthMarketData(Task task)
{
	PyLock lock;
	CFocusFtdcDepthMarketDataField task_data = any_cast<CFocusFtdcDepthMarketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["PreDelta"] = task_data.PreDelta;
	data["StkOrderStatus"] = task_data.StkOrderStatus;
	data["OpenPrice"] = task_data.OpenPrice;
	data["HighestPrice"] = task_data.HighestPrice;
	data["LowestPrice"] = task_data.LowestPrice;
	data["ClosePrice"] = task_data.ClosePrice;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["SettlementPrice"] = task_data.SettlementPrice;
	data["CurrDelta"] = task_data.CurrDelta;
	data["LastPrice"] = task_data.LastPrice;
	data["Volume"] = task_data.Volume;
	data["Turnover"] = task_data.Turnover;
	data["OpenInterest"] = task_data.OpenInterest;
	data["BidPrice1"] = task_data.BidPrice1;
	data["BidVolume1"] = task_data.BidVolume1;
	data["AskPrice1"] = task_data.AskPrice1;
	data["AskVolume1"] = task_data.AskVolume1;
	data["BidPrice2"] = task_data.BidPrice2;
	data["BidVolume2"] = task_data.BidVolume2;
	data["BidPrice3"] = task_data.BidPrice3;
	data["BidVolume3"] = task_data.BidVolume3;
	data["AskPrice2"] = task_data.AskPrice2;
	data["AskVolume2"] = task_data.AskVolume2;
	data["AskPrice3"] = task_data.AskPrice3;
	data["AskVolume3"] = task_data.AskVolume3;
	data["BidPrice4"] = task_data.BidPrice4;
	data["BidVolume4"] = task_data.BidVolume4;
	data["BidPrice5"] = task_data.BidPrice5;
	data["BidVolume5"] = task_data.BidVolume5;
	data["AskPrice4"] = task_data.AskPrice4;
	data["AskVolume4"] = task_data.AskVolume4;
	data["AskPrice5"] = task_data.AskPrice5;
	data["AskVolume5"] = task_data.AskVolume5;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;
	data["ExchangeID"] = task_data.ExchangeID;
	data["VolumeAskLot"] = task_data.VolumeAskLot;
	data["VolumeBidLot"] = task_data.VolumeBidLot;

	this->onRtnMultiDepthMarketData(data);
};

void UserApi::processRspSubMarketData(Task task)
{
	PyLock lock;
	CFocusFtdcSpecificInstrumentField task_data = any_cast<CFocusFtdcSpecificInstrumentField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSubMarketData(data, error, task.task_id, task.task_last);
};

void UserApi::processRspUnSubMarketData(Task task)
{
	PyLock lock;
	CFocusFtdcSpecificInstrumentField task_data = any_cast<CFocusFtdcSpecificInstrumentField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUnSubMarketData(data, error, task.task_id, task.task_last);
};

void UserApi::processRspTopicSearch(Task task)
{
	PyLock lock;
	CFocusFtdcTopicSearchField task_data = any_cast<CFocusFtdcTopicSearchField>(task.task_data);
	dict data;
	data["TopicID"] = task_data.TopicID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspTopicSearch(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnMBLMarketData(Task task)
{
	PyLock lock;
	CFocusFtdcMBLMarketDataField task_data = any_cast<CFocusFtdcMBLMarketDataField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["Direction"] = task_data.Direction;
	data["Price"] = task_data.Price;
	data["Volume"] = task_data.Volume;
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;

	this->onRtnMBLMarketData(data);
};

void UserApi::processRtnQmdInstrumentStatu(Task task)
{
	PyLock lock;
	CFocusFtdcQmdInstrumentStateField task_data = any_cast<CFocusFtdcQmdInstrumentStateField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["InstrumentStatus"] = task_data.InstrumentStatus;

	this->onRtnQmdInstrumentStatu(data);
};

void UserApi::processRtnFlowMessageCancel(Task task)
{
	PyLock lock;
	CFocusFtdcFlowMessageCancelField task_data = any_cast<CFocusFtdcFlowMessageCancelField>(task.task_data);
	dict data;
	data["SequenceSeries"] = task_data.SequenceSeries;
	data["TradingDay"] = task_data.TradingDay;
	data["DataCenterID"] = task_data.DataCenterID;
	data["StartSequenceNo"] = task_data.StartSequenceNo;
	data["EndSequenceNo"] = task_data.EndSequenceNo;

	this->onRtnFlowMessageCancel(data);
};

void UserApi::processRtnTrade(Task task)
{
	PyLock lock;
	CFocusFtdcTradeField task_data = any_cast<CFocusFtdcTradeField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["TradeID"] = task_data.TradeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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

void UserApi::processRtnOrder(Task task)
{
	PyLock lock;
	CFocusFtdcOrderField task_data = any_cast<CFocusFtdcOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BusinessType"] = task_data.BusinessType;
	data["TradingDay"] = task_data.TradingDay;
	data["InsertTime"] = task_data.InsertTime;
	data["OrderSource"] = task_data.OrderSource;
	data["OrderStatus"] = task_data.OrderStatus;
	data["CancelTime"] = task_data.CancelTime;
	data["CancelUserID"] = GBK_TO_UTF8(task_data.CancelUserID);
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
	data["BranchID"] = GBK_TO_UTF8(task_data.BranchID);
	data["RecNum"] = task_data.RecNum;

	this->onRtnOrder(data);
};

void UserApi::processErrRtnOrderInsert(Task task)
{
	PyLock lock;
	CFocusFtdcInputOrderField task_data = any_cast<CFocusFtdcInputOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BusinessType"] = task_data.BusinessType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onErrRtnOrderInsert(data, error);
};

void UserApi::processErrRtnOrderAction(Task task)
{
	PyLock lock;
	CFocusFtdcOrderActionField task_data = any_cast<CFocusFtdcOrderActionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UserOrderActionLocalID"] = GBK_TO_UTF8(task_data.UserOrderActionLocalID);
	data["ActionFlag"] = task_data.ActionFlag;
	data["LimitPrice"] = task_data.LimitPrice;
	data["VolumeChange"] = task_data.VolumeChange;
	data["FrontID"] = task_data.FrontID;
	data["SessionID"] = task_data.SessionID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onErrRtnOrderAction(data, error);
};

void UserApi::processRtnInstrumentStatus(Task task)
{
	PyLock lock;
	CFocusFtdcInstrumentStatusField task_data = any_cast<CFocusFtdcInstrumentStatusField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["ProductName"] = GBK_TO_UTF8(task_data.ProductName);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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

void UserApi::processRtnInvestorAccountDeposit(Task task)
{
	PyLock lock;
	CFocusFtdcInvestorAccountDepositResField task_data = any_cast<CFocusFtdcInvestorAccountDepositResField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["AccountID"] = task_data.AccountID;
	data["AccountSeqNo"] = task_data.AccountSeqNo;
	data["Amount"] = task_data.Amount;
	data["AmountDirection"] = task_data.AmountDirection;
	data["Available"] = task_data.Available;
	data["Balance"] = task_data.Balance;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);

	this->onRtnInvestorAccountDeposit(data);
};

void UserApi::processRtnMessageNotify(Task task)
{
	PyLock lock;
	CFocusFtdcMessageNotifyField task_data = any_cast<CFocusFtdcMessageNotifyField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["Nums"] = task_data.Nums;
	data["WarnLevel"] = task_data.WarnLevel;
	data["WarnID"] = task_data.WarnID;
	data["WarnMsg"] = GBK_TO_UTF8(task_data.WarnMsg);
	data["WarnTime"] = task_data.WarnTime;

	this->onRtnMessageNotify(data);
};

void UserApi::processRtnAdviceOrder(Task task)
{
	PyLock lock;
	CFocusFtdcAdviceOrderField task_data = any_cast<CFocusFtdcAdviceOrderField>(task.task_data);
	dict data;
	data["InvestorAdvicer"] = task_data.InvestorAdvicer;
	data["InvestorManager"] = task_data.InvestorManager;
	data["UserTrader"] = GBK_TO_UTF8(task_data.UserTrader);
	data["VolumeFrozen"] = task_data.VolumeFrozen;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BusinessType"] = task_data.BusinessType;
	data["TradingDay"] = task_data.TradingDay;
	data["InsertTime"] = task_data.InsertTime;
	data["OrderSource"] = task_data.OrderSource;
	data["OrderStatus"] = task_data.OrderStatus;
	data["CancelTime"] = task_data.CancelTime;
	data["CancelUserID"] = GBK_TO_UTF8(task_data.CancelUserID);
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
	data["BranchID"] = GBK_TO_UTF8(task_data.BranchID);
	data["RecNum"] = task_data.RecNum;
	data["AdviceUserInfo"] = GBK_TO_UTF8(task_data.AdviceUserInfo);

	this->onRtnAdviceOrder(data);
};

void UserApi::processRtnSubInstrumentStatus(Task task)
{
	PyLock lock;
	CFocusFtdcSubInstrumentStatusField task_data = any_cast<CFocusFtdcSubInstrumentStatusField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["InstrumentStatus"] = task_data.InstrumentStatus;
	data["EnterTime"] = task_data.EnterTime;
	data["EnterReason"] = task_data.EnterReason;

	this->onRtnSubInstrumentStatus(data);
};

void UserApi::processRspQryOrder(Task task)
{
	PyLock lock;
	CFocusFtdcOrderField task_data = any_cast<CFocusFtdcOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BusinessType"] = task_data.BusinessType;
	data["TradingDay"] = task_data.TradingDay;
	data["InsertTime"] = task_data.InsertTime;
	data["OrderSource"] = task_data.OrderSource;
	data["OrderStatus"] = task_data.OrderStatus;
	data["CancelTime"] = task_data.CancelTime;
	data["CancelUserID"] = GBK_TO_UTF8(task_data.CancelUserID);
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
	data["BranchID"] = GBK_TO_UTF8(task_data.BranchID);
	data["RecNum"] = task_data.RecNum;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryOrder(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryTrade(Task task)
{
	PyLock lock;
	CFocusFtdcTradeField task_data = any_cast<CFocusFtdcTradeField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["TradeID"] = task_data.TradeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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

void UserApi::processRspQryUserInvestor(Task task)
{
	PyLock lock;
	CFocusFtdcRspUserInvestorField task_data = any_cast<CFocusFtdcRspUserInvestorField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["NextUserID"] = GBK_TO_UTF8(task_data.NextUserID);
	data["OrderMode"] = task_data.OrderMode;
	data["RunMode"] = task_data.RunMode;
	data["AdviceSwitchFlag"] = task_data.AdviceSwitchFlag;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryUserInvestor(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInvestorAccount(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorAccountField task_data = any_cast<CFocusFtdcRspInvestorAccountField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["AccountID"] = task_data.AccountID;
	data["InvestorPasswd"] = task_data.InvestorPasswd;
	data["PreBalance"] = task_data.PreBalance;
	data["PreAvailable"] = task_data.PreAvailable;
	data["Deposit"] = task_data.Deposit;
	data["Withdraw"] = task_data.Withdraw;
	data["Margin"] = task_data.Margin;
	data["Premium"] = task_data.Premium;
	data["Fee"] = task_data.Fee;
	data["FrozenMargin"] = task_data.FrozenMargin;
	data["FrozenPremium"] = task_data.FrozenPremium;
	data["FrozenFee"] = task_data.FrozenFee;
	data["CloseProfit"] = task_data.CloseProfit;
	data["PositionProfit"] = task_data.PositionProfit;
	data["Available"] = task_data.Available;
	data["Balance"] = task_data.Balance;
	data["LongMargin"] = task_data.LongMargin;
	data["ShortMargin"] = task_data.ShortMargin;
	data["LongFrozenMargin"] = task_data.LongFrozenMargin;
	data["ShortFrozenMargin"] = task_data.ShortFrozenMargin;
	data["DynamicRights"] = task_data.DynamicRights;
	data["Risk"] = task_data.Risk;
	data["OtherFee"] = task_data.OtherFee;
	data["Mortgage"] = task_data.Mortgage;
	data["Currency"] = task_data.Currency;
	data["WithdrawQuota"] = task_data.WithdrawQuota;
	data["TransferFee"] = task_data.TransferFee;
	data["FrozenTransferFee"] = task_data.FrozenTransferFee;
	data["StampTax"] = task_data.StampTax;
	data["FrozenStampTax"] = task_data.FrozenStampTax;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInvestorAccount(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInstrument(Task task)
{
	PyLock lock;
	CFocusFtdcRspInstrumentField task_data = any_cast<CFocusFtdcRspInstrumentField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["ProductName"] = GBK_TO_UTF8(task_data.ProductName);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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

void UserApi::processRspQryExchange(Task task)
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

void UserApi::processRspQryInvestorPosition(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorPositionField task_data = any_cast<CFocusFtdcRspInvestorPositionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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
	data["LastOrderLocalID"] = GBK_TO_UTF8(task_data.LastOrderLocalID);
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

void UserApi::processRspSubscribeTopic(Task task)
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

void UserApi::processRspQryTopic(Task task)
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

void UserApi::processRspQryUser(Task task)
{
	PyLock lock;
	CFocusFtdcRspUserField task_data = any_cast<CFocusFtdcRspUserField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["Password"] = task_data.Password;
	data["GroupID"] = task_data.GroupID;
	data["GroupName"] = GBK_TO_UTF8(task_data.GroupName);
	data["IsActive"] = task_data.IsActive;
	data["UserName"] = GBK_TO_UTF8(task_data.UserName);
	data["UserType"] = task_data.UserType;
	data["Department"] = task_data.Department;
	data["GrantFuncSet"] = task_data.GrantFuncSet;
	data["MaxOnline"] = task_data.MaxOnline;
	data["IPAddress"] = task_data.IPAddress;
	data["CheckProductInfo"] = task_data.CheckProductInfo;
	data["MacAddress"] = task_data.MacAddress;
	data["CheckIPMacAddr"] = task_data.CheckIPMacAddr;
	data["LoginErrorLimit"] = task_data.LoginErrorLimit;
	data["LoginErrorCount"] = task_data.LoginErrorCount;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryUser(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInvestorFee(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorFeeField task_data = any_cast<CFocusFtdcRspInvestorFeeField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["OpenFeeRate"] = task_data.OpenFeeRate;
	data["OpenFeeAmt"] = task_data.OpenFeeAmt;
	data["OffsetFeeRate"] = task_data.OffsetFeeRate;
	data["OffsetFeeAmt"] = task_data.OffsetFeeAmt;
	data["OTFeeRate"] = task_data.OTFeeRate;
	data["OTFeeAmt"] = task_data.OTFeeAmt;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInvestorFee(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInvestorMargin(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorMarginField task_data = any_cast<CFocusFtdcRspInvestorMarginField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["LongMarginRate"] = task_data.LongMarginRate;
	data["LongMarginAmt"] = task_data.LongMarginAmt;
	data["ShortMarginRate"] = task_data.ShortMarginRate;
	data["ShortMarginAmt"] = task_data.ShortMarginAmt;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInvestorMargin(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInvestor(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorField task_data = any_cast<CFocusFtdcRspInvestorField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["InvestorPasswd"] = task_data.InvestorPasswd;
	data["InvestorName"] = GBK_TO_UTF8(task_data.InvestorName);
	data["InvestorType"] = task_data.InvestorType;
	data["ClientType"] = task_data.ClientType;
	data["SSERegId"] = task_data.SSERegId;
	data["SZSERegId"] = task_data.SZSERegId;
	data["SHFERegId"] = task_data.SHFERegId;
	data["ZCERegId"] = task_data.ZCERegId;
	data["DCERegId"] = task_data.DCERegId;
	data["GroupID"] = task_data.GroupID;
	data["GroupName"] = GBK_TO_UTF8(task_data.GroupName);
	data["Alias"] = task_data.Alias;
	data["LinkType"] = task_data.LinkType;
	data["F_TerminalId"] = task_data.F_TerminalId;
	data["ParentInvestorID"] = task_data.ParentInvestorID;
	data["LoginStatus"] = task_data.LoginStatus;
	data["PositionType"] = task_data.PositionType;
	data["SelfTradeAvoidType"] = task_data.SelfTradeAvoidType;
	data["TradingRight"] = task_data.TradingRight;
	data["CheckAccount"] = task_data.CheckAccount;
	data["CheckPosition"] = task_data.CheckPosition;
	data["OrderWarning"] = task_data.OrderWarning;
	data["QryUpAccPosi"] = task_data.QryUpAccPosi;
	data["DistributeType"] = task_data.DistributeType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInvestor(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryAccountRisk(Task task)
{
	PyLock lock;
	CFocusFtdcRspAccountRiskField task_data = any_cast<CFocusFtdcRspAccountRiskField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["AccountID"] = task_data.AccountID;
	data["SetBalance"] = task_data.SetBalance;
	data["OpenAvailable"] = task_data.OpenAvailable;
	data["OffsetAvailable"] = task_data.OffsetAvailable;
	data["AccountStatus"] = task_data.AccountStatus;
	data["DynamicRights"] = task_data.DynamicRights;
	data["TradingRight"] = task_data.TradingRight;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAccountRisk(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryUserSession(Task task)
{
	PyLock lock;
	CFocusFtdcRspUserSessionField task_data = any_cast<CFocusFtdcRspUserSessionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserType"] = task_data.UserType;
	data["SessionID"] = task_data.SessionID;
	data["FrontID"] = task_data.FrontID;
	data["LoginTime"] = task_data.LoginTime;
	data["IPAddress"] = task_data.IPAddress;
	data["MacAddress"] = task_data.MacAddress;
	data["UserProductInfo"] = GBK_TO_UTF8(task_data.UserProductInfo);
	data["InterfaceProductInfo"] = GBK_TO_UTF8(task_data.InterfaceProductInfo);
	data["ProtocolInfo"] = GBK_TO_UTF8(task_data.ProtocolInfo);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryUserSession(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryMarketData(Task task)
{
	PyLock lock;
	CFocusFtdcRspMarketDataField task_data = any_cast<CFocusFtdcRspMarketDataField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["TradingDay"] = task_data.TradingDay;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["PreDelta"] = task_data.PreDelta;
	data["StkOrderStatus"] = task_data.StkOrderStatus;
	data["OpenPrice"] = task_data.OpenPrice;
	data["HighestPrice"] = task_data.HighestPrice;
	data["LowestPrice"] = task_data.LowestPrice;
	data["ClosePrice"] = task_data.ClosePrice;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["SettlementPrice"] = task_data.SettlementPrice;
	data["CurrDelta"] = task_data.CurrDelta;
	data["LastPrice"] = task_data.LastPrice;
	data["Volume"] = task_data.Volume;
	data["Turnover"] = task_data.Turnover;
	data["OpenInterest"] = task_data.OpenInterest;
	data["BidPrice1"] = task_data.BidPrice1;
	data["BidVolume1"] = task_data.BidVolume1;
	data["AskPrice1"] = task_data.AskPrice1;
	data["AskVolume1"] = task_data.AskVolume1;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMarketData(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInvestorRelation(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorRelationField task_data = any_cast<CFocusFtdcRspInvestorRelationField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["ParentInvestorID"] = task_data.ParentInvestorID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInvestorRelation(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryProduct(Task task)
{
	PyLock lock;
	CFocusFtdcRspProductField task_data = any_cast<CFocusFtdcRspProductField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
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

void UserApi::processRspQryAdviceTrader(Task task)
{
	PyLock lock;
	CFocusFtdcRspAdviceTraderField task_data = any_cast<CFocusFtdcRspAdviceTraderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["RelationUserID"] = GBK_TO_UTF8(task_data.RelationUserID);
	data["RelationUserName"] = GBK_TO_UTF8(task_data.RelationUserName);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAdviceTrader(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryMaxVolume(Task task)
{
	PyLock lock;
	CFocusFtdcRspMaxVolumeField task_data = any_cast<CFocusFtdcRspMaxVolumeField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["LimitPrice"] = task_data.LimitPrice;
	data["Volume"] = task_data.Volume;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMaxVolume(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryCmbPositionDetail(Task task)
{
	PyLock lock;
	CFocusFtdcRspCmbPositionDetailField task_data = any_cast<CFocusFtdcRspCmbPositionDetailField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["CmbInstrumentID"] = GBK_TO_UTF8(task_data.CmbInstrumentID);
	data["TradeID"] = task_data.TradeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["Direction"] = task_data.Direction;
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["Position"] = task_data.Position;
	data["LegQty"] = task_data.LegQty;
	data["TradingDay"] = task_data.TradingDay;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryCmbPositionDetail(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQrySettlementInfo(Task task)
{
	PyLock lock;
	CFocusFtdcRspSettlementInfoField task_data = any_cast<CFocusFtdcRspSettlementInfoField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["SequenceNo"] = task_data.SequenceNo;
	data["Content"] = task_data.Content;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQrySettlementInfo(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSubInstrument(Task task)
{
	PyLock lock;
	CFocusFtdcSubSpecificInstrumentField task_data = any_cast<CFocusFtdcSubSpecificInstrumentField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSubInstrument(data, error, task.task_id, task.task_last);
};

void UserApi::processRspUnSubInstrument(Task task)
{
	PyLock lock;
	CFocusFtdcSubSpecificInstrumentField task_data = any_cast<CFocusFtdcSubSpecificInstrumentField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUnSubInstrument(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryResultPage(Task task)
{
	PyLock lock;
	CFocusFtdcQryResultPageField task_data = any_cast<CFocusFtdcQryResultPageField>(task.task_data);
	dict data;
	data["ResultID"] = task_data.ResultID;
	data["Count"] = task_data.Count;
	data["Pages"] = task_data.Pages;
	data["Remain"] = task_data.Remain;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryResultPage(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInvestorPositionDetail(Task task)
{
	PyLock lock;
	CFocusFtdcRspPositionDetailField task_data = any_cast<CFocusFtdcRspPositionDetailField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["HedgeFlag"] = task_data.HedgeFlag;
	data["Direction"] = task_data.Direction;
	data["OpenDate"] = task_data.OpenDate;
	data["TradeID"] = task_data.TradeID;
	data["Volume"] = task_data.Volume;
	data["OpenPrice"] = task_data.OpenPrice;
	data["TradingDay"] = task_data.TradingDay;
	data["TradeType"] = task_data.TradeType;
	data["CombInstrumentID"] = GBK_TO_UTF8(task_data.CombInstrumentID);
	data["CloseProfitByDate"] = task_data.CloseProfitByDate;
	data["CloseProfitByTrade"] = task_data.CloseProfitByTrade;
	data["PositionProfitByDate"] = task_data.PositionProfitByDate;
	data["PositionProfitByTrade"] = task_data.PositionProfitByTrade;
	data["Margin"] = task_data.Margin;
	data["ExchMargin"] = task_data.ExchMargin;
	data["MarginRateByMoney"] = task_data.MarginRateByMoney;
	data["MarginRateByVolume"] = task_data.MarginRateByVolume;
	data["LastSettlementPrice"] = task_data.LastSettlementPrice;
	data["SettlementPrice"] = task_data.SettlementPrice;
	data["CloseVolume"] = task_data.CloseVolume;
	data["CloseAmount"] = task_data.CloseAmount;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInvestorPositionDetail(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnTheoryPriceData(Task task)
{
	PyLock lock;
	CFocusFtdcTheoryPriceDataField task_data = any_cast<CFocusFtdcTheoryPriceDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["TheoryPrice"] = task_data.TheoryPrice;
	data["TheoryVol"] = task_data.TheoryVol;
	data["UnderlyingLastPrice"] = task_data.UnderlyingLastPrice;
	data["UnderlyingBidPrice1"] = task_data.UnderlyingBidPrice1;
	data["UnderlyingAskPrice1"] = task_data.UnderlyingAskPrice1;
	data["RemainDay"] = task_data.RemainDay;

	this->onRtnTheoryPriceData(data);
};

void UserApi::processRtnOptionIndexData(Task task)
{
	PyLock lock;
	CFocusFtdcOptionIndexDataField task_data = any_cast<CFocusFtdcOptionIndexDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["Delta"] = task_data.Delta;
	data["Gamma"] = task_data.Gamma;
	data["Vega"] = task_data.Vega;
	data["Theta"] = task_data.Theta;
	data["Rho"] = task_data.Rho;
	data["BidVol"] = task_data.BidVol;
	data["AskVol"] = task_data.AskVol;
	data["MidVol"] = task_data.MidVol;
	data["LastVol"] = task_data.LastVol;
	data["LastPrice"] = task_data.LastPrice;
	data["BidPrice1"] = task_data.BidPrice1;
	data["AskPrice1"] = task_data.AskPrice1;
	data["TheoryVol"] = task_data.TheoryVol;
	data["UnderlyingLastPrice"] = task_data.UnderlyingLastPrice;
	data["UnderlyingBidPrice1"] = task_data.UnderlyingBidPrice1;
	data["UnderlyingAskPrice1"] = task_data.UnderlyingAskPrice1;
	data["RemainDay"] = task_data.RemainDay;
	data["IsManalSetVol"] = task_data.IsManalSetVol;
	data["AtmVol"] = task_data.AtmVol;

	this->onRtnOptionIndexData(data);
};

void UserApi::processRspSetPricingParam(Task task)
{
	PyLock lock;
	CFocusFtdcPricingParamField task_data = any_cast<CFocusFtdcPricingParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UnderlyingId"] = task_data.UnderlyingId;
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["PriceLevel1"] = task_data.PriceLevel1;
	data["PriceLevel2"] = task_data.PriceLevel2;
	data["PriceLevel3"] = task_data.PriceLevel3;
	data["CalcDayType"] = task_data.CalcDayType;
	data["YearTotalDay"] = task_data.YearTotalDay;
	data["CalcTimeType"] = task_data.CalcTimeType;
	data["RiskFreeRate"] = task_data.RiskFreeRate;
	data["Dividend"] = task_data.Dividend;
	data["PricingEngine"] = task_data.PricingEngine;
	data["ExerciseType"] = task_data.ExerciseType;
	data["VolTolerance"] = task_data.VolTolerance;
	data["VolType"] = task_data.VolType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetPricingParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetOptionTheoryVol(Task task)
{
	PyLock lock;
	CFocusFtdcOptionTheoryVolField task_data = any_cast<CFocusFtdcOptionTheoryVolField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["TheoryVol"] = task_data.TheoryVol;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetOptionTheoryVol(data, error, task.task_id, task.task_last);
};

void UserApi::processRspCalcOneOption(Task task)
{
	PyLock lock;
	CFocusFtdcBasePricingParamField task_data = any_cast<CFocusFtdcBasePricingParamField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["CalculateTarget"] = task_data.CalculateTarget;
	data["ExerciseType"] = task_data.ExerciseType;
	data["OptionsType"] = task_data.OptionsType;
	data["UnderlyingPrice"] = task_data.UnderlyingPrice;
	data["StrikePrice"] = task_data.StrikePrice;
	data["RiskFreeRate"] = task_data.RiskFreeRate;
	data["Dividend"] = task_data.Dividend;
	data["RemainDay"] = task_data.RemainDay;
	data["TradingDate"] = task_data.TradingDate;
	data["ExpireDate"] = task_data.ExpireDate;
	data["Vol"] = task_data.Vol;
	data["PricingModel"] = task_data.PricingModel;
	data["OptionPrice"] = task_data.OptionPrice;
	data["ResetFrequency"] = task_data.ResetFrequency;
	data["Delta"] = task_data.Delta;
	data["Gamma"] = task_data.Gamma;
	data["Vega"] = task_data.Vega;
	data["Theta"] = task_data.Theta;
	data["Rho"] = task_data.Rho;
	data["Vanna"] = task_data.Vanna;
	data["Volga"] = task_data.Volga;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspCalcOneOption(data, error, task.task_id, task.task_last);
};

void UserApi::processRspCalcBarrierOption(Task task)
{
	PyLock lock;
	CFocusFtdcDoubleBarrierPricingParamField task_data = any_cast<CFocusFtdcDoubleBarrierPricingParamField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["CalculateTarget"] = task_data.CalculateTarget;
	data["ExerciseType"] = task_data.ExerciseType;
	data["OptionsType"] = task_data.OptionsType;
	data["UnderlyingPrice"] = task_data.UnderlyingPrice;
	data["StrikePrice"] = task_data.StrikePrice;
	data["RiskFreeRate"] = task_data.RiskFreeRate;
	data["Dividend"] = task_data.Dividend;
	data["RemainDay"] = task_data.RemainDay;
	data["TradingDate"] = task_data.TradingDate;
	data["ExpireDate"] = task_data.ExpireDate;
	data["Vol"] = task_data.Vol;
	data["PricingModel"] = task_data.PricingModel;
	data["OptionPrice"] = task_data.OptionPrice;
	data["ResetFrequency"] = task_data.ResetFrequency;
	data["Delta"] = task_data.Delta;
	data["Gamma"] = task_data.Gamma;
	data["Vega"] = task_data.Vega;
	data["Theta"] = task_data.Theta;
	data["Rho"] = task_data.Rho;
	data["Vanna"] = task_data.Vanna;
	data["Volga"] = task_data.Volga;
	data["BarrierType"] = task_data.BarrierType;
	data["LowerBarrierRate"] = task_data.LowerBarrierRate;
	data["UpperBarrierRate"] = task_data.UpperBarrierRate;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspCalcBarrierOption(data, error, task.task_id, task.task_last);
};

void UserApi::processRspVolatilityFitting(Task task)
{
	PyLock lock;
	CFocusFtdcVolatilityFittingField task_data = any_cast<CFocusFtdcVolatilityFittingField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["RemainDay"] = task_data.RemainDay;
	data["StrikePrice"] = task_data.StrikePrice;
	data["Vol"] = task_data.Vol;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspVolatilityFitting(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryWingModelParam(Task task)
{
	PyLock lock;
	CFocusFtdcWingModelParamField task_data = any_cast<CFocusFtdcWingModelParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["FitModel"] = task_data.FitModel;
	data["WingParamType"] = task_data.WingParamType;
	data["TradingDay"] = task_data.TradingDay;
	data["InsertTime"] = task_data.InsertTime;
	data["Atm"] = task_data.Atm;
	data["Days"] = task_data.Days;
	data["ref"] = task_data.ref;
	data["ssr"] = task_data.ssr;
	data["vcr"] = task_data.vcr;
	data["scr"] = task_data.scr;
	data["cc"] = task_data.cc;
	data["uc"] = task_data.uc;
	data["usm"] = task_data.usm;
	data["pc"] = task_data.pc;
	data["dc"] = task_data.dc;
	data["dsm"] = task_data.dsm;
	data["vr"] = task_data.vr;
	data["sr"] = task_data.sr;
	data["vc"] = task_data.vc;
	data["sc"] = task_data.sc;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryWingModelParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetWingModelParam(Task task)
{
	PyLock lock;
	CFocusFtdcWingModelParamField task_data = any_cast<CFocusFtdcWingModelParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["FitModel"] = task_data.FitModel;
	data["WingParamType"] = task_data.WingParamType;
	data["TradingDay"] = task_data.TradingDay;
	data["InsertTime"] = task_data.InsertTime;
	data["Atm"] = task_data.Atm;
	data["Days"] = task_data.Days;
	data["ref"] = task_data.ref;
	data["ssr"] = task_data.ssr;
	data["vcr"] = task_data.vcr;
	data["scr"] = task_data.scr;
	data["cc"] = task_data.cc;
	data["uc"] = task_data.uc;
	data["usm"] = task_data.usm;
	data["pc"] = task_data.pc;
	data["dc"] = task_data.dc;
	data["dsm"] = task_data.dsm;
	data["vr"] = task_data.vr;
	data["sr"] = task_data.sr;
	data["vc"] = task_data.vc;
	data["sc"] = task_data.sc;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetWingModelParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnQuoteTotalTradePrice(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteTotalTradePriceField task_data = any_cast<CFocusFtdcQuoteTotalTradePriceField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["AskTradeVolume"] = task_data.AskTradeVolume;
	data["BidTradeVolume"] = task_data.BidTradeVolume;
	data["BidQuotePrice"] = task_data.BidQuotePrice;
	data["BidQuoteAmount"] = task_data.BidQuoteAmount;
	data["AskQuotePrice"] = task_data.AskQuotePrice;
	data["AskQuoteAmount"] = task_data.AskQuoteAmount;
	data["ForQuoteSendAmount"] = task_data.ForQuoteSendAmount;
	data["ForQuoteTotalAmount"] = task_data.ForQuoteTotalAmount;
	data["BidForQuotePrice"] = task_data.BidForQuotePrice;
	data["BidForQuoteAmount"] = task_data.BidForQuoteAmount;
	data["AskForQuotePrice"] = task_data.AskForQuotePrice;
	data["AskForQuoteAmount"] = task_data.AskForQuoteAmount;
	data["FowardDirection"] = task_data.FowardDirection;

	this->onRtnQuoteTotalTradePrice(data);
};

void UserApi::processRspQryMarkerStrategySet(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerStrategyField task_data = any_cast<CFocusFtdcMarkerStrategyField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["AutoOffer"] = task_data.AutoOffer;
	data["AutoRespAsking"] = task_data.AutoRespAsking;
	data["BidAmount"] = task_data.BidAmount;
	data["AskAmount"] = task_data.AskAmount;
	data["ForQuoteBidAmount"] = task_data.ForQuoteBidAmount;
	data["ForQuoteAskAmount"] = task_data.ForQuoteAskAmount;
	data["BidMax"] = task_data.BidMax;
	data["AskMax"] = task_data.AskMax;
	data["SpreadType"] = task_data.SpreadType;
	data["QuotePriceWidth"] = task_data.QuotePriceWidth;
	data["QuoteWidthRatio"] = task_data.QuoteWidthRatio;
	data["ForQuotePriceWidth"] = task_data.ForQuotePriceWidth;
	data["ForQuoteWidthRatio"] = task_data.ForQuoteWidthRatio;
	data["IsActive"] = task_data.IsActive;
	data["Remark"] = task_data.Remark;
	data["OfferType"] = task_data.OfferType;
	data["TOL_TICK"] = task_data.TOL_TICK;
	data["ForQuoteOfferType"] = task_data.ForQuoteOfferType;
	data["QuoteWidthType"] = task_data.QuoteWidthType;
	data["ForQuoteWidthType"] = task_data.ForQuoteWidthType;
	data["InstrumentOneSide"] = task_data.InstrumentOneSide;
	data["UnderlyingOneSide"] = task_data.UnderlyingOneSide;
	data["MinPrice"] = task_data.MinPrice;
	data["QuoteStepID"] = task_data.QuoteStepID;
	data["QuoteDeltaStepID"] = task_data.QuoteDeltaStepID;
	data["QuoteVegaStepID"] = task_data.QuoteVegaStepID;
	data["ForQuoteStepID"] = task_data.ForQuoteStepID;
	data["ForQuoteDeltaStepID"] = task_data.ForQuoteDeltaStepID;
	data["ForQuoteVegaStepID"] = task_data.ForQuoteVegaStepID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMarkerStrategySet(data, error, task.task_id, task.task_last);
};

void UserApi::processRspUpMarkerStrategySet(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerStrategyField task_data = any_cast<CFocusFtdcMarkerStrategyField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["AutoOffer"] = task_data.AutoOffer;
	data["AutoRespAsking"] = task_data.AutoRespAsking;
	data["BidAmount"] = task_data.BidAmount;
	data["AskAmount"] = task_data.AskAmount;
	data["ForQuoteBidAmount"] = task_data.ForQuoteBidAmount;
	data["ForQuoteAskAmount"] = task_data.ForQuoteAskAmount;
	data["BidMax"] = task_data.BidMax;
	data["AskMax"] = task_data.AskMax;
	data["SpreadType"] = task_data.SpreadType;
	data["QuotePriceWidth"] = task_data.QuotePriceWidth;
	data["QuoteWidthRatio"] = task_data.QuoteWidthRatio;
	data["ForQuotePriceWidth"] = task_data.ForQuotePriceWidth;
	data["ForQuoteWidthRatio"] = task_data.ForQuoteWidthRatio;
	data["IsActive"] = task_data.IsActive;
	data["Remark"] = task_data.Remark;
	data["OfferType"] = task_data.OfferType;
	data["TOL_TICK"] = task_data.TOL_TICK;
	data["ForQuoteOfferType"] = task_data.ForQuoteOfferType;
	data["QuoteWidthType"] = task_data.QuoteWidthType;
	data["ForQuoteWidthType"] = task_data.ForQuoteWidthType;
	data["InstrumentOneSide"] = task_data.InstrumentOneSide;
	data["UnderlyingOneSide"] = task_data.UnderlyingOneSide;
	data["MinPrice"] = task_data.MinPrice;
	data["QuoteStepID"] = task_data.QuoteStepID;
	data["QuoteDeltaStepID"] = task_data.QuoteDeltaStepID;
	data["QuoteVegaStepID"] = task_data.QuoteVegaStepID;
	data["ForQuoteStepID"] = task_data.ForQuoteStepID;
	data["ForQuoteDeltaStepID"] = task_data.ForQuoteDeltaStepID;
	data["ForQuoteVegaStepID"] = task_data.ForQuoteVegaStepID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUpMarkerStrategySet(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryUserSwitch(Task task)
{
	PyLock lock;
	CFocusFtdcUserSwitchField task_data = any_cast<CFocusFtdcUserSwitchField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["WholeSwitch"] = task_data.WholeSwitch;
	data["WholeOffer"] = task_data.WholeOffer;
	data["WholeRespAsking"] = task_data.WholeRespAsking;
	data["WholeHedge"] = task_data.WholeHedge;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryUserSwitch(data, error, task.task_id, task.task_last);
};

void UserApi::processRspUserSwitch(Task task)
{
	PyLock lock;
	CFocusFtdcUserSwitchField task_data = any_cast<CFocusFtdcUserSwitchField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["WholeSwitch"] = task_data.WholeSwitch;
	data["WholeOffer"] = task_data.WholeOffer;
	data["WholeRespAsking"] = task_data.WholeRespAsking;
	data["WholeHedge"] = task_data.WholeHedge;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUserSwitch(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryMarkerHedge(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerHedgeField task_data = any_cast<CFocusFtdcMarkerHedgeField>(task.task_data);
	dict data;
	data["UnderlyingId"] = task_data.UnderlyingId;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["InvestorID"] = task_data.InvestorID;
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AutoHedge"] = task_data.AutoHedge;
	data["HedgePriceType"] = task_data.HedgePriceType;
	data["HdegeType"] = task_data.HdegeType;
	data["HedgePeriod"] = task_data.HedgePeriod;
	data["DeltaMax"] = task_data.DeltaMax;
	data["DelatMin"] = task_data.DelatMin;
	data["LastHedgeTime"] = task_data.LastHedgeTime;
	data["OrderPriceSlip"] = task_data.OrderPriceSlip;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMarkerHedge(data, error, task.task_id, task.task_last);
};

void UserApi::processRspUpMarkerHedge(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerHedgeField task_data = any_cast<CFocusFtdcMarkerHedgeField>(task.task_data);
	dict data;
	data["UnderlyingId"] = task_data.UnderlyingId;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["InvestorID"] = task_data.InvestorID;
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AutoHedge"] = task_data.AutoHedge;
	data["HedgePriceType"] = task_data.HedgePriceType;
	data["HdegeType"] = task_data.HdegeType;
	data["HedgePeriod"] = task_data.HedgePeriod;
	data["DeltaMax"] = task_data.DeltaMax;
	data["DelatMin"] = task_data.DelatMin;
	data["LastHedgeTime"] = task_data.LastHedgeTime;
	data["OrderPriceSlip"] = task_data.OrderPriceSlip;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUpMarkerHedge(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryFittingParam(Task task)
{
	PyLock lock;
	CFocusFtdcFittingParamField task_data = any_cast<CFocusFtdcFittingParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["FitModel"] = task_data.FitModel;
	data["CallBidFlag"] = task_data.CallBidFlag;
	data["CallAskFlag"] = task_data.CallAskFlag;
	data["PutBidFlag"] = task_data.PutBidFlag;
	data["PutAskFlag"] = task_data.PutAskFlag;
	data["CallMidFlag"] = task_data.CallMidFlag;
	data["PutMidFlag"] = task_data.PutMidFlag;
	data["OTMFlag"] = task_data.OTMFlag;
	data["AutoRemoveOutlier"] = task_data.AutoRemoveOutlier;
	data["ValidIntervalMax"] = task_data.ValidIntervalMax;
	data["ValidIntervalMin"] = task_data.ValidIntervalMin;
	data["AutoFit"] = task_data.AutoFit;
	data["AUTO_FIT_TIME"] = task_data.AUTO_FIT_TIME;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryFittingParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetFittingParam(Task task)
{
	PyLock lock;
	CFocusFtdcFittingParamField task_data = any_cast<CFocusFtdcFittingParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["FitModel"] = task_data.FitModel;
	data["CallBidFlag"] = task_data.CallBidFlag;
	data["CallAskFlag"] = task_data.CallAskFlag;
	data["PutBidFlag"] = task_data.PutBidFlag;
	data["PutAskFlag"] = task_data.PutAskFlag;
	data["CallMidFlag"] = task_data.CallMidFlag;
	data["PutMidFlag"] = task_data.PutMidFlag;
	data["OTMFlag"] = task_data.OTMFlag;
	data["AutoRemoveOutlier"] = task_data.AutoRemoveOutlier;
	data["ValidIntervalMax"] = task_data.ValidIntervalMax;
	data["ValidIntervalMin"] = task_data.ValidIntervalMin;
	data["AutoFit"] = task_data.AutoFit;
	data["AUTO_FIT_TIME"] = task_data.AUTO_FIT_TIME;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetFittingParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryPricingParam(Task task)
{
	PyLock lock;
	CFocusFtdcPricingParamField task_data = any_cast<CFocusFtdcPricingParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UnderlyingId"] = task_data.UnderlyingId;
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["PriceLevel1"] = task_data.PriceLevel1;
	data["PriceLevel2"] = task_data.PriceLevel2;
	data["PriceLevel3"] = task_data.PriceLevel3;
	data["CalcDayType"] = task_data.CalcDayType;
	data["YearTotalDay"] = task_data.YearTotalDay;
	data["CalcTimeType"] = task_data.CalcTimeType;
	data["RiskFreeRate"] = task_data.RiskFreeRate;
	data["Dividend"] = task_data.Dividend;
	data["PricingEngine"] = task_data.PricingEngine;
	data["ExerciseType"] = task_data.ExerciseType;
	data["VolTolerance"] = task_data.VolTolerance;
	data["VolType"] = task_data.VolType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryPricingParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryOptionTheoryVol(Task task)
{
	PyLock lock;
	CFocusFtdcOptionTheoryVolField task_data = any_cast<CFocusFtdcOptionTheoryVolField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["TheoryVol"] = task_data.TheoryVol;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryOptionTheoryVol(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQuoteInsert(Task task)
{
	PyLock lock;
	CFocusFtdcInputQuoteField task_data = any_cast<CFocusFtdcInputQuoteField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AccountID"] = task_data.AccountID;
	data["InvestorID"] = task_data.InvestorID;
	data["QuoteRef"] = task_data.QuoteRef;
	data["QuoteLocalID"] = GBK_TO_UTF8(task_data.QuoteLocalID);
	data["AskOrderRef"] = task_data.AskOrderRef;
	data["BidOrderRef"] = task_data.BidOrderRef;
	data["QuoteSysID"] = task_data.QuoteSysID;
	data["ForQuoteSysID"] = task_data.ForQuoteSysID;
	data["BidVolume"] = task_data.BidVolume;
	data["AskVolume"] = task_data.AskVolume;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BidOffsetFlag"] = task_data.BidOffsetFlag;
	data["BidHedgeFlag"] = task_data.BidHedgeFlag;
	data["BidPrice"] = task_data.BidPrice;
	data["AskOffsetFlag"] = task_data.AskOffsetFlag;
	data["AskHedgeFlag"] = task_data.AskHedgeFlag;
	data["AskPrice"] = task_data.AskPrice;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["IsAuto"] = task_data.IsAuto;
	data["APIID"] = task_data.APIID;
	data["Remark"] = task_data.Remark;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQuoteInsert(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQuoteAction(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteActionField task_data = any_cast<CFocusFtdcQuoteActionField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AccountID"] = task_data.AccountID;
	data["InvestorID"] = task_data.InvestorID;
	data["QuoteSysID"] = task_data.QuoteSysID;
	data["QuoteLocalID"] = GBK_TO_UTF8(task_data.QuoteLocalID);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["ActionFlag"] = task_data.ActionFlag;
	data["ParticipantID"] = task_data.ParticipantID;
	data["ClientID"] = task_data.ClientID;
	data["ActionLocalID"] = GBK_TO_UTF8(task_data.ActionLocalID);
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["APIID"] = task_data.APIID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQuoteAction(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryQuote(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteField task_data = any_cast<CFocusFtdcQuoteField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AccountID"] = task_data.AccountID;
	data["InvestorID"] = task_data.InvestorID;
	data["QuoteRef"] = task_data.QuoteRef;
	data["QuoteLocalID"] = GBK_TO_UTF8(task_data.QuoteLocalID);
	data["AskOrderRef"] = task_data.AskOrderRef;
	data["BidOrderRef"] = task_data.BidOrderRef;
	data["QuoteSysID"] = task_data.QuoteSysID;
	data["ForQuoteSysID"] = task_data.ForQuoteSysID;
	data["BidVolume"] = task_data.BidVolume;
	data["AskVolume"] = task_data.AskVolume;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BidOffsetFlag"] = task_data.BidOffsetFlag;
	data["BidHedgeFlag"] = task_data.BidHedgeFlag;
	data["BidPrice"] = task_data.BidPrice;
	data["AskOffsetFlag"] = task_data.AskOffsetFlag;
	data["AskHedgeFlag"] = task_data.AskHedgeFlag;
	data["AskPrice"] = task_data.AskPrice;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["IsAuto"] = task_data.IsAuto;
	data["APIID"] = task_data.APIID;
	data["Remark"] = task_data.Remark;
	data["InsertTime"] = task_data.InsertTime;
	data["CancelTime"] = task_data.CancelTime;
	data["TradeTime"] = task_data.TradeTime;
	data["BidOrderSysID"] = task_data.BidOrderSysID;
	data["AskOrderSysID"] = task_data.AskOrderSysID;
	data["QuoteStatus"] = task_data.QuoteStatus;
	data["OrderSubmitStatus"] = task_data.OrderSubmitStatus;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryQuote(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnQuote(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteField task_data = any_cast<CFocusFtdcQuoteField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AccountID"] = task_data.AccountID;
	data["InvestorID"] = task_data.InvestorID;
	data["QuoteRef"] = task_data.QuoteRef;
	data["QuoteLocalID"] = GBK_TO_UTF8(task_data.QuoteLocalID);
	data["AskOrderRef"] = task_data.AskOrderRef;
	data["BidOrderRef"] = task_data.BidOrderRef;
	data["QuoteSysID"] = task_data.QuoteSysID;
	data["ForQuoteSysID"] = task_data.ForQuoteSysID;
	data["BidVolume"] = task_data.BidVolume;
	data["AskVolume"] = task_data.AskVolume;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BidOffsetFlag"] = task_data.BidOffsetFlag;
	data["BidHedgeFlag"] = task_data.BidHedgeFlag;
	data["BidPrice"] = task_data.BidPrice;
	data["AskOffsetFlag"] = task_data.AskOffsetFlag;
	data["AskHedgeFlag"] = task_data.AskHedgeFlag;
	data["AskPrice"] = task_data.AskPrice;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["IsAuto"] = task_data.IsAuto;
	data["APIID"] = task_data.APIID;
	data["Remark"] = task_data.Remark;
	data["InsertTime"] = task_data.InsertTime;
	data["CancelTime"] = task_data.CancelTime;
	data["TradeTime"] = task_data.TradeTime;
	data["BidOrderSysID"] = task_data.BidOrderSysID;
	data["AskOrderSysID"] = task_data.AskOrderSysID;
	data["QuoteStatus"] = task_data.QuoteStatus;
	data["OrderSubmitStatus"] = task_data.OrderSubmitStatus;

	this->onRtnQuote(data);
};

void UserApi::processRspForQuote(Task task)
{
	PyLock lock;
	CFocusFtdcInputReqForQuoteField task_data = any_cast<CFocusFtdcInputReqForQuoteField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AccountID"] = task_data.AccountID;
	data["InvestorID"] = task_data.InvestorID;
	data["ReqForQuoteID"] = task_data.ReqForQuoteID;
	data["ClientID"] = task_data.ClientID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["ReqForQuoteTime"] = task_data.ReqForQuoteTime;
	data["ForQuoteLocalID"] = GBK_TO_UTF8(task_data.ForQuoteLocalID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspForQuote(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnForQuote(Task task)
{
	PyLock lock;
	CFocusFtdcInputReqForQuoteField task_data = any_cast<CFocusFtdcInputReqForQuoteField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AccountID"] = task_data.AccountID;
	data["InvestorID"] = task_data.InvestorID;
	data["ReqForQuoteID"] = task_data.ReqForQuoteID;
	data["ClientID"] = task_data.ClientID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["ReqForQuoteTime"] = task_data.ReqForQuoteTime;
	data["ForQuoteLocalID"] = GBK_TO_UTF8(task_data.ForQuoteLocalID);

	this->onRtnForQuote(data);
};

void UserApi::processRspQryOrderInsertFailed(Task task)
{
	PyLock lock;
	CFocusFtdcOrderInsertFailedField task_data = any_cast<CFocusFtdcOrderInsertFailedField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["BatchNum"] = task_data.BatchNum;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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
	data["BusinessUnit"] = GBK_TO_UTF8(task_data.BusinessUnit);
	data["BusinessType"] = task_data.BusinessType;
	data["TradingDay"] = task_data.TradingDay;
	data["InsertTime"] = task_data.InsertTime;
	data["OrderSource"] = task_data.OrderSource;
	data["OrderStatus"] = task_data.OrderStatus;
	data["CancelTime"] = task_data.CancelTime;
	data["CancelUserID"] = GBK_TO_UTF8(task_data.CancelUserID);
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
	data["BranchID"] = GBK_TO_UTF8(task_data.BranchID);
	data["RecNum"] = task_data.RecNum;
	data["ParticipantID"] = task_data.ParticipantID;
	data["ClientID"] = task_data.ClientID;
	data["SeatID"] = task_data.SeatID;
	data["OrderLocalID"] = GBK_TO_UTF8(task_data.OrderLocalID);
	data["SubAccountID"] = task_data.SubAccountID;
	data["OrderUserID"] = GBK_TO_UTF8(task_data.OrderUserID);
	data["TradeType"] = task_data.TradeType;
	data["DealFlag"] = task_data.DealFlag;
	data["TradeCommision"] = task_data.TradeCommision;
	data["TradeAmnt"] = task_data.TradeAmnt;
	data["SubInvestorID"] = task_data.SubInvestorID;
	data["InvestorType"] = task_data.InvestorType;
	data["SubOrderSysID"] = task_data.SubOrderSysID;
	data["ParentInvestorCode"] = task_data.ParentInvestorCode;
	data["APIID"] = task_data.APIID;
	data["VolumeFrozenClosing"] = task_data.VolumeFrozenClosing;
	data["VolumeFrozen"] = task_data.VolumeFrozen;
	data["FrozenMoney"] = task_data.FrozenMoney;
	data["AdviceOrderSysID"] = task_data.AdviceOrderSysID;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["FrozenFee"] = task_data.FrozenFee;
	data["FrozenTransferFee"] = task_data.FrozenTransferFee;
	data["FrozenStampTax"] = task_data.FrozenStampTax;
	data["PurRedVolumeFrozen"] = task_data.PurRedVolumeFrozen;
	data["CloseVolumeFrozen"] = task_data.CloseVolumeFrozen;
	data["Remark"] = task_data.Remark;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryOrderInsertFailed(data, error, task.task_id, task.task_last);
};

void UserApi::processRspCleanQuoteThresHold(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteTotalTradePriceField task_data = any_cast<CFocusFtdcQuoteTotalTradePriceField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["AskTradeVolume"] = task_data.AskTradeVolume;
	data["BidTradeVolume"] = task_data.BidTradeVolume;
	data["BidQuotePrice"] = task_data.BidQuotePrice;
	data["BidQuoteAmount"] = task_data.BidQuoteAmount;
	data["AskQuotePrice"] = task_data.AskQuotePrice;
	data["AskQuoteAmount"] = task_data.AskQuoteAmount;
	data["ForQuoteSendAmount"] = task_data.ForQuoteSendAmount;
	data["ForQuoteTotalAmount"] = task_data.ForQuoteTotalAmount;
	data["BidForQuotePrice"] = task_data.BidForQuotePrice;
	data["BidForQuoteAmount"] = task_data.BidForQuoteAmount;
	data["AskForQuotePrice"] = task_data.AskForQuotePrice;
	data["AskForQuoteAmount"] = task_data.AskForQuoteAmount;
	data["FowardDirection"] = task_data.FowardDirection;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspCleanQuoteThresHold(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetPriceSpread(Task task)
{
	PyLock lock;
	CFocusFtdcPriceSpreadField task_data = any_cast<CFocusFtdcPriceSpreadField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["Spread"] = task_data.Spread;
	data["SpreadInstrumentId"] = GBK_TO_UTF8(task_data.SpreadInstrumentId);
	data["PriceSpreadType"] = task_data.PriceSpreadType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetPriceSpread(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryPriceSpread(Task task)
{
	PyLock lock;
	CFocusFtdcPriceSpreadField task_data = any_cast<CFocusFtdcPriceSpreadField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["Spread"] = task_data.Spread;
	data["SpreadInstrumentId"] = GBK_TO_UTF8(task_data.SpreadInstrumentId);
	data["PriceSpreadType"] = task_data.PriceSpreadType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryPriceSpread(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelPricingParam(Task task)
{
	PyLock lock;
	CFocusFtdcPricingParamField task_data = any_cast<CFocusFtdcPricingParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UnderlyingId"] = task_data.UnderlyingId;
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["PriceLevel1"] = task_data.PriceLevel1;
	data["PriceLevel2"] = task_data.PriceLevel2;
	data["PriceLevel3"] = task_data.PriceLevel3;
	data["CalcDayType"] = task_data.CalcDayType;
	data["YearTotalDay"] = task_data.YearTotalDay;
	data["CalcTimeType"] = task_data.CalcTimeType;
	data["RiskFreeRate"] = task_data.RiskFreeRate;
	data["Dividend"] = task_data.Dividend;
	data["PricingEngine"] = task_data.PricingEngine;
	data["ExerciseType"] = task_data.ExerciseType;
	data["VolTolerance"] = task_data.VolTolerance;
	data["VolType"] = task_data.VolType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelPricingParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelMarkerStrategySet(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerStrategyField task_data = any_cast<CFocusFtdcMarkerStrategyField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["AutoOffer"] = task_data.AutoOffer;
	data["AutoRespAsking"] = task_data.AutoRespAsking;
	data["BidAmount"] = task_data.BidAmount;
	data["AskAmount"] = task_data.AskAmount;
	data["ForQuoteBidAmount"] = task_data.ForQuoteBidAmount;
	data["ForQuoteAskAmount"] = task_data.ForQuoteAskAmount;
	data["BidMax"] = task_data.BidMax;
	data["AskMax"] = task_data.AskMax;
	data["SpreadType"] = task_data.SpreadType;
	data["QuotePriceWidth"] = task_data.QuotePriceWidth;
	data["QuoteWidthRatio"] = task_data.QuoteWidthRatio;
	data["ForQuotePriceWidth"] = task_data.ForQuotePriceWidth;
	data["ForQuoteWidthRatio"] = task_data.ForQuoteWidthRatio;
	data["IsActive"] = task_data.IsActive;
	data["Remark"] = task_data.Remark;
	data["OfferType"] = task_data.OfferType;
	data["TOL_TICK"] = task_data.TOL_TICK;
	data["ForQuoteOfferType"] = task_data.ForQuoteOfferType;
	data["QuoteWidthType"] = task_data.QuoteWidthType;
	data["ForQuoteWidthType"] = task_data.ForQuoteWidthType;
	data["InstrumentOneSide"] = task_data.InstrumentOneSide;
	data["UnderlyingOneSide"] = task_data.UnderlyingOneSide;
	data["MinPrice"] = task_data.MinPrice;
	data["QuoteStepID"] = task_data.QuoteStepID;
	data["QuoteDeltaStepID"] = task_data.QuoteDeltaStepID;
	data["QuoteVegaStepID"] = task_data.QuoteVegaStepID;
	data["ForQuoteStepID"] = task_data.ForQuoteStepID;
	data["ForQuoteDeltaStepID"] = task_data.ForQuoteDeltaStepID;
	data["ForQuoteVegaStepID"] = task_data.ForQuoteVegaStepID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelMarkerStrategySet(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetAlertParam(Task task)
{
	PyLock lock;
	CFocusFtdcAlertIndexSetParamField task_data = any_cast<CFocusFtdcAlertIndexSetParamField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["InvestorID"] = task_data.InvestorID;
	data["InvestorType"] = task_data.InvestorType;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AlertIndexCode"] = task_data.AlertIndexCode;
	data["MAX_L1"] = task_data.MAX_L1;
	data["MIN_L1"] = task_data.MIN_L1;
	data["MAX_L2"] = task_data.MAX_L2;
	data["MIN_L2"] = task_data.MIN_L2;
	data["TimeAvail"] = task_data.TimeAvail;
	data["AlertAction"] = task_data.AlertAction;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetAlertParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryAlertParam(Task task)
{
	PyLock lock;
	CFocusFtdcAlertIndexSetParamField task_data = any_cast<CFocusFtdcAlertIndexSetParamField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["InvestorID"] = task_data.InvestorID;
	data["InvestorType"] = task_data.InvestorType;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AlertIndexCode"] = task_data.AlertIndexCode;
	data["MAX_L1"] = task_data.MAX_L1;
	data["MIN_L1"] = task_data.MIN_L1;
	data["MAX_L2"] = task_data.MAX_L2;
	data["MIN_L2"] = task_data.MIN_L2;
	data["TimeAvail"] = task_data.TimeAvail;
	data["AlertAction"] = task_data.AlertAction;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAlertParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryAlertData(Task task)
{
	PyLock lock;
	CFocusFtdcAlertIndexSetDataField task_data = any_cast<CFocusFtdcAlertIndexSetDataField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AlertIndexCode"] = task_data.AlertIndexCode;
	data["IndexVolume"] = task_data.IndexVolume;
	data["MAX_L1"] = task_data.MAX_L1;
	data["MIN_L1"] = task_data.MIN_L1;
	data["MAX_L2"] = task_data.MAX_L2;
	data["MIN_L2"] = task_data.MIN_L2;
	data["AlertAction"] = task_data.AlertAction;
	data["OperDate"] = task_data.OperDate;
	data["OperTime"] = task_data.OperTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAlertData(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnAlertData(Task task)
{
	PyLock lock;
	CFocusFtdcAlertIndexSetDataField task_data = any_cast<CFocusFtdcAlertIndexSetDataField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AlertIndexCode"] = task_data.AlertIndexCode;
	data["IndexVolume"] = task_data.IndexVolume;
	data["MAX_L1"] = task_data.MAX_L1;
	data["MIN_L1"] = task_data.MIN_L1;
	data["MAX_L2"] = task_data.MAX_L2;
	data["MIN_L2"] = task_data.MIN_L2;
	data["AlertAction"] = task_data.AlertAction;
	data["OperDate"] = task_data.OperDate;
	data["OperTime"] = task_data.OperTime;

	this->onRtnAlertData(data);
};

void UserApi::processRtnStrategyLog(Task task)
{
	PyLock lock;
	CFocusFtdcStrategyLogField task_data = any_cast<CFocusFtdcStrategyLogField>(task.task_data);
	dict data;
	data["EventID"] = task_data.EventID;
	data["TradingDay"] = task_data.TradingDay;
	data["EventType"] = task_data.EventType;
	data["EventCode"] = task_data.EventCode;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["Log_Content"] = task_data.Log_Content;
	data["OperDate"] = task_data.OperDate;
	data["OperTime"] = task_data.OperTime;

	this->onRtnStrategyLog(data);
};

void UserApi::processRtnQuoteTotalTradePosition(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteTotalTradePositionField task_data = any_cast<CFocusFtdcQuoteTotalTradePositionField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["BuyVolume"] = task_data.BuyVolume;
	data["SellVolume"] = task_data.SellVolume;
	data["NetVolume"] = task_data.NetVolume;
	data["BuyPosition"] = task_data.BuyPosition;
	data["SellPosition"] = task_data.SellPosition;
	data["NetPosition"] = task_data.NetPosition;

	this->onRtnQuoteTotalTradePosition(data);
};

void UserApi::processRspDelOptionTheoryVol(Task task)
{
	PyLock lock;
	CFocusFtdcOptionTheoryVolField task_data = any_cast<CFocusFtdcOptionTheoryVolField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["TheoryVol"] = task_data.TheoryVol;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelOptionTheoryVol(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelMarkerHedge(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerHedgeField task_data = any_cast<CFocusFtdcMarkerHedgeField>(task.task_data);
	dict data;
	data["UnderlyingId"] = task_data.UnderlyingId;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["InvestorID"] = task_data.InvestorID;
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AutoHedge"] = task_data.AutoHedge;
	data["HedgePriceType"] = task_data.HedgePriceType;
	data["HdegeType"] = task_data.HdegeType;
	data["HedgePeriod"] = task_data.HedgePeriod;
	data["DeltaMax"] = task_data.DeltaMax;
	data["DelatMin"] = task_data.DelatMin;
	data["LastHedgeTime"] = task_data.LastHedgeTime;
	data["OrderPriceSlip"] = task_data.OrderPriceSlip;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelMarkerHedge(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetMarkerStep(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerStepField task_data = any_cast<CFocusFtdcMarkerStepField>(task.task_data);
	dict data;
	data["StepID"] = task_data.StepID;
	data["StepName"] = GBK_TO_UTF8(task_data.StepName);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StepType"] = task_data.StepType;
	data["WidthType"] = task_data.WidthType;
	data["LowPrice"] = task_data.LowPrice;
	data["UpPrice"] = task_data.UpPrice;
	data["StepValue1"] = task_data.StepValue1;
	data["StepValue2"] = task_data.StepValue2;
	data["StepValue3"] = task_data.StepValue3;
	data["StepValueKey"] = task_data.StepValueKey;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetMarkerStep(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelMarkerStep(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerStepField task_data = any_cast<CFocusFtdcMarkerStepField>(task.task_data);
	dict data;
	data["StepID"] = task_data.StepID;
	data["StepName"] = GBK_TO_UTF8(task_data.StepName);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StepType"] = task_data.StepType;
	data["WidthType"] = task_data.WidthType;
	data["LowPrice"] = task_data.LowPrice;
	data["UpPrice"] = task_data.UpPrice;
	data["StepValue1"] = task_data.StepValue1;
	data["StepValue2"] = task_data.StepValue2;
	data["StepValue3"] = task_data.StepValue3;
	data["StepValueKey"] = task_data.StepValueKey;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelMarkerStep(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelAlertParam(Task task)
{
	PyLock lock;
	CFocusFtdcAlertIndexSetParamField task_data = any_cast<CFocusFtdcAlertIndexSetParamField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["InvestorID"] = task_data.InvestorID;
	data["InvestorType"] = task_data.InvestorType;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["AlertIndexCode"] = task_data.AlertIndexCode;
	data["MAX_L1"] = task_data.MAX_L1;
	data["MIN_L1"] = task_data.MIN_L1;
	data["MAX_L2"] = task_data.MAX_L2;
	data["MIN_L2"] = task_data.MIN_L2;
	data["TimeAvail"] = task_data.TimeAvail;
	data["AlertAction"] = task_data.AlertAction;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelAlertParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetQuoteMove(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteMoveField task_data = any_cast<CFocusFtdcQuoteMoveField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["SumVolumeTime"] = task_data.SumVolumeTime;
	data["SumVolume"] = task_data.SumVolume;
	data["Move"] = task_data.Move;
	data["KeepTime"] = task_data.KeepTime;
	data["TakeOut"] = task_data.TakeOut;
	data["IsActive"] = task_data.IsActive;
	data["NearStrikeMove"] = task_data.NearStrikeMove;
	data["NearStrikeVolSpread"] = task_data.NearStrikeVolSpread;
	data["NearMoveType"] = task_data.NearMoveType;
	data["NearKeepTime"] = task_data.NearKeepTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetQuoteMove(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelQuoteMove(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteMoveField task_data = any_cast<CFocusFtdcQuoteMoveField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["SumVolumeTime"] = task_data.SumVolumeTime;
	data["SumVolume"] = task_data.SumVolume;
	data["Move"] = task_data.Move;
	data["KeepTime"] = task_data.KeepTime;
	data["TakeOut"] = task_data.TakeOut;
	data["IsActive"] = task_data.IsActive;
	data["NearStrikeMove"] = task_data.NearStrikeMove;
	data["NearStrikeVolSpread"] = task_data.NearStrikeVolSpread;
	data["NearMoveType"] = task_data.NearMoveType;
	data["NearKeepTime"] = task_data.NearKeepTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelQuoteMove(data, error, task.task_id, task.task_last);
};

void UserApi::processRspRebackQuote(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteTotalTradePriceField task_data = any_cast<CFocusFtdcQuoteTotalTradePriceField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["AskTradeVolume"] = task_data.AskTradeVolume;
	data["BidTradeVolume"] = task_data.BidTradeVolume;
	data["BidQuotePrice"] = task_data.BidQuotePrice;
	data["BidQuoteAmount"] = task_data.BidQuoteAmount;
	data["AskQuotePrice"] = task_data.AskQuotePrice;
	data["AskQuoteAmount"] = task_data.AskQuoteAmount;
	data["ForQuoteSendAmount"] = task_data.ForQuoteSendAmount;
	data["ForQuoteTotalAmount"] = task_data.ForQuoteTotalAmount;
	data["BidForQuotePrice"] = task_data.BidForQuotePrice;
	data["BidForQuoteAmount"] = task_data.BidForQuoteAmount;
	data["AskForQuotePrice"] = task_data.AskForQuotePrice;
	data["AskForQuoteAmount"] = task_data.AskForQuoteAmount;
	data["FowardDirection"] = task_data.FowardDirection;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspRebackQuote(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryDepMarketData(Task task)
{
	PyLock lock;
	CFocusFtdcDepthMarketDataField task_data = any_cast<CFocusFtdcDepthMarketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["PreDelta"] = task_data.PreDelta;
	data["StkOrderStatus"] = task_data.StkOrderStatus;
	data["OpenPrice"] = task_data.OpenPrice;
	data["HighestPrice"] = task_data.HighestPrice;
	data["LowestPrice"] = task_data.LowestPrice;
	data["ClosePrice"] = task_data.ClosePrice;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["SettlementPrice"] = task_data.SettlementPrice;
	data["CurrDelta"] = task_data.CurrDelta;
	data["LastPrice"] = task_data.LastPrice;
	data["Volume"] = task_data.Volume;
	data["Turnover"] = task_data.Turnover;
	data["OpenInterest"] = task_data.OpenInterest;
	data["BidPrice1"] = task_data.BidPrice1;
	data["BidVolume1"] = task_data.BidVolume1;
	data["AskPrice1"] = task_data.AskPrice1;
	data["AskVolume1"] = task_data.AskVolume1;
	data["BidPrice2"] = task_data.BidPrice2;
	data["BidVolume2"] = task_data.BidVolume2;
	data["BidPrice3"] = task_data.BidPrice3;
	data["BidVolume3"] = task_data.BidVolume3;
	data["AskPrice2"] = task_data.AskPrice2;
	data["AskVolume2"] = task_data.AskVolume2;
	data["AskPrice3"] = task_data.AskPrice3;
	data["AskVolume3"] = task_data.AskVolume3;
	data["BidPrice4"] = task_data.BidPrice4;
	data["BidVolume4"] = task_data.BidVolume4;
	data["BidPrice5"] = task_data.BidPrice5;
	data["BidVolume5"] = task_data.BidVolume5;
	data["AskPrice4"] = task_data.AskPrice4;
	data["AskVolume4"] = task_data.AskVolume4;
	data["AskPrice5"] = task_data.AskPrice5;
	data["AskVolume5"] = task_data.AskVolume5;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;
	data["ExchangeID"] = task_data.ExchangeID;
	data["VolumeAskLot"] = task_data.VolumeAskLot;
	data["VolumeBidLot"] = task_data.VolumeBidLot;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryDepMarketData(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryQuoteMove(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteMoveField task_data = any_cast<CFocusFtdcQuoteMoveField>(task.task_data);
	dict data;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["SumVolumeTime"] = task_data.SumVolumeTime;
	data["SumVolume"] = task_data.SumVolume;
	data["Move"] = task_data.Move;
	data["KeepTime"] = task_data.KeepTime;
	data["TakeOut"] = task_data.TakeOut;
	data["IsActive"] = task_data.IsActive;
	data["NearStrikeMove"] = task_data.NearStrikeMove;
	data["NearStrikeVolSpread"] = task_data.NearStrikeVolSpread;
	data["NearMoveType"] = task_data.NearMoveType;
	data["NearKeepTime"] = task_data.NearKeepTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryQuoteMove(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryBaseMarkerStep(Task task)
{
	PyLock lock;
	CFocusFtdcBaseMarkerStepField task_data = any_cast<CFocusFtdcBaseMarkerStepField>(task.task_data);
	dict data;
	data["StepID"] = task_data.StepID;
	data["StepName"] = GBK_TO_UTF8(task_data.StepName);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StepType"] = task_data.StepType;
	data["WidthType"] = task_data.WidthType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryBaseMarkerStep(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryMarkerStep(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerStepField task_data = any_cast<CFocusFtdcMarkerStepField>(task.task_data);
	dict data;
	data["StepID"] = task_data.StepID;
	data["StepName"] = GBK_TO_UTF8(task_data.StepName);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StepType"] = task_data.StepType;
	data["WidthType"] = task_data.WidthType;
	data["LowPrice"] = task_data.LowPrice;
	data["UpPrice"] = task_data.UpPrice;
	data["StepValue1"] = task_data.StepValue1;
	data["StepValue2"] = task_data.StepValue2;
	data["StepValue3"] = task_data.StepValue3;
	data["StepValueKey"] = task_data.StepValueKey;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMarkerStep(data, error, task.task_id, task.task_last);
};

void UserApi::processRspFocusStatus(Task task)
{
	PyLock lock;
	CFocusFtdcFocusStatusField task_data = any_cast<CFocusFtdcFocusStatusField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["TradeStatus"] = task_data.TradeStatus;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspFocusStatus(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnATMPriceData(Task task)
{
	PyLock lock;
	CFocusFtdcATMPriceDataField task_data = any_cast<CFocusFtdcATMPriceDataField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["OptionSeriesId"] = task_data.OptionSeriesId;
	data["UnderlyingMid"] = task_data.UnderlyingMid;
	data["AtmForword"] = task_data.AtmForword;
	data["RemainDay"] = task_data.RemainDay;
	data["V10D"] = task_data.V10D;
	data["V25D"] = task_data.V25D;
	data["V45D"] = task_data.V45D;
	data["AtmVol"] = task_data.AtmVol;
	data["V55D"] = task_data.V55D;
	data["V75D"] = task_data.V75D;
	data["V90D"] = task_data.V90D;
	data["OperTime"] = task_data.OperTime;

	this->onRtnATMPriceData(data);
};

void UserApi::processRspSetFutureMakerWholeSwitch(Task task)
{
	PyLock lock;
	CFocusFtdcFutureMakerWholeSwitchField task_data = any_cast<CFocusFtdcFutureMakerWholeSwitchField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["WholeSwitch"] = task_data.WholeSwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetFutureMakerWholeSwitch(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetFutureMakerStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcFutureMakerStrategyField task_data = any_cast<CFocusFtdcFutureMakerStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["FirstSwitch"] = task_data.FirstSwitch;
	data["FirstFutureMakerFlag"] = task_data.FirstFutureMakerFlag;
	data["FirstToler"] = task_data.FirstToler;
	data["FirstAmount"] = task_data.FirstAmount;
	data["FirstWidth"] = task_data.FirstWidth;
	data["SecondSwitch"] = task_data.SecondSwitch;
	data["SecondFutureMakerFlag"] = task_data.SecondFutureMakerFlag;
	data["SecondToler"] = task_data.SecondToler;
	data["SecondAmount"] = task_data.SecondAmount;
	data["SecondWidth"] = task_data.SecondWidth;
	data["ThirdSwitch"] = task_data.ThirdSwitch;
	data["ThirdFutureMakerFlag"] = task_data.ThirdFutureMakerFlag;
	data["ThirdToler"] = task_data.ThirdToler;
	data["ThirdAmount"] = task_data.ThirdAmount;
	data["ThirdWidth"] = task_data.ThirdWidth;
	data["SumVolumeTime"] = task_data.SumVolumeTime;
	data["SumVolume"] = task_data.SumVolume;
	data["KeepTime"] = task_data.KeepTime;
	data["FutureOffsetFlag"] = task_data.FutureOffsetFlag;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetFutureMakerStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetSlefHedgeStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcSlefHedgeStrategyField task_data = any_cast<CFocusFtdcSlefHedgeStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["SlefHedgeFutureMakerFlag"] = task_data.SlefHedgeFutureMakerFlag;
	data["SlefHedgeFutureMakerTick"] = task_data.SlefHedgeFutureMakerTick;
	data["SlefHedgeDeviate"] = task_data.SlefHedgeDeviate;
	data["SlefHedgeTimeAction"] = task_data.SlefHedgeTimeAction;
	data["SlefChaseTimes"] = task_data.SlefChaseTimes;
	data["MaxLossTick"] = task_data.MaxLossTick;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetSlefHedgeStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetFutureHedgeStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcFutureHedgeStrategyField task_data = any_cast<CFocusFtdcFutureHedgeStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["HedgeExchangeID"] = task_data.HedgeExchangeID;
	data["HedgeInstrumentID"] = GBK_TO_UTF8(task_data.HedgeInstrumentID);
	data["HedgeInvestorID"] = task_data.HedgeInvestorID;
	data["Spread"] = task_data.Spread;
	data["HedgeFutureMakerFlag"] = task_data.HedgeFutureMakerFlag;
	data["HedgeFutureMakerTick"] = task_data.HedgeFutureMakerTick;
	data["HedgeDeviate"] = task_data.HedgeDeviate;
	data["HedgeTimeAction"] = task_data.HedgeTimeAction;
	data["HedgeChaseTimes"] = task_data.HedgeChaseTimes;
	data["HedgeOffsetFlag"] = task_data.HedgeOffsetFlag;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetFutureHedgeStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetQuoteAdditionParm(Task task)
{
	PyLock lock;
	CFocusFtdcQuoteAdditionParmField task_data = any_cast<CFocusFtdcQuoteAdditionParmField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["QuotePriceWidth"] = task_data.QuotePriceWidth;
	data["QuoteWidthRatio"] = task_data.QuoteWidthRatio;
	data["QuoteWidthType"] = task_data.QuoteWidthType;
	data["TOL_TICK"] = task_data.TOL_TICK;
	data["Remark"] = task_data.Remark;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetQuoteAdditionParm(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnMarkerStrategyChange(Task task)
{
	PyLock lock;
	CFocusFtdcMarkerStrategyField task_data = any_cast<CFocusFtdcMarkerStrategyField>(task.task_data);
	dict data;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["AutoOffer"] = task_data.AutoOffer;
	data["AutoRespAsking"] = task_data.AutoRespAsking;
	data["BidAmount"] = task_data.BidAmount;
	data["AskAmount"] = task_data.AskAmount;
	data["ForQuoteBidAmount"] = task_data.ForQuoteBidAmount;
	data["ForQuoteAskAmount"] = task_data.ForQuoteAskAmount;
	data["BidMax"] = task_data.BidMax;
	data["AskMax"] = task_data.AskMax;
	data["SpreadType"] = task_data.SpreadType;
	data["QuotePriceWidth"] = task_data.QuotePriceWidth;
	data["QuoteWidthRatio"] = task_data.QuoteWidthRatio;
	data["ForQuotePriceWidth"] = task_data.ForQuotePriceWidth;
	data["ForQuoteWidthRatio"] = task_data.ForQuoteWidthRatio;
	data["IsActive"] = task_data.IsActive;
	data["Remark"] = task_data.Remark;
	data["OfferType"] = task_data.OfferType;
	data["TOL_TICK"] = task_data.TOL_TICK;
	data["ForQuoteOfferType"] = task_data.ForQuoteOfferType;
	data["QuoteWidthType"] = task_data.QuoteWidthType;
	data["ForQuoteWidthType"] = task_data.ForQuoteWidthType;
	data["InstrumentOneSide"] = task_data.InstrumentOneSide;
	data["UnderlyingOneSide"] = task_data.UnderlyingOneSide;
	data["MinPrice"] = task_data.MinPrice;
	data["QuoteStepID"] = task_data.QuoteStepID;
	data["QuoteDeltaStepID"] = task_data.QuoteDeltaStepID;
	data["QuoteVegaStepID"] = task_data.QuoteVegaStepID;
	data["ForQuoteStepID"] = task_data.ForQuoteStepID;
	data["ForQuoteDeltaStepID"] = task_data.ForQuoteDeltaStepID;
	data["ForQuoteVegaStepID"] = task_data.ForQuoteVegaStepID;

	this->onRtnMarkerStrategyChange(data);
};

void UserApi::processRspStopAllFutureMakerHedgeOffer(Task task)
{
	PyLock lock;
	CFocusFtdcStopAllFutureMakerHedgeOfferField task_data = any_cast<CFocusFtdcStopAllFutureMakerHedgeOfferField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["HedgeOfferType"] = task_data.HedgeOfferType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspStopAllFutureMakerHedgeOffer(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnFutureMakerHedgeStatus(Task task)
{
	PyLock lock;
	CFocusFtdcFutureMakerHedgeStatusField task_data = any_cast<CFocusFtdcFutureMakerHedgeStatusField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["SlefHedgeStatus"] = task_data.SlefHedgeStatus;
	data["FutureHedgeStatus"] = task_data.FutureHedgeStatus;

	this->onRtnFutureMakerHedgeStatus(data);
};

void UserApi::processRtnInvestorPosition(Task task)
{
	PyLock lock;
	CFocusFtdcRspInvestorPositionField task_data = any_cast<CFocusFtdcRspInvestorPositionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InvestorID"] = task_data.InvestorID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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
	data["LastOrderLocalID"] = GBK_TO_UTF8(task_data.LastOrderLocalID);
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

void UserApi::processRspQryFutureMakerStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcAllFutureMakerStrategyField task_data = any_cast<CFocusFtdcAllFutureMakerStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["WholeSwitch"] = task_data.WholeSwitch;
	data["FirstSwitch"] = task_data.FirstSwitch;
	data["FirstFutureMakerFlag"] = task_data.FirstFutureMakerFlag;
	data["FirstToler"] = task_data.FirstToler;
	data["FirstAmount"] = task_data.FirstAmount;
	data["FirstWidth"] = task_data.FirstWidth;
	data["SecondSwitch"] = task_data.SecondSwitch;
	data["SecondFutureMakerFlag"] = task_data.SecondFutureMakerFlag;
	data["SecondToler"] = task_data.SecondToler;
	data["SecondAmount"] = task_data.SecondAmount;
	data["SecondWidth"] = task_data.SecondWidth;
	data["ThirdSwitch"] = task_data.ThirdSwitch;
	data["ThirdFutureMakerFlag"] = task_data.ThirdFutureMakerFlag;
	data["ThirdToler"] = task_data.ThirdToler;
	data["ThirdAmount"] = task_data.ThirdAmount;
	data["ThirdWidth"] = task_data.ThirdWidth;
	data["SumVolumeTime"] = task_data.SumVolumeTime;
	data["SumVolume"] = task_data.SumVolume;
	data["KeepTime"] = task_data.KeepTime;
	data["FutureOffsetFlag"] = task_data.FutureOffsetFlag;
	data["SlefHedgeFutureMakerFlag"] = task_data.SlefHedgeFutureMakerFlag;
	data["SlefHedgeFutureMakerTick"] = task_data.SlefHedgeFutureMakerTick;
	data["SlefHedgeDeviate"] = task_data.SlefHedgeDeviate;
	data["SlefHedgeTimeAction"] = task_data.SlefHedgeTimeAction;
	data["SlefChaseTimes"] = task_data.SlefChaseTimes;
	data["MaxLossTick"] = task_data.MaxLossTick;
	data["HedgeExchangeID"] = task_data.HedgeExchangeID;
	data["HedgeInstrumentID"] = GBK_TO_UTF8(task_data.HedgeInstrumentID);
	data["HedgeInvestorID"] = task_data.HedgeInvestorID;
	data["Spread"] = task_data.Spread;
	data["HedgeFutureMakerFlag"] = task_data.HedgeFutureMakerFlag;
	data["HedgeFutureMakerTick"] = task_data.HedgeFutureMakerTick;
	data["HedgeDeviate"] = task_data.HedgeDeviate;
	data["HedgeTimeAction"] = task_data.HedgeTimeAction;
	data["HedgeChaseTimes"] = task_data.HedgeChaseTimes;
	data["HedgeOffsetFlag"] = task_data.HedgeOffsetFlag;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryFutureMakerStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryAllInnerHighStockStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcInnerHighStockStrategyField task_data = any_cast<CFocusFtdcInnerHighStockStrategyField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyName"] = GBK_TO_UTF8(task_data.StockStrategyName);
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["Ratio"] = task_data.Ratio;
	data["MaxVolume"] = task_data.MaxVolume;
	data["MinVolume"] = task_data.MinVolume;
	data["StockRatioAvail"] = task_data.StockRatioAvail;
	data["AverMactchTradeVolume1"] = task_data.AverMactchTradeVolume1;
	data["AverMactchTradeVolume2"] = task_data.AverMactchTradeVolume2;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["StockPriceType"] = task_data.StockPriceType;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["LastOrderSysID"] = task_data.LastOrderSysID;
	data["Direction"] = task_data.Direction;
	data["LastBatchNum"] = task_data.LastBatchNum;
	data["YPosition"] = task_data.YPosition;
	data["StaticEndPosition"] = task_data.StaticEndPosition;
	data["EndPosition"] = task_data.EndPosition;
	data["NowPosition"] = task_data.NowPosition;
	data["PositionClose"] = task_data.PositionClose;
	data["OpenVolume"] = task_data.OpenVolume;
	data["CloseVolume"] = task_data.CloseVolume;
	data["AlphaTargetValue"] = task_data.AlphaTargetValue;
	data["AlphaCurrentTotalValue"] = task_data.AlphaCurrentTotalValue;
	data["StartOperTime"] = task_data.StartOperTime;
	data["LastOperTime"] = task_data.LastOperTime;
	data["LastNeedSendVolume"] = task_data.LastNeedSendVolume;
	data["LastSendPrice"] = task_data.LastSendPrice;
	data["PreMarketTradeVolume"] = task_data.PreMarketTradeVolume;
	data["MAStockAvail"] = task_data.MAStockAvail;
	data["GapVolume"] = task_data.GapVolume;
	data["StockIsTrading"] = task_data.StockIsTrading;
	data["IsLowStock"] = task_data.IsLowStock;
	data["SignalHasBuyTotalPosition"] = task_data.SignalHasBuyTotalPosition;
	data["SignalHasSellTotalPosition"] = task_data.SignalHasSellTotalPosition;
	data["SignalLastPer"] = task_data.SignalLastPer;
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["Priority"] = task_data.Priority;
	data["StkOrderStatus"] = task_data.StkOrderStatus;
	data["OpenPrice"] = task_data.OpenPrice;
	data["TotalTradeVolume"] = task_data.TotalTradeVolume;
	data["TotalBuyCostMoney"] = task_data.TotalBuyCostMoney;
	data["TotalSellCostMoney"] = task_data.TotalSellCostMoney;
	data["AverCostMoney"] = task_data.AverCostMoney;
	data["TotalRoundAmount"] = task_data.TotalRoundAmount;
	data["AllAddTotalTradeVolume"] = task_data.AllAddTotalTradeVolume;
	data["AllAddTotalBuyCostMoney"] = task_data.AllAddTotalBuyCostMoney;
	data["AllAddTotalSellCostMoney"] = task_data.AllAddTotalSellCostMoney;
	data["AllAddAverCostMoney"] = task_data.AllAddAverCostMoney;
	data["AlphaListStaticEndPosition"] = task_data.AlphaListStaticEndPosition;
	data["AlphaListEndPosition"] = task_data.AlphaListEndPosition;
	data["AlphaListNowPosition"] = task_data.AlphaListNowPosition;
	data["AlphaListPriority"] = task_data.AlphaListPriority;
	data["AlphaListStockIsTrading"] = task_data.AlphaListStockIsTrading;
	data["TZeroStaticEndPosition"] = task_data.TZeroStaticEndPosition;
	data["TZeroEndPosition"] = task_data.TZeroEndPosition;
	data["TZeroNowPosition"] = task_data.TZeroNowPosition;
	data["TZeroLastOperTime"] = task_data.TZeroLastOperTime;
	data["TZeroGapVolume"] = task_data.TZeroGapVolume;
	data["TZeroEndOperTime"] = task_data.TZeroEndOperTime;
	data["TZeroUpperEndPrice"] = task_data.TZeroUpperEndPrice;
	data["TZeroLowerEndPrice"] = task_data.TZeroLowerEndPrice;
	data["TZeroStockPriceType"] = task_data.TZeroStockPriceType;
	data["TZeroAddPosition"] = task_data.TZeroAddPosition;
	data["T0StaticTotalMoney"] = task_data.T0StaticTotalMoney;
	data["TZeroStaticRights"] = task_data.TZeroStaticRights;
	data["TZeroColseRights"] = task_data.TZeroColseRights;
	data["StillNeedSendPosition"] = task_data.StillNeedSendPosition;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["AlgoNote"] = GBK_TO_UTF8(task_data.AlgoNote);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAllInnerHighStockStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnInnerHighStockStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcInnerHighStockStrategyField task_data = any_cast<CFocusFtdcInnerHighStockStrategyField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyName"] = GBK_TO_UTF8(task_data.StockStrategyName);
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["Ratio"] = task_data.Ratio;
	data["MaxVolume"] = task_data.MaxVolume;
	data["MinVolume"] = task_data.MinVolume;
	data["StockRatioAvail"] = task_data.StockRatioAvail;
	data["AverMactchTradeVolume1"] = task_data.AverMactchTradeVolume1;
	data["AverMactchTradeVolume2"] = task_data.AverMactchTradeVolume2;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["StockPriceType"] = task_data.StockPriceType;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["LastOrderSysID"] = task_data.LastOrderSysID;
	data["Direction"] = task_data.Direction;
	data["LastBatchNum"] = task_data.LastBatchNum;
	data["YPosition"] = task_data.YPosition;
	data["StaticEndPosition"] = task_data.StaticEndPosition;
	data["EndPosition"] = task_data.EndPosition;
	data["NowPosition"] = task_data.NowPosition;
	data["PositionClose"] = task_data.PositionClose;
	data["OpenVolume"] = task_data.OpenVolume;
	data["CloseVolume"] = task_data.CloseVolume;
	data["AlphaTargetValue"] = task_data.AlphaTargetValue;
	data["AlphaCurrentTotalValue"] = task_data.AlphaCurrentTotalValue;
	data["StartOperTime"] = task_data.StartOperTime;
	data["LastOperTime"] = task_data.LastOperTime;
	data["LastNeedSendVolume"] = task_data.LastNeedSendVolume;
	data["LastSendPrice"] = task_data.LastSendPrice;
	data["PreMarketTradeVolume"] = task_data.PreMarketTradeVolume;
	data["MAStockAvail"] = task_data.MAStockAvail;
	data["GapVolume"] = task_data.GapVolume;
	data["StockIsTrading"] = task_data.StockIsTrading;
	data["IsLowStock"] = task_data.IsLowStock;
	data["SignalHasBuyTotalPosition"] = task_data.SignalHasBuyTotalPosition;
	data["SignalHasSellTotalPosition"] = task_data.SignalHasSellTotalPosition;
	data["SignalLastPer"] = task_data.SignalLastPer;
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["Priority"] = task_data.Priority;
	data["StkOrderStatus"] = task_data.StkOrderStatus;
	data["OpenPrice"] = task_data.OpenPrice;
	data["TotalTradeVolume"] = task_data.TotalTradeVolume;
	data["TotalBuyCostMoney"] = task_data.TotalBuyCostMoney;
	data["TotalSellCostMoney"] = task_data.TotalSellCostMoney;
	data["AverCostMoney"] = task_data.AverCostMoney;
	data["TotalRoundAmount"] = task_data.TotalRoundAmount;
	data["AllAddTotalTradeVolume"] = task_data.AllAddTotalTradeVolume;
	data["AllAddTotalBuyCostMoney"] = task_data.AllAddTotalBuyCostMoney;
	data["AllAddTotalSellCostMoney"] = task_data.AllAddTotalSellCostMoney;
	data["AllAddAverCostMoney"] = task_data.AllAddAverCostMoney;
	data["AlphaListStaticEndPosition"] = task_data.AlphaListStaticEndPosition;
	data["AlphaListEndPosition"] = task_data.AlphaListEndPosition;
	data["AlphaListNowPosition"] = task_data.AlphaListNowPosition;
	data["AlphaListPriority"] = task_data.AlphaListPriority;
	data["AlphaListStockIsTrading"] = task_data.AlphaListStockIsTrading;
	data["TZeroStaticEndPosition"] = task_data.TZeroStaticEndPosition;
	data["TZeroEndPosition"] = task_data.TZeroEndPosition;
	data["TZeroNowPosition"] = task_data.TZeroNowPosition;
	data["TZeroLastOperTime"] = task_data.TZeroLastOperTime;
	data["TZeroGapVolume"] = task_data.TZeroGapVolume;
	data["TZeroEndOperTime"] = task_data.TZeroEndOperTime;
	data["TZeroUpperEndPrice"] = task_data.TZeroUpperEndPrice;
	data["TZeroLowerEndPrice"] = task_data.TZeroLowerEndPrice;
	data["TZeroStockPriceType"] = task_data.TZeroStockPriceType;
	data["TZeroAddPosition"] = task_data.TZeroAddPosition;
	data["T0StaticTotalMoney"] = task_data.T0StaticTotalMoney;
	data["TZeroStaticRights"] = task_data.TZeroStaticRights;
	data["TZeroColseRights"] = task_data.TZeroColseRights;
	data["StillNeedSendPosition"] = task_data.StillNeedSendPosition;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["AlgoNote"] = GBK_TO_UTF8(task_data.AlgoNote);

	this->onRtnInnerHighStockStrategy(data);
};

void UserApi::processRspSetHighStockStrategySwitch(Task task)
{
	PyLock lock;
	CFocusFtdcWholeHighStockStrategySwitchField task_data = any_cast<CFocusFtdcWholeHighStockStrategySwitchField>(task.task_data);
	dict data;
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockWholeSwitch"] = task_data.StockWholeSwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetHighStockStrategySwitch(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryAPIHighStockStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcAPIHighStockStrategyField task_data = any_cast<CFocusFtdcAPIHighStockStrategyField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyName"] = GBK_TO_UTF8(task_data.StockStrategyName);
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["Ratio"] = task_data.Ratio;
	data["MaxVolume"] = task_data.MaxVolume;
	data["MinVolume"] = task_data.MinVolume;
	data["StockRatioAvail"] = task_data.StockRatioAvail;
	data["AverMactchTradeVolume1"] = task_data.AverMactchTradeVolume1;
	data["AverMactchTradeVolume2"] = task_data.AverMactchTradeVolume2;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["StockPriceType"] = task_data.StockPriceType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAPIHighStockStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQrySignalPIHighStockStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcAPIHighStockStrategyField task_data = any_cast<CFocusFtdcAPIHighStockStrategyField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyName"] = GBK_TO_UTF8(task_data.StockStrategyName);
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["Ratio"] = task_data.Ratio;
	data["MaxVolume"] = task_data.MaxVolume;
	data["MinVolume"] = task_data.MinVolume;
	data["StockRatioAvail"] = task_data.StockRatioAvail;
	data["AverMactchTradeVolume1"] = task_data.AverMactchTradeVolume1;
	data["AverMactchTradeVolume2"] = task_data.AverMactchTradeVolume2;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["StockPriceType"] = task_data.StockPriceType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQrySignalPIHighStockStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetSignalHighStockStrategySwitch(Task task)
{
	PyLock lock;
	CFocusFtdcSignalHighStockStrategySwitchField task_data = any_cast<CFocusFtdcSignalHighStockStrategySwitchField>(task.task_data);
	dict data;
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockWholeSwitch"] = task_data.StockWholeSwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetSignalHighStockStrategySwitch(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetHighStockStrategyRelationParam(Task task)
{
	PyLock lock;
	CFocusFtdcHighFutureStrategyRelationField task_data = any_cast<CFocusFtdcHighFutureStrategyRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["StockTimeAvail"] = task_data.StockTimeAvail;
	data["MAStockAvail"] = task_data.MAStockAvail;
	data["StockTolerRatio"] = task_data.StockTolerRatio;
	data["StopDeviRatio"] = task_data.StopDeviRatio;
	data["RrecovrDeviRatio"] = task_data.RrecovrDeviRatio;
	data["TargetMoney"] = task_data.TargetMoney;
	data["RoundMaxMoney"] = task_data.RoundMaxMoney;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["StaticRebuyMoney"] = task_data.StaticRebuyMoney;
	data["BRNeedContinue"] = task_data.BRNeedContinue;
	data["MaxTradePer"] = task_data.MaxTradePer;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["FlowerFuture"] = task_data.FlowerFuture;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["PositionRatioType"] = task_data.PositionRatioType;
	data["StockAlgoType"] = task_data.StockAlgoType;
	data["AlgoStrategyStartTime"] = task_data.AlgoStrategyStartTime;
	data["AlgoStrategyEndTime"] = task_data.AlgoStrategyEndTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetHighStockStrategyRelationParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnHighInnerFutureStrategyRelation(Task task)
{
	PyLock lock;
	CFocusFtdcHighInnerFutureStrategyRelationField task_data = any_cast<CFocusFtdcHighInnerFutureStrategyRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["StockTimeAvail"] = task_data.StockTimeAvail;
	data["MAStockAvail"] = task_data.MAStockAvail;
	data["StockTolerRatio"] = task_data.StockTolerRatio;
	data["StopDeviRatio"] = task_data.StopDeviRatio;
	data["RrecovrDeviRatio"] = task_data.RrecovrDeviRatio;
	data["TargetMoney"] = task_data.TargetMoney;
	data["RoundMaxMoney"] = task_data.RoundMaxMoney;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["StaticRebuyMoney"] = task_data.StaticRebuyMoney;
	data["BRNeedContinue"] = task_data.BRNeedContinue;
	data["MaxTradePer"] = task_data.MaxTradePer;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["FlowerFuture"] = task_data.FlowerFuture;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["PositionRatioType"] = task_data.PositionRatioType;
	data["StockAlgoType"] = task_data.StockAlgoType;
	data["AlgoStrategyStartTime"] = task_data.AlgoStrategyStartTime;
	data["AlgoStrategyEndTime"] = task_data.AlgoStrategyEndTime;
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["RelationOrderStatus"] = task_data.RelationOrderStatus;
	data["RealTargetMoney"] = task_data.RealTargetMoney;
	data["LastTotalBuyMoney"] = task_data.LastTotalBuyMoney;
	data["LastTotalSellMoney"] = task_data.LastTotalSellMoney;
	data["LastTotalNeedBuyMoney"] = task_data.LastTotalNeedBuyMoney;
	data["LastTotalNeedSellMoney"] = task_data.LastTotalNeedSellMoney;
	data["LastFrozenMoney"] = task_data.LastFrozenMoney;
	data["LastBuyPer"] = task_data.LastBuyPer;
	data["LastSellPer"] = task_data.LastSellPer;
	data["LastOperTime"] = task_data.LastOperTime;
	data["TotalBuyCostMoney"] = task_data.TotalBuyCostMoney;
	data["TotalSellCostMoney"] = task_data.TotalSellCostMoney;
	data["TotalFeeCostMoney"] = task_data.TotalFeeCostMoney;
	data["AverCostMoney"] = task_data.AverCostMoney;
	data["IsPerEqual"] = task_data.IsPerEqual;
	data["BuySellGapMoney"] = task_data.BuySellGapMoney;
	data["CloseEndSellMoney"] = task_data.CloseEndSellMoney;
	data["TotalAverCostMoney"] = task_data.TotalAverCostMoney;
	data["BRebuySwitch"] = task_data.BRebuySwitch;
	data["AllAddLastTotalBuyMoney"] = task_data.AllAddLastTotalBuyMoney;
	data["AllAddLastTotalSellMoney"] = task_data.AllAddLastTotalSellMoney;
	data["AllAddTotalBuyCostMoney"] = task_data.AllAddTotalBuyCostMoney;
	data["AllAddTotalSellCostMoney"] = task_data.AllAddTotalSellCostMoney;
	data["AllAddTotalFeeCostMoney"] = task_data.AllAddTotalFeeCostMoney;
	data["AllAddAverCostMoney"] = task_data.AllAddAverCostMoney;
	data["AllAddTotalAverCostMoney"] = task_data.AllAddTotalAverCostMoney;
	data["IndexDirSignal"] = task_data.IndexDirSignal;
	data["LastFuOperTime"] = task_data.LastFuOperTime;
	data["LastFuTarNetPosition"] = task_data.LastFuTarNetPosition;
	data["FutureNote"] = GBK_TO_UTF8(task_data.FutureNote);
	data["FutureSpreadNeedCheck"] = task_data.FutureSpreadNeedCheck;
	data["OpenFuInstrPrice"] = task_data.OpenFuInstrPrice;
	data["BeforeLastFuTarNetPosition"] = task_data.BeforeLastFuTarNetPosition;
	data["NetFuPosition"] = task_data.NetFuPosition;
	data["RealTimeSpreadPrice"] = task_data.RealTimeSpreadPrice;
	data["RealIndexPrice"] = task_data.RealIndexPrice;
	data["RealFuturePrice"] = task_data.RealFuturePrice;
	data["FutureRelationNote"] = GBK_TO_UTF8(task_data.FutureRelationNote);
	data["LastHedgeFuOperTime"] = task_data.LastHedgeFuOperTime;
	data["AlgoNote"] = GBK_TO_UTF8(task_data.AlgoNote);

	this->onRtnHighInnerFutureStrategyRelation(data);
};

void UserApi::processRspQryAllStrategyRelation(Task task)
{
	PyLock lock;
	CFocusFtdcHighFutureStrategyRelationField task_data = any_cast<CFocusFtdcHighFutureStrategyRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["StockTimeAvail"] = task_data.StockTimeAvail;
	data["MAStockAvail"] = task_data.MAStockAvail;
	data["StockTolerRatio"] = task_data.StockTolerRatio;
	data["StopDeviRatio"] = task_data.StopDeviRatio;
	data["RrecovrDeviRatio"] = task_data.RrecovrDeviRatio;
	data["TargetMoney"] = task_data.TargetMoney;
	data["RoundMaxMoney"] = task_data.RoundMaxMoney;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["StaticRebuyMoney"] = task_data.StaticRebuyMoney;
	data["BRNeedContinue"] = task_data.BRNeedContinue;
	data["MaxTradePer"] = task_data.MaxTradePer;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["FlowerFuture"] = task_data.FlowerFuture;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["PositionRatioType"] = task_data.PositionRatioType;
	data["StockAlgoType"] = task_data.StockAlgoType;
	data["AlgoStrategyStartTime"] = task_data.AlgoStrategyStartTime;
	data["AlgoStrategyEndTime"] = task_data.AlgoStrategyEndTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAllStrategyRelation(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetAPIHighStockStrategyParam(Task task)
{
	PyLock lock;
	CFocusFtdcAPIHighStockStrategyField task_data = any_cast<CFocusFtdcAPIHighStockStrategyField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyName"] = GBK_TO_UTF8(task_data.StockStrategyName);
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["Ratio"] = task_data.Ratio;
	data["MaxVolume"] = task_data.MaxVolume;
	data["MinVolume"] = task_data.MinVolume;
	data["StockRatioAvail"] = task_data.StockRatioAvail;
	data["AverMactchTradeVolume1"] = task_data.AverMactchTradeVolume1;
	data["AverMactchTradeVolume2"] = task_data.AverMactchTradeVolume2;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["StockPriceType"] = task_data.StockPriceType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetAPIHighStockStrategyParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelHighStockStrategyRelationParam(Task task)
{
	PyLock lock;
	CFocusFtdcHighFutureStrategyRelationField task_data = any_cast<CFocusFtdcHighFutureStrategyRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["StockTimeAvail"] = task_data.StockTimeAvail;
	data["MAStockAvail"] = task_data.MAStockAvail;
	data["StockTolerRatio"] = task_data.StockTolerRatio;
	data["StopDeviRatio"] = task_data.StopDeviRatio;
	data["RrecovrDeviRatio"] = task_data.RrecovrDeviRatio;
	data["TargetMoney"] = task_data.TargetMoney;
	data["RoundMaxMoney"] = task_data.RoundMaxMoney;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["StaticRebuyMoney"] = task_data.StaticRebuyMoney;
	data["BRNeedContinue"] = task_data.BRNeedContinue;
	data["MaxTradePer"] = task_data.MaxTradePer;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["FlowerFuture"] = task_data.FlowerFuture;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["PositionRatioType"] = task_data.PositionRatioType;
	data["StockAlgoType"] = task_data.StockAlgoType;
	data["AlgoStrategyStartTime"] = task_data.AlgoStrategyStartTime;
	data["AlgoStrategyEndTime"] = task_data.AlgoStrategyEndTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelHighStockStrategyRelationParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelAPIHighStockStrategyParam(Task task)
{
	PyLock lock;
	CFocusFtdcAPIHighStockStrategyField task_data = any_cast<CFocusFtdcAPIHighStockStrategyField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyName"] = GBK_TO_UTF8(task_data.StockStrategyName);
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["Ratio"] = task_data.Ratio;
	data["MaxVolume"] = task_data.MaxVolume;
	data["MinVolume"] = task_data.MinVolume;
	data["StockRatioAvail"] = task_data.StockRatioAvail;
	data["AverMactchTradeVolume1"] = task_data.AverMactchTradeVolume1;
	data["AverMactchTradeVolume2"] = task_data.AverMactchTradeVolume2;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["StockPriceType"] = task_data.StockPriceType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelAPIHighStockStrategyParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryAllTradingPeriodStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcStockMarketTradingPeriodStrategyField task_data = any_cast<CFocusFtdcStockMarketTradingPeriodStrategyField>(task.task_data);
	dict data;
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;
	data["StockOrderType"] = task_data.StockOrderType;
	data["StopDeviRatio"] = task_data.StopDeviRatio;
	data["RrecovrDeviRatio"] = task_data.RrecovrDeviRatio;
	data["RoundMaxMoney"] = task_data.RoundMaxMoney;
	data["StockTimeAvail"] = task_data.StockTimeAvail;
	data["StockTolerRatio"] = task_data.StockTolerRatio;
	data["NeedAddCancelVolumeSwitch"] = task_data.NeedAddCancelVolumeSwitch;
	data["NeedGetSideVolumeSwitch"] = task_data.NeedGetSideVolumeSwitch;
	data["CheckMaxVolumeSwitch"] = task_data.CheckMaxVolumeSwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAllTradingPeriodStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetTradingPeriodStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcStockMarketTradingPeriodStrategyField task_data = any_cast<CFocusFtdcStockMarketTradingPeriodStrategyField>(task.task_data);
	dict data;
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;
	data["StockOrderType"] = task_data.StockOrderType;
	data["StopDeviRatio"] = task_data.StopDeviRatio;
	data["RrecovrDeviRatio"] = task_data.RrecovrDeviRatio;
	data["RoundMaxMoney"] = task_data.RoundMaxMoney;
	data["StockTimeAvail"] = task_data.StockTimeAvail;
	data["StockTolerRatio"] = task_data.StockTolerRatio;
	data["NeedAddCancelVolumeSwitch"] = task_data.NeedAddCancelVolumeSwitch;
	data["NeedGetSideVolumeSwitch"] = task_data.NeedGetSideVolumeSwitch;
	data["CheckMaxVolumeSwitch"] = task_data.CheckMaxVolumeSwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetTradingPeriodStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelTradingPeriodStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcStockMarketTradingPeriodStrategyField task_data = any_cast<CFocusFtdcStockMarketTradingPeriodStrategyField>(task.task_data);
	dict data;
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;
	data["StockOrderType"] = task_data.StockOrderType;
	data["StopDeviRatio"] = task_data.StopDeviRatio;
	data["RrecovrDeviRatio"] = task_data.RrecovrDeviRatio;
	data["RoundMaxMoney"] = task_data.RoundMaxMoney;
	data["StockTimeAvail"] = task_data.StockTimeAvail;
	data["StockTolerRatio"] = task_data.StockTolerRatio;
	data["NeedAddCancelVolumeSwitch"] = task_data.NeedAddCancelVolumeSwitch;
	data["NeedGetSideVolumeSwitch"] = task_data.NeedGetSideVolumeSwitch;
	data["CheckMaxVolumeSwitch"] = task_data.CheckMaxVolumeSwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelTradingPeriodStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryAllInnerStrategyRelation(Task task)
{
	PyLock lock;
	CFocusFtdcHighInnerFutureStrategyRelationField task_data = any_cast<CFocusFtdcHighInnerFutureStrategyRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyType"] = task_data.StockStrategyType;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["StockTimeAvail"] = task_data.StockTimeAvail;
	data["MAStockAvail"] = task_data.MAStockAvail;
	data["StockTolerRatio"] = task_data.StockTolerRatio;
	data["StopDeviRatio"] = task_data.StopDeviRatio;
	data["RrecovrDeviRatio"] = task_data.RrecovrDeviRatio;
	data["TargetMoney"] = task_data.TargetMoney;
	data["RoundMaxMoney"] = task_data.RoundMaxMoney;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["StaticRebuyMoney"] = task_data.StaticRebuyMoney;
	data["BRNeedContinue"] = task_data.BRNeedContinue;
	data["MaxTradePer"] = task_data.MaxTradePer;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["FlowerFuture"] = task_data.FlowerFuture;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["PositionRatioType"] = task_data.PositionRatioType;
	data["StockAlgoType"] = task_data.StockAlgoType;
	data["AlgoStrategyStartTime"] = task_data.AlgoStrategyStartTime;
	data["AlgoStrategyEndTime"] = task_data.AlgoStrategyEndTime;
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["RelationOrderStatus"] = task_data.RelationOrderStatus;
	data["RealTargetMoney"] = task_data.RealTargetMoney;
	data["LastTotalBuyMoney"] = task_data.LastTotalBuyMoney;
	data["LastTotalSellMoney"] = task_data.LastTotalSellMoney;
	data["LastTotalNeedBuyMoney"] = task_data.LastTotalNeedBuyMoney;
	data["LastTotalNeedSellMoney"] = task_data.LastTotalNeedSellMoney;
	data["LastFrozenMoney"] = task_data.LastFrozenMoney;
	data["LastBuyPer"] = task_data.LastBuyPer;
	data["LastSellPer"] = task_data.LastSellPer;
	data["LastOperTime"] = task_data.LastOperTime;
	data["TotalBuyCostMoney"] = task_data.TotalBuyCostMoney;
	data["TotalSellCostMoney"] = task_data.TotalSellCostMoney;
	data["TotalFeeCostMoney"] = task_data.TotalFeeCostMoney;
	data["AverCostMoney"] = task_data.AverCostMoney;
	data["IsPerEqual"] = task_data.IsPerEqual;
	data["BuySellGapMoney"] = task_data.BuySellGapMoney;
	data["CloseEndSellMoney"] = task_data.CloseEndSellMoney;
	data["TotalAverCostMoney"] = task_data.TotalAverCostMoney;
	data["BRebuySwitch"] = task_data.BRebuySwitch;
	data["AllAddLastTotalBuyMoney"] = task_data.AllAddLastTotalBuyMoney;
	data["AllAddLastTotalSellMoney"] = task_data.AllAddLastTotalSellMoney;
	data["AllAddTotalBuyCostMoney"] = task_data.AllAddTotalBuyCostMoney;
	data["AllAddTotalSellCostMoney"] = task_data.AllAddTotalSellCostMoney;
	data["AllAddTotalFeeCostMoney"] = task_data.AllAddTotalFeeCostMoney;
	data["AllAddAverCostMoney"] = task_data.AllAddAverCostMoney;
	data["AllAddTotalAverCostMoney"] = task_data.AllAddTotalAverCostMoney;
	data["IndexDirSignal"] = task_data.IndexDirSignal;
	data["LastFuOperTime"] = task_data.LastFuOperTime;
	data["LastFuTarNetPosition"] = task_data.LastFuTarNetPosition;
	data["FutureNote"] = GBK_TO_UTF8(task_data.FutureNote);
	data["FutureSpreadNeedCheck"] = task_data.FutureSpreadNeedCheck;
	data["OpenFuInstrPrice"] = task_data.OpenFuInstrPrice;
	data["BeforeLastFuTarNetPosition"] = task_data.BeforeLastFuTarNetPosition;
	data["NetFuPosition"] = task_data.NetFuPosition;
	data["RealTimeSpreadPrice"] = task_data.RealTimeSpreadPrice;
	data["RealIndexPrice"] = task_data.RealIndexPrice;
	data["RealFuturePrice"] = task_data.RealFuturePrice;
	data["FutureRelationNote"] = GBK_TO_UTF8(task_data.FutureRelationNote);
	data["LastHedgeFuOperTime"] = task_data.LastHedgeFuOperTime;
	data["AlgoNote"] = GBK_TO_UTF8(task_data.AlgoNote);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAllInnerStrategyRelation(data, error, task.task_id, task.task_last);
};

void UserApi::processRspCancelAllStrategyRelationOrder(Task task)
{
	PyLock lock;
	CFocusFtdcQryWholeHighStockStrategyField task_data = any_cast<CFocusFtdcQryWholeHighStockStrategyField>(task.task_data);
	dict data;
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyType"] = task_data.StockStrategyType;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspCancelAllStrategyRelationOrder(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetAutoReBuySwitch(Task task)
{
	PyLock lock;
	CFocusFtdcRelationAutoReBuySwitchField task_data = any_cast<CFocusFtdcRelationAutoReBuySwitchField>(task.task_data);
	dict data;
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["RelationReBuySwitch"] = task_data.RelationReBuySwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetAutoReBuySwitch(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSendFutureStrategyOrder(Task task)
{
	PyLock lock;
	CFocusFtdcFutureStrategyOrderField task_data = any_cast<CFocusFtdcFutureStrategyOrderField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["TargetNetPosition"] = task_data.TargetNetPosition;
	data["StartTradingTime"] = task_data.StartTradingTime;
	data["AlgoType"] = task_data.AlgoType;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["StrategyIsTrading"] = task_data.StrategyIsTrading;
	data["StrategyPrice"] = task_data.StrategyPrice;
	data["MactchTrdVol"] = task_data.MactchTrdVol;
	data["MactchTrdPriceType"] = task_data.MactchTrdPriceType;
	data["VwapMaxVolume"] = task_data.VwapMaxVolume;
	data["IsAddPosi"] = task_data.IsAddPosi;
	data["AddPositionType"] = task_data.AddPositionType;
	data["PriceDirection"] = task_data.PriceDirection;
	data["TriggerPrice"] = task_data.TriggerPrice;
	data["TotalTimeAvail"] = task_data.TotalTimeAvail;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSendFutureStrategyOrder(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetAlgoParm(Task task)
{
	PyLock lock;
	CFocusFtdcAlgoParmField task_data = any_cast<CFocusFtdcAlgoParmField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["TolerTick"] = task_data.TolerTick;
	data["TwapTotalTime"] = task_data.TwapTotalTime;
	data["TwapSplitAmount"] = task_data.TwapSplitAmount;
	data["VwapTimeAvail"] = task_data.VwapTimeAvail;
	data["VwapTotalTime"] = task_data.VwapTotalTime;
	data["VwapVolumeTotalTime"] = task_data.VwapVolumeTotalTime;
	data["StockStrategyPrice"] = task_data.StockStrategyPrice;
	data["MaxNetPosition"] = task_data.MaxNetPosition;
	data["MinChangePosition"] = task_data.MinChangePosition;
	data["NeedGetSideVolumeSwitch"] = task_data.NeedGetSideVolumeSwitch;
	data["SideVolumePer"] = task_data.SideVolumePer;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetAlgoParm(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnInnerFutureStrategyOrder(Task task)
{
	PyLock lock;
	CFocusFtdcInnerFutureStrategyOrderField task_data = any_cast<CFocusFtdcInnerFutureStrategyOrderField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["TargetNetPosition"] = task_data.TargetNetPosition;
	data["StartTradingTime"] = task_data.StartTradingTime;
	data["AlgoType"] = task_data.AlgoType;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["StrategyIsTrading"] = task_data.StrategyIsTrading;
	data["StrategyPrice"] = task_data.StrategyPrice;
	data["MactchTrdVol"] = task_data.MactchTrdVol;
	data["MactchTrdPriceType"] = task_data.MactchTrdPriceType;
	data["VwapMaxVolume"] = task_data.VwapMaxVolume;
	data["IsAddPosi"] = task_data.IsAddPosi;
	data["AddPositionType"] = task_data.AddPositionType;
	data["PriceDirection"] = task_data.PriceDirection;
	data["TriggerPrice"] = task_data.TriggerPrice;
	data["TotalTimeAvail"] = task_data.TotalTimeAvail;
	data["TolerTick"] = task_data.TolerTick;
	data["TwapTotalTime"] = task_data.TwapTotalTime;
	data["TwapSplitAmount"] = task_data.TwapSplitAmount;
	data["VwapTimeAvail"] = task_data.VwapTimeAvail;
	data["VwapTotalTime"] = task_data.VwapTotalTime;
	data["VwapVolumeTotalTime"] = task_data.VwapVolumeTotalTime;
	data["StockStrategyPrice"] = task_data.StockStrategyPrice;
	data["MaxNetPosition"] = task_data.MaxNetPosition;
	data["MinChangePosition"] = task_data.MinChangePosition;
	data["NeedGetSideVolumeSwitch"] = task_data.NeedGetSideVolumeSwitch;
	data["SideVolumePer"] = task_data.SideVolumePer;
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["GapMillisec"] = task_data.GapMillisec;
	data["SplitVolume"] = task_data.SplitVolume;
	data["OrginalSplitVolume"] = task_data.OrginalSplitVolume;
	data["StaticlTotalNeedTradeVolume"] = task_data.StaticlTotalNeedTradeVolume;
	data["LastCurrOperTime"] = task_data.LastCurrOperTime;
	data["LastCurrMillisec"] = task_data.LastCurrMillisec;
	data["TolerTimeAvail"] = task_data.TolerTimeAvail;
	data["SignalLastPer"] = task_data.SignalLastPer;
	data["PreparPrice"] = task_data.PreparPrice;
	data["TotalCostMoney"] = task_data.TotalCostMoney;
	data["TotalFeeCostMoney"] = task_data.TotalFeeCostMoney;
	data["AverCostMoney"] = task_data.AverCostMoney;
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["StrategyTradeVolume"] = task_data.StrategyTradeVolume;
	data["NowPosition"] = task_data.NowPosition;
	data["OrginRecvOrderTime"] = task_data.OrginRecvOrderTime;
	data["LastRecvOrderTime"] = task_data.LastRecvOrderTime;
	data["LastOperTime"] = task_data.LastOperTime;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;

	this->onRtnInnerFutureStrategyOrder(data);
};

void UserApi::processRspQryAlgoParm(Task task)
{
	PyLock lock;
	CFocusFtdcAlgoParmField task_data = any_cast<CFocusFtdcAlgoParmField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["TolerTick"] = task_data.TolerTick;
	data["TwapTotalTime"] = task_data.TwapTotalTime;
	data["TwapSplitAmount"] = task_data.TwapSplitAmount;
	data["VwapTimeAvail"] = task_data.VwapTimeAvail;
	data["VwapTotalTime"] = task_data.VwapTotalTime;
	data["VwapVolumeTotalTime"] = task_data.VwapVolumeTotalTime;
	data["StockStrategyPrice"] = task_data.StockStrategyPrice;
	data["MaxNetPosition"] = task_data.MaxNetPosition;
	data["MinChangePosition"] = task_data.MinChangePosition;
	data["NeedGetSideVolumeSwitch"] = task_data.NeedGetSideVolumeSwitch;
	data["SideVolumePer"] = task_data.SideVolumePer;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAlgoParm(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryFutureStrategyOrder(Task task)
{
	PyLock lock;
	CFocusFtdcFutureStrategyOrderField task_data = any_cast<CFocusFtdcFutureStrategyOrderField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["TargetNetPosition"] = task_data.TargetNetPosition;
	data["StartTradingTime"] = task_data.StartTradingTime;
	data["AlgoType"] = task_data.AlgoType;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["StrategyIsTrading"] = task_data.StrategyIsTrading;
	data["StrategyPrice"] = task_data.StrategyPrice;
	data["MactchTrdVol"] = task_data.MactchTrdVol;
	data["MactchTrdPriceType"] = task_data.MactchTrdPriceType;
	data["VwapMaxVolume"] = task_data.VwapMaxVolume;
	data["IsAddPosi"] = task_data.IsAddPosi;
	data["AddPositionType"] = task_data.AddPositionType;
	data["PriceDirection"] = task_data.PriceDirection;
	data["TriggerPrice"] = task_data.TriggerPrice;
	data["TotalTimeAvail"] = task_data.TotalTimeAvail;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryFutureStrategyOrder(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInnerFutureStrategyOrder(Task task)
{
	PyLock lock;
	CFocusFtdcInnerFutureStrategyOrderField task_data = any_cast<CFocusFtdcInnerFutureStrategyOrderField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["TargetNetPosition"] = task_data.TargetNetPosition;
	data["StartTradingTime"] = task_data.StartTradingTime;
	data["AlgoType"] = task_data.AlgoType;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["StrategyIsTrading"] = task_data.StrategyIsTrading;
	data["StrategyPrice"] = task_data.StrategyPrice;
	data["MactchTrdVol"] = task_data.MactchTrdVol;
	data["MactchTrdPriceType"] = task_data.MactchTrdPriceType;
	data["VwapMaxVolume"] = task_data.VwapMaxVolume;
	data["IsAddPosi"] = task_data.IsAddPosi;
	data["AddPositionType"] = task_data.AddPositionType;
	data["PriceDirection"] = task_data.PriceDirection;
	data["TriggerPrice"] = task_data.TriggerPrice;
	data["TotalTimeAvail"] = task_data.TotalTimeAvail;
	data["TolerTick"] = task_data.TolerTick;
	data["TwapTotalTime"] = task_data.TwapTotalTime;
	data["TwapSplitAmount"] = task_data.TwapSplitAmount;
	data["VwapTimeAvail"] = task_data.VwapTimeAvail;
	data["VwapTotalTime"] = task_data.VwapTotalTime;
	data["VwapVolumeTotalTime"] = task_data.VwapVolumeTotalTime;
	data["StockStrategyPrice"] = task_data.StockStrategyPrice;
	data["MaxNetPosition"] = task_data.MaxNetPosition;
	data["MinChangePosition"] = task_data.MinChangePosition;
	data["NeedGetSideVolumeSwitch"] = task_data.NeedGetSideVolumeSwitch;
	data["SideVolumePer"] = task_data.SideVolumePer;
	data["Direction"] = task_data.Direction;
	data["OffsetFlag"] = task_data.OffsetFlag;
	data["GapMillisec"] = task_data.GapMillisec;
	data["SplitVolume"] = task_data.SplitVolume;
	data["OrginalSplitVolume"] = task_data.OrginalSplitVolume;
	data["StaticlTotalNeedTradeVolume"] = task_data.StaticlTotalNeedTradeVolume;
	data["LastCurrOperTime"] = task_data.LastCurrOperTime;
	data["LastCurrMillisec"] = task_data.LastCurrMillisec;
	data["TolerTimeAvail"] = task_data.TolerTimeAvail;
	data["SignalLastPer"] = task_data.SignalLastPer;
	data["PreparPrice"] = task_data.PreparPrice;
	data["TotalCostMoney"] = task_data.TotalCostMoney;
	data["TotalFeeCostMoney"] = task_data.TotalFeeCostMoney;
	data["AverCostMoney"] = task_data.AverCostMoney;
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["StrategyTradeVolume"] = task_data.StrategyTradeVolume;
	data["NowPosition"] = task_data.NowPosition;
	data["OrginRecvOrderTime"] = task_data.OrginRecvOrderTime;
	data["LastRecvOrderTime"] = task_data.LastRecvOrderTime;
	data["LastOperTime"] = task_data.LastOperTime;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInnerFutureStrategyOrder(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetStragedyMessage(Task task)
{
	PyLock lock;
	CFocusFtdcIndexDirSignalField task_data = any_cast<CFocusFtdcIndexDirSignalField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["MessageType"] = task_data.MessageType;
	data["MessageID"] = task_data.MessageID;
	data["NeedNtfMessage"] = task_data.NeedNtfMessage;
	data["OperTime"] = task_data.OperTime;
	data["Note"] = GBK_TO_UTF8(task_data.Note);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetStragedyMessage(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryIndexDirSignal(Task task)
{
	PyLock lock;
	CFocusFtdcIndexDirSignalField task_data = any_cast<CFocusFtdcIndexDirSignalField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["MessageType"] = task_data.MessageType;
	data["MessageID"] = task_data.MessageID;
	data["NeedNtfMessage"] = task_data.NeedNtfMessage;
	data["OperTime"] = task_data.OperTime;
	data["Note"] = GBK_TO_UTF8(task_data.Note);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryIndexDirSignal(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelFutureStrategyOrder(Task task)
{
	PyLock lock;
	CFocusFtdcFutureStrategyOrderIndexField task_data = any_cast<CFocusFtdcFutureStrategyOrderIndexField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelFutureStrategyOrder(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelAlgoParm(Task task)
{
	PyLock lock;
	CFocusFtdcFutureStrategyOrderIndexField task_data = any_cast<CFocusFtdcFutureStrategyOrderIndexField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelAlgoParm(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetSpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcSpreadInstrStrategyField task_data = any_cast<CFocusFtdcSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["Note"] = GBK_TO_UTF8(task_data.Note);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetSpreadInstrStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQrySpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcSpreadInstrStrategyField task_data = any_cast<CFocusFtdcSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["Note"] = GBK_TO_UTF8(task_data.Note);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQrySpreadInstrStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelSpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcSpreadInstrStrategyField task_data = any_cast<CFocusFtdcSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["Note"] = GBK_TO_UTF8(task_data.Note);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelSpreadInstrStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryInnerSpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcInnerSpreadInstrStrategyField task_data = any_cast<CFocusFtdcInnerSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["LastOperTime"] = task_data.LastOperTime;
	data["SignalLastPer"] = task_data.SignalLastPer;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInnerSpreadInstrStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnInnerSpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcInnerSpreadInstrStrategyField task_data = any_cast<CFocusFtdcInnerSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["LastOperTime"] = task_data.LastOperTime;
	data["SignalLastPer"] = task_data.SignalLastPer;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);

	this->onRtnInnerSpreadInstrStrategy(data);
};

void UserApi::processRspSetTZeroHighStockStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcTZeroHighStockStrategyField task_data = any_cast<CFocusFtdcTZeroHighStockStrategyField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["TZeroGapVolume"] = task_data.TZeroGapVolume;
	data["TZeroStockPriceType"] = task_data.TZeroStockPriceType;
	data["TZeroEndOperTime"] = task_data.TZeroEndOperTime;
	data["TZeroUpperEndPrice"] = task_data.TZeroUpperEndPrice;
	data["TZeroLowerEndPrice"] = task_data.TZeroLowerEndPrice;
	data["TZeroLastOperTime"] = task_data.TZeroLastOperTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetTZeroHighStockStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryTZeroHighStockStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcTZeroHighStockStrategyField task_data = any_cast<CFocusFtdcTZeroHighStockStrategyField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["TZeroGapVolume"] = task_data.TZeroGapVolume;
	data["TZeroStockPriceType"] = task_data.TZeroStockPriceType;
	data["TZeroEndOperTime"] = task_data.TZeroEndOperTime;
	data["TZeroUpperEndPrice"] = task_data.TZeroUpperEndPrice;
	data["TZeroLowerEndPrice"] = task_data.TZeroLowerEndPrice;
	data["TZeroLastOperTime"] = task_data.TZeroLastOperTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryTZeroHighStockStrategy(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnStragedyMessage(Task task)
{
	PyLock lock;
	CFocusFtdcIndexDirSignalField task_data = any_cast<CFocusFtdcIndexDirSignalField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["MessageType"] = task_data.MessageType;
	data["MessageID"] = task_data.MessageID;
	data["NeedNtfMessage"] = task_data.NeedNtfMessage;
	data["OperTime"] = task_data.OperTime;
	data["Note"] = GBK_TO_UTF8(task_data.Note);

	this->onRtnStragedyMessage(data);
};

void UserApi::processRspSetfutruetradeinstr(Task task)
{
	PyLock lock;
	CFocusFtdcQryInstrumentField task_data = any_cast<CFocusFtdcQryInstrumentField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetfutruetradeinstr(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryFlowerFutureTargetMoney(Task task)
{
	PyLock lock;
	CFocusFtdcFlowerFutureTargetMoneyField task_data = any_cast<CFocusFtdcFlowerFutureTargetMoneyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["TradingDay"] = task_data.TradingDay;
	data["LastOperTime"] = task_data.LastOperTime;
	data["FlowerFutureTarMoney"] = task_data.FlowerFutureTarMoney;
	data["WholeSwitch"] = task_data.WholeSwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryFlowerFutureTargetMoney(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetFlowerFutureTargetMoney(Task task)
{
	PyLock lock;
	CFocusFtdcFlowerFutureTargetMoneyField task_data = any_cast<CFocusFtdcFlowerFutureTargetMoneyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["TradingDay"] = task_data.TradingDay;
	data["LastOperTime"] = task_data.LastOperTime;
	data["FlowerFutureTarMoney"] = task_data.FlowerFutureTarMoney;
	data["WholeSwitch"] = task_data.WholeSwitch;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetFlowerFutureTargetMoney(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnParentOrder(Task task)
{
	PyLock lock;
	CFocusFtdcParentOrderField task_data = any_cast<CFocusFtdcParentOrderField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["Direction"] = task_data.Direction;
	data["orderQty"] = task_data.orderQty;
	data["orderAmt"] = task_data.orderAmt;
	data["TradingDay"] = task_data.TradingDay;
	data["LastOperTime"] = task_data.LastOperTime;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["StrategyID"] = task_data.StrategyID;

	this->onRtnParentOrder(data);
};

void UserApi::processRtnParentOrderAction(Task task)
{
	PyLock lock;
	CFocusFtdcParentOrderActionField task_data = any_cast<CFocusFtdcParentOrderActionField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["ActionOption"] = task_data.ActionOption;

	this->onRtnParentOrderAction(data);
};

void UserApi::processRtnAmendParentOrder(Task task)
{
	PyLock lock;
	CFocusFtdcAmendParentOrderField task_data = any_cast<CFocusFtdcAmendParentOrderField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["Direction"] = task_data.Direction;
	data["orderQty"] = task_data.orderQty;
	data["orderAmt"] = task_data.orderAmt;
	data["TradingDay"] = task_data.TradingDay;
	data["LastOperTime"] = task_data.LastOperTime;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["StrategyID"] = task_data.StrategyID;

	this->onRtnAmendParentOrder(data);
};

void UserApi::processRtnExtraManualParentOrder(Task task)
{
	PyLock lock;
	CFocusFtdcExtraManualParentOrderField task_data = any_cast<CFocusFtdcExtraManualParentOrderField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["StrategyID"] = task_data.StrategyID;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["sliceQty"] = task_data.sliceQty;
	data["slicePrice"] = task_data.slicePrice;
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);

	this->onRtnExtraManualParentOrder(data);
};

void UserApi::processRspQryMarketTradingTime(Task task)
{
	PyLock lock;
	CFocusFtdcMarketTradingPeriodInfoField task_data = any_cast<CFocusFtdcMarketTradingPeriodInfoField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["ExchangeName"] = GBK_TO_UTF8(task_data.ExchangeName);
	data["ProductID"] = GBK_TO_UTF8(task_data.ProductID);
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;
	data["Flags"] = task_data.Flags;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMarketTradingTime(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetFutureStrategyTotalSecondRelationParam(Task task)
{
	PyLock lock;
	CFocusFtdcFutureStrategyTotalSecondRelationField task_data = any_cast<CFocusFtdcFutureStrategyTotalSecondRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetFutureStrategyTotalSecondRelationParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnHighInnerFutureStrategyTotalSecondRelation(Task task)
{
	PyLock lock;
	CFocusFtdcInnerFutureStrategyTotalSecondRelationField task_data = any_cast<CFocusFtdcInnerFutureStrategyTotalSecondRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["LastTotalBuyMoney"] = task_data.LastTotalBuyMoney;
	data["LastTotalSellMoney"] = task_data.LastTotalSellMoney;
	data["LastTotalNeedBuyMoney"] = task_data.LastTotalNeedBuyMoney;
	data["LastTotalNeedSellMoney"] = task_data.LastTotalNeedSellMoney;
	data["LastFuOperTime"] = task_data.LastFuOperTime;
	data["LastFuTarNetPosition"] = task_data.LastFuTarNetPosition;
	data["FutureNote"] = GBK_TO_UTF8(task_data.FutureNote);
	data["FutureSpreadNeedCheck"] = task_data.FutureSpreadNeedCheck;
	data["OpenFuInstrPrice"] = task_data.OpenFuInstrPrice;
	data["BeforeLastFuTarNetPosition"] = task_data.BeforeLastFuTarNetPosition;
	data["NetFuPosition"] = task_data.NetFuPosition;
	data["RealTimeSpreadPrice"] = task_data.RealTimeSpreadPrice;
	data["RealIndexPrice"] = task_data.RealIndexPrice;
	data["RealFuturePrice"] = task_data.RealFuturePrice;
	data["LastHedgeFuOperTime"] = task_data.LastHedgeFuOperTime;
	data["DoubleFutureAmount"] = task_data.DoubleFutureAmount;

	this->onRtnHighInnerFutureStrategyTotalSecondRelation(data);
};

void UserApi::processRspQryAllTotalSecondStrategyRelation(Task task)
{
	PyLock lock;
	CFocusFtdcFutureStrategyTotalSecondRelationField task_data = any_cast<CFocusFtdcFutureStrategyTotalSecondRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAllTotalSecondStrategyRelation(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelHighStockStrategyTotalSecondRelationParam(Task task)
{
	PyLock lock;
	CFocusFtdcFutureStrategyTotalSecondRelationField task_data = any_cast<CFocusFtdcFutureStrategyTotalSecondRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelHighStockStrategyTotalSecondRelationParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryAllInnerTotalSecondStrategyRelation(Task task)
{
	PyLock lock;
	CFocusFtdcInnerFutureStrategyTotalSecondRelationField task_data = any_cast<CFocusFtdcInnerFutureStrategyTotalSecondRelationField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["StockStrategyID"] = task_data.StockStrategyID;
	data["StockStrategyIsTrading"] = task_data.StockStrategyIsTrading;
	data["FutureExchangeID"] = task_data.FutureExchangeID;
	data["FutureInstrumentID"] = GBK_TO_UTF8(task_data.FutureInstrumentID);
	data["FutureDirection"] = task_data.FutureDirection;
	data["FuturePriceType"] = task_data.FuturePriceType;
	data["FutureIsTrading"] = task_data.FutureIsTrading;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FutureTimeAvail"] = task_data.FutureTimeAvail;
	data["FutureAvailAmount"] = task_data.FutureAvailAmount;
	data["FutureAlgoType"] = task_data.FutureAlgoType;
	data["IndexExchangeID"] = task_data.IndexExchangeID;
	data["IndexInstrumentID"] = GBK_TO_UTF8(task_data.IndexInstrumentID);
	data["SpreadPrice"] = task_data.SpreadPrice;
	data["FutureAmount"] = task_data.FutureAmount;
	data["ListPriceType"] = task_data.ListPriceType;
	data["FuStockRelation"] = task_data.FuStockRelation;
	data["TpStart"] = task_data.TpStart;
	data["TpEnd"] = task_data.TpEnd;
	data["Note"] = GBK_TO_UTF8(task_data.Note);
	data["LastTotalBuyMoney"] = task_data.LastTotalBuyMoney;
	data["LastTotalSellMoney"] = task_data.LastTotalSellMoney;
	data["LastTotalNeedBuyMoney"] = task_data.LastTotalNeedBuyMoney;
	data["LastTotalNeedSellMoney"] = task_data.LastTotalNeedSellMoney;
	data["LastFuOperTime"] = task_data.LastFuOperTime;
	data["LastFuTarNetPosition"] = task_data.LastFuTarNetPosition;
	data["FutureNote"] = GBK_TO_UTF8(task_data.FutureNote);
	data["FutureSpreadNeedCheck"] = task_data.FutureSpreadNeedCheck;
	data["OpenFuInstrPrice"] = task_data.OpenFuInstrPrice;
	data["BeforeLastFuTarNetPosition"] = task_data.BeforeLastFuTarNetPosition;
	data["NetFuPosition"] = task_data.NetFuPosition;
	data["RealTimeSpreadPrice"] = task_data.RealTimeSpreadPrice;
	data["RealIndexPrice"] = task_data.RealIndexPrice;
	data["RealFuturePrice"] = task_data.RealFuturePrice;
	data["LastHedgeFuOperTime"] = task_data.LastHedgeFuOperTime;
	data["DoubleFutureAmount"] = task_data.DoubleFutureAmount;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryAllInnerTotalSecondStrategyRelation(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryParentDetialUpdateMessage(Task task)
{
	PyLock lock;
	CFocusFtdcParentDetialUpdateMessageField task_data = any_cast<CFocusFtdcParentDetialUpdateMessageField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["transactDay"] = task_data.transactDay;
	data["transactTime"] = task_data.transactTime;
	data["strategyStatus"] = task_data.strategyStatus;
	data["pauseReason"] = task_data.pauseReason;
	data["Direction"] = task_data.Direction;
	data["orderQty"] = task_data.orderQty;
	data["knockQty"] = task_data.knockQty;
	data["knockAmt"] = task_data.knockAmt;
	data["knockAmtWithFee"] = task_data.knockAmtWithFee;
	data["orderStatus"] = task_data.orderStatus;
	data["avgPrice"] = task_data.avgPrice;
	data["marketTwap"] = task_data.marketTwap;
	data["marketVwap"] = task_data.marketVwap;
	data["arrivalPrice"] = task_data.arrivalPrice;
	data["avgOffset_T"] = task_data.avgOffset_T;
	data["avgOffset_V"] = task_data.avgOffset_V;
	data["avgOffset_A"] = task_data.avgOffset_A;
	data["realParticipateRate"] = task_data.realParticipateRate;
	data["cancelRate"] = task_data.cancelRate;
	data["avgOpenTime"] = task_data.avgOpenTime;
	data["passiveRate"] = task_data.passiveRate;
	data["serialNum"] = task_data.serialNum;
	data["failReason"] = task_data.failReason;
	data["targetProgress"] = task_data.targetProgress;
	data["knockPercent"] = task_data.knockPercent;
	data["progressOffset"] = task_data.progressOffset;
	data["pushFlag"] = task_data.pushFlag;
	data["ErrorID"] = task_data.ErrorID;
	data["FunctionID"] = task_data.FunctionID;
	data["StrategyStartTime"] = task_data.StrategyStartTime;
	data["StrategyEndTime"] = task_data.StrategyEndTime;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryParentDetialUpdateMessage(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryParentOrderStaticParam(Task task)
{
	PyLock lock;
	CFocusFtdcParentOrderStaticParamField task_data = any_cast<CFocusFtdcParentOrderStaticParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
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

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryParentOrderStaticParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnParentDetialUpdateMessage(Task task)
{
	PyLock lock;
	CFocusFtdcParentDetialUpdateMessageField task_data = any_cast<CFocusFtdcParentDetialUpdateMessageField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;
	data["transactDay"] = task_data.transactDay;
	data["transactTime"] = task_data.transactTime;
	data["strategyStatus"] = task_data.strategyStatus;
	data["pauseReason"] = task_data.pauseReason;
	data["Direction"] = task_data.Direction;
	data["orderQty"] = task_data.orderQty;
	data["knockQty"] = task_data.knockQty;
	data["knockAmt"] = task_data.knockAmt;
	data["knockAmtWithFee"] = task_data.knockAmtWithFee;
	data["orderStatus"] = task_data.orderStatus;
	data["avgPrice"] = task_data.avgPrice;
	data["marketTwap"] = task_data.marketTwap;
	data["marketVwap"] = task_data.marketVwap;
	data["arrivalPrice"] = task_data.arrivalPrice;
	data["avgOffset_T"] = task_data.avgOffset_T;
	data["avgOffset_V"] = task_data.avgOffset_V;
	data["avgOffset_A"] = task_data.avgOffset_A;
	data["realParticipateRate"] = task_data.realParticipateRate;
	data["cancelRate"] = task_data.cancelRate;
	data["avgOpenTime"] = task_data.avgOpenTime;
	data["passiveRate"] = task_data.passiveRate;
	data["serialNum"] = task_data.serialNum;
	data["failReason"] = task_data.failReason;
	data["targetProgress"] = task_data.targetProgress;
	data["knockPercent"] = task_data.knockPercent;
	data["progressOffset"] = task_data.progressOffset;
	data["pushFlag"] = task_data.pushFlag;
	data["ErrorID"] = task_data.ErrorID;
	data["FunctionID"] = task_data.FunctionID;
	data["StrategyStartTime"] = task_data.StrategyStartTime;
	data["StrategyEndTime"] = task_data.StrategyEndTime;

	this->onRtnParentDetialUpdateMessage(data);
};

void UserApi::processRspSetParentOrderStaticParam(Task task)
{
	PyLock lock;
	CFocusFtdcParentOrderStaticParamField task_data = any_cast<CFocusFtdcParentOrderStaticParamField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
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

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetParentOrderStaticParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspDelParentOrderStaticParam(Task task)
{
	PyLock lock;
	CFocusFtdcParentOrderIndexField task_data = any_cast<CFocusFtdcParentOrderIndexField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspDelParentOrderStaticParam(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryJavaAlgoStatus(Task task)
{
	PyLock lock;
	CFocusFtdcFocusStatusField task_data = any_cast<CFocusFtdcFocusStatusField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["TradeStatus"] = task_data.TradeStatus;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryJavaAlgoStatus(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnJavaAlgoStatus(Task task)
{
	PyLock lock;
	CFocusFtdcFocusStatusField task_data = any_cast<CFocusFtdcFocusStatusField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["TradeStatus"] = task_data.TradeStatus;

	this->onRtnJavaAlgoStatus(data);
};

void UserApi::processRspQryFuSkAccountRelation(Task task)
{
	PyLock lock;
	CFocusFtdcFuSkAccountRelationField task_data = any_cast<CFocusFtdcFuSkAccountRelationField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["StockInvestorID"] = task_data.StockInvestorID;
	data["FutureInvestorID"] = task_data.FutureInvestorID;
	data["FuturePasswd"] = task_data.FuturePasswd;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryFuSkAccountRelation(data, error, task.task_id, task.task_last);
};

void UserApi::processRspBatchOrderInsert(Task task)
{
	PyLock lock;
	CFocusFtdcBatchInputOrderField task_data = any_cast<CFocusFtdcBatchInputOrderField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
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

void UserApi::processRspBatchOrderAction(Task task)
{
	PyLock lock;
	CFocusFtdcBatchOrderActionField task_data = any_cast<CFocusFtdcBatchOrderActionField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["UserOrderLocalID"] = GBK_TO_UTF8(task_data.UserOrderLocalID);
	data["UserCustom"] = GBK_TO_UTF8(task_data.UserCustom);
	data["ExchangeID"] = task_data.ExchangeID;
	data["OrderSysID"] = task_data.OrderSysID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["UserOrderActionLocalID"] = GBK_TO_UTF8(task_data.UserOrderActionLocalID);
	data["FrontID"] = task_data.FrontID;
	data["SessionID"] = task_data.SessionID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspBatchOrderAction(data, error, task.task_id, task.task_last);
};

void UserApi::processRspSetUserInvestorSeatBasePasswd(Task task)
{
	PyLock lock;
	CFocusFtdcUserInvestorSeatBaseField task_data = any_cast<CFocusFtdcUserInvestorSeatBaseField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["OldUserPassword"] = GBK_TO_UTF8(task_data.OldUserPassword);
	data["NewUserPassword"] = GBK_TO_UTF8(task_data.NewUserPassword);
	data["SeatID"] = task_data.SeatID;
	data["OldSeatPassword"] = task_data.OldSeatPassword;
	data["NewSeatPassword"] = task_data.NewSeatPassword;
	data["InvestorID"] = task_data.InvestorID;
	data["OldInvestorPasswd"] = task_data.OldInvestorPasswd;
	data["NewInvestorPasswd"] = task_data.NewInvestorPasswd;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSetUserInvestorSeatBasePasswd(data, error, task.task_id, task.task_last);
};

void UserApi::processRtnSpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcSpreadInstrStrategyField task_data = any_cast<CFocusFtdcSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["Note"] = GBK_TO_UTF8(task_data.Note);

	this->onRtnSpreadInstrStrategy(data);
};

void UserApi::processRtnAmendPSpreadInstrStrategy(Task task)
{
	PyLock lock;
	CFocusFtdcSpreadInstrStrategyField task_data = any_cast<CFocusFtdcSpreadInstrStrategyField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
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
	data["Note"] = GBK_TO_UTF8(task_data.Note);

	this->onRtnAmendPSpreadInstrStrategy(data);
};

void UserApi::processRspQryUnFinshPutureOrder(Task task)
{
	PyLock lock;
	CFocusFtdcUnFinshPutureOrderField task_data = any_cast<CFocusFtdcUnFinshPutureOrderField>(task.task_data);
	dict data;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["InvestorID"] = task_data.InvestorID;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = GBK_TO_UTF8(task_data.InstrumentID);
	data["StrategyID"] = task_data.StrategyID;
	data["TargetNetPosition"] = task_data.TargetNetPosition;
	data["AlgoParentOrderSysID"] = task_data.AlgoParentOrderSysID;

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryUnFinshPutureOrder(data, error, task.task_id, task.task_last);
};

void UserApi::processRspQryTodayTayoutDetails(Task task)
{
	PyLock lock;
	CFocusFtdcTodayTayoutDetailsField task_data = any_cast<CFocusFtdcTodayTayoutDetailsField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["InvestorID"] = task_data.InvestorID;
	data["UserID"] = GBK_TO_UTF8(task_data.UserID);
	data["occurTime"] = task_data.occurTime;
	data["bankId"] = task_data.bankId;
	data["bankAcctId"] = task_data.bankAcctId;
	data["contractNum"] = task_data.contractNum;
	data["acctName"] = GBK_TO_UTF8(task_data.acctName);
	data["TodayInOut"] = task_data.TodayInOut;
	data["memo"] = GBK_TO_UTF8(task_data.memo);
	data["briefId"] = task_data.briefId;
	data["postAmt"] = task_data.postAmt;
	data["custId"] = task_data.custId;
	data["undoFlagDesc"] = GBK_TO_UTF8(task_data.undoFlagDesc);

	CFocusFtdcRspInfoField task_error = any_cast<CFocusFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryTodayTayoutDetails(data, error, task.task_id, task.task_last);
};





///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void UserApi::createFtdcUserApi(string pszFlowPath)
{
	this->api = CFocusFtdcUserApi::CreateFtdcUserApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
};

void UserApi::release()
{
	this->api->Release();
};

void UserApi::init(int nPrivatePort)
{
	this->api->Init(nPrivatePort);
};

int UserApi::join()
{
	int i = this->api->Join();
	return i;
};

int UserApi::exit()
{
	//该函数在原生API里没有，用于安全退出API用，原生的join似乎不太稳定
	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

string UserApi::getTradingDay()
{
	string day = this->api->GetTradingDay();
	return day;
};

void UserApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};

void UserApi::subscribePrivateTopic(int nType)
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

void UserApi::subscribePublicTopic(int nType)
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

int UserApi::reqUserLogin(dict req, int nRequestID)
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

int UserApi::reqUserLogout(dict req, int nRequestID)
{
	CFocusFtdcReqUserLogoutField myreq = CFocusFtdcReqUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int UserApi::reqUserPasswordUpdate(dict req, int nRequestID)
{
	CFocusFtdcUserPasswordUpdateField myreq = CFocusFtdcUserPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "OldPassword", myreq.OldPassword);
	getStr(req, "NewPassword", myreq.NewPassword);
	int i = this->api->ReqUserPasswordUpdate(&myreq, nRequestID);
	return i;
};

int UserApi::reqForceUserExit(dict req, int nRequestID)
{
	CFocusFtdcForceUserExitField myreq = CFocusFtdcForceUserExitField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	int i = this->api->ReqForceUserExit(&myreq, nRequestID);
	return i;
};

int UserApi::reqForceUserLogout(dict req, int nRequestID)
{
	CFocusFtdcForceUserExitField myreq = CFocusFtdcForceUserExitField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	int i = this->api->ReqForceUserLogout(&myreq, nRequestID);
	return i;
};

int UserApi::reqDumpMemDB(dict req, int nRequestID)
{
	CFocusFtdcMemDBField myreq = CFocusFtdcMemDBField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "MemTableName", myreq.MemTableName);
	int i = this->api->ReqDumpMemDB(&myreq, nRequestID);
	return i;
};

int UserApi::reqOrderInsert(dict req, int nRequestID)
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

int UserApi::reqOrderAction(dict req, int nRequestID)
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

int UserApi::reqAccountDeposit(dict req, int nRequestID)
{
	CFocusFtdcReqAccountDepositField myreq = CFocusFtdcReqAccountDepositField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "AccountSeqNo", myreq.AccountSeqNo);
	getStr(req, "AccountID", myreq.AccountID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getDouble(req, "Amount", &myreq.Amount);
	getChar(req, "AmountDirection", &myreq.AmountDirection);
	getStr(req, "Date", myreq.Date);
	getStr(req, "Time", myreq.Time);
	getStr(req, "Note", myreq.Note);
	getInt(req, "isSuccess", &myreq.isSuccess);
	getStr(req, "UserID", myreq.UserID);
	int i = this->api->ReqAccountDeposit(&myreq, nRequestID);
	return i;
};

int UserApi::reqInvestorRight(dict req, int nRequestID)
{
	CFocusFtdcInvestorRightField myreq = CFocusFtdcInvestorRightField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InvestorID", myreq.InvestorID);
	getChar(req, "PositionType", &myreq.PositionType);
	getChar(req, "SelfTradeAvoidType", &myreq.SelfTradeAvoidType);
	getChar(req, "TradingRight", &myreq.TradingRight);
	getInt(req, "CheckAccount", &myreq.CheckAccount);
	getInt(req, "CheckPosition", &myreq.CheckPosition);
	getInt(req, "OrderWarning", &myreq.OrderWarning);
	getInt(req, "QryUpAccPosi", &myreq.QryUpAccPosi);
	getChar(req, "DistributeType", &myreq.DistributeType);
	int i = this->api->ReqInvestorRight(&myreq, nRequestID);
	return i;
};

int UserApi::reqTBCommand(dict req, int nRequestID)
{
	CFocusFtdcTBCommandField myreq = CFocusFtdcTBCommandField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "CommandNo", &myreq.CommandNo);
	getStr(req, "CommandDate", myreq.CommandDate);
	getStr(req, "CommandTime", myreq.CommandTime);
	getStr(req, "CommandType", myreq.CommandType);
	getStr(req, "FieldName", myreq.FieldName);
	getStr(req, "FieldContent", myreq.FieldContent);
	int i = this->api->ReqTBCommand(&myreq, nRequestID);
	return i;
};

int UserApi::reqPingPong(dict req, int nRequestID)
{
	CFocusFtdcPingPongField myreq = CFocusFtdcPingPongField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getInt(req, "SequenceNo", &myreq.SequenceNo);
	getStr(req, "UserCustom", myreq.UserCustom);
	int i = this->api->ReqPingPong(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetAdviceRunMode(dict req, int nRequestID)
{
	CFocusFtdcAdviceRunModeField myreq = CFocusFtdcAdviceRunModeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "RunMode", &myreq.RunMode);
	int i = this->api->ReqSetAdviceRunMode(&myreq, nRequestID);
	return i;
};

int UserApi::reqSubMarketData(dict req, int nRequestID)
{
	CFocusFtdcSpecificInstrumentField myreq = CFocusFtdcSpecificInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSubMarketData(&myreq, nRequestID);
	return i;
};

int UserApi::reqUnSubMarketData(dict req, int nRequestID)
{
	CFocusFtdcSpecificInstrumentField myreq = CFocusFtdcSpecificInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqUnSubMarketData(&myreq, nRequestID);
	return i;
};

int UserApi::reqTopicSearch(dict req, int nRequestID)
{
	CFocusFtdcTopicSearchField myreq = CFocusFtdcTopicSearchField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "TopicID", &myreq.TopicID);
	int i = this->api->ReqTopicSearch(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryOrder(dict req, int nRequestID)
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

int UserApi::reqQryTrade(dict req, int nRequestID)
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

int UserApi::reqQryUserInvestor(dict req, int nRequestID)
{
	CFocusFtdcQryUserInvestorField myreq = CFocusFtdcQryUserInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	int i = this->api->ReqQryUserInvestor(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInvestorAccount(dict req, int nRequestID)
{
	CFocusFtdcQryInvestorAccountField myreq = CFocusFtdcQryInvestorAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestorAccount(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInstrument(dict req, int nRequestID)
{
	CFocusFtdcQryInstrumentField myreq = CFocusFtdcQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrument(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryExchange(dict req, int nRequestID)
{
	CFocusFtdcQryExchangeField myreq = CFocusFtdcQryExchangeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQryExchange(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInvestorPosition(dict req, int nRequestID)
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

int UserApi::reqSubscribeTopic(dict req, int nRequestID)
{
	CFocusFtdcDisseminationField myreq = CFocusFtdcDisseminationField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "SequenceSeries", &myreq.SequenceSeries);
	getInt(req, "SequenceNo", &myreq.SequenceNo);
	int i = this->api->ReqSubscribeTopic(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryTopic(dict req, int nRequestID)
{
	CFocusFtdcDisseminationField myreq = CFocusFtdcDisseminationField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "SequenceSeries", &myreq.SequenceSeries);
	getInt(req, "SequenceNo", &myreq.SequenceNo);
	int i = this->api->ReqQryTopic(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryUser(dict req, int nRequestID)
{
	CFocusFtdcQryUserField myreq = CFocusFtdcQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StartUserID", myreq.StartUserID);
	getStr(req, "EndUserID", myreq.EndUserID);
	int i = this->api->ReqQryUser(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInvestorFee(dict req, int nRequestID)
{
	CFocusFtdcQryInvestorFeeField myreq = CFocusFtdcQryInvestorFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorFee(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInvestorMargin(dict req, int nRequestID)
{
	CFocusFtdcQryInvestorMarginField myreq = CFocusFtdcQryInvestorMarginField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	int i = this->api->ReqQryInvestorMargin(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInvestor(dict req, int nRequestID)
{
	CFocusFtdcQryInvestorField myreq = CFocusFtdcQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestor(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAccountRisk(dict req, int nRequestID)
{
	CFocusFtdcQryAccountRiskField myreq = CFocusFtdcQryAccountRiskField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryAccountRisk(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryUserSession(dict req, int nRequestID)
{
	CFocusFtdcQryUserSessionField myreq = CFocusFtdcQryUserSessionField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StartUserID", myreq.StartUserID);
	getStr(req, "EndUserID", myreq.EndUserID);
	int i = this->api->ReqQryUserSession(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryMarketData(dict req, int nRequestID)
{
	CFocusFtdcQryMarketDataField myreq = CFocusFtdcQryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryMarketData(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInvestorRelation(dict req, int nRequestID)
{
	CFocusFtdcQryInvestorRelationField myreq = CFocusFtdcQryInvestorRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestorRelation(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryProduct(dict req, int nRequestID)
{
	CFocusFtdcQryProductField myreq = CFocusFtdcQryProductField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryProduct(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAdviceTrader(dict req, int nRequestID)
{
	CFocusFtdcQryAdviceTraderField myreq = CFocusFtdcQryAdviceTraderField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "LogBrokerID", myreq.LogBrokerID);
	getStr(req, "LogUserID", myreq.LogUserID);
	int i = this->api->ReqQryAdviceTrader(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryMaxVolume(dict req, int nRequestID)
{
	CFocusFtdcQryMaxVolumeField myreq = CFocusFtdcQryMaxVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	int i = this->api->ReqQryMaxVolume(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryCmbPositionDetail(dict req, int nRequestID)
{
	CFocusFtdcQryCmbPositionDetailField myreq = CFocusFtdcQryCmbPositionDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryCmbPositionDetail(&myreq, nRequestID);
	return i;
};

int UserApi::reqQrySettlementInfo(dict req, int nRequestID)
{
	CFocusFtdcQrySettlementInfoField myreq = CFocusFtdcQrySettlementInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "TradingDay", myreq.TradingDay);
	int i = this->api->ReqQrySettlementInfo(&myreq, nRequestID);
	return i;
};

int UserApi::reqSubInstrument(dict req, int nRequestID)
{
	CFocusFtdcSubSpecificInstrumentField myreq = CFocusFtdcSubSpecificInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSubInstrument(&myreq, nRequestID);
	return i;
};

int UserApi::reqUnSubInstrument(dict req, int nRequestID)
{
	CFocusFtdcSubSpecificInstrumentField myreq = CFocusFtdcSubSpecificInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqUnSubInstrument(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryResultPage(dict req, int nRequestID)
{
	CFocusFtdcQryResultPageField myreq = CFocusFtdcQryResultPageField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "ResultID", &myreq.ResultID);
	getInt(req, "Count", &myreq.Count);
	getInt(req, "Pages", &myreq.Pages);
	getInt(req, "Remain", &myreq.Remain);
	int i = this->api->ReqQryResultPage(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryOrderPage(dict req, int nRequestID)
{
	CFocusFtdcQryOrderField myreq = CFocusFtdcQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "OrderSysID", myreq.OrderSysID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOrderPage(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryTradePage(dict req, int nRequestID)
{
	CFocusFtdcQryTradeField myreq = CFocusFtdcQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "TradeID", myreq.TradeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryTradePage(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInvestorPositionPage(dict req, int nRequestID)
{
	CFocusFtdcQryInvestorPositionField myreq = CFocusFtdcQryInvestorPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorPositionPage(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInvestorPositionDetail(dict req, int nRequestID)
{
	CFocusFtdcQryPositionDetailField myreq = CFocusFtdcQryPositionDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorPositionDetail(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetPricingParam(dict req, int nRequestID)
{
	CFocusFtdcPricingParamField myreq = CFocusFtdcPricingParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "UnderlyingId", myreq.UnderlyingId);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getChar(req, "PriceLevel1", &myreq.PriceLevel1);
	getChar(req, "PriceLevel2", &myreq.PriceLevel2);
	getChar(req, "PriceLevel3", &myreq.PriceLevel3);
	getChar(req, "CalcDayType", &myreq.CalcDayType);
	getInt(req, "YearTotalDay", &myreq.YearTotalDay);
	getChar(req, "CalcTimeType", &myreq.CalcTimeType);
	getDouble(req, "RiskFreeRate", &myreq.RiskFreeRate);
	getDouble(req, "Dividend", &myreq.Dividend);
	getChar(req, "PricingEngine", &myreq.PricingEngine);
	getChar(req, "ExerciseType", &myreq.ExerciseType);
	getDouble(req, "VolTolerance", &myreq.VolTolerance);
	getChar(req, "VolType", &myreq.VolType);
	int i = this->api->ReqSetPricingParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetOptionTheoryVol(dict req, int nRequestID)
{
	CFocusFtdcOptionTheoryVolField myreq = CFocusFtdcOptionTheoryVolField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getDouble(req, "TheoryVol", &myreq.TheoryVol);
	int i = this->api->ReqSetOptionTheoryVol(&myreq, nRequestID);
	return i;
};

int UserApi::reqCalcOneOption(dict req, int nRequestID)
{
	CFocusFtdcBasePricingParamField myreq = CFocusFtdcBasePricingParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "CalculateTarget", &myreq.CalculateTarget);
	getChar(req, "ExerciseType", &myreq.ExerciseType);
	getChar(req, "OptionsType", &myreq.OptionsType);
	getDouble(req, "UnderlyingPrice", &myreq.UnderlyingPrice);
	getDouble(req, "StrikePrice", &myreq.StrikePrice);
	getDouble(req, "RiskFreeRate", &myreq.RiskFreeRate);
	getDouble(req, "Dividend", &myreq.Dividend);
	getDouble(req, "RemainDay", &myreq.RemainDay);
	getStr(req, "TradingDate", myreq.TradingDate);
	getStr(req, "ExpireDate", myreq.ExpireDate);
	getDouble(req, "Vol", &myreq.Vol);
	getChar(req, "PricingModel", &myreq.PricingModel);
	getDouble(req, "OptionPrice", &myreq.OptionPrice);
	getInt(req, "ResetFrequency", &myreq.ResetFrequency);
	getDouble(req, "Delta", &myreq.Delta);
	getDouble(req, "Gamma", &myreq.Gamma);
	getDouble(req, "Vega", &myreq.Vega);
	getDouble(req, "Theta", &myreq.Theta);
	getDouble(req, "Rho", &myreq.Rho);
	getDouble(req, "Vanna", &myreq.Vanna);
	getDouble(req, "Volga", &myreq.Volga);
	int i = this->api->ReqCalcOneOption(&myreq, nRequestID);
	return i;
};

int UserApi::reqCalcBarrierOption(dict req, int nRequestID)
{
	CFocusFtdcDoubleBarrierPricingParamField myreq = CFocusFtdcDoubleBarrierPricingParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "CalculateTarget", &myreq.CalculateTarget);
	getChar(req, "ExerciseType", &myreq.ExerciseType);
	getChar(req, "OptionsType", &myreq.OptionsType);
	getDouble(req, "UnderlyingPrice", &myreq.UnderlyingPrice);
	getDouble(req, "StrikePrice", &myreq.StrikePrice);
	getDouble(req, "RiskFreeRate", &myreq.RiskFreeRate);
	getDouble(req, "Dividend", &myreq.Dividend);
	getDouble(req, "RemainDay", &myreq.RemainDay);
	getStr(req, "TradingDate", myreq.TradingDate);
	getStr(req, "ExpireDate", myreq.ExpireDate);
	getDouble(req, "Vol", &myreq.Vol);
	getChar(req, "PricingModel", &myreq.PricingModel);
	getDouble(req, "OptionPrice", &myreq.OptionPrice);
	getInt(req, "ResetFrequency", &myreq.ResetFrequency);
	getDouble(req, "Delta", &myreq.Delta);
	getDouble(req, "Gamma", &myreq.Gamma);
	getDouble(req, "Vega", &myreq.Vega);
	getDouble(req, "Theta", &myreq.Theta);
	getDouble(req, "Rho", &myreq.Rho);
	getDouble(req, "Vanna", &myreq.Vanna);
	getDouble(req, "Volga", &myreq.Volga);
	getChar(req, "BarrierType", &myreq.BarrierType);
	getDouble(req, "LowerBarrierRate", &myreq.LowerBarrierRate);
	getDouble(req, "UpperBarrierRate", &myreq.UpperBarrierRate);
	int i = this->api->ReqCalcBarrierOption(&myreq, nRequestID);
	return i;
};

int UserApi::reqMarketDataTest(dict req, int nRequestID)
{
	CFocusFtdcDepthMarketDataField myreq = CFocusFtdcDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "TradingDay", myreq.TradingDay);
	getDouble(req, "PreSettlementPrice", &myreq.PreSettlementPrice);
	getDouble(req, "PreClosePrice", &myreq.PreClosePrice);
	getDouble(req, "PreOpenInterest", &myreq.PreOpenInterest);
	getDouble(req, "PreDelta", &myreq.PreDelta);
	getChar(req, "StkOrderStatus", &myreq.StkOrderStatus);
	getDouble(req, "OpenPrice", &myreq.OpenPrice);
	getDouble(req, "HighestPrice", &myreq.HighestPrice);
	getDouble(req, "LowestPrice", &myreq.LowestPrice);
	getDouble(req, "ClosePrice", &myreq.ClosePrice);
	getDouble(req, "UpperLimitPrice", &myreq.UpperLimitPrice);
	getDouble(req, "LowerLimitPrice", &myreq.LowerLimitPrice);
	getDouble(req, "SettlementPrice", &myreq.SettlementPrice);
	getDouble(req, "CurrDelta", &myreq.CurrDelta);
	getDouble(req, "LastPrice", &myreq.LastPrice);
	getInt(req, "Volume", &myreq.Volume);
	getDouble(req, "Turnover", &myreq.Turnover);
	getDouble(req, "OpenInterest", &myreq.OpenInterest);
	getDouble(req, "BidPrice1", &myreq.BidPrice1);
	getInt(req, "BidVolume1", &myreq.BidVolume1);
	getDouble(req, "AskPrice1", &myreq.AskPrice1);
	getInt(req, "AskVolume1", &myreq.AskVolume1);
	getDouble(req, "BidPrice2", &myreq.BidPrice2);
	getInt(req, "BidVolume2", &myreq.BidVolume2);
	getDouble(req, "BidPrice3", &myreq.BidPrice3);
	getInt(req, "BidVolume3", &myreq.BidVolume3);
	getDouble(req, "AskPrice2", &myreq.AskPrice2);
	getInt(req, "AskVolume2", &myreq.AskVolume2);
	getDouble(req, "AskPrice3", &myreq.AskPrice3);
	getInt(req, "AskVolume3", &myreq.AskVolume3);
	getDouble(req, "BidPrice4", &myreq.BidPrice4);
	getInt(req, "BidVolume4", &myreq.BidVolume4);
	getDouble(req, "BidPrice5", &myreq.BidPrice5);
	getInt(req, "BidVolume5", &myreq.BidVolume5);
	getDouble(req, "AskPrice4", &myreq.AskPrice4);
	getInt(req, "AskVolume4", &myreq.AskVolume4);
	getDouble(req, "AskPrice5", &myreq.AskPrice5);
	getInt(req, "AskVolume5", &myreq.AskVolume5);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "UpdateTime", myreq.UpdateTime);
	getInt(req, "UpdateMillisec", &myreq.UpdateMillisec);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getInt(req, "VolumeAskLot", &myreq.VolumeAskLot);
	getInt(req, "VolumeBidLot", &myreq.VolumeBidLot);
	int i = this->api->ReqMarketDataTest(&myreq, nRequestID);
	return i;
};

int UserApi::reqVolatilityFitting(dict req, int nRequestID)
{
	CFocusFtdcVolatilityFittingField myreq = CFocusFtdcVolatilityFittingField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	getDouble(req, "RemainDay", &myreq.RemainDay);
	getDouble(req, "StrikePrice", &myreq.StrikePrice);
	getDouble(req, "Vol", &myreq.Vol);
	int i = this->api->ReqVolatilityFitting(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryWingModelParam(dict req, int nRequestID)
{
	CFocusFtdcQryWingModelParamField myreq = CFocusFtdcQryWingModelParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getChar(req, "WingParamType", &myreq.WingParamType);
	getChar(req, "FitModel", &myreq.FitModel);
	int i = this->api->ReqQryWingModelParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetWingModelParam(dict req, int nRequestID)
{
	CFocusFtdcWingModelParamField myreq = CFocusFtdcWingModelParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getChar(req, "FitModel", &myreq.FitModel);
	getChar(req, "WingParamType", &myreq.WingParamType);
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "InsertTime", myreq.InsertTime);
	getDouble(req, "Atm", &myreq.Atm);
	getDouble(req, "Days", &myreq.Days);
	getDouble(req, "ref", &myreq.ref);
	getDouble(req, "ssr", &myreq.ssr);
	getDouble(req, "vcr", &myreq.vcr);
	getDouble(req, "scr", &myreq.scr);
	getDouble(req, "cc", &myreq.cc);
	getDouble(req, "uc", &myreq.uc);
	getDouble(req, "usm", &myreq.usm);
	getDouble(req, "pc", &myreq.pc);
	getDouble(req, "dc", &myreq.dc);
	getDouble(req, "dsm", &myreq.dsm);
	getDouble(req, "vr", &myreq.vr);
	getDouble(req, "sr", &myreq.sr);
	getDouble(req, "vc", &myreq.vc);
	getDouble(req, "sc", &myreq.sc);
	int i = this->api->ReqSetWingModelParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryMarkerStrategySet(dict req, int nRequestID)
{
	CFocusFtdcQryUserField myreq = CFocusFtdcQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StartUserID", myreq.StartUserID);
	getStr(req, "EndUserID", myreq.EndUserID);
	int i = this->api->ReqQryMarkerStrategySet(&myreq, nRequestID);
	return i;
};

int UserApi::reqUpMarkerStrategySet(dict req, int nRequestID)
{
	CFocusFtdcMarkerStrategyField myreq = CFocusFtdcMarkerStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getChar(req, "AutoOffer", &myreq.AutoOffer);
	getChar(req, "AutoRespAsking", &myreq.AutoRespAsking);
	getInt(req, "BidAmount", &myreq.BidAmount);
	getInt(req, "AskAmount", &myreq.AskAmount);
	getInt(req, "ForQuoteBidAmount", &myreq.ForQuoteBidAmount);
	getInt(req, "ForQuoteAskAmount", &myreq.ForQuoteAskAmount);
	getInt(req, "BidMax", &myreq.BidMax);
	getInt(req, "AskMax", &myreq.AskMax);
	getChar(req, "SpreadType", &myreq.SpreadType);
	getDouble(req, "QuotePriceWidth", &myreq.QuotePriceWidth);
	getDouble(req, "QuoteWidthRatio", &myreq.QuoteWidthRatio);
	getDouble(req, "ForQuotePriceWidth", &myreq.ForQuotePriceWidth);
	getDouble(req, "ForQuoteWidthRatio", &myreq.ForQuoteWidthRatio);
	getChar(req, "IsActive", &myreq.IsActive);
	getStr(req, "Remark", myreq.Remark);
	getChar(req, "OfferType", &myreq.OfferType);
	getInt(req, "TOL_TICK", &myreq.TOL_TICK);
	getChar(req, "ForQuoteOfferType", &myreq.ForQuoteOfferType);
	getChar(req, "QuoteWidthType", &myreq.QuoteWidthType);
	getChar(req, "ForQuoteWidthType", &myreq.ForQuoteWidthType);
	getChar(req, "InstrumentOneSide", &myreq.InstrumentOneSide);
	getChar(req, "UnderlyingOneSide", &myreq.UnderlyingOneSide);
	getDouble(req, "MinPrice", &myreq.MinPrice);
	getStr(req, "QuoteStepID", myreq.QuoteStepID);
	getStr(req, "QuoteDeltaStepID", myreq.QuoteDeltaStepID);
	getStr(req, "QuoteVegaStepID", myreq.QuoteVegaStepID);
	getStr(req, "ForQuoteStepID", myreq.ForQuoteStepID);
	getStr(req, "ForQuoteDeltaStepID", myreq.ForQuoteDeltaStepID);
	getStr(req, "ForQuoteVegaStepID", myreq.ForQuoteVegaStepID);
	int i = this->api->ReqUpMarkerStrategySet(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryUserSwitch(dict req, int nRequestID)
{
	CFocusFtdcQryUserField myreq = CFocusFtdcQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StartUserID", myreq.StartUserID);
	getStr(req, "EndUserID", myreq.EndUserID);
	int i = this->api->ReqQryUserSwitch(&myreq, nRequestID);
	return i;
};

int UserApi::reqUserSwitch(dict req, int nRequestID)
{
	CFocusFtdcUserSwitchField myreq = CFocusFtdcUserSwitchField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "WholeSwitch", &myreq.WholeSwitch);
	getChar(req, "WholeOffer", &myreq.WholeOffer);
	getChar(req, "WholeRespAsking", &myreq.WholeRespAsking);
	getChar(req, "WholeHedge", &myreq.WholeHedge);
	int i = this->api->ReqUserSwitch(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryMarkerHedge(dict req, int nRequestID)
{
	CFocusFtdcQryUserField myreq = CFocusFtdcQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StartUserID", myreq.StartUserID);
	getStr(req, "EndUserID", myreq.EndUserID);
	int i = this->api->ReqQryMarkerHedge(&myreq, nRequestID);
	return i;
};

int UserApi::reqUpMarkerHedge(dict req, int nRequestID)
{
	CFocusFtdcMarkerHedgeField myreq = CFocusFtdcMarkerHedgeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UnderlyingId", myreq.UnderlyingId);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "AutoHedge", &myreq.AutoHedge);
	getChar(req, "HedgePriceType", &myreq.HedgePriceType);
	getChar(req, "HdegeType", &myreq.HdegeType);
	getInt(req, "HedgePeriod", &myreq.HedgePeriod);
	getDouble(req, "DeltaMax", &myreq.DeltaMax);
	getDouble(req, "DelatMin", &myreq.DelatMin);
	getStr(req, "LastHedgeTime", myreq.LastHedgeTime);
	getInt(req, "OrderPriceSlip", &myreq.OrderPriceSlip);
	int i = this->api->ReqUpMarkerHedge(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryFittingParam(dict req, int nRequestID)
{
	CFocusFtdcQryFittingParamField myreq = CFocusFtdcQryFittingParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	int i = this->api->ReqQryFittingParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetFittingParam(dict req, int nRequestID)
{
	CFocusFtdcFittingParamField myreq = CFocusFtdcFittingParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getChar(req, "FitModel", &myreq.FitModel);
	getChar(req, "CallBidFlag", &myreq.CallBidFlag);
	getChar(req, "CallAskFlag", &myreq.CallAskFlag);
	getChar(req, "PutBidFlag", &myreq.PutBidFlag);
	getChar(req, "PutAskFlag", &myreq.PutAskFlag);
	getChar(req, "CallMidFlag", &myreq.CallMidFlag);
	getChar(req, "PutMidFlag", &myreq.PutMidFlag);
	getChar(req, "OTMFlag", &myreq.OTMFlag);
	getChar(req, "AutoRemoveOutlier", &myreq.AutoRemoveOutlier);
	getDouble(req, "ValidIntervalMax", &myreq.ValidIntervalMax);
	getDouble(req, "ValidIntervalMin", &myreq.ValidIntervalMin);
	getChar(req, "AutoFit", &myreq.AutoFit);
	getInt(req, "AUTO_FIT_TIME", &myreq.AUTO_FIT_TIME);
	int i = this->api->ReqSetFittingParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryPricingParam(dict req, int nRequestID)
{
	CFocusFtdcQryPricingParamField myreq = CFocusFtdcQryPricingParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	int i = this->api->ReqQryPricingParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryOptionTheoryVol(dict req, int nRequestID)
{
	CFocusFtdcQryOptionTheoryVolField myreq = CFocusFtdcQryOptionTheoryVolField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionTheoryVol(&myreq, nRequestID);
	return i;
};

int UserApi::reqQuoteInsert(dict req, int nRequestID)
{
	CFocusFtdcInputQuoteField myreq = CFocusFtdcInputQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "AccountID", myreq.AccountID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "QuoteRef", myreq.QuoteRef);
	getStr(req, "QuoteLocalID", myreq.QuoteLocalID);
	getStr(req, "AskOrderRef", myreq.AskOrderRef);
	getStr(req, "BidOrderRef", myreq.BidOrderRef);
	getStr(req, "QuoteSysID", myreq.QuoteSysID);
	getStr(req, "ForQuoteSysID", myreq.ForQuoteSysID);
	getInt(req, "BidVolume", &myreq.BidVolume);
	getInt(req, "AskVolume", &myreq.AskVolume);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "BusinessUnit", myreq.BusinessUnit);
	getChar(req, "BidOffsetFlag", &myreq.BidOffsetFlag);
	getChar(req, "BidHedgeFlag", &myreq.BidHedgeFlag);
	getDouble(req, "BidPrice", &myreq.BidPrice);
	getChar(req, "AskOffsetFlag", &myreq.AskOffsetFlag);
	getChar(req, "AskHedgeFlag", &myreq.AskHedgeFlag);
	getDouble(req, "AskPrice", &myreq.AskPrice);
	getStr(req, "UserCustom", myreq.UserCustom);
	getChar(req, "IsAuto", &myreq.IsAuto);
	getInt(req, "APIID", &myreq.APIID);
	getStr(req, "Remark", myreq.Remark);
	int i = this->api->ReqQuoteInsert(&myreq, nRequestID);
	return i;
};

int UserApi::reqQuoteAction(dict req, int nRequestID)
{
	CFocusFtdcQuoteActionField myreq = CFocusFtdcQuoteActionField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "AccountID", myreq.AccountID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "QuoteSysID", myreq.QuoteSysID);
	getStr(req, "QuoteLocalID", myreq.QuoteLocalID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getStr(req, "ParticipantID", myreq.ParticipantID);
	getStr(req, "ClientID", myreq.ClientID);
	getStr(req, "ActionLocalID", myreq.ActionLocalID);
	getStr(req, "BusinessUnit", myreq.BusinessUnit);
	getStr(req, "UserCustom", myreq.UserCustom);
	getInt(req, "APIID", &myreq.APIID);
	int i = this->api->ReqQuoteAction(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryQuote(dict req, int nRequestID)
{
	CFocusFtdcQryQuoteField myreq = CFocusFtdcQryQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "QuoteSysID", myreq.QuoteSysID);
	getStr(req, "ClientID", myreq.ClientID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "UserID", myreq.UserID);
	int i = this->api->ReqQryQuote(&myreq, nRequestID);
	return i;
};

int UserApi::reqForQuote(dict req, int nRequestID)
{
	CFocusFtdcInputReqForQuoteField myreq = CFocusFtdcInputReqForQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "AccountID", myreq.AccountID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ReqForQuoteID", myreq.ReqForQuoteID);
	getStr(req, "ClientID", myreq.ClientID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "ReqForQuoteTime", myreq.ReqForQuoteTime);
	getStr(req, "ForQuoteLocalID", myreq.ForQuoteLocalID);
	int i = this->api->ReqForQuote(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryOrderInsertFailed(dict req, int nRequestID)
{
	CFocusFtdcQryOrderInsertFailedField myreq = CFocusFtdcQryOrderInsertFailedField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "OrderSysID", myreq.OrderSysID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "LogBrokerID", myreq.LogBrokerID);
	getStr(req, "LogUserID", myreq.LogUserID);
	int i = this->api->ReqQryOrderInsertFailed(&myreq, nRequestID);
	return i;
};

int UserApi::reqCleanQuoteThresHold(dict req, int nRequestID)
{
	CFocusFtdcQuoteTotalTradePriceField myreq = CFocusFtdcQuoteTotalTradePriceField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getInt(req, "AskTradeVolume", &myreq.AskTradeVolume);
	getInt(req, "BidTradeVolume", &myreq.BidTradeVolume);
	getDouble(req, "BidQuotePrice", &myreq.BidQuotePrice);
	getInt(req, "BidQuoteAmount", &myreq.BidQuoteAmount);
	getDouble(req, "AskQuotePrice", &myreq.AskQuotePrice);
	getInt(req, "AskQuoteAmount", &myreq.AskQuoteAmount);
	getInt(req, "ForQuoteSendAmount", &myreq.ForQuoteSendAmount);
	getInt(req, "ForQuoteTotalAmount", &myreq.ForQuoteTotalAmount);
	getDouble(req, "BidForQuotePrice", &myreq.BidForQuotePrice);
	getInt(req, "BidForQuoteAmount", &myreq.BidForQuoteAmount);
	getDouble(req, "AskForQuotePrice", &myreq.AskForQuotePrice);
	getInt(req, "AskForQuoteAmount", &myreq.AskForQuoteAmount);
	getChar(req, "FowardDirection", &myreq.FowardDirection);
	int i = this->api->ReqCleanQuoteThresHold(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetPriceSpread(dict req, int nRequestID)
{
	CFocusFtdcPriceSpreadField myreq = CFocusFtdcPriceSpreadField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getDouble(req, "Spread", &myreq.Spread);
	getStr(req, "SpreadInstrumentId", myreq.SpreadInstrumentId);
	getChar(req, "PriceSpreadType", &myreq.PriceSpreadType);
	int i = this->api->ReqSetPriceSpread(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryPriceSpread(dict req, int nRequestID)
{
	CFocusFtdcQryPriceSpreadField myreq = CFocusFtdcQryPriceSpreadField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	int i = this->api->ReqQryPriceSpread(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelPricingParam(dict req, int nRequestID)
{
	CFocusFtdcPricingParamField myreq = CFocusFtdcPricingParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "UnderlyingId", myreq.UnderlyingId);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getChar(req, "PriceLevel1", &myreq.PriceLevel1);
	getChar(req, "PriceLevel2", &myreq.PriceLevel2);
	getChar(req, "PriceLevel3", &myreq.PriceLevel3);
	getChar(req, "CalcDayType", &myreq.CalcDayType);
	getInt(req, "YearTotalDay", &myreq.YearTotalDay);
	getChar(req, "CalcTimeType", &myreq.CalcTimeType);
	getDouble(req, "RiskFreeRate", &myreq.RiskFreeRate);
	getDouble(req, "Dividend", &myreq.Dividend);
	getChar(req, "PricingEngine", &myreq.PricingEngine);
	getChar(req, "ExerciseType", &myreq.ExerciseType);
	getDouble(req, "VolTolerance", &myreq.VolTolerance);
	getChar(req, "VolType", &myreq.VolType);
	int i = this->api->ReqDelPricingParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelMarkerStrategySet(dict req, int nRequestID)
{
	CFocusFtdcMarkerStrategyField myreq = CFocusFtdcMarkerStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getChar(req, "AutoOffer", &myreq.AutoOffer);
	getChar(req, "AutoRespAsking", &myreq.AutoRespAsking);
	getInt(req, "BidAmount", &myreq.BidAmount);
	getInt(req, "AskAmount", &myreq.AskAmount);
	getInt(req, "ForQuoteBidAmount", &myreq.ForQuoteBidAmount);
	getInt(req, "ForQuoteAskAmount", &myreq.ForQuoteAskAmount);
	getInt(req, "BidMax", &myreq.BidMax);
	getInt(req, "AskMax", &myreq.AskMax);
	getChar(req, "SpreadType", &myreq.SpreadType);
	getDouble(req, "QuotePriceWidth", &myreq.QuotePriceWidth);
	getDouble(req, "QuoteWidthRatio", &myreq.QuoteWidthRatio);
	getDouble(req, "ForQuotePriceWidth", &myreq.ForQuotePriceWidth);
	getDouble(req, "ForQuoteWidthRatio", &myreq.ForQuoteWidthRatio);
	getChar(req, "IsActive", &myreq.IsActive);
	getStr(req, "Remark", myreq.Remark);
	getChar(req, "OfferType", &myreq.OfferType);
	getInt(req, "TOL_TICK", &myreq.TOL_TICK);
	getChar(req, "ForQuoteOfferType", &myreq.ForQuoteOfferType);
	getChar(req, "QuoteWidthType", &myreq.QuoteWidthType);
	getChar(req, "ForQuoteWidthType", &myreq.ForQuoteWidthType);
	getChar(req, "InstrumentOneSide", &myreq.InstrumentOneSide);
	getChar(req, "UnderlyingOneSide", &myreq.UnderlyingOneSide);
	getDouble(req, "MinPrice", &myreq.MinPrice);
	getStr(req, "QuoteStepID", myreq.QuoteStepID);
	getStr(req, "QuoteDeltaStepID", myreq.QuoteDeltaStepID);
	getStr(req, "QuoteVegaStepID", myreq.QuoteVegaStepID);
	getStr(req, "ForQuoteStepID", myreq.ForQuoteStepID);
	getStr(req, "ForQuoteDeltaStepID", myreq.ForQuoteDeltaStepID);
	getStr(req, "ForQuoteVegaStepID", myreq.ForQuoteVegaStepID);
	int i = this->api->ReqDelMarkerStrategySet(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetAlertParam(dict req, int nRequestID)
{
	CFocusFtdcAlertIndexSetParamField myreq = CFocusFtdcAlertIndexSetParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getStr(req, "InvestorID", myreq.InvestorID);
	getChar(req, "InvestorType", &myreq.InvestorType);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "AlertIndexCode", &myreq.AlertIndexCode);
	getDouble(req, "MAX_L1", &myreq.MAX_L1);
	getDouble(req, "MIN_L1", &myreq.MIN_L1);
	getDouble(req, "MAX_L2", &myreq.MAX_L2);
	getDouble(req, "MIN_L2", &myreq.MIN_L2);
	getInt(req, "TimeAvail", &myreq.TimeAvail);
	getChar(req, "AlertAction", &myreq.AlertAction);
	int i = this->api->ReqSetAlertParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAlertParam(dict req, int nRequestID)
{
	CFocusFtdcQryAlertIndexSetParamField myreq = CFocusFtdcQryAlertIndexSetParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "InvestorType", &myreq.InvestorType);
	getChar(req, "AlertIndexCode", &myreq.AlertIndexCode);
	int i = this->api->ReqQryAlertParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAlertData(dict req, int nRequestID)
{
	CFocusFtdcQryAlertIndexSetParamField myreq = CFocusFtdcQryAlertIndexSetParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "InvestorType", &myreq.InvestorType);
	getChar(req, "AlertIndexCode", &myreq.AlertIndexCode);
	int i = this->api->ReqQryAlertData(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelOptionTheoryVol(dict req, int nRequestID)
{
	CFocusFtdcOptionTheoryVolField myreq = CFocusFtdcOptionTheoryVolField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getDouble(req, "TheoryVol", &myreq.TheoryVol);
	int i = this->api->ReqDelOptionTheoryVol(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelMarkerHedge(dict req, int nRequestID)
{
	CFocusFtdcMarkerHedgeField myreq = CFocusFtdcMarkerHedgeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UnderlyingId", myreq.UnderlyingId);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "AutoHedge", &myreq.AutoHedge);
	getChar(req, "HedgePriceType", &myreq.HedgePriceType);
	getChar(req, "HdegeType", &myreq.HdegeType);
	getInt(req, "HedgePeriod", &myreq.HedgePeriod);
	getDouble(req, "DeltaMax", &myreq.DeltaMax);
	getDouble(req, "DelatMin", &myreq.DelatMin);
	getStr(req, "LastHedgeTime", myreq.LastHedgeTime);
	getInt(req, "OrderPriceSlip", &myreq.OrderPriceSlip);
	int i = this->api->ReqDelMarkerHedge(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetMarkerStep(dict req, int nRequestID)
{
	CFocusFtdcMarkerStepField myreq = CFocusFtdcMarkerStepField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StepID", myreq.StepID);
	getStr(req, "StepName", myreq.StepName);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "StepType", &myreq.StepType);
	getChar(req, "WidthType", &myreq.WidthType);
	getDouble(req, "LowPrice", &myreq.LowPrice);
	getDouble(req, "UpPrice", &myreq.UpPrice);
	getDouble(req, "StepValue1", &myreq.StepValue1);
	getDouble(req, "StepValue2", &myreq.StepValue2);
	getDouble(req, "StepValue3", &myreq.StepValue3);
	getInt(req, "StepValueKey", &myreq.StepValueKey);
	int i = this->api->ReqSetMarkerStep(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelMarkerStep(dict req, int nRequestID)
{
	CFocusFtdcMarkerStepField myreq = CFocusFtdcMarkerStepField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StepID", myreq.StepID);
	getStr(req, "StepName", myreq.StepName);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "StepType", &myreq.StepType);
	getChar(req, "WidthType", &myreq.WidthType);
	getDouble(req, "LowPrice", &myreq.LowPrice);
	getDouble(req, "UpPrice", &myreq.UpPrice);
	getDouble(req, "StepValue1", &myreq.StepValue1);
	getDouble(req, "StepValue2", &myreq.StepValue2);
	getDouble(req, "StepValue3", &myreq.StepValue3);
	getInt(req, "StepValueKey", &myreq.StepValueKey);
	int i = this->api->ReqDelMarkerStep(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelAlertParam(dict req, int nRequestID)
{
	CFocusFtdcAlertIndexSetParamField myreq = CFocusFtdcAlertIndexSetParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getStr(req, "InvestorID", myreq.InvestorID);
	getChar(req, "InvestorType", &myreq.InvestorType);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "AlertIndexCode", &myreq.AlertIndexCode);
	getDouble(req, "MAX_L1", &myreq.MAX_L1);
	getDouble(req, "MIN_L1", &myreq.MIN_L1);
	getDouble(req, "MAX_L2", &myreq.MAX_L2);
	getDouble(req, "MIN_L2", &myreq.MIN_L2);
	getInt(req, "TimeAvail", &myreq.TimeAvail);
	getChar(req, "AlertAction", &myreq.AlertAction);
	int i = this->api->ReqDelAlertParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetQuoteMove(dict req, int nRequestID)
{
	CFocusFtdcQuoteMoveField myreq = CFocusFtdcQuoteMoveField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getInt(req, "SumVolumeTime", &myreq.SumVolumeTime);
	getInt(req, "SumVolume", &myreq.SumVolume);
	getDouble(req, "Move", &myreq.Move);
	getInt(req, "KeepTime", &myreq.KeepTime);
	getChar(req, "TakeOut", &myreq.TakeOut);
	getChar(req, "IsActive", &myreq.IsActive);
	getChar(req, "NearStrikeMove", &myreq.NearStrikeMove);
	getDouble(req, "NearStrikeVolSpread", &myreq.NearStrikeVolSpread);
	getChar(req, "NearMoveType", &myreq.NearMoveType);
	getInt(req, "NearKeepTime", &myreq.NearKeepTime);
	int i = this->api->ReqSetQuoteMove(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelQuoteMove(dict req, int nRequestID)
{
	CFocusFtdcQuoteMoveField myreq = CFocusFtdcQuoteMoveField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "OptionSeriesId", myreq.OptionSeriesId);
	getInt(req, "SumVolumeTime", &myreq.SumVolumeTime);
	getInt(req, "SumVolume", &myreq.SumVolume);
	getDouble(req, "Move", &myreq.Move);
	getInt(req, "KeepTime", &myreq.KeepTime);
	getChar(req, "TakeOut", &myreq.TakeOut);
	getChar(req, "IsActive", &myreq.IsActive);
	getChar(req, "NearStrikeMove", &myreq.NearStrikeMove);
	getDouble(req, "NearStrikeVolSpread", &myreq.NearStrikeVolSpread);
	getChar(req, "NearMoveType", &myreq.NearMoveType);
	getInt(req, "NearKeepTime", &myreq.NearKeepTime);
	int i = this->api->ReqDelQuoteMove(&myreq, nRequestID);
	return i;
};

int UserApi::reqRebackQuote(dict req, int nRequestID)
{
	CFocusFtdcQuoteTotalTradePriceField myreq = CFocusFtdcQuoteTotalTradePriceField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getInt(req, "AskTradeVolume", &myreq.AskTradeVolume);
	getInt(req, "BidTradeVolume", &myreq.BidTradeVolume);
	getDouble(req, "BidQuotePrice", &myreq.BidQuotePrice);
	getInt(req, "BidQuoteAmount", &myreq.BidQuoteAmount);
	getDouble(req, "AskQuotePrice", &myreq.AskQuotePrice);
	getInt(req, "AskQuoteAmount", &myreq.AskQuoteAmount);
	getInt(req, "ForQuoteSendAmount", &myreq.ForQuoteSendAmount);
	getInt(req, "ForQuoteTotalAmount", &myreq.ForQuoteTotalAmount);
	getDouble(req, "BidForQuotePrice", &myreq.BidForQuotePrice);
	getInt(req, "BidForQuoteAmount", &myreq.BidForQuoteAmount);
	getDouble(req, "AskForQuotePrice", &myreq.AskForQuotePrice);
	getInt(req, "AskForQuoteAmount", &myreq.AskForQuoteAmount);
	getChar(req, "FowardDirection", &myreq.FowardDirection);
	int i = this->api->ReqRebackQuote(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryDepMarketData(dict req, int nRequestID)
{
	CFocusFtdcQryMarketDataField myreq = CFocusFtdcQryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryDepMarketData(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryQuoteMove(dict req, int nRequestID)
{
	CFocusFtdcQryUserField myreq = CFocusFtdcQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StartUserID", myreq.StartUserID);
	getStr(req, "EndUserID", myreq.EndUserID);
	int i = this->api->ReqQryQuoteMove(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryBaseMarkerStep(dict req, int nRequestID)
{
	CFocusFtdcQryUserField myreq = CFocusFtdcQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StartUserID", myreq.StartUserID);
	getStr(req, "EndUserID", myreq.EndUserID);
	int i = this->api->ReqQryBaseMarkerStep(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryMarkerStep(dict req, int nRequestID)
{
	CFocusFtdcBaseMarkerStepField myreq = CFocusFtdcBaseMarkerStepField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StepID", myreq.StepID);
	getStr(req, "StepName", myreq.StepName);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "StepType", &myreq.StepType);
	getChar(req, "WidthType", &myreq.WidthType);
	int i = this->api->ReqQryMarkerStep(&myreq, nRequestID);
	return i;
};

int UserApi::reqFocusStatus(dict req, int nRequestID)
{
	CFocusFtdcFocusStatusField myreq = CFocusFtdcFocusStatusField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "TradeStatus", &myreq.TradeStatus);
	int i = this->api->ReqFocusStatus(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetFutureMakerWholeSwitch(dict req, int nRequestID)
{
	CFocusFtdcFutureMakerWholeSwitchField myreq = CFocusFtdcFutureMakerWholeSwitchField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "WholeSwitch", &myreq.WholeSwitch);
	int i = this->api->ReqSetFutureMakerWholeSwitch(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetFutureMakerStrategy(dict req, int nRequestID)
{
	CFocusFtdcFutureMakerStrategyField myreq = CFocusFtdcFutureMakerStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "FirstSwitch", &myreq.FirstSwitch);
	getChar(req, "FirstFutureMakerFlag", &myreq.FirstFutureMakerFlag);
	getInt(req, "FirstToler", &myreq.FirstToler);
	getInt(req, "FirstAmount", &myreq.FirstAmount);
	getInt(req, "FirstWidth", &myreq.FirstWidth);
	getChar(req, "SecondSwitch", &myreq.SecondSwitch);
	getChar(req, "SecondFutureMakerFlag", &myreq.SecondFutureMakerFlag);
	getInt(req, "SecondToler", &myreq.SecondToler);
	getInt(req, "SecondAmount", &myreq.SecondAmount);
	getInt(req, "SecondWidth", &myreq.SecondWidth);
	getChar(req, "ThirdSwitch", &myreq.ThirdSwitch);
	getChar(req, "ThirdFutureMakerFlag", &myreq.ThirdFutureMakerFlag);
	getInt(req, "ThirdToler", &myreq.ThirdToler);
	getInt(req, "ThirdAmount", &myreq.ThirdAmount);
	getInt(req, "ThirdWidth", &myreq.ThirdWidth);
	getInt(req, "SumVolumeTime", &myreq.SumVolumeTime);
	getInt(req, "SumVolume", &myreq.SumVolume);
	getInt(req, "KeepTime", &myreq.KeepTime);
	getChar(req, "FutureOffsetFlag", &myreq.FutureOffsetFlag);
	int i = this->api->ReqSetFutureMakerStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetSlefHedgeStrategy(dict req, int nRequestID)
{
	CFocusFtdcSlefHedgeStrategyField myreq = CFocusFtdcSlefHedgeStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "SlefHedgeFutureMakerFlag", &myreq.SlefHedgeFutureMakerFlag);
	getInt(req, "SlefHedgeFutureMakerTick", &myreq.SlefHedgeFutureMakerTick);
	getInt(req, "SlefHedgeDeviate", &myreq.SlefHedgeDeviate);
	getInt(req, "SlefHedgeTimeAction", &myreq.SlefHedgeTimeAction);
	getInt(req, "SlefChaseTimes", &myreq.SlefChaseTimes);
	getInt(req, "MaxLossTick", &myreq.MaxLossTick);
	int i = this->api->ReqSetSlefHedgeStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetFutureHedgeStrategy(dict req, int nRequestID)
{
	CFocusFtdcFutureHedgeStrategyField myreq = CFocusFtdcFutureHedgeStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "HedgeExchangeID", myreq.HedgeExchangeID);
	getStr(req, "HedgeInstrumentID", myreq.HedgeInstrumentID);
	getStr(req, "HedgeInvestorID", myreq.HedgeInvestorID);
	getDouble(req, "Spread", &myreq.Spread);
	getChar(req, "HedgeFutureMakerFlag", &myreq.HedgeFutureMakerFlag);
	getInt(req, "HedgeFutureMakerTick", &myreq.HedgeFutureMakerTick);
	getInt(req, "HedgeDeviate", &myreq.HedgeDeviate);
	getInt(req, "HedgeTimeAction", &myreq.HedgeTimeAction);
	getInt(req, "HedgeChaseTimes", &myreq.HedgeChaseTimes);
	getChar(req, "HedgeOffsetFlag", &myreq.HedgeOffsetFlag);
	int i = this->api->ReqSetFutureHedgeStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetQuoteAdditionParm(dict req, int nRequestID)
{
	CFocusFtdcQuoteAdditionParmField myreq = CFocusFtdcQuoteAdditionParmField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getDouble(req, "QuotePriceWidth", &myreq.QuotePriceWidth);
	getDouble(req, "QuoteWidthRatio", &myreq.QuoteWidthRatio);
	getChar(req, "QuoteWidthType", &myreq.QuoteWidthType);
	getInt(req, "TOL_TICK", &myreq.TOL_TICK);
	getStr(req, "Remark", myreq.Remark);
	int i = this->api->ReqSetQuoteAdditionParm(&myreq, nRequestID);
	return i;
};

int UserApi::reqStopAllFutureMakerHedgeOffer(dict req, int nRequestID)
{
	CFocusFtdcStopAllFutureMakerHedgeOfferField myreq = CFocusFtdcStopAllFutureMakerHedgeOfferField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "HedgeOfferType", myreq.HedgeOfferType);
	int i = this->api->ReqStopAllFutureMakerHedgeOffer(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryFutureMakerStrategy(dict req, int nRequestID)
{
	CFocusFtdcFutureMakerIndexField myreq = CFocusFtdcFutureMakerIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryFutureMakerStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAllInnerHighStockStrategy(dict req, int nRequestID)
{
	CFocusFtdcQryWholeHighStockStrategyField myreq = CFocusFtdcQryWholeHighStockStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	int i = this->api->ReqQryAllInnerHighStockStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetHighStockStrategySwitch(dict req, int nRequestID)
{
	CFocusFtdcWholeHighStockStrategySwitchField myreq = CFocusFtdcWholeHighStockStrategySwitchField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getChar(req, "StockWholeSwitch", &myreq.StockWholeSwitch);
	int i = this->api->ReqSetHighStockStrategySwitch(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAllAPIHighStockStrategy(dict req, int nRequestID)
{
	CFocusFtdcQryWholeHighStockStrategyField myreq = CFocusFtdcQryWholeHighStockStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	int i = this->api->ReqQryAllAPIHighStockStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqQrySignalAPIHighStockStrategy(dict req, int nRequestID)
{
	CFocusFtdcQrySignalHighStockStrategyField myreq = CFocusFtdcQrySignalHighStockStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQrySignalAPIHighStockStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetSignalHighStockStrategySwitch(dict req, int nRequestID)
{
	CFocusFtdcSignalHighStockStrategySwitchField myreq = CFocusFtdcSignalHighStockStrategySwitchField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "StockWholeSwitch", &myreq.StockWholeSwitch);
	int i = this->api->ReqSetSignalHighStockStrategySwitch(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetHighStockStrategyRelationParam(dict req, int nRequestID)
{
	CFocusFtdcHighFutureStrategyRelationField myreq = CFocusFtdcHighFutureStrategyRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	getInt(req, "StockStrategyIsTrading", &myreq.StockStrategyIsTrading);
	getInt(req, "StockTimeAvail", &myreq.StockTimeAvail);
	getInt(req, "MAStockAvail", &myreq.MAStockAvail);
	getStr(req, "StockTolerRatio", myreq.StockTolerRatio);
	getDouble(req, "StopDeviRatio", &myreq.StopDeviRatio);
	getDouble(req, "RrecovrDeviRatio", &myreq.RrecovrDeviRatio);
	getDouble(req, "TargetMoney", &myreq.TargetMoney);
	getDouble(req, "RoundMaxMoney", &myreq.RoundMaxMoney);
	getStr(req, "FutureExchangeID", myreq.FutureExchangeID);
	getStr(req, "FutureInstrumentID", myreq.FutureInstrumentID);
	getChar(req, "FutureDirection", &myreq.FutureDirection);
	getChar(req, "FuturePriceType", &myreq.FuturePriceType);
	getInt(req, "FutureIsTrading", &myreq.FutureIsTrading);
	getStr(req, "FutureInvestorID", myreq.FutureInvestorID);
	getInt(req, "FutureTimeAvail", &myreq.FutureTimeAvail);
	getDouble(req, "StaticRebuyMoney", &myreq.StaticRebuyMoney);
	getChar(req, "BRNeedContinue", &myreq.BRNeedContinue);
	getDouble(req, "MaxTradePer", &myreq.MaxTradePer);
	getInt(req, "FutureAlgoType", &myreq.FutureAlgoType);
	getStr(req, "IndexExchangeID", myreq.IndexExchangeID);
	getStr(req, "IndexInstrumentID", myreq.IndexInstrumentID);
	getDouble(req, "SpreadPrice", &myreq.SpreadPrice);
	getInt(req, "FutureAmount", &myreq.FutureAmount);
	getChar(req, "ListPriceType", &myreq.ListPriceType);
	getDouble(req, "FuStockRelation", &myreq.FuStockRelation);
	getInt(req, "FlowerFuture", &myreq.FlowerFuture);
	getInt(req, "FutureAvailAmount", &myreq.FutureAvailAmount);
	getChar(req, "PositionRatioType", &myreq.PositionRatioType);
	getInt(req, "StockAlgoType", &myreq.StockAlgoType);
	getStr(req, "AlgoStrategyStartTime", myreq.AlgoStrategyStartTime);
	getStr(req, "AlgoStrategyEndTime", myreq.AlgoStrategyEndTime);
	int i = this->api->ReqSetHighStockStrategyRelationParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAllStrategyRelation(dict req, int nRequestID)
{
	CFocusFtdcQryAllHighFutureStrategyRelationField myreq = CFocusFtdcQryAllHighFutureStrategyRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	int i = this->api->ReqQryAllStrategyRelation(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetAPIHighStockStrategyParam(dict req, int nRequestID)
{
	CFocusFtdcAPIHighStockStrategyField myreq = CFocusFtdcAPIHighStockStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getStr(req, "StockStrategyName", myreq.StockStrategyName);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	getDouble(req, "Ratio", &myreq.Ratio);
	getInt(req, "MaxVolume", &myreq.MaxVolume);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getDouble(req, "StockRatioAvail", &myreq.StockRatioAvail);
	getInt(req, "AverMactchTradeVolume1", &myreq.AverMactchTradeVolume1);
	getInt(req, "AverMactchTradeVolume2", &myreq.AverMactchTradeVolume2);
	getDouble(req, "PreClosePrice", &myreq.PreClosePrice);
	getChar(req, "StockPriceType", &myreq.StockPriceType);
	int i = this->api->ReqSetAPIHighStockStrategyParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelHighStockStrategyRelationParam(dict req, int nRequestID)
{
	CFocusFtdcHighFutureStrategyRelationField myreq = CFocusFtdcHighFutureStrategyRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	getInt(req, "StockStrategyIsTrading", &myreq.StockStrategyIsTrading);
	getInt(req, "StockTimeAvail", &myreq.StockTimeAvail);
	getInt(req, "MAStockAvail", &myreq.MAStockAvail);
	getStr(req, "StockTolerRatio", myreq.StockTolerRatio);
	getDouble(req, "StopDeviRatio", &myreq.StopDeviRatio);
	getDouble(req, "RrecovrDeviRatio", &myreq.RrecovrDeviRatio);
	getDouble(req, "TargetMoney", &myreq.TargetMoney);
	getDouble(req, "RoundMaxMoney", &myreq.RoundMaxMoney);
	getStr(req, "FutureExchangeID", myreq.FutureExchangeID);
	getStr(req, "FutureInstrumentID", myreq.FutureInstrumentID);
	getChar(req, "FutureDirection", &myreq.FutureDirection);
	getChar(req, "FuturePriceType", &myreq.FuturePriceType);
	getInt(req, "FutureIsTrading", &myreq.FutureIsTrading);
	getStr(req, "FutureInvestorID", myreq.FutureInvestorID);
	getInt(req, "FutureTimeAvail", &myreq.FutureTimeAvail);
	getDouble(req, "StaticRebuyMoney", &myreq.StaticRebuyMoney);
	getChar(req, "BRNeedContinue", &myreq.BRNeedContinue);
	getDouble(req, "MaxTradePer", &myreq.MaxTradePer);
	getInt(req, "FutureAlgoType", &myreq.FutureAlgoType);
	getStr(req, "IndexExchangeID", myreq.IndexExchangeID);
	getStr(req, "IndexInstrumentID", myreq.IndexInstrumentID);
	getDouble(req, "SpreadPrice", &myreq.SpreadPrice);
	getInt(req, "FutureAmount", &myreq.FutureAmount);
	getChar(req, "ListPriceType", &myreq.ListPriceType);
	getDouble(req, "FuStockRelation", &myreq.FuStockRelation);
	getInt(req, "FlowerFuture", &myreq.FlowerFuture);
	getInt(req, "FutureAvailAmount", &myreq.FutureAvailAmount);
	getChar(req, "PositionRatioType", &myreq.PositionRatioType);
	getInt(req, "StockAlgoType", &myreq.StockAlgoType);
	getStr(req, "AlgoStrategyStartTime", myreq.AlgoStrategyStartTime);
	getStr(req, "AlgoStrategyEndTime", myreq.AlgoStrategyEndTime);
	int i = this->api->ReqDelHighStockStrategyRelationParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelAPIHighStockStrategyParam(dict req, int nRequestID)
{
	CFocusFtdcAPIHighStockStrategyField myreq = CFocusFtdcAPIHighStockStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getStr(req, "StockStrategyName", myreq.StockStrategyName);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	getDouble(req, "Ratio", &myreq.Ratio);
	getInt(req, "MaxVolume", &myreq.MaxVolume);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getDouble(req, "StockRatioAvail", &myreq.StockRatioAvail);
	getInt(req, "AverMactchTradeVolume1", &myreq.AverMactchTradeVolume1);
	getInt(req, "AverMactchTradeVolume2", &myreq.AverMactchTradeVolume2);
	getDouble(req, "PreClosePrice", &myreq.PreClosePrice);
	getChar(req, "StockPriceType", &myreq.StockPriceType);
	int i = this->api->ReqDelAPIHighStockStrategyParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAllTradingPeriodStrategy(dict req, int nRequestID)
{
	CFocusFtdcQryWholeHighStockStrategyField myreq = CFocusFtdcQryWholeHighStockStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	int i = this->api->ReqQryAllTradingPeriodStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetTradingPeriodStrategy(dict req, int nRequestID)
{
	CFocusFtdcStockMarketTradingPeriodStrategyField myreq = CFocusFtdcStockMarketTradingPeriodStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getStr(req, "TpStart", myreq.TpStart);
	getStr(req, "TpEnd", myreq.TpEnd);
	getStr(req, "StockOrderType", myreq.StockOrderType);
	getDouble(req, "StopDeviRatio", &myreq.StopDeviRatio);
	getDouble(req, "RrecovrDeviRatio", &myreq.RrecovrDeviRatio);
	getDouble(req, "RoundMaxMoney", &myreq.RoundMaxMoney);
	getInt(req, "StockTimeAvail", &myreq.StockTimeAvail);
	getStr(req, "StockTolerRatio", myreq.StockTolerRatio);
	getChar(req, "NeedAddCancelVolumeSwitch", &myreq.NeedAddCancelVolumeSwitch);
	getChar(req, "NeedGetSideVolumeSwitch", &myreq.NeedGetSideVolumeSwitch);
	getChar(req, "CheckMaxVolumeSwitch", &myreq.CheckMaxVolumeSwitch);
	int i = this->api->ReqSetTradingPeriodStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelTradingPeriodStrategy(dict req, int nRequestID)
{
	CFocusFtdcStockMarketTradingPeriodStrategyField myreq = CFocusFtdcStockMarketTradingPeriodStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getStr(req, "TpStart", myreq.TpStart);
	getStr(req, "TpEnd", myreq.TpEnd);
	getStr(req, "StockOrderType", myreq.StockOrderType);
	getDouble(req, "StopDeviRatio", &myreq.StopDeviRatio);
	getDouble(req, "RrecovrDeviRatio", &myreq.RrecovrDeviRatio);
	getDouble(req, "RoundMaxMoney", &myreq.RoundMaxMoney);
	getInt(req, "StockTimeAvail", &myreq.StockTimeAvail);
	getStr(req, "StockTolerRatio", myreq.StockTolerRatio);
	getChar(req, "NeedAddCancelVolumeSwitch", &myreq.NeedAddCancelVolumeSwitch);
	getChar(req, "NeedGetSideVolumeSwitch", &myreq.NeedGetSideVolumeSwitch);
	getChar(req, "CheckMaxVolumeSwitch", &myreq.CheckMaxVolumeSwitch);
	int i = this->api->ReqDelTradingPeriodStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAllInnerStrategyRelation(dict req, int nRequestID)
{
	CFocusFtdcQryAllHighFutureStrategyRelationField myreq = CFocusFtdcQryAllHighFutureStrategyRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	int i = this->api->ReqQryAllInnerStrategyRelation(&myreq, nRequestID);
	return i;
};

int UserApi::reqCancelAllStrategyRelationOrder(dict req, int nRequestID)
{
	CFocusFtdcQryWholeHighStockStrategyField myreq = CFocusFtdcQryWholeHighStockStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyType", &myreq.StockStrategyType);
	int i = this->api->ReqCancelAllStrategyRelationOrder(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetAutoReBuySwitch(dict req, int nRequestID)
{
	CFocusFtdcRelationAutoReBuySwitchField myreq = CFocusFtdcRelationAutoReBuySwitchField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getChar(req, "RelationReBuySwitch", &myreq.RelationReBuySwitch);
	int i = this->api->ReqSetAutoReBuySwitch(&myreq, nRequestID);
	return i;
};

int UserApi::reqSendFutureStrategyOrder(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyOrderField myreq = CFocusFtdcFutureStrategyOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	getInt(req, "TargetNetPosition", &myreq.TargetNetPosition);
	getStr(req, "StartTradingTime", myreq.StartTradingTime);
	getInt(req, "AlgoType", &myreq.AlgoType);
	getStr(req, "UserCustom", myreq.UserCustom);
	getInt(req, "StrategyIsTrading", &myreq.StrategyIsTrading);
	getChar(req, "StrategyPrice", &myreq.StrategyPrice);
	getInt(req, "MactchTrdVol", &myreq.MactchTrdVol);
	getChar(req, "MactchTrdPriceType", &myreq.MactchTrdPriceType);
	getInt(req, "VwapMaxVolume", &myreq.VwapMaxVolume);
	getChar(req, "IsAddPosi", &myreq.IsAddPosi);
	getChar(req, "AddPositionType", &myreq.AddPositionType);
	getChar(req, "PriceDirection", &myreq.PriceDirection);
	getDouble(req, "TriggerPrice", &myreq.TriggerPrice);
	getInt(req, "TotalTimeAvail", &myreq.TotalTimeAvail);
	int i = this->api->ReqSendFutureStrategyOrder(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetAlgoParm(dict req, int nRequestID)
{
	CFocusFtdcAlgoParmField myreq = CFocusFtdcAlgoParmField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	getInt(req, "TolerTick", &myreq.TolerTick);
	getInt(req, "TwapTotalTime", &myreq.TwapTotalTime);
	getInt(req, "TwapSplitAmount", &myreq.TwapSplitAmount);
	getInt(req, "VwapTimeAvail", &myreq.VwapTimeAvail);
	getInt(req, "VwapTotalTime", &myreq.VwapTotalTime);
	getInt(req, "VwapVolumeTotalTime", &myreq.VwapVolumeTotalTime);
	getChar(req, "StockStrategyPrice", &myreq.StockStrategyPrice);
	getInt(req, "MaxNetPosition", &myreq.MaxNetPosition);
	getInt(req, "MinChangePosition", &myreq.MinChangePosition);
	getChar(req, "NeedGetSideVolumeSwitch", &myreq.NeedGetSideVolumeSwitch);
	getDouble(req, "SideVolumePer", &myreq.SideVolumePer);
	int i = this->api->ReqSetAlgoParm(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAlgoParm(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyOrderIndexField myreq = CFocusFtdcFutureStrategyOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqQryAlgoParm(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryFutureStrategyOrder(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyOrderIndexField myreq = CFocusFtdcFutureStrategyOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqQryFutureStrategyOrder(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInnerFutureStrategyOrder(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyOrderIndexField myreq = CFocusFtdcFutureStrategyOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqQryInnerFutureStrategyOrder(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetStragedyMessage(dict req, int nRequestID)
{
	CFocusFtdcIndexDirSignalField myreq = CFocusFtdcIndexDirSignalField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getChar(req, "MessageType", &myreq.MessageType);
	getInt(req, "MessageID", &myreq.MessageID);
	getInt(req, "NeedNtfMessage", &myreq.NeedNtfMessage);
	getStr(req, "OperTime", myreq.OperTime);
	getStr(req, "Note", myreq.Note);
	int i = this->api->ReqSetStragedyMessage(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryIndexDirSignal(dict req, int nRequestID)
{
	CFocusFtdcQryAllHighFutureStrategyRelationField myreq = CFocusFtdcQryAllHighFutureStrategyRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	int i = this->api->ReqQryIndexDirSignal(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelFutureStrategyOrder(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyOrderIndexField myreq = CFocusFtdcFutureStrategyOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqDelFutureStrategyOrder(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelAlgoParm(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyOrderIndexField myreq = CFocusFtdcFutureStrategyOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqDelAlgoParm(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetSpreadInstrStrategy(dict req, int nRequestID)
{
	CFocusFtdcSpreadInstrStrategyField myreq = CFocusFtdcSpreadInstrStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "StrategyID", myreq.StrategyID);
	getStr(req, "ExchangeIDLeg1", myreq.ExchangeIDLeg1);
	getChar(req, "DirectionLeg1", &myreq.DirectionLeg1);
	getStr(req, "InstrLeg1", myreq.InstrLeg1);
	getStr(req, "ExchangeIDLeg2", myreq.ExchangeIDLeg2);
	getChar(req, "DirectionLeg2", &myreq.DirectionLeg2);
	getStr(req, "InstrLeg2", myreq.InstrLeg2);
	getDouble(req, "LegPer", &myreq.LegPer);
	getStr(req, "StartTradingTime", myreq.StartTradingTime);
	getStr(req, "EndTradingTime", myreq.EndTradingTime);
	getInt(req, "TimeAvail", &myreq.TimeAvail);
	getInt(req, "TargetTradeVolume", &myreq.TargetTradeVolume);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getInt(req, "AlgoType", &myreq.AlgoType);
	getDouble(req, "SpreadPrice", &myreq.SpreadPrice);
	getInt(req, "EachTrdvolume", &myreq.EachTrdvolume);
	getInt(req, "StrategyIsTrading", &myreq.StrategyIsTrading);
	getInt(req, "LiquidLack", &myreq.LiquidLack);
	getStr(req, "AlgoParentOrderSysID", myreq.AlgoParentOrderSysID);
	getStr(req, "Note", myreq.Note);
	int i = this->api->ReqSetSpreadInstrStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqQrySpreadInstrStrategy(dict req, int nRequestID)
{
	CFocusFtdcSpreadInstrStrategyIndexField myreq = CFocusFtdcSpreadInstrStrategyIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqQrySpreadInstrStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelSpreadInstrStrategy(dict req, int nRequestID)
{
	CFocusFtdcSpreadInstrStrategyIndexField myreq = CFocusFtdcSpreadInstrStrategyIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqDelSpreadInstrStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryInnerSpreadInstrStrategy(dict req, int nRequestID)
{
	CFocusFtdcSpreadInstrStrategyIndexField myreq = CFocusFtdcSpreadInstrStrategyIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqQryInnerSpreadInstrStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetTZeroHighStockStrategy(dict req, int nRequestID)
{
	CFocusFtdcTZeroHighStockStrategyField myreq = CFocusFtdcTZeroHighStockStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "TZeroGapVolume", &myreq.TZeroGapVolume);
	getChar(req, "TZeroStockPriceType", &myreq.TZeroStockPriceType);
	getStr(req, "TZeroEndOperTime", myreq.TZeroEndOperTime);
	getDouble(req, "TZeroUpperEndPrice", &myreq.TZeroUpperEndPrice);
	getDouble(req, "TZeroLowerEndPrice", &myreq.TZeroLowerEndPrice);
	getStr(req, "TZeroLastOperTime", myreq.TZeroLastOperTime);
	int i = this->api->ReqSetTZeroHighStockStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryTZeroHighStockStrategy(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyOrderIndexField myreq = CFocusFtdcFutureStrategyOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqQryTZeroHighStockStrategy(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetfutruetradeinstr(dict req, int nRequestID)
{
	CFocusFtdcQryInstrumentField myreq = CFocusFtdcQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "ProductID", myreq.ProductID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSetfutruetradeinstr(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryFlowerFutureTargetMoney(dict req, int nRequestID)
{
	CFocusFtdcQryAllHighFutureStrategyRelationField myreq = CFocusFtdcQryAllHighFutureStrategyRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	int i = this->api->ReqQryFlowerFutureTargetMoney(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetFlowerFutureTargetMoney(dict req, int nRequestID)
{
	CFocusFtdcFlowerFutureTargetMoneyField myreq = CFocusFtdcFlowerFutureTargetMoneyField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "LastOperTime", myreq.LastOperTime);
	getDouble(req, "FlowerFutureTarMoney", &myreq.FlowerFutureTarMoney);
	getChar(req, "WholeSwitch", &myreq.WholeSwitch);
	int i = this->api->ReqSetFlowerFutureTargetMoney(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetParentDetialUpdateMessage(dict req, int nRequestID)
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

int UserApi::reqQryMarketTradingTime(dict req, int nRequestID)
{
	CFocusFtdcAPIQryMarketTradingTimeField myreq = CFocusFtdcAPIQryMarketTradingTimeField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "ExchangeName", myreq.ExchangeName);
	getStr(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryMarketTradingTime(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetFutureStrategyTotalSecondRelationParam(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyTotalSecondRelationField myreq = CFocusFtdcFutureStrategyTotalSecondRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyIsTrading", &myreq.StockStrategyIsTrading);
	getStr(req, "FutureExchangeID", myreq.FutureExchangeID);
	getStr(req, "FutureInstrumentID", myreq.FutureInstrumentID);
	getChar(req, "FutureDirection", &myreq.FutureDirection);
	getChar(req, "FuturePriceType", &myreq.FuturePriceType);
	getInt(req, "FutureIsTrading", &myreq.FutureIsTrading);
	getStr(req, "FutureInvestorID", myreq.FutureInvestorID);
	getInt(req, "FutureTimeAvail", &myreq.FutureTimeAvail);
	getInt(req, "FutureAvailAmount", &myreq.FutureAvailAmount);
	getInt(req, "FutureAlgoType", &myreq.FutureAlgoType);
	getStr(req, "IndexExchangeID", myreq.IndexExchangeID);
	getStr(req, "IndexInstrumentID", myreq.IndexInstrumentID);
	getDouble(req, "SpreadPrice", &myreq.SpreadPrice);
	getInt(req, "FutureAmount", &myreq.FutureAmount);
	getChar(req, "ListPriceType", &myreq.ListPriceType);
	getDouble(req, "FuStockRelation", &myreq.FuStockRelation);
	getStr(req, "TpStart", myreq.TpStart);
	getStr(req, "TpEnd", myreq.TpEnd);
	int i = this->api->ReqSetFutureStrategyTotalSecondRelationParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAllTotalSecondStrategyRelation(dict req, int nRequestID)
{
	CFocusFtdcQryAllHighFutureStrategyRelationField myreq = CFocusFtdcQryAllHighFutureStrategyRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	int i = this->api->ReqQryAllTotalSecondStrategyRelation(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelHighStockStrategyTotalSecondRelationParam(dict req, int nRequestID)
{
	CFocusFtdcFutureStrategyTotalSecondRelationField myreq = CFocusFtdcFutureStrategyTotalSecondRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "StockStrategyID", myreq.StockStrategyID);
	getInt(req, "StockStrategyIsTrading", &myreq.StockStrategyIsTrading);
	getStr(req, "FutureExchangeID", myreq.FutureExchangeID);
	getStr(req, "FutureInstrumentID", myreq.FutureInstrumentID);
	getChar(req, "FutureDirection", &myreq.FutureDirection);
	getChar(req, "FuturePriceType", &myreq.FuturePriceType);
	getInt(req, "FutureIsTrading", &myreq.FutureIsTrading);
	getStr(req, "FutureInvestorID", myreq.FutureInvestorID);
	getInt(req, "FutureTimeAvail", &myreq.FutureTimeAvail);
	getInt(req, "FutureAvailAmount", &myreq.FutureAvailAmount);
	getInt(req, "FutureAlgoType", &myreq.FutureAlgoType);
	getStr(req, "IndexExchangeID", myreq.IndexExchangeID);
	getStr(req, "IndexInstrumentID", myreq.IndexInstrumentID);
	getDouble(req, "SpreadPrice", &myreq.SpreadPrice);
	getInt(req, "FutureAmount", &myreq.FutureAmount);
	getChar(req, "ListPriceType", &myreq.ListPriceType);
	getDouble(req, "FuStockRelation", &myreq.FuStockRelation);
	getStr(req, "TpStart", myreq.TpStart);
	getStr(req, "TpEnd", myreq.TpEnd);
	int i = this->api->ReqDelHighStockStrategyTotalSecondRelationParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryAllInnerTotalSecondStrategyRelation(dict req, int nRequestID)
{
	CFocusFtdcQryAllHighFutureStrategyRelationField myreq = CFocusFtdcQryAllHighFutureStrategyRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	int i = this->api->ReqQryAllInnerTotalSecondStrategyRelation(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryParentDetialUpdateMessage(dict req, int nRequestID)
{
	CFocusFtdcParentOrderDetialIndexField myreq = CFocusFtdcParentOrderDetialIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	getStr(req, "AlgoParentOrderSysID", myreq.AlgoParentOrderSysID);
	int i = this->api->ReqQryParentDetialUpdateMessage(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryParentOrderStaticParam(dict req, int nRequestID)
{
	CFocusFtdcParentOrderIndexField myreq = CFocusFtdcParentOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqQryParentOrderStaticParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetParentOrderStaticParam(dict req, int nRequestID)
{
	CFocusFtdcParentOrderStaticParamField myreq = CFocusFtdcParentOrderStaticParamField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	getInt(req, "style", &myreq.style);
	getDouble(req, "maxVolumeP", &myreq.maxVolumeP);
	getInt(req, "minDisplaySize", &myreq.minDisplaySize);
	getInt(req, "displaySize", &myreq.displaySize);
	getInt(req, "countVolInLimitPx", &myreq.countVolInLimitPx);
	getInt(req, "resetVolOnAmend", &myreq.resetVolOnAmend);
	getDouble(req, "limitPrice", &myreq.limitPrice);
	getInt(req, "relativePriceLimitBase", &myreq.relativePriceLimitBase);
	getInt(req, "relativePriceLimitType", &myreq.relativePriceLimitType);
	getDouble(req, "relativePriceLimitOffset", &myreq.relativePriceLimitOffset);
	getInt(req, "stepSpread", &myreq.stepSpread);
	getInt(req, "optOnExtreme", &myreq.optOnExtreme);
	int i = this->api->ReqSetParentOrderStaticParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqDelParentOrderStaticParam(dict req, int nRequestID)
{
	CFocusFtdcParentOrderIndexField myreq = CFocusFtdcParentOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqDelParentOrderStaticParam(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryJavaAlgoStatus(dict req, int nRequestID)
{
	CFocusFtdcFocusStatusField myreq = CFocusFtdcFocusStatusField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "TradeStatus", &myreq.TradeStatus);
	int i = this->api->ReqQryJavaAlgoStatus(&myreq, nRequestID);
	return i;
};

int UserApi::reqSetJavaAlgoStatus(dict req, int nRequestID)
{
	CFocusFtdcFocusStatusField myreq = CFocusFtdcFocusStatusField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getChar(req, "TradeStatus", &myreq.TradeStatus);
	int i = this->api->ReqSetJavaAlgoStatus(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryFuSkAccountRelation(dict req, int nRequestID)
{
	CFocusFtdcFuSkAccountRelationField myreq = CFocusFtdcFuSkAccountRelationField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "StockInvestorID", myreq.StockInvestorID);
	getStr(req, "FutureInvestorID", myreq.FutureInvestorID);
	getStr(req, "FuturePasswd", myreq.FuturePasswd);
	int i = this->api->ReqQryFuSkAccountRelation(&myreq, nRequestID);
	return i;
};

int UserApi::reqBatchOrderInsert(dict req, int nRequestID)
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

int UserApi::reqBatchOrderAction(dict req, int nRequestID)
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

int UserApi::reqSetUserInvestorSeatBasePasswd(dict req, int nRequestID)
{
	CFocusFtdcUserInvestorSeatBaseField myreq = CFocusFtdcUserInvestorSeatBaseField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "OldUserPassword", myreq.OldUserPassword);
	getStr(req, "NewUserPassword", myreq.NewUserPassword);
	getStr(req, "SeatID", myreq.SeatID);
	getStr(req, "OldSeatPassword", myreq.OldSeatPassword);
	getStr(req, "NewSeatPassword", myreq.NewSeatPassword);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "OldInvestorPasswd", myreq.OldInvestorPasswd);
	getStr(req, "NewInvestorPasswd", myreq.NewInvestorPasswd);
	int i = this->api->ReqSetUserInvestorSeatBasePasswd(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryUnFinshPutureOrder(dict req, int nRequestID)
{
	CFocusFtdcParentOrderIndexField myreq = CFocusFtdcParentOrderIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "StrategyID", myreq.StrategyID);
	int i = this->api->ReqQryUnFinshPutureOrder(&myreq, nRequestID);
	return i;
};

int UserApi::reqQryTodayTayoutDetails(dict req, int nRequestID)
{
	CFocusFtdcQryTodayTayoutDetailsIndexField myreq = CFocusFtdcQryTodayTayoutDetailsIndexField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "InvestorID", myreq.InvestorID);
	getStr(req, "UserID", myreq.UserID);
	getStr(req, "contractNum", myreq.contractNum);
	int i = this->api->ReqQryTodayTayoutDetails(&myreq, nRequestID);
	return i;
};



///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

struct UserApiWrap : UserApi, wrapper < UserApi >
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

	virtual void onRspUserPasswordUpdate(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspUserPasswordUpdate")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspForceUserExit(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspForceUserExit")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspForceUserLogout(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspForceUserLogout")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDumpMemDB(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDumpMemDB")(data, error, id, last);
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

	virtual void onRspAccountDeposit(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspAccountDeposit")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspInvestorRight(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspInvestorRight")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspTBCommand(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspTBCommand")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspPingPong(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspPingPong")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetAdviceRunMode(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetAdviceRunMode")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnDepthMarketData(dict data)
	{
		try
		{
			this->get_override("onRtnDepthMarketData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnMultiDepthMarketData(dict data)
	{
		try
		{
			this->get_override("onRtnMultiDepthMarketData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSubMarketData(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSubMarketData")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspUnSubMarketData(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspUnSubMarketData")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspTopicSearch(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspTopicSearch")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnMBLMarketData(dict data)
	{
		try
		{
			this->get_override("onRtnMBLMarketData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnQmdInstrumentStatu(dict data)
	{
		try
		{
			this->get_override("onRtnQmdInstrumentStatu")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnFlowMessageCancel(dict data)
	{
		try
		{
			this->get_override("onRtnFlowMessageCancel")(data);
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

	virtual void onErrRtnOrderInsert(dict data, dict error)
	{
		try
		{
			this->get_override("onErrRtnOrderInsert")(data, error);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onErrRtnOrderAction(dict data, dict error)
	{
		try
		{
			this->get_override("onErrRtnOrderAction")(data, error);
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

	virtual void onRtnInvestorAccountDeposit(dict data)
	{
		try
		{
			this->get_override("onRtnInvestorAccountDeposit")(data);
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

	virtual void onRtnAdviceOrder(dict data)
	{
		try
		{
			this->get_override("onRtnAdviceOrder")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnSubInstrumentStatus(dict data)
	{
		try
		{
			this->get_override("onRtnSubInstrumentStatus")(data);
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

	virtual void onRspQryUserInvestor(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryUserInvestor")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInvestorAccount(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInvestorAccount")(data, error, id, last);
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

	virtual void onRspQryUser(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryUser")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInvestorFee(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInvestorFee")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInvestorMargin(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInvestorMargin")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInvestor(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInvestor")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAccountRisk(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAccountRisk")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryUserSession(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryUserSession")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryMarketData(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryMarketData")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInvestorRelation(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInvestorRelation")(data, error, id, last);
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

	virtual void onRspQryAdviceTrader(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAdviceTrader")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryMaxVolume(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryMaxVolume")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryCmbPositionDetail(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryCmbPositionDetail")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQrySettlementInfo(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQrySettlementInfo")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSubInstrument(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSubInstrument")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspUnSubInstrument(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspUnSubInstrument")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryResultPage(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryResultPage")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInvestorPositionDetail(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInvestorPositionDetail")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnTheoryPriceData(dict data)
	{
		try
		{
			this->get_override("onRtnTheoryPriceData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnOptionIndexData(dict data)
	{
		try
		{
			this->get_override("onRtnOptionIndexData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetPricingParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetPricingParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetOptionTheoryVol(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetOptionTheoryVol")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspCalcOneOption(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspCalcOneOption")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspCalcBarrierOption(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspCalcBarrierOption")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspVolatilityFitting(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspVolatilityFitting")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryWingModelParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryWingModelParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetWingModelParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetWingModelParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnQuoteTotalTradePrice(dict data)
	{
		try
		{
			this->get_override("onRtnQuoteTotalTradePrice")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryMarkerStrategySet(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryMarkerStrategySet")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspUpMarkerStrategySet(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspUpMarkerStrategySet")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryUserSwitch(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryUserSwitch")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspUserSwitch(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspUserSwitch")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryMarkerHedge(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryMarkerHedge")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspUpMarkerHedge(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspUpMarkerHedge")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryFittingParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryFittingParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetFittingParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetFittingParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryPricingParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryPricingParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryOptionTheoryVol(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryOptionTheoryVol")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQuoteInsert(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQuoteInsert")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQuoteAction(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQuoteAction")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryQuote(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryQuote")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnQuote(dict data)
	{
		try
		{
			this->get_override("onRtnQuote")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspForQuote(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspForQuote")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnForQuote(dict data)
	{
		try
		{
			this->get_override("onRtnForQuote")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryOrderInsertFailed(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryOrderInsertFailed")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspCleanQuoteThresHold(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspCleanQuoteThresHold")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetPriceSpread(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetPriceSpread")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryPriceSpread(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryPriceSpread")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelPricingParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelPricingParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelMarkerStrategySet(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelMarkerStrategySet")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetAlertParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetAlertParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAlertParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAlertParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAlertData(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAlertData")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnAlertData(dict data)
	{
		try
		{
			this->get_override("onRtnAlertData")(data);
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

	virtual void onRtnQuoteTotalTradePosition(dict data)
	{
		try
		{
			this->get_override("onRtnQuoteTotalTradePosition")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelOptionTheoryVol(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelOptionTheoryVol")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelMarkerHedge(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelMarkerHedge")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetMarkerStep(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetMarkerStep")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelMarkerStep(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelMarkerStep")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelAlertParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelAlertParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetQuoteMove(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetQuoteMove")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelQuoteMove(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelQuoteMove")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspRebackQuote(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspRebackQuote")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryDepMarketData(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryDepMarketData")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryQuoteMove(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryQuoteMove")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryBaseMarkerStep(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryBaseMarkerStep")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryMarkerStep(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryMarkerStep")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspFocusStatus(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspFocusStatus")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnATMPriceData(dict data)
	{
		try
		{
			this->get_override("onRtnATMPriceData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetFutureMakerWholeSwitch(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetFutureMakerWholeSwitch")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetFutureMakerStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetFutureMakerStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetSlefHedgeStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetSlefHedgeStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetFutureHedgeStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetFutureHedgeStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetQuoteAdditionParm(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetQuoteAdditionParm")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnMarkerStrategyChange(dict data)
	{
		try
		{
			this->get_override("onRtnMarkerStrategyChange")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspStopAllFutureMakerHedgeOffer(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspStopAllFutureMakerHedgeOffer")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnFutureMakerHedgeStatus(dict data)
	{
		try
		{
			this->get_override("onRtnFutureMakerHedgeStatus")(data);
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

	virtual void onRspQryFutureMakerStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryFutureMakerStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAllInnerHighStockStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAllInnerHighStockStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnInnerHighStockStrategy(dict data)
	{
		try
		{
			this->get_override("onRtnInnerHighStockStrategy")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetHighStockStrategySwitch(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetHighStockStrategySwitch")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAPIHighStockStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAPIHighStockStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQrySignalPIHighStockStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQrySignalPIHighStockStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetSignalHighStockStrategySwitch(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetSignalHighStockStrategySwitch")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetHighStockStrategyRelationParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetHighStockStrategyRelationParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnHighInnerFutureStrategyRelation(dict data)
	{
		try
		{
			this->get_override("onRtnHighInnerFutureStrategyRelation")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAllStrategyRelation(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAllStrategyRelation")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetAPIHighStockStrategyParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetAPIHighStockStrategyParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelHighStockStrategyRelationParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelHighStockStrategyRelationParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelAPIHighStockStrategyParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelAPIHighStockStrategyParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAllTradingPeriodStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAllTradingPeriodStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetTradingPeriodStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetTradingPeriodStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelTradingPeriodStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelTradingPeriodStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAllInnerStrategyRelation(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAllInnerStrategyRelation")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspCancelAllStrategyRelationOrder(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspCancelAllStrategyRelationOrder")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetAutoReBuySwitch(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetAutoReBuySwitch")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSendFutureStrategyOrder(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSendFutureStrategyOrder")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetAlgoParm(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetAlgoParm")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnInnerFutureStrategyOrder(dict data)
	{
		try
		{
			this->get_override("onRtnInnerFutureStrategyOrder")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAlgoParm(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAlgoParm")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryFutureStrategyOrder(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryFutureStrategyOrder")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInnerFutureStrategyOrder(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInnerFutureStrategyOrder")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetStragedyMessage(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetStragedyMessage")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryIndexDirSignal(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryIndexDirSignal")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelFutureStrategyOrder(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelFutureStrategyOrder")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelAlgoParm(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelAlgoParm")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetSpreadInstrStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetSpreadInstrStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQrySpreadInstrStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQrySpreadInstrStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelSpreadInstrStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelSpreadInstrStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryInnerSpreadInstrStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInnerSpreadInstrStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnInnerSpreadInstrStrategy(dict data)
	{
		try
		{
			this->get_override("onRtnInnerSpreadInstrStrategy")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetTZeroHighStockStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetTZeroHighStockStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryTZeroHighStockStrategy(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryTZeroHighStockStrategy")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnStragedyMessage(dict data)
	{
		try
		{
			this->get_override("onRtnStragedyMessage")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetfutruetradeinstr(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetfutruetradeinstr")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryFlowerFutureTargetMoney(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryFlowerFutureTargetMoney")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetFlowerFutureTargetMoney(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetFlowerFutureTargetMoney")(data, error, id, last);
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

	virtual void onRspSetFutureStrategyTotalSecondRelationParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetFutureStrategyTotalSecondRelationParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnHighInnerFutureStrategyTotalSecondRelation(dict data)
	{
		try
		{
			this->get_override("onRtnHighInnerFutureStrategyTotalSecondRelation")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAllTotalSecondStrategyRelation(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAllTotalSecondStrategyRelation")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelHighStockStrategyTotalSecondRelationParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelHighStockStrategyTotalSecondRelationParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryAllInnerTotalSecondStrategyRelation(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryAllInnerTotalSecondStrategyRelation")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryParentDetialUpdateMessage(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryParentDetialUpdateMessage")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryParentOrderStaticParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryParentOrderStaticParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnParentDetialUpdateMessage(dict data)
	{
		try
		{
			this->get_override("onRtnParentDetialUpdateMessage")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspSetParentOrderStaticParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetParentOrderStaticParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspDelParentOrderStaticParam(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspDelParentOrderStaticParam")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryJavaAlgoStatus(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryJavaAlgoStatus")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnJavaAlgoStatus(dict data)
	{
		try
		{
			this->get_override("onRtnJavaAlgoStatus")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryFuSkAccountRelation(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryFuSkAccountRelation")(data, error, id, last);
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

	virtual void onRspSetUserInvestorSeatBasePasswd(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspSetUserInvestorSeatBasePasswd")(data, error, id, last);
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

	virtual void onRspQryUnFinshPutureOrder(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryUnFinshPutureOrder")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryTodayTayoutDetails(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryTodayTayoutDetails")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};


};

BOOST_PYTHON_MODULE(userbinding)
{
	PyEval_InitThreads();	//导入时运行，保证先创建GIL

	class_<UserApiWrap, boost::noncopyable>("UserApi")
		.def("createFtdcTraderApi", &UserApiWrap::createFtdcUserApi)
		.def("release", &UserApiWrap::release)
		.def("init", &UserApiWrap::init)
		.def("join", &UserApiWrap::join)
		.def("exit", &UserApiWrap::exit)
		.def("getTradingDay", &UserApiWrap::getTradingDay)
		.def("registerFront", &UserApiWrap::registerFront)
		.def("subscribePrivateTopic", &UserApiWrap::subscribePrivateTopic)
		.def("subscribePublicTopic", &UserApiWrap::subscribePublicTopic)
		.def("onFrontConnected", pure_virtual(&UserApiWrap::onFrontConnected))
		.def("onFrontDisconnected", pure_virtual(&UserApiWrap::onFrontDisconnected))
		.def("onHeartBeatWarning", pure_virtual(&UserApiWrap::onHeartBeatWarning))
		.def("onRspError", pure_virtual(&UserApiWrap::onRspError))
		.def("onRspUserLogin", pure_virtual(&UserApiWrap::onRspUserLogin))
		.def("onRspUserLogout", pure_virtual(&UserApiWrap::onRspUserLogout))
		.def("onRspUserPasswordUpdate", pure_virtual(&UserApiWrap::onRspUserPasswordUpdate))
		.def("onRspForceUserExit", pure_virtual(&UserApiWrap::onRspForceUserExit))
		.def("onRspForceUserLogout", pure_virtual(&UserApiWrap::onRspForceUserLogout))
		.def("onRspDumpMemDB", pure_virtual(&UserApiWrap::onRspDumpMemDB))
		.def("onRspOrderInsert", pure_virtual(&UserApiWrap::onRspOrderInsert))
		.def("onRspOrderAction", pure_virtual(&UserApiWrap::onRspOrderAction))
		.def("onRspAccountDeposit", pure_virtual(&UserApiWrap::onRspAccountDeposit))
		.def("onRspInvestorRight", pure_virtual(&UserApiWrap::onRspInvestorRight))
		.def("onRspTBCommand", pure_virtual(&UserApiWrap::onRspTBCommand))
		.def("onRspPingPong", pure_virtual(&UserApiWrap::onRspPingPong))
		.def("onRspSetAdviceRunMode", pure_virtual(&UserApiWrap::onRspSetAdviceRunMode))
		.def("onRtnDepthMarketData", pure_virtual(&UserApiWrap::onRtnDepthMarketData))
		.def("onRtnMultiDepthMarketData", pure_virtual(&UserApiWrap::onRtnMultiDepthMarketData))
		.def("onRspSubMarketData", pure_virtual(&UserApiWrap::onRspSubMarketData))
		.def("onRspUnSubMarketData", pure_virtual(&UserApiWrap::onRspUnSubMarketData))
		.def("onRspTopicSearch", pure_virtual(&UserApiWrap::onRspTopicSearch))
		.def("onRtnMBLMarketData", pure_virtual(&UserApiWrap::onRtnMBLMarketData))
		.def("onRtnQmdInstrumentStatu", pure_virtual(&UserApiWrap::onRtnQmdInstrumentStatu))
		.def("onRtnFlowMessageCancel", pure_virtual(&UserApiWrap::onRtnFlowMessageCancel))
		.def("onRtnTrade", pure_virtual(&UserApiWrap::onRtnTrade))
		.def("onRtnOrder", pure_virtual(&UserApiWrap::onRtnOrder))
		.def("onErrRtnOrderInsert", pure_virtual(&UserApiWrap::onErrRtnOrderInsert))
		.def("onErrRtnOrderAction", pure_virtual(&UserApiWrap::onErrRtnOrderAction))
		.def("onRtnInstrumentStatus", pure_virtual(&UserApiWrap::onRtnInstrumentStatus))
		.def("onRtnInvestorAccountDeposit", pure_virtual(&UserApiWrap::onRtnInvestorAccountDeposit))
		.def("onRtnMessageNotify", pure_virtual(&UserApiWrap::onRtnMessageNotify))
		.def("onRtnAdviceOrder", pure_virtual(&UserApiWrap::onRtnAdviceOrder))
		.def("onRtnSubInstrumentStatus", pure_virtual(&UserApiWrap::onRtnSubInstrumentStatus))
		.def("onRspQryOrder", pure_virtual(&UserApiWrap::onRspQryOrder))
		.def("onRspQryTrade", pure_virtual(&UserApiWrap::onRspQryTrade))
		.def("onRspQryUserInvestor", pure_virtual(&UserApiWrap::onRspQryUserInvestor))
		.def("onRspQryInvestorAccount", pure_virtual(&UserApiWrap::onRspQryInvestorAccount))
		.def("onRspQryInstrument", pure_virtual(&UserApiWrap::onRspQryInstrument))
		.def("onRspQryExchange", pure_virtual(&UserApiWrap::onRspQryExchange))
		.def("onRspQryInvestorPosition", pure_virtual(&UserApiWrap::onRspQryInvestorPosition))
		.def("onRspSubscribeTopic", pure_virtual(&UserApiWrap::onRspSubscribeTopic))
		.def("onRspQryTopic", pure_virtual(&UserApiWrap::onRspQryTopic))
		.def("onRspQryUser", pure_virtual(&UserApiWrap::onRspQryUser))
		.def("onRspQryInvestorFee", pure_virtual(&UserApiWrap::onRspQryInvestorFee))
		.def("onRspQryInvestorMargin", pure_virtual(&UserApiWrap::onRspQryInvestorMargin))
		.def("onRspQryInvestor", pure_virtual(&UserApiWrap::onRspQryInvestor))
		.def("onRspQryAccountRisk", pure_virtual(&UserApiWrap::onRspQryAccountRisk))
		.def("onRspQryUserSession", pure_virtual(&UserApiWrap::onRspQryUserSession))
		.def("onRspQryMarketData", pure_virtual(&UserApiWrap::onRspQryMarketData))
		.def("onRspQryInvestorRelation", pure_virtual(&UserApiWrap::onRspQryInvestorRelation))
		.def("onRspQryProduct", pure_virtual(&UserApiWrap::onRspQryProduct))
		.def("onRspQryAdviceTrader", pure_virtual(&UserApiWrap::onRspQryAdviceTrader))
		.def("onRspQryMaxVolume", pure_virtual(&UserApiWrap::onRspQryMaxVolume))
		.def("onRspQryCmbPositionDetail", pure_virtual(&UserApiWrap::onRspQryCmbPositionDetail))
		.def("onRspQrySettlementInfo", pure_virtual(&UserApiWrap::onRspQrySettlementInfo))
		.def("onRspSubInstrument", pure_virtual(&UserApiWrap::onRspSubInstrument))
		.def("onRspUnSubInstrument", pure_virtual(&UserApiWrap::onRspUnSubInstrument))
		.def("onRspQryResultPage", pure_virtual(&UserApiWrap::onRspQryResultPage))
		.def("onRspQryInvestorPositionDetail", pure_virtual(&UserApiWrap::onRspQryInvestorPositionDetail))
		.def("onRtnTheoryPriceData", pure_virtual(&UserApiWrap::onRtnTheoryPriceData))
		.def("onRtnOptionIndexData", pure_virtual(&UserApiWrap::onRtnOptionIndexData))
		.def("onRspSetPricingParam", pure_virtual(&UserApiWrap::onRspSetPricingParam))
		.def("onRspSetOptionTheoryVol", pure_virtual(&UserApiWrap::onRspSetOptionTheoryVol))
		.def("onRspCalcOneOption", pure_virtual(&UserApiWrap::onRspCalcOneOption))
		.def("onRspCalcBarrierOption", pure_virtual(&UserApiWrap::onRspCalcBarrierOption))
		.def("onRspVolatilityFitting", pure_virtual(&UserApiWrap::onRspVolatilityFitting))
		.def("onRspQryWingModelParam", pure_virtual(&UserApiWrap::onRspQryWingModelParam))
		.def("onRspSetWingModelParam", pure_virtual(&UserApiWrap::onRspSetWingModelParam))
		.def("onRtnQuoteTotalTradePrice", pure_virtual(&UserApiWrap::onRtnQuoteTotalTradePrice))
		.def("onRspQryMarkerStrategySet", pure_virtual(&UserApiWrap::onRspQryMarkerStrategySet))
		.def("onRspUpMarkerStrategySet", pure_virtual(&UserApiWrap::onRspUpMarkerStrategySet))
		.def("onRspQryUserSwitch", pure_virtual(&UserApiWrap::onRspQryUserSwitch))
		.def("onRspUserSwitch", pure_virtual(&UserApiWrap::onRspUserSwitch))
		.def("onRspQryMarkerHedge", pure_virtual(&UserApiWrap::onRspQryMarkerHedge))
		.def("onRspUpMarkerHedge", pure_virtual(&UserApiWrap::onRspUpMarkerHedge))
		.def("onRspQryFittingParam", pure_virtual(&UserApiWrap::onRspQryFittingParam))
		.def("onRspSetFittingParam", pure_virtual(&UserApiWrap::onRspSetFittingParam))
		.def("onRspQryPricingParam", pure_virtual(&UserApiWrap::onRspQryPricingParam))
		.def("onRspQryOptionTheoryVol", pure_virtual(&UserApiWrap::onRspQryOptionTheoryVol))
		.def("onRspQuoteInsert", pure_virtual(&UserApiWrap::onRspQuoteInsert))
		.def("onRspQuoteAction", pure_virtual(&UserApiWrap::onRspQuoteAction))
		.def("onRspQryQuote", pure_virtual(&UserApiWrap::onRspQryQuote))
		.def("onRtnQuote", pure_virtual(&UserApiWrap::onRtnQuote))
		.def("onRspForQuote", pure_virtual(&UserApiWrap::onRspForQuote))
		.def("onRtnForQuote", pure_virtual(&UserApiWrap::onRtnForQuote))
		.def("onRspQryOrderInsertFailed", pure_virtual(&UserApiWrap::onRspQryOrderInsertFailed))
		.def("onRspCleanQuoteThresHold", pure_virtual(&UserApiWrap::onRspCleanQuoteThresHold))
		.def("onRspSetPriceSpread", pure_virtual(&UserApiWrap::onRspSetPriceSpread))
		.def("onRspQryPriceSpread", pure_virtual(&UserApiWrap::onRspQryPriceSpread))
		.def("onRspDelPricingParam", pure_virtual(&UserApiWrap::onRspDelPricingParam))
		.def("onRspDelMarkerStrategySet", pure_virtual(&UserApiWrap::onRspDelMarkerStrategySet))
		.def("onRspSetAlertParam", pure_virtual(&UserApiWrap::onRspSetAlertParam))
		.def("onRspQryAlertParam", pure_virtual(&UserApiWrap::onRspQryAlertParam))
		.def("onRspQryAlertData", pure_virtual(&UserApiWrap::onRspQryAlertData))
		.def("onRtnAlertData", pure_virtual(&UserApiWrap::onRtnAlertData))
		.def("onRtnStrategyLog", pure_virtual(&UserApiWrap::onRtnStrategyLog))
		.def("onRtnQuoteTotalTradePosition", pure_virtual(&UserApiWrap::onRtnQuoteTotalTradePosition))
		.def("onRspDelOptionTheoryVol", pure_virtual(&UserApiWrap::onRspDelOptionTheoryVol))
		.def("onRspDelMarkerHedge", pure_virtual(&UserApiWrap::onRspDelMarkerHedge))
		.def("onRspSetMarkerStep", pure_virtual(&UserApiWrap::onRspSetMarkerStep))
		.def("onRspDelMarkerStep", pure_virtual(&UserApiWrap::onRspDelMarkerStep))
		.def("onRspDelAlertParam", pure_virtual(&UserApiWrap::onRspDelAlertParam))
		.def("onRspSetQuoteMove", pure_virtual(&UserApiWrap::onRspSetQuoteMove))
		.def("onRspDelQuoteMove", pure_virtual(&UserApiWrap::onRspDelQuoteMove))
		.def("onRspRebackQuote", pure_virtual(&UserApiWrap::onRspRebackQuote))
		.def("onRspQryDepMarketData", pure_virtual(&UserApiWrap::onRspQryDepMarketData))
		.def("onRspQryQuoteMove", pure_virtual(&UserApiWrap::onRspQryQuoteMove))
		.def("onRspQryBaseMarkerStep", pure_virtual(&UserApiWrap::onRspQryBaseMarkerStep))
		.def("onRspQryMarkerStep", pure_virtual(&UserApiWrap::onRspQryMarkerStep))
		.def("onRspFocusStatus", pure_virtual(&UserApiWrap::onRspFocusStatus))
		.def("onRtnATMPriceData", pure_virtual(&UserApiWrap::onRtnATMPriceData))
		.def("onRspSetFutureMakerWholeSwitch", pure_virtual(&UserApiWrap::onRspSetFutureMakerWholeSwitch))
		.def("onRspSetFutureMakerStrategy", pure_virtual(&UserApiWrap::onRspSetFutureMakerStrategy))
		.def("onRspSetSlefHedgeStrategy", pure_virtual(&UserApiWrap::onRspSetSlefHedgeStrategy))
		.def("onRspSetFutureHedgeStrategy", pure_virtual(&UserApiWrap::onRspSetFutureHedgeStrategy))
		.def("onRspSetQuoteAdditionParm", pure_virtual(&UserApiWrap::onRspSetQuoteAdditionParm))
		.def("onRtnMarkerStrategyChange", pure_virtual(&UserApiWrap::onRtnMarkerStrategyChange))
		.def("onRspStopAllFutureMakerHedgeOffer", pure_virtual(&UserApiWrap::onRspStopAllFutureMakerHedgeOffer))
		.def("onRtnFutureMakerHedgeStatus", pure_virtual(&UserApiWrap::onRtnFutureMakerHedgeStatus))
		.def("onRtnInvestorPosition", pure_virtual(&UserApiWrap::onRtnInvestorPosition))
		.def("onRspQryFutureMakerStrategy", pure_virtual(&UserApiWrap::onRspQryFutureMakerStrategy))
		.def("onRspQryAllInnerHighStockStrategy", pure_virtual(&UserApiWrap::onRspQryAllInnerHighStockStrategy))
		.def("onRtnInnerHighStockStrategy", pure_virtual(&UserApiWrap::onRtnInnerHighStockStrategy))
		.def("onRspSetHighStockStrategySwitch", pure_virtual(&UserApiWrap::onRspSetHighStockStrategySwitch))
		.def("onRspQryAPIHighStockStrategy", pure_virtual(&UserApiWrap::onRspQryAPIHighStockStrategy))
		.def("onRspQrySignalPIHighStockStrategy", pure_virtual(&UserApiWrap::onRspQrySignalPIHighStockStrategy))
		.def("onRspSetSignalHighStockStrategySwitch", pure_virtual(&UserApiWrap::onRspSetSignalHighStockStrategySwitch))
		.def("onRspSetHighStockStrategyRelationParam", pure_virtual(&UserApiWrap::onRspSetHighStockStrategyRelationParam))
		.def("onRtnHighInnerFutureStrategyRelation", pure_virtual(&UserApiWrap::onRtnHighInnerFutureStrategyRelation))
		.def("onRspQryAllStrategyRelation", pure_virtual(&UserApiWrap::onRspQryAllStrategyRelation))
		.def("onRspSetAPIHighStockStrategyParam", pure_virtual(&UserApiWrap::onRspSetAPIHighStockStrategyParam))
		.def("onRspDelHighStockStrategyRelationParam", pure_virtual(&UserApiWrap::onRspDelHighStockStrategyRelationParam))
		.def("onRspDelAPIHighStockStrategyParam", pure_virtual(&UserApiWrap::onRspDelAPIHighStockStrategyParam))
		.def("onRspQryAllTradingPeriodStrategy", pure_virtual(&UserApiWrap::onRspQryAllTradingPeriodStrategy))
		.def("onRspSetTradingPeriodStrategy", pure_virtual(&UserApiWrap::onRspSetTradingPeriodStrategy))
		.def("onRspDelTradingPeriodStrategy", pure_virtual(&UserApiWrap::onRspDelTradingPeriodStrategy))
		.def("onRspQryAllInnerStrategyRelation", pure_virtual(&UserApiWrap::onRspQryAllInnerStrategyRelation))
		.def("onRspCancelAllStrategyRelationOrder", pure_virtual(&UserApiWrap::onRspCancelAllStrategyRelationOrder))
		.def("onRspSetAutoReBuySwitch", pure_virtual(&UserApiWrap::onRspSetAutoReBuySwitch))
		.def("onRspSendFutureStrategyOrder", pure_virtual(&UserApiWrap::onRspSendFutureStrategyOrder))
		.def("onRspSetAlgoParm", pure_virtual(&UserApiWrap::onRspSetAlgoParm))
		.def("onRtnInnerFutureStrategyOrder", pure_virtual(&UserApiWrap::onRtnInnerFutureStrategyOrder))
		.def("onRspQryAlgoParm", pure_virtual(&UserApiWrap::onRspQryAlgoParm))
		.def("onRspQryFutureStrategyOrder", pure_virtual(&UserApiWrap::onRspQryFutureStrategyOrder))
		.def("onRspQryInnerFutureStrategyOrder", pure_virtual(&UserApiWrap::onRspQryInnerFutureStrategyOrder))
		.def("onRspSetStragedyMessage", pure_virtual(&UserApiWrap::onRspSetStragedyMessage))
		.def("onRspQryIndexDirSignal", pure_virtual(&UserApiWrap::onRspQryIndexDirSignal))
		.def("onRspDelFutureStrategyOrder", pure_virtual(&UserApiWrap::onRspDelFutureStrategyOrder))
		.def("onRspDelAlgoParm", pure_virtual(&UserApiWrap::onRspDelAlgoParm))
		.def("onRspSetSpreadInstrStrategy", pure_virtual(&UserApiWrap::onRspSetSpreadInstrStrategy))
		.def("onRspQrySpreadInstrStrategy", pure_virtual(&UserApiWrap::onRspQrySpreadInstrStrategy))
		.def("onRspDelSpreadInstrStrategy", pure_virtual(&UserApiWrap::onRspDelSpreadInstrStrategy))
		.def("onRspQryInnerSpreadInstrStrategy", pure_virtual(&UserApiWrap::onRspQryInnerSpreadInstrStrategy))
		.def("onRtnInnerSpreadInstrStrategy", pure_virtual(&UserApiWrap::onRtnInnerSpreadInstrStrategy))
		.def("onRspSetTZeroHighStockStrategy", pure_virtual(&UserApiWrap::onRspSetTZeroHighStockStrategy))
		.def("onRspQryTZeroHighStockStrategy", pure_virtual(&UserApiWrap::onRspQryTZeroHighStockStrategy))
		.def("onRtnStragedyMessage", pure_virtual(&UserApiWrap::onRtnStragedyMessage))
		.def("onRspSetfutruetradeinstr", pure_virtual(&UserApiWrap::onRspSetfutruetradeinstr))
		.def("onRspQryFlowerFutureTargetMoney", pure_virtual(&UserApiWrap::onRspQryFlowerFutureTargetMoney))
		.def("onRspSetFlowerFutureTargetMoney", pure_virtual(&UserApiWrap::onRspSetFlowerFutureTargetMoney))
		.def("onRtnParentOrder", pure_virtual(&UserApiWrap::onRtnParentOrder))
		.def("onRtnParentOrderAction", pure_virtual(&UserApiWrap::onRtnParentOrderAction))
		.def("onRtnAmendParentOrder", pure_virtual(&UserApiWrap::onRtnAmendParentOrder))
		.def("onRtnExtraManualParentOrder", pure_virtual(&UserApiWrap::onRtnExtraManualParentOrder))
		.def("onRspQryMarketTradingTime", pure_virtual(&UserApiWrap::onRspQryMarketTradingTime))
		.def("onRspSetFutureStrategyTotalSecondRelationParam", pure_virtual(&UserApiWrap::onRspSetFutureStrategyTotalSecondRelationParam))
		.def("onRtnHighInnerFutureStrategyTotalSecondRelation", pure_virtual(&UserApiWrap::onRtnHighInnerFutureStrategyTotalSecondRelation))
		.def("onRspQryAllTotalSecondStrategyRelation", pure_virtual(&UserApiWrap::onRspQryAllTotalSecondStrategyRelation))
		.def("onRspDelHighStockStrategyTotalSecondRelationParam", pure_virtual(&UserApiWrap::onRspDelHighStockStrategyTotalSecondRelationParam))
		.def("onRspQryAllInnerTotalSecondStrategyRelation", pure_virtual(&UserApiWrap::onRspQryAllInnerTotalSecondStrategyRelation))
		.def("onRspQryParentDetialUpdateMessage", pure_virtual(&UserApiWrap::onRspQryParentDetialUpdateMessage))
		.def("onRspQryParentOrderStaticParam", pure_virtual(&UserApiWrap::onRspQryParentOrderStaticParam))
		.def("onRtnParentDetialUpdateMessage", pure_virtual(&UserApiWrap::onRtnParentDetialUpdateMessage))
		.def("onRspSetParentOrderStaticParam", pure_virtual(&UserApiWrap::onRspSetParentOrderStaticParam))
		.def("onRspDelParentOrderStaticParam", pure_virtual(&UserApiWrap::onRspDelParentOrderStaticParam))
		.def("onRspQryJavaAlgoStatus", pure_virtual(&UserApiWrap::onRspQryJavaAlgoStatus))
		.def("onRtnJavaAlgoStatus", pure_virtual(&UserApiWrap::onRtnJavaAlgoStatus))
		.def("onRspQryFuSkAccountRelation", pure_virtual(&UserApiWrap::onRspQryFuSkAccountRelation))
		.def("onRspBatchOrderInsert", pure_virtual(&UserApiWrap::onRspBatchOrderInsert))
		.def("onRspBatchOrderAction", pure_virtual(&UserApiWrap::onRspBatchOrderAction))
		.def("onRspSetUserInvestorSeatBasePasswd", pure_virtual(&UserApiWrap::onRspSetUserInvestorSeatBasePasswd))
		.def("onRtnSpreadInstrStrategy", pure_virtual(&UserApiWrap::onRtnSpreadInstrStrategy))
		.def("onRtnAmendPSpreadInstrStrategy", pure_virtual(&UserApiWrap::onRtnAmendPSpreadInstrStrategy))
		.def("onRspQryUnFinshPutureOrder", pure_virtual(&UserApiWrap::onRspQryUnFinshPutureOrder))
		.def("onRspQryTodayTayoutDetails", pure_virtual(&UserApiWrap::onRspQryTodayTayoutDetails))
		.def("reqUserLogin", &UserApiWrap::reqUserLogin)
		.def("reqUserLogout", &UserApiWrap::reqUserLogout)
		.def("reqUserPasswordUpdate", &UserApiWrap::reqUserPasswordUpdate)
		.def("reqForceUserExit", &UserApiWrap::reqForceUserExit)
		.def("reqForceUserLogout", &UserApiWrap::reqForceUserLogout)
		.def("reqDumpMemDB", &UserApiWrap::reqDumpMemDB)
		.def("reqOrderInsert", &UserApiWrap::reqOrderInsert)
		.def("reqOrderAction", &UserApiWrap::reqOrderAction)
		.def("reqAccountDeposit", &UserApiWrap::reqAccountDeposit)
		.def("reqInvestorRight", &UserApiWrap::reqInvestorRight)
		.def("reqTBCommand", &UserApiWrap::reqTBCommand)
		.def("reqPingPong", &UserApiWrap::reqPingPong)
		.def("reqSetAdviceRunMode", &UserApiWrap::reqSetAdviceRunMode)
		.def("reqSubMarketData", &UserApiWrap::reqSubMarketData)
		.def("reqUnSubMarketData", &UserApiWrap::reqUnSubMarketData)
		.def("reqTopicSearch", &UserApiWrap::reqTopicSearch)
		.def("reqQryOrder", &UserApiWrap::reqQryOrder)
		.def("reqQryTrade", &UserApiWrap::reqQryTrade)
		.def("reqQryUserInvestor", &UserApiWrap::reqQryUserInvestor)
		.def("reqQryInvestorAccount", &UserApiWrap::reqQryInvestorAccount)
		.def("reqQryInstrument", &UserApiWrap::reqQryInstrument)
		.def("reqQryExchange", &UserApiWrap::reqQryExchange)
		.def("reqQryInvestorPosition", &UserApiWrap::reqQryInvestorPosition)
		.def("reqSubscribeTopic", &UserApiWrap::reqSubscribeTopic)
		.def("reqQryTopic", &UserApiWrap::reqQryTopic)
		.def("reqQryUser", &UserApiWrap::reqQryUser)
		.def("reqQryInvestorFee", &UserApiWrap::reqQryInvestorFee)
		.def("reqQryInvestorMargin", &UserApiWrap::reqQryInvestorMargin)
		.def("reqQryInvestor", &UserApiWrap::reqQryInvestor)
		.def("reqQryAccountRisk", &UserApiWrap::reqQryAccountRisk)
		.def("reqQryUserSession", &UserApiWrap::reqQryUserSession)
		.def("reqQryMarketData", &UserApiWrap::reqQryMarketData)
		.def("reqQryInvestorRelation", &UserApiWrap::reqQryInvestorRelation)
		.def("reqQryProduct", &UserApiWrap::reqQryProduct)
		.def("reqQryAdviceTrader", &UserApiWrap::reqQryAdviceTrader)
		.def("reqQryMaxVolume", &UserApiWrap::reqQryMaxVolume)
		.def("reqQryCmbPositionDetail", &UserApiWrap::reqQryCmbPositionDetail)
		.def("reqQrySettlementInfo", &UserApiWrap::reqQrySettlementInfo)
		.def("reqSubInstrument", &UserApiWrap::reqSubInstrument)
		.def("reqUnSubInstrument", &UserApiWrap::reqUnSubInstrument)
		.def("reqQryResultPage", &UserApiWrap::reqQryResultPage)
		.def("reqQryOrderPage", &UserApiWrap::reqQryOrderPage)
		.def("reqQryTradePage", &UserApiWrap::reqQryTradePage)
		.def("reqQryInvestorPositionPage", &UserApiWrap::reqQryInvestorPositionPage)
		.def("reqQryInvestorPositionDetail", &UserApiWrap::reqQryInvestorPositionDetail)
		.def("reqSetPricingParam", &UserApiWrap::reqSetPricingParam)
		.def("reqSetOptionTheoryVol", &UserApiWrap::reqSetOptionTheoryVol)
		.def("reqCalcOneOption", &UserApiWrap::reqCalcOneOption)
		.def("reqCalcBarrierOption", &UserApiWrap::reqCalcBarrierOption)
		.def("reqMarketDataTest", &UserApiWrap::reqMarketDataTest)
		.def("reqVolatilityFitting", &UserApiWrap::reqVolatilityFitting)
		.def("reqQryWingModelParam", &UserApiWrap::reqQryWingModelParam)
		.def("reqSetWingModelParam", &UserApiWrap::reqSetWingModelParam)
		.def("reqQryMarkerStrategySet", &UserApiWrap::reqQryMarkerStrategySet)
		.def("reqUpMarkerStrategySet", &UserApiWrap::reqUpMarkerStrategySet)
		.def("reqQryUserSwitch", &UserApiWrap::reqQryUserSwitch)
		.def("reqUserSwitch", &UserApiWrap::reqUserSwitch)
		.def("reqQryMarkerHedge", &UserApiWrap::reqQryMarkerHedge)
		.def("reqUpMarkerHedge", &UserApiWrap::reqUpMarkerHedge)
		.def("reqQryFittingParam", &UserApiWrap::reqQryFittingParam)
		.def("reqSetFittingParam", &UserApiWrap::reqSetFittingParam)
		.def("reqQryPricingParam", &UserApiWrap::reqQryPricingParam)
		.def("reqQryOptionTheoryVol", &UserApiWrap::reqQryOptionTheoryVol)
		.def("reqQuoteInsert", &UserApiWrap::reqQuoteInsert)
		.def("reqQuoteAction", &UserApiWrap::reqQuoteAction)
		.def("reqQryQuote", &UserApiWrap::reqQryQuote)
		.def("reqForQuote", &UserApiWrap::reqForQuote)
		.def("reqQryOrderInsertFailed", &UserApiWrap::reqQryOrderInsertFailed)
		.def("reqCleanQuoteThresHold", &UserApiWrap::reqCleanQuoteThresHold)
		.def("reqSetPriceSpread", &UserApiWrap::reqSetPriceSpread)
		.def("reqQryPriceSpread", &UserApiWrap::reqQryPriceSpread)
		.def("reqDelPricingParam", &UserApiWrap::reqDelPricingParam)
		.def("reqDelMarkerStrategySet", &UserApiWrap::reqDelMarkerStrategySet)
		.def("reqSetAlertParam", &UserApiWrap::reqSetAlertParam)
		.def("reqQryAlertParam", &UserApiWrap::reqQryAlertParam)
		.def("reqQryAlertData", &UserApiWrap::reqQryAlertData)
		.def("reqDelOptionTheoryVol", &UserApiWrap::reqDelOptionTheoryVol)
		.def("reqDelMarkerHedge", &UserApiWrap::reqDelMarkerHedge)
		.def("reqSetMarkerStep", &UserApiWrap::reqSetMarkerStep)
		.def("reqDelMarkerStep", &UserApiWrap::reqDelMarkerStep)
		.def("reqDelAlertParam", &UserApiWrap::reqDelAlertParam)
		.def("reqSetQuoteMove", &UserApiWrap::reqSetQuoteMove)
		.def("reqDelQuoteMove", &UserApiWrap::reqDelQuoteMove)
		.def("reqRebackQuote", &UserApiWrap::reqRebackQuote)
		.def("reqQryDepMarketData", &UserApiWrap::reqQryDepMarketData)
		.def("reqQryQuoteMove", &UserApiWrap::reqQryQuoteMove)
		.def("reqQryBaseMarkerStep", &UserApiWrap::reqQryBaseMarkerStep)
		.def("reqQryMarkerStep", &UserApiWrap::reqQryMarkerStep)
		.def("reqFocusStatus", &UserApiWrap::reqFocusStatus)
		.def("reqSetFutureMakerWholeSwitch", &UserApiWrap::reqSetFutureMakerWholeSwitch)
		.def("reqSetFutureMakerStrategy", &UserApiWrap::reqSetFutureMakerStrategy)
		.def("reqSetSlefHedgeStrategy", &UserApiWrap::reqSetSlefHedgeStrategy)
		.def("reqSetFutureHedgeStrategy", &UserApiWrap::reqSetFutureHedgeStrategy)
		.def("reqSetQuoteAdditionParm", &UserApiWrap::reqSetQuoteAdditionParm)
		.def("reqStopAllFutureMakerHedgeOffer", &UserApiWrap::reqStopAllFutureMakerHedgeOffer)
		.def("reqQryFutureMakerStrategy", &UserApiWrap::reqQryFutureMakerStrategy)
		.def("reqQryAllInnerHighStockStrategy", &UserApiWrap::reqQryAllInnerHighStockStrategy)
		.def("reqSetHighStockStrategySwitch", &UserApiWrap::reqSetHighStockStrategySwitch)
		.def("reqQryAllAPIHighStockStrategy", &UserApiWrap::reqQryAllAPIHighStockStrategy)
		.def("reqQrySignalAPIHighStockStrategy", &UserApiWrap::reqQrySignalAPIHighStockStrategy)
		.def("reqSetSignalHighStockStrategySwitch", &UserApiWrap::reqSetSignalHighStockStrategySwitch)
		.def("reqSetHighStockStrategyRelationParam", &UserApiWrap::reqSetHighStockStrategyRelationParam)
		.def("reqQryAllStrategyRelation", &UserApiWrap::reqQryAllStrategyRelation)
		.def("reqSetAPIHighStockStrategyParam", &UserApiWrap::reqSetAPIHighStockStrategyParam)
		.def("reqDelHighStockStrategyRelationParam", &UserApiWrap::reqDelHighStockStrategyRelationParam)
		.def("reqDelAPIHighStockStrategyParam", &UserApiWrap::reqDelAPIHighStockStrategyParam)
		.def("reqQryAllTradingPeriodStrategy", &UserApiWrap::reqQryAllTradingPeriodStrategy)
		.def("reqSetTradingPeriodStrategy", &UserApiWrap::reqSetTradingPeriodStrategy)
		.def("reqDelTradingPeriodStrategy", &UserApiWrap::reqDelTradingPeriodStrategy)
		.def("reqQryAllInnerStrategyRelation", &UserApiWrap::reqQryAllInnerStrategyRelation)
		.def("reqCancelAllStrategyRelationOrder", &UserApiWrap::reqCancelAllStrategyRelationOrder)
		.def("reqSetAutoReBuySwitch", &UserApiWrap::reqSetAutoReBuySwitch)
		.def("reqSendFutureStrategyOrder", &UserApiWrap::reqSendFutureStrategyOrder)
		.def("reqSetAlgoParm", &UserApiWrap::reqSetAlgoParm)
		.def("reqQryAlgoParm", &UserApiWrap::reqQryAlgoParm)
		.def("reqQryFutureStrategyOrder", &UserApiWrap::reqQryFutureStrategyOrder)
		.def("reqQryInnerFutureStrategyOrder", &UserApiWrap::reqQryInnerFutureStrategyOrder)
		.def("reqSetStragedyMessage", &UserApiWrap::reqSetStragedyMessage)
		.def("reqQryIndexDirSignal", &UserApiWrap::reqQryIndexDirSignal)
		.def("reqDelFutureStrategyOrder", &UserApiWrap::reqDelFutureStrategyOrder)
		.def("reqDelAlgoParm", &UserApiWrap::reqDelAlgoParm)
		.def("reqSetSpreadInstrStrategy", &UserApiWrap::reqSetSpreadInstrStrategy)
		.def("reqQrySpreadInstrStrategy", &UserApiWrap::reqQrySpreadInstrStrategy)
		.def("reqDelSpreadInstrStrategy", &UserApiWrap::reqDelSpreadInstrStrategy)
		.def("reqQryInnerSpreadInstrStrategy", &UserApiWrap::reqQryInnerSpreadInstrStrategy)
		.def("reqSetTZeroHighStockStrategy", &UserApiWrap::reqSetTZeroHighStockStrategy)
		.def("reqQryTZeroHighStockStrategy", &UserApiWrap::reqQryTZeroHighStockStrategy)
		.def("reqSetfutruetradeinstr", &UserApiWrap::reqSetfutruetradeinstr)
		.def("reqQryFlowerFutureTargetMoney", &UserApiWrap::reqQryFlowerFutureTargetMoney)
		.def("reqSetFlowerFutureTargetMoney", &UserApiWrap::reqSetFlowerFutureTargetMoney)
		.def("reqSetParentDetialUpdateMessage", &UserApiWrap::reqSetParentDetialUpdateMessage)
		.def("reqQryMarketTradingTime", &UserApiWrap::reqQryMarketTradingTime)
		.def("reqSetFutureStrategyTotalSecondRelationParam", &UserApiWrap::reqSetFutureStrategyTotalSecondRelationParam)
		.def("reqQryAllTotalSecondStrategyRelation", &UserApiWrap::reqQryAllTotalSecondStrategyRelation)
		.def("reqDelHighStockStrategyTotalSecondRelationParam", &UserApiWrap::reqDelHighStockStrategyTotalSecondRelationParam)
		.def("reqQryAllInnerTotalSecondStrategyRelation", &UserApiWrap::reqQryAllInnerTotalSecondStrategyRelation)
		.def("reqQryParentDetialUpdateMessage", &UserApiWrap::reqQryParentDetialUpdateMessage)
		.def("reqQryParentOrderStaticParam", &UserApiWrap::reqQryParentOrderStaticParam)
		.def("reqSetParentOrderStaticParam", &UserApiWrap::reqSetParentOrderStaticParam)
		.def("reqDelParentOrderStaticParam", &UserApiWrap::reqDelParentOrderStaticParam)
		.def("reqQryJavaAlgoStatus", &UserApiWrap::reqQryJavaAlgoStatus)
		.def("reqSetJavaAlgoStatus", &UserApiWrap::reqSetJavaAlgoStatus)
		.def("reqQryFuSkAccountRelation", &UserApiWrap::reqQryFuSkAccountRelation)
		.def("reqBatchOrderInsert", &UserApiWrap::reqBatchOrderInsert)
		.def("reqBatchOrderAction", &UserApiWrap::reqBatchOrderAction)
		.def("reqSetUserInvestorSeatBasePasswd", &UserApiWrap::reqSetUserInvestorSeatBasePasswd)
		.def("reqQryUnFinshPutureOrder", &UserApiWrap::reqQryUnFinshPutureOrder)
		.def("reqQryTodayTayoutDetails", &UserApiWrap::reqQryTodayTayoutDetails)

		;
}
