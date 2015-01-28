#ifndef SERIALISER_H_
#define SERIALISER_H_

#include "Manager.h"

#include <string>

using namespace libcellml::general;
using namespace libcellml::model;

//! Used for creating serialisations of the models of a Manager.
class Serialiser {
public:
  /**
   Serialise the manager's collection of CellML models.
   \param manager The Manager that owns the models to be serialised.
   \return Collection of XML representations
   */
  std::string createXml(const Manager& manager);
};



#endif /* SERIALISER_H_ */
