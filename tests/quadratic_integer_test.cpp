#include <gtest/gtest.h>
#include "../math/quadratic_integer.h"

//=============================================================================
TEST(quadraticIntegerTest, DefaultConstructor) 
{
   EXPECT_EQ(GaussianInteger(), GaussianInteger::zero());
   EXPECT_EQ(QuadraticInteger<2>(), QuadraticInteger<2>::zero());
}

//=============================================================================
TEST(quadraticIntegerTest, IntegerConstructor) 
{
   EXPECT_EQ(GaussianInteger(0,0), GaussianInteger::zero());
   EXPECT_EQ(QuadraticInteger<2>(0,0), QuadraticInteger<2>::zero());
}

//=============================================================================
TEST(quadraticIntegerTest, GaussianAddition) 
{
   // 0 + 0
   EXPECT_EQ(GaussianInteger(0,0) + GaussianInteger(0,0), GaussianInteger::zero());

   // X + 0
   EXPECT_EQ(GaussianInteger(1,2) + GaussianInteger(0,0), GaussianInteger(1,2));
   EXPECT_EQ(GaussianInteger(0,0) + GaussianInteger(1,2), GaussianInteger(1,2));

   // X + Y
   EXPECT_EQ(GaussianInteger(1,2) + GaussianInteger(-4,5), GaussianInteger(-3,7));
   EXPECT_EQ(GaussianInteger(-4,5) + GaussianInteger(1,2), GaussianInteger(-3,7));

   // X + Y = 0
   EXPECT_EQ(GaussianInteger(1,2) + GaussianInteger(-1,-2), GaussianInteger::zero());
   EXPECT_EQ(GaussianInteger(-1,-2) + GaussianInteger(1,2), GaussianInteger::zero());
}

//=============================================================================
TEST(quadraticIntegerTest, Root2Addition) 
{
   // 0 + 0
   EXPECT_EQ(QuadraticInteger<2>(0,0) + QuadraticInteger<2>(0,0), QuadraticInteger<2>::zero());

   // X + 0
   EXPECT_EQ(QuadraticInteger<2>(1,2) + QuadraticInteger<2>(0,0), QuadraticInteger<2>(1,2));
   EXPECT_EQ(QuadraticInteger<2>(0,0) + QuadraticInteger<2>(1,2), QuadraticInteger<2>(1,2));

   // X + Y
   EXPECT_EQ(QuadraticInteger<2>(1,2) + QuadraticInteger<2>(-4,5), QuadraticInteger<2>(-3,7));
   EXPECT_EQ(QuadraticInteger<2>(-4,5) + QuadraticInteger<2>(1,2), QuadraticInteger<2>(-3,7));

   // X + Y = 0
   EXPECT_EQ(QuadraticInteger<2>(1,2) + QuadraticInteger<2>(-1,-2), QuadraticInteger<2>::zero());
   EXPECT_EQ(QuadraticInteger<2>(-1,-2) + QuadraticInteger<2>(1,2), QuadraticInteger<2>::zero());
}

//=============================================================================
TEST(quadraticIntegerTest, Negation) 
{
   // -0
   EXPECT_EQ(-GaussianInteger(0,0), GaussianInteger::zero());
   EXPECT_EQ(-QuadraticInteger<2>(0,0), QuadraticInteger<2>::zero());

   // -X
   EXPECT_EQ(-GaussianInteger(1,-2), GaussianInteger(-1,2));
   EXPECT_EQ(-QuadraticInteger<2>(1,-2), QuadraticInteger<2>(-1,2));

   // -(-X)
   EXPECT_EQ(-(-GaussianInteger(1,-2)), GaussianInteger(1,-2));
   EXPECT_EQ(-(-QuadraticInteger<2>(1,-2)), QuadraticInteger<2>(1,-2));

   // X + (-X) = 0
   EXPECT_EQ(GaussianInteger(1,-2) + (-GaussianInteger(1,-2)), GaussianInteger::zero());
   EXPECT_EQ(QuadraticInteger<2>(1,-2) + (-QuadraticInteger<2>(1,-2)), QuadraticInteger<2>::zero());
}

//=============================================================================
TEST(quadraticIntegerTest, Conjugation) 
{
   // ~0
   EXPECT_EQ(GaussianInteger(0,0).conjugate(), GaussianInteger::zero());
   EXPECT_EQ(QuadraticInteger<2>(0,0).conjugate(), QuadraticInteger<2>::zero());

   // ~X
   EXPECT_EQ(GaussianInteger(1,-2).conjugate(), GaussianInteger(1,2));
   EXPECT_EQ(QuadraticInteger<2>(1,-2).conjugate(), QuadraticInteger<2>(1,2));

   // ~(~X)
   EXPECT_EQ(GaussianInteger(1,-2).conjugate().conjugate(), GaussianInteger(1,-2));
   EXPECT_EQ(QuadraticInteger<2>(1,-2).conjugate().conjugate(), QuadraticInteger<2>(1,-2));

   // X + (~X) = int
   EXPECT_EQ(GaussianInteger(1,-2) + GaussianInteger(1,-2).conjugate(), Integer(2));
   EXPECT_EQ(QuadraticInteger<2>(1,-2) + QuadraticInteger<2>(1,-2).conjugate(), Integer(2));
}

//=============================================================================
TEST(quadraticIntegerTest, GaussianSubtraction) 
{
   // 0 - 0
   EXPECT_EQ(GaussianInteger(0,0) - GaussianInteger(0,0), GaussianInteger::zero());

   // X - 0
   EXPECT_EQ(GaussianInteger(1,2) - GaussianInteger(0,0), GaussianInteger(1,2));
   EXPECT_EQ(GaussianInteger(0,0) - GaussianInteger(1,2), GaussianInteger(-1,-2));

   // X - Y
   EXPECT_EQ(GaussianInteger(1,2) - GaussianInteger(-4,5), GaussianInteger(5,-3));
   EXPECT_EQ(GaussianInteger(-4,5) - GaussianInteger(1,2), GaussianInteger(-5,3));

   // X - X = 0
   EXPECT_EQ(GaussianInteger(1,2) - GaussianInteger(1,2), GaussianInteger::zero());
}

//=============================================================================
TEST(quadraticIntegerTest, Root2Subtraction) 
{
   // 0 - 0
   EXPECT_EQ(QuadraticInteger<2>(0,0) - QuadraticInteger<2>(0,0), QuadraticInteger<2>::zero());

   // X - 0
   EXPECT_EQ(QuadraticInteger<2>(1,2) - QuadraticInteger<2>(0,0), QuadraticInteger<2>(1,2));
   EXPECT_EQ(QuadraticInteger<2>(0,0) - QuadraticInteger<2>(1,2), QuadraticInteger<2>(-1,-2));

   // X - Y
   EXPECT_EQ(QuadraticInteger<2>(1,2) - QuadraticInteger<2>(-4,5), QuadraticInteger<2>(5,-3));
   EXPECT_EQ(QuadraticInteger<2>(-4,5) - QuadraticInteger<2>(1,2), QuadraticInteger<2>(-5,3));

   // X - X = 0
   EXPECT_EQ(QuadraticInteger<2>(1,2) - QuadraticInteger<2>(1,2), QuadraticInteger<2>::zero());
}

//=============================================================================
TEST(quadraticIntegerTest, GaussianMultiplication) 
{
   // 0 * 0
   EXPECT_EQ(GaussianInteger(0,0) * GaussianInteger(0,0), GaussianInteger::zero());

   // X * 0
   EXPECT_EQ(GaussianInteger(1,2) * GaussianInteger(0,0), GaussianInteger::zero());
   EXPECT_EQ(GaussianInteger(0,0) * GaussianInteger(1,2), GaussianInteger::zero());

   // X * Y
   EXPECT_EQ(GaussianInteger(1,2) * GaussianInteger(-4,5), GaussianInteger(-14,-3));
   EXPECT_EQ(GaussianInteger(-4,5) * GaussianInteger(1,2), GaussianInteger(-14,-3));
}

//=============================================================================
TEST(quadraticIntegerTest, Root2Multiplication) 
{
   // 0 * 0
   EXPECT_EQ(QuadraticInteger<2>(0,0) * QuadraticInteger<2>(0,0), QuadraticInteger<2>::zero());

   // X * 0
   EXPECT_EQ(QuadraticInteger<2>(1,2) * QuadraticInteger<2>(0,0), QuadraticInteger<2>::zero());
   EXPECT_EQ(QuadraticInteger<2>(0,0) * QuadraticInteger<2>(1,2), QuadraticInteger<2>::zero());

   // X - Y
   EXPECT_EQ(QuadraticInteger<2>(1,2) * QuadraticInteger<2>(-4,5), QuadraticInteger<2>(16,-3));
   EXPECT_EQ(QuadraticInteger<2>(-4,5) * QuadraticInteger<2>(1,2), QuadraticInteger<2>(16,-3));
}

//=============================================================================
TEST(quadraticIntegerTest, Zero) 
{
   EXPECT_EQ(GaussianInteger(0,0), GaussianInteger::zero());
   EXPECT_TRUE(GaussianInteger::zero().isZero());
   EXPECT_FALSE(GaussianInteger::unity().isZero());

   EXPECT_EQ(QuadraticInteger<2>(0,0), QuadraticInteger<2>::zero());
   EXPECT_TRUE(QuadraticInteger<2>::zero().isZero());
   EXPECT_FALSE(QuadraticInteger<2>::unity().isZero());
}

//=============================================================================
TEST(quadraticIntegerTest, Unity) 
{
   EXPECT_EQ(GaussianInteger(1,0), GaussianInteger::unity());
   EXPECT_TRUE(GaussianInteger::unity().isUnity());
   EXPECT_FALSE(GaussianInteger::zero().isUnity());

   EXPECT_EQ(QuadraticInteger<2>(1,0), QuadraticInteger<2>::unity());
   EXPECT_TRUE(QuadraticInteger<2>::unity().isUnity());
   EXPECT_FALSE(QuadraticInteger<2>::zero().isUnity());

   // X * 1 = X
   EXPECT_EQ(GaussianInteger(1,2) * GaussianInteger::unity(), GaussianInteger(1,2));
   EXPECT_EQ(GaussianInteger::unity() * GaussianInteger(1,2), GaussianInteger(1,2));

   EXPECT_EQ(QuadraticInteger<2>(1,2) * QuadraticInteger<2>::unity(), QuadraticInteger<2>(1,2));
   EXPECT_EQ(QuadraticInteger<2>::unity() * QuadraticInteger<2>(1,2), QuadraticInteger<2>(1,2));
}

//=============================================================================
TEST(quadraticIntegerTest, IntegerConversion) 
{
   EXPECT_EQ(GaussianInteger(1), GaussianInteger(1,0));
   EXPECT_EQ(GaussianInteger(1, 0).toInteger(), Integer(1));
   EXPECT_THROW(GaussianInteger(1, 1).toInteger(), std::runtime_error);
}
