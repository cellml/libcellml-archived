#include <iostream>
#include "Version.h"

#include "gtest/gtest.h"


//! IndependentMethod is a test case - here, we have 2 tests for this 1 test case
TEST(Version, Version) {
    auto v1 = libcellml::general::getVersion();
    auto v2 = libcellml::general::getVersion();
    EXPECT_EQ(v1, v2);
}


