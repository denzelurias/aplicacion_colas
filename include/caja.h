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

    //Método agregar
    void agregarCaja(cliente p);

    //Metodo Tamaño
    int tamanoCaja() const;

    //Método Imprimir
    void imprimir() const;

    //Método ObtenerNombre
    std::string obtenerNombre();



private:
    unsigned short _tiempo_atendido;
    cola<cliente> _atendidos;
};


#endif //COLA_CAJA_H