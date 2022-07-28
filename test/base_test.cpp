#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <utils/defines.h>

#include <iostream>

namespace BaseTest {
namespace {
TEST(BaseTest, Stdio) {
  LOG("hi");
  EXPECT_EQ(0, 0);
}
}  // namespace
}  // namespace BaseTest
