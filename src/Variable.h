#ifndef Libcellml_Variable_h
#define Libcellml_Variable_h

#include <memory>
#include <string>
#include <vector>

#include "Component.h"
#include "Child.h"

namespace libcellml {
namespace model {

class Component;

//! In-memory representation of a CellML Variable
class Variable : public Child<Component, Variable>{
  friend class Component;

  //! Variable name
  std::wstring name_;

public:
  Variable(std::weak_ptr<Component>, const this_is_private &);

  /**! Variable's name attribute
   * \return Variable's name
   */
  std::wstring getName() const {
    return name_;
  }

};

} // namespace model
} // namespace libcellml

#endif
