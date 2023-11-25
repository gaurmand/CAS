#include "ring/integer.h"

#include <cassert>

namespace CAS
{

Integer& Integer::operator+=(const Integer& rhs)
{
   int_ += rhs.int_;
   return *this;
}

Integer& Integer::operator-=(const Integer& rhs)
{
   int_ -= rhs.int_;
   return *this;
}

Integer& Integer::operator*=(const Integer& rhs)
{
   int_ *= rhs.int_;
   return *this;
}

// GMP does not define euclidean division afaik. Instead implement using floor & ceil division.
// See: https://en.wikipedia.org/wiki/Modulo#Variants_of_the_definition
Integer& Integer::operator/=(const Integer& divisor)
{
   assert(divisor != Integer::zero());

   if (divisor > Integer::zero() )
   {
      mpz_fdiv_q
      (
         int_.backend().data(), 
         int_.backend().data(), 
         divisor.int_.backend().data()
      );
   }
   else
   {
      mpz_cdiv_q
      (
         int_.backend().data(), 
         int_.backend().data(), 
         divisor.int_.backend().data()
      );
   }
   return *this;
}

Integer& Integer::operator%=(const Integer& divisor)
{
   assert(divisor != Integer::zero());

   mpz_mod
   (
      int_.backend().data(), 
      int_.backend().data(), 
      divisor.int_.backend().data()
   );
   return *this;
}

// Also implement using floor & ceil division.
QuoremResult<Integer> Integer::quorem(const Integer& divisor)
{
   assert(divisor != Integer::zero());

   QuoremResult result{*this, *this};

   if (divisor > Integer::zero() )
   {
      mpz_fdiv_qr
      (
         result.quo.int_.backend().data(), 
         result.rem.int_.backend().data(),
         int_.backend().data(), 
         divisor.int_.backend().data()
      );
   }
   else
   {
      mpz_cdiv_qr
      (
         result.quo.int_.backend().data(), 
         result.rem.int_.backend().data(),
         int_.backend().data(), 
         divisor.int_.backend().data()
      );
   }

   return result;
}

Integer& Integer::negate()
{
   int_ = -int_;
   return *this;
}

Integer operator-(const Integer& rhs)
{
   Integer result(rhs);
   result.negate();
   return result;
}

Integer operator+(const Integer& lhs, const Integer& rhs)
{
   Integer result(lhs);
   result += rhs;
   return result;
}

Integer operator-(const Integer& lhs, const Integer& rhs)
{
   Integer result(lhs);
   result -= rhs;
   return result;
}

Integer operator*(const Integer& lhs, const Integer& rhs)
{
   Integer result(lhs);
   result *= rhs;
   return result;
}

Integer operator/(const Integer& lhs, const Integer& rhs)
{
   Integer result(lhs);
   result /= rhs;
   return result;
}

Integer operator%(const Integer& lhs, const Integer& rhs)
{
   Integer result(lhs);
   result %= rhs;
   return result;
}

std::ostream& operator<<(std::ostream& os, const Integer& rhs)
{
   return os << rhs.int_;
}

} // namespace CAS
