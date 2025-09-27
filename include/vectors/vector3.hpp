//
// Created by lahce on 14/08/2025.
//

#ifndef VECTOR3_HPP
#define VECTOR3_HPP
#include <type_traits>

namespace LinearAlgebra {

/**
 * @brief A 3D vector class template for arithmetic types.
 *
 * Represents a three-dimensional vector with arithmetic components.
 * Provides common vector operations including addition, subtraction,
 * scalar and component-wise multiplication, cross product, normalization,
 * dot product, and distance computation.
 *
 * @tparam T Must be an arithmetic type (int, float, double, etc.)
 */
template <typename T> requires std::is_arithmetic_v<T>
struct vector3
{
private:
    T x; ///< The X-component of the vector
    T y; ///< The Y-component of the vector
    T z; ///< The Z-component of the vector

public:
    /**
     * @brief Constructs a vector with given x, y, and z components.
     * @param x The X-component
     * @param y The Y-component
     * @param z The Z-component
     */
    explicit vector3(T x, T y, T z);

    /**
     * @brief Default constructor. Leaves components uninitialized.
     */
    vector3() = default;

    /**
     * @brief Constructs a vector with all components set to the same value.
     * @param x The value to set for all components
     */
    explicit vector3(const T& x);

    /**
     * @brief Access vector components by index.
     * @param i Index of the component (0 for x, 1 for y, 2 for z)
     * @return The value of the requested component
     */
    T constexpr operator[](int i) const;

    /**
     * @brief Computes the magnitude (length) of the vector.
     * @return Magnitude of the vector
     */
    [[nodiscard]] auto getMagnitude() const;

    /**
     * @brief Checks if the vector is normalized (magnitude == 1)
     * @return true if the vector is normalized
     */
    [[nodiscard]] bool isNormalized() const;

    /**
     * @brief Returns a normalized vector (unit length in the same direction)
     * @return Normalized vector
     */
    [[nodiscard]] vector3 normalize() const;
    // Vector arithmetic operators
    vector3 operator+(const vector3& other) const; ///< Vector addition
    vector3& operator+=(const vector3& other);    ///< In-place vector addition
    vector3 operator-(const vector3& other) const; ///< Vector subtraction
    vector3& operator-=(const vector3& other);    ///< In-place vector subtraction
    vector3& cross(vector3& other);               ///< Cross product (perpendicular vector)
    vector3 operator*(const vector3& other) const; ///< Component-wise multiplication
    vector3& operator*=(const vector3& other);     ///< In-place component-wise multiplication

    // Static vectors for convenience
    static constinit vector3 identity=vector3(1,1,1); ///< Vector with all components equal to 1
    static constinit vector3 zero=vector3(0,0,0);     ///< Vector with all components equal to 0
    static constinit vector3  up = vector3(0,0,1);
    static constinit vector3 down = vector3(0,0,-1);
    static constinit vector3  right =vector3(0,1,0);
    static constinit vector3 left = vector3(0,-1,0);
    static constinit vector3 forward = vector3(-1,0,0);
    static constinit vector3 backward = vector3(1,0,0);
    // Comparison operators
    bool operator==(const vector3& other) const; ///< Equality comparison
    bool operator!=(const vector3& other) const; ///< Inequality comparison

    /**
     * @brief Computes the dot product of this vector with another.
     * @param other The vector to dot with
     * @return The dot product
     */
    auto dot(const vector3& other) const;

    /**
     * @brief Computes the Euclidean distance between this vector and another.
     * @param other The other vector
     * @return The Euclidean distance
     */
    auto euclidianDistance(const vector3& other) const;
};

} // namespace LinearAlgebra::vector

// Aliases for common types
using fvec3 = LinearAlgebra::vector3<float>;
using dvec3 = LinearAlgebra::vector3<double>;
using ivec3 = LinearAlgebra::vector3<int>;

#endif // VECTOR3_HPP
