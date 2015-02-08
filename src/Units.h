#ifndef Libcellml_Units_h
#define Libcellml_Units_h

#include <memory>
#include <string>

#include "UnitsOwner.h"
#include "Child.h"

namespace libcellml {

class UnitsOwner;

//! In-memory representation of a CellML Units entity (i.e. physical unit of measure)
class Units : public Child<UnitsOwner, Units>{
  friend class UnitsOwner;

  //! Units object's name
  std::wstring name_;

public:
  Units(std::weak_ptr<UnitsOwner>, const this_is_private &);

  /** Units object's name attribute
   * \return Units object's name
   */
  std::wstring getName() const {
    return name_;
  }

};

} // namespace libcellml

#endif
