#ifndef Libcellml_Model_h
#define Libcellml_Model_h

#include <memory>
#include <string>
#include <vector>

#include "Component.h"
#include "UnitsOwner.h"

#include "Child.h"
#include "Parent.h"

namespace libcellml {

namespace general {
class Manager;
}

//! Namespace for entities directly related to defining CellML 1.2 models.
namespace model {

class Component;

//! In-memory representation of a CellML model
class Model :
  public Child<general::Manager, Model>,
  public Parent<Model, Component>
{
  friend class general::Manager;

  //! Model name
  std::wstring name_;

  //! Units Owner delegate
  std::shared_ptr<UnitsOwner> unitsOwner_;

public:
  Model(std::weak_ptr<general::Manager> p, const this_is_private &t);

  /** Model name attribute
   * \return model name
   */
  std::wstring getName() const {
    return name_;
  }

  /**
   * Create a child component object, of which this model object is the parent
   * \param componentName The name of the new component
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<libcellml::model::Component> createComponent(std::wstring componentName);

  /**
   * Create a child unit object, of which this model object is the parent
   * \param unitName The name of the new unit
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<libcellml::model::Unit> createUnit(std::wstring unitName);

};

} // namespace model
} // namespace libcellml

#endif
