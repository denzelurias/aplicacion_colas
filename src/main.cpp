//
// Created by denzelurias on 3/11/26.
//
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "../include/cola.h"
#include "../include/cliente.h"
#include "../include/auxiliares.h"
#include "../include/caja.h"

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

    /*
    bool uno_eliminar = false;
    bool dos_eliminar = false;
    bool tres_eliminar = false;
    */

    // En espera
    cola<cliente> en_espera;
    //Hola
    // Hacemos un primer cooldown para el primer cliente
    int cooldown_espera = aleatorio(COOLDOWN_ESPERA_MINIMA, COOLDOWN_ESPERA_MAXIMA);
    // Pantalla dos
    for (int i = 1; i < tiempo_atencion; i++) {

        std::cout << "La caja atenderá a cuantas personas pueda en " << tiempo_atencion << " minutos.\n";
        std::cout << "Reloj: " << i << "\tCooldown: " << cooldown_espera << "\n\n";

        // Caja uno
        if (caja_uno.estaOcupada()) {
            std::cout << "\tLa caja uno está atendiendo a " << caja_uno.obtenerNombre()
                      << "\t\tTiempo de atención: " << caja_uno.obtenerTiempoAtendido();
            if (caja_uno.obtenerTiempoAtendido() == caja_uno.obtenerTiempoRequerido()) {
                caja_uno.desocupar();
                caja_uno.elQueSigue();
            }
            else
                caja_uno.atender();
        }
        else {
            std::cout << "\tLa caja uno está desocupada";

            if (!en_espera.estaVacia()) {
                caja_uno.agregarCaja(en_espera.frente());
                en_espera.eliminar();
                //uno_eliminar = true;
                caja_uno.ocupar();
            }
            else {
                caja_uno.desocupar();
            }
        }

        std::cout << "\n\n";

        // Caja dps
        if (caja_dos.estaOcupada()) {
            std::cout << "\tLa caja dos está atendiendo a " << caja_dos.obtenerNombre()
                      << "\t\tTiempo de atención: " << caja_dos.obtenerTiempoAtendido();
            if (caja_dos.obtenerTiempoAtendido() == caja_dos.obtenerTiempoRequerido()) {
                caja_dos.desocupar();
                caja_dos.elQueSigue();
            }
            else
                caja_dos.atender();
        }
        else {
            std::cout << "\tLa caja dos está desocupada";

            if (!en_espera.estaVacia()) {
                //Se ondeo el denzel aqui
                caja_dos.agregarCaja(en_espera.frente());
                en_espera.eliminar();
                //dos_eliminar = true;
                caja_dos.ocupar();
            }
            else {
                caja_dos.desocupar();
            }
        }

        std::cout << "\n\n";

        // Caja tres
        if (caja_tres.estaOcupada()) {
            std::cout << "\tLa caja tres está atendiendo a " << caja_tres.obtenerNombre()
                      << "\t\tTiempo de atención: " << caja_tres.obtenerTiempoAtendido();
            if (caja_tres.obtenerTiempoAtendido() == caja_tres.obtenerTiempoRequerido()) {
                caja_tres.desocupar();
                caja_tres.elQueSigue();
            }
            else
                caja_tres.atender();
        }
        else {
            std::cout << "\tLa caja tres está desocupada";

            if (!en_espera.estaVacia()) {\
                //Falta metodo agregar a caja
                caja_tres.agregarCaja(en_espera.frente());
                en_espera.eliminar();
                //tres_eliminar = true;
                caja_tres.ocupar();
            }
            else {
                caja_tres.desocupar();
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

        /*
        if (uno_eliminar) {
            en_espera.eliminar();
            uno_eliminar = false;
        }
        if (dos_eliminar) {
            en_espera.eliminar();
            dos_eliminar = false;
        }
        if (tres_eliminar) {
            en_espera.eliminar();
            tres_eliminar = false;
        }
        */


        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        --cooldown_espera;
        limpiarPantalla();
    }

    // Atendidos por caja 1:
    std::cout << "La caja uno atendió a " << caja_uno.tamano() << " personas, cuyos nombres, en orden de atención, son:\n";
    caja_uno.imprimir();

    // Atendidos por caja 2:
    std::cout << "La caja dos atendió a " << caja_dos.tamano() << " personas, cuyos nombres, en orden de atención, son:\n";
    caja_dos.imprimir();


    // Atendidos por caja 3:
    std::cout << "La caja tres atendió a " << caja_tres.tamano() << " personas, cuyos nombres, en orden de atención, son:\n";
    caja_tres.imprimir();

    // Sin atender:
    std::cout << "Quedaron " << en_espera.tamano() << " personas sin atender:\n";
    if (!en_espera.estaVacia()) en_espera.imprimir();

    return 0;
}