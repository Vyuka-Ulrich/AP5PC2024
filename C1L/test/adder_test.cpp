#include <gtest/gtest.h>
#include <adder.h>

// Demonstrate some basic assertions.
TEST(AdderTest, Two_positive_Integers_add_up) {
  ASSERT_EQ(add(5,6), 11);
}