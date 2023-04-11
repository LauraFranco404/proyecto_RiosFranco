//
// Created by laura on 3/04/2023.
//

#include "Animal.h"

//Constructor
Animal::Animal(string nombre, int edad, string especie, string tipoA, int horasS, int tiempoJuego, bool estadoSalud, string habitat, bool haJugado){
    this->nombre = nombre;
    this->edad = edad;
    this->especie = especie;
    this->tipoA = tipoA;
    this->horasS = horasS;
    this->tiempoJuego = tiempoJuego;
    this->estadoSalud = estadoSalud;
    this->habitat = habitat;
    this->haJugado = haJugado;
}

/*
 * Las funciones getters se encargan específicamente de buscar el valor que tenga cada uno de los atributos de los objetos pertenecientes a la clase Animal
 */
string Animal::getHabitat() {
    return this->habitat;
}

string Animal::getNombre(){
    return this->nombre;
}
int Animal::getEdad(){
    return this->edad;
}

string Animal::getEspecie(){
    return this->especie;
}

string Animal::getTipoAlimentacion(){
    return this->tipoA;
}

int Animal::getHorasSuenio(){
    return this->horasS;
}
int Animal::getTiempoJuego(){
    return this->tiempoJuego;
}

string Animal::getEstadoSalud(){
    if(estadoSalud == true){
        return "sano";
    }
    else{
        return "enfermo";
    }
}

bool Animal::getHaJugado(){
    return this->haJugado;
}

//Esta función se utiliza específicamente para el momento en el que se muestren por consola los atributos del objeto creado
string Animal::verSiHaJugado(){
    if(haJugado == true){
        return "Ha jugado";
    }
    else{
        return "No ha jugado";
    }
}

//Esta función ayuda a modificar el valor del booleano haJugado cuando se decide jugar con un animal en el zoológico
void Animal::setHaJugado(bool haJugado){
    this->haJugado = haJugado;
}