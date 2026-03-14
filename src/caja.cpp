//
// Created by Denzel Urias on 12/03/26.
//

#include "../include/caja.h"

caja::caja() {
    this->_tiempo_atendido = 0;
    this->_ocupada = false;
}

void caja::atender() {
    ++this->_tiempo_atendido;
}

void caja::elQueSigue() {
    this->_tiempo_atendido = 0;
}

int caja::obtenerTiempoRequerido() {
    return this->_atendidos.fondo().obtenerTiempoRequerido(); // Cliente
}

int caja::obtenerTiempoAtendido() {
    return this->_tiempo_atendido;
}

std::string caja::obtenerNombre(){
    return this->_atendidos.fondo().obtenerNombre();
}

void caja::agregarCaja(const cliente &p){
    this->_atendidos.agregar(p);
}

int caja::tamanoCaja() const{
    return this->_atendidos.tamano();
}

void caja::imprimir() const {
    this->_atendidos.imprimir();
}

bool caja::estaOcupada() const {
    return _ocupada;
}

void caja::ocupar() {
    this->_ocupada = true;
}

void caja::desocupar() {
    this->_ocupada = false;
}

unsigned int caja::tamano() const {
    return this->_atendidos.tamano();
}
