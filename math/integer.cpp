#include "integer.h"

//=============================================================================
Integer& Integer::operator+=(const Integer& rhs) 
{
   int_ += rhs.int_;
   return *this;
}

//=============================================================================
Integer& Integer::operator-=(const Integer& rhs) 
{
   int_ -= rhs.int_;
   return *this;
}

//=============================================================================
Integer& Integer::operator*=(const Integer& rhs) 
{
   int_ *= rhs.int_;
   return *this;
}
