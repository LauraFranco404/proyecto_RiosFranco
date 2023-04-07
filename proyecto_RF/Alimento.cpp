//
// Created by laura on 6/04/2023.
//

#include "Alimento.h"

Alimento::Alimento(string nombreAlimento, int categoria) {
    this->nombreAlimento = nombreAlimento;
    this->categoria = categoria;
}
string Alimento::getNombreAlimento() {
    return this->nombreAlimento;
}
string Alimento::getCategoriaAlimento() {
    if(this->categoria == 0){
        return "Alimento para carnivoros y omnivoros";
    }
    else if (this->categoria == 1){
        return "Alimento apto para herviboros y omnivoros";
    }
    else{
        return "Alimento apto para omnivoros";
    }
};