################################
# Testing
################################
if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests/gtest-1.7.0)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src/libcellml")

  ##############
  # Unit Tests
  ##############
  add_executable (libcellmlTest 
    ${PROJECT_SOURCE_DIR}/tests/version_test.cpp 
    ${HEADER_FILES}
  )

  # Standard linking to gtest stuff.
  target_link_libraries(libcellmlTest gtest gtest_main)

  # Extra linking for the project.
  target_link_libraries(libcellmlTest Libcellml)

  # test executable.
  add_test(libcellmlTest libcellmlTest)
endif()
