#include <Serialiser.h>

#include <iostream>
#include "cellml_1_2.hxx"

using namespace std;
using namespace cellml12;

void Serialiser::createXml() {
  cellml12::model m("blah");
  cellml12::component c1("c1");
  cellml12::variable v1("v1", "kg", "real");

  v1.public_interface(cellml12::yesno::value::yes);
  v1.private_interface(cellml12::yesno::value::yes);

  c1.variable().push_back(v1);
  m.component().push_back(c1);

  cellml12::component c2("c2");
  m.component().push_back(c2);

  model_(cout, m);
  auto m2 = model_("example01.xml");
  cout << endl;
  cout << "Read in model name: " << m2->name() << endl;
}

