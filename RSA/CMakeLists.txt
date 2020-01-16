cmake_minimum_required(VERSION 3.8)
project(RSA)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BigInteger.cpp BigInteger.h RSAencrypt.cpp RSAdecrypt.cpp)
add_executable(RSA ${SOURCE_FILES})