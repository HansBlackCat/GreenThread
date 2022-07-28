enable_language(C ASM)

file(GLOB_RECURSE project_sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# TODO AArch / AMD64
# AMD64
list(APPEND project_sources ${CMAKE_CURRENT_SOURCE_DIR}/asm/context_amd64.S)
list(FILTER project_sources EXCLUDE REGEX .*_aarch.cpp)

set(asm_options "-x assembler-with-cpp -fPIC -ggdb")
set(CMAKE_ASM_FLAGS ${CFLAGS} ${asm_options})
message(STATUS "Finding project_sources ${project_sources}")

add_library(greenthread STATIC ${project_sources})
target_include_directories(greenthread PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(greenthread PUBLIC cxx_std_20)
target_compile_options(greenthread PRIVATE -Wall -Werror -Wpedantic)
