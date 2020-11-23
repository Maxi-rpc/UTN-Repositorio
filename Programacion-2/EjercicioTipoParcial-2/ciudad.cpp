#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "ciudad.h"

void Ciudad::setCodCiudad(char *n){
    strcpy(nombre,n);
}
void Ciudad::setNombre(char *n){
    strcpy(nombre,n);
}
void Ciudad::setProvincia(int p){
    codProvincia = p;
}

bool Ciudad::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/Ciudades.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Ciudad::leerDisco(int pos){
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
