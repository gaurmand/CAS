#include "ring/integer.h"

#include <gtest/gtest.h>
#include <string>

using namespace CAS;

TEST(integerTest, BasicConstruction) 
{
   EXPECT_EQ(Integer(), Integer(0));

   EXPECT_EQ(Integer(true), Integer(1));
   EXPECT_EQ(Integer(false), Integer(0));

   EXPECT_EQ(Integer('a'), Integer(97));
   EXPECT_EQ(Integer(97), Integer(97));
   EXPECT_EQ(Integer(97l), Integer(97));
   EXPECT_EQ(Integer(97ull), Integer(97));
}

TEST(integerTest, StringConstruction) 
{
   using namespace std::string_literals;
   using namespace std::string_view_literals;

   EXPECT_EQ(Integer("97"), Integer(97));
   EXPECT_EQ(Integer("97"sv), Integer(97));
   EXPECT_EQ(Integer("97"s), Integer(97));
}

TEST(integerTest, LongIntConstruction) 
{
   Integer a1("93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
   Integer a2(1);
   for (int i = 1; i <= 100; ++i)
   {
      a2 *= i;
   }

   EXPECT_EQ(a1, a2);
}

TEST(integerTest, Equality) 
{
   Integer a1(100);
   EXPECT_EQ(a1, a1);
   EXPECT_GE(a1, a1);
   EXPECT_LE(a1, a1);
   EXPECT_EQ(a1, 100);
   EXPECT_EQ(100, a1);
}

TEST(integerTest, Comparison) 
{
   Integer a1(-100);
   Integer a2(100);
   EXPECT_LT(a1, a2);
   EXPECT_LE(a1, a2);
   EXPECT_GT(a2, a1);
   EXPECT_GE(a2, a1);
   EXPECT_LT(a1, 0);
   EXPECT_LT(0, a2);
}

TEST(integerTest, Addition) 
{
   Integer a1(1);
   Integer a2(-1);
   EXPECT_EQ(a1 + a2, 0);
   EXPECT_EQ(a1 + (-1), 0);
   EXPECT_EQ(1 + a2, 0);
   EXPECT_EQ(a1 += a2, 0);
   EXPECT_EQ(a2 += 0, a2);
}

TEST(integerTest, Subtraction) 
{
   Integer a1(1);
   Integer a2(1);
   EXPECT_EQ(a1 - a2, 0);
   EXPECT_EQ(a1 - 1, 0);
   EXPECT_EQ(1 - a2, 0);
   EXPECT_EQ(a1 -= a2, 0);
   EXPECT_EQ(a2 -= 0, a2);
}

TEST(integerTest, Multiplication) 
{
   Integer a1(2);
   Integer a2(3);
   EXPECT_EQ(a1 * a2, 6);
   EXPECT_EQ(a1 * 3, 6);
   EXPECT_EQ(2 * a2, 6);
   EXPECT_EQ(a1 *= a2, 6);
   EXPECT_EQ(a2 *= 0, 0);
}

TEST(integerTest, Quotient) 
{
   Integer a1(7);
   Integer a2(3);
   EXPECT_EQ(a1 / a2, 2);
   EXPECT_EQ(a1 / 3, 2);
   EXPECT_EQ(7 / a2, 2);
   EXPECT_EQ(a1 /= a2, 2);
   EXPECT_EQ(a2 /= 1, a2);
}

TEST(integerTest, Remainder) 
{
   Integer a1(7);
   Integer a2(3);
   EXPECT_EQ(a1 % a2, 1);
   EXPECT_EQ(a1 % 3, 1);
   EXPECT_EQ(7 % a2, 1);
   EXPECT_EQ(a1 %= a2, 1);
   EXPECT_EQ(a2 %= 3, 0);
}

TEST(integerTest, Quorem) 
{
   Integer a1(7);
   Integer a2(3);
   const auto [quo, rem] = a1.quorem(a2);
   EXPECT_EQ(quo, 2);
   EXPECT_EQ(rem, 1);
}

// TEST(integerTest, TruncatedDivision) 
// {
//    Integer a1(7);
//    Integer a2(-3);
//    EXPECT_EQ(a1 / a2, -2);
//    EXPECT_EQ(a1 % a2, 1);

//    Integer b1(-7);
//    Integer b2(3);
//    EXPECT_EQ(b1 / b2, -2);
//    EXPECT_EQ(b1 % b2, -1);

//    Integer c1(-7);
//    Integer c2(-3);
//    EXPECT_EQ(c1 / c2, 2);
//    EXPECT_EQ(c1 % c2, -1);
// }

TEST(integerTest, EuclideanDivision) 
{
   Integer a1(7);
   Integer a2(3);
   EXPECT_EQ(a1 / a2, 2);
   EXPECT_EQ(a1 % a2, 1);
   EXPECT_EQ(a1.quorem(a2), QuoremResult<Integer>(2, 1));

   Integer b1(7);
   Integer b2(-3);
   EXPECT_EQ(b1 / b2, -2);
   EXPECT_EQ(b1 % b2, 1);
   EXPECT_EQ(b1.quorem(b2), QuoremResult<Integer>(-2, 1));

   Integer c1(-7);
   Integer c2(3);
   EXPECT_EQ(c1 / c2, -3);
   EXPECT_EQ(c1 % c2, 2);
   EXPECT_EQ(c1.quorem(c2), QuoremResult<Integer>(-3, 2));

   Integer d1(-7);
   Integer d2(-3);
   EXPECT_EQ(d1 / d2, 3);
   EXPECT_EQ(d1 % d2, 2);
   EXPECT_EQ(d1.quorem(d2), QuoremResult<Integer>(3, 2));
}

TEST(integerTest, Negation) 
{
   Integer a1(2);
   Integer a2(-2);
   EXPECT_EQ(-a1, -2);
   EXPECT_EQ(-a2, 2);
}

TEST(integerTest, Identity) 
{
   EXPECT_EQ(Integer::zero(), 0);
   EXPECT_EQ(Integer::unity(), 1);
}

