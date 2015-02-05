#include <memory>
#include <iostream>

#include "Model.h"

#include <Unit.h>

#include "gtest/gtest.h"

using namespace libcellml;
using namespace std;

//! Test unit has name specified during creation
TEST(Unit, UnitNaming) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");

  auto u1 = m1->createUnit(L"kg");

  ASSERT_EQ(u1->getName(), L"kg");
}

