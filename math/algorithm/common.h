#ifndef CAS_COMMON_ALG_H
#define CAS_COMMON_ALG_H

#include <gmpxx.h>

namespace CAS
{

//=============================================================================
template <typename R>
inline R abs(const R& r)
{
   return r < R::zero() ? -r : r;
}

//=============================================================================
// From the set of all associates (unit multiples) returns the canonical
// representative.
//  + e.g. Returns positive associate for integer or rational
//  + e.g. Returns associate w/ positive lc for Z[x] polynomials
//  + e.g. Returns monic associate for F[x] polynomials
template <typename R>
R associate(const R& r)
{
   return abs(r);
}

//=============================================================================
// Euclidean algorithm:
// + Assumes R is a euclidean domain with a euclidean norm
// + % performs euclidean division: i.e. a % b returns r such that a = b*q + r 
// with r = 0 or norm(r) < norm(b)
template <typename R>
R gcd(const R& r1, const R& r2)
{
   R a = associate(r1);
   R b = associate(r2);
   if (a == R::zero())
   {
      return b;
   }
   if (b == R::zero())
   {
      return a;
   }

   R q, r;
   while(b != R::zero())
   {
      r = a % b;
      a = b;
      b = r;
   }
   return a;
}

} // namespace CAS

#endif
