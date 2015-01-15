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


/**! Test a simple connection between to variables from separate components.
 */
TEST(Variable, SimpleVariableConnection) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto m1 = m->createModel(L"test model");
  auto c1 = m1->createComponent(L"test component 1");
  auto c2 = m1->createComponent(L"test component 2");
  auto u1 = m1->createUnit(L"kg");
  auto v1 = c1->createVariable(L"v1", u1);
  auto v2 = c2->createVariable(L"v2", u1);
  v1->connect(v2);

  auto v1ConnectedVars = v1->getConnectedVariables();
  ASSERT_EQ(1, v1ConnectedVars.size());

  auto v2ConnectedVars = v2->getConnectedVariables();
  ASSERT_EQ(1, v2ConnectedVars.size());
}
