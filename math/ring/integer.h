#ifndef CAS_INTEGER_H
#define CAS_INTEGER_H

#include <gmpxx.h>
#include <string>

namespace CAS
{

class GMPRational;

class Integer
{
public:
   //=============================================================================
   Integer() = default;

   //=============================================================================
   Integer(const signed char val): int_(val) {}
   Integer(const signed short val): int_(val) {}
   Integer(const signed int val): int_(val) {}
   Integer(const signed long val): int_(val) {}
   Integer(const unsigned char val): int_(val) {}
   Integer(const unsigned short val): int_(val) {}
   Integer(const unsigned int val): int_(val) {}
   Integer(const unsigned long val): int_(val) {}

   // Disable implicit conversions from mpz_class unsupported types
   Integer(const signed long long) = delete;
   Integer(const unsigned long long) = delete;

   // Disable narrowing implicit conversions
   Integer(const float) = delete;
   Integer(const double) = delete;
   Integer(const long double) = delete;

   //=============================================================================
   explicit Integer(const char* str, const int base = 0): int_(str, base) {}
   explicit Integer(const std::string& str, const int base = 0): int_(str, base) {}

   //=============================================================================
   Integer& operator+=(const Integer&);
   Integer operator+(const Integer& rhs) const { return Integer(*this) += rhs; }

   //=============================================================================
   Integer operator-() const { return Integer(-int_); }

   //=============================================================================
   Integer& operator-=(const Integer&);
   Integer operator-(const Integer& rhs) const { return Integer(*this) -= rhs; }

   //=============================================================================
   Integer& operator*=(const Integer&);
   Integer operator*(const Integer& rhs) const { return Integer(*this) *= rhs; }

   //=============================================================================
   // Euclidean division: n = q*d + r where 0 <= r < abs(d)
   // NOTE: Computing r is aka "reduction modulo n"
   Integer& operator%=(const Integer&);
   Integer operator%(const Integer& rhs) const { return Integer(*this) %= rhs; };
   Integer& operator/=(const Integer&);
   Integer operator/(const Integer& rhs) const { return Integer(*this) /= rhs; };
   
   // Compute q & r simultaneously for efficiency
   void quorem(const Integer&, Integer&, Integer&) const;

   //=============================================================================
   bool operator==(const Integer& rhs) const { return int_ == rhs.int_; };
   bool operator!=(const Integer& rhs) const { return !(*this == rhs); };

   //=============================================================================
   bool operator<=(const Integer& rhs) const { return int_ <= rhs.int_; };
   bool operator>=(const Integer& rhs) const { return int_ >= rhs.int_; };
   bool operator<(const Integer& rhs) const { return int_ < rhs.int_; };
   bool operator>(const Integer& rhs) const { return int_ > rhs.int_;  };

   //=============================================================================
   static Integer zero() { return 0; }
   bool isZero() const { return int_ == 0; }

   //=============================================================================
   static Integer unity() { return 1; }
   bool isUnity() const { return int_ == 1; }

   //=============================================================================
   void swap(Integer& o) { int_.swap(o.int_); };

   //=============================================================================
   friend std::ostream& operator<<(std::ostream&, const Integer&);
   friend class GMPRational;

private:
   //=============================================================================
   explicit Integer(const mpz_class& val): int_(val) {}

   //=============================================================================
   mpz_class int_ = 0_mpz;
};

} // namespace CAS

#endif
