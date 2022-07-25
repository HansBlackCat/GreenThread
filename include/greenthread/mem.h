#pragma once

#include <greenthread/context.h>
#include <utils/utils.h>

#include <list>
#include <memory>
#include <optional>
#include <unordered_map>

static std::list<std::shared_ptr<Context>> contexts{};
//static std::unordered_map<uint64_t, Context> context_map{};
//constinit static uint64_t dump_block_ptr;
constinit static std::optional<Register> main_register = std::nullopt;

extern "C" {
  uint64_t set_context(Register *reg);
  void switch_context(Register *reg);
}

uint64_t spawnThread(RoutineEntry fun, uint64_t stack_size);
void invokeScheduler();
