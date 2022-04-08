cmake_minimum_required(VERSION 3.16)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)
FILE(COPY input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(untitled6 main.cpp)
