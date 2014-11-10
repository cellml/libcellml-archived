#ifndef Libcellml_Component_h
#define Libcellml_Component_h

#include <memory>
#include <string>
#include <vector>

#include "Model.h"

namespace libcellml {
namespace model {

class Model;

//! In-memory representation of a CellML component
class Component {
  friend class Model;

  /** make_shared workaround: Hidden class, effectively makes public constructor private.

   This is take from http://stackoverflow.com/a/8147326
   */
  struct this_is_private {
  };

  //! make_shared workaround: create only accessible to friend. \see Model::createComponent
  static std::shared_ptr<Component> create(std::wstring name, std::weak_ptr<Model> model) {
    return std::make_shared<Component>(name, model, this_is_private { });
  }

  //! Reference from child component back to parent model.
  //! This needs to be a weak_ptr to avoid circular ref counting issue.
  std::weak_ptr<Model> model_;

  //! Component name
  std::wstring name_;

public:

  /**! make_shared workaround: public constructor, but effectively private, only possible to make instance of this_is_private from privileged members.

   \see Manager::createModel
   */
  explicit Component(std::wstring name, std::weak_ptr<Model> model, const this_is_private &);

  //! Get a weak reference to parent model object.
  const std::weak_ptr<const Model> getModel() const;

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
