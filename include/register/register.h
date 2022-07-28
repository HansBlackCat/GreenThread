#pragma once
#include <cstdint>

// TODO
#if defined(PROJECT_AARCH64)
/**
 * @brief AArch64 Register struct, callee saves registers from context
 */
struct Register {
  uint64_t r9 = 0;   ///< temporary register
  uint64_t r10 = 0;  ///< temporary register
  uint64_t r11 = 0;  ///< temporary register
  uint64_t r13 = 0;  ///< temporary register
  uint64_t r12 = 0;  ///< temporary register
  uint64_t r14 = 0;  ///< temporary register
  uint64_t r15 = 0;  ///< temporary register

  uint64_t r19 = 0;  ///< callee-saved register
  uint64_t r20 = 0;  ///< callee-saved register
  uint64_t r21 = 0;  ///< callee-saved register
  uint64_t r22 = 0;  ///< callee-saved register
  uint64_t r23 = 0;  ///< callee-saved register
  uint64_t r24 = 0;  ///< callee-saved register
  uint64_t r25 = 0;  ///< callee-saved register
  uint64_t r26 = 0;  ///< callee-saved register
  uint64_t r27 = 0;  ///< callee-saved register
  uint64_t r28 = 0;  ///< callee-saved register

  uint64_t r29 = 0;  ///< frame pointer
  uint64_t rsp = 0;  ///< stack pointer
  uint64_t r30 = 0;  ///< link register
};

#else

/**
 * @brief Linux X86_64 Register struct, callee saves registers from
 * context
 */
struct Register {
  uint64_t rbx = 0;  ///< callee-saved register
  uint64_t rbp = 0;  ///< callee-saved register
  uint64_t r12 = 0;  ///< callee-saved register
  uint64_t r13 = 0;  ///< callee-saved register
  uint64_t r14 = 0;  ///< callee-saved register
  uint64_t r15 = 0;  ///< callee-saved register
  uint64_t rsp = 0;  ///< stack pointer
  uint64_t rdx = 0;  ///< point to EntryPoint
};

#endif

/**
 * @brief RegNew initialize Register struct
 */
Register RegNew(uint64_t stack_pointer);

/**
 * @brief interface from asm library
 */
extern "C" {
/**
 * @brief set_context stores current state to Register struct
 * @return return 1 if success
 */
uint64_t set_context(Register* reg);
/**
 * @brief switch_context loads stored-state from Register struct
 * @return return 1 if success
 */
uint64_t switch_context(Register* reg);
}
