cmake_minimum_required (VERSION 3.1)

# Use the following variables when configuring the build from the command line to
# set the corresponding cache variables.
# TESTS ==> LIBCELLML_TESTS
SET( LIBCELLML_TESTS "" CACHE BOOL "Enable build of automated LibCellML tests." )
IF( TESTS )
  SET( LIBCELLML_TESTS "${TESTS}" CACHE BOOL "Enable build of automated LibCellML tests." FORCE )
ENDIF()

set(PROJECT_NAME libCellML)
project(${PROJECT_NAME} CXX)

################################
# Normal Libraries & Executables
################################

if (MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /EHsc")
endif()


# The version number.
set (LIBCELLML_VERSION_MAJOR 0)
set (LIBCELLML_VERSION_MINOR 1)
set (LIBCELLML_VERSION_PATCH 0)



# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." OFF) # Makes boolean 'test' available.

set(CMAKE_CXX_FLAGS "-g -Wall")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if (LIBCELLML_TESTS)
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()
