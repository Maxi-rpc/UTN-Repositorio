#include <iostream>

using namespace std;
#include "tipos.h"


void punto1(){
    int instrumento = 1;
    int sesiones = 0;
    cout << "CANTIDAD DE SESIONES DEL INSTRUMENTO: " << endl;
    for(instrumento; instrumento<16; instrumento++){
        sesiones = contarSesionMesAgosto(instrumento);
        cout << instrumento << "," << sesiones << endl;
        cout << "-----------" << endl;
    }
}

void punto2(){
    puntos2 aux;
    musico reg;
    FILE *f = fopen("Musicos.dat", "rb");
    if(f == NULL){
        return -1;
    }
    while(fread(&reg, sizeof(musico), 1, f)){
        strcpy(aux.dniMusico, reg.dni); //se copia en - desde
        strcpy(aux.nombreMusico, reg.nombreMusico);
        strcpy(aux.apellidoMusico, reg.apellidoMusico);
        aux.sesiones = contarSesion(aux.dniMusico);

        if(grabarPunto2(aux)){cout << "ARCHIVO GUARDADO";}
        else{cout << "ERROR AL GUARDAR ARCHIVO";}
    }
    fclose(f);
}

int contarSesionMesAgosto(int instrumento){
    int sesiones=0, mes = 8;
    sesion user;
    FILE *f = fopen("Sesiones.dat", "rb");
    if(f == NULL){
        return -1;
    }
    while(fread(&user, sizeof(sesion), 1, f)){
        if(instrumento == user.instrumento && user.fechaSesion.mes == mes){
            sesiones++;
        }
    }
    fclose(f);
    return sesiones;
}

bool grabarPunto2(puntos2 aux){
    bool guardo;
    FILE *f = fopen("punto2.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(&aux, sizeof(puntos2), 1, f);
    fclose(f);
    return guardo;
}

int contarSesion(int dni){
    int sesiones=0;
    sesion user;
    FILE *f = fopen("Sesiones.dat", "rb");
    if(f == NULL){
        return -1;
    }
    while(fread(&user, sizeof(sesion), 1, f)){
        if(dni == user.dniCoordinador){
            sesiones++;
        }
    }
    fclose(f);
    return sesiones;
}
