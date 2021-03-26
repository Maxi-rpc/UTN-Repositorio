#include <iostream>

using namespace std;
#include "funcion.h"

void cargarDatos(float m[][3]){

    int pais, dia;
    float monto;

    cout << "Numero de pais: " <<endl;
    cin >> pais;

    while(pais != -1){
        cout << "Dia: " <<endl;
        cin >> dia;
        cout << "Monto: " <<endl;
        cin >> monto;

        m[dia-1][pais-1] += monto;

        cout << "Numero de pais: " <<endl;
        cin >> pais;
    }

}

void puntoA(float m[][3]){
    int i, j;
    for(i=0; i<3; i++){
        cout << "Pais " << i+1 << endl;
        for(j=0; j<31; j++){
            if(m[j][i] != 0){
                cout << "Dia " << j+1 << ": $";
                cout << m[j][i] << endl;

            }
        }
        cout << endl;
    }
}

void puntoB(float m[][3]){
    int cant, i, j;

    for(i=0; i<3; i++){
        cant=0;
        for(j=0; j<31; j++){
            if(m[j][i] == 0){
                cant++;
            }
        }
        cout << "Pais " << i+1 << " - Dias sin recaudacion: " << cant << endl;
    }
}

void puntoC(float m[][3]){
    int cant, i, j;
    bool recaudo;

    for(i=0; i<31; i++){
        recaudo = false;
        for(j=0; j<3; j++){
            if(m[i][j] > 0){
                recaudo = true;
            }
        }
        if(recaudo == false){
            cout << i+1 << " ";
        }
    }

}
