#include <Units.h>
#include <memory>
#include <iostream>

#include "Model.h"

#include "gtest/gtest.h"

using namespace libcellml;
using namespace std;

//! Test a units has name specified during creation
TEST(Units, UnitsNaming) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");

  auto u1 = m1->createUnits(L"kg");

  ASSERT_EQ(u1->getName(), L"kg");
}

