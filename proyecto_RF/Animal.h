//
// Created by laura on 3/04/2023.
//

#ifndef PROYECTO_RF_ANIMAL_H
#define PROYECTO_RF_ANIMAL_H
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

class Animal {
private:
     string nombre;
     int edad;
     string especie;
     string tipoA;
     int horasS;
     int tiempoJuego;
     bool estadoSalud;
     string habitat;
     bool haJugado;

public:
    Animal(string nombre, int edad, string especie, string tipoA, int horasS, int tiempoJuego, bool estadoSalud, string habitat, bool haJugado);
    string getHabitat();
    string getNombre();
    int getEdad();
    string getEspecie();
    string getTipoAlimentacion();
    int getHorasSuenio();
    int getTiempoJuego();
    string getEstadoSalud();
    string verSiHaJugado();
    bool getHaJugado();
    void setHaJugado(bool haJugado);
};


#endif //PROYECTO_RF_ANIMAL_H
