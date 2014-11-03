#include <iostream>
#include "Manager.h"

#include "gtest/gtest.h"

using namespace libcellml::general;

// Test creation of empty model using manager
TEST(Manager, CreateEmptyModel) {
  Manager m;
  auto v1 = m.createModel();
}


