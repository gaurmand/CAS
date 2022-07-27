/* 
Assumptions made about T
+ T is copyable
+ T provides the operators: +=, -=, *=, -(unary), ==
+ T provides a static zero() method
*/
template <typename T>
class Ring
{
public:
   //=============================================================================
   Ring() = default;
   Ring(const Ring&) = default;
   Ring(const T& elem): elem_(elem) {}
   Ring& operator=(const Ring&) = default;
   virtual ~Ring() = default;

   //=============================================================================
   // Addition 
   Ring operator+(const Ring& rhs) const;
   Ring& operator+=(const Ring& rhs);

   //=============================================================================
   // Negation (additive inverse of operand)
   Ring operator-() const;

   //=============================================================================
   // Subtraction (sum of LHS operand and negated RHS operand)
   Ring operator-(const Ring& rhs) const;
   Ring& operator-=(const Ring& rhs);

   //=============================================================================
   // Multiplication
   Ring operator*(const Ring& rhs) const;
   Ring& operator*=(const Ring& rhs);

   //=============================================================================
   // Equality
   bool operator==(const Ring& rhs) const { return elem_ == rhs.elem_; };
   bool operator!=(const Ring& rhs) const { return !(elem_ == rhs.elem); }

   //=============================================================================
   // Returns additive identity
   static Ring zero() { return T::zero(); }

   //=============================================================================
   // Returns true if equivalent to additive identity
   bool isZero() const { return elem_ == T::zero(); }

private:
   //=============================================================================
   T elem_ = T::zero();
};
