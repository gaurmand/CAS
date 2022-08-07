#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;
using CAS::Polynomial;

using CAS::Integer;
using CAS::IntegerMod;
using CAS::GaussianInteger;
using CAS::Rational;

//=============================================================================
TEST(addTest, AddZeroTerm) 
{  
   EXPECT_EQ(
      Polynomial<Rational>() + Term<Rational>(), 
      Polynomial<Rational>());

   EXPECT_EQ(
      Polynomial<Integer>() + Term(Integer(1),1), 
      Polynomial<Integer>({Term(Integer(1),1)}));

   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),1)}) + Term<GaussianInteger>(), 
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),1)}));
}

//=============================================================================
TEST(addTest, AddTerm) 
{  
   // Append case
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),1)}) + Term(Rational(2,3),2), 
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(2,3),2)}));

   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,8),0), Term(Rational(-1,2),2)}) + Term(Rational(2,3),1), 
      Polynomial<Rational>({Term(Rational(1,8),0), Term(Rational(2,3),1), Term(Rational(-1,2),2)}));

   // Insert case
   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),1)}) + Term(GaussianInteger(2,1),0), 
      Polynomial<GaussianInteger>({Term(GaussianInteger(2,1),0), Term(GaussianInteger(1,1),1)}));

   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),0), Term(GaussianInteger(1,-1),2)}) + Term(GaussianInteger(2,1),1), 
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),0), Term(GaussianInteger(2,1),1), Term(GaussianInteger(1,-1),2)}));

   // Sum case
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(1,4),2)}) + Term(Rational(1,3),1), 
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(2,3),1), Term(Rational(1,4),2)}));

   // Case where terms sum to zero
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(-1,3),1), Term(Rational(1,4),2)}) + Term(Rational(1,3),1), 
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,4),2)}));

   // Case where terms sum to zero creating zero polynomial
   EXPECT_EQ(
      Polynomial<Integer>({Term(Integer(-1),1)}) + Term(Integer(1),1), 
      Polynomial<Integer>());
}

//=============================================================================
TEST(addTest, AddZeroPolynomial) 
{  
   EXPECT_EQ(
      Polynomial<Rational>() + Polynomial<Rational>(),
      Polynomial<Rational>());

   EXPECT_EQ(
      Polynomial<Rational>::unity() + Polynomial<Rational>(),
      Polynomial<Rational>::unity());

   EXPECT_EQ(
      Polynomial<Rational>() + Polynomial<Rational>::unity(),
      Polynomial<Rational>::unity());
}

//=============================================================================
TEST(addTest, AddPolynomial) 
{  
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),2)}) + 
      Polynomial<Rational>({Term(Rational(1),0), Term(Rational(2,3),1)}), 
      Polynomial<Rational>({Term(Rational(1),0), Term(Rational(2,3),1), Term(Rational(1,2),2)}));

   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(1,4),2)}) + 
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(1,4),2)}), 
      Polynomial<Rational>({Term(Rational(1),0), Term(Rational(2,3),1), Term(Rational(1,2),2)}));

   // Case where terms sum to zero
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(-1,4),2)}) + 
      Polynomial<Rational>({Term(Rational(-1,2),0), Term(Rational(1,3),1), Term(Rational(1,4),2)}), 
      Polynomial<Rational>({Term(Rational(2,3),1)}));

   // Case where terms sum to zero creating zero polynomial
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,3),1), Term(Rational(-1,4),2)}) + 
      Polynomial<Rational>({Term(Rational(-1,2),0), Term(Rational(-1,3),1), Term(Rational(1,4),2)}), 
      Polynomial<Rational>());
}
