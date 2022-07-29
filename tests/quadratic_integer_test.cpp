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
TEST(quadraticIntegerTest, Addition) 
{
   EXPECT_EQ(GaussianInteger(0,0) += GaussianInteger(0,0), GaussianInteger::zero());
   EXPECT_EQ(QuadraticInteger<2>(0,0) + QuadraticInteger<2>(0,0), QuadraticInteger<2>(0,0));
}
