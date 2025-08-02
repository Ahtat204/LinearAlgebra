//
// Created by lahce on 25/07/2025.
//

#include "Mat2.hpp"
 using namespace Matrix;
template <typename T> requires std::is_arithmetic_v<T>
    Mat2<T>::Mat2(T a, T b, T c, T d)
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T>::Mat2(T a)
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool Mat2<T>::operator==(const Mat2&) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
bool Mat2<T>::operator!=(const Mat2&) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::operator+(const Mat2&) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::operator-(const Mat2&) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::operator*(const Mat2&) const
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::operator*(auto& scalar)
{
}

template <typename T> requires std::is_arithmetic_v<T>
T Mat2<T>::operator[](const std::pair<int, int>& index)
{
}

template <typename T> requires std::is_arithmetic_v<T>
auto Mat2<T>::determinant()
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::transpose()
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::inverse()
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::identity()
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::zero()
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::ones()
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::rotation(T angle)
{
}




