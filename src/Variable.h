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
  std::weak_ptr<const Unit> const getUnit() const {
    return unit_;
  }

  /**! Returns the collection of variables connected to this variable.
   * \return Variables connected to this variable
   */
  const std::vector<std::weak_ptr<const Variable>>& getConnectedVariables() const{
    std::vector<std::weak_ptr<const Variable>> dummy;
    return std::move(dummy);
  }

  /**! Connect a variable to this variable
   */
  void connect(std::weak_ptr<Variable>){}
};

} // namespace model
} // namespace libcellml

#endif
