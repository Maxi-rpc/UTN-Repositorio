#include <iostream>
using namespace std;
#include <iomanip>
#include <cstring>
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

int main()
{
    initUI(); // INICIA UI, NECESARIO
    while(true){
        cls(); // Elimina lo que hay en la pantalla
        //Ingresar el titulo como ejemplo, colores definidos en ui.h
        title("MENU PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5); //Indica la posicion despues del titulo, 1 = COLUMNA , 5 FILA
        cout << "Bienvenido a la interfaz de Consola, aca 2 ejemplos" << endl;
        cout << "1 -MENSAJE EXITO " << endl;
        cout << "2 -MENSAJE ERROR" << endl;
        cout << "3 -MENSAJE ADVERTENCIA/AVISO" << endl;
        cout << "4 -LISTAR PLANILLA" << endl;
        cout << "------------------" << endl;
        cout << "0 - SALIR" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                // msj se muestra abajo a la izquierda, colores en rlutil.h - texto, color letra, color fondo
                msj("Guardado con exito!", rlutil::WHITE, rlutil::GREEN);
            break;
            case 2:
                // msj se muestra abajo a la izquierda, colores en rlutil.h - texto, color letra, color fondo
                msj("No se pudo guardar", rlutil::WHITE, rlutil::RED);
            break;
            case 3:
                // msj se muestra abajo a la izquierda, colores en rlutil.h - texto, color letra, color fondo
                msj("Mensaje de advertencia", rlutil::WHITE, rlutil::MAGENTA);
            break;
            case 4:
                // lista la tipo planilla
                listarPlanilla();
            break;
            case 0:
                return 0;
            break;
        }
    }
}
