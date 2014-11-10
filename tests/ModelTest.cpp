#include <memory>
#include <iostream>
#include "Manager.h"
#include "Model.h"


#include "gtest/gtest.h"

using namespace libcellml::general;
using namespace std;

//! Test creation of empty model using manager
TEST(Model, ModelNaming) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto m1 = m->createModel(L"test model");
  ASSERT_EQ(m1->getName(), L"test model");
}


//! Test creation of empty component using model
TEST(Model, ComponentCreation) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto m1 = m->createModel(L"test model");
  ASSERT_EQ(m1->getName(), L"test model");
  auto c1 = m1->createComponent(L"test component");
  ASSERT_NE(c1, nullptr);
}


