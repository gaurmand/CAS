#include "common.h"
#include "../ring.h"

namespace CAS
{

//=============================================================================
template <> Rational associate<Rational>(const Rational& r) 
{
   if (r == Rational::zero())
   {
      return r;
   }
   else
   {
      return Rational(1);
   }
}

} // namespace CAS
