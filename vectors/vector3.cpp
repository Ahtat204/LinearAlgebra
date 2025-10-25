//
// Created by lahce on 14/08/2025.
//

#include "vectors/vector3.hpp"

#include <valarray>

#include "vectors/vector2.hpp"

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
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector3<T>::isNormalized() const
{
    return (this->getMagnitude() == 1 ? true : false);
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::normalize() const
{
    auto magnitude = this->getMagnitude();
    return vector3(this->x / magnitude, this->y / magnitude, this->z / magnitude);
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::operator+(const vector3& other) const
{
    return vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>& vector3<T>::operator+=(const vector3& other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::operator-(const vector3& other) const
{
    return vector3(this->x - other.x,this->y-other.y,this->z-other.z);
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>& vector3<T>::operator-=(const vector3& other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>& vector3<T>::cross(vector3& other)
{
    return vector3(this->y * other.z - this->z * other.y,this->x*other.z-this->z*other.x,this->x*other.y - this->y*other.x);
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T> vector3<T>::operator*(const vector3& other) const
{
    return vector2(this->x * other.x,this->y * other.y,this->z * other.z);
}

template <typename T> requires std::is_arithmetic_v<T>
vector3<T>& vector3<T>::operator*=(const vector3& other)
{
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    return *this;
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector3<T>::operator==(const vector3& other) const
{
    return this->x == other.x && this->y == other.y && this->z == other.z;
}

template <typename T> requires std::is_arithmetic_v<T>
bool vector3<T>::operator!=(const vector3& other) const
{
    return this->x != other.x || this->y != other.y || this->z != other.z;
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector3<T>::dot(const vector3& other) const
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector3<T>::euclidianDistance(const vector3& other) const
{
    return std::sqrt(pow(this->x-other.x)+pow(this->y-other.y)+pow(this->z-other.z,2));
}

template <typename T> requires std::is_arithmetic_v<T>
constexpr T vector3<T>::operator[](const int i) const
{
    switch (i)
    {
        case 0: return this->x;
        case 1: return this->y;
        case 2: return this->z;
    default: return nullptr;
    }
}
