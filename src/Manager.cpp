#include "Manager.h"

#include <algorithm>
#include <memory>

#include "Model.h"

using namespace std;
using namespace libcellml::general;
using namespace libcellml::model;

modelCollectionConstT Manager::getModelsReadOnly() const {
  modelCollectionConstT modelsc(models.begin(), models.end()); // Have to copy to get const version.
  return modelsc;
}

modelCollectionT Manager::getModels() {
  return models;
}

const shared_ptr<const Model> Manager::createModel(std::wstring modelName) {
  shared_ptr<Model> modelp(Model::create(modelName, shared_from_this()));
  models.push_back(modelp);
  return models.back();
}
