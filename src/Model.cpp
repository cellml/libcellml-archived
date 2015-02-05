#include "Model.h"
#include "Component.h"
#include "Child.h"

using namespace std;
using namespace libcellml;

Model::Model(const wstring name)
:
  name_(name),
  unitsOwner_(new UnitsOwner)
{}


const shared_ptr<Component> Model::createComponent(wstring componentName) {
  auto c = createChild();
  c->name_ = componentName;
  return c;
}

const shared_ptr<Unit> Model::createUnit(wstring unitName) {
  auto u = unitsOwner_->createUnit(unitName);
  return u;
}
