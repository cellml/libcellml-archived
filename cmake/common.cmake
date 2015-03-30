macro(INITIALISE_PROJECT)
  if(LIBCELLML_WARNINGS_TREATED_AS_ERRORS)
    if(WIN32)
      set(CMAKE_CXX_FLAGS "/W3")
    else()
      set(CMAKE_CXX_FLAGS "-Wall -W -Werror")
    endif()
  endif()
  
  if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /EHsc")
  endif()

endmacro()
