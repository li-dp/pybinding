# encoding: UTF-8

import os
import io
import traceback
import chardet
from string import Template
from femasDataStruct import structDict

_apiName = ''
headerprocess = io.StringIO()
headeron = io.StringIO()
headerfunction = io.StringIO()
headerdefine = io.StringIO()

bodyspi = io.StringIO()
bodyprocess = io.StringIO()
bodyreq = io.StringIO()
bodyswitch = io.StringIO()
bodywrap = io.StringIO()
bodyexport = io.StringIO()
define_count = 1

def processCallBack(line):
    orignalLine = line
    line = line.replace('\tvirtual void ', '')      # 删除行首的无效内容
    line = line.replace('{};\n', '')                # 删除行尾的无效内容

    content = line.split('(')
    cbName = content[0]                             # 回调函数名称

    cbArgs = content[1]                             # 回调函数参数
    if cbArgs[-1] == ' ':
        cbArgs = cbArgs.replace(') ', '')
    else:
        cbArgs = cbArgs.replace(')', '')

    cbArgsList = cbArgs.split(', ')                 # 将每个参数转化为列表

    cbArgsTypeList = []
    cbArgsValueList = []

    for arg in cbArgsList:                          # 开始处理参数
        content = arg.split(' ')
        if len(content) > 1:
            cbArgsTypeList.append(content[0])           # 参数类型列表
            cbArgsValueList.append(content[1])          # 参数数据列表

    createTask(cbName, cbArgsTypeList, cbArgsValueList, orignalLine)
    createProcess(cbName, cbArgsTypeList, cbArgsValueList)

    # 生成.h文件中的process部分
    process_line = '\tvoid process' + cbName[2:] + '(Task task);\n'
    headerprocess.write(process_line)
    headerprocess.write('\n')

    # 生成.h文件中的on部分
    On_line = orignalLine.replace('{};', ';')
    if "OnPackage" not in On_line:
        headeron.write(On_line)   # CPP实现的SPI callback

    if 'OnRspError' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(dict error, int id, bool last) {};\n'
    elif 'OnRsp' in cbName:
        if 'OnRspDSProxySubmitInfo' in cbName: # 3个参数
            on_line = '\tvirtual void on' + cbName[2:] + '(dict error, int id, bool last) {};\n'
        else: # 4个参数
            on_line = '\tvirtual void on' + cbName[2:] + '(dict data, dict error, int id, bool last) {};\n'
    elif 'OnRtn' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(dict data) {};\n'
    elif 'OnErrRtn' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(dict data, dict error) {};\n'
    elif 'OnFrontConnected' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '() {};\n'
    elif 'OnFrontDisconnected' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(int i) {};\n'
    elif 'OnQryFrontConnected' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '() {};\n'
    elif 'OnQryFrontDisconnected' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(int i) {};\n'
    elif 'OnHeartBeatWarning' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(int i) {};\n'
    elif 'OnPackage' in cbName:
        #on_line = '\tvirtual void on' + cbName[2:] + '(int topicID, int sequencdNo) {};\n'
        on_line = '' # no need too process this function
    else:
        on_line = ''

    headeron.write(on_line)   # 给python代码提供的callback
    headeron.write('\n')

    # 生成封装部分
    createWrap(cbName)


#----------------------------------------------------------------------
def createWrap(cbName):
    """在Python封装段代码中进行处理"""
    # 生成.h文件中的on部分
    if 'OnRspError' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(dict error, int id, bool last)\n'
        override_line = '("on' + cbName[2:] + '")(error, id, last);\n'
    elif 'OnRsp' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(dict data, dict error, int id, bool last)\n'
        override_line = '("on' + cbName[2:] + '")(data, error, id, last);\n'
    elif 'OnRtn' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(dict data)\n'
        override_line = '("on' + cbName[2:] + '")(data);\n'
    elif 'OnErrRtn' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(dict data, dict error)\n'
        override_line = '("on' + cbName[2:] + '")(data, error);\n'
    elif 'OnFrontDisconnected' in cbName or 'OnHeartBeatWarning' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '(int i)\n'
        override_line = '("on' + cbName[2:] + '")(i);\n'
    elif 'OnFrontConnected' in cbName:
        on_line = '\tvirtual void on' + cbName[2:] + '()\n'
        override_line = '("on' + cbName[2:] + '")();\n'
    else:
        on_line = ''

    if on_line != '':
        bodywrap.write(on_line)
        bodywrap.write('\t{\n')
        if 'onFrontConnected' in on_line or 'onFrontDisconnected' in on_line or 'onHeartBeatWarning' in on_line:
            bodywrap.write('\t\t\tPyLock lock;\n')
        bodywrap.write('\t\ttry\n')
        bodywrap.write('\t\t{\n')
        bodywrap.write('\t\t\tthis->get_override'+override_line)
        bodywrap.write('\t\t}\n')
        bodywrap.write('\t\tcatch (error_already_set const &)\n')
        bodywrap.write('\t\t{\n')
        bodywrap.write('\t\t\tstd::cerr << __FILE__ << __LINE__ << std::endl;;\n')
        bodywrap.write('\t\t\tPyErr_Print();\n')
        bodywrap.write('\t\t}\n')
        bodywrap.write('\t};\n')
        bodywrap.write('\n')

        export_line = '\t\t.def("on%s", pure_virtual(&%sWrap::on%s))\n' %(cbName[2:], _apiName, cbName[2:])
        bodyexport.write(export_line)



def createTask(cbName, cbArgsTypeList, cbArgsValueList, orignalLine):
    # 从回调函数生成任务对象，并放入队列
    funcline = orignalLine.replace('\tvirtual void ', 'void ' + _apiName + '::')
    funcline = funcline.replace('{};', '')

    bodyspi.write(funcline)
    bodyspi.write('{\n')
    bodyspi.write("\tTask task = Task();\n")

    bodyspi.write("\ttask.task_name = " + cbName.upper() + ";\n")

    # define常量
    global define_count
    headerdefine.write("#define " + cbName.upper() + ' ' + str(define_count) + '\n')
    define_count = define_count + 1

    # switch段代码
    bodyswitch.write("\t\tcase " + cbName.upper() + ':\n')
    bodyswitch.write("\t\t{\n")
    bodyswitch.write("\t\t\tthis->" + cbName.replace('On', 'process') + '(task);\n')
    bodyswitch.write("\t\t\tbreak;\n")
    bodyswitch.write("\t\t}\n")
    bodyswitch.write("\n")

    for i, type_ in enumerate(cbArgsTypeList):
        if type_ == 'int':
            bodyspi.write("\ttask.task_id = " + cbArgsValueList[i] + ";\n")
        elif type_ == 'bool':
            bodyspi.write("\ttask.task_last = " + cbArgsValueList[i] + ";\n")
        elif 'RspInfoField' in type_:
            bodyspi.write("\n")
            bodyspi.write("\tif (pRspInfo)\n")
            bodyspi.write("\t{\n")
            bodyspi.write("\t\ttask.task_error = " + cbArgsValueList[i] + ";\n")
            bodyspi.write("\t}\n")
            bodyspi.write("\telse\n")
            bodyspi.write("\t{\n")
            bodyspi.write("\t\tCUstpFtdcRspInfoField empty_error = CUstpFtdcRspInfoField();\n")
            bodyspi.write("\t\tmemset(&empty_error, 0, sizeof(empty_error));\n")
            bodyspi.write("\t\ttask.task_error = empty_error;\n")
            bodyspi.write("\t}\n")
        else:
            bodyspi.write("\n")
            bodyspi.write("\tif (" + cbArgsValueList[i][1:] + ")\n")
            bodyspi.write("\t{\n")
            bodyspi.write("\t\ttask.task_data = " + cbArgsValueList[i] + ";\n")
            bodyspi.write("\t}\n")
            bodyspi.write("\telse\n")
            bodyspi.write("\t{\n")
            bodyspi.write("\t\t" + type_ + " empty_data = " + type_ + "();\n")
            bodyspi.write("\t\tmemset(&empty_data, 0, sizeof(empty_data));\n")
            bodyspi.write("\t\ttask.task_data = empty_data;\n")
            bodyspi.write("\t}\n")

    bodyspi.write("\tthis->task_queue.push(task);\n")
    bodyspi.write("};\n")
    bodyspi.write("\n")


def createProcess(cbName, cbArgsTypeList, cbArgsValueList):
    # 从队列中提取任务，并转化为python字典
    bodyprocess.write("void " + _apiName + '::' + cbName.replace('On', 'process') + '(Task task)' + "\n")
    bodyprocess.write("{\n")
    bodyprocess.write("\tPyLock lock;\n")

    onArgsList = []

    for i, type_ in enumerate(cbArgsTypeList):
        if 'RspInfoField' in type_:
            bodyprocess.write("\t"+ type_ + ' task_error = any_cast<' + type_ + '>(task.task_error);\n')
            bodyprocess.write("\t"+ "dict error;\n")

            struct = structDict[type_]
            for key in struct.keys():
                if key == 'ErrorMsg': # 针对CTP返回的GBK格式的中文进行特殊处理
                    bodyprocess.write('\terror["ErrorMsg"] = GBK_TO_UTF8(task_error.ErrorMsg);')
                else:
                    bodyprocess.write("\t"+ 'error["' + key + '"] = task_error.' + key + ';\n')

            bodyprocess.write("\n")

            onArgsList.append('error')

        elif type_ in structDict:
            bodyprocess.write("\t"+ type_ + ' task_data = any_cast<' + type_ + '>(task.task_data);\n')
            bodyprocess.write("\t"+ "dict data;\n")

            struct = structDict[type_]
            for key in struct.keys():
                if 'Name' in key or 'Msg' in key: # 针对CTP返回的GBK格式的中文进行特殊处理
                    bodyprocess.write("\t"+ 'data["' + key + '"] = GBK_TO_UTF8(task_data.' + key + ');\n')
                else:
                    bodyprocess.write("\t"+ 'data["' + key + '"] = task_data.' + key + ';\n')

            bodyprocess.write("\n")

            onArgsList.append('data')

        elif type_ == 'bool':
            onArgsList.append('task.task_last')

        elif type_ == 'int':
            onArgsList.append('task.task_id')

    onArgs = ', '.join(onArgsList)
    bodyprocess.write('\tthis->' + cbName.replace('On', 'on') + '(' + onArgs +');\n')

    bodyprocess.write("};\n")
    bodyprocess.write("\n")


def processFunction(line):
    line = line.replace('\tvirtual int ', '')       # 删除行首的无效内容
    line = line.replace(') = 0;\n', '')                # 删除行尾的无效内容

    content = line.split('(')
    fcName = content[0]                             # 回调函数名称

    fcArgs = content[1]                             # 回调函数参数
    fcArgs = fcArgs.replace(')', '')

    fcArgsList = fcArgs.split(', ')                 # 将每个参数转化为列表

    fcArgsTypeList = []
    fcArgsValueList = []

    for arg in fcArgsList:                          # 开始处理参数
        content = arg.split(' ')
        if len(content) > 1:
            fcArgsTypeList.append(content[0])           # 参数类型列表
            fcArgsValueList.append(content[1])          # 参数数据列表


    # 生成.h文件中的主动函数部分
    if 'Req' in fcName:
        if not(len(fcArgsTypeList)>0 and fcArgsTypeList[0] in structDict):
            return
        createFunction(fcName, fcArgsTypeList, fcArgsValueList)
        req_line = '\tint req' + fcName[3:] + '(dict req, int nRequestID);\n'
        headerfunction.write(req_line)
        headerfunction.write('\n')
        export_line = '\t\t.def("req%s", &%sWrap::req%s)\n' %(fcName[3:], _apiName, fcName[3:])
        bodyexport.write(export_line)

def createFunction(fcName, fcArgsTypeList, fcArgsValueList):
    type_ = fcArgsTypeList[0]
    struct = structDict[type_]

    bodyreq.write('int '+ _apiName + '::req' + fcName[3:] + '(dict req, int nRequestID)\n')
    bodyreq.write('{\n')
    bodyreq.write('\t' + type_ +' myreq = ' + type_ + '();\n')
    bodyreq.write('\tmemset(&myreq, 0, sizeof(myreq));\n')

    for key, value in struct.items():
        if value == 'string':
            line = '\tgetStr(req, "' + key + '", myreq.' + key + ');\n'
        elif value == 'char':
            line = '\tgetChar(req, "' + key + '", &myreq.' + key + ');\n'
        elif value == 'int':
            line = '\tgetInt(req, "' + key + '", &myreq.' + key + ');\n'
        elif value == 'float':
            line = '\tgetDouble(req, "' + key + '", &myreq.' + key + ');\n'
        bodyreq.write(line)

    bodyreq.write('\tint i = this->api->' + fcName + '(&myreq, nRequestID);\n')
    bodyreq.write('\treturn i;\n')

    bodyreq.write('};\n')
    bodyreq.write('\n')


#########################################################
def genCppFiles(mdapiHeader, apiName,hTemplate, hDestFile,
                  cppTempalte, cppDestFile):
    global _apiName, define_count
    global headerprocess, headeron, headerfunction, headerdefine
    global bodyspi, bodyprocess, bodyreq, bodyswitch, bodywrap, bodyexport
    _apiName = apiName
    define_count = 1

    headerprocess = io.StringIO()
    headeron = io.StringIO()
    headerfunction = io.StringIO()
    headerdefine = io.StringIO()

    bodyspi = io.StringIO()
    bodyprocess = io.StringIO()
    bodyreq = io.StringIO()
    bodyswitch = io.StringIO()
    bodywrap = io.StringIO()
    bodyexport = io.StringIO()
    
    encoding = chardet.detect(open(mdapiHeader, 'rb').read())['encoding']
    fheader = open(mdapiHeader, 'r', encoding=encoding)

    for line in fheader:
        if "\tvirtual void On" in line:
            if "OnPackage" not in line:
                processCallBack(line)
        elif "\tvirtual int" in line:
            processFunction(line)

    h_template = Template(open(hTemplate, 'r', encoding='utf-8').read())
    h_s = h_template.substitute({
        'md_define': headerdefine.getvalue(),
        'md_header_process':headerprocess.getvalue(),
        'header_function' : headerfunction.getvalue(),
        'md_header_on':headeron.getvalue(),
        })
    open(hDestFile, 'w', encoding='utf-8').write(h_s)

    print(hDestFile + '生成完成')

    cpp_template = Template(open(cppTempalte, 'r', encoding='utf-8').read())
    cpp_s = cpp_template.substitute({
        'body_SPI':bodyspi.getvalue(),
        'process_body':bodyprocess.getvalue(),
        'body_wrap':bodywrap.getvalue(),
        'body_req':bodyreq.getvalue(),
        'body_switch':bodyswitch.getvalue(),
        'body_export':bodyexport.getvalue()
        })
    open(cppDestFile, 'w', encoding='utf-8').write(cpp_s)
    print(cppDestFile + '生成完成')
    fheader.close()
    bodyspi.close()
    bodyprocess.close()
    bodyreq.close()
    bodyswitch.close()
    headerdefine.close()
    headerprocess.close()
    headeron.close()
    headerfunction.close()
    bodywrap.close()



