# encoding: utf-8

import os

# API头文件目录
api_folder = "GuAPI"
_cpp_api_path = os.path.join(os.path.dirname(__file__), "..", api_folder, "include")

# 数据类型头文件
md_api_datatype_header = os.path.join(_cpp_api_path, 'QdFtdcUserApiDataType.h')
md_api_struct_header = os.path.join(_cpp_api_path, 'QdFtdcUserApiStruct.h')
md_api_header = os.path.join(_cpp_api_path, 'QdFtdcMduserApi.h')
md_datatype_py = "QdDataType.py"
md_struct_py = "QdStruct.py"

user_api_datatype_header = os.path.join(_cpp_api_path, 'FocusFtdcUserApiDataType.h')
user_api_struct_header = os.path.join(_cpp_api_path, 'FocusFtdcUserApiStruct.h')
user_api_header = os.path.join(_cpp_api_path, 'FocusFtdcUserApi.h')
user_datatype_py = "FocusDataType.py"
user_struct_py = "FocusStruct.py"

td_api_datatype_header = os.path.join(_cpp_api_path, 'FocusFtdcUserApiDataType.h')
td_api_struct_header = os.path.join(_cpp_api_path, 'FocusFtdcUserApiStruct.h')
td_api_header = os.path.join(_cpp_api_path, 'FocusFtdcTraderApi.h')
td_datatype_py = "FocusDataType.py"
td_struct_py = "FocusStruct.py"


