#include <iostream>

using namespace std;
#include "funcion.h"

int main()
{
    cout << "Hello world!" << endl;
    int numCurso;
    int aula[10] = {0};
    char turno[3] = {0};
    int cant;

    cargarDatos(numCurso, aula[], turno[], cant);


    return 0;
}
