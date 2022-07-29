#ifndef CAS_QUAD_INTEGER_H
#define CAS_QUAD_INTEGER_H

#include "integer.h"

// Represents numbers of the form: a + b*sqrt(N)
// NOTE: Technically this defines a quadratic extension of the integers, not a
// ring of quadratic integers (they are similar concepts with key differences 
// I do not really understand)
template <long N> 
class QuadraticInteger
{
public:
   //=============================================================================
   QuadraticInteger() = default;
   QuadraticInteger(const Integer& a, const Integer& b = 0): a_(a), b_(b) {}

   //=============================================================================
   QuadraticInteger& operator+=(const QuadraticInteger&);
   QuadraticInteger operator+(const QuadraticInteger& rhs) { return QuadraticInteger(*this) += rhs;}

   //=============================================================================
   QuadraticInteger operator-() { return QuadraticInteger(-a_, -b_); }

   //=============================================================================
   QuadraticInteger& operator-=(const QuadraticInteger&);
   QuadraticInteger operator-(const QuadraticInteger& rhs) { return QuadraticInteger(*this) -= rhs;}

   //=============================================================================
   QuadraticInteger& operator*=(const QuadraticInteger&);
   QuadraticInteger operator*(const QuadraticInteger& rhs) { return QuadraticInteger(*this) *= rhs;}

   //=============================================================================
   bool operator==(const QuadraticInteger& rhs) const { return a_ == rhs.a_ && b_ == rhs.b_; };
   bool operator!=(const QuadraticInteger& rhs) const { return !(*this == rhs); };

   //=============================================================================
   static QuadraticInteger zero() { return QuadraticInteger(0, 0); }
   bool isZero() const { return a_ == 0 && b_ == 0; }

   //=============================================================================
   static QuadraticInteger unity() { return QuadraticInteger(1, 0); }
   bool isUnity() const { return a_ == 1 && b_ == 0; }

   //=============================================================================
   QuadraticInteger conjugate() { return QuadraticInteger(a_, -b_); }

   //=============================================================================
   QuadraticInteger isInteger() const { return b_ == 0; }
   Integer toInteger() const;

   //=============================================================================
   Integer a() { return a_; }
   Integer b() { return b_; }

private:
   //=============================================================================
   Integer a_ = 0;
   Integer b_ = 0;
};

using GaussianInteger = QuadraticInteger<-1>;
using Root2Integer = QuadraticInteger<2>;

#endif
