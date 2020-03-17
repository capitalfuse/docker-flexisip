#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "bctoolbox" for configuration "RelWithDebInfo"
set_property(TARGET bctoolbox APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(bctoolbox PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libbctoolbox.so.1"
  IMPORTED_SONAME_RELWITHDEBINFO "libbctoolbox.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS bctoolbox )
list(APPEND _IMPORT_CHECK_FILES_FOR_bctoolbox "${_IMPORT_PREFIX}/lib/libbctoolbox.so.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
