#include "Units.h"
#include "UnitsOwner.h"

using namespace std;
using namespace libcellml;

Units::Units(weak_ptr<UnitsOwner> p, const this_is_private &t) : Child<UnitsOwner, Units>(p, t){}
