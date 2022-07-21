#pragma once

#include <unistd.h>
#include <utils/defines.h>

#include <cstdlib>

#include <random>
#include <cstdint>
#include <unordered_set>
#include <vector>

static std::unordered_set<uint64_t> tids;
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<uint64_t> uniformIntDistribution(0, UINT64_MAX);


namespace SystemUtil {
  inline long getPagesize() {
    long pagesize;
    if ((pagesize = sysconf(_SC_PAGE_SIZE)) == -1) {
      LOG("fail to get _SC_PAGE_SIZE with errorno: %s", std::strerror(errno));  
      std::exit(EXIT_FAILURE);
    }
    return pagesize;
  }
  inline uint64_t nextTid() {
    uint64_t next = 0;
    while (true) {
      next = uniformIntDistribution(gen);
      if (!tids.contains(next)) {
        tids.insert(next);
        return next;
      }
    }
  }
}