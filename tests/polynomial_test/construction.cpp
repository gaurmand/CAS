#include <gtest/gtest.h>
#include "../../math/ring.h"

using CAS::Term;
using CAS::Polynomial;
using CAS::Integer;

//=============================================================================
TEST(polynomialTest, DefaultConstructor) 
{  
   EXPECT_EQ(Polynomial<Integer>().lt(), Term<Integer>(0,0));
   EXPECT_EQ(Polynomial<Integer>().lc(), 0);
   EXPECT_EQ(Polynomial<Integer>().degree(), 0);
}
