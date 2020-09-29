#include <iostream>

using namespace std;
#include "tipos.h"


void punto1(){
    musico reg;
    int contar=0;
    FILE *p = fopen("Musicos.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    while(fread(&reg,sizeof reg, 1, p)==1){
        if(reg.instrumento == 2 && reg.claustro == 1){
            contar++;
        }
    }
    fclose(p);
    cout << "La cantidad de musicos docentes que tocan guitarra: "<< contar << endl;
}

void punto2(){
    musico reg;
    puntos2 aux;
    FILE *p = fopen("Musicos.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    while(fread(&reg,sizeof reg, 1, p)==1){
        strcpy(aux.dniMusico, reg.dni); //se copia en - desde
        strcpy(aux.nombreMusico, reg.nombreMusico);
        strcpy(aux.apellidoMusico, reg.apellidoMusico);
        aux.sesiones = contarSesion(reg.dni);
        if(!grabarPunto2(aux)){
            fclose(p);
            cout << "NO SE PUDO GRABAR EL REGISTRO" << endl;
            return;
        }
    }
    fclose(p);
    cout << "ARCHIVO CREADO" << endl;

}

int contarSesion(musico reg){
    int totalSesion=0;
    sesion ses;
    FILE *p = fopen("Sesiones.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    while(fread(&reg,sizeof reg, 1, p)==1){
        if(ses.dniCoordinador == reg.dni){
            totalSesion++;
        }
    }
    fclose(p);
    return totalSesion;
}

bool grabarPunto2(puntos2 aux){
    FILE *p = fopen("punto2.dat", "ab");
    if(p==NULL){
        return false;
    }
    bool grabo = fwrite(&aux, sizeof aux, 1, p);
    fclose(p);
    return grabo;
}
