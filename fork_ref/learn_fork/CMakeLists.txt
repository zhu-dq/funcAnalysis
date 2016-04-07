cmake_minimum_required(VERSION 3.5)
project(learn_fork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test1.cpp test2.cpp test3.cpp)
add_executable(learn_fork ${SOURCE_FILES})