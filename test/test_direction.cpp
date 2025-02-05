#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <direction.h>

TEST(direction, addition)
{
    direction pos(100);
    direction add(-10);

    direction res = pos+add;

    EXPECT_EQ( res, direction(90));
}

TEST(direction, overflow)
{
    direction pos(180);
    direction add(359);

    direction res = pos+add;

    EXPECT_EQ( res, direction(179));
}