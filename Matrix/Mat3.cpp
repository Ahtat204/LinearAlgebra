//
// Created by lahce on 14/08/2025.
//

#include "Matrix/Mat3.hpp"

using namespace LinearAlgebra;

template <typename T> requires std::is_arithmetic_v<T>
    Mat3<T>::Mat3(T a, T b, T c, T d, T e, T f, T g, T h)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = c;
    this->f = f;
    this->g = g;
    this->h = h;
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T>::Mat3(T element)
{
    this->a = element;
    this->b = element;
    this->c = element;
    this->d = element;
    this->e = element;
    this->f = element;
    this->g = element;
    this->h = element;
}

template <typename T> requires std::is_arithmetic_v<T>
bool Mat3<T>::operator==(Mat3 const& other) const
{
    bool equal = this->a == other.a && this->b == other.b && this->c == other.c && this->d == other.d && this->e == other.e && this->f == other.f && this->g == other.g && this->h == other.h;
    return equal;
}

template <typename T> requires std::is_arithmetic_v<T>
bool Mat3<T>::operator!=(Mat3 const& other) const
{
    return !(*this == other);
}

template <typename T> requires std::is_arithmetic_v<T>
T Mat3<T>::operator[](int i, int j) const
{
    
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::operator*(Mat3 const& other) const
{
    
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::operator+(Mat3 const& other) const
{
    return new Mat3(this->a + other.a, this->b + other.b,this->c + other.c,this->d + other.d,this->e + other.e,this->f+other.f,this.g+other.g,this.h+other.h,this->i+other.i);
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::operator-(Mat3 const& other) const
{
    return new Mat3(this->a - other.a, this->b - other.b,this->c - other.c,this->d - other.d,this->e - other.e,this->f-other.f,this.g-other.g,this.h-other.h,this->i-other.i);
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::operator*(T const& other) const
{
    return new Mat3(this->a*other,this->b*other,this->c*other,this->d*other,this->e*other,this->f*other,this->g*other,this->h*other,this->i*other);
}

template <typename T> requires std::is_arithmetic_v<T>
auto Mat3<T>::determinant() const
{
    
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::inverse() const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::transpose() const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::rotation(T x, T y, T z)
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::translation(T x, T y, T z)
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::scale(T x, T y, T z)
{
}
