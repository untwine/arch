// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/arch/threads.h>
#include <gtest/gtest.h>

using namespace pxr;

TEST(ThreadTest, IsMainThread) {
    ASSERT_TRUE(ArchIsMainThread());
}
