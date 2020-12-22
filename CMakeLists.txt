cmake_minimum_required(VERSION 3.1)
project(vn_femas_api)

# 设置Femas API根路径，要编译不同版本API对应的python封装，只需修改此路径即可
#set(FemasAPI_BASE FemasClassic_1.03)
set(FemasAPI_BASE FemasOption_2.05.16)

option(FEMAS_CLASSIC "Femas classic api" ON)  # getMarketTopic 是否可用，futurue需要开启

# 设置使用的编译器
set(CMAKE_BUILD_TYPE "Release")
if (CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_GNUCXX)
	if (FEMAS_CLASSIC)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 -DFEMAS_CLASSIC")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0")
	endif()
endif ()
# disable: pyerrors replace snprintf with _snprintf
add_definitions(-DHAVE_SNPRINTF)

# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# 使用64位编译
option(USE_64BITS "comiple 64bits" ON)
if (USE_64BITS)
  add_definitions(-DUSE_64BITS)
  #set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
endif()

# 设置C++ API源文件的所在目录
include_directories(${FemasAPI_BASE}/include)
set(Femas_LIB_PATH )
if (WIN32)
	set(Femas_LIB_PATH ${FemasAPI_BASE}/lib/win64)

	find_library(FemasAPI_MD_LIBRARY
		NAMES USTPmduserapi
		PATHS ${Femas_LIB_PATH}) 
	find_library(FemasAPI_TD_LIBRARY
		NAMES USTPtraderapi
		PATHS ${Femas_LIB_PATH})

elseif (UNIX)
	set(Femas_LIB_PATH ${FemasAPI_BASE}/lib/linux64)
    if (FEMAS_CLASSIC)
		find_library(FemasAPI_MD_LIBRARY
			NAMES USTPmduserapi
			PATHS ${Femas_LIB_PATH}) 
		find_library(FemasAPI_TD_LIBRARY
			NAMES USTPtraderapi
			PATHS ${Femas_LIB_PATH})

	else()
		find_library(FemasAPI_MD_LIBRARY
			NAMES USTPmduserapiAF
			PATHS ${Femas_LIB_PATH}) 
		find_library(FemasAPI_TD_LIBRARY
			NAMES USTPtraderapiAF
			PATHS ${Femas_LIB_PATH})
	endif()
endif()

# 设置编译源文件
set (vnfemasmd )
set (vnfemastd )

option(BUILD_Femas_MD "build femas md" ON)
if (BUILD_Femas_MD)
  add_definitions(-DBUILD_Femas_MD)
  set(Femas_MD_PATH vnfemasmd/vnfemasmd)
  include_directories(Femas_MD_PATH)
  set(VN_Femas_MD_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/vnfemasmd/vnfemasmd/vnfemasmd.cpp)
  add_library(vnfemasmd SHARED ${VN_Femas_MD_SOURCE})
endif()
option(BUILD_FEMAS_TD "build femas td" ON)
if (BUILD_FEMAS_TD)
  add_definitions(-DBUILD_Femas_TD)
  set(FEMAS_TD_PATH vnfemastd/vnfemastd)
  include_directories(FEMAS_TD_PATH)
  set(VN_FEMAS_TD_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/vnfemastd/vnfemastd/vnfemastd.cpp)
  add_library(vnfemastd SHARED ${VN_FEMAS_TD_SOURCE})  
endif()

# 设置Python所在的目录
find_package (Python3 COMPONENTS Interpreter Development)
find_package (PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# 链接boost库，anaconda
if (WIN32)
    set(Boost_USE_STATIC_LIBS        ON)    #链接boost静态库
endif()
set(Boost_USE_MULTITHREADED      ON)
find_package(Boost 1.70.0 REQUIRED python36 locale thread date_time system chrono ) # 如果boost库没有完全编译，需要将编译的库明确地指出，否者message(${Boost_LIBRARIES})会出错
include_directories(${Boost_INCLUDE_DIRS})


# 去掉生成的so文件名中前缀的lib
set_target_properties(vnfemasmd PROPERTIES PREFIX "")

# 链接生成.so文件
target_link_libraries(vnfemasmd  ${Boost_LIBRARIES} ${PYTHON_LIBRARY} ${FemasAPI_MD_LIBRARY})

# 将生成的dll文件后缀名修改为pyd（仅在windows下）
set(MD_DLL "${LIBRARY_OUTPUT_PATH}/Release/vnfemasmd.dll")
if (EXISTS ${MD_DLL})
  file(RENAME ${MD_DLL} ${LIBRARY_OUTPUT_PATH}/Release/vnfemasmd.pyd)
endif()

# 和上面的MD相同
set_target_properties(vnfemastd PROPERTIES PREFIX "")
target_link_libraries(vnfemastd  ${Boost_LIBRARIES} ${PYTHON_LIBRARY} ${FemasAPI_TD_LIBRARY})
set(TD_DLL ${LIBRARY_OUTPUT_PATH}/Release/vnfemastd.dll)
if (EXISTS ${TD_DLL})
  file(RENAME  ${TD_DLL} ${LIBRARY_OUTPUT_PATH}/Release/vnfemastd.pyd)
endif()
