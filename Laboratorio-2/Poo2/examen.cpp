#include <iostream>

using namespace std;
#include "rlutil.h"
#include "ui.h"
using namespace rlutil;
#include "examen.h"

// SE CREAN COMPORTAMIENTOS GET

int Examen::getLegajo(){
    return legajo;
}

float Examen::getNota(){
    return nota;
}

int Examen::getTipo(){
    return tipo;
}

Fecha Examen::getFechaExamen(){
    return fechaExamen;
}

// SE CREAN COMPORTAMIENTOS SET
void Examen::setLegajo(int l){
    legajo = l;
}

void Examen::setNota(float n){
    nota = n;
}

void Examen::setTipo(int t){
    tipo = t;
}
void Examen::setFecha(Fecha f){
    fechaExamen = f;
}

void Examen::cargarExamen(){
    cout << "Ingresar Legajo: ";
    cin >> legajo;
    cout << "Ingresar Nota: ";
    cin >> nota;
    cout << "Ingresar Tipo: ";
    cin >> tipo;
    fechaExamen.cargarFecha();
}

void Examen::mostrarExamen(){
    cout << "Legajo: " << legajo << endl;
    cout << "Nota: " << nota << endl;
    cout << "Tipo: " << tipo << endl;
    fechaExamen.mostrarFecha();
}

bool Examen::grabarEnDisco(int pos){
    bool guardo;
    FILE *f;
    if(pos == -1){
        f = fopen("datos/archivo.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar.";
            return false;
        }
    }
    else{
        f = fopen("datos/archivo.dat", "rb+");
        if(f == NULL){
            cout << "No se puede guardar.";
            return false;
        }
        fseek(f, pos * sizeof(Examen), 0);
    }
    guardo = fwrite(this, sizeof(Examen), 1, f);
    fclose(f);
    return guardo;
}

bool Examen::leerDeDisco(int pos){
    bool leer;
    FILE *f = fopen("datos/archivo.dat", "rb");

    if(f == NULL){
        cout << "No se puede leer.";
        return false;
    }
    fseek(f, pos * sizeof(Examen), 0);
    leer = fread(this, sizeof(Examen), 1, f);
    fclose(f);
    return leer;
}
