#ifndef Libcellml_Variable_h
#define Libcellml_Variable_h

#include <memory>
#include <string>
#include <vector>

#include "Component.h"
#include "Unit.h"

#include "Child.h"

namespace libcellml {
namespace model {

class Component;

//! In-memory representation of a CellML Variable
class Variable : public Child<Component, Variable>{
  friend class Component;

  //! Variable name
  std::wstring name_;

  //! Unit of measure
  std::weak_ptr<Unit> unit_;

public:
  Variable(std::weak_ptr<Component>, const this_is_private &);

  /**! Variable's name attribute
   * \return Variable's name
   */
  std::wstring getName() const {
    return name_;
  }

  /**! Variable's name attribute
   * \return Variable's name
   */
  std::weak_ptr<Unit> getUnit() const {
    return unit_; //! todo: is this const correct?
  }

};

} // namespace model
} // namespace libcellml

#endif
