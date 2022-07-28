#include <greenthread/mem.h>
#include <utils/utils.h>

uint64_t Spawn(RoutineEntry fun, uint64_t stack_size) {
  auto tid = SystemUtil::NextTid();
  contexts.push_back(
      std::make_shared<Context>(stack_size, tid, std::move(fun)));
  InvokeScheduler();
  return tid;
}

void InvokeScheduler() {
  if (contexts.size() == 1) {
    return;
  }

  const auto &front = contexts.front();
  // TODO is std::move valid?
  const auto regs = front->regs;

  contexts.pop_front();
  contexts.push_back(front);

  if (set_context(regs)) {
    const auto &next = contexts.front();
    if (switch_context(next->regs)) {
    }
  }
}

// TODO
void InitializeContext(RoutineEntry fun, uint64_t stack_size) {
  if (main_register.has_value()) {
    LOG("initialize main_register double time");
  }
  auto reg = std::make_shared<Register>();
  main_register.emplace();
}

// TODO
void DeAllocStack() {}

extern "C" void EntryPoint() {
  const auto &front = contexts.front();
  front->routineEntry();
  tids.erase(front->tid);
  // uint64_t dump_block_ptr = front->block_ptr;
  contexts.pop_front();

  if (contexts.empty()) {
    if (main_register.has_value()) {
      switch_context(main_register->get());
    } else {
      fprintf(stderr, "Fatal: no main register available");
      _exit(EXIT_FAILURE);
    }
  } else {
    switch_context(front->regs);
  }
}
