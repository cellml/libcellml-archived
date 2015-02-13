#include <Units.h>
#include <memory>

#include "Model.h"
#include "Component.h"
#include "Variable.h"
#include "gtest/gtest.h"

using namespace libcellml;
using namespace std;

/**! Test that a variable can be connected to itself.
 * Although this won't result in valid CellML, it still needs to be possible as an interim stage towards creating a valid model.
 */
TEST(Variable, VariableSelfConnection) {

  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  auto c1 = m1->createComponent(L"test component");
  weak_ptr<Units> u1 = m1->createUnits(L"kg");
  auto v1 = c1->createVariable(L"v1", u1);
  v1->connect(v1);
  auto connectedVars = v1->getConnectedVariables();

  ASSERT_EQ(1, connectedVars.size());
}


/**! Test that a variable can be created without having a Unit for it.
 */
TEST(Variable, UnitAbsent) {

  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  auto c1 = m1->createComponent(L"test component");
  auto uPlaceholderUnit = m1->createUnits(L"nothing");
  auto v1 = c1->createVariable(L"v1", boost::none);
  auto u1 = v1->getUnit();

  ASSERT_EQ(L"nothing", u1.value_or(uPlaceholderUnit).lock()->getName());
}


/**! Test a simple connection between to variables from separate components.
 */
TEST(Variable, SimpleVariableConnection) {
  shared_ptr<Model> m1 = make_shared<Model>(L"test model");
  auto c1 = m1->createComponent(L"test component 1");
  auto c2 = m1->createComponent(L"test component 2");
  weak_ptr<Units> u1 = m1->createUnits(L"kg");
  decltype(u1) u2;
//  ASSERT_EQ(L"", u2->getName());
  auto v1 = c1->createVariable(L"v1", u1);
  auto v2 = c2->createVariable(L"v2", u2);
  v1->connect(v2);

  auto v1ConnectedVars = v1->getConnectedVariables();
  ASSERT_EQ(1, v1ConnectedVars.size());

  auto v2ConnectedVars = v2->getConnectedVariables();
  ASSERT_EQ(1, v2ConnectedVars.size());
}
