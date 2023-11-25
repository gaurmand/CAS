#include "ring/integermod.h"

#include <gtest/gtest.h>
#include <string>

using CAS::IntegerMod;

TEST(integerTest, BasicConstruction) 
{
   EXPECT_EQ(IntegerMod(), IntegerMod<1>(0));
}
