cmake_minimum_required(VERSION 3.10)
project(HelloARM C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Main app (define BUILD_MAIN so main() is included)
add_executable(hello hello.c)
target_compile_definitions(hello PRIVATE BUILD_MAIN)

# Enable testing
enable_testing()

# Test executable (no BUILD_MAIN, so no conflict with gtest main)
add_executable(test_hello tests/test_hello.cpp hello.c)
target_link_libraries(test_hello gtest gtest_main pthread)

add_test(NAME HelloTest COMMAND test_hello)

if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message(STATUS "Enabling code coverage flags")
    add_compile_options(--coverage -O0)
    add_link_options(--coverage)
endif()