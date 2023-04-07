//
// Created by laura on 6/04/2023.
//

#ifndef PROYECTO_RF_ALIMENTO_H
#define PROYECTO_RF_ALIMENTO_H

#include <iostream>
#include <string>
#include <iterator>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Alimento {
private:

    string nombreAlimento;
    int categoria;

public:
    Alimento(string nombreAlimento, int categoria);
    string getNombreAlimento();
    string getCategoriaAlimento();
    int getNumCategoriaAlimento();
};


#endif //PROYECTO_RF_ALIMENTO_H
