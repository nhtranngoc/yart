cmake_minimum_required(VERSION 3.10)

project(yart)

set(CMAKE_CXX_FLAGS "-Wall -pedantic -Werror -Wno-variadic-macros -Wno-long-long -Wno-shadow -std=c++11")

add_subdirectory(src)
add_subdirectory(lib/googletest)
enable_testing()
add_subdirectory(tests)


# # Now simply link against gtest or gtest_main as needed. Eg
# add_executable(example example.cpp)
# target_link_libraries(example gtest_main)
# add_test(NAME example_test COMMAND example)