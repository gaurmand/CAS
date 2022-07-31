#ifndef CAS_RATIONAL_H
#define CAS_RATIONAL_H

#include <gmpxx.h>
#include "integer.h"

namespace CAS
{

class CASRational
{
public:
   //=============================================================================
   CASRational() = default;
   CASRational(const Integer& num): num_(num) {}
   CASRational(const Integer& num, const Integer& denom);

   //=============================================================================
   CASRational& operator+=(const CASRational&);
   CASRational operator+(const CASRational& rhs) const { return CASRational(*this) += rhs;}

   //=============================================================================
   CASRational operator-() const { return CASRational(-num_, denom_); }

   //=============================================================================
   CASRational& operator-=(const CASRational&);
   CASRational operator-(const CASRational& rhs) const { return CASRational(*this) -= rhs;}

   //=============================================================================
   CASRational& operator*=(const CASRational&);
   CASRational operator*(const CASRational& rhs) const { return CASRational(*this) *= rhs;}

   //=============================================================================
   bool operator==(const CASRational& rhs) const { return num_ == rhs.num_ && denom_ == rhs.denom_; };
   bool operator!=(const CASRational& rhs) const { return !(*this == rhs); };

   //=============================================================================
   bool operator<=(const CASRational&) const;
   bool operator>=(const CASRational&) const;
   bool operator<(const CASRational& rhs) const { return !(*this >= rhs); };
   bool operator>(const CASRational& rhs) const { return !(*this <= rhs);  };

   //=============================================================================
   static CASRational zero() { return CASRational(0); }
   bool isZero() const { return num_ == 0; }

   //=============================================================================
   static CASRational unity() { return CASRational(1); }
   bool isUnity() const { return num_ == 1 && denom_ == 1; }

   //=============================================================================
   bool isInteger() const { return denom_ == 1; }
   Integer toInteger() const;

   //=============================================================================
   friend std::ostream& operator<<(std::ostream&, const CASRational&);

private:
   //=============================================================================
   // Enforces the following invariants:
   // 1) num and denom are coprime
   // 2) denom is positive
   // 3) If num is 0, then denom is 1 (i.e. 0 is always represented as 0/1)
   void canonicalize();

   //=============================================================================
   Integer num_ = 0;
   Integer denom_ = 1;
};

using Rational = CASRational;

} // namespace CAS

#endif
