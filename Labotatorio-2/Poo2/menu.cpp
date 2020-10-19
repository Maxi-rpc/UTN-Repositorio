#include <iostream>
#include <iomanip>
using namespace std;
#include "rlutil.h"
#include "ui.h"
using namespace rlutil;
#include "menu.h"
#include "examen.h"

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
            menuCargarExamen();
        break;
        case 2:
            //listarExamenes();
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

void menuCargarExamen(){
    Examen e;
    system("cls");
    title("CARGAR EXAMEN", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    gotoxy(1,5);
    e.cargarExamen();
}

/*
void listarExamenes(){
    Examen e;
    int ancho =10; // Determina el ancho de cada columna
    cls();
    title("LISTAR EXÁMENES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    gotoxy(1, 5);
    cout << left;
    cout << setw(ancho) << "FECHA" << setw(ancho) << "LEGAJO" << setw(ancho) << "NOTA" << setw(ancho) << "TIPO";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    for(int i = 0; i<2; i++){
        cout << setw(ancho) << e.fechaExamen.getDia()<<"/"<<e.fechaExamen.getMes()<<"/"<<e.fechaExamen.getAnio;
        cout << setw(ancho) << e.getLegajo();
        cout << setw(ancho) << e.getNota();
        cout << setw(ancho) << e.getTipo();
        cout << endl << "----------------------------------------------------------------------------" << endl;
    }
    msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
    return;
}
*/
