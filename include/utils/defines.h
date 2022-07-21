#pragma once

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <unistd.h>

#define PROJECT_COMPILER_UNKNOWN 0
#define PROJECT_COMPILER_GCC 1
#define PROJECT_COMPILER_CLANG 2
#define PROJECT_OS_UNKNOWN 0
#define PROJECT_OS_LINUX 1

#ifdef DEBUG
#  define LOG(M, ...)                               \
    std::fprintf(stderr,                            \
                 "\x1b[31m"                         \
                 "[DEBUG] (%s %d): " M "\x1b[0m\n", \
                 __FILE__, __LINE__, ##__VA_ARGS__)  ///< LOG function
#  define LOGTID(M, ...)                               \
    std::fprintf(stderr,                               \
                 "\x1b[31m"                            \
                 "[DEBUG] (TID: %lu): " M "\x1b[0m\n", \
                 gettid(), ##__VA_ARGS__)
#else
#  define LOG(M, ...)
#  define LOGTID(M, ...)
#endif

#if defined(__gnu_linux__) || defined(__linux__)
#  define PROJECT_OS PROJECT_OS_LINUX
#else
#  define PROJECT_OS PROJECT_OS_UNKNOWN
#endif

#if defined(__GNUC__)
#define PROJECT_COMPILER PROJECT_COMPILER_GCC 
#elif defined(__clang__)
#define PROJECT_COMPILER PROJECT_COMPILER_CLANG
#else
#define PROJECT_COMPILER PROJECT_COMPILER_UNKNOWN
#endif