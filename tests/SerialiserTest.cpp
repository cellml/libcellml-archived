#include <memory>
#include <iostream>

#include "Serialiser.h"
#include <Manager.h>
#include <Model.h>
#include <Component.h>
#include <Variable.h>

#include "gtest/gtest.h"

using namespace std;
using namespace libcellml::general;

//! Test creation of simple model using manager
TEST(Serialiser, simpleXmlOutput) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto m1 = m->createModel(L"test model");
  auto c1 = m1->createComponent(L"test component");
  auto v1 = c1->createVariable(L"test variable");

  Serialiser s;
  auto xml = s.createXml(*m);

  string expectedXml(
R"(<?xml version="1.0" encoding="UTF-8" standalone="no" ?>
<p1:model xmlns:p1="http://www.cellml.org/cellml/1.2#" name="test model">
  <p1:component name="test component">
    <p1:variable name="test variable" type="real" units="kg"/>
  </p1:component>
</p1:model>
)");

  ASSERT_EQ(expectedXml, xml);
}




