#include <greenthread/mem.h>

uint64_t spawnThread(RoutineEntry fun, uint64_t stack_size) {
  auto tid = SystemUtil::nextTid();
  contexts.push_back(std::make_shared<Context>(stack_size, tid, std::move(fun)));
  invokeScheduler();
  // TODO
  return 0;
}

void invokeScheduler() {
  if (contexts.size() == 1) {
    return;
  }

  auto front = contexts.front();
  // TODO is std::move valid?
  auto regs = std::move(front->regs);

  contexts.pop_front();
  contexts.push_back(front);

  if (set_context(&regs) == 0) {
    auto next = contexts.front();
    switch_context(&(next->regs));
  }
}

extern "C" void entryPoint() {
  auto front = contexts.front();
  front->routineEntry();
  tids.erase(front->tid);
  dump_block_ptr = front->block_ptr;
  contexts.pop_front();

  if (contexts.empty()) {
    if (main_register.has_value()) {
      switch_context(&(main_register.value()));
    } else {
      fprintf(stderr, "Fatal: no main register available");
      exit(EXIT_FAILURE);
    }
  } else {
    switch_context(&(front->regs));
  }
}
