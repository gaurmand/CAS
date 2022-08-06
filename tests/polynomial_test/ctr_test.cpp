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
   Polynomial<Integer> a;
   EXPECT_EQ(a.term(0), Term<Integer>());
   EXPECT_EQ(a.numTerms(), 1);

   Polynomial<IntegerMod<7>> b;
   EXPECT_EQ(b.term(0), Term<IntegerMod<7>>());
   EXPECT_EQ(b.numTerms(), 1);

   Polynomial<GaussianInteger> c;
   EXPECT_EQ(c.term(0), Term<GaussianInteger>());
   EXPECT_EQ(c.numTerms(), 1);

   Polynomial<Rational> d;
   EXPECT_EQ(d.term(0), Term<Rational>());
   EXPECT_EQ(d.numTerms(), 1);
}

//=============================================================================
TEST(polynomialCtrTest, ZeroVector) 
{  
   // Empty vector
   Polynomial<Integer> a{std::vector<Term<Integer>>()};
   EXPECT_EQ(a.term(0), Term<Integer>());
   EXPECT_EQ(a.numTerms(), 1);

   Polynomial<IntegerMod<7>> b = std::vector<Term<IntegerMod<7>>>();
   EXPECT_EQ(b.term(0), Term<IntegerMod<7>>());
   EXPECT_EQ(b.numTerms(), 1);

   Polynomial<Integer> e({});
   EXPECT_EQ(e.term(0), Term<Integer>());
   EXPECT_EQ(e.numTerms(), 1);

   // Zero-polynomial vector
   Polynomial<GaussianInteger> c(std::vector<Term<GaussianInteger>>{Term<GaussianInteger>()});
   EXPECT_EQ(c.term(0), Term<GaussianInteger>());
   EXPECT_EQ(c.numTerms(), 1);

   Polynomial<Rational> d = std::vector<Term<Rational>>{Term<Rational>()};
   EXPECT_EQ(d.term(0), Term<Rational>());
   EXPECT_EQ(d.numTerms(), 1);

   Polynomial<GaussianInteger> f = {Term<GaussianInteger>()};
   EXPECT_EQ(f.term(0), Term<GaussianInteger>());
   EXPECT_EQ(f.numTerms(), 1);
}

//=============================================================================
TEST(polynomialCtrTest, IntegerVector) 
{  
   Polynomial<Integer> a({Term(Integer(1),1), Term(Integer(2),2), Term(Integer(3),3)});
   EXPECT_EQ(a.term(0), Term(Integer(1),1));
   EXPECT_EQ(a.term(1), Term(Integer(2),2));
   EXPECT_EQ(a.term(2), Term(Integer(3),3));
   EXPECT_EQ(a.numTerms(), 3);

   // Sorting by exponent
   Polynomial<Integer> b({Term(Integer(3),3), Term(Integer(2),2), Term(Integer(1),1)});
   EXPECT_EQ(b.term(0), Term(Integer(1),1));
   EXPECT_EQ(b.term(1), Term(Integer(2),2));
   EXPECT_EQ(b.term(2), Term(Integer(3),3));
   EXPECT_EQ(b.numTerms(), 3);

   // Summing of terms
   Polynomial<Integer> c({Term(Integer(2),3), Term(Integer(1),3), Term(Integer(2),2), Term(Integer(1),1)});
   EXPECT_EQ(c.term(0), Term(Integer(1),1));
   EXPECT_EQ(c.term(1), Term(Integer(2),2));
   EXPECT_EQ(c.term(2), Term(Integer(3),3));
   EXPECT_EQ(c.numTerms(), 3);

   // Terms sum to 0
   Polynomial<Integer> d({Term<Integer>(3,3), Term<Integer>(-3,3)});
   EXPECT_EQ(d.term(0), Term<Integer>());
   EXPECT_EQ(d.numTerms(), 1);
}

//=============================================================================
TEST(polynomialCtrTest, IntegerModVector) 
{  
   Polynomial<IntegerMod<7>> a({Term(IntegerMod<7>(1),1), Term(IntegerMod<7>(2),2), Term(IntegerMod<7>(3),3)});
   EXPECT_EQ(a.term(0), Term(IntegerMod<7>(1),1));
   EXPECT_EQ(a.term(1), Term(IntegerMod<7>(2),2));
   EXPECT_EQ(a.term(2), Term(IntegerMod<7>(3),3));

   // Sorting by exponent
   Polynomial<IntegerMod<7>> b({Term(IntegerMod<7>(3),3), Term(IntegerMod<7>(2),2), Term(IntegerMod<7>(1),1)});
   EXPECT_EQ(b.term(0), Term(IntegerMod<7>(1),1));
   EXPECT_EQ(b.term(1), Term(IntegerMod<7>(2),2));
   EXPECT_EQ(b.term(2), Term(IntegerMod<7>(3),3));

   // Summing of terms
   Polynomial<IntegerMod<7>> c({Term(IntegerMod<7>(2),3), Term(IntegerMod<7>(1),3), Term(IntegerMod<7>(2),2), Term(IntegerMod<7>(1),1)});
   EXPECT_EQ(c.term(0), Term(IntegerMod<7>(1),1));
   EXPECT_EQ(c.term(1), Term(IntegerMod<7>(2),2));
   EXPECT_EQ(c.term(2), Term(IntegerMod<7>(3),3));

   // Terms sum to 0
   Polynomial<IntegerMod<7>> d({Term(IntegerMod<7>(7),1), Term(IntegerMod<7>(3),5), Term(IntegerMod<7>(4),5)});
   EXPECT_EQ(d.term(0), Term<IntegerMod<7>>());
   EXPECT_EQ(d.numTerms(), 1);
}

//=============================================================================
TEST(polynomialCtrTest, GaussianIntegerVector) 
{  
   Polynomial<GaussianInteger> a({Term(GaussianInteger(1,1),1), Term(GaussianInteger(2,2),2), Term(GaussianInteger(3,3),3)});
   EXPECT_EQ(a.term(0), Term(GaussianInteger(1,1),1));
   EXPECT_EQ(a.term(1), Term(GaussianInteger(2,2),2));
   EXPECT_EQ(a.term(2), Term(GaussianInteger(3,3),3));

   // Sorting by exponent
   Polynomial<GaussianInteger> b({Term(GaussianInteger(3,3),3), Term(GaussianInteger(2,2),2), Term(GaussianInteger(1,1),1)});
   EXPECT_EQ(b.term(0), Term(GaussianInteger(1,1),1));
   EXPECT_EQ(b.term(1), Term(GaussianInteger(2,2),2));
   EXPECT_EQ(b.term(2), Term(GaussianInteger(3,3),3));

   // Summing of terms
   Polynomial<GaussianInteger> c({Term(GaussianInteger(2,2),3), Term(GaussianInteger(1,1),3), Term(GaussianInteger(2,2),2), Term(GaussianInteger(1,1),1)});
   EXPECT_EQ(c.term(0), Term(GaussianInteger(1,1),1));
   EXPECT_EQ(c.term(1), Term(GaussianInteger(2,2),2));
   EXPECT_EQ(c.term(2), Term(GaussianInteger(3,3),3));

   // Terms sum to 0
   Polynomial<GaussianInteger> d({Term(GaussianInteger(3,-3),3), Term(GaussianInteger(-3,3),3)});
   EXPECT_EQ(d.term(0), Term<GaussianInteger>());
   EXPECT_EQ(d.numTerms(), 1);
}

//=============================================================================
TEST(polynomialCtrTest, RationalVector) 
{  
   Polynomial<Rational> a({Term(Rational(1,2),1), Term(Rational(2,3),2), Term(Rational(3,4),3)});
   EXPECT_EQ(a.term(0), Term(Rational(1,2),1));
   EXPECT_EQ(a.term(1), Term(Rational(2,3),2));
   EXPECT_EQ(a.term(2), Term(Rational(3,4),3));

   // Sorting by exponent
   Polynomial<Rational> b({Term(Rational(3,4),3), Term(Rational(2,3),2), Term(Rational(1,2),1)});
   EXPECT_EQ(b.term(0), Term(Rational(1,2),1));
   EXPECT_EQ(b.term(1), Term(Rational(2,3),2));
   EXPECT_EQ(b.term(2), Term(Rational(3,4),3));

   // Summing of terms
   Polynomial<Rational> c({Term(Rational(1,4),3), Term(Rational(2,4),3), Term(Rational(2,3),2), Term(Rational(1,2),1)});
   EXPECT_EQ(c.term(0), Term(Rational(1,2),1));
   EXPECT_EQ(c.term(1), Term(Rational(2,3),2));
   EXPECT_EQ(c.term(2), Term(Rational(3,4),3));

   // Terms sum to 0
   Polynomial<Rational> d({Term(Rational(5,3),3), Term(Rational(-5,3),3)});
   EXPECT_EQ(d.term(0), Term<Rational>());
   EXPECT_EQ(d.numTerms(), 1);
}

//=============================================================================
TEST(polynomialCtrTest, NegativeExp) 
{  
   EXPECT_THROW(Polynomial<Integer>({Term(Integer(),-1)}), std::invalid_argument);
   EXPECT_THROW(Polynomial<IntegerMod<7>>({Term(IntegerMod<7>(),-8)}), std::invalid_argument);
   EXPECT_THROW(Polynomial<GaussianInteger>({Term(GaussianInteger(),-3)}), std::invalid_argument);
   EXPECT_THROW(Polynomial<Rational>({Term(Rational(),-5)}), std::invalid_argument);
}
