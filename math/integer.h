#include "ring.h"
#include <gmpxx.h>

// Private class intended only for use with Ring<T>
class IntegerElement
{
public:
   //=============================================================================
   IntegerElement() = default;
   IntegerElement(const IntegerElement&) = default;
   IntegerElement(const long val): int_(val) {}
   IntegerElement(const mpz_class& mpz_val): int_(mpz_val) {}

   //=============================================================================
   IntegerElement& operator+=(const IntegerElement&);

   //=============================================================================
   IntegerElement operator-() const;

   //=============================================================================
   IntegerElement& operator-=(const IntegerElement&);

   //=============================================================================
   IntegerElement& operator*=(const IntegerElement&);

   //=============================================================================
   bool operator==(const IntegerElement& rhs) const { return int_ == rhs.int_; };

   //=============================================================================
   static IntegerElement zero() { return 0; }

   //=============================================================================
   static IntegerElement unity() { return 1; }

private:
   //=============================================================================
   mpz_class int_ = 0_mpz;
};

using Integer = Ring<IntegerElement>;
