#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ui.h"
#include "rlutil.h"
#include "menu.h"
#include "usuario.h"
using namespace rlutil;

Usuario nuevoUsuarios(){
    Usuario reg;

    cls();
    title("NUEVO USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    gotoxy(1, 5); //Indica la posicion despues del titulo, 1 = COLUMNA , 5 FILA

    cout << "Ingresar los siguientes datos: " << endl;
    cout << "ID: ";
    cin >> reg.id;
    cout << "Nombre: ";
    cin >> reg.nombre;
    cout << "Apellido: ";
    cin >> reg.apellido;
    cout << "Fecha de Nacimiento: ";
    cin >> reg.nacimiento.dia;
    cin >> reg.nacimiento.mes;
    cin >> reg.nacimiento.anio;
    cout << "Altura: ";
    cin >> reg.altura;
    cout << "Peso: ";
    cin >> reg.peso;
    cout << "Perfil de Actividad A - B - C: ";
    cin >> reg.perfilActividad;
    cout << "Apto Médico 1 - 0: ";
    cin >> reg.aptoMedico;

    reg.estado = true;
}
