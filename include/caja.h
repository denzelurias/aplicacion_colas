//
// Created by Denzel Urias on 12/03/26.
//

#ifndef COLA_CAJA_H
#define COLA_CAJA_H

#include "cliente.h"
#include "cola.h"

class caja {
public:
    caja();

    void atender();

    void elQueSigue();

    //Método obtTiempoRequerido
    int obtenerTiempoRequerido();

    //Método ObtenerTiempoAtendido
    int obtenerTiempoAtendido();

    //Método ObtenerNombre
    std::string obtenerNombre();

    //Método agregar
    void agregarCaja(const cliente &p);

    //Metodo Tamaño
    int tamanoCaja() const;

    //Método Imprimir
    void imprimir() const;

    bool estaOcupada() const;

    void ocupar();

    void desocupar();

    unsigned int tamano() const;

private:
    unsigned short _tiempo_atendido;
    bool _ocupada;
    cola<cliente> _atendidos;
};


#endif //COLA_CAJA_H