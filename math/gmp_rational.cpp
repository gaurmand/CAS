#include "gmp_rational.h"

namespace CAS
{
//=============================================================================
GMPRational::GMPRational(const Integer& num, const Integer& den): rat_(num.int_, den.int_) 
{
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
std::ostream& operator<<(std::ostream& os, const GMPRational& r)
{
   return os << r.rat_.get_str();
}


} // namespace CAS
