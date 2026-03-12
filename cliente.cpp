//
// Created by denzelurias on 3/11/26.
//

#include "cliente.h"
#include "auxiliares.h"

// Tiempos en caja
#define CAJA_TIEMPO_MIN 5
#define CAJA_TIEMPO_MAX 15

// Arreglo constante de 20 nombres
const std::string nombres[20] = {
    "Alejandro", "Beatriz", "Denzel", "Daniela", "Eduardo",
    "Fernanda", "Gabriel", "Hector", "Isabel", "Angel",
    "Karla", "Luis", "Maria", "Nicolas", "Olivia",
    "Pablo", "Sofia", "Tomas", "Samantha", "Irene"
};
#define NUM_NOMBRES 20

// Arreglo constante de 20 apellidos
const std::string apellidos[20] = {
    "Garcia", "Martinez", "Rodriguez", "Lopez", "Gonzalez",
    "Perez", "Sanchez", "Romero", "Sosa", "Torres",
    "Ramirez", "Cruz", "Flores", "Gomez", "Rivera",
    "Reyes", "Felix", "Ortiz", "Ortega", "Castillo"
};
#define NUM_APELLIDOS 20

cliente::cliente() {
    // Creamos a la persona
        // Nombre aleatorio
        int nombre = aleatorio(0, NUM_NOMBRES - 1);
        // Apellido aleatorio
        int apellido = aleatorio(0, NUM_APELLIDOS - 1);

    this->nombre_completo = nombres[nombre] + " " + apellidos[apellido];
    this->tiempo_requerido = aleatorio(CAJA_TIEMPO_MIN, CAJA_TIEMPO_MAX);
    this->tiempo_atendido = 0;
}

std::string cliente::obtenerNombre() const{
    return this->nombre_completo;
}

void cliente::atender() {
    ++(this->tiempo_atendido);
}

int cliente::obtenerTiempoRequerido() const {
    return this->tiempo_requerido;
}

int cliente::obtenerTiempoAtendido() const {
    return this->tiempo_atendido;
}

std::ostream &operator<<(std::ostream &salida, const cliente &c) {
    salida << c.obtenerNombre();
    return salida;
}