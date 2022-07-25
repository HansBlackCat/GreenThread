#include <doctest/doctest.h>
#include <register/register.h>
#include <utils/defines.h>
#include <utils/utils.h>
#include <greenthread/mem.h>

TEST_CASE("Hello") {
   CHECK(1 == 1);
   INFO("HI");
}

TEST_CASE("Register test") {
  Register reg;
  uint64_t l = set_context(&reg);
  INFO(l);
}