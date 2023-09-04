// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/arch/systemInfo.h>
#include <gtest/gtest.h>

using namespace pxr;

using std::string;

TEST(SystemInfoTest, GetExecutablePath)
{
    ASSERT_NE(ArchGetExecutablePath().find("testArch", 0), string::npos);
}
