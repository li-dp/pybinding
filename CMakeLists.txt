cmake_minimum_required(VERSION 3.1)
project(vn_femas_api)

set(CPPAPI_BASE GuAPI)

# 设置使用的编译器
if (CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0")
endif ()
# disable: pyerrors replace snprintf with _snprintf
add_definitions(-DHAVE_SNPRINTF)

# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# 设置C++ API源文件的所在目录
include_directories(${CPPAPI_BASE}/include)
set(CPP_LIB_PATH ${CPPAPI_BASE}/lib/linux64)

find_library(MD_API_LIBRARY
	NAMES qdmduserapi
	PATHS ${CPP_LIB_PATH}) 
find_library(TD_API_LIBRARY
	NAMES focustraderapi
	PATHS ${CPP_LIB_PATH})
find_library(USER_API_LIBRARY
	NAMES focususerapi
	PATHS ${CPP_LIB_PATH})

	
# 设置Python所在的目录
find_package (Python3 COMPONENTS Interpreter Development)
find_package (PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# 链接boost库，anaconda
if (WIN32)
    set(Boost_USE_STATIC_LIBS        ON)    #链接boost静态库
endif()
set(Boost_USE_MULTITHREADED      ON)
find_package(Boost 1.69 REQUIRED COMPONENTS python36 locale thread date_time system chrono ) # 如果boost库没有完全编译，需要将编译的库明确地指出，否者message(${Boost_LIBRARIES})会出错
include_directories(${Boost_INCLUDE_DIRS})

# 设置编译源文件

option(BUILD_MD_BINDING "build md binding" ON)
if (BUILD_MD_BINDING)
	add_definitions(-DBUILD_MD_BINDING)
	set(MD_BINDING_PATH mdbinding)
	include_directories(MD_BINDING_PATH)
	set(MD_BINDING_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/mdbinding/mdbinding.cpp)
	add_library(qdmbinding SHARED ${MD_BINDING_SOURCE})

	# 去掉生成的so文件名中前缀的lib
	set_target_properties(qdmbinding PROPERTIES PREFIX "")
	# 链接生成.so文件
	target_link_libraries(qdmbinding  ${Boost_LIBRARIES} ${PYTHON_LIBRARY} ${MD_API_LIBRARY})
endif()

option(BUILD_TD_BINDING "build td binding" ON)
if (BUILD_TD_BINDING)
	add_definitions(-DBUILD_TD_BINDING)
	set(TD_BINDING_PATH tdbinding)
	include_directories(TD_BINDING_PATH)
	set(TD_BINDING_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/tdbinding/tdbinding.cpp)
	add_library(focusbinding SHARED ${TD_BINDING_SOURCE})  
	
	set_target_properties(focusbinding PROPERTIES PREFIX "")
	target_link_libraries(focusbinding  ${Boost_LIBRARIES} ${PYTHON_LIBRARY} ${TD_API_LIBRARY})
endif()

option(BUILD_USER_BINDING "build user binding" ON)
if (BUILD_USER_BINDING)
	add_definitions(-DBUILD_USER_BINDING)
	set(USER_BINDING_PATH userbinding)
	include_directories(USER_BINDING_PATH)
	set(USER_BINDING_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/userbinding/userbinding.cpp)
	add_library(userbinding SHARED ${USER_BINDING_SOURCE})  
	
	set_target_properties(userbinding PROPERTIES PREFIX "")
	target_link_libraries(userbinding  ${Boost_LIBRARIES} ${PYTHON_LIBRARY} ${USER_API_LIBRARY})
endif()

