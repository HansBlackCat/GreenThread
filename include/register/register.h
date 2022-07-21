#pragma once
#include <cstdint>

/**
 * @class Register
 * @brief Register class used for save register
 */
class Register {
public:
  uint64_t sp = 0;   ///< stack pointer
  uint64_t r30 = 0;  ///< link register
  uint64_t r29 = 0;  ///< frame pointer

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

  uint64_t r9 = 0;   ///< temporary register
  uint64_t r10 = 0;  ///< temporary register
  uint64_t r11 = 0;  ///< temporary register
  uint64_t r13 = 0;  ///< temporary register
  uint64_t r12 = 0;  ///< temporary register
  uint64_t r14 = 0;  ///< temporary register
  uint64_t r15 = 0;  ///< temporary register

  Register() = default;
  explicit Register(uint64_t stack_pointer);
  Register(const Register&) = delete;
  Register(Register &&) = default;
  Register &operator=(const Register &) = delete;
  Register &operator=(Register &&) = default;
};





