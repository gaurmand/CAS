#include "integer.h"

//=============================================================================
IntegerElement& IntegerElement::operator+=(const IntegerElement& rhs) 
{
   int_ += rhs.int_;
   return *this;
}

//=============================================================================
IntegerElement IntegerElement::operator-() const
{
   return IntegerElement(-int_);
}

//=============================================================================
IntegerElement& IntegerElement::operator-=(const IntegerElement& rhs) 
{
   int_ -= rhs.int_;
   return *this;
}

//=============================================================================
IntegerElement& IntegerElement::operator*=(const IntegerElement& rhs) 
{
   int_ *= rhs.int_;
   return *this;
}
