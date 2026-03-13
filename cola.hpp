/**
 * \file Queue.hpp
 * \brief Implementacíon de colas
 * \author Denzel
 * \date 06/03/2026
 */

#include <iostream>
#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T = int> class cola {
public:
    cola();

    cola(const cola &p);

    cola &operator=(const cola &p);

    ~cola();

    void agregar(T valor);

    void eliminar();

    T frente() const;

    T fondo() const;

    void vaciar();

    int tamano() const;

    bool estaVacia() const;

    void imprimir() const;

private:
    int _numElem;

    struct elemento {
        elemento(T v, elemento *next_ = nullptr);
        T _valor;
        elemento *_siguiente;
    };
    elemento *_fondo;
};

#include "cola.tpp"

#endif // QUEUE_HPP