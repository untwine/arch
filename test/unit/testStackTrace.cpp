// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/arch/fileSystem.h>
#include <pxr/arch/stackTrace.h>
#include <archTest/util.h>
#include <gtest/gtest.h>

#include <cstdio>
#include <string>

using namespace pxr;

TEST(StackTraceTest, TestCrash)
{
    ASSERT_FALSE(ArchIsAppCrashing());

    std::string log = ArchMakeTmpFileName("statusLogTester");
    FILE *logFile;

    ASSERT_NE((logFile = ArchOpenFile(log.c_str(), "w")), nullptr);
    fputs("fake log\n", logFile);
    fputs("let's throw in a weird printf %1024$s specifier\n", logFile);
    fclose(logFile);

    ArchLogStackTrace("Crashing", true, log.c_str());
    ArchUnlinkFile(log.c_str());

    ASSERT_FALSE(ArchIsAppCrashing());
    ArchLogCurrentProcessState("Test Non-Fatal");

    ASSERT_FALSE(ArchIsAppCrashing());
    ArchLogFatalProcessState("Test Fatal");

    // Now we should be marked as crashing
    ASSERT_TRUE(ArchIsAppCrashing());

    // test crashing with and without spawning
    ArchTestCrash(ArchTestCrashMode::ReadInvalidAddresses);
    ArchTestCrash(ArchTestCrashMode::ReadInvalidAddressesWithThread);

    // test GetStackTrace
    std::vector<std::string> stackTrace = ArchGetStackTrace(20);
    bool found = false;
    for (unsigned int i = 0; i < stackTrace.size(); i++) {
        found |= (stackTrace[i].find("main", 0) != std::string::npos);
    }
#if defined(ARCH_OS_WINDOWS) && !defined(_DEBUG)
    // Release builds on windows can't get symbolic names.
    found |= !stackTrace.empty();
#endif
    ASSERT_TRUE(found);
}

int main(int argc, char** argv)
{
    ArchSetProgramNameForErrors("testArch ArchError");
    ArchTestCrashArgParse(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
