#pragma once

#include <memory>
#include <list>
#include <greenthread/context.h>

static std::list<std::shared_ptr<Context>> contexts{};

extern "C" {
  uint64_t set_context(Register *reg);
  void switch_context(Register *reg);
}

namespace GreenThread {
  uint64_t spwanThread(RoutineEntry fun, uint64_t stack_size);
  void invokeSchduler();
}