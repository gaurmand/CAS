#include <gtest/gtest.h>
#include "../math/gmp_rational.h"
#include "../math/cas_rational.h"

using CAS::Rational;
using CAS::Integer;

//=============================================================================
TEST(rationalTest, DefaultConstructor) 
{
   EXPECT_EQ(Rational(), Rational::zero());
}

//=============================================================================
TEST(rationalTest, IntConstructor) 
{
   EXPECT_EQ(Rational(0, 1), Rational::zero());
   EXPECT_EQ(Rational(0, 5), Rational::zero());
   EXPECT_EQ(Rational(0), Rational::zero());

   EXPECT_EQ(Rational(5), Rational(5, 1));
   EXPECT_EQ(Rational(5), Rational(100, 20));

   EXPECT_EQ(Rational(1, 2), Rational(2, 4));
   EXPECT_EQ(Rational(1, 2), Rational(8, 16));
   EXPECT_EQ(Rational(1, -2), Rational(-1, 2));

   EXPECT_THROW(Rational(1, 0), std::domain_error);
}

//=============================================================================
TEST(rationalTest, Addition) 
{
   // O + 0
   EXPECT_EQ(Rational(0) + Rational(0), Rational::zero());

   // O + X
   EXPECT_EQ(Rational(0) + Rational(1, 2), Rational(1, 2));

   // X + Y
   EXPECT_EQ(Rational(1, 2) + Rational(1, 4), Rational(3, 4));
   EXPECT_EQ(Rational(1, 2) + Rational(-1, 4), Rational(1, 4));
   EXPECT_EQ(Rational(1, -2) + Rational(1, 4), Rational(-1, 4));
   EXPECT_EQ(Rational(1, -2) + Rational(-1, 4), Rational(-3, 4));

   // X + Y = 1
   EXPECT_EQ(Rational(1, 2) + Rational(1, 2), Rational(1));
   EXPECT_EQ(Rational(-3, 7) + Rational(-4, 7), Rational(-1));

   // X + Y = 0
   EXPECT_EQ(Rational(1, 2) + Rational(-1, 2), Rational::zero());
   EXPECT_EQ(Rational(3, 7) + Rational(-3, 7), Rational::zero());
}

//=============================================================================
TEST(rationalTest, Negation) 
{
   // -0
   EXPECT_EQ(-Rational(0), Rational::zero());
   EXPECT_EQ(Rational(-0), Rational::zero());

   // -X
   EXPECT_EQ(-Rational(2), Rational(-2));
   EXPECT_EQ(-Rational(-1, 2), Rational(1, 2));

   // -(-X)
   EXPECT_EQ(-(-Rational(2)), Rational(2));
   EXPECT_EQ(-(-Rational(-1, 2)), Rational(-1, 2));
}

//=============================================================================
TEST(rationalTest, Subtraction) 
{
   // O - 0
   EXPECT_EQ(Rational(0) - Rational(0), Rational::zero());

   // O - X
   EXPECT_EQ(Rational(0) - Rational(1, 2), Rational(-1, 2));
   EXPECT_EQ(Rational(1,2) - Rational(0), Rational(1, 2));

   // X - Y
   EXPECT_EQ(Rational(1, 2) - Rational(1, 4), Rational(1, 4));
   EXPECT_EQ(Rational(1, 2) - Rational(-1, 4), Rational(3, 4));
   EXPECT_EQ(Rational(1, -2) - Rational(1, 4), Rational(-3, 4));
   EXPECT_EQ(Rational(1, -2) - Rational(-1, 4), Rational(-1, 4));

   // X - Y = 1
   EXPECT_EQ(Rational(3, 7) - Rational(-4, 7), Rational(1));
   EXPECT_EQ(Rational(-7, 4) - Rational(1, 4), Rational(-2));

   // X - Y = 0
   EXPECT_EQ(Rational(1, 2) - Rational(1, 2), Rational::zero());
}

//=============================================================================
TEST(rationalTest, Multiplication) 
{
   // O * 0
   EXPECT_EQ(Rational(0) * Rational(0), Rational::zero());

   // O * X
   EXPECT_EQ(Rational(0) * Rational(1, 2), Rational::zero());

   // X * Y
   EXPECT_EQ(Rational(1, 2) * Rational(1, 4), Rational(1, 8));
   EXPECT_EQ(Rational(1, 2) * Rational(-1, 4), Rational(-1, 8));
   EXPECT_EQ(Rational(-1, 2) * Rational(1, 4), Rational(-1, 8));
   EXPECT_EQ(Rational(-1, 2) * Rational(-1, 4), Rational(1, 8));

   // X * Y canonicalize
   EXPECT_EQ(Rational(3, 14) * Rational(7, 3), Rational(1, 2));
   EXPECT_EQ(Rational(-5, 32) * Rational(64, 5), Rational(-2));

   // X * Y = 1
   EXPECT_EQ(Rational(1, 8) * Rational(8), Rational(1));
   EXPECT_EQ(Rational(-1, 8) * Rational(8), Rational(-1));
}

//=============================================================================
TEST(rationalTest, Zero) 
{
   EXPECT_EQ(Rational(0), Rational::zero());
   EXPECT_TRUE(Rational::zero().isZero());
   EXPECT_FALSE(Rational::unity().isZero());
}

//=============================================================================
TEST(rationalTest, Unity) 
{
   EXPECT_EQ(Rational(1), Rational::unity());
   EXPECT_TRUE(Rational::unity().isUnity());
   EXPECT_FALSE(Rational::zero().isUnity());
}

//=============================================================================
TEST(rationalTest, IntegerConversion) 
{
   EXPECT_EQ(Rational(1).toInteger(), Integer(1));
   EXPECT_THROW(Rational(1, 2).toInteger(), std::runtime_error);
}
