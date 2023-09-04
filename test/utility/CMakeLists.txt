add_library(archTest
    archTest/util.cpp
)

target_include_directories(archTest
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(archTest
    PUBLIC
        arch
)

add_subdirectory(plugins)
