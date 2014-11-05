#include <memory>
#include <iostream>
#include "Manager.h"


#include "gtest/gtest.h"

using namespace libcellml::general;
using namespace std;

// Test creation of empty model using manager
TEST(Manager, CreateEmptyModel) {
  shared_ptr<Manager> m = make_shared<Manager>();
  const auto v1 = m->createModel();
  ASSERT_NE(v1, nullptr);
}


// Test that creating 2 empty models results in two different objects
TEST(Manager, Create2EmptyModels) {
  shared_ptr<Manager> m = make_shared<Manager>();
  const auto v1 = m->createModel();
  const auto v2 = m->createModel();
  ASSERT_NE(v1, nullptr);
  ASSERT_NE(v2, nullptr);
  ASSERT_NE(v1, v2);
}


// Test that creating 2 empty models results in two different objects
TEST(Manager, ModelPointsToCreator) {
  shared_ptr<Manager> m = make_shared<Manager>();
  const auto v1 = m->createModel();
  ASSERT_EQ(v1->getManager().lock(), m);
}


// Test that 2 different managers are distinct from the point of view of a child model of each
TEST(Manager, ManagersDistinct) {
  shared_ptr<Manager> m1 = make_shared<Manager>();
  shared_ptr<Manager> m2 = make_shared<Manager>();
  const auto v1 = m1->createModel();
  const auto v2 = m2->createModel();
  ASSERT_NE(v1->getManager().lock(), v2->getManager().lock());
}


