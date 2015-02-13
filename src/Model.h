#ifndef Libcellml_Model_h
#define Libcellml_Model_h

#include <memory>
#include <string>
#include <vector>

#include "Component.h"
#include "UnitsOwner.h"

#include "Child.h"
#include "Parent.h"

//! Everything in LibCellML is in this namespace.
namespace libcellml {

class Component;

//! In-memory representation of a CellML model
class Model :
  public Parent<Model, Component>
{

  //! Model name
  std::wstring name_;

  //! Units Owner delegate
  std::shared_ptr<UnitsOwner> unitsOwner_;

public:
  /**
   * Default constructor
   */
  Model();

  /**
   * Constructor
   * \param name The model name
   */
  Model(const std::wstring name);

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
  const std::shared_ptr<Component> createComponent(std::wstring componentName);

  /**
   * Create a child units object, of which this model object is the parent
   * \param unitsName The name of the new units object
   * \return a pointer the newly created units object.
   */
  const std::shared_ptr<Units> createUnits(std::wstring unitsName);

};

} // namespace libcellml

#endif
