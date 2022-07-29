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

//=============================================================================
std::ostream& operator<<(std::ostream& os, const Integer& i)
{
   return os << i.int_.get_str();
}
