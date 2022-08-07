#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;
using CAS::Polynomial;

using CAS::Integer;
using CAS::IntegerMod;
using CAS::GaussianInteger;
using CAS::Rational;

//=============================================================================
TEST(multiplicationTest, MultZeroTerm) 
{  
   EXPECT_EQ(
      Polynomial<Rational>() * Term<Rational>(), 
      Polynomial<Rational>());

   EXPECT_EQ(
      Polynomial<Integer>() * Term(Integer(1),1), 
      Polynomial<Integer>());

   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),1)}) * Term<GaussianInteger>(), 
      Polynomial<GaussianInteger>());
}

//=============================================================================
TEST(multiplicationTest, MultTerm) 
{  
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),1)}) * Term(Rational(2,3),2), 
      Polynomial<Rational>({Term(Rational(1,3),3)}));

   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,8),0), Term(GaussianInteger(-1,2),2)}) * Term(GaussianInteger(2,3),1), 
      Polynomial<GaussianInteger>({Term(GaussianInteger(-22,19),1), Term(GaussianInteger(-8,1),3)}));

   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(1,4),2)}) * Term(Rational(1,3),1), 
      Polynomial<Rational>({Term(Rational(1,6),1), Term(Rational(1,9),2), Term(Rational(1,12),3)}));

   // Case where terms multiply to zero
   EXPECT_EQ(
      Polynomial<IntegerMod<8>>({Term(IntegerMod<8>(2),0), Term(IntegerMod<8>(7),1)}) * Term(IntegerMod<8>(4),1), 
      Polynomial<IntegerMod<8>>({Term(IntegerMod<8>(4),2)}));

   // Case where terms multiply to zero creating zero polynomial
   EXPECT_EQ(
      Polynomial<IntegerMod<10>>({Term(IntegerMod<10>(2),0)}) * Term(IntegerMod<10>(5),0), 
      Polynomial<IntegerMod<10>>());
}

//=============================================================================
TEST(multiplicationTest, MultZeroPolynomial) 
{  
   EXPECT_EQ(
      Polynomial<Integer>() * Polynomial<Integer>(),
      Polynomial<Integer>());

   EXPECT_EQ(
      Polynomial<Rational>::unity() * Polynomial<Rational>(),
      Polynomial<Rational>());

   EXPECT_EQ(
      Polynomial<GaussianInteger>() * Polynomial<GaussianInteger>::unity(),
      Polynomial<GaussianInteger>());
}

//=============================================================================
TEST(multiplicationTest, MultPolynomial) 
{  
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),2)}) * 
      Polynomial<Rational>({Term(Rational(1),0), Term(Rational(2,3),1)}), 
      Polynomial<Rational>({Term(Rational(1,2),2), Term(Rational(1,3),3)}));

   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(1,4),2)}) * 
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(1,4),2)}), 
      Polynomial<Rational>({Term(Rational(1,4),0), Term(Rational(1,3),1), Term(Rational(13,36),2), Term(Rational(1,6),3), Term(Rational(1,16),4)}));

   // Case where terms sum to zero
   EXPECT_EQ(
      Polynomial<IntegerMod<8>>({Term(IntegerMod<8>(2),0), Term(IntegerMod<8>(7),1)}) *  Polynomial<IntegerMod<8>>({Term(IntegerMod<8>(4),1)}), 
      Polynomial<IntegerMod<8>>({Term(IntegerMod<8>(4),2)}));

   // Case where terms sum to zero creating zero polynomial
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(-1,4),2)}) + 
      Polynomial<Rational>({Term(Rational(-1,2),0), Term(Rational(-1,3),1), Term(Rational(1,4),2)}), 
      Polynomial<Rational>());
}
