#include <gmock/gmock.h>
#include <greenthread/mem.h>
#include <gtest/gtest.h>
#include <register/register.h>

#include <iostream>

#include "testsettings.hpp"

namespace RegisterTest {
namespace {
TEST(RegisterTest, set_context) {
  auto reg = new Register{.rsp = 0, .rdx = (uint64_t)EntryPoint};
  uint64_t ls = set_context(reg);
  EXPECT_EQ(ls, 1);
  std::cerr << STDERR_GTEST_INIT << "Hi" << '\n';
  uint64_t lw = switch_context(reg);
  EXPECT_EQ(lw, 1);
}

}  // namespace
}  // namespace RegisterTest
