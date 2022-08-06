#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;
using CAS::Polynomial;

using CAS::Integer;
using CAS::GaussianInteger;

//=============================================================================
TEST(getTermsTest, EmptyCase) 
{  
   Polynomial<Integer> a;
   EXPECT_EQ(a.lt(), Term(Integer(),0));
   EXPECT_EQ(a.lc(), Integer());
   EXPECT_EQ(a.degree(), 0);
}

//=============================================================================
TEST(getTermsTest, NormalCase) 
{  
   Polynomial<GaussianInteger> a = {Term(GaussianInteger(1),0), Term(GaussianInteger(2,-1),1), Term(GaussianInteger(4,4),2)};
   EXPECT_EQ(a.lt(), Term(GaussianInteger(4,4),2));
   EXPECT_EQ(a.lc(), GaussianInteger(4,4));
   EXPECT_EQ(a.degree(), 2);
}
