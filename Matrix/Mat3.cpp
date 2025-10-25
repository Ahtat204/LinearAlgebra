//
// Created by lahce on 14/08/2025.
//

#include "Matrix/Mat3.hpp"

using namespace LinearAlgebra;

template <typename T> requires std::is_arithmetic_v<T>
    Mat3<T>::Mat3(T a, T b, T c, T d, T e, T f, T g, T h)
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T>::Mat3(T element)
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool Mat3<T>::operator==(Mat3<T> const& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool Mat3<T>::operator!=(Mat3<T> const& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
T Mat3<T>::operator()(int i, int j) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
T Mat3<T>::operator[](int i, int j) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::operator*(Mat3<T> const& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::operator+(Mat3<T> const& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::operator-(Mat3<T> const& other) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat3<T> Mat3<T>::operator*(T const& other) const
{
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
