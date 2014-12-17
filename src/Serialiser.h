#ifndef SERIALISER_H_
#define SERIALISER_H_

#include "Manager.h"

#include <string>

using namespace libcellml::general;
using namespace libcellml::model;

class Serialiser {
public:
  std::string createXml(const Manager&);
};



#endif /* SERIALISER_H_ */
