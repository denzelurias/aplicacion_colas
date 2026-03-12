//
// Created by denzelurias on 3/11/26.
//

#include <iostream>
#include "auxiliares.h"

void limpiarPantalla() {
#ifdef _WIN32
    std::system("cls");
#else
    // Asume cualquier sistema basado en Unix (Linux/macOS)
    std::system("clear");
#endif
}

void presionarTecla() {
    std::cout << "Presiona Enter para continuar..." << '\n';
    std::cin.get();
}

int aleatorio(int inicio, int final) {

    return rand() % (final - inicio + 1) + inicio;
}
