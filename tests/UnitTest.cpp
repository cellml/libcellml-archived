#include <memory>
#include <iostream>
#include "UnitsOwner.h"
#include "Unit.h"

#include "gtest/gtest.h"

using namespace libcellml::model;
using namespace std;

//! Test unit has name specified during creation
TEST(Unit, UnitNaming) {
  shared_ptr<UnitsOwner> uo = make_shared<UnitsOwner>(); // todo: owner shouldn't float, should be Model or Component.
  auto u1 = uo->createUnit(L"kg");

  ASSERT_EQ(u1->getName(), L"kg");
}

