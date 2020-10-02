#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ui.h"
#include "rlutil.h"
#include "menu.h"
using namespace rlutil;

void menuPrincipal()
{

    initUI(); // INICIA UI, NECESARIO
    while(true){
        cls(); // Elimina lo que hay en la pantalla
        //Ingresar el titulo como ejemplo, colores definidos en ui.h
        title("MENÚ PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5); //Indica la posicion despues del titulo, 1 = COLUMNA , 5 FILA
        cout << "1) USUARIOS" << endl;
        cout << "2) ENTRENAMIENTOS" << endl;
        cout << "3) REPORTES" << endl;
        cout << "4) CONFIGURACIÓN" << endl;
        cout << "------------------" << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                //menuUsuarios();
            break;
            case 2:
                //menuEntrenamientos();
            break;
            case 3:
                //menuReportes();
            break;
            case 4:
                //menuConfiguracion();
            break;
            case 0:
                return;
            break;
        }
    }
}

