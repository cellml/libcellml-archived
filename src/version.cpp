#include "version.h"
#include <sstream>
#include <string>
#include "libcellml_config.h"

const std::string libcellml::getVersion() {
    std::ostringstream os;
    os << LIBCELLML_VERSION_MAJOR << "." << LIBCELLML_VERSION_MINOR << "." << LIBCELLML_VERSION_PATCH << std::endl;
    return os.str();
}
