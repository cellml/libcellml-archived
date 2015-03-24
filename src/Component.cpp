#include "libcellml/Component.h"
#include "libcellml/Model.h"

using namespace std;
using namespace libcellml;


Component::Component(weak_ptr<Model> p, const this_is_private &t)
:
  Child<Model, Component>(p, t),
  unitsOwner_(new UnitsOwner)
{}


const shared_ptr<Variable> Component::createVariable(wstring variableName, boost::optional<weak_ptr<Units>> units) {
  auto v = createChild();
  v->name_ = variableName;
  v->units_ = units;
  return v;
}

const shared_ptr<Units> Component::createUnits(wstring unitsName) {
  auto u = unitsOwner_->createUnits(unitsName);
  return u;
}
