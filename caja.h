//
// Created by Denzel Urias on 12/03/26.
//

#ifndef COLA_CAJA_H
#define COLA_CAJA_H

#include "cliente.h"
#include "cola.hpp"

class caja {
public:
    caja();

    void atender();

    void elQueSigue();

    int obtenerTiempoAtendido();

    cola<cliente> _atendidos;

private:
    unsigned short _tiempo_atendido;
};


#endif //COLA_CAJA_H