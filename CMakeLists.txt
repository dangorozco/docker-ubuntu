cmake_minimum_required(VERSION 3.10)
project(HelloARM C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Option to control whether to build the standalone hello app
option(BUILD_MAIN "Build hello as standalone app" ON)

# Main app (only if BUILD_MAIN is ON)
if(BUILD_MAIN)
    add_executable(hello hello.c)
    target_compile_definitions(hello PRIVATE BUILD_MAIN)
    set_target_properties(hello PROPERTIES LINKER_LANGUAGE C)
endif()

# Test executable (always built, no BUILD_MAIN macro)
if(NOT CMAKE_CROSSCOMPILING)
    enable_testing()
    add_executable(test_hello tests/test_hello.cpp hello.c)
    target_link_libraries(test_hello PRIVATE gtest gtest_main pthread)
    add_test(NAME HelloTest COMMAND test_hello)
endif()

# Coverage support
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message(STATUS "Enabling code coverage flags")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

    # Ensure test_hello is instrumented
    if(TARGET test_hello)
        target_compile_options(test_hello PRIVATE -O0 -g --coverage -fprofile-arcs -ftest-coverage)
        target_link_libraries(test_hello PRIVATE gcov)
    endif()
endif()