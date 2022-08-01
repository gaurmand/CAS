#ifndef CAS_POLYNOMIAL_H
#define CAS_POLYNOMIAL_H

#include "../ring/integer.h"
#include <vector>

namespace CAS
{

//=============================================================================
template <typename R>
class Term
{
public:
   //=============================================================================
   Term() = default;
   Term(const R& r, const Integer& e): coefficient_(r), exponent_(e) {}

   //=============================================================================
   R coefficient() const { return coefficient_; }

   //=============================================================================
   Integer exponent() const { return exponent_; }

   //=============================================================================
   bool operator==(const Term& rhs) const { return exponent_ == rhs.exponent_ && coefficient_ == rhs.coefficient_; };
   bool operator!=(const Term& rhs) const { return !(*this == rhs); };

private:
   //=============================================================================
   R coefficient_ = R::zero();
   Integer exponent_ = 0;
};

template<typename R> Term(R r, Integer e) -> Term<R>;

//=============================================================================
template <typename R>
class Polynomial
{
public:
   //=============================================================================
   Polynomial() = default;
   Polynomial(const std::vector<Term<R>>& terms) : terms_(terms) {}

   //=============================================================================
   // NOTE: We follow the convention that deg(0) = 0 for convenience.
   Integer degree() const { return terms_.back().exponent(); }

   //=============================================================================
   Term<R> lt() const { return terms_.back(); }

   //=============================================================================
   R lc() const { return terms_.back().coefficient(); }

private:
   //=============================================================================
   // Enforces the following invariants:
   // + Terms are ordered from smallest to largest exponent
   // + Each term has a unique exponent
   // + The zero polynomial is represented by the monomial 0*x^0
   void canonicalize();

   //=============================================================================
   std::vector<Term<R>> terms_ = std::vector<Term<R>>(1);
};


} // namespace CAS

#endif

