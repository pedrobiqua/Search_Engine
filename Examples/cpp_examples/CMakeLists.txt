cmake_minimum_required(VERSION 3.10)
project(TestSearchEngineCpp)

set(CMAKE_CXX_STANDARD 17)

# Library directory
# Set here your env path to search_engine_cpp/lib
set(LIB_DIR "/home/pedro/projects/teste_search_engine/env/lib/python3.12/site-packages/search_engine_cpp/lib")

# Header directory (change to the correct path if necessary)
# Set here your env path to search_engine_cpp/lib/include
set(INCLUDE_DIR "/home/pedro/projects/teste_search_engine/env/lib/python3.12/site-packages/search_engine_cpp/lib/include")

# Include headers
include_directories(${INCLUDE_DIR})

# Add the main executable
add_executable(main_test main.cpp)

# Add the shared library
add_library(search_engine SHARED IMPORTED)
set_target_properties(search_engine PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/libsearch_engine.so)

# Link the library to the executable
target_link_libraries(main_test PRIVATE search_engine)
