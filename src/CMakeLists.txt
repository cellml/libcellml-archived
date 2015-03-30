# Copyright 2015 University of Auckland
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.cmake_minimum_required (VERSION 3.1)

INCLUDE(${CMAKE_SOURCE_DIR}/cmake/common.cmake)

INITIALISE_PROJECT()

set(CELLML_EXPORT_H "${CMAKE_CURRENT_BINARY_DIR}/api/libcellml/libcellml_export.h")
set(LIBCELLML_CONFIG_H "${CMAKE_CURRENT_BINARY_DIR}/libcellml_config.h")
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/libcellml_config.h.in"
  ${LIBCELLML_CONFIG_H}
)

set(SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/version.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/model.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/xml_serialisation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/cellml_1_2.cpp 
)

set(API_HEADER_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/api/libcellml/version.h
  ${CMAKE_CURRENT_SOURCE_DIR}/api/libcellml/model.h
  ${CMAKE_CURRENT_SOURCE_DIR}/api/libcellml/xml_serialisation.h
  ${CMAKE_CURRENT_SOURCE_DIR}/cellml_1_2.h
  ${CELLML_EXPORT_H}
)

set(HEADER_FILES
  ${LIBCELLML_CONFIG_H}
)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/api
  ${CMAKE_CURRENT_SOURCE_DIR}/api
  ${CMAKE_CURRENT_SOURCE_DIR}/../extdep/libxsd
  ${CMAKE_CURRENT_BINARY_DIR}
)

include(GenerateExportHeader)

add_compiler_export_flags()
add_library(cellml
  ${SOURCE_FILES}
  ${HEADER_FILES}
  ${API_HEADER_FILES}
)
generate_export_header(cellml EXPORT_FILE_NAME ${CELLML_EXPORT_H} BASE_NAME LIBCELLML)

set(XercesC_ROOT "${XercesC_ROOT}" CACHE PATH "Location of Xerces-C")
set(BOOST_ROOT "${BOOST_ROOT}" CACHE PATH "Location of Boost")

set(CMAKE_INCLUDE_PATH "${XercesC_ROOT}/include")
set(CMAKE_LIBRARY_PATH "${XercesC_ROOT}/lib")
find_package (XercesC)
if (XercesC_FOUND)
  include_directories(${XercesC_INCLUDE_DIR})
  target_link_libraries (cellml ${XercesC_LIBRARY})
endif (XercesC_FOUND)


find_package (Boost)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries (cellml ${Boost_LIBRARIES})
endif (Boost_FOUND)


set_source_files_properties(${CELLML_EXPORT_H} PROPERTIES GENERATED TRUE)

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

set_target_properties(cellml PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
