cmake_minimum_required(VERSION 3.10)

project(yart)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)


# # Now simply link against gtest or gtest_main as needed. Eg
# add_executable(example example.cpp)
# target_link_libraries(example gtest_main)
# add_test(NAME example_test COMMAND example)