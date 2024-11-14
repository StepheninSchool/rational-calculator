cmake_minimum_required(VERSION 3.29)
project(rational)

set(CMAKE_CXX_STANDARD 20)

add_executable(rational source/main.cpp
        include/Rational.h
        source/Rational.cpp
        source/validation.cpp
        include/Validation.h
)
