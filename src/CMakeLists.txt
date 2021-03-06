cmake_minimum_required(VERSION 3.10)

set(LDSCRIPT "${CMAKE_SOURCE_DIR}/stm32f429i-discovery.ld")
set(LIBNAME "opencm3_stm32f4")
add_definitions(-DSTM32F4)

set(FP_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
set(ARCH_FLAGS "-mthumb -mcpu=cortex-m4 ${FP_FLAGS}")

set(OPENCM3_DIR "${CMAKE_SOURCE_DIR}/lib/libopencm3")

include_directories(${OPENCM3_DIR}/include)

link_directories(${OPENCM3_DIR}/lib)

set(CMAKE_ASM_FLAGS "-D__ASSEMBLY__ -mcpu=cortex-m4 -mthumb")
set(CMAKE_C_FLAGS " \
${COMMON_C_FLAGS} \
-fsingle-precision-constant -Wdouble-promotion -Wfloat-conversion \
${ARCH_FLAGS}")

set(CMAKE_CXX_FLAGS " \
${COMMON_CXX_FLAGS} \
-fsingle-precision-constant -Wdouble-promotion -Wfloat-conversion \
${ARCH_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS " \
${ARCH_FLAGS} \
-T${LDSCRIPT} \
-nostartfiles \
--specs=nano.specs \
--specs=nosys.specs \
-Wl,--start-group -lc -lgcc -Wl,--end-group \
-Wl,--no-wchar-size-warning \
-Wl,--gc-sections")

add_custom_target(libopencm3 make WORKING_DIRECTORY ${OPENCM3_DIR})


# Src 
# Conditional to change float computation between stm32 and testing host
add_definitions(-DSTM32)

include_directories(../include)
include_directories(../include/lcd)
include_directories(../include/shapes)
include_directories(../include/patterns)

file(GLOB USER_SOURCES 
    ${CMAKE_SOURCE_DIR}/src/*.cpp 
    ${CMAKE_SOURCE_DIR}/src/lcd/*.c 
    ${CMAKE_SOURCE_DIR}/src/shapes/*.cpp 
    ${CMAKE_SOURCE_DIR}/src/patterns/*.cpp)

add_executable(yart.elf ${USER_SOURCES})
target_link_libraries(yart.elf opencm3_stm32f4)
