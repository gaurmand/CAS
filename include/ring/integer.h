#ifndef CAS_INTEGER_H
#define CAS_INTEGER_H

#include <boost/multiprecision/gmp.hpp>
#include <compare>
#include <concepts>
#include <ostream>
#include <string_view>

#include "quorem.h"

namespace CAS
{

class Integer
{
using InternalInt = boost::multiprecision::mpz_int;

public:
   Integer() = default;
   Integer(std::integral auto init): int_(init) {}
   explicit Integer(std::string_view sv): int_(sv.data()) {}

   std::strong_ordering operator<=>(const Integer&) const = default;

   Integer& operator+=(const Integer&); 
   Integer& operator-=(const Integer&); 
   Integer& operator*=(const Integer&);
   Integer& operator/=(const Integer&);
   Integer& operator%=(const Integer&); 
   Integer& negate();

   QuoremResult<Integer> quorem(const Integer&);

   friend std::ostream& operator<<(std::ostream&, const Integer&);

   static Integer zero() { return Integer(); }
   static Integer unity() { return Integer(1); }

private:
   InternalInt int_;
};

Integer operator-(const Integer&);
Integer operator+(const Integer&, const Integer&);
Integer operator-(const Integer&, const Integer&);
Integer operator*(const Integer&, const Integer&);
Integer operator/(const Integer&, const Integer&);
Integer operator%(const Integer&, const Integer&);

std::ostream& operator<<(std::ostream&, const Integer&);

} // namespace CAS

#endif