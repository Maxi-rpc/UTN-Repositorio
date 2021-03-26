#include <iostream>

using namespace std;
#include "funcion.h"

int main()
{
    cout << "Hello world!" << endl;

    float recaudacion[31][3]={0};

    cargarDatos(recaudacion);

    ///Punto A
    puntoA(recaudacion);
    ///PUNTO B
    puntoB(recaudacion);
    ///PUNTO C
    puntoC(recaudacion);

    return 0;
}
