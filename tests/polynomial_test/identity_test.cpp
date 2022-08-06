#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;
using CAS::Polynomial;

using CAS::Integer;
using CAS::IntegerMod;
using CAS::GaussianInteger;
using CAS::Rational;

//=============================================================================
TEST(identityTest, zeroTest) 
{  
   EXPECT_TRUE(Term<Integer>().isZero());
   EXPECT_FALSE(Term<Integer>::unity().isZero());

   EXPECT_TRUE(Polynomial<IntegerMod<5>>().isZero());
   EXPECT_FALSE(Polynomial<IntegerMod<5>>::unity().isZero());
}

//=============================================================================
TEST(identityTest, unityTest) 
{  
   EXPECT_TRUE(Term<GaussianInteger>::unity().isUnity());
   EXPECT_FALSE(Term<GaussianInteger>::unity().isZero());

   EXPECT_TRUE(Term<Rational>::unity().isUnity());
   EXPECT_FALSE(Term<Rational>::unity().isZero());
}