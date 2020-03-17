#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "bzrtp" for configuration "RelWithDebInfo"
set_property(TARGET bzrtp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(bzrtp PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libbzrtp.so.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libbzrtp.so.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS bzrtp )
list(APPEND _IMPORT_CHECK_FILES_FOR_bzrtp "${_IMPORT_PREFIX}/lib/libbzrtp.so.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
