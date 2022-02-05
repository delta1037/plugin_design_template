cmake_minimum_required(VERSION 3.17)
# 动态库工程和测试工程
project(plugin_1)
project(main_prj)

set(CMAKE_CXX_STANDARD 11)

# 设置插件的输出目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release/plugin)
# 设置主程序的输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release)


# include 的文件夹
include_directories(include)

# 插件动态库编译
add_library(plugin_1 SHARED
        plugin_1/plugin_1.cpp
        )

# 主工程程序
find_library(plugin_1_lib NAMES plugin_1 PATHS ${CMAKE_SOURCE_DIR}/release/plugin)
add_executable(main_prj
        src/plugin_ctrl.cpp
        src/main_prj.cpp)
