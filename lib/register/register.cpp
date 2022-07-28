#include <greenthread/mem.h>
#include <register/register.h>

Register RegNew(uint64_t stack_pointer) {
  // ReSharper disable once CppLocalVariableMayBeConst
  Register reg{ .rsp = stack_pointer, .rdx = (uint64_t)EntryPoint };
  return reg;
}
