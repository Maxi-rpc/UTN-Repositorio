#include <iostream>

using namespace std;

#include "funciones.h"

void cargarVector( int vecEnt[], int numEnt){
    int i, num;
    for (i=0; i < numEnt; i++){
        cout << "Ingresar numero: " << endl;
        cin >> num;
        vecEnt[i] = num;
    }
}

int buscarIndMax(int vecEnt[], int numEnt){
    int i, indMax=0;
    for (i=1; i < numEnt; i++){
        if(vecEnt[i] > vecEnt[indMax]){
            indMax = i;
        }
    }
    return indMax;
}
