//
// Created by lahce on 14/08/2025.
//

#ifndef MAT3_HPP
#define MAT3_HPP
#include <type_traits>

namespace LinearAlgebra
{
    template <typename T> requires std::is_arithmetic_v<T>
    struct Mat3
    {
    private:
        T a,b,c,d,e,f,g,h,i;
        T m[3][3]={{a,b,c},{d,e,f},{g,h,i}};
        public:
        /*
         |a   d   g|
         |b   e   h|
         |c   f   i|
         **/
        explicit Mat3(T a, T b, T c, T d, T e, T f, T g, T h);
        explicit Mat3(T element);
        Mat3()=default;
        bool operator==(Mat3<T> const& other) const;
        bool operator!=(Mat3<T> const& other) const;
        T operator[](int i,int j) const;
        Mat3 operator*(Mat3<T> const& other) const;
        Mat3 operator+(Mat3<T> const& other) const;
        Mat3 operator-(Mat3<T> const& other) const;
        Mat3 operator*(T const& other) const;
        auto determinant() const;
        Mat3 inverse() const;
        Mat3 transpose() const;
        static constinit Mat3 identity=Mat3(1,0,0,0,1,0,0,0,1);
        static constinit Mat3 zero=Mat3(0,0,0,0,0,0,0,0,0);
        static constinit Mat3 one=Mat3(1,1,1,1,1,1,1,1,1,1);
        static Mat3 rotation(T x, T y, T z);
        static Mat3 translation(T x, T y, T z);
        static Mat3 scale(T x, T y, T z);
        
    };

    
} // Matrix

#endif //MAT3_HPP
