//
// Created by laura on 3/04/2023.
//

#include "Habitat.h"

Habitat::Habitat(string tipoHabitat){
    this->tipoH = tipoHabitat;
}


string Habitat::getTipoH() {
    return this->tipoH;
};

void Habitat::recibirAnimal(int id, Animal *pAnimalTemp, string habitat) {
    if(pAnimalTemp->getHabitat() != habitat){
        cout << "Este animal pertenece al habitat " << pAnimalTemp ->getHabitat() << std::endl;
        throw std::logic_error("Recuerda que solo puedes ingresar a este animal al habitat al que pertenece.") ;
    }
    this->mapaAnimales.insert(std::make_pair(id, pAnimalTemp));
}

bool Habitat::existeHabitat(string habitat) {
    if(habitat != "desertico" || habitat != "selvatico" || habitat != "polar" || habitat != "acuatico"){
        return true;
    }
    return false;
}