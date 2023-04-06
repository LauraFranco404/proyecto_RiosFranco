#include <iostream>

using std::cout;
using std::cin;
using std::getline;
using std::endl;

#include "Sistema.h"

void primeraOpcion(Sistema* sistema, int idTemp){
    string tipoHabitatTemp;

    cout << "Bienvenido, usuario." << endl;
    cout << "A continuacion recibiremos la informacion del habitat." << endl;
    cout << "Ingrese el tipo de habitat: ";
    cin >> tipoHabitatTemp;
    if(sistema->estaHabitat(tipoHabitatTemp) == false){
        Habitat *pHabitatTemp = new Habitat(tipoHabitatTemp);
        try{
            sistema->recibirHabitat(idTemp, pHabitatTemp);
        }catch(std::logic_error ex){
            cout << "Se presento un error: " << ex.what() << endl;
        }
    }
    cin >> tipoHabitatTemp;
}

void segundaOpcion(Sistema* sistema, int idTemp){

    string nombreTemp;
    int edadTemp;
    string especieTemp;
    string tipoATemp;
    int horasSTemp;
    int tiempoJuegoTemp;
    bool estadoSaludTemp;
    string habitatTemp;

    cout << "Bienvenido, usuario." << endl;
    cout << "A continuacion recibiremos la informacion del animal que desea agregar al sistema." << endl;
    cout << "Ingrese el nombre: ";
    cin >> nombreTemp;
    cout << "Ingrese la edad: ";
    cin >> edadTemp;
    cout << "Ingrese la especie: ";
    cin >> especieTemp;
    cout << "Ingrese el tipo de alimentacion: ";
    cin >> tipoATemp;
    cout << "Ingrese las horas de sueño recomendadas: ";
    cin >> horasSTemp;
    cout << "Ingrese las horas de juego recomendadas: ";
    cin >> tiempoJuegoTemp;
    cout << "Ingrese el estado de salud (1 si esta saludable y 0 si no lo esta): ";
    cin >> estadoSaludTemp;
    cout << "Ingrese el habitat al que pertenece (desertico, selvatico polar o acuatico): ";
    cin >> habitatTemp;


}


void mostrarMenu(Sistema* sistema){
    int opcion;
    do{
        cout << "\n****Bienvenido al zoologico RF****\n";
        cout << "1. Agregar un habitat." << endl;
    }while (opcion != 0);
}



int main() {
    //Sistema* pSistema = new Sistema();
    //mostrarMenu(pSistema);
    return 0;
}

