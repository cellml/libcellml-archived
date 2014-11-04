#include <memory>
#include <iostream>
#include "Manager.h"


#include "gtest/gtest.h"

using namespace libcellml::general;
using namespace std;

// Test creation of empty model using manager
TEST(Manager, CreateEmptyModel) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto v1 = m->createModel();
  ASSERT_FALSE(v1 == nullptr);
}


// Test that creating 2 empty models results in two different objects
TEST(Manager, Create2EmptyModels) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto v1 = m->createModel();
  auto v2 = m->createModel();
  ASSERT_FALSE(v1 == v2);
}


// Test that creating 2 empty models results in two different objects
TEST(Manager, ModelPointsToCreator) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto v1 = m->createModel();
  ASSERT_TRUE(v1->getManager().lock() == m);
}


