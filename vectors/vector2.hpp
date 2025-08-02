//
// Created by lahcen on 18/07/2025.
//

#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include <type_traits>


namespace Vector {


    template<typename T> requires std::is_arithmetic_v<T>
        struct vector2
    {
    private:
        T x;
        T y;
    public:
        vector2(T x, T  y );
         vector2()=default;
        T constexpr  operator[](const int& index) const;

        [[nodiscard]] auto getMagnitude() const;

      
        [[nodiscard]]  bool isNormalized() const  ;
        [[nodiscard]] vector2<T> normalize() const;
        vector2 operator+(const vector2& other) const;
        vector2& operator+=(const vector2& other) ;

        vector2 operator-(const vector2& other) const;
        vector2& operator-=(const vector2& other);

        vector2& cross(vector2& other);
        vector2 operator*(const vector2& other) const;
        vector2& operator*=(const vector2& other);
        static vector2 identity();
        static vector2 zero();
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
        auto Eucdistance(const vector2& other) const;
    };
;


} // Vector

#endif //VECTOR2_HPP
