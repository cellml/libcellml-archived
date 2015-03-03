#ifndef Libcellml_Version_h
#define Libcellml_Version_h

#include <string>

//! Everything in LibCellML is in this namespace.
namespace libcellml {

/** Get the version string.
 * The version string is in the format x.y.z, where the "."s are literal, and x,y and z represent counting numbers,
 * in which case x is the major version, y the minor version, and z the patch level.
 *  @return The version string
 */
const std::string getVersion();

} // namespace libcellml

#endif
