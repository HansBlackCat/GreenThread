#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "GreenThread::GreenThread" for configuration "Debug"
set_property(TARGET GreenThread::GreenThread APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(GreenThread::GreenThread PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/GreenThread-1.0/libGreenThread.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS GreenThread::GreenThread )
list(APPEND _IMPORT_CHECK_FILES_FOR_GreenThread::GreenThread "${_IMPORT_PREFIX}/lib/GreenThread-1.0/libGreenThread.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
