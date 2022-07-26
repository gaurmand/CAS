#include <gtest/gtest.h>
#include <gmpxx.h>
#include <string>

//=======================================================================================
inline void MPZ_SI_EQ(const mpz_class& x, long val)
{ 
  EXPECT_EQ(x.get_si(), val);
}

inline void MPZ_UI_EQ(const mpz_class& x, unsigned long val)
{
  EXPECT_EQ(x.get_ui(), val);
}

//=======================================================================================
// Constructor Tests
//=======================================================================================
TEST(mpzTest, DefaultConstructor) 
{
   MPZ_SI_EQ(mpz_class(), 0);
}

TEST(mpzTest, IntegerConstructors) 
{
   MPZ_SI_EQ(mpz_class(1), 1);
   MPZ_SI_EQ(mpz_class(1l), 1);
   MPZ_SI_EQ(mpz_class(1u), 1);
   MPZ_SI_EQ(mpz_class(1ul), 1);

   // get_ui() return abs value
   MPZ_UI_EQ(mpz_class(-1), 1);  
}

TEST(mpzTest, FloatConstructors)
{
   MPZ_SI_EQ(mpz_class(1.0), 1);
   MPZ_SI_EQ(mpz_class(1.0f), 1);

   // Float args are truncated
   MPZ_SI_EQ(mpz_class(1.5), 1);
}

TEST(mpzTest, StringConstructors)
{
   MPZ_SI_EQ(mpz_class("123"), 123);
   MPZ_SI_EQ(mpz_class(std::string("123")), 123);

   EXPECT_THROW({mpz_class c("123a");}, std::invalid_argument);
}

TEST(mpzTest, StringBaseConstructors)
{
   MPZ_SI_EQ(mpz_class("0xFFFF"), 65535);
   MPZ_SI_EQ(mpz_class("FFFF", 16), 65535);

   MPZ_SI_EQ(mpz_class("0177777"), 65535);
   MPZ_SI_EQ(mpz_class("177777", 8), 65535);

   MPZ_SI_EQ(mpz_class("0b1111111111111111"), 65535);
   MPZ_SI_EQ(mpz_class("1111111111111111", 2), 65535);

   MPZ_SI_EQ(mpz_class("65535"), 65535);
   MPZ_SI_EQ(mpz_class("65535", 10), 65535);
}

TEST(mpzTest, CopyConstructor) 
{  
   mpz_class a(1);
   MPZ_SI_EQ(mpz_class(a), 1);
}

TEST(mpzTest, Literals) 
{  
   MPZ_SI_EQ(12345_mpz, 12345);
   MPZ_SI_EQ(-12345_mpz, -12345);
}

//=======================================================================================
// Assignemnt/Comparison Operator Tests
//=======================================================================================

TEST(mpzTest, AssignmentOperator) 
{  
   mpz_class a;
   a = 25_mpz;
   MPZ_SI_EQ(a, 25);

   a = -25;
   MPZ_SI_EQ(a, -25);
   MPZ_UI_EQ(a, 25); // Abs value

   a = 2.99f;
   MPZ_SI_EQ(a, 2);  // Truncated
}

TEST(mpzTest, EqualityOperators) 
{  
   EXPECT_EQ(1_mpz, 1_mpz);
   EXPECT_NE(1_mpz, 0_mpz);
}

TEST(mpzTest, ComparisonOperators) 
{  
   EXPECT_GT(1_mpz, 0_mpz);
   EXPECT_GE(1_mpz, 0_mpz);
   EXPECT_GE(1_mpz, 1_mpz);

   EXPECT_LT(0_mpz, 1_mpz);
   EXPECT_LE(0_mpz, 1_mpz);
   EXPECT_LE(1_mpz, 1_mpz);
}

//=======================================================================================
// Arithmetic Operator Tests
//=======================================================================================
TEST(mpzTest, AdditionTest) 
{  
   mpz_class a = 1_mpz;
   mpz_class b = -1_mpz;
   EXPECT_EQ(a + a, 2_mpz);
   EXPECT_EQ(b + b, -2_mpz);
   EXPECT_EQ(a + b, 0_mpz);
}

TEST(mpzTest, SubtractionTest) 
{  
   mpz_class a = 1_mpz;
   mpz_class b = -1_mpz;
   EXPECT_EQ(a - a, 0_mpz);
   EXPECT_EQ(b - b, 0_mpz);
   EXPECT_EQ(a - b, 2_mpz);
   EXPECT_EQ(b - a, -2_mpz);
}

TEST(mpzTest, NegationTest) 
{  
   mpz_class a = 1_mpz;
   mpz_class b = -1_mpz;
   mpz_class c = 0_mpz;
   EXPECT_EQ(-a, -1_mpz);
   EXPECT_EQ(-b, 1_mpz);
   EXPECT_EQ(-c, 0_mpz);
}

TEST(mpzTest, MultiplicationTest) 
{  
   mpz_class a = 2_mpz;
   mpz_class b = -2_mpz;
   EXPECT_EQ(a * a, 4_mpz);
   EXPECT_EQ(b * b, 4_mpz);
   EXPECT_EQ(a * b, -4_mpz);
}

TEST(mpzTest, DivisionTest) 
{  
   mpz_class a = 4_mpz;
   mpz_class b = 2_mpz;
   mpz_class c = -2_mpz;
   EXPECT_EQ(a / a, 1_mpz);
   EXPECT_EQ(a / b, 2_mpz);
   EXPECT_EQ(a / c, -2_mpz);
   EXPECT_EQ(b / a, 0_mpz);

   // Round towards 0
   EXPECT_EQ(5_mpz / 3_mpz, 1_mpz);
   EXPECT_EQ(5_mpz / -3_mpz, -1_mpz);

   // Division by 0
   EXPECT_DEATH(mpz_class b = 5_mpz / 0_mpz, "");
}

TEST(mpzTest, ModTest) 
{  
   mpz_class a = 4_mpz;
   mpz_class b = 2_mpz;
   mpz_class c = -2_mpz;
   EXPECT_EQ(a % a, 0_mpz);
   EXPECT_EQ(a % b, 0_mpz);
   EXPECT_EQ(a % c, 0_mpz);

   // sign(remainder) = sign(quotient)
   EXPECT_EQ(5_mpz % 3_mpz, 2_mpz);
   EXPECT_EQ(5_mpz % -3_mpz, 2_mpz);
   EXPECT_EQ(-5_mpz % 3_mpz, -2_mpz);
   EXPECT_EQ(-5_mpz % -3_mpz, -2_mpz);

   // Mod by 0
   EXPECT_DEATH(mpz_class b = 5_mpz % 0_mpz, "");
}

//=======================================================================================
// Arbitrary Precision Tests
//=======================================================================================

TEST(mpzTest, LongIntTest) 
{  
   // 65 bit int (too large for long)
   mpz_class a = 0x10000000000000000_mpz;
   mpz_class b("0x10000000000000000");
   mpz_class c(std::string("0x10000000000000000"));
}

TEST(mpzTest, VeryLongIntTest) 
{  
   // 256-bit int
   mpz_class a = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF_mpz;
   EXPECT_EQ(a + a, 2*a);

   // 512-bit int
   mpz_class b = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF_mpz;
   EXPECT_EQ(b + b, 2*b);

   // 1024-bit int
   mpz_class c = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF_mpz;
   EXPECT_EQ(c + c, 2*c);
}
