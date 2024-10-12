#include <gtest/gtest.h>
#include "mylib.hh"

// Simple test for the 'add' function from the library
TEST(MyLibTest, AddTest) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0), 0);
}
