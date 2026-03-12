//
// Created by denzelurias on 3/11/26.
//
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "cola.hpp"
#include "cliente.h"
#include "auxiliares.h"

// Tiempos
#define TIEMPO_MINIMO 120
#define TIEMPO_MAXIMO 240

// Cooldown de llegada
#define COOLDOWN_ESPERA_MINIMA 4
#define COOLDOWN_ESPERA_MAXIMA 14

// Auxiliares
void limpiarPantalla();
int aleatorio(int inicio, int final);
void presionarTecla();

int main() {
    // Semilla
    srand(time(nullptr));

    // Pantalla uno
    int tiempo_atencion = aleatorio(TIEMPO_MINIMO, TIEMPO_MAXIMO);

    std::cout << "Las cajas atenderán a cuantas personas pueda en 132 minutos.\n\n";
    std::cout << "El tiempo de atención por persona es aleatorio\n";
    presionarTecla();
    limpiarPantalla();

    // Clientes ya atendidos
    cola<cliente> uno_caja_atendidos;
    cola<cliente> dos_caja_atendidos;
    cola<cliente> tres_caja_atendidos;

    // Cajas ocupadas
    bool uno_ocupada = false;
    bool dos_ocupada = false;
    bool tres_ocupada = false;

    // En espera
    cola<cliente> en_espera;

    // Hacemos un primer cooldown para el primer cliente
    int cooldown_espera = aleatorio(COOLDOWN_ESPERA_MINIMA, COOLDOWN_ESPERA_MAXIMA);
    // Pantalla dos
    for (int i = 1; i < tiempo_atencion; i++) {

        if (!uno_caja_atendidos.estaVacia()) std::cout << "BAAAAKA" << uno_caja_atendidos.fondo().obtenerTiempoAtendido() << '\n';
        if (cooldown_espera == 0) {
            cooldown_espera = aleatorio(COOLDOWN_ESPERA_MINIMA, COOLDOWN_ESPERA_MAXIMA);

            cliente nuevo_cliente;

            en_espera.agregar(nuevo_cliente);
        }

        std::cout << "La caja atenderá a cuantas personas pueda en " << tiempo_atencion << " minutos.\n";
        std::cout << "Reloj: " << i << '\n';

        // Caja uno
        if (uno_ocupada == true) {
            std::cout << "La caja uno está atendiendo a " << uno_caja_atendidos.fondo().obtenerNombre()
                      << "\t\tTiempo de atención: " << uno_caja_atendidos.fondo().obtenerTiempoAtendido() << '\n';
            if (uno_caja_atendidos.fondo().obtenerTiempoAtendido() == uno_caja_atendidos.fondo().obtenerTiempoRequerido())
                uno_ocupada = false;
            else
                uno_caja_atendidos.fondo().atender();
        }
        else {
            if (!en_espera.estaVacia()) {
                uno_caja_atendidos.agregar(en_espera.frente());
                en_espera.eliminar();
                uno_ocupada = true;
            }
            else uno_ocupada = false;
        }

        // Caja dps
        if (dos_ocupada == true) {
            std::cout << "La caja dos está atendiendo a " << dos_caja_atendidos.fondo().obtenerNombre()
                      << "\t\tTiempo de atención: " << dos_caja_atendidos.fondo().obtenerTiempoAtendido() << '\n';
            if (dos_caja_atendidos.fondo().obtenerTiempoAtendido() == dos_caja_atendidos.fondo().obtenerTiempoRequerido())
                dos_ocupada = false;
            else
                dos_caja_atendidos.fondo().atender();
        }
        else {
            if (!en_espera.estaVacia()) {
                dos_caja_atendidos.agregar(en_espera.frente());
                en_espera.eliminar();
                dos_ocupada = true;
            }
            else dos_ocupada = false;
        }

        // Caja tres
        if (tres_ocupada == true) {
            std::cout << "La caja tres está atendiendo a " << tres_caja_atendidos.fondo().obtenerNombre()
                      << "\t\tTiempo de atención: " << tres_caja_atendidos.fondo().obtenerTiempoAtendido() << '\n';
            if (tres_caja_atendidos.fondo().obtenerTiempoAtendido() == tres_caja_atendidos.fondo().obtenerTiempoRequerido())
                tres_ocupada = false;
            else
                tres_caja_atendidos.fondo().atender();
        }
        else {
            if (!en_espera.estaVacia()) {
                tres_caja_atendidos.agregar(en_espera.frente());
                en_espera.eliminar();
                tres_ocupada = true;
            }
            else tres_ocupada = false;
        }


        std::cout << "En espera:\n";
        if (!en_espera.estaVacia()) en_espera.imprimir();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        --cooldown_espera;
        limpiarPantalla();
    }


}