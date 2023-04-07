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

void Habitat::mostrarMapaAnimales() {
    unordered_map<int, Animal*>::iterator itMap;
    for (itMap = this->mapaAnimales.begin(); itMap != this->mapaAnimales.end(); ++itMap){
        Animal* pAnimalTemp = itMap->second;
        cout << "\n***Animal***" << endl;
        cout << "Nombre: " << pAnimalTemp->getNombre() << endl;
        cout << "Edad: " << pAnimalTemp->getEdad() << endl;
        cout << "Especie: " << pAnimalTemp->getEspecie() << endl;
        cout << "Tipo de alimentacion: " << pAnimalTemp->getTipoAlimentacion() << endl;
        cout << "Horas de suenio: " << pAnimalTemp->getHorasSuenio() << endl;
        cout << "Horas de juego: " << pAnimalTemp->getTiempoJuego() << endl;
        cout << "Estado de salud: " << pAnimalTemp->getEstadoSalud() << endl;
        cout << "Juego en el dia: " << pAnimalTemp->verSiHaJugado() << endl;
    }
}

Animal* Habitat::accederAAnimal(string nombre){
    unordered_map<int, Animal*>::iterator itMap;
    for (itMap = this->mapaAnimales.begin(); itMap != this->mapaAnimales.end(); ++itMap){
        Animal* pAnimalTemp = itMap->second;
        if(pAnimalTemp->getNombre() == nombre){
            cout << "Accedio a " << nombre << endl;
            return pAnimalTemp;
        }
    }
}


