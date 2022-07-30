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
Integer Integer::quotient(const Integer& divisor) const
{
   if (divisor.isZero())
   {
      throw std::domain_error("Cannot divide Integer by 0");
   }

   // GMP does not define a function to get the quotient of a euclidean division, 
   // so we have to define one in terms of floor and ceil division.
   // Source: https://en.wikipedia.org/wiki/Modulo_operation#Variants_of_the_definition
   Integer q;
   if (divisor.int_ > 0)
   {
      mpz_fdiv_q
      (
         q.int_.get_mpz_t(), 
         int_.get_mpz_t(), 
         divisor.int_.get_mpz_t()
      );
   }
   else
   {
      mpz_cdiv_q
      (
         q.int_.get_mpz_t(), 
         int_.get_mpz_t(), 
         divisor.int_.get_mpz_t()
      );
   }

   return q;
}

//=============================================================================
Integer Integer::remainder(const Integer& divisor) const
{
   if (divisor.isZero())
   {
      throw std::domain_error("Cannot divide Integer by 0");
   }

   // GMP defines mpz_mod() to get the remainder of a euclidean division.
   Integer r;
   mpz_mod
   (
      r.int_.get_mpz_t(), 
      int_.get_mpz_t(), 
      divisor.int_.get_mpz_t()
   );

   return r;
}

//=============================================================================
void Integer::quorem(const Integer& divisor, Integer& quotient, Integer& remainder) const
{
   if (divisor.isZero())
   {
      throw std::domain_error("Cannot divide Integer by 0");
   }

   // Similarly to quotient(), so we have to define the function in terms of floor 
   // and ceil division.
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
