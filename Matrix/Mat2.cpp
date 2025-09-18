//
// Created by lahce on 25/07/2025.
//

#include "Matrix/Mat2.hpp"

#include <stdexcept>
using namespace LinearAlgebra;
template <typename T> requires std::is_arithmetic_v<T>
    Mat2<T>::Mat2(T a, T b, T c, T d)
{
    this->a=a;
    this->b=b;
    this->c=c;
    this->d=d;
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T>::Mat2(T a)
{
    this->a=a;
    this->b=a;
    this->c=a;
    this->d=a;
}

template <typename T> requires std::is_arithmetic_v<T>
bool Mat2<T>::operator==(const Mat2& other) const
{
    return this->a==other.a && this->b==other.b && this->c==other.c && this->d==other.d;
}

template <typename T> requires std::is_arithmetic_v<T>
bool Mat2<T>::operator!=(const Mat2& other) const
{
    return this->a!=other.a || this->b!=other.b || this->c!=other.c || this->d!=other.d;
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::operator+(const Mat2& other) const
{
    return Mat2(this->a+other.a, this->b+other.b, this->c+other.c, this->d+other.d);
        
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::operator-(const Mat2& other) const
{
    return Mat2(this->a-other.a, this->b-other.b,this->c-other.c,this->d-other.d);
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::operator*(const Mat2& other) const
{
    return Mat2(this->a*other.a+this->b, this->a*other.b+this->b*other.d,this->a*other.c+this->d*other.c,this->b*other.c+this->d*other.d);
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::operator*(auto& scalar)
{
    return Mat2(scalar*this->a, scalar*this->b, scalar*this->c, scalar*this->d);
}

template <typename T> requires std::is_arithmetic_v<T>
T Mat2<T>::operator[](const std::pair<int, int>& index)
{
    return mat[index.first][index.second];
}

template <typename T> requires std::is_arithmetic_v<T>
auto Mat2<T>::determinant()
{
    return this->a*this->d - this->b*this->c;
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::transpose()
{
    return Mat2(this->a,this->c,this->b,this->d);
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::inverse()
{
    auto det = this->determinant();
    if (det == 0) throw std::invalid_argument("Mat2: determinant is 0");
    auto coMatrice=Mat2(this->d,this->c,this->b,this->a);
    auto tcoMatrice=coMatrice.transpose();
    return (1/det)*tcoMatrice;
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::identity()
{
    return Mat2(1,0,0,1);
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::zero()
{
    return Mat2(0,0,0,0);
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::ones()
{
    return Mat2(1,1,1,1);
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::rotation(T angle)
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::scaling(T x, T y)
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::translate(T x, T y)
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::rotate(T angle)
{
}

template <typename T> requires std::is_arithmetic_v<T>
Mat2<T> Mat2<T>::projection(T x, T y, T width, T height)
{
}




