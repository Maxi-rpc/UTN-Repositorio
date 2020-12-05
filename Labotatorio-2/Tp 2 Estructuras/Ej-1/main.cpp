#include <iostream>

using namespace std;
#include "strPelicula.h"

int main()
{
    cout << ".....Estructuras....." << endl;
    const int tam = 2;
    Pelicula nuevap[tam]; /// Punto 1

    cargar_lista_pelicula(nuevap, tam); /// Punto 2
    cout << endl;
    mostrar_lista_pelicula(nuevap, tam); /// Punto 3




    return 0;
}
