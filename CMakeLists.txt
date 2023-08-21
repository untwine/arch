cmake_minimum_required(VERSION 3.21...3.30)

# Default build type value.
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type")

project(pxr-arch
    HOMEPAGE_URL "https://github.com/untwine/pxr-arch"
    LANGUAGES C CXX
)

include(GNUInstallDirs)

if (NOT "${CMAKE_CXX_STANDARD}")
    set(CMAKE_CXX_STANDARD 17 CACHE STRING "Default C++ standard")
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default options.
option(BUILD_TESTS "Build tests" ON)
option(BUILD_DOCS "Build documentation" ON)
option(BUILD_SHARED_LIBS "Build Shared Library" ON)
option(ENABLE_PRECOMPILED_HEADERS "Enable precompiled headers." OFF)

if (NOT BUILD_SHARED_LIBS)
    add_compile_definitions(PXR_STATIC)
endif()

if (WIN32)
    # Prevent WinDef.h from defining min/max macros.
    add_definitions(-DNOMINMAX)

    # Exclude unnecessary Windows APIs for faster builds and fewer macro conflicts.
    add_definitions(-DWIN32_LEAN_AND_MEAN)

    # Disable /Zc:inline in VS 2019+ to retain "arch_ctor_<name>" symbols in release.
    # https://developercommunity.visualstudio.com/t/914943
    if (MSVC_VERSION GREATER_EQUAL 1920)
        set(CMAKE_CXX_FLAGS "/Zc:inline- ${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "/Zc:inline ${CMAKE_CXX_FLAGS}")
    endif()
endif()

# Update build type from environment for CMake < 3.22
if (DEFINED ENV{CMAKE_BUILD_TYPE})
    set(CMAKE_BUILD_TYPE $ENV{CMAKE_BUILD_TYPE}
        CACHE STRING "Specifies the build type" FORCE)
endif()

find_package(Threads REQUIRED)

add_subdirectory(src)

# Build and setup tests if required.
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# Build documentation if required.
if (BUILD_DOCS)
    find_package(Sphinx 1.8.6 REQUIRED)
    find_package(Doxygen 1.8.5 REQUIRED)

    add_subdirectory(doc)
endif()

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "cmake/pxr-arch-config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/pxr-arch-config.cmake"
    INSTALL_DESTINATION share/cmake/pxr-arch
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/pxr-arch-config.cmake"
    DESTINATION share/cmake/pxr-arch
)
