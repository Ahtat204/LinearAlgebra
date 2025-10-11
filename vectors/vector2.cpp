//
// Created by lahcen on 18/07/2025.
//

#include "vectors/vector2.hpp"
#include<random>
#include <stdexcept>
#include<algorithm>
#include <Matrix/Mat2.hpp>
//
using namespace LinearAlgebra;
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
    return std::abs(this->getMagnitude() - 1) < std::numeric_limits<T>::epsilon();
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::normalize() const
{
    auto const magnitude = this->getMagnitude();
    return vector2(this->x/magnitude, this->y/magnitude);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::operator+(const vector2& other) const
{
    return vector2(this->x + other.x, this->y + other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::operator+=(const vector2& other) 
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::operator-(const vector2& other) const
{
    return vector2(this->x - other.x, this->y - other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::operator-=(const vector2& other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::operator*(T scalar) const
{
    return vector2(this->x*scalar, this->y*scalar);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::operator*=(T scalar)
{
    return vector2(this->x*scalar, this->y*scalar);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::cross(vector2<T>& other)
{
    return vector2(this->y * other.x, this->x * other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
auto vector2<T>::angleBetween(const vector2& other) const
{
    auto dotProduct = this->dot(other);
    T magnitude1 = this->getMagnitude();
    T magnitude2 = other.getMagnitude();
    if (magnitude1 == 0 || magnitude2 == 0) throw std::domain_error("Cannot compute angle with zero-length vector");
    T cosTheta = dotProduct / (magnitude1 * magnitude2);
    cosTheta = std::clamp(cosTheta, T(-1), T(1));
    return std::acos(cosTheta);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T> vector2<T>::operator*(const vector2& other) const
{
    return vector2(this->x * other.x, this->y * other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::operator*=(const vector2<T>& other)
{
    return vector2(this->x * other.x, this->y * other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>::operator vector2() const
{
    return vector2<T>(static_cast<T>(x), static_cast<T>(y));
}

template <typename T> requires std::is_arithmetic_v<T>
vector2<T>& vector2<T>::operator*(const Mat2<T>& other)
{
    return vector2(this->x * other.x, this->y * other.y);
}

template <typename T> requires std::is_arithmetic_v<T>
 vector2<T> vector2<T>::random(T min ,T max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(min, max);
        return {dist(gen), dist(gen)};
    } else {
        std::uniform_real_distribution<T> dist(min, max);
        return {dist(gen), dist(gen)};
    }
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
vector2<T> vector2<T>::rotate(T angle) const
{
    return Mat2<T>::rotation(angle)*this;
}

template <typename T> requires std::is_arithmetic_v<T>
constexpr auto vector2<T>::dot(const vector2<T>& other) const
{
    return this->x * other.x + this->y * other.y;
}

template <typename T> requires std::is_arithmetic_v<T>
 constexpr  auto  vector2<T>::euclidianDistance(const vector2& other) const
{
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}
