#include "integer.h"

namespace CAS
{

// Assumes N > 0
template <unsigned long N> 
class IntegerMod
{
public:
   //=============================================================================
   IntegerMod() = default;
   IntegerMod(const Integer& val): int_(val % N) {}

   //=============================================================================
   IntegerMod& operator+=(const IntegerMod& rhs)
   {
      int_ += rhs.int_;
      int_ %= N;
      return *this;
   }
   IntegerMod operator+(const IntegerMod& rhs) const { return IntegerMod(*this) += rhs;}
   
   //=============================================================================
   IntegerMod operator-() const 
   { 
      return Integer(N) - int_; 
   }

   //=============================================================================
   IntegerMod& operator-=(const IntegerMod& rhs)
   {
      int_ -= rhs.int_;
      int_ %= N;
      return *this;
   }
   IntegerMod operator-(const IntegerMod& rhs) const { return IntegerMod(*this) -= rhs;}

   //=============================================================================
   IntegerMod& operator*=(const IntegerMod& rhs)
   {
      int_ *= rhs.int_;
      int_ %= N;
      return *this;
   }
   IntegerMod operator*(const IntegerMod& rhs) const { return IntegerMod(*this) *= rhs;}

   //=============================================================================
   bool operator==(const IntegerMod& rhs) const { return int_ == rhs.int_; };
   bool operator!=(const IntegerMod& rhs) const { return !(*this == rhs); };

   //=============================================================================
   static IntegerMod zero() { return IntegerMod(); }
   bool isZero() const { return int_ == 0; }

   //=============================================================================
   static IntegerMod unity() { return IntegerMod(2); }
   bool isUnity() const { return int_ == 1; }

   //=============================================================================
   friend std::ostream& operator<<(std::ostream& os, const IntegerMod& rhs)
   {
      return os << rhs.int_ << " (mod " << N << ")";
   }

private:
   //=============================================================================
   Integer int_ = 0;
};

} // namespace CAS
