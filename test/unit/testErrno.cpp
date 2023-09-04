// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/arch/errno.h>
#include <gtest/gtest.h>

using namespace pxr;

TEST(ErrnoTest, ErrorMessages)
{
    for (int i = -1; i < 10; i++) {
        ASSERT_NE(ArchStrerror(i), "");
    }
}
