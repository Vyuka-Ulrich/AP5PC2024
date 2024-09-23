#include <adder.h>
#include <gtest/gtest.h>

TEST(MojeTesty, Test_Adder_Adds_Integers) {
    ASSERT_EQ(add(5,6), 10);
}