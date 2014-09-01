#include <sstream>
#include <string>
#include "Version.h"
#include "LibcellmlConfig.h"

using namespace std;

const string libcellml::general::getVersion() {
    ostringstream os;
    os << LIBCELLML_VERSION_MAJOR << "." << LIBCELLML_VERSION_MAJOR << endl;
    return os.str();
}