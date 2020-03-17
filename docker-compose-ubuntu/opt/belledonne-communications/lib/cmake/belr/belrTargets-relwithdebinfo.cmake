#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "belr" for configuration "RelWithDebInfo"
set_property(TARGET belr APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(belr PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libbelr.so.1"
  IMPORTED_SONAME_RELWITHDEBINFO "libbelr.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS belr )
list(APPEND _IMPORT_CHECK_FILES_FOR_belr "${_IMPORT_PREFIX}/lib/libbelr.so.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
