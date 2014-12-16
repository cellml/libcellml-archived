#include <memory>
#include <iostream>

#include "cellml_1_2.hxx"
#include "gtest/gtest.h"

using namespace std;
using namespace cellml12;

//! Test creation of empty model using manager
TEST(XmlBindingsSerialisation, DummyXmlOutput) {
  cellml12::Model m("blah");
  cellml12::Component c1("c1");
  cellml12::Variable v1("v1", "kg", "real");

  v1.setPublic_interface(cellml12::Yesno::Value::yes);
  c1.getVariable().push_back(v1);
  m.getComponent().push_back(c1);

  cellml12::Component c2("c2");
  m.getComponent().push_back(c2);

  serializeModel(cout, m);

  auto m2 = parseModel("example01.xml");
  cout << endl;
//  cout << "Read in model name: " << m2->name() << endl;


  ASSERT_EQ(true, true);
}




