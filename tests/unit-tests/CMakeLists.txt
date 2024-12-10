set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)

add_executable(
    LibUnitTests
    tests.cpp
    sum-test.cpp
    subtraction-test.cpp
    page_rank-test.cpp
    inverted_index-test.cpp
)

target_include_directories(LibUnitTests PRIVATE ${CMAKE_SOURCE_DIR}/lib/include/)

target_link_libraries(LibUnitTests PRIVATE gtest_main search_engine)