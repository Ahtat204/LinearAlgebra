//
// Created by lahce on 25/07/2025.
//

#ifndef MAT2_HPP
#define MAT2_HPP
#include <utility>

namespace LinearAlgebra
{
    template <typename T> requires std::is_arithmetic_v<T>
    struct Mat2
    {
    private:
        T a, b, c, d;
        /**
         * 
         */
        T mat[2][2] = {{a, b}, {c, d}};

    public:
        explicit Mat2(T a, T b, T c, T d);
        explicit Mat2(T a);
        Mat2() = default;
        bool operator==(const Mat2& other) const;
        bool operator!=(const Mat2& other) const;
        Mat2 operator+(const Mat2& other) const;
        Mat2 operator-(const Mat2& other) const;
        Mat2 operator*(const Mat2& other) const;
        Mat2 operator *(auto& scalar);
        T operator[](const std::pair<int, int>& index);
        auto determinant();
        Mat2 transpose();
        Mat2 inverse();
        static constinit Mat2 identity = Mat2(1, 0, 0, 1);
        static constinit Mat2 zero = Mat2(0, 0, 0, 0);
        static constinit Mat2 ones = Mat2(1, 1, 1, 1);
        static Mat2 rotation(float angle);
        static Mat2 scaling(T x, T y);
        static Mat2 translation(T x, T y);
        static Mat2 projection(T x, T y, T width, T height);
    };
} // Matrix

#endif //MAT2_HPP
