#include "integer.h"

namespace CAS
{

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
Integer& Integer::operator/=(const Integer& rhs)
{
   if (rhs.isZero())
   {
      throw std::domain_error("Division by 0 is undefined");
   }

   // GMP does not define a function to get the quotient of a euclidean division, 
   // so we have to define one in terms of floor and ceil division.
   // Source: https://en.wikipedia.org/wiki/Modulo_operation#Variants_of_the_definition
   if (rhs.int_ > 0)
   {
      mpz_fdiv_q
      (
         int_.get_mpz_t(), 
         int_.get_mpz_t(), 
         rhs.int_.get_mpz_t()
      );
   }
   else
   {
      mpz_cdiv_q
      (
         int_.get_mpz_t(), 
         int_.get_mpz_t(), 
         rhs.int_.get_mpz_t()
      );
   }

   return *this;
}

//=============================================================================
Integer& Integer::operator%=(const Integer& rhs)
{
   if (rhs.isZero())
   {
      throw std::domain_error("Division by 0 is undefined");
   }

   mpz_mod
   (
      int_.get_mpz_t(), 
      int_.get_mpz_t(), 
      rhs.int_.get_mpz_t()
   );
   return *this;
}

//=============================================================================
void Integer::quorem(const Integer& divisor, Integer& quotient, Integer& remainder) const
{
   if (divisor.isZero())
   {
      throw std::domain_error("Division by 0 is undefined");
   }

   // Similarly to division operator we have to define euclidean division in 
   // terms of floor and ceil division.
   if (divisor.int_ > 0)
   {
      mpz_fdiv_qr
      (
         quotient.int_.get_mpz_t(), 
         remainder.int_.get_mpz_t(), 
         int_.get_mpz_t(), 
         divisor.int_.get_mpz_t()
      );
   }
   else
   {
      mpz_cdiv_qr
      (
         quotient.int_.get_mpz_t(), 
         remainder.int_.get_mpz_t(), 
         int_.get_mpz_t(), 
         divisor.int_.get_mpz_t()
      );
   }
}

//=============================================================================
std::ostream& operator<<(std::ostream& os, const Integer& i)
{
   return os << i.int_.get_str();
}

} // namespace CAS
