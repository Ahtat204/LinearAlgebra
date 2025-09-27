//
// Created by lahcen on 18/07/2025.
//

#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include <type_traits>

namespace LinearAlgebra
{
    /**
     * @brief A 2D vector class template for arithmetic types.
     *
     * This struct represents a 2-dimensional vector with arithmetic components.
     * It provides common vector operations such as addition, subtraction, 
     * scalar multiplication/division, normalization, dot product, and 
     * computing angles and distances.
     *
     * @tparam T Must be an arithmetic type (int, float, double, etc.)
     */
    template <typename T> requires std::is_arithmetic_v<T>
    struct vector2
    {
    private:
        T x; ///< The X-component of the vector
        T y; ///< The Y-component of the vector
    public:
        /**
         * @brief Constructs a vector with the given x and y components.
         * @param x The X-component
         * @param y The Y-component
         */
        explicit vector2(T x, T y);
        /**
         * @brief Default constructor. Leaves components uninitialized.
         */
        vector2() = default;
        /**
         * @brief Access vector components by index.
         * @param index Index of the component (0 for x, 1 for y)
         * @return The value of the requested component
         */
        T constexpr operator[](const int& index) const;
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
        [[nodiscard]] vector2 normalize() const;

        /**
         * @brief Adds two vectors.
         * @param other The vector to add
         * @return The result of the addition
         */
        vector2 operator+(const vector2& other) const;

        /**
         * @brief Adds another vector to this vector in place.
         * @param other The vector to add
         * @return Reference to this vector after addition
         */
        vector2& operator+=(const vector2& other);

        vector2 operator-(const vector2& other) const; ///< Vector subtraction
        vector2& operator-=(const vector2& other); ///< In-place subtraction
        vector2 operator*(T scalar) const; ///< Scalar multiplication
        vector2& operator*=(T scalar); ///< In-place scalar multiplication
        vector2 operator/(T scalar) const; ///< Scalar division
        vector2& operator/=(T scalar); ///< In-place scalar division
        vector2 cross(vector2& other); ///< Cross product (returns perpendicular vector)
        auto angleBetween(const vector2& other) const; ///< Angle between two vectors
        vector2 operator*(const vector2& other) const; ///< Component-wise multiplication
        vector2& operator*=(const vector2& other); ///< In-place component-wise multiplication
        explicit operator vector2() const;///<
        // Predefined static vectors for convenience
        static constinit vector2 identity = vector2(1, 1); ///< Vector with components (1,1)
        static constinit vector2 zero = vector2(0, 0); ///< Vector with components (0,0)
        static constinit vector2 up = vector2(0, 1); ///< Vector pointing up (0,1)
        static constinit vector2 down = vector2(0, -1); ///< Vector pointing down (0,-1)
        static constinit vector2 left = vector2(-1, 0); ///< Vector pointing left (-1,0)
        static constinit vector2 right = vector2(1, 0); ///< Vector pointing right (1,0)
        static vector2 random(T min ,T max); ///< Returns a random vector
        bool operator==(const vector2& other) const; ///< Equality comparison
        bool operator!=(const vector2& other) const; ///< Inequality comparison
        /**
         * @brief Computes the dot product of this vector with another.
         * @param other The vector to dot with
         * @return The dot product
         */
        constexpr auto dot(const vector2& other) const;
        /**
         * @brief Computes the Euclidean distance between this vector and another.
         * @param other The other vector
         * @return The Euclidean distance
         */
        constexpr auto euclidianDistance(const vector2& other) const;
    };
} 
using fvec2 = LinearAlgebra::vector2<float>;
using dvec2 = LinearAlgebra::vector2<double>;
using ivec2 = LinearAlgebra::vector2<int>;

#endif 
