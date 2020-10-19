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
    int getTipo();
    Fecha getFechaExamen();
    void setLegajo(int l);
    void setNota(float n);
    void setTipo(int t);
    void setFecha(Fecha);
    void cargarExamen();
    void mostrarExamen();
    bool grabarEnDisco(int pos);
};

#endif // EXAMEN_H_INCLUDED
