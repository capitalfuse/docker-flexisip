#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mediastreamer" for configuration "RelWithDebInfo"
set_property(TARGET mediastreamer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(mediastreamer PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libmediastreamer.so.10"
  IMPORTED_SONAME_RELWITHDEBINFO "libmediastreamer.so.10"
  )

list(APPEND _IMPORT_CHECK_TARGETS mediastreamer )
list(APPEND _IMPORT_CHECK_FILES_FOR_mediastreamer "${_IMPORT_PREFIX}/lib/libmediastreamer.so.10" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
