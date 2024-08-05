cmake_minimum_required(VERSION 3.5.0)

project(Factory)

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 ")

set(SRC_LIST main.cpp Factory.cpp )

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(factory ${SRC_LIST})