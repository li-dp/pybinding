# encoding: UTF-8

import os
# API 类型， 支持ctp/tora/femas
api_prefix = "femas"

# API头文件目录
#femas_api_folder = "FemasClassic_1.03"
femas_api_folder = "FemasOption_2.05.16"
#femas_api_folder = "FemasAllFutures_3.02.01"

_cpp_api_path = os.path.join(os.path.dirname(__file__), "..", femas_api_folder, "include")

# 数据类型头文件
cpp_api_datatype = os.path.join(_cpp_api_path, 'USTPFtdcUserApiDataType.h')
cpp_api_struct = os.path.join(_cpp_api_path, 'USTPFtdcUserApiStruct.h')
cpp_api_md = os.path.join(_cpp_api_path, 'USTPFtdcMduserApi.h')
cpp_api_td = os.path.join(_cpp_api_path, 'USTPFtdcTraderApi.h')
