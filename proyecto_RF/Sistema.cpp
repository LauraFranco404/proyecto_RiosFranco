//
// Created by laura on 4/04/2023.
//

#include "Sistema.h"
using std::cout;
using std::endl;


void Sistema::recibirHabitat(int id, Habitat* pHabitatTemp) {
    string habitatTemp = pHabitatTemp->getTipoH();
    if( habitatTemp != "desertico" && habitatTemp != "selvatico" && habitatTemp != "polar" && habitatTemp != "acuatico"){
        throw std::logic_error("Recuerda que solo puedes ingresar los siguientes tipos de habitat (en minusculas): desertico, selvatico, polar y acuatico\n") ;
    }
    this->mapaHabitats.insert(std::make_pair(id, pHabitatTemp));
}

bool Sistema::estaHabitat(string tipoHabitat) {
    unordered_map<int, Habitat*>::iterator itMap;
    for (itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap){
        Habitat* pHabitat = itMap->second;
        if(pHabitat->getTipoH() == tipoHabitat){
            return true;
        }
    }
    return false;
}

Sistema::~Sistema() {
    cout << "\n Gracias por preferirnos!" << endl;
}