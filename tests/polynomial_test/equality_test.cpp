#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;
using CAS::Polynomial;

using CAS::Integer;
using CAS::IntegerMod;
using CAS::GaussianInteger;
using CAS::Rational;

//=============================================================================
TEST(equalityTests, SingleCase) 
{  
   EXPECT_EQ(Polynomial<Integer>(), Polynomial<Integer>());
   EXPECT_NE(Polynomial<Integer>({Term(Integer(1),1)}), Polynomial<Integer>());

   EXPECT_EQ(
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),1)}),
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),1)}));
   EXPECT_NE(
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),1)}),
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),0)}));
   EXPECT_NE(
      Polynomial<GaussianInteger>({Term(GaussianInteger(1,1),1)}),
      Polynomial<GaussianInteger>({Term(GaussianInteger(-1,1),1)}));
}

//=============================================================================
TEST(equalityTests, MultCase) 
{  
   EXPECT_EQ(
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(1,2),2), Term(Rational(1,2),3)}), 
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(1,2),2), Term(Rational(1,2),3)}));

   EXPECT_NE(
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(1,2),2), Term(Rational(1,2),3)}), 
      Polynomial<Rational>({Term(Rational(1,2),0), Term(Rational(1,2),2), Term(Rational(1,2),3)}));

   EXPECT_NE(
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(1,2),2), Term(Rational(1,2),3)}), 
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(1,3),2), Term(Rational(1,2),3)}));

   EXPECT_NE(
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(1,2),2), Term(Rational(1,2),3)}), 
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(1,2),2)}));

   EXPECT_NE(
      Polynomial<Rational>({Term(Rational(1,2),1), Term(Rational(1,2),2), Term(Rational(1,2),3)}), 
      Polynomial<Rational>({Term(Rational(1,2),2), Term(Rational(1,2),3)}));
}
