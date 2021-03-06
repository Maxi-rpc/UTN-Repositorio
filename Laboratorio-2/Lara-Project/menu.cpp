#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ui.h"
#include "rlutil.h"
#include "menu.h"
#include "usuario.h"
using namespace rlutil;

// MENU PRINCIPAL
void menuPrincipal()
{

    while(true){
        cls(); // Elimina lo que hay en la pantalla
        //Ingresar el titulo como ejemplo, colores definidos en ui.h
        title("MEN� PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5); //Indica la posicion despues del titulo, 1 = COLUMNA , 5 FILA
        cout << "1) USUARIOS" << endl;
        cout << "2) ENTRENAMIENTOS" << endl;
        cout << "3) REPORTES" << endl;
        cout << "4) CONFIGURACI�N" << endl;
        cout << "------------------" << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                menuUsuarios();
            break;
            case 2:
                menuEntrenamientos();
            break;
            case 3:
                //menuReportes();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                return;
            break;
        }
    }
}

// MENU USUARIO
void menuUsuarios()
{

    while(true){
        cls(); // Elimina lo que hay en la pantalla
        //Ingresar el titulo como ejemplo, colores definidos en ui.h
        title("MEN� USUARIOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5); //Indica la posicion despues del titulo, 1 = COLUMNA , 5 FILA
        cout << "1) NUEVO USUARIO" << endl;
        cout << "2) MODIFICAR USUARIO" << endl;
        cout << "3) LISTAR USUARIO POR ID" << endl;
        cout << "4) LISTAR TODOS LOS USUARIOS" << endl;
        cout << "5) ELIMINAR USUARIO" << endl;
        cout << "------------------" << endl;
        cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                nuevoUsuarios();
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

// MENU ENTRENAMIENTO
void menuEntrenamientos()
{

    while(true){
        cls(); // Elimina lo que hay en la pantalla
        //Ingresar el titulo como ejemplo, colores definidos en ui.h
        title("MEN� USUARIOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5); //Indica la posicion despues del titulo, 1 = COLUMNA , 5 FILA
        cout << "1) NUEVO ENTRENAMIENTO" << endl;
        cout << "2) MODIFICAR ENTRENAMIENTO" << endl;
        cout << "3) LISTAR ENTRENAMIENTO POR ID" << endl;
        cout << "4) LISTAR ENTRENAMIENTO POR IDUSUARIO" << endl;
        cout << "5) LISTAR TODOS LOS ENTRENAMIENTO" << endl;
        cout << "------------------" << endl;
        cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
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

// MENU CONFIGURACION
void menuConfiguracion()
{

    while(true){
        cls(); // Elimina lo que hay en la pantalla
        //Ingresar el titulo como ejemplo, colores definidos en ui.h
        title("MEN� CONFIGURACI�N", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5); //Indica la posicion despues del titulo, 1 = COLUMNA , 5 FILA
        cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
        cout << "2) RESTAURAR COPIA DE SEGURIDAD" << endl;
        cout << "------------------" << endl;
        cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
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
            case 0:
                return;
            break;
        }
    }
}
