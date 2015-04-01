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

#ifndef LIBCELLML_LIBCELLML_MODEL_H_
#define LIBCELLML_LIBCELLML_MODEL_H_

#include <string>
#include <boost/optional.hpp>

#include "libcellml/libcellml_export.h"

//! Everything in LibCellML is in this namespace.
namespace libcellml {

//! In-memory representation of a CellML model.
class LIBCELLML_EXPORT Model {
  //! Model name
  boost::optional<std::wstring> name_;

 public:
  /**
   * Default constructor.
   */
  Model();

  /**
   * Constructor
   * \param name The model name
   */
  Model(const boost::optional<std::wstring> name);

  /** Model name attribute
   * \return Model name
   */
  boost::optional< std::wstring> getName() const {
    return name_;
  }

};

}  // namespace libcellml

#endif  // LIBCELLML_LIBCELLML_MODEL_H_
