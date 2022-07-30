#include <gtest/gtest.h>
#include "../math/integer_mod.h"

using CAS::IntegerMod;

//=============================================================================
TEST(integerModTest, DefaultConstructor) 
{
   EXPECT_EQ(IntegerMod<3>(), IntegerMod<3>::zero());
   EXPECT_EQ(IntegerMod<10>(), IntegerMod<10>::zero());
}
