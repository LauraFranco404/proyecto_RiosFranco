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
#include "Alimento.h"

class Sistema {
private:
    unordered_map<int, Habitat*> mapaHabitats;
    unordered_map<int, Alimento*> mapaAlimentos;
public:
    Sistema() = default;
    ~Sistema();

    void recibirHabitat(int id, Habitat* pHabitatTemp);
    bool estaHabitat(string tipoHabitat);
    Habitat* accederAHabitat(string tipoHabitat);
    void mostrarInfoHabitats();

    void recibirAlimentos(int id, Alimento* pAlimentoTemp);
    void mostrarInfoAlimentos();
    Alimento* accederAAlimento();
};


#endif //PROYECTO_RF_SISTEMA_H
