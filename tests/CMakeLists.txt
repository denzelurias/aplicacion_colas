cmake_minimum_required(VERSION 3.30.5)
project(cola)

set(CMAKE_CXX_STANDARD 20)

add_executable(cola ../src/main.cpp

        ../include/caja.h
        ../src/caja.cpp

        ../include/cliente.h
        ../src/cliente.cpp

        ../include/auxiliares.h
        ../src/auxiliares.cpp

        ../include/cola.h
        ../src/cola.tpp
)
