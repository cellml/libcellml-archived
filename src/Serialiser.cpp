#include <Serialiser.h>

#include <memory>
#include <iostream>
#include <strstream>
#include <string>

#include "cellml_1_2.hxx"

using namespace std;
using namespace cellml12;


string Serialiser::createXml(const Manager& m) {
  ostringstream oss;

  auto models = m.getChildrenReadOnly();
  for( auto model : models) {
    auto modelName = model->getName();

    cellml12::Model modelXml(modelName);

    auto components = model->getChildrenReadOnly();
    for( auto component : components) {
      auto compName = component->getName();
      cellml12::Component componentXml(compName);
      modelXml.getComponent().push_back(componentXml);
    }
    serializeModel(oss, modelXml);
  }

  return oss.str();

}

