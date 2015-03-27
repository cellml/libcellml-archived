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

# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/gtest-1.7.0)

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src/api"  "${PROJECT_BINARY_DIR}/src/api")

add_executable (libcellmlTest
  ${CMAKE_CURRENT_SOURCE_DIR}/version_test.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/xml_serialisation_test.cpp
  ${HEADER_FILES}
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/extdep/libxsd
)

# Standard linking to gtest stuff.
target_link_libraries(libcellmlTest gtest gtest_main)

find_package (Boost)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries (libcellmlTest ${Boost_LIBRARIES})
endif (Boost_FOUND)



# Extra linking for the project.
target_link_libraries(libcellmlTest cellml)

# test executable.
add_test(libcellmlTest libcellmlTest)

set_target_properties(libcellmlTest PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
