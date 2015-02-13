#include <memory>
#include <iostream>
#include "Model.h"

#include "gtest/gtest.h"

using namespace libcellml;
using namespace std;

// todo: use boost::optional to indicate whether or not name attribute is present.
//! Test model construction without naming the model.
TEST(Model, ModelNameless) {
  shared_ptr<Model> m1 = make_shared<Model>();
  ASSERT_EQ(m1->getName(), L"");
}


//! Test model has name specified during creation
TEST(Model, ModelNaming) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  ASSERT_EQ(m1->getName(), L"test model");
}


//! Test creation of empty component using model
TEST(Model, ComponentCreation) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  ASSERT_EQ(m1->getName(), L"test model");
  auto c1 = m1->createComponent(L"test component");
  ASSERT_NE(c1, nullptr);
  ASSERT_EQ(c1->getName(), L"test component");
}


