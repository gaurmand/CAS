#include <gtest/gtest.h>
#include "../math/integer.h"

//=======================================================================================
TEST(integerTest, DefaultConstructor) 
{
   Integer a;
   EXPECT_TRUE(a.isZero());
}
