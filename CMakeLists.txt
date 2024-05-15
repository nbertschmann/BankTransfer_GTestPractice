cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(bank_transfer)

include_directories(include)

add_subdirectory(src)
add_subdirectory(external)
add_subdirectory(tests)

