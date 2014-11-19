#include "Model.h"
#include "Manager.h"
#include "Component.h"

using namespace std;
using namespace libcellml::model;
using namespace libcellml::general;


Model::Model(weak_ptr<Manager> p, const this_is_private &t) : Child<Manager, Model>(p, t){}


const shared_ptr<Component> Model::createComponent(wstring componentName) {
  auto c = createChild();
  c->name_ = componentName;
  return c;
}
