#include <gtest/gtest.h>

#include "subtraction.h"

TEST(SubtractionTest, TestSubtraction_Valid) {
    double s = Subtraction(1.0, 1.0);
    EXPECT_NEAR(0.0, s, 0.6);
}