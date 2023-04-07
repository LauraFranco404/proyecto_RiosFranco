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

void Sistema::recibirAlimentos(int id, Alimento *pAlimentoTemp) {
    this->mapaAlimentos.insert(std::make_pair(id, pAlimentoTemp));
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

Habitat* Sistema::accederAHabitat(string tipoHabitat) {
    unordered_map<int, Habitat*>::iterator itMap;
    for (itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap) {
        Habitat *pHabitatTemp = itMap->second;
        if (pHabitatTemp->getTipoH() == tipoHabitat) {
            cout << "Accedio al habitat "<< tipoHabitat << endl;
            return pHabitatTemp;
        }
    }
}



void Sistema::mostrarInfoHabitats() {
    unordered_map<int, Habitat*>::iterator itMap;
    for (itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap) {
        Habitat *pHabitatTemp = itMap->second;
        cout << "\n ***Habitat " << pHabitatTemp->getTipoH() << "***" << endl;
        pHabitatTemp->mostrarMapaAnimales();
    }
}

void Sistema::mostrarInfoAlimentos(){
    unordered_map<int, Alimento*>::iterator itMap;
    for (itMap = this->mapaAlimentos.begin(); itMap != this->mapaAlimentos.end(); ++itMap) {
        Alimento *pAlimentoTemp = itMap->second;
        cout << "\n ***Alimento*** " << endl;
        cout << "Nombre: " << pAlimentoTemp->getNombreAlimento() << endl;
        cout << "Categoria: " << pAlimentoTemp->getCategoriaAlimento() << endl;
    }
}

Sistema::~Sistema() {
    cout << "\n Gracias por preferirnos!" << endl;
}