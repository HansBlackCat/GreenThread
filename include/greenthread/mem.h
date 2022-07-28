#pragma once

#include <greenthread/context.h>

#include <list>
#include <memory>
#include <optional>

static std::list<std::shared_ptr<Context>> contexts{};  ///< Hi
// static std::unordered_map<uint64_t, Context> context_map{};
// constinit static uint64_t dump_block_ptr;
constinit static std::optional<std::shared_ptr<Register>> main_register =
    std::nullopt;

/**
 * @brief SpawnThread push subroutine to context-lists
 * @return return tid
 */
uint64_t Spawn(RoutineEntry fun, uint64_t stack_size);

/**
 * @brief InvokeScheduler pop next context from context-lists and switch
 * register
 */
void InvokeScheduler();

/**
 * @brief InitializeContext initialize main context with register only once
 */
void InitializeContext(RoutineEntry fun, uint64_t stack_size);

/**
 * @brief DeallocStack release a protection and deallocate dump stack memory
 */
void DeAllocStack();

/**
 * @brief EntryPoint
 */
extern "C" void EntryPoint();
