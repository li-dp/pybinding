# encoding: UTF-8

import os
import traceback
import chardet
import config
import importlib

def gen_struct(cpp_struct_header, datatype_py,  struct_py):
    """主函数"""
    dt = importlib.import_module(datatype_py.replace(".py", ""))
    encoding = chardet.detect(open(cpp_struct_header, 'rb').read())['encoding']
    fcpp = open(cpp_struct_header, 'r', encoding=encoding)
    fpy = open(struct_py, 'w', encoding='utf-8')

    fpy.write('# encoding: UTF-8\n')
    fpy.write('\n')
    fpy.write('structDict = {}\n')
    fpy.write('\n')
    try:
        for no, line in enumerate(fcpp):
            # 结构体申明注释
            if '///' in line and '\t' not in line:
                py_line = '#' + line[3:]

            # 结构体变量注释
            elif '\t///' in line:
                py_line = '#' + line[4:]

            # 结构体申明
            elif 'struct ' in line:
                content = line.split(' ')
                name = content[1]
                name = name.replace('\r\n','')
                name = name.replace('\n','')
                py_line = '%s = {}\n' % name

            # 结构体变量
            elif '\t' in line and 'Type' in line and '///' not in line:
                content = line.split('\t')
                typedef = content[1]
                type_ = dt.typedefDict[typedef]
                variable = content[2]
                variable = variable.replace(';\r\n', "")
                variable = variable.replace(';\n', "")

                py_line = '%s["%s"] = "%s"\n' % (name, variable, type_)

            # 结构体结束
            elif '}' in line:
                py_line = "structDict['%s'] = %s\n\n" % (name, name)

            # 结构体开始
            elif '{' in line:
                py_line = ''

            # 其他
            else:
                py_line = '\n'

            #fpy.write(py_line.decode('gbk').encode('utf-8'))
            fpy.write(py_line)
        print("DataStruct 生成完成")
    except Exception as excp:
        print(str(excp))
        traceback.print_exc()
        print("DataStruct 生成错误")

