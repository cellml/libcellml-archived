#include <memory>
#include <iostream>

#include "Model.h"
#include "Component.h"
#include "Variable.h"

#include "XmlSerialisation.h"

#include "gtest/gtest.h"

using namespace std;
using namespace libcellml;

//! Test creation of simple model using Model
TEST(XmlSerialisation, simpleXmlOutput) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  auto c1 = m1->createComponent(L"test component");
  weak_ptr<Unit> u1 = m1->createUnit(L"kg");
  auto v1 = c1->createVariable(L"test variable", u1);

  auto xml = createXml(*m1);

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


//! Test serialising model that has a variable that is missing units.
TEST(XmlSerialisation, xmlOutput_VarMissingUnits) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  auto c1 = m1->createComponent(L"test component");
  auto v1 = c1->createVariable(L"test variable", boost::none);

  auto xml = createXml(*m1);

  string expectedXml(
R"(<?xml version="1.0" encoding="UTF-8" standalone="no" ?>
<p1:model xmlns:p1="http://www.cellml.org/cellml/1.2#" name="test model">
  <p1:component name="test component">
    <p1:variable name="test variable" type="real" units=""/>
  </p1:component>
</p1:model>
)");

  ASSERT_EQ(expectedXml, xml);
}




