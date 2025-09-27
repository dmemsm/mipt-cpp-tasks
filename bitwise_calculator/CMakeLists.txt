cmake_minimum_required(VERSION 3.20)

set(TARGET "bitwise_calculator")

set(SOURCES
        bitwise_calculator.cpp
)

project(${TARGET} CXX)

add_executable(${TARGET} ${SOURCES})

install(TARGETS ${TARGET})
