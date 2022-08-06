#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;

using CAS::Integer;
using CAS::IntegerMod;
using CAS::GaussianInteger;
using CAS::Rational;

//=============================================================================
TEST(termTest, DefaultCtr) 
{  
   EXPECT_EQ(Term<Integer>(), Term(Integer(),0));
   EXPECT_EQ(Term<IntegerMod<7>>(), Term(IntegerMod<7>(),0));
   EXPECT_EQ(Term<GaussianInteger>(), Term(GaussianInteger(),0));
   EXPECT_EQ(Term<Rational>(), Term(Rational(),0));
}

//=============================================================================
TEST(termTest, NormalCtr) 
{  
   Term a(Integer(1), 1);
   EXPECT_EQ(a.coeff(), Integer(1));
   EXPECT_EQ(a.exp(), 1);

   Term b(IntegerMod<7>(1), 5);
   EXPECT_EQ(b.coeff(), IntegerMod<7>(1));
   EXPECT_EQ(b.exp(), 5);

   Term c(GaussianInteger(1,1));
   EXPECT_EQ(c.coeff(), GaussianInteger(1,1));
   EXPECT_EQ(c.exp(), 0);

   Term d(Rational(1,2), 2);
   EXPECT_EQ(d.coeff(), Rational(1,2));
   EXPECT_EQ(d.exp(), 2);
}

//=============================================================================
TEST(termTest, AdditionTest) 
{  
   EXPECT_EQ(Term(Integer(1),1) + Term(Integer(1),1), Term(Integer(2),1));
   EXPECT_EQ(Term(IntegerMod<7>(6),2) + Term(IntegerMod<7>(4),2), Term(IntegerMod<7>(3),2));
   EXPECT_EQ(Term(GaussianInteger(1,1),3) + Term(GaussianInteger(2,2),3), Term(GaussianInteger(3,3),3));
   EXPECT_EQ(Term(Rational(1,2),4) + Term(Rational(2,2),4), Term(Rational(3,2),4));

   EXPECT_THROW(Term(Integer(1),1) + Term(Integer(1),2), std::invalid_argument);
   EXPECT_THROW(Term(IntegerMod<7>(6),6) + Term(IntegerMod<7>(4),2), std::invalid_argument);
   EXPECT_THROW(Term(GaussianInteger(1,1),4) + Term(GaussianInteger(2,2),3), std::invalid_argument);
   EXPECT_THROW(Term(Rational(1,2),5) + Term(Rational(2,2),1), std::invalid_argument);
}
