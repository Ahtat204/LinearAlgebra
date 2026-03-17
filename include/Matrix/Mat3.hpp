
#ifndef MAT3_HPP
#define MAT3_HPP

#include <type_traits>
#include <utility>
#include <stdexcept>
#include <iostream>
#include"Mat2.hpp"
namespace LinearAlgebra
{
    template<typename T>
        requires std::is_arithmetic_v<T>
    struct Mat3
    {
        T m[3][3]{};
        constexpr Mat3(T a, T b, T c,
                       T d, T e, T f,
                       T g, T h, T i)
            : m{{a, b, c}, {d, e, f}, {g, h, i}} {}

        explicit constexpr Mat3(T val)
            : m{{val, val, val}, {val, val, val}, {val, val, val}} {}

        constexpr Mat3() = default;
        constexpr bool operator==(const Mat3& other) const {
            for (size_t r = 0; r < 3; ++r)
                for (size_t c = 0; c < 3; ++c)
                    if (m[r][c] != other.m[r][c]) return false;
            return true;
        }

        constexpr bool operator!=(const Mat3& other) const {
            return !(*this == other);
        }
        constexpr T& operator()(size_t row, size_t col) {
            if (row >= 3 || col >= 3)
                throw std::out_of_range("Mat3 index out of range");
            return m[row][col];
        }
        constexpr const T& operator()(size_t row, size_t col) const {
            if (row >= 3 || col >= 3)
                throw std::out_of_range("Mat3 index out of range");
            return m[row][col];
        }
        constexpr Mat3 operator+(const Mat3& other) const {
            Mat3 result;
            for (size_t r = 0; r < 3; ++r)
                for (size_t c = 0; c < 3; ++c)
                    result.m[r][c] = m[r][c] + other.m[r][c];
            return result;
        }
        constexpr Mat3 operator-(const Mat3& other) const {
            Mat3 result;
            for (size_t r = 0; r < 3; ++r)
                for (size_t c = 0; c < 3; ++c)
                    result.m[r][c] = m[r][c] - other.m[r][c];
            return result;
        }
        constexpr Mat3 operator*(const Mat3& other) const {
            Mat3 result{};
            for (size_t r = 0; r < 3; ++r)
                for (size_t c = 0; c < 3; ++c)
                    for (size_t k = 0; k < 3; ++k)
                        result.m[r][c] += m[r][k] * other.m[k][c];
            return result;
        }

        constexpr Mat3 operator*(T scalar) const {
            Mat3 result;
            for (size_t r = 0; r < 3; ++r)
                for (size_t c = 0; c < 3; ++c)
                    result.m[r][c] = m[r][c] * scalar;
            return result;
        }
        constexpr T determinant() const {
            return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
                 - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
                 + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        }

        constexpr Mat3 transpose() const {
            return {
                m[0][0], m[1][0], m[2][0],
                m[0][1], m[1][1], m[2][1],
                m[0][2], m[1][2], m[2][2]
            };
        }

        constexpr Mat3 inverse() const {
            T det = determinant();
            if (det == static_cast<T>(0))
                throw std::runtime_error("Matrix is singular and cannot be inverted");
            T invDet = static_cast<T>(1) / det;

            Mat3 adj{
                (m[1][1] * m[2][2] - m[1][2] * m[2][1]),
                -(m[0][1] * m[2][2] - m[0][2] * m[2][1]),
                (m[0][1] * m[1][2] - m[0][2] * m[1][1]),

                -(m[1][0] * m[2][2] - m[1][2] * m[2][0]),
                (m[0][0] * m[2][2] - m[0][2] * m[2][0]),
                -(m[0][0] * m[1][2] - m[0][2] * m[1][0]),

                (m[1][0] * m[2][1] - m[1][1] * m[2][0]),
                -(m[0][0] * m[2][1] - m[0][1] * m[2][0]),
                (m[0][0] * m[1][1] - m[0][1] * m[1][0])
            };

            return adj.transpose() * invDet;
        }
        inline static constinit Mat3 identity{1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1};

        inline static constinit Mat3 zero{0, 0, 0,
                                          0, 0, 0,
                                          0, 0, 0};

        inline static constinit Mat3 ones{1, 1, 1,
                                          1, 1, 1,
                                          1, 1, 1};
        static Mat3 rotation(T x, T y, T z){}
        explicit operator Mat2<T>() const {
            return Mat2<T>(this->m[0][0], this->m[0][1], this->m[0][2]);
        }
    };
}
#endif