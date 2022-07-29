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
Integer Integer::quotient(const Integer& rhs) const
{
   if (rhs.isZero())
   {
      throw std::domain_error("Cannot divide Integer by 0");
   }

   return Integer(int_ / rhs.int_);
}

//=============================================================================
Integer Integer::remainder(const Integer& divisor) const
{
   if (divisor.isZero())
   {
      throw std::domain_error("Cannot divide Integer by 0");
   }

   return Integer(int_ % divisor.int_);
}

//=============================================================================
void Integer::quorem(const Integer& divisor, Integer& quotient, Integer& remainder) const
{
   if (divisor.isZero())
   {
      throw std::domain_error("Cannot divide Integer by 0");
   }

   mpz_tdiv_qr(
      quotient.int_.get_mpz_t(), 
      remainder.int_.get_mpz_t(), 
      int_.get_mpz_t(), 
      divisor.int_.get_mpz_t()
   );
}

//=============================================================================
std::ostream& operator<<(std::ostream& os, const Integer& i)
{
   return os << i.int_.get_str();
}
