#include "Model.h"
#include "Manager.h"

using namespace std;
using namespace libcellml::model;
using namespace libcellml::general;

Model::Model(weak_ptr<Manager> manager, const this_is_private &):
  manager_(manager)
{}


const weak_ptr<const Manager> Model::getManager() const {
    return manager_;
}
