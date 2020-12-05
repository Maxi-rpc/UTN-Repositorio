#include <iostream>

using namespace std;

#include "funcion.h"

void cargarVector (int vecEnt[], int numEnt) {
    int num, i;
    for (i=0; i<numEnt; i++){
        cout << "Ingresar un numero: "<< endl;
        cin >> num;
        vecEnt[i] = num;
    }
    return;
}

int buscarMinimo (int vecEnt[], int numEnt) {
    int i, minimo=0;
    for (i=1; i<numEnt; i++){
        if (vecEnt[i] < vecEnt[minimo]) {
            minimo = i;
        }
    }
    return vecEnt[minimo];
}

