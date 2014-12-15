#include <Serialiser.h>

#include <iostream>
#include "cellml_1_2.hxx"

using namespace std;
using namespace cellml12;

void Serialiser::createXml() {
  cellml12::model m("blah");
  model_(cout, m);
}

