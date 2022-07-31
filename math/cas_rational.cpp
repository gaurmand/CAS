#include "cas_rational.h"
#include <iostream>

namespace CAS
{

//=============================================================================
CASRational::CASRational(const Integer& num, const Integer& denom): num_(num), denom_(denom)
{
   if (denom.isZero())
   {
      throw std::domain_error("Rational cannot have denominator of 0");
   }
   canonicalize();
}

//=============================================================================
CASRational& CASRational::operator+=(const CASRational& rhs)
{
   num_ *= rhs.denom_;
   num_ += denom_*rhs.num_;
   denom_ *= rhs.denom_;
   canonicalize();
   return *this;
}

//=============================================================================
CASRational& CASRational::operator-=(const CASRational& rhs)
{
   num_ *= rhs.denom_;
   num_ -= denom_*rhs.num_;
   denom_ *= rhs.denom_;
   canonicalize();
   return *this;
}

//=============================================================================
CASRational& CASRational::operator*=(const CASRational& rhs)
{
   num_ *= rhs.num_;
   denom_ *= rhs.denom_;
   canonicalize();
   return *this;
}

//=============================================================================
bool CASRational::operator<=(const CASRational& rhs) const
{
   return (num_*rhs.denom_) <= (denom_*rhs.num_);
}

//=============================================================================
bool CASRational::operator>=(const CASRational& rhs) const
{
   return (num_*rhs.denom_) >= (denom_*rhs.num_);
}

//=============================================================================
std::ostream& operator<<(std::ostream& os, const CASRational& r)
{
   return os << r.num_ << "/" << r.denom_;
}

//=============================================================================
Integer CASRational::toInteger() const
{
   if (!isInteger())
   {
      throw std::runtime_error("Cannot convert GMPRational to Integer");
   }

   return Integer(num_);
}

//=============================================================================
void CASRational::canonicalize()
{
   // Ensure 0 is always represented by 0/1
   if (num_ == 0)
   {
      denom_ = 1;
      return;
   }

   // Ensure denom is positive
   if (denom_ < 0)
   {
      denom_ = -denom_;
      num_ = -num_;
   }
   
   // Ensure num and denom are coprime (i.e. do not share any common factors)
   if (denom_ != 1)
   {
      const Integer g = num_.gcd(denom_);
      num_ /= g;
      denom_ /= g;
   }
}

} // namespace CAS
