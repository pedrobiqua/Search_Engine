cmake_minimum_required(VERSION 3.22)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

project(search_engine VERSION 1.0)

add_subdirectory(lib)

option(BUILD_TESTS "Build and enable tests" ON)

if (BUILD_TESTS)
    enable_testing()
    include(FetchContent)
    add_subdirectory(tests/unit-tests)
endif()
