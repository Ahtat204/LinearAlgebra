//
// Created by lahce on 14/08/2025.
//

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <type_traits>
#include <cmath>

namespace LinearAlgebra {

template <typename T> requires std::is_arithmetic_v<T>
struct vector3
{
    T x; ///< The X-component
    T y; ///< The Y-component
    T z; ///< The Z-component

    // Constructors
    constexpr vector3() = default;
    constexpr explicit vector3(T x, T y, T z) : x(x), y(y), z(z) {}
    constexpr explicit vector3(const T& val) : x(val), y(val), z(val) {}

    // Access by index
    constexpr T operator[](int i) const {
        switch(i) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: return T(); // fallback
        }
    }

    // Magnitude
    [[nodiscard]] auto getMagnitude() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    [[nodiscard]] bool isNormalized() const {
        return std::abs(getMagnitude() - T(1)) < T(1e-6);
    }

    [[nodiscard]] vector3 normalize() const {
        auto mag = getMagnitude();
        return (mag == 0) ? vector3(0,0,0) : vector3(x/mag, y/mag, z/mag);
    }

    // Arithmetic operators
    constexpr vector3 operator+(const vector3& other) const {
        return vector3(x + other.x, y + other.y, z + other.z);
    }

    constexpr vector3& operator+=(const vector3& other) {
        x += other.x; y += other.y; z += other.z; return *this;
    }

    constexpr vector3 operator-(const vector3& other) const {
        return vector3(x - other.x, y - other.y, z - other.z);
    }

    constexpr vector3& operator-=(const vector3& other) {
        x -= other.x; y -= other.y; z -= other.z; return *this;
    }

    // Scalar multiplication/division
    constexpr vector3 operator*(T scalar) const {
        return vector3(x * scalar, y * scalar, z * scalar);
    }

    constexpr vector3& operator*=(T scalar) {
        x *= scalar; y *= scalar; z *= scalar; return *this;
    }

    constexpr vector3 operator/(T scalar) const {
        return vector3(x / scalar, y / scalar, z / scalar);
    }

    constexpr vector3& operator/=(T scalar) {
        x /= scalar; y /= scalar; z /= scalar; return *this;
    }

    // Cross product
    constexpr vector3 cross(const vector3& other) const {
        return vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Component-wise multiplication
    constexpr vector3 operator*(const vector3& other) const {
        return vector3(x * other.x, y * other.y, z * other.z);
    }

    constexpr vector3& operator*=(const vector3& other) {
        x *= other.x; y *= other.y; z *= other.z; return *this;
    }

    // Dot product
    constexpr auto dot(const vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Euclidean distance
    auto euclidianDistance(const vector3& other) const {
        return std::sqrt((x - other.x)*(x - other.x) +
                         (y - other.y)*(y - other.y) +
                         (z - other.z)*(z - other.z));
    }

    // Equality
    constexpr bool operator==(const vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    constexpr bool operator!=(const vector3& other) const {
        return !(*this == other);
    }

    // Static vectors
    static constinit vector3 identity;
    static constinit vector3 zero;
    static constinit vector3 up;
    static constinit vector3 down;
    static constinit vector3 right;
    static constinit vector3 left;
    static constinit vector3 forward;
    static constinit vector3 backward;
};
}

#endif
