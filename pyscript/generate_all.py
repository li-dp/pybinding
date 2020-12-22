# encoding: UTF-8

"""
根据Femas API自动生成对应的DataType.py，以及C++封装文件
"""

import os
import traceback
import config

from generate_data_type import genDataType
genDataType(config.cpp_api_datatype)

from generate_struct import genStruct
genStruct(config.cpp_api_struct)

from generate_cppfiles import genCppFiles
genCppFiles(config.cpp_api_md, apiName='MdApi',
            hTemplate='vnfemasmd.h.template', hDestFile=r'../vnfemasmd/vnfemasmd/vnfemasmd.h',
            cppTempalte='vnfemasmd.cpp.template', cppDestFile=r'../vnfemasmd/vnfemasmd/vnfemasmd.cpp'
            )

genCppFiles(config.cpp_api_td, apiName='TdApi',
            hTemplate='vnfemastd.h.template', hDestFile=r'../vnfemastd/vnfemastd/vnfemastd.h',
            cppTempalte='vnfemastd.cpp.template', cppDestFile=r'../vnfemastd/vnfemastd/vnfemastd.cpp'
            )
