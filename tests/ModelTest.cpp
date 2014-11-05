#include <memory>
#include <iostream>
#include "Manager.h"
#include "Model.h"


#include "gtest/gtest.h"

using namespace libcellml::general;
using namespace std;

// Test creation of empty model using manager
TEST(Model, ModelNaming) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto m1 = m->createModel();
  ASSERT_EQ(m1->getName(), L"");
}


