//
// Created by lahce on 14/08/2025.
//

#ifndef VECTOR3_HPP
#define VECTOR3_HPP
#include <type_traits>

namespace LinearAlgebra::vector
{
    template <typename T> requires std::is_arithmetic_v<T>
    struct vector3
    {
    private:
        T x, y, z;
        public:
        explicit vector3(const T x, const T y, const T z);
        vector3()=default;
        explicit vector3(const T& x);
        T constexpr operator[](int i) const;
        [[nodiscard]] auto getMagnitude() const;
        [[nodiscard]]  bool isNormalized() const;
        [[nodiscard]] vector3 normalize() const;
        vector3 operator+(const vector3& other) const;
        vector3& operator+=(const vector3& other) ;

        vector3 operator-(const vector3& other) const;
        vector3& operator-=(const vector3& other);

        vector3& cross(vector3& other);
        vector3 operator*(const vector3& other) const;
        vector3& operator*=(const vector3& other);
        static vector3 identity();
        static vector3 zero();
        bool operator==(const vector3& other) const;
        bool operator!=(const vector3& other) const;
        /**
         * dot product of two vectors
         * @param other 
         * @return 
         */
        auto dot(const vector3& other) const;
        /**
         * method returns the euclidian distance  
         * @param other 
         * @return 
         */
        auto euclidianDistance(const vector3& other) const;
        
    };

   
}
using fvec3=LinearAlgebra::vector::vector3<float>;
using dvec3=LinearAlgebra::vector::vector3<double>;
using ivec3=LinearAlgebra::vector::vector3<int>;

#endif //VECTOR3_HPP
