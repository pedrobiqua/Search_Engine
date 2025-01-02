#include <gtest/gtest.h>

#include "sum.h"

TEST(SumTest, TestSum_Valid) {
    double s = Sum(1.0, 1.0);
    EXPECT_NEAR(2.0, s, 0.6);
}