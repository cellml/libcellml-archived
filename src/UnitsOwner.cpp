#include <libcellml/Units.h>
#include "libcellml/UnitsOwner.h"

using namespace std;
using namespace libcellml;

const shared_ptr<Units> UnitsOwner::createUnits(wstring unitsName) {
  auto u = createChild();
  u->name_ = unitsName;
  return u;
}
