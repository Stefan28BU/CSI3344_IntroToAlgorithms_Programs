cmake_minimum_required(VERSION 3.8)
project(proj1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BigInteger.cpp BigInteger.h)
add_executable(proj1 ${SOURCE_FILES})