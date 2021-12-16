cmake_minimum_required(VERSION 3.0.0)
project(cppstudy VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include/binaryTree)
include_directories(include/linkedList)

# 添加需要编译的文件
#add_executable(leetcode src/linkedList/707.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
