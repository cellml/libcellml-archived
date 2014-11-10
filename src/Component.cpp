#include "Component.h"
#include "Model.h"

using namespace std;
using namespace libcellml::model;


Component::Component(wstring name, weak_ptr<Model> model, const this_is_private &):
  model_(model),
  name_(move(name))
{}


const weak_ptr<const Model> Component::getModel() const {
    return model_;
}

