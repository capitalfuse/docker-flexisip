#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "lime" for configuration "RelWithDebInfo"
set_property(TARGET lime APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(lime PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/liblime.so.0"
  IMPORTED_SONAME_RELWITHDEBINFO "liblime.so.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS lime )
list(APPEND _IMPORT_CHECK_FILES_FOR_lime "${_IMPORT_PREFIX}/lib/liblime.so.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
