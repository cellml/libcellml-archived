set(HEADER_FILES 
  ${PROJECT_SOURCE_DIR}/src/api/libcellml/version.h
)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/libcellml_config.h.in"
  "${PROJECT_BINARY_DIR}/src/libcellml_config.h"
)

include_directories(
  "${PROJECT_BINARY_DIR}/src"
  "${PROJECT_SOURCE_DIR}/src/api"
)

add_library(Libcellml 
  ${PROJECT_SOURCE_DIR}/src/version.cpp 
  ${HEADER_FILES}
)
