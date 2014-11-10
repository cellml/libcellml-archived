#include "Model.h"
#include "Manager.h"

using namespace std;
using namespace libcellml::model;
using namespace libcellml::general;


Model::Model(wstring name, weak_ptr<Manager> manager, const this_is_private &):
  manager_(manager),
  name_(move(name))
{}


const weak_ptr<const Manager> Model::getManager() const {
    return manager_;
}


const shared_ptr<Component> Model::createComponent(wstring componentName) {
  shared_ptr<Component> componentp(Component::create(componentName, shared_from_this()));
  components_.push_back(componentp);
  return components_.back();
}
