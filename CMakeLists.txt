cmake_minimum_required(VERSION 4.0)
project(cola)

set(CMAKE_CXX_STANDARD 20)

add_executable(cola main.cpp
        cola.hpp
        cola.tpp
        main.cpp
        cliente.cpp
        cliente.h
        auxiliares.cpp
        auxiliares.h
)
