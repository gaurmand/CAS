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
   Polynomial& operator+=(const Term<R>& term)
   {
      // Adding zero or adding to zero
      if (term.isZero())
      {
         return *this;
      }
      if(isZero())
      {
         terms_[0] = term;
         return *this;
      }

      // No term with exponent => term.exponent -> append term
      if (term.exp() > degree())
      {
         terms_.push_back(term);
         return *this;
      }

      // Find first term with exponent => term.exponent
      const auto comp = [](const Term<R>& l, const Term<R>& r) { return l.exp() < r.exp(); };
      const auto res = std::lower_bound(terms_.begin(), terms_.end(), term, comp);
      assert(res != terms_.end());

      // Term with greater exponent found -> insert term
      if (res->exp() != term.exp())
      {
         terms_.insert(res, term);
      }
      // Term with same exponent found -> sum terms
      else
      {
         *res += term;
         if (res->coeff() == R::zero())
         {
            terms_.erase(res);
            ensureCanoncialZero();
         }
      }
      return *this;
   }
   Polynomial operator+(const Term<R>& rhs) { return Polynomial(*this) += rhs; }

   //=============================================================================
   Polynomial& operator+=(const Polynomial& rhs)
   {
      for (const auto& term: rhs.terms_)
      {
         *this += term;
      }
      return *this;
   }
   Polynomial operator+(const Polynomial& rhs) { return Polynomial(*this) += rhs; }

   //=============================================================================
   Polynomial operator-() 
   {
      Polynomial copy(*this);
      for (auto& term: copy.terms_)
      {
         term = -term;
      }
      return copy;
   }

   //=============================================================================
   static Polynomial zero() { return Polynomial(); }
   bool isZero() const { return numTerms() == 1 && lt().isZero(); }

   //=============================================================================
   static Polynomial unity() { return Polynomial({Term<R>::unity()}); }
   bool isUnity() const { return numTerms() == 1 && lt().isUnity(); }

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
   void ensureCanoncialZero();

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

   removeZeroTerms();
   ensureCanoncialZero();
}

//=============================================================================
template <typename R>
void Polynomial<R>::removeZeroTerms()
{
   const auto last = std::remove_if(
      terms_.begin(), 
      terms_.end(), 
      [](const Term<R>& t) { return t.coeff() == R::zero();}
   );
   terms_.erase(last, terms_.end());
}

//=============================================================================
template <typename R>
void Polynomial<R>::ensureCanoncialZero()
{
   if (terms_.size() == 0)
   {
      terms_.emplace_back();
      return;
   }
}

} // namespace CAS

#endif

