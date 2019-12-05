cmake_minimum_required(VERSION 3.10)

# Test targets 
set(YART_TEST_SOURCES main.cpp ch1.cpp)

add_executable(tests ${YART_TEST_SOURCES})
target_link_libraries(tests gtest_main)
add_test(NAME tests COMMAND tests)
