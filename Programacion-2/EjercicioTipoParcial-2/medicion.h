#ifndef MEDICION_H_INCLUDED
#define MEDICION_H_INCLUDED
#include "fecha.h"

class Medicion {
private:
    char codCiudad [5];
    int visibilidad;
    float temperatura;
    Fecha fechaMed;
public:
    void setCodCiudad(char *c);
    void setVisibilidad(int v);
    void setTemperatura(float t);
    void setFecha(Fecha);
    char *getCodCiudad(){return codCiudad;};
    int getVisibilidad(){return visibilidad;};
    float getTemperatura(){return temperatura;};
    Fecha getFecha(){return fechaMed;};
    bool escribirDisco();
    int leerDisco(int pos);
};

#endif // MEDICION_H_INCLUDED
