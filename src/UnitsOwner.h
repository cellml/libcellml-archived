#ifndef Libcellml_UnitsOwner_h
#define Libcellml_UnitsOwner_h

#include <memory>
#include <string>

#include "Unit.h"
#include "Parent.h"

namespace libcellml {

namespace model {

class Unit;
class Model;

//! Implements ownership of units, behaviour shared by Component and Model.
class UnitsOwner :
  public Parent<UnitsOwner, Unit>
{
  friend class Model;

  UnitsOwner(){}

public:

  /**
   * Create a child unit object, of which this UnitsOwner object is the parent/owner
   * \param unitName The name of the new unit
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<libcellml::model::Unit> createUnit(std::wstring unitName);

};

} // namespace model
} // namespace libcellml

#endif
