cmake_minimum_required(VERSION 3.0.0)
project(cppstudy VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include/binary_tree)
add_executable(leetcode src/array/76-minimum-window-substring.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
