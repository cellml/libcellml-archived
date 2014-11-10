#ifndef Libcellml_Model_h
#define Libcellml_Model_h

#include <memory>
#include <string>
#include <vector>

namespace libcellml {

namespace general {
class Manager;
}

class Component;

namespace model {

//! For collection of const child components (i.e. each child component immutable).
//! Overall collection is also not mutable
using componentCollectionConstT = std::vector<std::shared_ptr<const Component>> const;

//! Overall collection is not mutable, but each child component is mutable
using componentCollectionT = std::vector<std::shared_ptr<Component>> const;

//! In-memory representation of a CellML model
class Model: public std::enable_shared_from_this<Model> // Needed so that a reference to the Model parent object creating a child object (e.g. Component or Unit) can be stored by the child object.
{
  friend class general::Manager;

  /** make_shared workaround: Hidden class, effectively makes public constructor private.

   This is take from http://stackoverflow.com/a/8147326
   */
  struct this_is_private {
  };

  //! make_shared workaround: create only accessible to friend. \see Manager::createModel
  static std::shared_ptr<Model> create(std::wstring name,
      std::weak_ptr<libcellml::general::Manager> manager) {
    return std::make_shared<Model>(name, manager, this_is_private { });
  }

  //! Reference from child model back to parent manager.
  //! This needs to be a weak_ptr to avoid circular ref counting issue.
  std::weak_ptr<libcellml::general::Manager> manager_;

  //! Model name
  std::wstring name_;

  //! Children components of this model
  std::vector<std::shared_ptr<Component>> components_;
public:

  /**! make_shared workaround: public constructor, but effectively private, only possible to make instance of this_is_private from privileged members.

   \see Manager::createModel
   */
  explicit Model(std::wstring name, std::weak_ptr<general::Manager> manager,
      const this_is_private &);

  //! Get a weak reference to parent manager object.
  const std::weak_ptr<const general::Manager> getManager() const;

  /**! Model name attribute
   * \return model name
   */
  std::wstring getName() const {
    return name_;
  }

  /** Get read-only collection of child components
   *
   * Each child component is immutable.
   * \return The collection of child components, read-only.
   */
  componentCollectionConstT getComponentsReadOnly() const;

  /** Get collection of mutable child components
   *
   * Each child component is mutable.
   * Overall membership of collection is still fixed.
   * \return The collection of mutable child components.
   */
  componentCollectionT getComponents();

  /**
   * Create a child component object, of which this model object is the parent
   * \param componentName The name of the new component
   * \return a pointer the newly created child model object.
   */
  const std::shared_ptr<Component> createComponent(std::wstring componentName){
    return nullptr;
  }
};

} // namespace model
} // namespace libcellml

#endif
