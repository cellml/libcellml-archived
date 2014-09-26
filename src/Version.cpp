#include <sstream>
#include <string>
#include "Version.h"
#include "LibcellmlConfig.h"

using namespace std;

static string badVersion;

const string libcellml::general::getVersion() {
    badVersion = badVersion + "... more junk";
    ostringstream os;
    os << LIBCELLML_VERSION_MAJOR << "." << LIBCELLML_VERSION_MINOR << endl;
//    return os.str();
    return badVersion;
}