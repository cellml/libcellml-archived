cmake_minimum_required (VERSION 2.8)

set(PROJECT_NAME libCellML)
project(${PROJECT_NAME})

################################
# Normal Libraries & Executables
################################

# The version number.
set (Libcellml_VERSION_MAJOR 0)
set (Libcellml_VERSION_MINOR 1)

set(HEADER_FILES ${PROJECT_SOURCE_DIR}/src/Version.h)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/LibcellmlConfig.h.in"
  "${PROJECT_BINARY_DIR}/src/LibcellmlConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}/src")

add_library(Libcellml src/Version.cpp ${HEADER_FILES})


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


################################
# Testing
################################
if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(extdep/gtest-1.7.0)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src")

  ##############
  # Unit Tests
  ##############
  add_executable (libcellmlTest ${PROJECT_SOURCE_DIR}/tests/Test.cpp ${HEADER_FILES})

  # Standard linking to gtest stuff.
  target_link_libraries(libcellmlTest gtest gtest_main)

  # Extra linking for the project.
  target_link_libraries(libcellmlTest Libcellml)

  # test executable.
  add_test(libcellmlTest libcellmlTest)
endif()