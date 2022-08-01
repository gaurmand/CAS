#include <gtest/gtest.h>
#include "../../math/ring.h"
#include "../../math/algorithm.h"

using CAS::gcd;
using CAS::Integer;
using CAS::Rational;

//=============================================================================
TEST(gcdTest, Integer) 
{
   // 0 Arguments
   EXPECT_EQ(gcd(Integer(0), Integer(0)), Integer(0));
   EXPECT_EQ(gcd(Integer(4), Integer(0)), Integer(4));
   EXPECT_EQ(gcd(Integer(0), Integer(4)), Integer(4));

   // Divisors
   EXPECT_EQ(gcd(Integer(24), Integer(6)), Integer(6));
   EXPECT_EQ(gcd(Integer(6), Integer(24)), Integer(6));

   // Non-divisors
   EXPECT_EQ(gcd(Integer(1400), Integer(800)), Integer(200));
   EXPECT_EQ(gcd(Integer(800), Integer(1400)), Integer(200));

   // Coprime
   EXPECT_EQ(gcd(Integer(7), Integer(9)), Integer(1));
   EXPECT_EQ(gcd(Integer(140), Integer(97)), Integer(1));
   EXPECT_EQ(gcd(Integer(100003), Integer(10000)), Integer(1));

   // 0 Arguments Negative
   EXPECT_EQ(gcd(Integer(-10), Integer(0)), Integer(10));
   EXPECT_EQ(gcd(Integer(0), Integer(-10)), Integer(10));

   // Negative arguments
   EXPECT_EQ(gcd(Integer(2112), Integer(495)), Integer(33));
   EXPECT_EQ(gcd(Integer(-2112), Integer(495)), Integer(33));
   EXPECT_EQ(gcd(Integer(2112), Integer(-495)), Integer(33));
   EXPECT_EQ(gcd(Integer(-2112), Integer(-495)), Integer(33));

   // Large arguments
   EXPECT_EQ(gcd(Integer(1160718174), Integer(316258250)), Integer(1078));
}

//=============================================================================
TEST(gcdTest, Rational) 
{
   // NOTE: Every nonzero rational is divisible by every other nonzero rational, 
   // and also all nonzero rationals are associates. That's why gcd should always 
   // return 1 or 0.

   EXPECT_EQ(gcd(Rational(0), Rational(0)), Rational(0));
   EXPECT_EQ(gcd(Rational(4,3), Rational(0)), Rational(1));
   EXPECT_EQ(gcd(Rational(0), Rational(-4,3)), Rational(1));

   EXPECT_EQ(gcd(Rational(24,5), Rational(6,5)), Rational(1));
   EXPECT_EQ(gcd(Rational(-6,5), Rational(24,5)), Rational(1));
}
