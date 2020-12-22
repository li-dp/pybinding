# encoding: UTF-8
import os
import traceback
import chardet
# C++和python类型的映射字典
_type_dict = {
    'int': 'int',
    'long long int': 'long',
    'char': 'char',
    'double': 'float',
    'short': 'int',
    'string': 'string'
}


def _process_line(line):
    """处理每行"""
    if '///' in line:           # 注释
        py_line = _process_comment(line)
    elif 'typedef' in line:     # 类型申明
        py_line = _process_typedef(line)
    elif '#define' in line:     # 定义常量
        py_line = _process_define(line)
    elif line == '\n':          # 空行
        py_line = line
    else:
        py_line = ''

    return py_line


def _process_comment(line):
    """处理注释"""
    # if line[3] == '/':
    #     py_line = ''
    # else:
    #     py_line = '#' + line[3:]
    py_line = '#' + line[3:]
    return py_line


def _process_typedef(line):
    """处理类型申明"""
    content = line.split(' ')
    type_ = _type_dict[' '.join(content[1:-1])]

    if type_ == 'char' and '[' in line:
        type_ = 'string'

    keyword = content[-1]
    keyword = keyword.replace(';\r\n', '')  # 删除行末分号
    keyword = keyword.replace(';\n', '')  # 删除行末分号
    if '[' in keyword:
        i = keyword.index('[')
        keyword = keyword[:i]


    py_line = 'typedefDict["%s"] = "%s"\n' % (keyword, type_)

    return py_line


def _process_define(line):
    """处理定义常量"""
    content = line.split(' ')
    constant = content[1]

    if len(content)>2:
        value = content[-1]
        py_line = 'defineDict["%s"] = %s' % (constant, value)
    else:
        py_line = ''

    return py_line


def genDataType(dataTypeHeader):
    """主函数"""
    try:
        import os
        encoding = chardet.detect(open(dataTypeHeader, 'rb').read())['encoding']
        fcpp = open(dataTypeHeader,'r', encoding=encoding)
        fpy = open('femasDataType.py', 'w', encoding='utf-8')

        fpy.write('# encoding: UTF-8\n')
        fpy.write('\n')
        fpy.write('defineDict = {}\n')
        fpy.write('typedefDict = {}\n')
        fpy.write('\n')

        for line in fcpp:
            py_line = _process_line(line)
            if py_line:
                fpy.write(py_line)


        fcpp.close()
        fpy.close()

        print('data_type.py生成过程完成')
    except Exception as excp:
        print(str(excp))
        traceback.print_exc()
        print('data_type.py生成过程出错')


