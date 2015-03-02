set(HEADER_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/api/libcellml/version.h
  "${CMAKE_CURRENT_BINARY_DIR}/libcellml_config.h"
)

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/libcellml_config.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/libcellml_config.h"
)

include_directories(
  "${CMAKE_CURRENT_BINARY_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}/api"
)

add_library(cellml 
  ${CMAKE_CURRENT_SOURCE_DIR}/version.cpp 
  ${HEADER_FILES}
)
