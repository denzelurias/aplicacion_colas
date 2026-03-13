cmake_minimum_required(VERSION 4.0)
project(cola)

set(CMAKE_CXX_STANDARD 20)

add_executable(cola main.cpp

        cola.tpp
        cola.hpp

        cliente.cpp
        cliente.h

        auxiliares.cpp
        auxiliares.h

        caja.cpp
        caja.h
)
