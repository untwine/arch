// Copyright 2019 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/arch/math.h>
#include <gtest/gtest.h>

#include <string>

using namespace pxr;

static testing::AssertionResult IsCompliant(bool cond, const char* type)
{
    if (!cond) {
        return testing::AssertionFailure()
               << "failed: " << type << " is not IEEE-754 compliant";
    }

    return testing::AssertionSuccess() << type << " is IEEE-754 compliant.";
}

TEST(MathTest, FloatIEEE754Compliance)
{
    auto a = 5.6904566e-28f;
    auto b = 0x12345678;
    auto cond =
        (ArchFloatToBitPattern(a) == b && ArchBitPatternToFloat(b) == a);

    ASSERT_TRUE(IsCompliant(cond, "float"));
}

TEST(MathTest, DoubleIEEE754Compliance)
{
    auto a = 5.6263470058989390e-221;
    auto b = 0x1234567811223344ULL;
    auto cond =
        (ArchDoubleToBitPattern(a) == b && ArchBitPatternToDouble(b) == a);

    ASSERT_TRUE(IsCompliant(cond, "double"));
}

TEST(MathTest, Sign)
{
    ASSERT_EQ(ArchSign(-123), -1);
    ASSERT_EQ(ArchSign(123), 1);
    ASSERT_EQ(ArchSign(0), 0);
}

TEST(MathTest, CountTrailingZeros)
{
    ASSERT_EQ(ArchCountTrailingZeros(1), 0);
    ASSERT_EQ(ArchCountTrailingZeros(2), 1);
    ASSERT_EQ(ArchCountTrailingZeros(3), 0);
    ASSERT_EQ(ArchCountTrailingZeros(4), 2);
    ASSERT_EQ(ArchCountTrailingZeros(5), 0);
    ASSERT_EQ(ArchCountTrailingZeros(6), 1);
    ASSERT_EQ(ArchCountTrailingZeros(7), 0);
    ASSERT_EQ(ArchCountTrailingZeros(8), 3);

    ASSERT_EQ(ArchCountTrailingZeros(65535), 0);
    ASSERT_EQ(ArchCountTrailingZeros(65536), 16);

    ASSERT_EQ(ArchCountTrailingZeros(~((1ull << 32ull) - 1ull)), 32);
    ASSERT_EQ(ArchCountTrailingZeros(1ull << 63ull), 63);
}
