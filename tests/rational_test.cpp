#include <gtest/gtest.h>
#include "../math/gmp_rational.h"

using Rational = CAS::GMPRational;

//=============================================================================
TEST(rationalTest, DefaultConstructor) 
{
   EXPECT_EQ(Rational(), Rational::zero());
}
