#include <memory>
#include <iostream>

#include "Model.h"
#include "Component.h"

#include "gtest/gtest.h"

using namespace libcellml;
using namespace std;

//! Test component has name specified during creation
TEST(Component, ComponentNaming) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  auto c1 = m1->createComponent(L"test component");
  ASSERT_EQ(c1->getName(), L"test component");
}

//! Test creating unit within component
TEST(Component, UnitCreation) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  auto c1 = m1->createComponent(L"test component");
  auto u1 = c1->createUnits(L"test unit");
  ASSERT_EQ(u1->getName(), L"test unit");
}


