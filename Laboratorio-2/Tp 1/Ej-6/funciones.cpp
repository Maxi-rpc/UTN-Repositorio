#include <iostream>

using namespace std;
#include "funcion.h"

void cargarDatos (int numCurso, int aula[10], char turno[3], int cant){
    int numAula;
    char turnos;

    cout << "Ingresar num de curso: ";
    cin >> numCurso;

    while(numCurso > 0){
        cout << "Ingresar Aula: " << endl;
        cin >> numAula;

            aula[numAula] += numCurso;

        cout << "Ingresar Turno: " << endl;
        cin >> turnos;
        turno[turnos]


        cout << "Ingresar num de curso: ";
        cin >> numCurso;
    }


}
