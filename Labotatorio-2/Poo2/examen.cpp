#include <iostream>

using namespace std;
#include "examen.h"

// SE CREA OBJETO / CLASE EXAMEN
class Examen{
private:
    int legajo;
    float nota;
    Fecha fechaExamen;
    int tipo; // 1- Parcial , 2- Trabajo Practico, 3- Final

public:
    int getLegajo();
    float getNota();

};

// SE CREAN COMPORTAMIENTOS GET

int Examen::getLegajo(){
    return legajo;
}

int Examen::getNota(){
    return nota;
}
