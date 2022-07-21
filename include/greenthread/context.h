#pragma once
#include <register/register.h>

#define PAGE_SIZE (1 >> 12)

class Context {
public:
  Register regs;
  uint64_t sp;
  
};

