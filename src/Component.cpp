#include "Component.h"
#include "Model.h"

using namespace std;
using namespace libcellml::model;


Component::Component(weak_ptr<Model> p, const this_is_private &t) : Child<Model, Component>(p, t){}

