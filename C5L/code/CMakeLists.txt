cmake_minimum_required(VERSION 3.14)
project(cviko LANGUAGES CXX)

add_subdirectory(lib)

add_executable(my_main main.cpp)

target_link_libraries(my_main math)