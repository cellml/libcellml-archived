#ifndef XMLSERIALISATION_H_
#define XMLSERIALISATION_H_

#include "model.h"

#include <string>

namespace libcellml {

/**
 Serialise the Model
 \param model The model to be serialised.
 \return XML representation
 */
std::string createXml(const Model& model);

}


#endif /* XMLSERIALISATION_H_ */

