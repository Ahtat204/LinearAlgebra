#ifndef MAT2_HPP
#define MAT2_HPP

#include <type_traits>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <iostream>

namespace LinearAlgebra {

template<typename T>
    requires std::is_arithmetic_v<T>
struct Mat2 {
    T mat[2][2]{};

    // ===== Constructors =====
    constexpr Mat2(T a, T b, T c, T d) : mat{{a, b}, {c, d}} {}
    explicit constexpr Mat2(T val) : mat{{val, val}, {val, val}} {}
    constexpr Mat2() = default;

    // ===== Comparison =====
    constexpr bool operator==(const Mat2& other) const {
        return mat[0][0] == other.mat[0][0] &&
               mat[0][1] == other.mat[0][1] &&
               mat[1][0] == other.mat[1][0] &&
               mat[1][1] == other.mat[1][1];
    }

    constexpr bool operator!=(const Mat2& other) const {
        return !(*this == other);
    }

    // ===== Arithmetic =====
    constexpr Mat2 operator+(const Mat2& other) const {
        return {mat[0][0] + other.mat[0][0], mat[0][1] + other.mat[0][1],
                mat[1][0] + other.mat[1][0], mat[1][1] + other.mat[1][1]};
    }

    constexpr Mat2 operator-(const Mat2& other) const {
        return {mat[0][0] - other.mat[0][0], mat[0][1] - other.mat[0][1],
                mat[1][0] - other.mat[1][0], mat[1][1] - other.mat[1][1]};
    }

    constexpr Mat2 operator*(const Mat2& other) const {
        return {
            mat[0][0] * other.mat[0][0] + mat[0][1] * other.mat[1][0],
            mat[0][0] * other.mat[0][1] + mat[0][1] * other.mat[1][1],
            mat[1][0] * other.mat[0][0] + mat[1][1] * other.mat[1][0],
            mat[1][0] * other.mat[0][1] + mat[1][1] * other.mat[1][1]
        };
    }

    constexpr Mat2 operator*(T scalar) const {
        return {mat[0][0] * scalar, mat[0][1] * scalar,
                mat[1][0] * scalar, mat[1][1] * scalar};
    }

    // ===== Element Access =====
    constexpr T& operator[](const std::pair<size_t, size_t>& index) {
        if (index.first >= 2 || index.second >= 2)
            throw std::out_of_range("Mat2 index out of range");
        return mat[index.first][index.second];
    }

    constexpr const T& operator[](const std::pair<size_t, size_t>& index) const {
        if (index.first >= 2 || index.second >= 2)
            throw std::out_of_range("Mat2 index out of range");
        return mat[index.first][index.second];
    }

    // ===== Math =====
    constexpr T determinant() const {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    constexpr Mat2 transpose() const {
        return {mat[0][0], mat[1][0],
                mat[0][1], mat[1][1]};
    }

    constexpr Mat2 inverse() const {
        T det = determinant();
        if (det == static_cast<T>(0))
            throw std::runtime_error("Matrix is singular and cannot be inverted");
        T invDet = static_cast<T>(1) / det;
        return { mat[1][1] * invDet, -mat[0][1] * invDet,
                -mat[1][0] * invDet,  mat[0][0] * invDet };
    }
    inline static constinit Mat2 identity{1, 0, 0, 1};
    inline static constinit Mat2 zero{0, 0, 0, 0};
    inline static constinit Mat2 ones{1, 1, 1, 1};
    static Mat2 rotation(T angle) {
        T c = std::cos(angle);
        T s = std::sin(angle);
        return {c, -s, s, c};
    }

    static Mat2 scaling(T x, T y) {
        return {x, 0, 0, y};
    }

    static Mat2 translation(T x, T y) {
        return {1, x, y, 1};
    }

    static Mat2 projection(T x, T y, T width, T height) {
        return {static_cast<T>(2) / width, 0,
                0, static_cast<T>(2) / height};
    }

    // ===== Utility =====
    void print() const {
        std::cout << "[[" << mat[0][0] << ", " << mat[0][1] << "],\n"
                  << " [" << mat[1][0] << ", " << mat[1][1] << "]]\n";
    }
};

} // namespace LinearAlgebra

#endif // MAT2_HPP
