# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (earth)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb")

#set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")

include_directories("./src")
include_directories("./src/comm")
include_directories("./src/platform")

# 指定生成目标
aux_source_directory(./src DIR_SRCS)
aux_source_directory(./src/comm DIR_SRCS)
aux_source_directory(./src/platform DIR_SRCS)
find_package (Threads)
add_executable(earth ${DIR_SRCS})
target_link_libraries (earth ${CMAKE_THREAD_LIBS_INIT})