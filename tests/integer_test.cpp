#include <gtest/gtest.h>
#include "../math/integer.h"

//=======================================================================================
template <typename T>
inline void test_construct()
{
   const T v = 0;
   EXPECT_EQ(Integer(v), Integer::zero());
}

//=======================================================================================
TEST(integerTest, DefaultConstructor) 
{
   EXPECT_EQ(Integer(), Integer::zero());
}

//=======================================================================================
TEST(integerTest, IntConstructor) 
{
   test_construct<char>();
   test_construct<short>();
   test_construct<int>();
   test_construct<long>();

   test_construct<unsigned char>();
   test_construct<unsigned short>();
   test_construct<unsigned int>();
   test_construct<unsigned long>();

   // // TODO: Disable construction from long long due to possible narrowing
   test_construct<long long>();
   test_construct<unsigned long long>();
}

//=======================================================================================
TEST(integerTest, FloatConstructor) 
{
   // TODO: Disable construction from floating point types
   test_construct<float>();
   test_construct<double>();
   test_construct<long double>();
}
