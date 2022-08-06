#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;
using CAS::Polynomial;

using CAS::Integer;
using CAS::IntegerMod;
using CAS::GaussianInteger;
using CAS::Rational;

//=============================================================================
TEST(polynomialCtrTest, Default) 
{  
   EXPECT_EQ(Polynomial<Integer>().lt(), Term<Integer>());
   EXPECT_EQ(Polynomial<IntegerMod<7>>().lt(), Term<IntegerMod<7>>());
   EXPECT_EQ(Polynomial<GaussianInteger>().lt(), Term<GaussianInteger>());
   EXPECT_EQ(Polynomial<Rational>().lt(), Term<Rational>());
}

//=============================================================================
TEST(polynomialCtrTest, ZeroVector) 
{  
   // Empty vector
   EXPECT_EQ(
      Polynomial<Integer>(std::vector<Term<Integer>>()).lt(), 
      Term<Integer>());
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>(std::vector<Term<IntegerMod<7>>>()).lt(), 
      Term<IntegerMod<7>>());
   EXPECT_EQ(
      Polynomial<GaussianInteger>(std::vector<Term<GaussianInteger>>()).lt(), 
      Term<GaussianInteger>());
   EXPECT_EQ(
      Polynomial<Rational>(std::vector<Term<Rational>>()).lt(), 
      Term<Rational>());

   // Zero-polynomial vector
   EXPECT_EQ(
      Polynomial<Integer>({Term<Integer>()}).lt(), 
      Term<Integer>());
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term<IntegerMod<7>>()}).lt(), 
      Term<IntegerMod<7>>());
   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term<GaussianInteger>()}).lt(), 
      Term<GaussianInteger>());
   EXPECT_EQ(
      Polynomial<Rational>({Term<Rational>()}).lt(), 
      Term<Rational>());

   // Non-standard zero-polynomial vector
   EXPECT_EQ(
      Polynomial<Integer>({Term<Integer>(0,5)}).lt(), 
      Term<Integer>());
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(0),5)}).lt(), 
      Term<IntegerMod<7>>());
   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(0),5)}).lt(), 
      Term<GaussianInteger>());
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(0),5)}).lt(), 
      Term<Rational>());
}

//=============================================================================
TEST(polynomialCtrTest, IntegerVector) 
{  
   EXPECT_EQ(
      Polynomial<Integer>({Term<Integer>(5,5)}).lt(), 
      Term<Integer>(5,5));
   EXPECT_EQ(
      Polynomial<Integer>({Term<Integer>(5,5), Term<Integer>(1,1)}).lt(), 
      Term<Integer>(5,5));
   EXPECT_EQ(
      Polynomial<Integer>({Term<Integer>(3,5), Term<Integer>(2,5)}).lt(), 
      Term<Integer>(5,5));
   EXPECT_EQ(
      Polynomial<Integer>({Term<Integer>(2,0), Term<Integer>(2,5), Term<Integer>(7,4), Term<Integer>(3,5), Term<Integer>(1,1)}).lt(), 
      Term<Integer>(5,5));

   // Case where terms sum to 0
   EXPECT_EQ(
      Polynomial<Integer>({Term<Integer>(5,5), Term<Integer>(-5,5)}).lt(), 
      Term<Integer>());
}

//=============================================================================
TEST(polynomialCtrTest, IntegerModVector) 
{  
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(5),5)}).lt(), 
      Term(IntegerMod<7>(5),5));
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(5),5), Term(IntegerMod<7>(1),1)}).lt(), 
      Term(IntegerMod<7>(5),5));
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(3),5), Term(IntegerMod<7>(2),5)}).lt(), 
      Term(IntegerMod<7>(5),5));
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(2),0), Term(IntegerMod<7>(2),5), Term(IntegerMod<7>(7),4), Term(IntegerMod<7>(3),5), Term(IntegerMod<7>(1),1)}).lt(), 
      Term(IntegerMod<7>(5),5));

   // Case where terms sum to 0
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(7),1)}).lt(), 
      Term<IntegerMod<7>>());
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(3),5), Term(IntegerMod<7>(4),5)}).lt(), 
      Term<IntegerMod<7>>());
   EXPECT_EQ(
      Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(4),8), Term(IntegerMod<7>(2),5), Term(IntegerMod<7>(7),4), Term(IntegerMod<7>(3),5), Term(IntegerMod<7>(3),8)}).lt(), 
      Term(IntegerMod<7>(5),5));
}

//=============================================================================
TEST(polynomialCtrTest, GaussianIntegerVector) 
{  
   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(5,5),5)}).lt(), 
      Term(GaussianInteger(5,5),5));
   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(5,5),5), Term(GaussianInteger(1),1)}).lt(), 
      Term(GaussianInteger(5,5),5));
   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(3,2),5), Term(GaussianInteger(2,3),5)}).lt(), 
      Term(GaussianInteger(5,5),5));
   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(2,-5),0), Term(GaussianInteger(2,3),5), Term(GaussianInteger(7,6),4), Term(GaussianInteger(3,2),5), Term(GaussianInteger(1),1)}).lt(), 
      Term(GaussianInteger(5,5),5));

   // Case where terms sum to 0
   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(-5,5),5), Term(GaussianInteger(5,-5),5)}).lt(), 
      Term<GaussianInteger>());
}

//=============================================================================
TEST(polynomialCtrTest, RationalVector) 
{  
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(5,3),5)}).lt(), 
      Term(Rational(5,3),5));
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(5,3),5), Term(Rational(1),1)}).lt(), 
      Term(Rational(5,3),5));
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1),5), Term(Rational(2,3),5)}).lt(), 
      Term(Rational(5,3),5));
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(-5,2),0), Term(Rational(1,3),5), Term(Rational(7,6),4), Term(Rational(4,3),5), Term(Rational(1),1)}).lt(), 
      Term(Rational(5,3),5));

   // Case where terms sum to 0
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(5,3),5), Term(Rational(-5,3),5)}).lt(), 
      Term<Rational>());
}

//=============================================================================
TEST(polynomialCtrTest, NegativeExp) 
{  
   EXPECT_THROW(Polynomial<Integer>({Term(Integer(),-1)}), std::invalid_argument);
   EXPECT_THROW(Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(),-8)}), std::invalid_argument);
   EXPECT_THROW(Polynomial<GaussianInteger>({Term(GaussianInteger(),-3)}), std::invalid_argument);
   EXPECT_THROW(Polynomial<Rational>({Term(Rational(),-5)}), std::invalid_argument);
}
