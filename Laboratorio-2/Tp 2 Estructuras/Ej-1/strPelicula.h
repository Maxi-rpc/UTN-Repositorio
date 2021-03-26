#ifndef STRPELICULA_H_INCLUDED
#define STRPELICULA_H_INCLUDED

struct Pelicula {
    char titulo[50];
    float costo;
    float recaudacion;
    short idPais;
    float rentabilidad;
};

Pelicula cargar_pelicula(Pelicula *, int);
void mostrar_pelicula(Pelicula);

void cargar_lista_pelicula(Pelicula *, int);
void mostrar_lista_pelicula(Pelicula *, int);

bool validarNeg(float);
bool validarId(short);
float calcular_rentabilidad(float, float);




#endif // STRPELICULA_H_INCLUDED
