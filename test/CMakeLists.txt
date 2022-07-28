include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE project_test_sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
message(STATUS "test-resources ${project_test_sources}")

enable_testing()

add_executable(${PROJECT_NAME}Test ${project_test_sources})
target_link_libraries(${PROJECT_NAME}Test PRIVATE greenthread gtest gmock gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}Test)