cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(bank_transfer)

set(SOURCE_FILES
    src/main.cpp
    src/TransferService.cpp)


add_executable(bank_transfer ${SOURCE_FILES})
include_directories(include)