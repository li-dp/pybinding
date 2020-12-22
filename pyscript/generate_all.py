# encoding: UTF-8

"""
根据Femas API自动生成对应的DataType.py，以及C++封装文件
"""

import os
import traceback
import config

from generate_data_type import gen_data_type
from generate_struct import gen_struct

gen_data_type(config.md_api_datatype_header, config.md_datatype_py)
gen_struct(config.md_api_struct_header, config.md_datatype_py, config.md_struct_py)

gen_data_type(config.td_api_datatype_header, config.td_datatype_py)
gen_struct(config.td_api_struct_header, config.td_datatype_py, config.td_struct_py)

from generate_cppfiles import genCppFiles
genCppFiles(config.cpp_api_md, apiName='MdApi',
            hTemplate='vnfemasmd.h.template', hDestFile=r'../vnfemasmd/vnfemasmd/vnfemasmd.h',
            cppTempalte='vnfemasmd.cpp.template', cppDestFile=r'../vnfemasmd/vnfemasmd/vnfemasmd.cpp'
            )

genCppFiles(config.cpp_api_td, apiName='TdApi',
            hTemplate='vnfemastd.h.template', hDestFile=r'../vnfemastd/vnfemastd/vnfemastd.h',
            cppTempalte='vnfemastd.cpp.template', cppDestFile=r'../vnfemastd/vnfemastd/vnfemastd.cpp'
            )
