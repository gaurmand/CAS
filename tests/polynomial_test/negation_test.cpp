#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;
using CAS::Polynomial;

using CAS::Integer;
using CAS::IntegerMod;
using CAS::GaussianInteger;
using CAS::Rational;

//=============================================================================
TEST(negateTest, NegateTerm) 
{  
   EXPECT_EQ(-Term<Rational>(), Term<Rational>());
   EXPECT_EQ(-Term(Integer(1),1), Term(-Integer(1),1));
   EXPECT_EQ(-Term(GaussianInteger(1,1),3), Term(-GaussianInteger(1,1),3));
}

//=============================================================================
TEST(negateTest, NegatePolynomial) 
{  
   EXPECT_EQ(-Polynomial<Rational>(), Polynomial<Rational>());
   EXPECT_EQ(-Polynomial<Integer>({Term(Integer(1),1)}), Polynomial<Integer>({-Term(Integer(1),1)}));
   EXPECT_EQ(
      -Polynomial<Rational>({Term(Rational(1,8),0), Term(Rational(2,3),1), Term(Rational(-1,2),2)}),
      Polynomial<Rational>({-Term(Rational(1,8),0), -Term(Rational(2,3),1), -Term(Rational(-1,2),2)}));
}