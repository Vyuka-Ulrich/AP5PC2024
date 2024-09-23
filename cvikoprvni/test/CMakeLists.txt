include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(gtestik INTERFACE IMPORTED)
target_link_libraries(gtestik INTERFACE gtest_main)

enable_testing()

add_executable(adder_test adder_test.cpp)

target_link_libraries(adder_test PUBLIC gtestik adder)
