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

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${TARGET} ${SOURCES})

enable_testing()

add_executable(
        degrees-radians-tests
        degrees.cpp
        radians.cpp
        tests.cpp
)
target_link_libraries(
        degrees-radians-tests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(degrees-radians-tests)
