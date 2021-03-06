/*
Copyright 2015 University of Auckland

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.Some license of other
*/

#include "libcellml/version.h"

#include <sstream>
#include <string>

#include "libcellml_config.h"

const std::string libcellml::getVersion() {
    std::ostringstream os;
    os << LIBCELLML_VERSION_MAJOR << "." << LIBCELLML_VERSION_MINOR << "." << LIBCELLML_VERSION_PATCH;
    return os.str();
}
