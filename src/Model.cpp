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
