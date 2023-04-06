//
// Created by laura on 3/04/2023.
//

#ifndef PROYECTO_RF_HABITAT_H
#define PROYECTO_RF_HABITAT_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "Animal.h"

using std::cout;
using std::string;
using std::unordered_map;

class Habitat {
private:
    string tipoH;
    unordered_map<int, Animal*> mapaAnimales;
public:
    Habitat(string tipoHabitat);
    string getTipoH();
    void recibirAnimal(int id, Animal* pAnimalTemp, string habitat);
    bool existeHabitat(string habitat);
};


#endif //PROYECTO_RF_HABITAT_H
