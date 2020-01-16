cmake_minimum_required(VERSION 3.8)
project(np1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BigInteger.cpp BigInteger.h main.cpp)
add_executable(np1 ${SOURCE_FILES})