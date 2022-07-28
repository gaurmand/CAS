#include <gmpxx.h>
#include <string>

class Integer
{
public:
   //=============================================================================
   Integer() = default;

   // Problem?: Allows implicit narrowing conversions from unsigned long, long long, 
   // unsigned long long, float, double, long double
   Integer(const long val): int_(val) {}
   
   //=============================================================================
   Integer& operator+=(const Integer&);
   Integer operator+(const Integer& rhs) const { return Integer(int_) += rhs; }

   //=============================================================================
   Integer operator-() const { return Integer(-int_); }

   //=============================================================================
   Integer& operator-=(const Integer&);
   Integer operator-(const Integer& rhs) const { return Integer(int_) -= rhs; }

   //=============================================================================
   Integer& operator*=(const Integer&);
   Integer operator*(const Integer& rhs) const { return Integer(int_) *= rhs; }

   //=============================================================================
   bool operator==(const Integer& rhs) const { return int_ == rhs.int_; };
   bool operator!=(const Integer& rhs) const { return !(int_ == rhs.int_); };

   //=============================================================================
   static Integer zero() { return 0; }
   bool isZero() const { return int_ == 0; }

   //=============================================================================
   static Integer unity() { return 1; }
   bool isUnity() const { return int_ == 1; }

private:
   //=============================================================================
   explicit Integer(const mpz_class& val): int_(val) {}

   //=============================================================================
   mpz_class int_ = 0_mpz;
};
