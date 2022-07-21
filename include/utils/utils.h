#pragma once

#include <unistd.h>
#include <utils/defines.h>

#include <cstdlib>

namespace SystemUtil {
  inline long get_pagesize() {
    long pagesize;
    if ((pagesize = sysconf(_SC_PAGE_SIZE)) == -1) {
      LOG("fail to get _SC_PAGE_SIZE with errorno: %s", std::strerror(errno));  
      std::exit(EXIT_FAILURE);
    }
    return pagesize;
  }
}