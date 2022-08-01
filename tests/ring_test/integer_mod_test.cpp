#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::IntegerMod;

//=============================================================================
TEST(integerModTest, DefaultConstructor) 
{
   EXPECT_EQ(IntegerMod<3>(), IntegerMod<3>::zero());
   EXPECT_EQ(IntegerMod<10>(), IntegerMod<10>::zero());
}

//=============================================================================
TEST(integerModTest, IntegerConstructor) 
{
   EXPECT_EQ(IntegerMod<3>(0), IntegerMod<3>::zero());
   EXPECT_EQ(IntegerMod<3>(3), IntegerMod<3>::zero());
   EXPECT_EQ(IntegerMod<3>(-9), IntegerMod<3>::zero());

   EXPECT_EQ(IntegerMod<10>(0), IntegerMod<10>::zero());
   EXPECT_EQ(IntegerMod<10>(20), IntegerMod<10>::zero());
   EXPECT_EQ(IntegerMod<10>(-30), IntegerMod<10>::zero());
}

//=============================================================================
TEST(integerModTest, Addition) 
{
   // X + Y
   EXPECT_EQ(IntegerMod<3>(1) + IntegerMod<3>(1), IntegerMod<3>(2));
   EXPECT_EQ(IntegerMod<10>(5) + IntegerMod<10>(4), IntegerMod<10>(9));

   // X + Y = 0
   EXPECT_EQ(IntegerMod<3>(1) + IntegerMod<3>(2), IntegerMod<3>::zero());
   EXPECT_EQ(IntegerMod<10>(6) + IntegerMod<10>(4), IntegerMod<10>::zero());
}

//=============================================================================
TEST(integerModTest, Negation) 
{
   // -X
   EXPECT_EQ(-IntegerMod<3>(1), IntegerMod<3>(2));
   EXPECT_EQ(-IntegerMod<10>(5), IntegerMod<10>(5));

   //-(-X)
   EXPECT_EQ(-(-IntegerMod<3>(1)), IntegerMod<3>(1));
   EXPECT_EQ(-(-IntegerMod<10>(5)), IntegerMod<10>(5));
}

//=============================================================================
TEST(integerModTest, Subtraction) 
{
   // X - Y
   EXPECT_EQ(IntegerMod<3>(2) - IntegerMod<3>(1), IntegerMod<3>(1));
   EXPECT_EQ(IntegerMod<3>(1) - IntegerMod<3>(2), IntegerMod<3>(2));
   EXPECT_EQ(IntegerMod<10>(9) - IntegerMod<10>(5), IntegerMod<10>(4));
   EXPECT_EQ(IntegerMod<10>(5) - IntegerMod<10>(9), IntegerMod<10>(6));

   // X - Y = 0
   EXPECT_EQ(IntegerMod<3>(1) - IntegerMod<3>(1), IntegerMod<3>::zero());
   EXPECT_EQ(IntegerMod<10>(6) - IntegerMod<10>(6), IntegerMod<10>::zero());
}

//=============================================================================
TEST(integerModTest, Multiplication) 
{
   // X * Y
   EXPECT_EQ(IntegerMod<3>(2) * IntegerMod<3>(2), IntegerMod<3>(1));
   EXPECT_EQ(IntegerMod<10>(5) * IntegerMod<10>(3), IntegerMod<10>(5));

   // X * Y = 0
   EXPECT_EQ(IntegerMod<4>(2) * IntegerMod<4>(2), IntegerMod<4>::zero());
   EXPECT_EQ(IntegerMod<10>(5) * IntegerMod<10>(4), IntegerMod<10>::zero());
}

//=============================================================================
TEST(integerModTest, Zero) 
{
   EXPECT_EQ(IntegerMod<3>(0), IntegerMod<3>::zero());
   EXPECT_TRUE(IntegerMod<3>::zero().isZero());
   EXPECT_FALSE(IntegerMod<3>::unity().isZero());

   EXPECT_EQ(IntegerMod<10>(0), IntegerMod<10>::zero());
   EXPECT_TRUE(IntegerMod<10>::zero().isZero());
   EXPECT_FALSE(IntegerMod<10>::unity().isZero());
}

//=============================================================================
TEST(integerModTest, Unity) 
{
   EXPECT_EQ(IntegerMod<3>(1), IntegerMod<3>::unity());
   EXPECT_TRUE(IntegerMod<3>::unity().isUnity());
   EXPECT_FALSE(IntegerMod<3>::zero().isUnity());

   EXPECT_EQ(IntegerMod<10>(1), IntegerMod<10>::unity());
   EXPECT_TRUE(IntegerMod<10>::unity().isUnity());
   EXPECT_FALSE(IntegerMod<10>::zero().isUnity());

   // Special case for N=1 (zero ring)
   EXPECT_EQ(IntegerMod<1>::zero(), IntegerMod<1>::unity());
}

//=============================================================================
TEST(integerModTest, IntegerConversion) 
{
   EXPECT_EQ(IntegerMod<3>(20).toInteger(), 2);
   EXPECT_EQ(IntegerMod<10>(20).toInteger(), 0);
}
