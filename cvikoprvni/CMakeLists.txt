cmake_minimum_required(VERSION 3.16)
project(Adder LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_main main.cpp)
target_link_libraries(my_main PUBLIC adder)

add_subdirectory(lib)
add_subdirectory(test)




