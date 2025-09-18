//
// Created by lahce on 14/08/2025.
//

#include "vectors/vector3.hpp"

using namespace LinearAlgebra ;
template <typename T> requires std::is_arithmetic_v<T>
  vector3<T>::vector3(const T x, const T y, const T z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>::vector3(const T& x)
{
  this->x = x;
  this->y = x;
  this->z = x;
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector3<T>::getMagnitude() const
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector3<T>::isNormalized() const
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::normalize() const
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::operator+(const vector3& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>& vector3<T>::operator+=(const vector3& other)
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::operator-(const vector3& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>& vector3<T>::operator-=(const vector3& other)
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>& vector3<T>::cross(vector3& other)
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::operator*(const vector3& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>& vector3<T>::operator*=(const vector3& other)
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::identity()
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::zero()
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector3<T>::operator==(const vector3& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector3<T>::operator!=(const vector3& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector3<T>::dot(const vector3& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector3<T>::euclidianDistance(const vector3& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
   constexpr T vector3<T>::operator[](int i) const
   {
     
   }
    