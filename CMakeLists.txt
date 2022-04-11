cmake_minimum_required(VERSION 3.16)
project(ReadingFilesFromDirectory)

set(CMAKE_CXX_STANDARD 17)
FILE(COPY input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(untitled6 main.cpp)



