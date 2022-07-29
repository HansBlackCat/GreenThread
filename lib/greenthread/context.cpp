#include <greenthread/context.h>
#include <malloc.h>
#include <sys/mman.h>
#include <utils/defines.h>
#include <utils/utils.h>

#include <utility>

Context::Context(uint64_t stack_size, pid_t thread_id, RoutineEntry fun)
    : page_size_{SystemUtil::GetPageSize()},
      tid{thread_id},
      routineEntry{std::move(fun)} {
  const auto alignment = stack_size / page_size_;
  (stack_size % page_size_ != 0) ? block_size_ = page_size_ * (alignment + 1)
                                 : block_size_ = page_size_ * alignment;

  auto block_ptr_ = memalign(page_size_, stack_size);
  if (block_ptr_ == nullptr) {
    LOG("");
    fprintf(stderr, "fail to assign memory\n");
    exit(EXIT_FAILURE);
  }
  if (mprotect(block_ptr_, page_size_, PROT_NONE) == -1) {
    LOG("");
    fprintf(stderr, "fail to set mprotect");
    exit(EXIT_FAILURE);
  }
  block_ptr = (uint64_t)block_ptr_;

  regs = new Register{block_ptr + stack_size};
};

Context::~Context() {
  delete regs;
  free((void*)(block_ptr));
};
