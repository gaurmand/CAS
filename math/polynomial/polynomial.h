#ifndef CAS_POLYNOMIAL_H
#define CAS_POLYNOMIAL_H

#include "term.h"
#include "../ring/integer.h"
#include <vector>
#include <algorithm>

namespace CAS
{

//=============================================================================
template <typename R>
class Polynomial
{
public:
   //=============================================================================
   Polynomial() = default;
   Polynomial(const std::vector<Term<R>>& terms) : terms_(terms) { canonicalize(); }
   Polynomial(std::initializer_list<Term<R>> terms) : terms_(terms) { canonicalize(); }

   //=============================================================================
   Term<R> term(size_t i) const { return terms_.at(i); }

   //=============================================================================
   size_t numTerms() const { return terms_.size(); }

   //=============================================================================
   Term<R> lt() const { return terms_.back(); }

   //=============================================================================
   R lc() const { return terms_.back().coeff(); }

   //=============================================================================
   // NOTE: We follow the convention that deg(0) = 0 for convenience.
   Integer degree() const { return terms_.back().exp(); }

   //=============================================================================
   bool operator==(const Polynomial& rhs) const { return terms_ == rhs.terms_; };
   bool operator!=(const Polynomial& rhs) const { return !(*this == rhs); };

   //=============================================================================
   friend std::ostream& operator<<(std::ostream& os, const Polynomial& p)
   {
      for (auto it = p.terms_.begin(); it != p.terms_.end(); it++)
      {
         os << *it;
         if (it + 1 != p.terms_.end()) 
         {
            os << " + ";
         }
      }
      return os; 
   }

private:
   //=============================================================================
   // Enforces the following invariants:
   // + Terms are ordered from smallest to largest exponent
   // + Each term has a nonzero coefficient (unless zero polynomial)
   // + Each term has a unique exponent
   // + Each term has an exponent >= 0
   // + The zero polynomial is represented by the monomial 0*x^0
   void canonicalize();
   void removeZeroTerms();

   //=============================================================================
   std::vector<Term<R>> terms_ = {Term<R>()};
};

//=============================================================================
template <typename R>
void Polynomial<R>::canonicalize()
{
   // Ensure all terms have exponents >= 0
   const bool hasNegativeExp = std::any_of(
      terms_.begin(), 
      terms_.end(), 
      [](const Term<R>& t) { return t.exp() < 0;}
   );

   if (hasNegativeExp)
   {
      throw std::invalid_argument("Polynomial cannot have a negative exponent");
   }

   // Sort terms from smallest to largest exponent
   std::sort(
      terms_.begin(), 
      terms_.end(), 
      [](const Term<R>& l, const Term<R>& r) { return l.exp() < r.exp();}
   );

   // Sum up terms with the same exponent
   // a) Sum all groups of terms with same exponent and store in 1st term in group
   for(auto i = terms_.begin(); i != terms_.end();)
   {
      auto j = i + 1;
      for (; j != terms_.end(); j++)
      {
         if (j->exp() == i->exp())
         {
            *i += *j;
         }
         else
         {
            break;
         }
      }
      i = j;
   }

   // b) Remove extra terms
   const auto last = std::unique(
      terms_.begin(), 
      terms_.end(), 
      [](const Term<R>& l, const Term<R>& r) { return l.exp() == r.exp();}
   );
   terms_.erase(last, terms_.end());

   // Remove terms with 0 coefficients
   removeZeroTerms();
}

//=============================================================================
template <typename R>
void Polynomial<R>::removeZeroTerms()
{
   // Remove 0 terms
   const auto last = std::remove_if(
      terms_.begin(), 
      terms_.end(), 
      [](const Term<R>& t) { return t.coeff() == R::zero();}
   );
   terms_.erase(last, terms_.end());

   // Ensure the zero polynomial is represented by the monomial 0*x^0
   if (terms_.size() == 0)
   {
      terms_.emplace_back();
      return;
   }
}

} // namespace CAS

#endif

