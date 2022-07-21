#pragma once
#include <register/register.h>
#include <unistd.h>

#include <functional>
#include <utils/utils.h>

typedef std::function<void(void)> RoutineEntry;

/**
 * @struct Context of thread
 */
class Context {
private:
  const long page_size_;
  uint64_t block_size_;
  
public:
  pid_t tid;
  Register regs;
  uintptr_t block_ptr;
  RoutineEntry routineEntry;
  
  Context() = delete;
  Context(const Context &) = delete;
  Context(Context &&) = delete;
  Context &operator=(const Context &) = delete;
  Context &operator=(Context &&) = delete;
  
  Context(uint64_t stack_size, pid_t tid, RoutineEntry fun);
};

