# CMakeList.txt : CMake project for GreenThread, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.21)

project (
  GreenThread
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE_UPPER)
if (CMAKE_BUILD_TYPE_UPPER STREQUAL DEBUG)
  message(STATUS "DEBUG mode")
  add_compile_options(-DDEBUG)
endif ()

message(STATUS "CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

file(GLOB_RECURSE project_headers CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/include/*.h)
message(STATUS "Finding includes - ${project_headers}")

add_subdirectory(lib)
add_subdirectory(test)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "main.cpp"  "include/greenthread/message.h")
target_include_directories(${PROJECT_NAME} PUBLIC ${project_headers})
target_link_libraries(${PROJECT_NAME} PUBLIC greenthread)

set_property(TARGET GreenThread PROPERTY CXX_STANDARD 20)

# TODO: Add tests and install targets if needed.
