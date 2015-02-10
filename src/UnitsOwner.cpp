#include "Units.h"
#include "UnitsOwner.h"

using namespace std;
using namespace libcellml;

const shared_ptr<Units> UnitsOwner::createUnits(wstring unitsName) {
  auto u = createChild();
  u->name_ = unitsName;
  return u;
}
