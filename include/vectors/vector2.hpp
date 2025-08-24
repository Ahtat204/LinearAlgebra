//
// Created by lahcen on 18/07/2025.
//

#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include <type_traits>


namespace LinearAlgebra::vector {


    template<typename T> requires std::is_arithmetic_v<T>
        struct vector2
    {
    private:
        T x;
        T y;
    public:
        explicit vector2(T x, T y);
         vector2()=default;
        /**
         * to access vector's elements , we overload the [] operator
         * @param index the index of the required element
         * @return the element at the index @code index
         */
        T constexpr  operator[](const int& index) const;
        /**
         * @return returns the magnitude of the Vector
         * 
         */
        [[nodiscard]] auto getMagnitude() const;

        /**
         * 
         * @return returns true if the vector is normalized
         */
        [[nodiscard]]  bool isNormalized() const  ;
        /**
         * 
         * @return returns a normalized vector 
         */
        [[nodiscard]] vector2 normalize() const;
        /**
         * 
         * @param other the left side of the Addtition
         * @return the sum of two vectors
         */
        vector2 operator+(const vector2& other) const;
        /**
         * 
         * @param other the left side of the Addtition
         * @return assign the sum of the addition to the object
         */
        vector2& operator+=(const vector2& other) ;

        vector2 operator-(const vector2& other) const;
        vector2& operator-=(const vector2& other);
        vector2 operator*(T scalar) const;
        vector2& operator*=(T scalar);
        vector2 operator/(T scalar) const;
        vector2& operator/=(T scalar);
        vector2& cross(vector2& other);
        auto angleBetween(const vector2& other) const;
        vector2 operator*(const vector2& other) const;
        vector2& operator*=(const vector2& other);
        static vector2 identity=vector2(1,1);
        static vector2 zero=vector2(0,0);
        static vector2 up=vector2(0,1);
        static vector2 down=vector2(0,-1);
        static vector2 left;
        static vector2 right;
        static vector2 random();
        bool operator==(const vector2& other) const;
        bool operator!=(const vector2& other) const;
        /**
         * dot product of two vectors
         * @param other 
         * @return 
         */
        auto dot(const vector2& other) const;
        /**
         * method returns the euclidian distance  
         * @param other 
         * @return 
         */
        auto euclidianDistance(const vector2& other) const;
    };
;


} // Vector

using fvec2=LinearAlgebra::vector::vector2<float>;
using dvec2=LinearAlgebra::vector::vector2<double>;
using ivec2=LinearAlgebra::vector::vector2<int>;

#endif //VECTOR2_HPP
