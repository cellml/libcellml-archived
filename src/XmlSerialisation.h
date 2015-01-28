#ifndef XMLSERIALISATION_H_
#define XMLSERIALISATION_H_

#include "Manager.h"

#include <string>

using namespace libcellml::model;

namespace libcellml {
namespace general {

/**
 Serialise the manager's collection of CellML models.
 \param manager The Manager that owns the models to be serialised.
 \return Collection of XML representations
 */
std::string createXml(const Manager& manager);

}
}


#endif /* XMLSERIALISATION_H_ */

