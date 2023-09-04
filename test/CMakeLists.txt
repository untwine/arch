add_library(archTest
    testArchAbi.cpp
    testArchUtil.cpp
)

target_include_directories(archTest
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(archTest
    PUBLIC
        arch
)

if (WIN32)
    # Expand 'add_test' to copy dependent DLLs in the same folder after
    # building target to ensure that tests can run properly on Windows.
    macro(add_test NAME)
        add_custom_command(
            TARGET ${NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND}
            -E copy_if_different
            $<TARGET_RUNTIME_DLLS:${NAME}>
            $<TARGET_FILE_DIR:${NAME}>
            COMMAND_EXPAND_LISTS
        )
        _add_test(${NAME} ${ARGV})
    endmacro()
endif()

add_library(testArchAbiPlugin testArchAbiPlugin.cpp)

target_link_libraries(testArchAbiPlugin
    PUBLIC
        arch
        archTest
)

add_executable(testArchAbi testArchAbi.cpp)
target_link_libraries(testArchAbi
    PRIVATE
        arch
        testArchAbiPlugin
)
add_test(testArchAbi testArchAbi)

add_executable(testArchPRead testArchPRead.cpp)
target_link_libraries(testArchPRead
    PRIVATE
        arch
)

add_executable(testArchAttributes testAttributes.cpp)
target_link_libraries(testArchAttributes
    PRIVATE
        arch
)
add_test(testArchAttributes testArchAttributes)

add_executable(testArchDemangle testDemangle.cpp)
target_link_libraries(testArchDemangle
    PRIVATE
        arch
)
add_test(testArchDemangle testArchDemangle)

add_executable(testArchErrno testErrno.cpp)
target_link_libraries(testArchErrno
    PRIVATE
        arch
)
add_test(testArchErrno testArchErrno)

add_executable(testArchError testError.cpp)
target_link_libraries(testArchError
    PRIVATE
        arch
        archTest
)
add_test(testArchError testArchError)

add_executable(testArchFileSystem testFileSystem.cpp)
target_link_libraries(testArchFileSystem
    PRIVATE
        arch
)
add_test(testArchFileSystem testArchFileSystem)

add_executable(testArchFunction testFunction.cpp)
target_link_libraries(testArchFunction
    PRIVATE
        arch
)
add_test(testArchFunction testArchFunction)

add_executable(testArchMath testMath.cpp)
target_link_libraries(testArchMath
    PRIVATE
        arch
)
add_test(testArchMath testArchMath)

add_executable(testArchStackTrace testStackTrace.cpp)
target_link_libraries(testArchStackTrace
    PRIVATE
        arch
        archTest
)
add_test(testArchStackTrace testArchStackTrace)

add_executable(testArchSymbols testSymbols.cpp)
target_link_libraries(testArchSymbols
    PRIVATE
        arch
)
add_test(testArchSymbols testArchSymbols)

add_executable(testArchSystemInfo testSystemInfo.cpp)
target_link_libraries(testArchSystemInfo
    PRIVATE
        arch
)
add_test(testArchSystemInfo testArchSystemInfo)

add_executable(testArchThreads testThreads.cpp)
target_link_libraries(testArchThreads
    PRIVATE
        arch
)
add_test(testArchThreads testArchThreads)

add_executable(testArchTiming testTiming.cpp)
target_link_libraries(testArchTiming
    PRIVATE
        arch
)
add_test(testArchTiming testArchTiming)

add_executable(testArchVsnprintf testVsnprintf.cpp)
target_link_libraries(testArchVsnprintf
    PRIVATE
        arch
)
add_test(testArchVsnprintf testArchVsnprintf)
