cmake_minimum_required(VERSION 3.22)
project(LR8)


add_library(func0 STATIC fWorkWithFile.cpp)
add_library(func1 STATIC mainfunc.cpp)

add_executable(main Task_1.cpp)

target_link_libraries(main func0 func1)

enable_testing()