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


cmake_minimum_required (VERSION 3.1) #NB: Actually v3.2 is required.

set(PROJECT_NAME libCellML)
project(${PROJECT_NAME} CXX)

# Use the following variables when configuring the build from the command line to
# set the corresponding cache variables.
# TESTS ==> LIBCELLML_TESTS
set( LIBCELLML_TESTS OFF CACHE BOOL "Enable build of automated LibCellML tests." )
if( TESTS )
  set( LIBCELLML_TESTS "${TESTS}" CACHE BOOL "Enable build of automated LibCellML tests." FORCE )
endif()

# BUILD_TYPE ==> LIBCELLML_BUILD_TYPE
set( LIBCELLML_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." )
if( BUILD_TYPE )
  set( LIBCELLML_BUILD_TYPE ${BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE )
endif()

# INSTALL_PREFIX ==> LIBCELLML_INSTALL_PREFIX
set( LIBCELLML_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX} CACHE STRING "Install path prefix, prepended onto install directories." )
if( INSTALL_PREFIX )
  set( LIBCELLML_INSTALL_PREFIX ${INSTALL_PREFIX} CACHE STRING "Install path prefix, prepended onto install directories." FORCE )
endif()

# BUILD_SHARED ==> LIBCELLML_BUILD_SHARED
set( LIBCELLML_BUILD_SHARED OFF CACHE BOOL "Build shared libraries (so, dylib, DLLs)." )
if( BUILD_SHARED )
  set( LIBCELLML_BUILD_SHARED ${BUILD_SHARED} CACHE BOOL "Build shared libraries (so, dylib, DLLs)." FORCE )
endif()

# internalise some CMake variables
set( CMAKE_INSTALL_PREFIX ${LIBCELLML_INSTALL_PREFIX} CACHE INTERNAL "Internalise CMAKE_INSTALL_PREFIX, manipulate via LIBCELLML_INSTALL_PREFIX" FORCE )
set( CMAKE_BUILD_TYPE ${LIBCELLML_BUILD_TYPE} CACHE INTERNAL "Internalise CMAKE_BUILD_TYPE, manipulate via LIBCELLML_BUILD_TYPE" FORCE )
set( BUILD_SHARED_LIBS ${LIBCELLML_BUILD_SHARED} CACHE INTERNAL "Internalise BUILD_SHARED_LIBS, manipulate via LIBCELLML_BUILD_SHARED" FORCE )
set( CMAKE_CODEBLOCKS_EXECUTABLE "" CACHE INTERNAL "Internalise BUILD_SHARED_LIBS" FORCE )

# The version number.
set(LIBCELLML_VERSION_MAJOR 0)
set(LIBCELLML_VERSION_MINOR 1)
set(LIBCELLML_VERSION_PATCH 0)

# cellml library target
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if (LIBCELLML_TESTS)
  # enable testing here so that we can make use of the 'test' target
  enable_testing()
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()

