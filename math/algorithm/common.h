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

} // namespace CAS

#endif
