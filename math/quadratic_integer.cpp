#include "quadratic_integer.h"

//=============================================================================
template <long N> 
QuadraticInteger<N>& QuadraticInteger<N>::operator+=(const QuadraticInteger<N>& rhs)
{
   a_ += rhs.a_;
   b_ += rhs.b_;
   return *this;
}

//=============================================================================
template <long N> 
QuadraticInteger<N>& QuadraticInteger<N>::operator-=(const QuadraticInteger<N>& rhs)
{
   a_ -= rhs.a_;
   b_ -= rhs.b_;
   return *this;
}

//=============================================================================
template <long N> 
QuadraticInteger<N>& QuadraticInteger<N>::operator*=(const QuadraticInteger<N>& rhs)
{
   a_ *= rhs.a_;
   a_ += b_ * rhs.b_ * N;
   b_ *= rhs.b_;
   b_ += b_ * rhs.a_;
   return *this;
}
