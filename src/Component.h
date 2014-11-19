#ifndef Libcellml_Component_h
#define Libcellml_Component_h

#include <memory>
#include <string>
#include <vector>

#include "Model.h"
#include "Child.h"

namespace libcellml {
namespace model {

class Model;

//! In-memory representation of a CellML component
class Component : public Child<Model, Component>{
  friend class Model;

  //! Component name
  std::wstring name_;

public:
  Component(std::weak_ptr<Model>, const this_is_private &);

  /**! Component name attribute
   * \return component name
   */
  std::wstring getName() const {
    return name_;
  }

};

} // namespace model
} // namespace libcellml

#endif
