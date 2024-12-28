cmake_minimum_required(VERSION 3.0.0)
project(RssParse VERSION 1.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_COMPILE_COMMANDS ON)

# 添加源文件
set(SOURCE
    main.cpp
    TinyXml/src/tinyxml2.cpp
    RssParse/src/rssparse.cpp
)

# 添加头文件目录
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/TinyXml/include
    ${CMAKE_CURRENT_SOURCE_DIR}/RssParse/include
)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# 生成可执行文件
add_executable(rssparse ${SOURCE})