//
// Created by lahce on 03/12/2025.
//

#include "vectors/vector4.hpp"
using namespace LinearAlgebra;

template <typename T> requires std::is_arithmetic_v<T>
vector4<T>::vector4(T x, T y, T z, T w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
    
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T>::vector4(const T& x)
{
    this->x = x;
    this->y = x;
    this->z = x;
    this->w = x;
    
}

template <typename T> requires std::is_arithmetic_v<T>
constexpr T vector4<T>::operator[](int i) const
{
    switch (i)
    {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;
        default: return 0;
    }
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector4<T>::getMagnitude() const
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector4<T>::isNormalized() const
{
    return (this->getMagnitude() == 1?true:false);
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T> vector4<T>::normalize() const
{
    auto magnitude = getMagnitude();
    if (magnitude == 0) return vector4<T>();
    return *this / magnitude;
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T> vector4<T>::operator+(const vector4& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T>& vector4<T>::operator+=(const vector4& other)
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T> vector4<T>::operator-(const vector4& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T>& vector4<T>::operator-=(const vector4& other)
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T>& vector4<T>::cross(vector4& other)
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T> vector4<T>::operator*(const vector4& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
vector4<T>& vector4<T>::operator*=(const vector4& other)
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector4<T>::operator==(const vector4& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector4<T>::operator!=(const vector4& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector4<T>::dot(const vector4& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector4<T>::euclidianDistance(const vector4& other) const
{
} // LinearAlgerba