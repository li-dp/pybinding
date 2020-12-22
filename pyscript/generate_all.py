# encoding: UTF-8

"""
根据Femas API自动生成对应的DataType.py，以及C++封装文件
"""

import os
import traceback
import config

from generate_data_type import gen_data_type
from generate_struct import gen_struct
from generate_cppfiles import gen_cpp_file

gen_data_type(config.md_api_datatype_header, config.md_datatype_py)
gen_struct(config.md_api_struct_header, config.md_datatype_py, config.md_struct_py)

gen_data_type(config.td_api_datatype_header, config.td_datatype_py)
gen_struct(config.td_api_struct_header, config.td_datatype_py, config.td_struct_py)

gen_cpp_file(config.md_api_header, apiName='MdApi', structPy=config.md_struct_py,
            hTemplate='mdbinding.h.template', hDestFile=r'../mdbinding/mdbinding.h',
            cppTempalte='mdbinding.cpp.template', cppDestFile=r'../mdbinding/mdbinding.cpp'
            )

gen_cpp_file(config.td_api_header, apiName='TdApi', structPy=config.td_struct_py,
            hTemplate='tdbinding.h.template', hDestFile=r'../tdbinding/tdbinding.h',
            cppTempalte='tdbinding.cpp.template', cppDestFile=r'../tdbinding/tdbinding.cpp'
            )
