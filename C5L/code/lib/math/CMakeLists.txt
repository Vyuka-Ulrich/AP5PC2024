add_library(math math.cpp)

target_include_directories(math PUBLIC 
header
template)

target_link_libraries(math point)