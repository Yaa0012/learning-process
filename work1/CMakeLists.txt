cmake_minimum_required(VERSION 3.10)
project(Work1)
set(CMAKE_CXX_STANDARD 17)

add_library(my_lib func.cpp)
add_executable(main_app main2.cpp)
target_link_libraries(main_app my_lib)
