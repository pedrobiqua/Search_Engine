cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)

project(search_engine VERSION 1.0)

add_subdirectory(lib)

include(FetchContent)
add_subdirectory(tests/unit-tests)


