#include <gtest/gtest.h>
#include "../math/ring/integer.h"
#include "../math/ring/cas_rational.h"
#include "../math/algorithm/common.h"

using CAS::abs;
using CAS::Integer;
using CAS::Rational;

//=============================================================================
TEST(absTest, Integer) 
{
   EXPECT_EQ(abs(Integer(0)), Integer(0));
   EXPECT_EQ(abs(Integer(10)), Integer(10));
   EXPECT_EQ(abs(Integer(-10)), Integer(10));
}

//=============================================================================
TEST(absTest, Rational) 
{
   EXPECT_EQ(abs(Rational(0)), Rational(0));
   EXPECT_EQ(abs(Rational(5/7)), Rational(5/7));
   EXPECT_EQ(abs(Rational(-13/8)), Rational(13/8));
}
