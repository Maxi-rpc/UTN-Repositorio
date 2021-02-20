#include <iostream>
using namespace std;
#include <cstring>
#include "ejTipoParcial_2_Rutas.h"


int main()
{
    cout << "Hello world! Practica para Final de Prog-2" << endl;
    cout << endl;
    cout << "1) Ejercicio tipo parcial 2 - RUTAS" << endl;

    int opc;
    cout << "> ";
    cin >> opc;
    system("cls");
    switch(opc){
    case 1:
        ejTipoParcial_2_Rutas();
        break;
    }

    return 0;
}
