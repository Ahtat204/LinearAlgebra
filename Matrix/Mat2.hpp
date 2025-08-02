//
// Created by lahce on 25/07/2025.
//

#ifndef MAT2_HPP
#define MAT2_HPP
#include<concepts>
#include <utility>

namespace Matrix
{
    template <typename T> requires std::is_arithmetic_v<T>
    struct Mat2
    {
    private:
        T matrix[2][2];
        T a,b,c,d;
    
    public:
       explicit  Mat2(T a, T b, T c, T d);
        explicit   Mat2(T a);
        Mat2()=default;
        bool operator==(const Mat2&) const;
        bool operator!=(const Mat2&) const;
        Mat2 operator+(const Mat2&) const;
        Mat2 operator-(const Mat2&) const;
        Mat2 operator*(const Mat2&) const;
        Mat2 operator *( auto &scalar );
        T operator[](const std::pair<int,int>& index);
        auto determinant();
        Mat2 transpose();
        Mat2 inverse();
        static Mat2 identity();
        static Mat2 zero();
        static Mat2 ones();
        static Mat2 rotation(T angle);
     
        
    };


    
} // Matrix

#endif //MAT2_HPP
