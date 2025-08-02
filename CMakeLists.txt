cmake_minimum_required(VERSION 3.30)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 26)

add_library(STATIC vectors/vector2.cpp
        Matrix/Mat2.cpp
        Matrix/Mat2.hpp)

