#include <iostream>

using namespace std;

#include "funcion.h"

int main()
{
    cout << "Hello world!" << endl;

    int numEnt;
    int vecEnt[numEnt];
    int valorMinimo;

    cout << "Ingresar un numero entero que indique la cantidad de componentes: " << endl;
    cin >> numEnt;
    cargarVector(vecEnt, numEnt);
    cout << "El valor minimo del contenido de ese vector es: " << endl;
    valorMinimo = buscarMinimo(vecEnt, numEnt);
    cout << valorMinimo << endl;



    return 0;
}
