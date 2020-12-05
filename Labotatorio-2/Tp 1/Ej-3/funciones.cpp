#include <iostream>

using namespace std;
#include "funciones.h"

void cargarVector (int vecEnt[], int tam) {
    int i;
    for (i=0; i < tam; i++){
        cout << "Ingresa un numero: " << endl;
        cin >> vecEnt[i];
    }
    return;
}
int buscarPosValor (int vecEnt[], int tam, int num) {
    int i, indice;
    for (i=0; i < tam; i++){
        if (vecEnt[i] == num){
            indice = i;
        } else {
            indice = -1;
        }
    }
    return indice;
}
