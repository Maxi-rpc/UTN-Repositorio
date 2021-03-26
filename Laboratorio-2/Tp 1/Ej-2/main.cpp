#include <iostream>

using namespace std;
#include "funciones.h"
int main()
{
    cout << "Hello world!" << endl;

    int numEnt;
    int vecEnt[numEnt];
    int indValMax;

    cout << "Ingresar numero que indica la cantidad de componentes del vector: " << endl;
    cin >> numEnt;
    cargarVector(vecEnt, numEnt);
    indValMax = buscarIndMax(vecEnt, numEnt);
    cout << "El indice donde se encuentra el valor maximo es: " << endl;
    cout << indValMax;



    return 0;
}
