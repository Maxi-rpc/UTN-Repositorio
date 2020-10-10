#include <iostream>

using namespace std;
#include "rlutil.h"
#include "ui.h"
using namespace rlutil;
#include "fecha.h"

Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
void Fecha::setDia(int d){
    dia = d;
}
void Fecha::setMes(int m){
    mes = m;
}
void Fecha::setAnio(int a){
    anio = a;
}
void Fecha::cargarFecha(){
    gotoxy(1,5);
    cout << "Ingresar Fecha: " << endl;
    cout << ".. / .. / .... ";
    rlutil::locate(1,6);
    cin >> dia;
    rlutil::locate(6,6);
    cin >> mes;
    rlutil::locate(11,6);
    cin >> anio;
}
void Fecha::mostrarFecha(){
    cout << "Fecha: " << dia << " / " << mes << " / " << anio << endl;
}
