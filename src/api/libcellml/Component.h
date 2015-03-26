#ifndef Libcellml_Component_h
#define Libcellml_Component_h

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include "model.h"
#include "Variable.h"
#include "UnitsOwner.h"

#include "Child.h"
#include "Parent.h"


namespace libcellml {

class Model;
class Variable;

//! In-memory representation of a CellML component
class Component :
  public Child<Model, Component>,
  public Parent<Component, Variable>
{
  friend class Model;

  //! Component name
  std::wstring name_;

  //! Units Owner delegate
  std::shared_ptr<UnitsOwner> unitsOwner_;

public:
  Component(std::weak_ptr<Model>, const this_is_private &);

  /** Component name attribute
   * \return component name
   */
  std::wstring getName() const {
    return name_;
  }

  /**
   * Create a child variable object, of which this component object is the parent
   * \param variableName The name of the new variable
   * \param units The units object.
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<Variable> createVariable(std::wstring variableName, boost::optional<std::weak_ptr<Units>> units);

  /**
   * Create a units object, of which this component object is the parent
   * \param unitsName The name of the new units object
   * \return a pointer the newly created units object
   */
  const std::shared_ptr<Units> createUnits(std::wstring unitsName);

};


} // namespace libcellml

#endif
