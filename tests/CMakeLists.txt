cmake_minimum_required(VERSION 3.10)

include_directories(../include)

# Test targets 
set(YART_TEST_SOURCES main.cpp tuple.cpp)

add_executable(tests ${YART_TEST_SOURCES})
target_link_libraries(tests gtest_main)
add_test(NAME tests COMMAND tests)
