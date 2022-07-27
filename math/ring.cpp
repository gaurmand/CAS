#include "ring.h"

//=============================================================================
template <typename T>
Ring<T> Ring<T>::operator+(const Ring<T>& rhs) const
{
   return T(elem_) += rhs.elem_;
}

//=============================================================================
template <typename T>
Ring<T>& Ring<T>::operator+=(const Ring<T>& rhs)
{
   elem_ += rhs.elem_;
   return *this;
}

//=============================================================================
template <typename T>
Ring<T> Ring<T>::operator-() const
{
   return -elem_;
}

//=============================================================================
template <typename T>
Ring<T> Ring<T>::operator-(const Ring<T> & rhs) const
{
   return T(elem_) -= rhs;
}

//=============================================================================
template <typename T>
Ring<T>& Ring<T>::operator-=(const Ring<T>& rhs)
{
   elem_ -= rhs;
   return *this;
}

//=============================================================================
template <typename T>
Ring<T> Ring<T>::operator*(const Ring<T>& rhs) const
{
   return T(elem_) *= rhs;
}

//=============================================================================
template <typename T>
Ring<T>& Ring<T>::operator*=(const Ring<T>& rhs)
{
   elem_ *= rhs;
   return *this;
}
