//
// Created by laura on 3/04/2023.
//

#include "Animal.h"
Animal::Animal(string nombre, int edad, string especie, string tipoA, int horasS, int tiempoJuego, bool estadoSalud, string habitat){
    this->nombre = nombre;
    this->edad = edad;
    this->especie = especie;
    this->tipoA = tipoA;
    this->horasS = horasS;
    this->tiempoJuego = tiempoJuego;
    this->estadoSalud = estadoSalud;
    this->habitat = habitat;
}

string Animal::getHabitat() {
    return this->habitat;
}

