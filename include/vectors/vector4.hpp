
#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include <type_traits>
#include <cmath>

#if defined(__cplusplus) && __cplusplus >= 201703L
#define __NODISCARD__ [[nodiscard]]
#else
#define __NODISCARD__
#endif
namespace LinearAlgebra {

template <typename T> requires std::is_arithmetic_v<T>
struct vector4
{
    T x; ///< The X-component
    T y; ///< The Y-component
    T z; ///< The Z-component
    T w; ///< The W-component

    // Constructors
    constexpr vector4() = default;
    constexpr explicit vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
    constexpr explicit vector4(const T& val) : x(val), y(val), z(val), w(val) {}

    // Access by index
    constexpr T operator[](int i) const {
        switch(i) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            case 3: return w;
            default: return T(); // fallback
        }
    }
    __NODISCARD__ auto getMagnitude() const {
        return std::sqrt(x*x + y*y + z*z + w*w);
    }

    __NODISCARD__ bool isNormalized() const {
        return std::abs(getMagnitude() - T(1)) < T(1e-6);
    }
    __NODISCARD__ vector4 normalize() const {
        auto mag = getMagnitude();
        return (mag == 0) ? vector4(0,0,0,0) : vector4(x/mag, y/mag, z/mag, w/mag);
    }
    constexpr vector4 operator+(const vector4& other) const {
        return vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }
    constexpr vector4& operator+=(const vector4& other) {
        x += other.x; y += other.y; z += other.z; w += other.w; return *this;
    }
    constexpr vector4 operator-(const vector4& other) const {
        return vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }
    constexpr vector4& operator-=(const vector4& other) {
        x -= other.x; y -= other.y; z -= other.z; w -= other.w; return *this;
    }
    constexpr vector4 operator*(T scalar) const {
        return vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }
    constexpr vector4& operator*=(T scalar) {
        x *= scalar; y *= scalar; z *= scalar; w *= scalar; return *this;
    }
    constexpr vector4 operator/(T scalar) const {
        return vector4(x / scalar, y / scalar, z / scalar, w / scalar);
    }
    constexpr vector4& operator/=(T scalar) {
        x /= scalar; y /= scalar; z /= scalar; w /= scalar; return *this;
    }
    constexpr vector4 operator*(const vector4& other) const {
        return vector4(x * other.x, y * other.y, z * other.z, w * other.w);
    }

    constexpr vector4& operator*=(const vector4& other) {
        x *= other.x; y *= other.y; z *= other.z; w *= other.w; return *this;
    }
    constexpr auto dot(const vector4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }
    auto euclidianDistance(const vector4& other) const {
        return std::sqrt((x - other.x)*(x - other.x) +
                         (y - other.y)*(y - other.y) +
                         (z - other.z)*(z - other.z) +
                         (w - other.w)*(w - other.w));
    }
    constexpr bool operator==(const vector4& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    constexpr bool operator!=(const vector4& other) const {
        return !(*this == other);
    }
};

}
#endif
