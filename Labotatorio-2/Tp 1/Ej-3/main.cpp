#include <iostream>

using namespace std;
#include "funciones.h"
int main()
{
    cout << "Hello world!" << endl;

    int tam, vecEnt[tam];
    int numEnt;
    int num, resul;

    cout << "Ingresar tamaño del vector: " << endl;
    cin >> tam;
    cargarVector (vecEnt, tam);
    cout << "Ingresar numero a buscar: " << endl;
    cin >> num;
    resul = buscarPosValor (vecEnt, tam, num);
    cout << "La posicion del vector: "<< resul << endl;

    return 0;
}
