#ifndef Libcellml_Model_h
#define Libcellml_Model_h

#include <memory>

namespace libcellml {

namespace general {
class Manager;
}

namespace model {

//! In-memory representation of a CellML model
class Model {
  friend class general::Manager;


  /** make_shared workaround: Hidden class, effectively makes public constructor private.

   This is take from http://stackoverflow.com/a/8147326
   */
  struct this_is_private {
  };

  //! make_shared workaround: create only accessible to friend. \see Manager::createModel
  static std::shared_ptr<Model> create(
      std::weak_ptr<libcellml::general::Manager> manager) {
    return std::make_shared<Model>(manager, this_is_private { });
  }

  //! Reference from child model back to parent manager.
  //! This needs to be a weak_ptr to avoid circular ref counting issue.
  std::weak_ptr<libcellml::general::Manager> manager_;

public:

  /**! make_shared workaround: public constructor, but effectively private, only possible to make instance of this_is_private from privileged members.

   \see Manager::createModel
   */
  explicit Model(std::weak_ptr<general::Manager> manager,
      const this_is_private &);

  //! Get a weak reference to parent manager object.
  const std::weak_ptr<const general::Manager> getManager() const;

};

} // namespace model
} // namespace libcellml

#endif
