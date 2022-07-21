# Install script for directory: /Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/_deps/fmt-build/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xGreenThread_Developmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GreenThread-1.0" TYPE DIRECTORY FILES "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/PackageProjectInclude/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xGreenThread_Developmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/GreenThread-1.0" TYPE STATIC_LIBRARY FILES "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/libGreenThread.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/GreenThread-1.0/libGreenThread.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/GreenThread-1.0/libGreenThread.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/GreenThread-1.0/libGreenThread.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xGreenThread_Developmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/GreenThread-1.0/GreenThreadTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/GreenThread-1.0/GreenThreadTargets.cmake"
         "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/CMakeFiles/Export/lib/cmake/GreenThread-1.0/GreenThreadTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/GreenThread-1.0/GreenThreadTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/GreenThread-1.0/GreenThreadTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GreenThread-1.0" TYPE FILE FILES "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/CMakeFiles/Export/lib/cmake/GreenThread-1.0/GreenThreadTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GreenThread-1.0" TYPE FILE FILES "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/CMakeFiles/Export/lib/cmake/GreenThread-1.0/GreenThreadTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xGreenThread_Developmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GreenThread-1.0" TYPE FILE FILES
    "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/GreenThreadConfigVersion.cmake"
    "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/GreenThreadConfig.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xGreenThread_Developmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GreenThread-1.0" TYPE DIRECTORY FILES "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/include/")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/hansblackcat/Isolated_Documents/Dev/BUILDTEST/CMakeTest/GreenThread/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
