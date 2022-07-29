#include <gtest/gtest.h>
#include "../math/integer.h"

//=============================================================================
TEST(integerTest, DefaultConstructor) 
{
   EXPECT_EQ(Integer(), Integer::zero());
}

//=============================================================================
TEST(integerTest, NumericConstructors) 
{  
   EXPECT_EQ(Integer((char)0), Integer::zero());
   EXPECT_EQ(Integer((short)0), Integer::zero());
   EXPECT_EQ(Integer((int)0), Integer::zero());
   EXPECT_EQ(Integer((long)0), Integer::zero());

   EXPECT_EQ(Integer((unsigned char)0), Integer::zero());
   EXPECT_EQ(Integer((unsigned short)0), Integer::zero());
   EXPECT_EQ(Integer((unsigned int)0), Integer::zero());
   EXPECT_EQ(Integer((unsigned long)0), Integer::zero());

   // Deleted constructors
   // EXPECT_EQ(Integer((long long)0), Integer::zero());
   // EXPECT_EQ(Integer((unsigned long long)0), Integer::zero());
   // EXPECT_EQ(Integer((float)0), Integer::zero());
   // EXPECT_EQ(Integer((double)0), Integer::zero());
   // EXPECT_EQ(Integer((long double)0), Integer::zero());
}

//=============================================================================
TEST(integerTest, StringConstructors) 
{  
   // Decimal
   EXPECT_EQ(Integer("65535"), Integer(65535));
   EXPECT_EQ(Integer("65535", 10), Integer(65535));

   // Binary
   EXPECT_EQ(Integer("0b1111111111111111"), Integer(65535));
   EXPECT_EQ(Integer("1111111111111111", 2), Integer(0b1111111111111111));

   // Base 4
   EXPECT_EQ(Integer("33333333", 4), Integer(65535));

   // Octal
   EXPECT_EQ(Integer("0177777"), Integer(0177777));
   EXPECT_EQ(Integer("0177777", 8), Integer(0177777));

   // Base 12
   EXPECT_EQ(Integer("31b13", 12), Integer(65535));

   // Hexadecimal
   EXPECT_EQ(Integer("0xFFFF"), Integer(0xFFFF));
   EXPECT_EQ(Integer("FFFF", 16), Integer(0xFFFF));

   // Base 62 (max base)
   EXPECT_EQ(Integer("H31", 62), Integer(65535));
}

//=============================================================================
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

//=============================================================================
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

   // P + (-P) = 0
   EXPECT_EQ(Integer(10) + (-Integer(10)), Integer::zero());
   
   // N + (-N) = 0
   EXPECT_EQ(Integer(-10) + (-Integer(-10)), Integer::zero());
}

//=============================================================================
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

//=============================================================================
TEST(integerTest, Multiplication) 
{
   // O * 0
   EXPECT_EQ(Integer(0) * Integer(0), Integer::zero());

   // 0 * P
   EXPECT_EQ(Integer(0) * Integer(10), Integer::zero());
   EXPECT_EQ(Integer(10) * Integer(0), Integer::zero());

   // 0 * N
   EXPECT_EQ(Integer(0) * Integer(-10), Integer::zero());
   EXPECT_EQ(Integer(-10) * Integer(0), Integer::zero());

   // P * P
   EXPECT_EQ(Integer(20) * Integer(10), Integer(200));
   EXPECT_EQ(Integer(10) * Integer(20), Integer(200));

   // N * N
   EXPECT_EQ(Integer(-20) * Integer(-10), Integer(200));
   EXPECT_EQ(Integer(-10) * Integer(-20), Integer(200));

   // P * N
   EXPECT_EQ(Integer(20) * Integer(-10), Integer(-200));
   EXPECT_EQ(Integer(-10) * Integer(20), Integer(-200));
}

//=============================================================================
TEST(integerTest, Zero) 
{
   EXPECT_EQ(Integer(0), Integer::zero());
   EXPECT_TRUE(Integer::zero().isZero());
   EXPECT_FALSE(Integer::unity().isZero());
}

//=============================================================================
TEST(integerTest, Unity) 
{
   EXPECT_EQ(Integer(1), Integer::unity());
   EXPECT_TRUE(Integer::unity().isUnity());
   EXPECT_FALSE(Integer::zero().isUnity());

   // X * 1 = X
   EXPECT_EQ(Integer(5) * Integer::unity(), Integer(5));
   EXPECT_EQ(Integer::unity() * Integer(5), Integer(5));
}
