#pragma once

#include <utils/utils.h>

#include <cstdint>
#include <list>
#include <unordered_map>

/**
 * @brief MessageContainer contains base container of message queue and waiting
 * queue */
/*
template <typename T>
struct MessageContainer {
  std::unordered_map<uint64_t, std::list<T>> map;
};
static constexpr MessageContainer<uint64_t> global_message_map;
*/

static std::unordered_map<uint64_t, std::list<uint64_t>> global_map;
