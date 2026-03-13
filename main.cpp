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
#include "caja.h"

// Tiempos
#define TIEMPO_MINIMO 120
#define TIEMPO_MAXIMO 240

// Cooldown de llegada
#define COOLDOWN_ESPERA_MINIMA 4
#define COOLDOWN_ESPERA_MAXIMA 8

// Auxiliares
void limpiarPantalla();
int aleatorio(int inicio, int final);
void presionarTecla();

int main() {
    // Semilla
    srand(time(nullptr));

    // Pantalla uno
    int tiempo_atencion = aleatorio(TIEMPO_MINIMO, TIEMPO_MAXIMO);

    std::cout << "Las cajas atenderán a cuantas personas pueda en " << tiempo_atencion << " minutos.\n\n";
    std::cout << "El tiempo de atención por persona es aleatorio\n";
    presionarTecla();
    limpiarPantalla();

    // Clientes ya atendidos
    caja caja_uno;
    caja caja_dos;
    caja caja_tres;

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

        std::cout << "La caja atenderá a cuantas personas pueda en " << tiempo_atencion << " minutos.\n";
        std::cout << "Reloj: " << i << "\tCooldown: " << cooldown_espera << "\n\n";

        // Caja uno
        if (uno_ocupada == true) {
            std::cout << "\tLa caja uno está atendiendo a " << caja_uno._atendidos.fondo().obtenerNombre()
                      << "\t\tTiempo de atención: " << caja_uno.obtenerTiempoAtendido();
            if (caja_uno.obtenerTiempoAtendido() == caja_uno._atendidos.fondo().obtenerTiempoRequerido()) {
                uno_ocupada = false;
                caja_uno.elQueSigue();
            }
            else
                caja_uno.atender();
        }
        else {
            std::cout << "\tLa caja uno está desocupada";

            if (!en_espera.estaVacia()) {
                caja_uno._atendidos.agregar(en_espera.frente());
                en_espera.eliminar();
                uno_ocupada = true;
            }
            else {
                uno_ocupada = false;
            }
        }

        std::cout << "\n\n";

        // Caja dps
        if (dos_ocupada == true) {
            std::cout << "\tLa caja dos está atendiendo a " << caja_dos._atendidos.fondo().obtenerNombre()
                      << "\t\tTiempo de atención: " << caja_dos.obtenerTiempoAtendido();
            if (caja_dos.obtenerTiempoAtendido() == caja_dos._atendidos.fondo().obtenerTiempoRequerido()) {
                dos_ocupada = false;
                caja_dos.elQueSigue();
            }
            else
                caja_dos.atender();
        }
        else {
            std::cout << "\tLa caja dos está desocupada";

            if (!en_espera.estaVacia()) {
                caja_dos._atendidos.agregar(en_espera.frente());
                en_espera.eliminar();
                dos_ocupada = true;
            }
            else {
                dos_ocupada = false;
            }
        }

        std::cout << "\n\n";

        // Caja tres
        if (tres_ocupada == true) {
            std::cout << "\tLa caja tres está atendiendo a " << caja_tres._atendidos.fondo().obtenerNombre()
                      << "\t\tTiempo de atención: " << caja_tres.obtenerTiempoAtendido();
            if (caja_tres.obtenerTiempoAtendido() == caja_tres._atendidos.fondo().obtenerTiempoRequerido()) {
                tres_ocupada = false;
                caja_tres.elQueSigue();
            }
            else
                caja_tres.atender();
        }
        else {
            std::cout << "\tLa caja tres está desocupada";

            if (!en_espera.estaVacia()) {
                caja_tres._atendidos.agregar(en_espera.frente());
                en_espera.eliminar();
                tres_ocupada = true;
            }
            else {
                tres_ocupada = false;
            }
        }

        std::cout << "\n\n";

        if (cooldown_espera == 0) {
            cooldown_espera = aleatorio(COOLDOWN_ESPERA_MINIMA, COOLDOWN_ESPERA_MAXIMA);

            cliente nuevo_cliente;

            en_espera.agregar(nuevo_cliente);
        }

        std::cout << "En espera:\n";
        if (!en_espera.estaVacia()) en_espera.imprimir();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        --cooldown_espera;
        limpiarPantalla();
    }

    // Atendidos por caja 1:
    std::cout << "La caja uno atendió a " << caja_uno._atendidos.tamano() << " personas, cuyos nombres, en orden de atención, son:\n";
    caja_uno._atendidos.imprimir();

    // Atendidos por caja 2:
    std::cout << "La caja dos atendió a " << caja_dos._atendidos.tamano() << " personas, cuyos nombres, en orden de atención, son:\n";
    caja_dos._atendidos.imprimir();

    // Atendidos por caja 3:
    std::cout << "La caja tres atendió a " << caja_tres._atendidos.tamano() << " personas, cuyos nombres, en orden de atención, son:\n";
    caja_tres._atendidos.imprimir();

    // Sin atender:
    std::cout << "Quedaron " << en_espera.tamano() << " personas sin atender:\n";
    if (!en_espera.estaVacia()) en_espera.imprimir();

    return 0;
}