#pragma once
#include <register/register.h>
#include <unistd.h>

#include <functional>
#include <memory>

typedef std::function<void(void)> RoutineEntry;

/**
 * @brief Context of thread
 */
class Context {
 private:
  const long page_size_;
  uint64_t block_size_;

 public:
  pid_t tid;
  Register* regs;
  uint64_t block_ptr;
  RoutineEntry routineEntry;

  Context() = delete;
  Context(const Context&) = delete;
  Context(Context&&) = default;
  Context& operator=(const Context&) = delete;
  Context& operator=(Context&&) = delete;
  ~Context();

  Context(uint64_t stack_size, pid_t tid, RoutineEntry fun);
};
