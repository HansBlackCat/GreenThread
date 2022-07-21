#include <greenthread/mem.h>

namespace GreenThread {
  uint64_t spwanThread(RoutineEntry fun, uint64_t stack_size) {
    auto tid = SystemUtil::nextTid();
    contexts.push_back(std::make_shared<Context>(
        stack_size, tid, std::move(fun)
        ));
    invokeSchduler();
  }

  void invokeSchduler() {
    if (contexts.size() == 1) {
      return;
    }
    
    auto front = contexts.front();
    // TODO is std::move valid?
    auto regs = std::move(front -> regs);
    
    contexts.pop_front();
    contexts.push_back(front);
    
    if (set_context(&regs) == 0) {
      auto next = contexts.front();
      switch_context(&(next->regs));
    }
    
  }
}