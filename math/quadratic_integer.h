#ifndef CAS_QUAD_INTEGER_H
#define CAS_QUAD_INTEGER_H

#include "integer.h"

namespace CAS
{

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
   QuadraticInteger& operator+=(const QuadraticInteger& rhs)
   {
      a_ += rhs.a_;
      b_ += rhs.b_;
      return *this;
   }
   QuadraticInteger operator+(const QuadraticInteger& rhs) const { return QuadraticInteger(*this) += rhs;}

   //=============================================================================
   QuadraticInteger operator-() const { return QuadraticInteger(-a_, -b_); }

   //=============================================================================
   QuadraticInteger& operator-=(const QuadraticInteger& rhs)
   {
      a_ -= rhs.a_;
      b_ -= rhs.b_;
      return *this;
   }
   QuadraticInteger operator-(const QuadraticInteger& rhs) const { return QuadraticInteger(*this) -= rhs;}

   //=============================================================================
   QuadraticInteger& operator*=(const QuadraticInteger& rhs)
   {
      const Integer t = a_;
      a_ *= rhs.a_;
      a_ += b_ * rhs.b_ * N;
      b_ *= rhs.a_;
      b_ += t * rhs.b_;
      return *this;
   }
   QuadraticInteger operator*(const QuadraticInteger& rhs) const { return QuadraticInteger(*this) *= rhs;}

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
   QuadraticInteger conjugate() const { return QuadraticInteger(a_, -b_); }

   //=============================================================================
   bool isInteger() const { return b_ == 0; }
   Integer toInteger() const
   {
      if (!isInteger())
      {
         throw std::runtime_error("Cannot convert QuadraticInteger to Integer");
      }
      
      return a_;
   }

   //=============================================================================
   Integer a() const { return a_; }
   Integer b() const { return b_; }

private:
   //=============================================================================
   Integer a_ = 0;
   Integer b_ = 0;
};

template <long N> 
std::ostream& operator<<(std::ostream& os, const QuadraticInteger<N> qint)
{
   return os << qint.a() << " + " << qint.b() << "*sqrt(" << N << ")";
}

template class QuadraticInteger<-1>;
using GaussianInteger = QuadraticInteger<-1>;

} // namespace CAS

#endif
