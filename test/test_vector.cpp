#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <vector.h>

TEST(vector, addition)
{
    vector pos(1, 3);
    vector add(-2, 1);

    EXPECT_EQ(pos + add, vector(-1, 4));
}