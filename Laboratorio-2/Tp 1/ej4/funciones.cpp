#include <iostream>

using namespace std;
#include "funcion.h"

void cargarVector(int vec[], int tam){
    int i;
    bool rep=false;
    while(rep == false && i<tam){
         i++;
        cout << "Ingresar numero: "<< endl;
        cin >> vec[i];
        verificarVector(vec, tam);
    }

}


bool verificarVector(int vec[], int tam){
    int i, x, ind;
    bool rep = false;
    for(i=0; i<tam; i++){
        ind=i;
        for(x=1; x<tam; x++){
            if(vec[i] == vec[x]){
                rep = true;
            }
        }
    }
    return true;
}
