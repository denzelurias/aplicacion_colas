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

int caja::obtenerTiempoRequerido() //Caja
{
    return this->_atendidos.fondo().obtenerTiempoRequerido(); // Cliente
}


int caja::obtenerTiempoAtendido() {
    //
    return this->_tiempo_atendido;
}

std::string caja::obtenerNombre(){
    return this->_atendidos.fondo().obtenerNombre();

}

void caja::agregarCaja(cliente p){
    return this->_atendidos.agregar(p);
}

int caja::tamanoCaja() const{
    return this->_atendidos.tamano();
}

