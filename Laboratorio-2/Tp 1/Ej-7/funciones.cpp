#include <iostream>

using namespace std;
#include "funcion.h"

void puntoA(bool mat[][6], int tam){
    cout << "    1 2 3 4 5 6"<< endl;
    for (int f=0; f<tam; f++){
            cout << f +100 << " ";
        for (int c=0; c<6; c++){
            if(mat[f][c]){
                cout << "X ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void puntoB(bool mat[][6], int tam){
    bool todofalso = true;
    cout << endl;
    for (int f=0; f<tam; f++){
        todofalso = true;
        for (int c=0; c<6; c++){
            if(mat[f][c]){
                todofalso = false;
            }
        }
        if(todofalso){
            cout << f +100 << endl;
        }
    }
}

void puntoC(bool mat[][6], int tam){
    int total = 100;
    float porcen = 0;
    int cont;
    cout << endl;
    for (int c=0; c<6; c++){
        cont = 0;
        for (int f=0; f<tam; f++){
            if(mat[f][c]){
                cont++;
            }
        }
        porcen = (cont * total)/tam;
        cout << "Cuota N " << c+1 << ": " <<  porcen << "%" << endl;
    }
}
