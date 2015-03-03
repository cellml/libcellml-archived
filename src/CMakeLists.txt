

set(CELLML_EXPORT_H "${CMAKE_CURRENT_BINARY_DIR}/api/libcellml/libcellml_export.h")
set(LIBCELLML_CONFIG_H "${CMAKE_CURRENT_BINARY_DIR}/libcellml_config.h")
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/libcellml_config.h.in"
  ${LIBCELLML_CONFIG_H}
)

set(SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/version.cpp
)

set(API_HEADER_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/api/libcellml/version.h
  ${CELLML_EXPORT_H}
)

set(HEADER_FILES
  ${LIBCELLML_CONFIG_H}
)

include_directories(
  "${CMAKE_CURRENT_BINARY_DIR}/api"
  "${CMAKE_CURRENT_SOURCE_DIR}/api"
  "${CMAKE_CURRENT_BINARY_DIR}"
)

include(GenerateExportHeader)

add_compiler_export_flags()
add_library(cellml
  ${SOURCE_FILES}
  ${HEADER_FILES}
  ${API_HEADER_FILES}
)
generate_export_header(cellml EXPORT_FILE_NAME ${CELLML_EXPORT_H} BASE_NAME LIBCELLML)

set_source_files_properties(${CELLML_EXPORT_H} PROPERTIES GENERATED TRUE)
set_target_properties(cellml PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

export(TARGETS cellml FILE libcellml-exports.cmake)

install(TARGETS cellml EXPORT libcellml-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(FILES
  ${API_HEADER_FILES}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/libcellml
)
install(EXPORT libcellml-targets DESTINATION lib/cmake)

