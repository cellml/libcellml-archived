#include "Variable.h"
#include "Component.h"

using namespace std;
using namespace libcellml::model;


Variable::Variable(weak_ptr<Component> p, const this_is_private &t) : Child<Component, Variable>(p, t){}

