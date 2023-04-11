//
// Created by laura on 3/04/2023.
//

#include "Habitat.h"

//Constructor
Habitat::Habitat(string tipoHabitat){
    this->tipoH = tipoHabitat;
}

//Permite obtener el nombre del hábitat al que se esté refiriendo
string Habitat::getTipoH() {
    return this->tipoH;
}

//Esta función se encargará de agregar el animal creado a un hábitat siempre y cuando se verifique que el hábitat que se le asignó
//al objeto animal tiene el mismo nombre del hábitat al que trata de ingresarlo
void Habitat::recibirAnimal(int id, Animal *pAnimalTemp, string habitat) {
    if(pAnimalTemp->getHabitat() != habitat){
        cout << "Este animal pertenece al habitat " << pAnimalTemp ->getHabitat() << std::endl;
        throw std::logic_error("Recuerda que solo puedes ingresar a este animal al habitat al que pertenece.") ;
    }
    this->mapaAnimales.insert(std::make_pair(id, pAnimalTemp));
}

//Muestra por consola la información de los animales que pertenecen a un determinado hábitat.
//Se utiliza en el momento en el que se muestran los hábitats disponibles y de esa manera se accede a cada animal
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

//Esta función se utiliza cuando se va a realizar alguna acción en particular a un animal en específico.
//De esta manera, se accede a un animal en específico en función de su nombre
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


