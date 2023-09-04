add_library(arch
    pxr/arch/align.cpp
    pxr/arch/assumptions.cpp
    pxr/arch/attributes.cpp
    pxr/arch/daemon.cpp
    pxr/arch/debugger.cpp
    pxr/arch/demangle.cpp
    pxr/arch/env.cpp
    pxr/arch/errno.cpp
    pxr/arch/error.cpp
    pxr/arch/fileSystem.cpp
    pxr/arch/function.cpp
    pxr/arch/hash.cpp
    pxr/arch/initConfig.cpp
    pxr/arch/library.cpp
    pxr/arch/mallocHook.cpp
    pxr/arch/regex.cpp
    pxr/arch/stackTrace.cpp
    pxr/arch/symbols.cpp
    pxr/arch/systemInfo.cpp
    pxr/arch/threads.cpp
    pxr/arch/timing.cpp
    pxr/arch/virtualMemory.cpp
    pxr/arch/vsnprintf.cpp
)

target_include_directories(arch
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(arch
    PUBLIC
        Threads::Threads
        ${CMAKE_DL_LIBS}
)

if (WIN32)
    target_link_libraries(arch PUBLIC Ws2_32.lib Dbghelp.lib)
endif()

if (ENABLE_PRECOMPILED_HEADERS)
    target_precompile_headers(arch
        PRIVATE
            pxr/arch/pch.h
    )
endif()

set_target_properties(arch
    PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        OUTPUT_NAME "PxrArch"
)

target_compile_definitions(arch
    PRIVATE
        ARCH_EXPORTS
        MFB_PACKAGE_NAME=arch
        MFB_ALT_PACKAGE_NAME=arch
)

install(
    TARGETS arch EXPORT ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    FILES
        pxr/arch/align.h
        pxr/arch/api.h
        pxr/arch/attributes.h
        pxr/arch/buildMode.h
        pxr/arch/daemon.h
        pxr/arch/debugger.h
        pxr/arch/defines.h
        pxr/arch/demangle.h
        pxr/arch/env.h
        pxr/arch/errno.h
        pxr/arch/error.h
        pxr/arch/export.h
        pxr/arch/fileSystem.h
        pxr/arch/function.h
        pxr/arch/functionLite.h
        pxr/arch/hash.h
        pxr/arch/hints.h
        pxr/arch/inttypes.h
        pxr/arch/library.h
        pxr/arch/mallocHook.h
        pxr/arch/math.h
        pxr/arch/pragmas.h
        pxr/arch/regex.h
        pxr/arch/stackTrace.h
        pxr/arch/symbols.h
        pxr/arch/systemInfo.h
        pxr/arch/threads.h
        pxr/arch/timing.h
        pxr/arch/virtualMemory.h
        pxr/arch/vsnprintf.h
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/pxr/arch
)

install(EXPORT ${PROJECT_NAME}
    FILE pxr-arch-targets.cmake
    NAMESPACE pxr::
    DESTINATION share/cmake/pxr-arch
)
