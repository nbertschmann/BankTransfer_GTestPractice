cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(bank_transfer)

include(CTest)
include_directories(include)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(tests)

