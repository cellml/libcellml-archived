#ifndef Libcellml_Component_h
#define Libcellml_Component_h

#include <memory>
#include <string>
#include <vector>

#include "Model.h"
#include "Variable.h"
#include "Child.h"
#include "Parent.h"


namespace libcellml {
namespace model {

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

public:
  Component(std::weak_ptr<Model>, const this_is_private &);

  /**! Component name attribute
   * \return component name
   */
  std::wstring getName() const {
    return name_;
  }

  /**
   * Create a child variable object, of which this component object is the parent
   * \param variableName The name of the new variable
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<libcellml::model::Variable> createVariable(std::wstring variableName);

};

} // namespace model
} // namespace libcellml

#endif
