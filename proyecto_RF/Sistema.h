//
// Created by laura on 4/04/2023.
//

#ifndef PROYECTO_RF_SISTEMA_H
#define PROYECTO_RF_SISTEMA_H
#include <iostream>
#include <string>
#include <iterator>
#include <unordered_map>
#include "Habitat.h"

class Sistema {
private:
    unordered_map<int, Habitat*> mapaHabitats;
public:
    Sistema() = default;
    ~Sistema();

    void recibirHabitat(int id, Habitat* pHabitatTemp);
    bool estaHabitat(string tipoHabitat);
    Habitat* accederAHabitat(string tipoHabitat);
    void mostrarInfoHabitats();
};


#endif //PROYECTO_RF_SISTEMA_H
