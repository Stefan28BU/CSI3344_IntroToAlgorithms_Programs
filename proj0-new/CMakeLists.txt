cmake_minimum_required(VERSION 3.8)
project(proj0_new)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Graph.h TestGraph.h MainGraphTester.cpp TestSuccessor.cpp Successors.h Successors.cpp GraphData.txt)
add_executable(proj0_new ${SOURCE_FILES})