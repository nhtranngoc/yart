cmake_minimum_required(VERSION 3.10)

include_directories(../include)
set(YART_SOURCES main.cpp)

add_executable(yart ${YART_SOURCES})

add_custom_target(run 
	COMMAND yart)
