//
// Created by laura on 4/04/2023.
//

#include "Sistema.h"
using std::cout;
using std::endl;

//recibe un objeto Habitat creado y verifica si coincide con los que se aceptan como habitats.
//Si no lo hacen, elimina pHabitatTemp y arroja el error y la explicación. De lo contrario, lo agrega al mapa de habitats del sistema
void Sistema::recibirHabitat(int id, Habitat* pHabitatTemp) {
    string habitatTemp = pHabitatTemp->getTipoH();
    if( habitatTemp != "desertico" && habitatTemp != "selvatico" && habitatTemp != "polar" && habitatTemp != "acuatico"){
        delete pHabitatTemp;
        throw std::logic_error("Recuerda que solo puedes ingresar los siguientes tipos de habitat (en minusculas): desertico, selvatico, polar y acuatico");
    }
    this->mapaHabitats.insert(std::make_pair(id, pHabitatTemp));
}

//Agrega un objeto alimento al inventario, recibiendo un identificador y un objeto ya creado con las condiciones requeridas del programa
void Sistema::recibirAlimentos(int id, Alimento *pAlimentoTemp) {
    this->mapaAlimentos.insert(std::make_pair(id, pAlimentoTemp));
}

//Esta función nos ayuda a verificar con un string si el habitat ya se encuentra en el mapa de habitats.
//La importancia de esta función radica en que no puede haber más de un mismo tipo de habitat
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

//Similar a la función que accede al animal. Esta en específico la utilizamos en conjunto para acceder a un elemento de cierto habitat
//de manera inequívoca
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

//Esta función nos entrega el objeto al que hace referencia el string dentro del inventario
Alimento* Sistema::accederAAlimento(string alimento){
    unordered_map<int, Alimento*>::iterator itMap;
    for (itMap = this->mapaAlimentos.begin(); itMap != this->mapaAlimentos.end(); ++itMap) {
        Alimento *pAlimentoTemp = itMap->second;
        if(pAlimentoTemp->getNombreAlimento() == alimento){
            cout << "Accedio al alimento " << alimento << endl;
            return pAlimentoTemp;
        }
    }
}

//Esta función se usa dentro de nuestro programa cuando logramos alimentar a un animal, así el alimento es eliminado del mapa
void Sistema::liberarAlimento(string alimento) {
    unordered_map<int, Alimento *>::iterator itMap;
    for (itMap = this->mapaAlimentos.begin(); itMap != this->mapaAlimentos.end(); ++itMap) {
        Alimento *pAlimentoTemp = itMap->second;
        if (pAlimentoTemp->getNombreAlimento() == alimento) {
            mapaAlimentos.erase(itMap->first);
            cout << "Ha usado el alimento " << alimento;
            break;
        }
    }
}

//Muestra por consola los hábitats y a su vez con el temporal asociado, accede a los mapasa relacionados a cada hábitat
void Sistema::mostrarInfoHabitats() {
    unordered_map<int, Habitat*>::iterator itMap;
    for (itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap) {
        Habitat *pHabitatTemp = itMap->second;
        cout << "\n ***Habitat " << pHabitatTemp->getTipoH() << "***" << endl;
        pHabitatTemp->mostrarMapaAnimales();
    }
}

//Muestra la información de los alimentos, pare ver la disponibilidad de tipos de comida que se tienen en el inventario
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