#ifndef CAS_GMP_RATIONAL_H
#define CAS_GMP_RATIONAL_H

#include <gmpxx.h>
#include "integer.h"

namespace CAS
{

class GMPRational
{
public:
   //=============================================================================
   GMPRational() = default;
   GMPRational(const long num): rat_(num, 1) {}
   GMPRational(const Integer& num): rat_(num.int_, 1) {}
   GMPRational(const Integer& num, const Integer& denom);

   //=============================================================================
   GMPRational& operator+=(const GMPRational&);
   GMPRational operator+(const GMPRational& rhs) const { return GMPRational(*this) += rhs;}

   //=============================================================================
   GMPRational operator-() const { return GMPRational(-rat_); }

   //=============================================================================
   GMPRational& operator-=(const GMPRational&);
   GMPRational operator-(const GMPRational& rhs) const { return GMPRational(*this) -= rhs;}

   //=============================================================================
   GMPRational& operator*=(const GMPRational&);
   GMPRational operator*(const GMPRational& rhs) const { return GMPRational(*this) *= rhs;}

   //=============================================================================
   GMPRational& invert();
   GMPRational inverse() const { return GMPRational(*this).invert(); }

   //=============================================================================
   GMPRational& operator%=(const GMPRational&);
   GMPRational operator%(const GMPRational& rhs) const { return GMPRational(*this) %= rhs; };
   GMPRational& operator/=(const GMPRational&);
   GMPRational operator/(const GMPRational& rhs) const { return GMPRational(*this) /= rhs; };
   
   //=============================================================================
   bool operator==(const GMPRational& rhs) const { return rat_ == rhs.rat_; };
   bool operator!=(const GMPRational& rhs) const { return !(*this == rhs); };

   //=============================================================================
   bool operator<=(const GMPRational& rhs) const { return rat_ <= rhs.rat_; };
   bool operator>=(const GMPRational& rhs) const { return rat_ >= rhs.rat_; };
   bool operator<(const GMPRational& rhs) const { return rat_ < rhs.rat_; };
   bool operator>(const GMPRational& rhs) const { return rat_ > rhs.rat_;  };

   //=============================================================================
   static GMPRational zero() { return GMPRational(0); }
   bool isZero() const { return rat_ == 0; }

   //=============================================================================
   static GMPRational unity() { return GMPRational(1); }
   bool isUnity() const { return rat_ == 1; }

   //=============================================================================
   bool isInteger() const { return rat_.get_den() == 1; }
   Integer toInteger() const;

   //=============================================================================
   friend std::ostream& operator<<(std::ostream&, const GMPRational&);

private:
   //=============================================================================
   explicit GMPRational(const mpq_class& val): rat_(val) {}

   //=============================================================================
   mpq_class rat_ = 0;
};

} // namespace CAS

#endif
