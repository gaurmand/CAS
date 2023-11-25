#ifndef CAS_QUOREM_H
#define CAS_QUOREM_H

namespace CAS
{

template <typename T>
struct QuoremResult
{
   T quo;
   T rem;

   bool operator==(const QuoremResult&) const = default;
};

} // namespace CAS

#endif
