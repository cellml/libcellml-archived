################################
# Testing
################################
# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/gtest-1.7.0)

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src/api")

##############
# Unit Tests
##############
add_executable (libcellmlTest 
  ${CMAKE_CURRENT_SOURCE_DIR}/version_test.cpp 
  ${HEADER_FILES}
)

# Standard linking to gtest stuff.
target_link_libraries(libcellmlTest gtest gtest_main)

# Extra linking for the project.
target_link_libraries(libcellmlTest Libcellml)

# test executable.
add_test(libcellmlTest libcellmlTest)
