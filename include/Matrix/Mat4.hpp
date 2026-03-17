
#ifndef MAT4_HPP
#define MAT4_HPP
#include <bits/stdc++.h>
#include <type_traits>


namespace LinearAlgebra
{
    template <typename T>
        requires std::is_arithmetic_v<T>
    struct Mat4
    {
        T m[4][4]{};
       explicit  constexpr Mat4(T a, T b, T c, T d,
                       T e, T f, T g, T h,
                       T i, T j, T k, T l,
                       T m, T n, T o, T p) :
            m{{a, b, c,d}, {e, f,g,h}, {i,j,k,l},{m,n,o,p}}
        {
        }
        explicit constexpr Mat4(T a) :
    };
} // namespace LinearAlgebra


#endif // MAT4_HPP
