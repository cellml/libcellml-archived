#ifndef Libcellml_UnitsOwner_h
#define Libcellml_UnitsOwner_h

#include <libcellml/Units.h>
#include <memory>
#include <string>

#include "libcellml/Parent.h"

namespace libcellml {

class Units;
class Model;
class Component;

/**
 *  Implements ownership of units objects.
 *  This is behaviour shared by Component and Model.
 */
class UnitsOwner :
  public Parent<UnitsOwner, Units>
{
  friend class Model;
  friend class Component;

  UnitsOwner(){}

public:

  /**
   * Create a child units object, of which this UnitsOwner object is the parent/owner
   * \param unitsName The name of the new units object
   * \return a pointer the newly created units object.
   */
  const std::shared_ptr<Units> createUnits(std::wstring unitsName);

};

} // namespace libcellml

#endif
