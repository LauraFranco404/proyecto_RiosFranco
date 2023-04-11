#include <iostream>

using std::cout;
using std::cin;
using std::getline;
using std::endl;

#include "Sistema.h"

/*
 * La función primeraOpcion se encarga de utilizar la función definida para recibir un habitat e ingresarlo al sistema del zoológico
 * Recibe como parámetro un apuntador que dirige al sistema y un índice para construir el mapa de hábitats
*/
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


/*
 * La función segundaOpcion se encarga de utilizar la función definida para ingresar un animal a un habitat en específico.
 * Recibe como parámetro un apuntador que dirige al sistema y un índice para construir el mapa de animales que a su vez estará dentro de un objeto perteneciente al hábitat.
*/
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
        Animal *pAnimalTemp = new Animal(nombreTemp, edadTemp, especieTemp, tipoATemp, horasSTemp, tiempoJuegoTemp, estadoSaludTemp, habitatTemp,false);
        Habitat *pHabitatTemp = sistema->accederAHabitat(habitatTemp);
        pHabitatTemp->recibirAnimal(idTempA, pAnimalTemp, habitatTemp);
    }
}


/*
 * La función cuartaOpcion se encarga de utilizar la función definida para recibir un alimento e ingresarlo al sistema del zoológico
 * Recibe como parámetro un apuntador que dirige al sistema y un índice para construir el mapa de alimentos
 *
*/
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


/*
 * La función sextaOpcion se encarga de utilizar la función definida para alimentar un animal.
    De esta manera la función accede a los alimentos disponibles en el "inventario" del zoológico y toma uno para dárselo
    a un animal que pueda consumirlo según su dieta
 * Recibe como parámetro un apuntador que dirige al sistema, pues este contiene los animales y alimentos disponibles
 */
void sextaOpcion(Sistema* sistema) {
    string nombreH;
    string nombreA;
    string tipoA;
    int catAl;
    string nombreAl;
    int categoria;

    cout << "Bienvenido, usuario." << endl;
    cout << "A continuacion alimentara a un animal: " << endl;
    sistema->mostrarInfoHabitats();
    cout << "Digite el habitat del animal que desea alimentar:";
    cin >> nombreH;
    Habitat *pHabitatTemp = sistema->accederAHabitat(nombreH);
    cout << "Ahora digite el nombre del animal al que desea alimentar:";
    cin >> nombreA;
    Animal *pAnimalTemp = pHabitatTemp->accederAAnimal(nombreA);
    tipoA = pAnimalTemp->getTipoAlimentacion();
    cout << "*Alimentos disponibles*";
    sistema->mostrarInfoAlimentos();
    cout << "Ingrese el nombre del alimento que desea dar al animal:";
    cin >> nombreAl;
    Alimento *pAlimentoTemp = sistema->accederAAlimento(nombreAl);
    catAl = pAlimentoTemp->getNumCategoriaAlimento();
    if (catAl == 0 && tipoA == "carnivora") {
        cout << "Dieta carnivora" << endl;
        sistema->liberarAlimento(pAlimentoTemp->getNombreAlimento());
    }
    else if (catAl == 1 && tipoA == "hervibora") {
        cout << "Dieta hervibora" << endl;
        sistema->liberarAlimento(pAlimentoTemp->getNombreAlimento());
    }
    else if(catAl == 2 && tipoA == "omnivora"){
        cout << "Dieta omnivora" << endl;
        sistema->liberarAlimento(pAlimentoTemp->getNombreAlimento());
    }
    else{
        cout << "Lo lamento, no puedes alimentar a este animal porque no le corresponde esa dieta." << endl;
    }
}


/*
 * Esta funcion accede a un animal y cambia el booleano que determina si el animal ha jugado o no.
 * Así, según el momento del día, se cambiará el estado del animal a un animal que ya jugó
 */
void septimaOpcion(Sistema* sistema){
    string nombreH;
    string nombreA;

    cout << "Bienvenido, usuario." << endl;
    cout << "A continuacion jugara con un animal: " << endl;
    sistema->mostrarInfoHabitats();
    cout << "Digite el habitat del animal con el que desea jugar:";
    cin >> nombreH;
    Habitat *pHabitatTemp = sistema->accederAHabitat(nombreH);
    cout << "Ahora digite el nombre del animal con el que desea jugar:";
    cin >> nombreA;
    Animal *pAnimalTemp = pHabitatTemp->accederAAnimal(nombreA);
    cout << pAnimalTemp->getNombre() << " "  << pAnimalTemp->verSiHaJugado() << endl;
    pAnimalTemp->setHaJugado(true);
}


/*
 * La función octavaOpcion se encarga de llevar a dormir a un animal teniendo en cuenta algunos puntos.
 * Esta función accede a la información del animal para verificar cuántas horas se le asignan de sueño. En caso de que estas
 * sobrepasen o no sean suficientes, no permitirá llevar al animal a dormir
 * Recibe como parámetro un apuntador que dirige al sistema y un índice para construir el mapa de alimentos
 */
void octavaOpcion(Sistema* sistema){
    string nombreH;
    string nombreA;
    int horasS;
    int horasDadas;
    cout << "Bienvenido, usuario." << endl;
    cout << "A continuacion llevara a dormir a un animal: " << endl;
    sistema->mostrarInfoHabitats();
    cout << "Digite el habitat del animal que llevar a dormir:";
    cin >> nombreH;
    Habitat *pHabitatTemp = sistema->accederAHabitat(nombreH);
    cout << "Ahora digite el nombre del animal al que llevara a dormir:";
    cin >> nombreA;
    Animal *pAnimalTemp = pHabitatTemp->accederAAnimal(nombreA);
    horasS = pAnimalTemp->getHorasSuenio();
    cout << "El animal debe dormir " << horasS << " horas" << endl;
    cout << "Ingrese el numero de horas que desea darle al animal para dormir:";
    cin >> horasDadas;
    while(horasS != horasDadas) {
        if(horasDadas < horasS){
            cout << "Ou, ten cuidado. No es suficiente tiempo para dormir" << endl;
        }
        else{
            cout << "Ou, ten cuidado. Es demasiado tiempo para dormir" << endl;
        }
        cout << "Recuerda que el animal debe dormir " << horasS << " horas" << endl;
        cout << "Ingrese el numero de horas que desea darle al animal para dormir:";
        cin >> horasDadas;

    }
    if (horasS  == horasDadas) {
        cout << pAnimalTemp->getNombre() << " se va a dormir ahora." << endl;
    }



}


/*
 * La función mostrarMenu se encarga de manejar aquello que se trabajará en el sistema que se creó.
 * Contiene las funcionalidades del proyecto y muestra al usuario aquello que puede hacer.
 */
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
        cout << "5. Mostrar alimentos en el inventario." << endl;
        cout << "6. Alimentar a un animal." << endl;
        cout << "7. Jugar con un animal." << endl;
        cout << "8. Enviar a dormir a un animal" << endl;
        cout << "0. Salir." << endl;
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
            case 6:
                sextaOpcion(sistema);
                break;
            case 7:
                septimaOpcion(sistema);
                break;
            case 8:
                octavaOpcion(sistema);
                break;
        }
    }while (opcion != 0);
    cout << "****Zoologico cerrado****" << endl;
}



int main() {
    Sistema* pSistema = new Sistema();
    mostrarMenu(pSistema);
    delete pSistema;
    return 0;
}

