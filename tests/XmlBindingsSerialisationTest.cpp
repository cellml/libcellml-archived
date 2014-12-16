#include <memory>
#include <iostream>
#include <strstream>
#include <string>

#include "cellml_1_2.hxx"
#include "gtest/gtest.h"

using namespace std;
using namespace cellml12;

string xml1() {
  return
    "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?>\n"
    "<p1:model xmlns:p1=\"http://www.cellml.org/cellml/1.2#\" name=\"modelName\">\n"
    "  <p1:component name=\"c1\">\n"
    "    <p1:variable name=\"v1\" public_interface=\"yes\" type=\"real\" units=\"kg\"/>\n"
    "  </p1:component>\n"
    "  <p1:component name=\"c2\"/>\n"
    "</p1:model>\n";
}


//! Test creation of a model and serialisation to XML
TEST(XmlBindingsSerialisation, SimpleExample01) {
  auto modelName = "modelName";
  cellml12::Model m(modelName);
  cellml12::Component c1("c1");
  cellml12::Variable v1("v1", "kg", "real");

  v1.setPublic_interface(cellml12::Yesno::Value::yes);
  c1.getVariable().push_back(v1);
  m.getComponent().push_back(c1);

  cellml12::Component c2("c2");
  m.getComponent().push_back(c2);

  ostringstream oss;

  serializeModel(oss, m);
  ASSERT_EQ(xml1(), oss.str());

}

//! Test reading in a simple model from XML text.
TEST(XmlBindingsDeserialisation, SimpleExample01) {

  istringstream iss (xml1());

  auto m2 = parseModel(iss, xml_schema::Flags::dont_validate);

  ostringstream oss;
  oss << "Read in model name: " << m2->getName() << endl;
  oss << "  Components:" << endl;
  auto cs = m2->getComponent();
  for (auto c : cs) {
    oss << "    " << c.getName() << endl;
    auto vs = c.getVariable();
    oss << "      Variables:" << endl;
    for (auto v : vs) {
      oss << "        " << v.getName() << "::" << v.getType() << "(private: " << v.getPrivate_interface() << ", public: " << v.getPublic_interface() << ")" << endl;
    }
  }

  string expectedSummary(
"Read in model name: modelName\n"
"  Components:\n"
"    c1\n"
"      Variables:\n"
"        v1::real(private: <not present>, public: yes)\n"
"    c2\n"
"      Variables:\n");
  ASSERT_EQ(expectedSummary, oss.str());
}
