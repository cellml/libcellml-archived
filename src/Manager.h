#ifndef libCellML_Manager_h
#define libCellML_Manager_h

#include <memory>
#include "Model.h"

namespace libcellml {
namespace general {

class Manager {
public:
  std::shared_ptr<libcellml::model::Model> createModel(){
    return std::make_shared<libcellml::model::Model>();
  }
};

} //namespace general
} //namespace libcellml
#endif
