cmake_minimum_required(VERSION 3.30)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_BUILD_TYPE Release)

add_library(linearalgebra  vectors/vector2.cpp
        Matrix/Mat2.cpp
        Matrix/Mat3.cpp
        vectors/vector3.cpp
        quaternions/quaternions.cpp
        Matrix/Mat4.cpp
        include/Matrix/Mat4.hpp
        vectors/vector4.cpp
        include/vectors/vector4.hpp
)
include_directories(include)
target_include_directories(linearalgebra PUBLIC
        include/
)