#include "ring/integer.h"
#include "ring/concepts.h"

#include <gtest/gtest.h>

using namespace CAS;

TEST(ConceptsTest, IntegerConcept) 
{
   static_assert(Group<Integer>);
   static_assert(Ring<Integer>);
   static_assert(EuclideanDomain<Integer>);
   static_assert(!Field<Integer>);
}
