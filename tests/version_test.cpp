#include <iostream>
#include "libcellml/version.h"

#include "gtest/gtest.h"

using namespace libcellml;

//! IndependentMethod is a test case - here, we have 2 tests for this 1 test case
TEST(Version, Version) {
    auto ver = getVersion();
    EXPECT_EQ("0.1.0", ver);
}


