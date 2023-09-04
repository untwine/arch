if (WIN32)
    # Patch Gtest discovery command to extend the DLL search path on Windows.

    macro(gtest_discover_tests NAME)
        gtest_add_tests(TARGET ${NAME} TEST_LIST tests)

        # Sanitize and extend environment.
        cmake_parse_arguments("" "" "" "PROPERTIES" ${ARGN})
        cmake_parse_arguments("" "" "" "ENVIRONMENT" ${_PROPERTIES})

        # Apply environment to newly added tests.
        set(DLL_DIRS $<TARGET_RUNTIME_DLL_DIRS:${NAME}>)

        set_tests_properties(${tests}
            PROPERTIES ENVIRONMENT
            "${_ENVIRONMENT};PATH=$<JOIN:$<SHELL_PATH:${DLL_DIRS}>,\\;>")
    endmacro()

    # Patch CMake's 'add_test' to extend the DLL search path on Windows based
    # on the command associated with the test, which is also a CMake target in
    # this case.

    macro(add_test)
        _add_test(${ARGV})

        cmake_parse_arguments("" "" "NAME;COMMAND" "" ${ARGV})
        set(DLL_DIRS $<TARGET_RUNTIME_DLL_DIRS:${_COMMAND}>)
        set_tests_properties(${_NAME}
            PROPERTIES ENVIRONMENT
            "PATH=$<JOIN:$<SHELL_PATH:${DLL_DIRS}>,\\;>")
    endmacro()
endif()

add_executable(testArchAbi testArchAbi.cpp)
target_link_libraries(testArchAbi
    PRIVATE
        arch
        archTest
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(
    testArchAbi
    PROPERTIES
        ENVIRONMENT "EXE_PATH=$<SHELL_PATH:$<TARGET_FILE_DIR:testArchAbi>>"
        ENVIRONMENT "PLUGIN_PATH=$<TARGET_FILE_DIR:archTestPlugin>"
)

add_executable(testArchAttributes testAttributes.cpp)
target_link_libraries(testArchAttributes
    PRIVATE
        arch
        GTest::gtest
)
add_test(NAME AttributeTest.OperationOrder COMMAND testArchAttributes)

add_executable(testArchDemangle testDemangle.cpp)
target_link_libraries(testArchDemangle
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchDemangle)

add_executable(testArchError testError.cpp)
target_link_libraries(testArchError
    PRIVATE
        arch
        archTest
)
add_test(NAME ErrorTest.TestCrash COMMAND testArchError)

add_executable(testArchErrno testErrno.cpp)
target_link_libraries(testArchErrno
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchErrno)

add_executable(testArchFileSystem testFileSystem.cpp)
target_link_libraries(testArchFileSystem
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchFileSystem)

add_executable(testArchFunction testFunction.cpp)
target_link_libraries(testArchFunction
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchFunction)

add_executable(testArchMath testMath.cpp)
target_link_libraries(testArchMath
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchMath)

add_executable(testArchStackTrace testStackTrace.cpp)
target_link_libraries(testArchStackTrace
    PRIVATE
        arch
        archTest
        GTest::gtest
)
gtest_discover_tests(testArchStackTrace)

add_executable(testArchSymbols testSymbols.cpp)
target_link_libraries(testArchSymbols
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchSymbols)

add_executable(testArchSystemInfo testSystemInfo.cpp)
target_link_libraries(testArchSystemInfo
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchSystemInfo)

add_executable(testArchThreads testThreads.cpp)
target_link_libraries(testArchThreads
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchThreads)

add_executable(testArchTiming testTiming.cpp)
target_link_libraries(testArchTiming
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchTiming)

add_executable(testArchVsnprintf testVsnprintf.cpp)
target_link_libraries(testArchVsnprintf
    PRIVATE
        arch
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testArchVsnprintf)
