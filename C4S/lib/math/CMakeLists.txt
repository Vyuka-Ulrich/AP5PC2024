add_library(math math.cpp)

target_include_directories(math PUBLIC include)

target_link_libraries(math point)