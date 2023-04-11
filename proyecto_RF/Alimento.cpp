//
// Created by laura on 6/04/2023.
//

#include "Alimento.h"

//Constructor
Alimento::Alimento(string nombreAlimento, int categoria) {
    this->nombreAlimento = nombreAlimento;
    this->categoria = categoria;
}

//Verificar el nombre de cada alimento para poder usarlo como un insumo para los animales
string Alimento::getNombreAlimento() {
    return this->nombreAlimento;
}

//Ayudar a determinar la categoría en el momento de mostrar las características de los alimentos en la consola
string Alimento::getCategoriaAlimento() {
    if(this->categoria == 0){
        return "Alimento para carnivoros";
    }
    else if (this->categoria == 1){
        return "Alimento apto para herviboros";
    }
    else{
        return "Alimento apto para omnivoros";
    }
}

//Verificar la categoría para cerciorarse de que el alimento es apto para un tipo de alimentación específica
int Alimento::getNumCategoriaAlimento() {
    return this->categoria;
}