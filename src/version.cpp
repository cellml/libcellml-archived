#include <sstream>
#include <string>
#include "libcellml/version.h"
#include "libcellml_config.h"

const std::string libcellml::getVersion() {
    std::ostringstream os;
    os << LIBCELLML_VERSION_MAJOR << "." << LIBCELLML_VERSION_MINOR << std::endl;
    return os.str();
}
