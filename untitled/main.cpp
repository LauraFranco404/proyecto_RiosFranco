#include <iostream>

std::string bienvenida(std::string diaSemana) {
    //Si se ingresa el dia viernes, sábado o domingo no deberia imprimirse
    if(diaSemana == "viernes" || diaSemana == "sabado" || diaSemana == "domingo"){
        throw std::logic_error("Amamos los viernes y fines de semana. That doesn't make much sense.");
    }
    return "Oh, por dios. Apenas es " + diaSemana;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    //std::cout <<bienvenida("viernes");
    //std::cout <<bienvenida("sabado");
    try{
        bienvenida("lunes");
    }catch(const std::logic_error ex){
        std::cout << "Se presento un error: " << ex.what() << std::endl;
    }
    std::cout <<bienvenida("lunes");

    return 0;
}
