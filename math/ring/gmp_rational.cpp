#include "gmp_rational.h"

namespace CAS
{
//=============================================================================
GMPRational::GMPRational(const Integer& num, const Integer& denom): rat_(num.int_, denom.int_) 
{
   if (denom.isZero())
   {
      throw std::domain_error("Rational cannot have denominator of 0");
   }
   rat_.canonicalize();
}

//=============================================================================
GMPRational& GMPRational::operator+=(const GMPRational& rhs)
{
   rat_ += rhs.rat_;
   return *this;
}

//=============================================================================
GMPRational& GMPRational::operator-=(const GMPRational& rhs)
{
   rat_ -= rhs.rat_;
   return *this;
}

//=============================================================================
GMPRational& GMPRational::operator*=(const GMPRational& rhs)
{
   rat_ *= rhs.rat_;
   return *this;
}

//=============================================================================
GMPRational& GMPRational::invert()
{
   if (isZero())
   {
      throw std::domain_error("The inverse of 0 is undefined");
   }
   
   mpq_inv(rat_.get_mpq_t(), rat_.get_mpq_t());
   return *this;
}

//=============================================================================
GMPRational& GMPRational::operator%=(const GMPRational& rhs)
{
   if (rhs.isZero())
   {
      throw std::domain_error("The inverse of 0 is undefined");
   }

   rat_ = 0;
   return *this;
}

//=============================================================================
GMPRational& GMPRational::operator/=(const GMPRational& rhs)
{
   if (rhs.isZero())
   {
      throw std::domain_error("The inverse of 0 is undefined");
   }

   rat_ /= rhs.rat_;
   return *this;
}

//=============================================================================
std::ostream& operator<<(std::ostream& os, const GMPRational& r)
{
   return os << r.rat_.get_str();
}

//=============================================================================
Integer GMPRational::toInteger() const
{
   if (!isInteger())
   {
      throw std::runtime_error("Cannot convert GMPRational to Integer");
   }

   return Integer(rat_.get_num());
}

} // namespace CAS
