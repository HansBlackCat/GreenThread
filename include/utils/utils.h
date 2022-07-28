#pragma once

#include <unistd.h>
#include <utils/defines.h>

#include <cstdint>
#include <cstdlib>
#include <random>
#include <unordered_set>

static std::unordered_set<uint64_t> tids;
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<uint64_t> uniformIntDistribution(
    0, UINT64_MAX);

namespace SystemUtil {
/**
 * @brief GetPageSize find system's page size by calling sysconf
 * @return return page size
 */
inline long GetPageSize() {
  long pagesize;
  if ((pagesize = sysconf(_SC_PAGE_SIZE)) == -1) {
    LOG("fail to get _SC_PAGE_SIZE with errorno: %s", std::strerror(errno));
    std::exit(EXIT_FAILURE);
  }
  return pagesize;
}
/**
 * @brief NextTid generate non-overlapping random number [0, UINT64_MAX]
 * @details given number is used to set context's own TID
 * @return return generated number
 */
inline uint64_t NextTid() {
  uint64_t next = 0;
  while (true) {
    next = uniformIntDistribution(gen);
    if (!tids.contains(next)) {
      tids.insert(next);
      return next;
    }
  }
}
}  // namespace SystemUtil
