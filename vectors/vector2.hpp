//
// Created by lahcen on 18/07/2025.
//

#ifndef VECTOR2_HPP
#define VECTOR2_HPP


namespace Vector {


    template<typename T>
        struct vector2:vector
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

        vector2 operator*(const vector2& other) const;
        vector2& operator*=(const vector2& other);

        bool operator==(const vector2& other) const;
        bool operator!=(const vector2& other) const;

        auto dot(const vector2& other) const;

        auto Eucdistance(const vector2& other) const;
    };



} // Vector

#endif //VECTOR2_HPP
