//
// Created by Denzel Urias on 12/03/26.
//

#include "caja.h"

caja::caja() {
    this->_tiempo_atendido = 0;
}

void caja::atender() {
    ++this->_tiempo_atendido;
}

void caja::elQueSigue() {
    this->_tiempo_atendido = 0;
}

int caja::obtenerTiempoAtendido() {
    return this->_tiempo_atendido;
}
