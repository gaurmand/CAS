#ifndef CAS_TERM_H
#define CAS_TERM_H

namespace CAS
{

//=============================================================================
template <typename R>
class Term
{
public:
   //=============================================================================
   Term() = default;
   Term(const R& r, const Integer& e = 0): coeff_(r), exp_(e) {}

   //=============================================================================
   R coeff() const { return coeff_; }

   //=============================================================================
   Integer exp() const { return exp_; }

   //=============================================================================
   Term& operator+=(const Term& rhs) 
   { 
      if (exp_ != rhs.exp_)
      {
         throw std::invalid_argument("Cannot add terms with different exponents");
      }
      coeff_ += rhs.coeff_; 
      return *this;
   }
   Term operator+(const Term& rhs) { return Term(*this) += rhs; }

   //=============================================================================
   bool operator==(const Term& rhs) const { return exp_ == rhs.exp_ && coeff_ == rhs.coeff_; };
   bool operator!=(const Term& rhs) const { return !(*this == rhs); };

   //=============================================================================
   static Term zero() { return Term(); }
   bool isZero() const { return coeff_ == R::zero() && exp_ == 0; }

   //=============================================================================
   static Term unity() { return R::unity(); }
   bool isUnity() const { return coeff_ == R::unity() && exp_ == 0; }

   //=============================================================================
   friend std::ostream& operator<<(std::ostream& os, const Term& t)
   {
      return os << t.coeff_ << "x^" << t.exp_;
   }

private:
   //=============================================================================
   R coeff_ = R::zero();
   Integer exp_ = 0;
};

} // namespace CAS

#endif