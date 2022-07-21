#include <greenthread/context.h>
#include <malloc.h>

#include <memory>
#include <utility>
#include <sys/mman.h>


Context::Context(uint64_t stack_size, pid_t thread_id, RoutineEntry fun)
    : page_size_{SystemUtil::get_pagesize()}, 
      tid{thread_id}, 
      routineEntry{std::move(fun)}
{
  auto alignment = stack_size / page_size_;
  (stack_size % page_size_ != 0) ? block_size_ = page_size_ * (alignment + 1)
                                 : block_size_ = page_size_ * alignment;

  auto block_ptr_ = memalign(page_size_, stack_size);
  if (block_ptr_ == nullptr) {
    LOGTID("");
    fprintf(stderr, "fail to assign memory\n");
    exit(EXIT_FAILURE);
  }
  if (mprotect(block_ptr_, page_size_, PROT_NONE)) {
    LOGTID("");
    fprintf(stderr, "fail to set mprotect");
    exit(EXIT_FAILURE);
  }
  block_ptr = reinterpret_cast<uintptr_t>(block_ptr_);
  
  regs = Register{block_ptr + stack_size};
  
  
};
