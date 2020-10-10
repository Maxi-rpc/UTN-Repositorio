#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#include "fecha.h"
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
    Fecha getFechaExamen();
    int getTipo();
};

#endif // EXAMEN_H_INCLUDED
