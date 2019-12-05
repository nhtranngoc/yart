cmake_minimum_required(VERSION 3.10)

# Include GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test targets 
set(YART_TEST_SOURCES main.cpp ch1.cpp)

add_executable(tests ${YART_TEST_SOURCES})
target_link_libraries(tests gtest_main)
add_test(NAME tests COMMAND tests)
