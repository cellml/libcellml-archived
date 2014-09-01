cmake_minimum_required (VERSION 3.0)
project (Libcellml)
# The version number.
set (Libcellml_VERSION_MAJOR 0)
set (Libcellml_VERSION_MINOR 1)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/LibcellmlConfig.h.in"
  "${PROJECT_BINARY_DIR}/src/LibcellmlConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}/src")

add_library(Version src/Version.cpp)

add_executable (Libcellml src/Test.cpp)

target_link_libraries (Libcellml Version)
