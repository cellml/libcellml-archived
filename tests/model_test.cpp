#include "libcellml/model.h"

#include "gtest/gtest.h"

//! Test model has name specified during creation
TEST(Model, ModelWithValidName) {
  boost::optional<std::wstring> modelName{L"testModel"};
  libcellml::Model m1{modelName};
  ASSERT_EQ(*(m1.getName()), L"testModel");
}
