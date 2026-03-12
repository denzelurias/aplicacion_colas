//
// Created by denzelurias on 3/11/26.
//

#ifndef COLA_CLIENTE_H
#define COLA_CLIENTE_H
#include <iostream>


class cliente {
    friend std::ostream &operator<<(std::ostream &salida, const cliente &c);
public:
    explicit cliente();

    std::string obtenerNombre() const;

    void atender();

    void imprimir() const;

    int obtenerTiempoRequerido() const;

    int obtenerTiempoAtendido() const;

private:
    std::string nombre_completo;
    unsigned short tiempo_requerido;

public:
    unsigned short tiempo_atendido;
};


#endif //COLA_CLIENTE_H