#ifndef libCellML_Manager_h
#define libCellML_Manager_h

#include <memory>
#include <vector>

#include "Model.h"


namespace libcellml {
namespace general {


//! For collection of const children models (i.e. each child model immutable).
//! Overall collection is also not mutable
using modelCollectionConstT = std::vector<std::shared_ptr<const libcellml::model::Model>> const;

//! Overall collection is not mutable, but each child model is mutable
using modelCollectionT = std::vector<std::shared_ptr<libcellml::model::Model>> const;


//! The class for a parent object
class Manager: public std::enable_shared_from_this<libcellml::general::Manager> // Needed so that a reference to the Manager parent object creating the child Model object can be stored by the child Model object.
{
  //! Children models
  std::vector<std::shared_ptr<libcellml::model::Model>> models;

public:
  /** Get read-only collection of Models
   *
   * Each child element is immutable.
   * \return The collection of children, read-only.
   */
  modelCollectionConstT getModelsReadOnly() const;

  /** Get collection of mutable children
   *
   * Each child element is mutable.
   * Overall membership of collection is still fixed.
   * \return The collection of mutable children.
   */
  modelCollectionT getModels();

  /**
   * Create a child B object, of which this object is the parent
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<const libcellml::model::Model> createModel(std::wstring modelName);
};


//class Manager {
//public:
//  std::shared_ptr<libcellml::model::Model> createModel() {
//    return std::make_shared<libcellml::model::Model>();
//  }
//};

} //namespace general
} //namespace libcellml
#endif
