cmake_minimum_required(VERSION 3.10)

project(yart)
enable_language(C CXX)

if(CMAKE_CROSSCOMPILING) 
    message(STATUS "Crosscompiling enabled, using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
    add_subdirectory(src)
else()
    message(STATUS "No crosscompiling specified, compiling in /tests only.")
    add_subdirectory(tests)
endif()

set(COMMON_C_FLAGS "-lc -lgcc -Os -g \
-Wall -Werror -Wredundant-decls -Wstrict-prototypes \
-fsingle-precision-constant -Wdouble-promotion -Wfloat-conversion \
-fno-common -ffunction-sections -fdata-sections -MD -Wundef")

set(COMMON_CXX_FLAGS "-lc -lgcc -Os -Wall -Werror -std=c++11 \
-fsingle-precision-constant -Wdouble-promotion -Wfloat-conversion")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)