#ifndef libCellML_Manager_h
#define libCellML_Manager_h

#include <memory>
#include <vector>

#include "Model.h"
#include "Parent.h"
#include "Child.h"

namespace libcellml {
namespace general {


//! Manages models
class Manager
  : public Parent<Manager, model::Model>
{

public:
  /**
   * Create a child model object, of which this manager object is the parent
   * \param modelName The name of the new model
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<libcellml::model::Model> createModel(std::wstring modelName);
};


} //namespace general
} //namespace libcellml
#endif
