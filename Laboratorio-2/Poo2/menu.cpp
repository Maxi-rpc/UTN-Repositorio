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
      cout << "> ";
      cin>>opc;
      system("cls");
      switch(opc){
        case 1:
            menuCargarExamen();
        break;
        case 2:
            listarExamenes();
        break;
        case 3:
            menuReportes1();
        break;
        case 4:
            menuReportes2();
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
    title("CARGAR EXAMEN");
    gotoxy(1,5);

    e.cargarExamen();
    if(e.grabarEnDisco()){
        msj("GRABO en disco", rlutil::WHITE, rlutil::GREEN);
    }
    else{
        msj("NO GRABO en disco", rlutil::WHITE, rlutil::RED);
    }
}


void listarExamenes(){
    Examen e;

    string tipos[3]{"Parcial","Trabajo Práctico","Final"};

    int i=0;
    int ancho =10; // Determina el ancho de cada columna
    cls();
    title("LISTAR EXÁMENES");
    gotoxy(1, 5);
    cout << left;
    cout << setw(12) << "FECHA" << setw(ancho) << "LEGAJO" << setw(ancho) << "NOTA" << setw(ancho) << "TIPO";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    while(e.leerDeDisco(i++)){
        cout << setw(2) << e.getFechaExamen().getDia();
        cout << "/";
        cout << setw(2) << e.getFechaExamen().getMes();
        cout << "/";
        cout << setw(6) << e.getFechaExamen().getAnio();

        cout << setw(ancho) << e.getLegajo();
        cout << setw(ancho) << e.getNota();
        cout << setw(ancho) << tipos[e.getTipo()-1];
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
    return;
}

void menuReportes1(){
    Examen e;

    string mes[12]{"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

    int anio;
    int i=0;
    int ancho=20; // Determina el ancho de cada columna
    cls();
    title("REPORTE MENSUAL");
    gotoxy(1, 5);
    cout << left;
    cout << "Ingresar Año ";
    cout << " > ";
    cin >> anio;

    cls();
    titleInt("REPORTE MENSUAL AÑO", anio);
    gotoxy(1, 5);
    cout << left;

    int cant[12]={};
    while(e.leerDeDisco(i++)){
        if(e.getFechaExamen().getAnio() == anio){
            if(e.getTipo() != 2){
                cant[e.getFechaExamen().getMes()-1]++;
            }
        }
    }

    cout << setw(ancho) << "MES" << setw(ancho) << "CANTIDAD";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    for(int v=0; v<12; v++){
        cout << setw(ancho) << mes[v];
        cout << setw(ancho) << cant[v];
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
    return;
}

void menuReportes2(){
    Examen e;

    string tipos[3]{"Parcial","Trabajo Práctico","Final"};

    cls();
    title("REPORTE PROMEDIO DE NOTAS POR TIPO");
    gotoxy(1, 5);
    cout << left;

    int i=0;
    float prom[3]={};
    float suma[3]={};
    int cant[3]={};
    while(e.leerDeDisco(i++)){
        for(int x=0; x<3; x++){
            if(e.getTipo() == x+1){
                suma[x] += e.getNota();
                cant[x]++;
            }
        }
    }

    for(int z=0; z<3; z++){
        prom[z] = suma[z] / cant[z];
    }

    int ancho=20; // Determina el ancho de cada columna
    cout << setw(ancho) << "TIPO DE EXAMEN" << setw(ancho) << "PROMEDIO";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    for(int v=0; v<3; v++){
        cout << setw(ancho) << tipos[v];
        cout << setw(ancho) << prom[v];
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
    return;
}
