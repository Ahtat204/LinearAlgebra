//
// Created by lahcen on 18/07/2025.
//

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <type_traits>
#include <cmath>
#include <random>
#include <Matrix/Mat2.hpp>

namespace LinearAlgebra
{
    template <typename T> requires std::is_arithmetic_v<T>
    struct vector2
    {
        T x; ///< The X-component
        T y; ///< The Y-component

        // Constructors
        constexpr vector2() = default;
        constexpr explicit vector2(T x, T y) : x(x), y(y) {}

        // Access by index
        constexpr T operator[](const int& index) const {
            return (index == 0) ? x : y;
        }

        // Magnitude
        [[nodiscard]] auto getMagnitude() const {
            return std::sqrt(x * x + y * y);
        }

        [[nodiscard]] bool isNormalized() const {
            return std::abs(getMagnitude() - T(1)) < T(1e-6);
        }

        [[nodiscard]] vector2 normalize() const {
            auto mag = getMagnitude();
            return (mag == 0) ? vector2(0,0) : vector2(x/mag, y/mag);
        }

        // Arithmetic operators
        constexpr vector2 operator+(const vector2& other) const {
            return vector2(x + other.x, y + other.y);
        }

        constexpr vector2& operator+=(const vector2& other) {
            x += other.x; y += other.y; return *this;
        }

        constexpr vector2 operator-(const vector2& other) const {
            return vector2(x - other.x, y - other.y);
        }

        constexpr vector2& operator-=(const vector2& other) {
            x -= other.x; y -= other.y; return *this;
        }

        constexpr vector2 operator*(T scalar) const {
            return vector2(x * scalar, y * scalar);
        }

        constexpr vector2& operator*=(T scalar) {
            x *= scalar; y *= scalar; return *this;
        }

        constexpr vector2 operator/(T scalar) const {
            return vector2(x / scalar, y / scalar);
        }

        constexpr vector2& operator/=(T scalar) {
            x /= scalar; y /= scalar; return *this;
        }

        // Component-wise multiplication
        constexpr vector2 operator*(const vector2& other) const {
            return vector2(x * other.x, y * other.y);
        }

        constexpr vector2& operator*=(const vector2& other) {
            x *= other.x; y *= other.y; return *this;
        }

        // Dot product
        constexpr auto dot(const vector2& other) const {
            return x * other.x + y * other.y;
        }

        // Cross product (2D → scalar)
        constexpr auto cross(const vector2& other) const {
            return x * other.y - y * other.x;
        }

        // Angle between vectors
        auto angleBetween(const vector2& other) const {
            auto d = dot(other);
            auto mags = getMagnitude() * other.getMagnitude();
            return std::acos(d / mags);
        }

        // Rotation
        vector2 rotate(T angle) const {
            T cosA = std::cos(angle);
            T sinA = std::sin(angle);
            return vector2(x * cosA - y * sinA, x * sinA + y * cosA);
        }

        // Distance
        constexpr auto euclidianDistance(const vector2& other) const {
            return std::sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y));
        }

        // Equality
        constexpr bool operator==(const vector2& other) const {
            return x == other.x && y == other.y;
        }

        constexpr bool operator!=(const vector2& other) const {
            return !(*this == other);
        }

        // Matrix multiplication
        vector2& operator*(const Mat2<T>& other) {
            T newX = other(0,0)*x + other(0,1)*y;
            T newY = other(1,0)*x + other(1,1)*y;
            x = newX; y = newY;
            return *this;
        }

        // Static vectors
        static constinit vector2 identity;
        static constinit vector2 zero;
        static constinit vector2 up;
        static constinit vector2 down;
        static constinit vector2 left;
        static constinit vector2 right;

        // Random vector
        static vector2 random(T min ,T max) {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_real_distribution<T> dist(min, max);
            return vector2(dist(gen), dist(gen));
        }
    };
} // namespace LinearAlgebra

// Convenient aliases
using fvec2 = LinearAlgebra::vector2<float>;
using dvec2 = LinearAlgebra::vector2<double>;
using ivec2 = LinearAlgebra::vector2<int>;

#endif // VECTOR2_HPP
