#include <gtest/gtest.h>
#include <gmpxx.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  mpz_class a, b, c;
  a = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1234_mpz;
  b = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5678_mpz;  // Expect two strings not to be equal.

  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(a, 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1234_mpz);
}
