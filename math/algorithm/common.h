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
template <typename R>
R gcd(const R a, const R b)
{
   R q, r;
   while(b != R::zero())
   {
      a.quorem(b, q, r);
      a = b;
      b = r;
   }
   return a;
}

} // namespace CAS

#endif
