//
// Created by lahcen on 18/07/2025.
//

#include "vectors/vector2.hpp"
//
using namespace LinearAlgebra::vector;
template<typename T> requires std::is_arithmetic_v<T>
vector2<T>::vector2(T x, T  y )
{
    this->x = x;
    this->y = y;
}

template <typename T> requires std::is_arithmetic_v<T>
T constexpr vector2<T>::operator[](const int& index) const
{
    return index == 0 ? this->x : this->y;
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector2<T>::getMagnitude() const
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

template <typename T> requires std::is_arithmetic_v<T>
 bool vector2<T>::isNormalized() const
{
    return this->getMagnitude()==1?true:false;
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::normalize() const
{
    auto const magnitude = this->getMagnitude();
    return vector2<T>(this->x/magnitude, this->y/magnitude);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::operator+(const vector2& other) const
{
    return vector2(this->x + other.x, this->y + other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::operator+=(const vector2& other) 
{
    return vector2(this->x + other.x, this->y + other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::operator-(const vector2& other) const
{
    return vector2(this->x - other.x, this->y - other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::operator-=(const vector2& other)
{
    return vector2(this->x - other.x, this->y - other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::cross(vector2<T>& other)
{
    return vector::vector2(this->y * other.x, this->x * other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::operator*(const vector2& other) const
{
    return vector2(this->x * other.x, this->y * other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::operator*=(const vector2<T>& other)
{
    return vector::vector2(this->x * other.x, this->y * other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector2<T>::operator==(const vector2<T>& other) const
{ return this->x == other.x && this->y == other.y; }


template <typename T> requires std::is_arithmetic_v<T>
bool vector2<T>::operator!=(const vector2<T>& other) const
{
    return this->x != other.x || this->y != other.y;
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector2<T>::dot(const vector2<T>& other) const
{
    return this->x * other.x + this->y * other.y;
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector2<T>::euclidianDistance(const vector2& other) const
{
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}
