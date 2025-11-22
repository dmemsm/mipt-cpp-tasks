cmake_minimum_required(VERSION 3.20)

set(TARGET "degrees-radians")

set(HEADERS
        degrees.h
        radians.h
)

set(SOURCES
        main.cpp
        degrees.cpp
        radians.cpp
)

project(${TARGET} CXX)

add_executable(${TARGET} ${SOURCES})

install(TARGETS ${TARGET})
