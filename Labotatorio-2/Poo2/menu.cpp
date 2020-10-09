#include <iostream>

using namespace std;
#include "rlutil.h"
#include "ui.h"
using namespace rlutil;
#include "menu.h"

void menuPrincipal(){
    initUI();
    int opc;
    while(true){
      system("cls");
      title("MENÚ PRINCIPAL POO-2", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
      gotoxy(1,5);
      cout << "-------------------------" << endl;
      cout << "1) CARGAR EXAMEN" << endl;
      cout << "2) LISTAR TODOS LOS EXÁMENES" << endl;
      cout << "3) REPORTE 1: EXÁMENES POR MES" << endl;
      cout << "4) REPORTE 2: PROMEDIO DE NOTAS POR TIPO" << endl;
      cout << "-------------------------" << endl;
      cout << "0) SALIR" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1:
            //menuEmpresas();
        break;
        case 2:
            //menuViajes();
        break;
        case 3:
            //menuReportes();
        break;
        case 0:
            return;
        break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
        break;
      }
      system("pause");
    }
    return;
}
