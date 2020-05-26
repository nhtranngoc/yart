cmake_minimum_required(VERSION 3.10)

include_directories(../include)

file(GLOB USER_SOURCES ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(yart.elf ${USER_SOURCES})
# add_executable(yart ${USER_SOURCES})
target_link_libraries(yart.elf opencm3_stm32f4)
