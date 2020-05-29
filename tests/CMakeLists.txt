cmake_minimum_required(VERSION 3.10)

if(DEFINED $ENV{CPPUTEST_HOME})
    message(STATUS "Using CppUTest home: $ENV{CPPUTEST_HOME}")
    set(CPPUTEST_INCLUDE_DIRS $ENV{CPPUTEST_HOME}/include)
    set(CPPUTEST_LIBRARIES $ENV{CPPUTEST_HOME}/lib)
    set(CPPUTEST_LDFLAGS CppUTest CppUTestExt)
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
    message(STATUS "Found CppUTest version ${CPPUTEST_VERSION}")
endif()

file(GLOB USER_SOURCES ${CMAKE_SOURCE_DIR}/tests/*.c ${CMAKE_SOURCE_DIR}/tests/*.cpp)

include_directories(${CPPUTEST_INCLUDE_DIRS} ../src/ ../include/)
link_directories(${CPPUTEST_LIBRARIES})

add_executable(yart_test.bin ${USER_SOURCES})
target_link_libraries(yart_test.bin ${APP_LIB_NAME} ${CPPUTEST_LDFLAGS})

add_custom_target(TARGET yart_test.bin COMMAND ./tests/yart_test.bin POST_BUILD)
