cmake_minimum_required(VERSION 3.8)
project(proj0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.h TestGraph.h MainGraphTester.cpp TestSuccessor.cpp Successors.cpp Successors.h)
add_executable(proj0 ${SOURCE_FILES} Successors.cpp)