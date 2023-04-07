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
    else{
        cout << "Lo siento. Este habitat ya existe :c" << endl;
    }
}

void segundaOpcion(Sistema* sistema, int idTempA){

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
    cout << "Ingrese el nombre:";
    cin >> nombreTemp;
    cout << "Ingrese la edad (entre 0 y 100 anios):";
    cin >> edadTemp;
    while (edadTemp < 0 || edadTemp > 100){
        cout << "Por favor verifique que la edad que esta ingresando se encuentra entre los 0 y 100 anios" << endl;
        cout << "Ingrese la edad:";
        cin >> edadTemp;
    }
    cout << "Ingrese la especie:";
    cin >> especieTemp;
    cout << "Ingrese el tipo de dieta(carnivora, omnivora o hervibora):";
    cin >> tipoATemp;
    while(tipoATemp != "carnivora" && tipoATemp != "omnivora" && tipoATemp != "hervibora"){
        cout << "Por favor verifique que el tipo de dieta que esta ingresando corresponde a una dieta disponible (carnivora, omnivora o hervibora)" << endl;
        cout << "Ingrese el tipo de dieta:";
        cin >> tipoATemp;
    }
    cout << "Ingrese las horas de suenio recomendadas:";
    cin >> horasSTemp;
    cout << "Ingrese las horas de juego recomendadas:";
    cin >> tiempoJuegoTemp;
    cout << "Ingrese el estado de salud (1 si esta saludable y 0 si no lo esta):";
    cin >> estadoSaludTemp;
    cout << "Ingrese el habitat al que pertenece (desertico, selvatico polar o acuatico):";
    cin >> habitatTemp;
    while(habitatTemp != "desertico" && habitatTemp != "selvatico" && habitatTemp != "polar" && habitatTemp != "acuatico"){
        cout << "Por favor verifique que el habitat que esta ingresando corresponde a los habitats existentes en el zoologico (desertico, selvatico polar o acuatico)" << endl;
        cout << "Ingrese el habitat al que pertenece:";
        cin >> habitatTemp;
    }
    while(sistema->estaHabitat(habitatTemp) == false){
        cout << "Lo lamento, este habitat no esta creado." << endl;
        cout << "Por favor ingrese un habitat existente." << endl;
        cin >> habitatTemp;
    }
    if(sistema->estaHabitat(habitatTemp) == true){
        Animal *pAnimalTemp = new Animal(nombreTemp, edadTemp, especieTemp, tipoATemp, horasSTemp, tiempoJuegoTemp, estadoSaludTemp, habitatTemp);
        Habitat *pHabitatTemp = sistema->accederAHabitat(habitatTemp);
        pHabitatTemp->recibirAnimal(idTempA, pAnimalTemp, habitatTemp);
    }
}

void cuartaOpcion(Sistema* sistema, int idTempAl){
    string nombreA;
    int categoriaA;

    cout << "Bienvenido, usuario." << endl;
    cout << "A continuacion recibiremos la informacion del alimento que desea agregar al sistema." << endl;
    cout << "Ingrese el nombre del alimento que desea agregar:";
    cin >> nombreA;
    cout << "Ahora ingrese la categoria en la que se encuentra el alimento (0 apto para carnivoros, 1 apto para herviboros y 2 apto para omnivoros):";
    cin >> categoriaA;
    while(categoriaA != 0 && categoriaA != 1 && categoriaA != 2){
        cout << "Por favor verifique que la categoria que esta ingresando corresponde a las categorias existentes en el zoologico (0 apto para carnivoros, 1 apto para herviboros y 2 apto para omnivoros)" << endl;
        cout << "Ingrese la categoria en la que se encuentra el alimento:";
        cin >> categoriaA;
    }
    Alimento *pAlimentoTemp = new Alimento(nombreA, categoriaA);
    sistema->recibirAlimentos(idTempAl, pAlimentoTemp);
    cout << "El alimento se ha agregado exitosamente" << endl;
}

void mostrarMenu(Sistema* sistema){
    int opcion;
    int idTemp = 1;
    int idTempA = 1;
    int idTempAl = 1;
    do{
        cout << "\n****Bienvenido al zoologico RF****\n";
        cout << "1. Agregar un habitat." << endl;
        cout << "2. Agregar un animal al zoologico." << endl;
        cout << "3. Mostrar habitats y animales disponibles" << endl;
        cout << "4. Ingresar un alimento al inventario." << endl;
        cout << "5. Mostrar alimentos en el inventario" << endl;
        cin >> opcion;
        switch(opcion){
            case 1:
                primeraOpcion(sistema, idTemp);
                idTemp++;
                break;
            case 2:
                segundaOpcion(sistema, idTempA);
                idTempA++;
                break;
            case 3:
                sistema->mostrarInfoHabitats();
                break;
            case 4:
                cuartaOpcion(sistema, idTempAl);
                idTempAl++;
                break;
            case 5:
                sistema->mostrarInfoAlimentos();
                break;
        }
    }while (opcion != 0);
}



int main() {
    Sistema* pSistema = new Sistema();
    mostrarMenu(pSistema);
    return 0;
}

