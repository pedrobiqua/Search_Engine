add_library(
    search_engine
        SHARED
            src/sum.cpp
            src/subtraction.cpp
            src/hello.cpp
            src/page_rank.cpp
            src/inverted_index.cpp
            src/preprocessing/stemmer.cpp
)

target_include_directories(search_engine PUBLIC include)

target_link_libraries(search_engine
    PUBLIC
    icuio
    icuuc
)

install(
    TARGETS search_engine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
