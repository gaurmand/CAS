#ifndef CAS_INTEGER_MOD_H
#define CAS_INTEGER_MOD_H

#include "integer.h"

#include <compare>
#include <concepts>
#include <ostream>
#include <string_view>

namespace CAS
{

using Modulus = unsigned long long;

template <Modulus N = 1ull>
class IntegerMod
{
public:
   IntegerMod() = default;
   IntegerMod(std::integral auto val): int_(val % N) {}
   IntegerMod(const Integer& val): int_(val % N) {}
   explicit IntegerMod(std::string_view sv): int_(Integer(sv) % N) {}

   auto operator<=>(const IntegerMod&) const = default;

   IntegerMod& operator+=(const IntegerMod& rhs)
   {
      int_ += rhs.int_;
      int_ %= N;
      return *this;
   }

   IntegerMod& operator-=(const IntegerMod& rhs)
   {
      int_ -= rhs.int_;
      int_ %= N;
      return *this;
   }

   IntegerMod& operator*=(const IntegerMod& rhs)
   {
      int_ *= rhs.int_;
      int_ %= N;
      return *this;
   }

   // Integer& operator/=(const Integer&);
   // Integer& operator%=(const Integer&); 

   IntegerMod& operator-()
   {
      int_ = N - int_;
      return *this;
   }

   friend std::ostream& operator<<(std::ostream& os, const IntegerMod& rhs)
   {
      return os << rhs.int_ << " ( mod " << N << ")";
   }


   // static Integer zero() { return Integer(); }
   // static Integer unity() { return Integer(1); }

   // static QuoremResult quorem(const Integer&, const Integer&);

private:
   Integer int_;
};

template <Modulus N>
IntegerMod<N> operator+(const IntegerMod<N>& lhs, const IntegerMod<N>& rhs)
{
   IntegerMod<N> result(lhs);
   result += rhs;
   return result;
}

// Integer operator-(const Integer&, const Integer&);
// Integer operator*(const Integer&, const Integer&);
// Integer operator/(const Integer&, const Integer&);
// Integer operator%(const Integer&, const Integer&);

// struct QuoremResult
// {
//    Integer quo_;
//    Integer rem_;
// };

} // namespace CAS

#endif