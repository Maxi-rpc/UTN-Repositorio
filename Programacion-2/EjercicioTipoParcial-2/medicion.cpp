#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "medicion.h"

void Medicion::setCodCiudad(char *c){
    strcpy(codCiudad,c);
}

void Medicion::setVisibilidad(int v){
    visibilidad = v;
}

void Medicion::setTemperatura(float t){
    temperatura = t;
}

void Medicion::setFecha(Fecha){
    int d, m, a;
    fechaMed.setFecha(d,m,a);
}
bool Medicion::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/Mediciones.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Medicion::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("datos/Ciudades.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}
