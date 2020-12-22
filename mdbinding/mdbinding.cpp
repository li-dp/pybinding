// mdbinding.cpp : 定义 DLL 应用程序的导出函数。
//

#include "mdbinding.h"

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
};

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
};

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
};

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
};


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------
void MdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void MdApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nReason;
	this->task_queue.push(task);
};

void MdApi::OnHeartBeatWarning(int nTimeLapse)
{
	Task task = Task();
	task.task_name = ONHEARTBEATWARNING;
	task.task_id = nTimeLapse;
	this->task_queue.push(task);
};

void MdApi::OnRspError(CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPERROR;

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspUserLogin(CQdFtdcRspUserLoginField *pRspUserLogin, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;

	if (pRspUserLogin)
	{
		task.task_data = *pRspUserLogin;
	}
	else
	{
		CQdFtdcRspUserLoginField empty_data = CQdFtdcRspUserLoginField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspUserLogout(CQdFtdcRspUserLogoutField *pRspUserLogout, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGOUT;

	if (pRspUserLogout)
	{
		task.task_data = *pRspUserLogout;
	}
	else
	{
		CQdFtdcRspUserLogoutField empty_data = CQdFtdcRspUserLogoutField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnDepthMarketData(CQdFtdcDepthMarketDataField *pDepthMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNDEPTHMARKETDATA;

	if (pDepthMarketData)
	{
		task.task_data = *pDepthMarketData;
	}
	else
	{
		CQdFtdcDepthMarketDataField empty_data = CQdFtdcDepthMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnMultiDepthMarketData(CQdFtdcDepthMarketDataField *pDepthMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNMULTIDEPTHMARKETDATA;

	if (pDepthMarketData)
	{
		task.task_data = *pDepthMarketData;
	}
	else
	{
		CQdFtdcDepthMarketDataField empty_data = CQdFtdcDepthMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubMarketData(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSUBMARKETDATA;

	if (pSpecificInstrument)
	{
		task.task_data = *pSpecificInstrument;
	}
	else
	{
		CQdFtdcSpecificInstrumentField empty_data = CQdFtdcSpecificInstrumentField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubMarketData(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBMARKETDATA;

	if (pSpecificInstrument)
	{
		task.task_data = *pSpecificInstrument;
	}
	else
	{
		CQdFtdcSpecificInstrumentField empty_data = CQdFtdcSpecificInstrumentField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnMBLMarketData(CQdFtdcMBLMarketDataField *pMBLMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNMBLMARKETDATA;

	if (pMBLMarketData)
	{
		task.task_data = *pMBLMarketData;
	}
	else
	{
		CQdFtdcMBLMarketDataField empty_data = CQdFtdcMBLMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnQmdInstrumentStatu(CQdFtdcQmdInstrumentStateField *pQmdInstrumentState) 
{
	Task task = Task();
	task.task_name = ONRTNQMDINSTRUMENTSTATU;

	if (pQmdInstrumentState)
	{
		task.task_data = *pQmdInstrumentState;
	}
	else
	{
		CQdFtdcQmdInstrumentStateField empty_data = CQdFtdcQmdInstrumentStateField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubscribeTopic(CQdFtdcDisseminationField *pDissemination, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSCRIBETOPIC;

	if (pDissemination)
	{
		task.task_data = *pDissemination;
	}
	else
	{
		CQdFtdcDisseminationField empty_data = CQdFtdcDisseminationField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspQryTopic(CQdFtdcDisseminationField *pDissemination, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTOPIC;

	if (pDissemination)
	{
		task.task_data = *pDissemination;
	}
	else
	{
		CQdFtdcDisseminationField empty_data = CQdFtdcDisseminationField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspQryMarketData(CQdFtdcRspMarketDataField *pRspMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKETDATA;

	if (pRspMarketData)
	{
		task.task_data = *pRspMarketData;
	}
	else
	{
		CQdFtdcRspMarketDataField empty_data = CQdFtdcRspMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspQryInstrumentList(CQdFtdcSpecificInstrumentField *pSpecificInstrument, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINSTRUMENTLIST;

	if (pSpecificInstrument)
	{
		task.task_data = *pSpecificInstrument;
	}
	else
	{
		CQdFtdcSpecificInstrumentField empty_data = CQdFtdcSpecificInstrumentField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnTenEntrust(CQdFtdcMDTenDepthMarketDataField *pMDTenDepthMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNTENENTRUST;

	if (pMDTenDepthMarketData)
	{
		task.task_data = *pMDTenDepthMarketData;
	}
	else
	{
		CQdFtdcMDTenDepthMarketDataField empty_data = CQdFtdcMDTenDepthMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnOptionIndexData(CQdFtdcOptionIndexDataField *pOptionIndexData) 
{
	Task task = Task();
	task.task_name = ONRTNOPTIONINDEXDATA;

	if (pOptionIndexData)
	{
		task.task_data = *pOptionIndexData;
	}
	else
	{
		CQdFtdcOptionIndexDataField empty_data = CQdFtdcOptionIndexDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnDepthMinMarketData(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNDEPTHMINMARKETDATA;

	if (pDeptMinMarketData)
	{
		task.task_data = *pDeptMinMarketData;
	}
	else
	{
		CQdFtdcDeptMinMarketDataField empty_data = CQdFtdcDeptMinMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspQryMinMarketData(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMINMARKETDATA;

	if (pDeptMinMarketData)
	{
		task.task_data = *pDeptMinMarketData;
	}
	else
	{
		CQdFtdcDeptMinMarketDataField empty_data = CQdFtdcDeptMinMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnDepthOneMinBarSlice(CQdFtdcDeptMinMarketDataField *pDeptMinMarketData) 
{
	Task task = Task();
	task.task_name = ONRTNDEPTHONEMINBARSLICE;

	if (pDeptMinMarketData)
	{
		task.task_data = *pDeptMinMarketData;
	}
	else
	{
		CQdFtdcDeptMinMarketDataField empty_data = CQdFtdcDeptMinMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspQryStInstrument(CQdFtdcQryMarketDataField *pQryMarketData, CQdFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYSTINSTRUMENT;

	if (pQryMarketData)
	{
		task.task_data = *pQryMarketData;
	}
	else
	{
		CQdFtdcQryMarketDataField empty_data = CQdFtdcQryMarketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}

	if (pRspInfo)
	{
		task.task_error = *pRspInfo;
	}
	else
	{
		CQdFtdcRspInfoField empty_error = CQdFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(empty_error));
		task.task_error = empty_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnTradeMaketData(CQdFtdcDeptTradeMaketDataField *pDeptTradeMaketData) 
{
	Task task = Task();
	task.task_name = ONRTNTRADEMAKETDATA;

	if (pDeptTradeMaketData)
	{
		task.task_data = *pDeptTradeMaketData;
	}
	else
	{
		CQdFtdcDeptTradeMaketDataField empty_data = CQdFtdcDeptTradeMaketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnOrderMaketData(CQdFtdcDeptOrderMaketDataField *pDeptOrderMaketData) 
{
	Task task = Task();
	task.task_name = ONRTNORDERMAKETDATA;

	if (pDeptOrderMaketData)
	{
		task.task_data = *pDeptOrderMaketData;
	}
	else
	{
		CQdFtdcDeptOrderMaketDataField empty_data = CQdFtdcDeptOrderMaketDataField();
		memset(&empty_data, 0, sizeof(empty_data));
		task.task_data = empty_data;
	}
	this->task_queue.push(task);
};



///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void MdApi::processTask()
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

		case ONRSPQRYMARKETDATA:
		{
			this->processRspQryMarketData(task);
			break;
		}

		case ONRSPQRYINSTRUMENTLIST:
		{
			this->processRspQryInstrumentList(task);
			break;
		}

		case ONRTNTENENTRUST:
		{
			this->processRtnTenEntrust(task);
			break;
		}

		case ONRTNOPTIONINDEXDATA:
		{
			this->processRtnOptionIndexData(task);
			break;
		}

		case ONRTNDEPTHMINMARKETDATA:
		{
			this->processRtnDepthMinMarketData(task);
			break;
		}

		case ONRSPQRYMINMARKETDATA:
		{
			this->processRspQryMinMarketData(task);
			break;
		}

		case ONRTNDEPTHONEMINBARSLICE:
		{
			this->processRtnDepthOneMinBarSlice(task);
			break;
		}

		case ONRSPQRYSTINSTRUMENT:
		{
			this->processRspQryStInstrument(task);
			break;
		}

		case ONRTNTRADEMAKETDATA:
		{
			this->processRtnTradeMaketData(task);
			break;
		}

		case ONRTNORDERMAKETDATA:
		{
			this->processRtnOrderMaketData(task);
			break;
		}


		};
	}
};

void MdApi::processFrontConnected(Task task)
{
	PyLock lock;
	this->onFrontConnected();
};

void MdApi::processFrontDisconnected(Task task)
{
	PyLock lock;
	this->onFrontDisconnected(task.task_id);
};

void MdApi::processHeartBeatWarning(Task task)
{
	PyLock lock;
	this->onHeartBeatWarning(task.task_id);
};

void MdApi::processRspError(Task task)
{
	PyLock lock;
	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspError(error, task.task_id, task.task_last);
};

void MdApi::processRspUserLogin(Task task)
{
	PyLock lock;
	CQdFtdcRspUserLoginField task_data = any_cast<CQdFtdcRspUserLoginField>(task.task_data);
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

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUserLogin(data, error, task.task_id, task.task_last);
};

void MdApi::processRspUserLogout(Task task)
{
	PyLock lock;
	CQdFtdcRspUserLogoutField task_data = any_cast<CQdFtdcRspUserLogoutField>(task.task_data);
	dict data;
	data["BrokerID"] = task_data.BrokerID;
	data["UserID"] = task_data.UserID;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUserLogout(data, error, task.task_id, task.task_last);
};

void MdApi::processRtnDepthMarketData(Task task)
{
	PyLock lock;
	CQdFtdcDepthMarketDataField task_data = any_cast<CQdFtdcDepthMarketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["PreDelta"] = task_data.PreDelta;
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
	data["NumberVloume"] = task_data.NumberVloume;
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
	data["BidPrice6"] = task_data.BidPrice6;
	data["BidVolume6"] = task_data.BidVolume6;
	data["BidPrice7"] = task_data.BidPrice7;
	data["BidVolume7"] = task_data.BidVolume7;
	data["AskPrice6"] = task_data.AskPrice6;
	data["AskVolume6"] = task_data.AskVolume6;
	data["AskPrice7"] = task_data.AskPrice7;
	data["AskVolume7"] = task_data.AskVolume7;
	data["BidPrice8"] = task_data.BidPrice8;
	data["BidVolume8"] = task_data.BidVolume8;
	data["BidPrice9"] = task_data.BidPrice9;
	data["BidVolume9"] = task_data.BidVolume9;
	data["AskPrice8"] = task_data.AskPrice8;
	data["AskVolume8"] = task_data.AskVolume8;
	data["AskPrice9"] = task_data.AskPrice9;
	data["AskVolume9"] = task_data.AskVolume9;
	data["BidPrice10"] = task_data.BidPrice10;
	data["BidVolume10"] = task_data.BidVolume10;
	data["AskPrice10"] = task_data.AskPrice10;
	data["AskVolume10"] = task_data.AskVolume10;
	data["InstrumentID"] = task_data.InstrumentID;
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;
	data["ExchangeID"] = task_data.ExchangeID;
	data["VolumeAskLot"] = task_data.VolumeAskLot;
	data["VolumeBidLot"] = task_data.VolumeBidLot;
	data["WeightAvgBidPx"] = task_data.WeightAvgBidPx;
	data["WeightAvgSellPx"] = task_data.WeightAvgSellPx;
	data["InstrumentStatus"] = task_data.InstrumentStatus;
	data["CalendarDate"] = task_data.CalendarDate;

	this->onRtnDepthMarketData(data);
};

void MdApi::processRtnMultiDepthMarketData(Task task)
{
	PyLock lock;
	CQdFtdcDepthMarketDataField task_data = any_cast<CQdFtdcDepthMarketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["PreDelta"] = task_data.PreDelta;
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
	data["NumberVloume"] = task_data.NumberVloume;
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
	data["BidPrice6"] = task_data.BidPrice6;
	data["BidVolume6"] = task_data.BidVolume6;
	data["BidPrice7"] = task_data.BidPrice7;
	data["BidVolume7"] = task_data.BidVolume7;
	data["AskPrice6"] = task_data.AskPrice6;
	data["AskVolume6"] = task_data.AskVolume6;
	data["AskPrice7"] = task_data.AskPrice7;
	data["AskVolume7"] = task_data.AskVolume7;
	data["BidPrice8"] = task_data.BidPrice8;
	data["BidVolume8"] = task_data.BidVolume8;
	data["BidPrice9"] = task_data.BidPrice9;
	data["BidVolume9"] = task_data.BidVolume9;
	data["AskPrice8"] = task_data.AskPrice8;
	data["AskVolume8"] = task_data.AskVolume8;
	data["AskPrice9"] = task_data.AskPrice9;
	data["AskVolume9"] = task_data.AskVolume9;
	data["BidPrice10"] = task_data.BidPrice10;
	data["BidVolume10"] = task_data.BidVolume10;
	data["AskPrice10"] = task_data.AskPrice10;
	data["AskVolume10"] = task_data.AskVolume10;
	data["InstrumentID"] = task_data.InstrumentID;
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;
	data["ExchangeID"] = task_data.ExchangeID;
	data["VolumeAskLot"] = task_data.VolumeAskLot;
	data["VolumeBidLot"] = task_data.VolumeBidLot;
	data["WeightAvgBidPx"] = task_data.WeightAvgBidPx;
	data["WeightAvgSellPx"] = task_data.WeightAvgSellPx;
	data["InstrumentStatus"] = task_data.InstrumentStatus;
	data["CalendarDate"] = task_data.CalendarDate;

	this->onRtnMultiDepthMarketData(data);
};

void MdApi::processRspSubMarketData(Task task)
{
	PyLock lock;
	CQdFtdcSpecificInstrumentField task_data = any_cast<CQdFtdcSpecificInstrumentField>(task.task_data);
	dict data;
	data["InstrumentID"] = task_data.InstrumentID;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSubMarketData(data, error, task.task_id, task.task_last);
};

void MdApi::processRspUnSubMarketData(Task task)
{
	PyLock lock;
	CQdFtdcSpecificInstrumentField task_data = any_cast<CQdFtdcSpecificInstrumentField>(task.task_data);
	dict data;
	data["InstrumentID"] = task_data.InstrumentID;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspUnSubMarketData(data, error, task.task_id, task.task_last);
};

void MdApi::processRtnMBLMarketData(Task task)
{
	PyLock lock;
	CQdFtdcMBLMarketDataField task_data = any_cast<CQdFtdcMBLMarketDataField>(task.task_data);
	dict data;
	data["InstrumentID"] = task_data.InstrumentID;
	data["Direction"] = task_data.Direction;
	data["Price"] = task_data.Price;
	data["Volume"] = task_data.Volume;
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;

	this->onRtnMBLMarketData(data);
};

void MdApi::processRtnQmdInstrumentStatu(Task task)
{
	PyLock lock;
	CQdFtdcQmdInstrumentStateField task_data = any_cast<CQdFtdcQmdInstrumentStateField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["InstrumentStatus"] = task_data.InstrumentStatus;

	this->onRtnQmdInstrumentStatu(data);
};

void MdApi::processRspSubscribeTopic(Task task)
{
	PyLock lock;
	CQdFtdcDisseminationField task_data = any_cast<CQdFtdcDisseminationField>(task.task_data);
	dict data;
	data["SequenceSeries"] = task_data.SequenceSeries;
	data["SequenceNo"] = task_data.SequenceNo;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspSubscribeTopic(data, error, task.task_id, task.task_last);
};

void MdApi::processRspQryTopic(Task task)
{
	PyLock lock;
	CQdFtdcDisseminationField task_data = any_cast<CQdFtdcDisseminationField>(task.task_data);
	dict data;
	data["SequenceSeries"] = task_data.SequenceSeries;
	data["SequenceNo"] = task_data.SequenceNo;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryTopic(data, error, task.task_id, task.task_last);
};

void MdApi::processRspQryMarketData(Task task)
{
	PyLock lock;
	CQdFtdcRspMarketDataField task_data = any_cast<CQdFtdcRspMarketDataField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["TradingDay"] = task_data.TradingDay;
	data["PreSettlementPrice"] = task_data.PreSettlementPrice;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["PreDelta"] = task_data.PreDelta;
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
	data["NumberVloume"] = task_data.NumberVloume;
	data["Turnover"] = task_data.Turnover;
	data["OpenInterest"] = task_data.OpenInterest;
	data["BidPrice1"] = task_data.BidPrice1;
	data["BidVolume1"] = task_data.BidVolume1;
	data["AskPrice1"] = task_data.AskPrice1;
	data["AskVolume1"] = task_data.AskVolume1;
	data["InstrumentID"] = task_data.InstrumentID;
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;
	data["InstrumentStatus"] = task_data.InstrumentStatus;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMarketData(data, error, task.task_id, task.task_last);
};

void MdApi::processRspQryInstrumentList(Task task)
{
	PyLock lock;
	CQdFtdcSpecificInstrumentField task_data = any_cast<CQdFtdcSpecificInstrumentField>(task.task_data);
	dict data;
	data["InstrumentID"] = task_data.InstrumentID;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryInstrumentList(data, error, task.task_id, task.task_last);
};

void MdApi::processRtnTenEntrust(Task task)
{
	PyLock lock;
	CQdFtdcMDTenDepthMarketDataField task_data = any_cast<CQdFtdcMDTenDepthMarketDataField>(task.task_data);
	dict data;
	data["InstrumentID"] = task_data.InstrumentID;
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;
	data["BestBuyOrderPrice"] = task_data.BestBuyOrderPrice;
	data["BestBuyOrderQtyOne"] = task_data.BestBuyOrderQtyOne;
	data["BestBuyOrderQtyTwo"] = task_data.BestBuyOrderQtyTwo;
	data["BestBuyOrderQtyThree"] = task_data.BestBuyOrderQtyThree;
	data["BestBuyOrderQtyFour"] = task_data.BestBuyOrderQtyFour;
	data["BestBuyOrderQtyFive"] = task_data.BestBuyOrderQtyFive;
	data["BestBuyOrderQtySix"] = task_data.BestBuyOrderQtySix;
	data["BestBuyOrderQtySeven"] = task_data.BestBuyOrderQtySeven;
	data["BestBuyOrderQtyEight"] = task_data.BestBuyOrderQtyEight;
	data["BestBuyOrderQtyNine"] = task_data.BestBuyOrderQtyNine;
	data["BestBuyOrderQtyTen"] = task_data.BestBuyOrderQtyTen;
	data["BestSellOrderPrice"] = task_data.BestSellOrderPrice;
	data["BestSellOrderQtyOne"] = task_data.BestSellOrderQtyOne;
	data["BestSellOrderQtyTwo"] = task_data.BestSellOrderQtyTwo;
	data["BestSellOrderQtyThree"] = task_data.BestSellOrderQtyThree;
	data["BestSellOrderQtyFour"] = task_data.BestSellOrderQtyFour;
	data["BestSellOrderQtyFive"] = task_data.BestSellOrderQtyFive;
	data["BestSellOrderQtySix"] = task_data.BestSellOrderQtySix;
	data["BestSellOrderQtySeven"] = task_data.BestSellOrderQtySeven;
	data["BestSellOrderQtyEight"] = task_data.BestSellOrderQtyEight;
	data["BestSellOrderQtyNine"] = task_data.BestSellOrderQtyNine;
	data["BestSellOrderQtyTen"] = task_data.BestSellOrderQtyTen;
	data["ExchangeID"] = task_data.ExchangeID;

	this->onRtnTenEntrust(data);
};

void MdApi::processRtnOptionIndexData(Task task)
{
	PyLock lock;
	CQdFtdcOptionIndexDataField task_data = any_cast<CQdFtdcOptionIndexDataField>(task.task_data);
	dict data;
	data["InstrumentID"] = task_data.InstrumentID;
	data["UpdateTime"] = task_data.UpdateTime;
	data["UpdateMillisec"] = task_data.UpdateMillisec;
	data["ExchangeID"] = task_data.ExchangeID;
	data["TradingDay"] = task_data.TradingDay;
	data["UserID"] = task_data.UserID;
	data["IsManalSetVol"] = task_data.IsManalSetVol;
	data["UnderlyingLastPrice"] = task_data.UnderlyingLastPrice;
	data["LastPrice"] = task_data.LastPrice;
	data["TheoryVol"] = task_data.TheoryVol;
	data["UnderlyingBidPrice1"] = task_data.UnderlyingBidPrice1;
	data["BidPrice1"] = task_data.BidPrice1;
	data["UnderlyingAskPrice1"] = task_data.UnderlyingAskPrice1;
	data["AskPrice1"] = task_data.AskPrice1;
	data["RemainDay"] = task_data.RemainDay;
	data["AskVol"] = task_data.AskVol;
	data["BidVol"] = task_data.BidVol;
	data["LastVol"] = task_data.LastVol;
	data["MidVol"] = task_data.MidVol;
	data["Delta"] = task_data.Delta;
	data["Gamma"] = task_data.Gamma;
	data["Vega"] = task_data.Vega;
	data["Theta"] = task_data.Theta;
	data["Rho"] = task_data.Rho;

	this->onRtnOptionIndexData(data);
};

void MdApi::processRtnDepthMinMarketData(Task task)
{
	PyLock lock;
	CQdFtdcDeptMinMarketDataField task_data = any_cast<CQdFtdcDeptMinMarketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["OpenPrice"] = task_data.OpenPrice;
	data["HighestPrice"] = task_data.HighestPrice;
	data["LowestPrice"] = task_data.LowestPrice;
	data["LastPrice"] = task_data.LastPrice;
	data["ClosePrice"] = task_data.ClosePrice;
	data["Volume"] = task_data.Volume;
	data["Turnover"] = task_data.Turnover;
	data["OpenInterest"] = task_data.OpenInterest;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["UpdateTime"] = task_data.UpdateTime;
	data["TickOpenPrice"] = task_data.TickOpenPrice;
	data["TickPreClosePrice"] = task_data.TickPreClosePrice;
	data["TickUpdateTime"] = task_data.TickUpdateTime;
	data["InstrumentStatus"] = task_data.InstrumentStatus;

	this->onRtnDepthMinMarketData(data);
};

void MdApi::processRspQryMinMarketData(Task task)
{
	PyLock lock;
	CQdFtdcDeptMinMarketDataField task_data = any_cast<CQdFtdcDeptMinMarketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["OpenPrice"] = task_data.OpenPrice;
	data["HighestPrice"] = task_data.HighestPrice;
	data["LowestPrice"] = task_data.LowestPrice;
	data["LastPrice"] = task_data.LastPrice;
	data["ClosePrice"] = task_data.ClosePrice;
	data["Volume"] = task_data.Volume;
	data["Turnover"] = task_data.Turnover;
	data["OpenInterest"] = task_data.OpenInterest;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["UpdateTime"] = task_data.UpdateTime;
	data["TickOpenPrice"] = task_data.TickOpenPrice;
	data["TickPreClosePrice"] = task_data.TickPreClosePrice;
	data["TickUpdateTime"] = task_data.TickUpdateTime;
	data["InstrumentStatus"] = task_data.InstrumentStatus;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryMinMarketData(data, error, task.task_id, task.task_last);
};

void MdApi::processRtnDepthOneMinBarSlice(Task task)
{
	PyLock lock;
	CQdFtdcDeptMinMarketDataField task_data = any_cast<CQdFtdcDeptMinMarketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["PreClosePrice"] = task_data.PreClosePrice;
	data["PreOpenInterest"] = task_data.PreOpenInterest;
	data["OpenPrice"] = task_data.OpenPrice;
	data["HighestPrice"] = task_data.HighestPrice;
	data["LowestPrice"] = task_data.LowestPrice;
	data["LastPrice"] = task_data.LastPrice;
	data["ClosePrice"] = task_data.ClosePrice;
	data["Volume"] = task_data.Volume;
	data["Turnover"] = task_data.Turnover;
	data["OpenInterest"] = task_data.OpenInterest;
	data["UpperLimitPrice"] = task_data.UpperLimitPrice;
	data["LowerLimitPrice"] = task_data.LowerLimitPrice;
	data["UpdateTime"] = task_data.UpdateTime;
	data["TickOpenPrice"] = task_data.TickOpenPrice;
	data["TickPreClosePrice"] = task_data.TickPreClosePrice;
	data["TickUpdateTime"] = task_data.TickUpdateTime;
	data["InstrumentStatus"] = task_data.InstrumentStatus;

	this->onRtnDepthOneMinBarSlice(data);
};

void MdApi::processRspQryStInstrument(Task task)
{
	PyLock lock;
	CQdFtdcQryMarketDataField task_data = any_cast<CQdFtdcQryMarketDataField>(task.task_data);
	dict data;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;

	CQdFtdcRspInfoField task_error = any_cast<CQdFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"] = task_error.ErrorID;
	error["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);
	this->onRspQryStInstrument(data, error, task.task_id, task.task_last);
};

void MdApi::processRtnTradeMaketData(Task task)
{
	PyLock lock;
	CQdFtdcDeptTradeMaketDataField task_data = any_cast<CQdFtdcDeptTradeMaketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["TradeIndex"] = task_data.TradeIndex;
	data["TradePirce"] = task_data.TradePirce;
	data["TradeVolume"] = task_data.TradeVolume;
	data["TradeTurnover"] = task_data.TradeTurnover;
	data["TradeTime"] = task_data.TradeTime;
	data["TradeMillisec"] = task_data.TradeMillisec;

	this->onRtnTradeMaketData(data);
};

void MdApi::processRtnOrderMaketData(Task task)
{
	PyLock lock;
	CQdFtdcDeptOrderMaketDataField task_data = any_cast<CQdFtdcDeptOrderMaketDataField>(task.task_data);
	dict data;
	data["TradingDay"] = task_data.TradingDay;
	data["ExchangeID"] = task_data.ExchangeID;
	data["InstrumentID"] = task_data.InstrumentID;
	data["Direction"] = task_data.Direction;
	data["OrderTypeStr"] = task_data.OrderTypeStr;
	data["OrderPirce"] = task_data.OrderPirce;
	data["TradeVolume"] = task_data.TradeVolume;
	data["OrderTime"] = task_data.OrderTime;
	data["OrderMillisec"] = task_data.OrderMillisec;

	this->onRtnOrderMaketData(data);
};




///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void MdApi::createFtdcMdApi(string pszFlowPath)
{
	this->api = CQdFtdcMduserApi::CreateFtdcMduserApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
};

void MdApi::release()
{
	this->api->Release();
};

void MdApi::init()
{
	this->api->Init();
};

int MdApi::join()
{
	int i = this->api->Join();
	return i;
};

int MdApi::exit()
{
	//该函数在原生API里没有，用于安全退出API用，原生的join似乎不太稳定
	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

string MdApi::getTradingDay()
{
	string day = this->api->GetTradingDay();
	return day;
};

void MdApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};

int MdApi::subscribeMarketData(string instrumentID)
{
	char* buffer = (char*) instrumentID.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubMarketData(myreq, 1);
	return i;
};

int MdApi::unSubscribeMarketData(string instrumentID)
{
	char* buffer = (char*)instrumentID.c_str();
	char* myreq[1] = { buffer };;
	int i = this->api->UnSubMarketData(myreq, 1);
	return i;
};

void MdApi::subscribeMarketDataTopic(int nTopicID, int nResumeType)
{
	this->api->SubscribeMarketDataTopic(nTopicID, QD_TE_RESUME_TYPE(nResumeType));
};


int MdApi::reqUserLogin(dict req, int nRequestID)
{
	CQdFtdcReqUserLoginField myreq = CQdFtdcReqUserLoginField();
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

int MdApi::reqUserLogout(dict req, int nRequestID)
{
	CQdFtdcReqUserLogoutField myreq = CQdFtdcReqUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "BrokerID", myreq.BrokerID);
	getStr(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int MdApi::reqSubMarketData(dict req, int nRequestID)
{
	CQdFtdcSpecificInstrumentField myreq = CQdFtdcSpecificInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSubMarketData(&myreq, nRequestID);
	return i;
};

int MdApi::reqUnSubMarketData(dict req, int nRequestID)
{
	CQdFtdcSpecificInstrumentField myreq = CQdFtdcSpecificInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqUnSubMarketData(&myreq, nRequestID);
	return i;
};

int MdApi::reqSubscribeTopic(dict req, int nRequestID)
{
	CQdFtdcDisseminationField myreq = CQdFtdcDisseminationField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "SequenceSeries", &myreq.SequenceSeries);
	getInt(req, "SequenceNo", &myreq.SequenceNo);
	int i = this->api->ReqSubscribeTopic(&myreq, nRequestID);
	return i;
};

int MdApi::reqQryTopic(dict req, int nRequestID)
{
	CQdFtdcDisseminationField myreq = CQdFtdcDisseminationField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "SequenceSeries", &myreq.SequenceSeries);
	getInt(req, "SequenceNo", &myreq.SequenceNo);
	int i = this->api->ReqQryTopic(&myreq, nRequestID);
	return i;
};

int MdApi::reqQryMarketData(dict req, int nRequestID)
{
	CQdFtdcQryMarketDataField myreq = CQdFtdcQryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryMarketData(&myreq, nRequestID);
	return i;
};

int MdApi::reqQryInstrumentList(dict req, int nRequestID)
{
	CQdFtdcMarketDataExchangeIDField myreq = CQdFtdcMarketDataExchangeIDField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQryInstrumentList(&myreq, nRequestID);
	return i;
};

int MdApi::reqQryMinMarketData(dict req, int nRequestID)
{
	CQdFtdcQryMinMarketDataField myreq = CQdFtdcQryMinMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	getStr(req, "InstrumentID", myreq.InstrumentID);
	getStr(req, "TradingDay", myreq.TradingDay);
	getStr(req, "StartUpdateTime", myreq.StartUpdateTime);
	getStr(req, "EndUpdateTime", myreq.EndUpdateTime);
	int i = this->api->ReqQryMinMarketData(&myreq, nRequestID);
	return i;
};

int MdApi::reqQryStInstrument(dict req, int nRequestID)
{
	CQdFtdcMarketDataExchangeIDField myreq = CQdFtdcMarketDataExchangeIDField();
	memset(&myreq, 0, sizeof(myreq));
	getStr(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQryStInstrument(&myreq, nRequestID);
	return i;
};



///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

struct MdApiWrap : MdApi, wrapper < MdApi >
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

	virtual void onRspQryInstrumentList(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryInstrumentList")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnTenEntrust(dict data)
	{
		try
		{
			this->get_override("onRtnTenEntrust")(data);
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

	virtual void onRtnDepthMinMarketData(dict data)
	{
		try
		{
			this->get_override("onRtnDepthMinMarketData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryMinMarketData(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryMinMarketData")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnDepthOneMinBarSlice(dict data)
	{
		try
		{
			this->get_override("onRtnDepthOneMinBarSlice")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRspQryStInstrument(dict data, dict error, int id, bool last)
	{
		try
		{
			this->get_override("onRspQryStInstrument")(data, error, id, last);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnTradeMaketData(dict data)
	{
		try
		{
			this->get_override("onRtnTradeMaketData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};

	virtual void onRtnOrderMaketData(dict data)
	{
		try
		{
			this->get_override("onRtnOrderMaketData")(data);
		}
		catch (error_already_set const &)
		{
			std::cerr << __FILE__ << __LINE__ << std::endl;;
			PyErr_Print();
		}
	};


};


BOOST_PYTHON_MODULE(vnfemasmd)
{
	PyEval_InitThreads();	//导入时运行，保证先创建GIL

	class_<MdApiWrap, boost::noncopyable>("MdApi")
		.def("createFtdcMdApi", &MdApiWrap::createFtdcMdApi)
		.def("release", &MdApiWrap::release)
		.def("init", &MdApiWrap::init)
		.def("join", &MdApiWrap::join)
		.def("exit", &MdApiWrap::exit)
		.def("getTradingDay", &MdApiWrap::getTradingDay)
		.def("registerFront", &MdApiWrap::registerFront)
		.def("subscribeMarketDataTopic", &MdApiWrap::subscribeMarketDataTopic)
		.def("subscribeMarketData", &MdApiWrap::subscribeMarketData)
		.def("unSubscribeMarketData", &MdApiWrap::unSubscribeMarketData)
		.def("onFrontConnected", pure_virtual(&MdApiWrap::onFrontConnected))
		.def("onFrontDisconnected", pure_virtual(&MdApiWrap::onFrontDisconnected))
		.def("onHeartBeatWarning", pure_virtual(&MdApiWrap::onHeartBeatWarning))
		.def("onRspError", pure_virtual(&MdApiWrap::onRspError))
		.def("onRspUserLogin", pure_virtual(&MdApiWrap::onRspUserLogin))
		.def("onRspUserLogout", pure_virtual(&MdApiWrap::onRspUserLogout))
		.def("onRtnDepthMarketData", pure_virtual(&MdApiWrap::onRtnDepthMarketData))
		.def("onRtnMultiDepthMarketData", pure_virtual(&MdApiWrap::onRtnMultiDepthMarketData))
		.def("onRspSubMarketData", pure_virtual(&MdApiWrap::onRspSubMarketData))
		.def("onRspUnSubMarketData", pure_virtual(&MdApiWrap::onRspUnSubMarketData))
		.def("onRtnMBLMarketData", pure_virtual(&MdApiWrap::onRtnMBLMarketData))
		.def("onRtnQmdInstrumentStatu", pure_virtual(&MdApiWrap::onRtnQmdInstrumentStatu))
		.def("onRspSubscribeTopic", pure_virtual(&MdApiWrap::onRspSubscribeTopic))
		.def("onRspQryTopic", pure_virtual(&MdApiWrap::onRspQryTopic))
		.def("onRspQryMarketData", pure_virtual(&MdApiWrap::onRspQryMarketData))
		.def("onRspQryInstrumentList", pure_virtual(&MdApiWrap::onRspQryInstrumentList))
		.def("onRtnTenEntrust", pure_virtual(&MdApiWrap::onRtnTenEntrust))
		.def("onRtnOptionIndexData", pure_virtual(&MdApiWrap::onRtnOptionIndexData))
		.def("onRtnDepthMinMarketData", pure_virtual(&MdApiWrap::onRtnDepthMinMarketData))
		.def("onRspQryMinMarketData", pure_virtual(&MdApiWrap::onRspQryMinMarketData))
		.def("onRtnDepthOneMinBarSlice", pure_virtual(&MdApiWrap::onRtnDepthOneMinBarSlice))
		.def("onRspQryStInstrument", pure_virtual(&MdApiWrap::onRspQryStInstrument))
		.def("onRtnTradeMaketData", pure_virtual(&MdApiWrap::onRtnTradeMaketData))
		.def("onRtnOrderMaketData", pure_virtual(&MdApiWrap::onRtnOrderMaketData))
		.def("reqUserLogin", &MdApiWrap::reqUserLogin)
		.def("reqUserLogout", &MdApiWrap::reqUserLogout)
		.def("reqSubMarketData", &MdApiWrap::reqSubMarketData)
		.def("reqUnSubMarketData", &MdApiWrap::reqUnSubMarketData)
		.def("reqSubscribeTopic", &MdApiWrap::reqSubscribeTopic)
		.def("reqQryTopic", &MdApiWrap::reqQryTopic)
		.def("reqQryMarketData", &MdApiWrap::reqQryMarketData)
		.def("reqQryInstrumentList", &MdApiWrap::reqQryInstrumentList)
		.def("reqQryMinMarketData", &MdApiWrap::reqQryMinMarketData)
		.def("reqQryStInstrument", &MdApiWrap::reqQryStInstrument)

		;
};
