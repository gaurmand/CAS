#include <gtest/gtest.h>
#include "../math/quadratic_integer.h"

//=============================================================================
TEST(quadraticIntegerTest, DefaultConstructor) 
{
   EXPECT_EQ(QuadraticInteger<2>(), QuadraticInteger<2>::zero());
}
