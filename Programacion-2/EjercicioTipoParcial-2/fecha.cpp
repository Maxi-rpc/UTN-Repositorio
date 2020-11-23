#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "fecha.h"

void Fecha::setFecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
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

