#include <memory>

#include <Manager.h>
#include <Model.h>
#include <Component.h>
#include <Variable.h>

#include "gtest/gtest.h"

using namespace libcellml::general;
using namespace std;

/**! Test that a variable can be connected to itself.
 * Although this won't result in valid CellML, it still needs to be possible as an interim stage towards creating a valid model.
 */
TEST(Variable, VariableSelfConnection) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto m1 = m->createModel(L"test model");
  auto c1 = m1->createComponent(L"test component");
  auto u1 = m1->createUnit(L"kg");
  auto v1 = c1->createVariable(L"v1", u1);
  v1->connect(v1);
  auto connectedVars = v1->getConnectedVariables();

  ASSERT_EQ(1, connectedVars.size());
}
