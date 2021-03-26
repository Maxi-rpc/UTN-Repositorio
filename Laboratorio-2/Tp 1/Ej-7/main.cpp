#include <iostream>

using namespace std;
#include "funcion.h"

int main()
{
    cout << "Hello world!" << endl;

    // 50 socios - num entre 100 y 149 - cuotas 6
    int socio, cuota;
    bool pagos[50][6] = {};

    cout << "Ingrese Num de Socio: ";
    cin >> socio;

    while (socio >= 100 && socio <= 149){
        cout << "Ingrese Num de Cuota: ";
        cin >> cuota;

        pagos[socio - 100][cuota -1] = true;

        cout << "Ingrese Num de Socio: ";
        cin >> socio;
    }
    puntoA(pagos, 50);
    puntoB(pagos, 50);
    puntoC(pagos, 50);


    return 0;
}
