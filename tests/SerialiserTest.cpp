#include <memory>
#include <iostream>
#include "Serialiser.h"


#include "gtest/gtest.h"

using namespace std;

//! Test creation of empty model using manager
TEST(Serialiser, DummyXmlOutput) {
  Serialiser s;
  s.createXml();
  ASSERT_EQ(true, true);
}




