/*
 * Some license of other
 */
#ifndef Libcellml_Version_h
#define Libcellml_Version_h

#include <string>

#include "libcellml/libcellml_export.h"

//! Everything in LibCellML is in this namespace.
namespace libcellml {

/**
 * Get the version string.
 * The version string is in the format x.y.z, where the "."s are literal, and x,y and z represent counting numbers,
 * in which case x is the major version, y the minor version, and z the patch level.
 *  @return a string to represent the version
 */
LIBCELLML_EXPORT const std::string getVersion();

} // namespace libcellml

#endif
