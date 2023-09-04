add_library(archTestPlugin SHARED main.cpp)

target_link_libraries(archTestPlugin
    PUBLIC
        arch
        archTest
)
