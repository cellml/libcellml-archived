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

#include "libcellml/xml_serialisation.h"
#include <memory>
#include <iostream>
#include <strstream>
#include <string>

#include "Cellml_1_2.h"

namespace libcellml {

std::string createXml(const libcellml::Model& model) {
  cellml12::Model modelXml;

  std::ostringstream oss;
  cellml12::serializeModel(oss, modelXml);
  return oss.str();
}

}  // namespace libcellml
