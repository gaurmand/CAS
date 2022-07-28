#include <gtest/gtest.h>
#include "../math/integer.h"

//=======================================================================================
TEST(integerTest, DefaultConstructor) 
{
   EXPECT_EQ(Integer(), Integer::zero());
}

//=======================================================================================
TEST(integerTest, IntConstructor) 
{
   EXPECT_EQ(Integer(0), Integer::zero());
   EXPECT_EQ(Integer(0u), Integer::zero());
   EXPECT_EQ(Integer(0l), Integer::zero());
   EXPECT_EQ(Integer(0ul), Integer::zero());
}

//=======================================================================================
TEST(integerTest, Addition) 
{
   // O + 0
   EXPECT_EQ(Integer(0) + Integer(0), Integer::zero());

   // 0 + P
   EXPECT_EQ(Integer(0) + Integer(10), Integer(10));
   EXPECT_EQ(Integer(10) + Integer(0), Integer(10));

   // 0 + N
   EXPECT_EQ(Integer(0) + Integer(-10), Integer(-10));
   EXPECT_EQ(Integer(-10) + Integer(0), Integer(-10));

   // P + P
   EXPECT_EQ(Integer(20) + Integer(10), Integer(30));
   EXPECT_EQ(Integer(10) + Integer(20), Integer(30));

   // N + N
   EXPECT_EQ(Integer(-20) + Integer(-10), Integer(-30));
   EXPECT_EQ(Integer(-10) + Integer(-20), Integer(-30));

   // P + N
   EXPECT_EQ(Integer(20) + Integer(-10), Integer(10));
   EXPECT_EQ(Integer(-10) + Integer(20), Integer(10));

   // P + N = 0
   EXPECT_EQ(Integer(10) + Integer(-10), Integer::zero());
   EXPECT_EQ(Integer(-10) + Integer(10), Integer::zero());
}

//=======================================================================================
TEST(integerTest, Negation) 
{  
   // - 0
   EXPECT_EQ(-Integer(0), Integer::zero());

   // - P
   EXPECT_EQ(-Integer(10), Integer(-10));

   // - N
   EXPECT_EQ(-Integer(-10), Integer(10));

   // -(-P) = P
   EXPECT_EQ(-(-Integer(10)), Integer(10));

   // -(-N) = N
   EXPECT_EQ(-(-Integer(-10)), Integer(-10));
}

//=======================================================================================
TEST(integerTest, Subtraction) 
{
   // O - 0
   EXPECT_EQ(Integer(0) - Integer(0), Integer::zero());

   // 0 - P / P - 0
   EXPECT_EQ(Integer(0) - Integer(10), Integer(-10));
   EXPECT_EQ(Integer(10) - Integer(0), Integer(10));

   // 0 - N / N - 0
   EXPECT_EQ(Integer(0) - Integer(-10), Integer(10));
   EXPECT_EQ(Integer(-10) - Integer(0), Integer(-10));

   // P - P
   EXPECT_EQ(Integer(20) - Integer(10), Integer(10));
   EXPECT_EQ(Integer(10) - Integer(20), Integer(-10));

   // N - N
   EXPECT_EQ(Integer(-20) - Integer(-10), Integer(-10));
   EXPECT_EQ(Integer(-10) - Integer(-20), Integer(10));

   // P - N / N - P
   EXPECT_EQ(Integer(20) - Integer(-10), Integer(30));
   EXPECT_EQ(Integer(-10) - Integer(20), Integer(-30));

   // P - P = 0 / N - N = 0
   EXPECT_EQ(Integer(10) - Integer(10), Integer::zero());
   EXPECT_EQ(Integer(-10) - Integer(-10), Integer::zero());
}

//=======================================================================================
TEST(integerTest, Multiplication) 
{
   // O * 0
   EXPECT_EQ(Integer(0) * Integer(0), Integer::zero());

   // 0 * P / P * 0
   EXPECT_EQ(Integer(0) * Integer(10), Integer::zero());
   EXPECT_EQ(Integer(10) * Integer(0), Integer::zero());

   // 0 * N / N * 0
   EXPECT_EQ(Integer(0) * Integer(-10), Integer::zero());
   EXPECT_EQ(Integer(-10) * Integer(0), Integer::zero());

   // P * P
   EXPECT_EQ(Integer(20) * Integer(10), Integer(200));
   EXPECT_EQ(Integer(10) * Integer(20), Integer(200));

   // N * N
   EXPECT_EQ(Integer(-20) * Integer(-10), Integer(200));
   EXPECT_EQ(Integer(-10) * Integer(-20), Integer(200));

   // P * N / N * P
   EXPECT_EQ(Integer(20) * Integer(-10), Integer(-200));
   EXPECT_EQ(Integer(-10) * Integer(20), Integer(-200));
}

//=======================================================================================
TEST(integerTest, Zero) 
{
   EXPECT_EQ(Integer(0), Integer::zero());
   EXPECT_TRUE(Integer::zero().isZero());
   EXPECT_FALSE(Integer::unity().isZero());
}

//=======================================================================================
TEST(integerTest, Unity) 
{
   EXPECT_EQ(Integer(1), Integer::unity());
   EXPECT_TRUE(Integer::unity().isUnity());
   EXPECT_FALSE(Integer::zero().isUnity());
}
