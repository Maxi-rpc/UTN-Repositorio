#include <iostream>
using namespace std;
#include <cstring>
#include "ejTipoParcial_2_Rutas.h"

void ejTipoParcial_2_Rutas(){
    cout << "1) Ejercicio tipo parcial 2 - RUTAS" << endl;


}

void puntoA(){
    // Busco la ruta con mayor longitud
    Ruta r, aux;
    int pos=0;
    float mayorRuta = 0;
    while(r.leerDisco(pos) == 1){
        if(r.get_longitud() > mayorRuta){
            aux.set_codCiudadOrigen(r.get_codOrigen());
            aux.set_codCiudadFin(r.get_codFin());
            mayorRuta = r.get_longitud();
            aux.set_codRuta(r.get_codRuta());
        }
        pos++;
    }
    // Busco los nombres de las ciudades
    Ciudad c;
    pos=0;
    char ciudadOrigen[20], ciudadFin[20];
    int codProvO, codProvF;
    while(c.leerDisco(pos) == 1){
        if(strcmp(c.get_codCiudad(),aux.get_codOrigen()) == 0){
            strcpy(ciudadOrigen,c.get_nombreCiudad());
            codProvO = c.get_codProvincia();
        }
        if(strcmp(c.get_codCiudad(),aux.get_codFin()) == 0){
            strcpy(ciudadFin,c.get_nombreCiudad());
            codProvF = c.get_codProvincia();
        }
        pos++;
    }
    // Busco nombre de la provincia
    Provincia p;
    pos=0;
    char provOrigen[20], provFin[20];
    while(p.leerDisco(pos) == 1){
        if(p.get_codProvincia() == codProvO){
            strcpy(provOrigen,p.get_nombreProvincia());
        }
        if(p.get_codProvincia() == codProvF){
            strcpy(provFin,p.get_nombreProvincia());
        }
        pos++;
    }

    cout << "Cod de Ruta" << aux.get_codRuta();
    cout << "Ruta mas larga" << mayorRuta;
    cout << "Ciudad Origen" << ciudadOrigen;
    cout << "Provincia Origen" << provOrigen;
    cout << "Ciudad Fin" << ciudadFin;
    cout << "Provincia Fin" << provFin;
}

void puntoB(){
    Ruta r;
    int totalRutas = contarRutas();
    int pos=0, dias=0;
    while(r.leerDisco(pos) == 1){
        dias = contarDias(r.get_codRuta()); // Cuento los dias de cada ruta
        if(dias != 0){ // valido si hubo dias intransitables , si es 0 dias, fue transitable todo el año
            Punto_B b;
            b.set_codRuta(r.get_codRuta());
            b.set_cant_dias(dias);
            b.escribirDisco(); // guardo el objeto
        }
        pos++;
    }
}

int contarDias(char *n){
    Estado e;
    int pos=0, int cant=0;
    while(e.leerDisco(pos) == 1){
        if(e.fec.get_dia()>0 && e.fec.get_anio()==2015 && e.get_estado()==2){
            cant++;
        }
        pos++;
    }
    return cant;
}

int contarRutas(){
    int cant=0, pos=0;
    Ruta r;
    while(r.leerDisco(pos)==1){
        cant++;
        pos++;
    }
    return cant;
}

bool Punto_B::escribirDisco(){
    bool guardo;
    FILE *f = fopen("archivo_puntoB.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

void Fecha::cargar(){
    cout << "Ingresar Dia: ";
    cin >> dia;
    cout << "Ingresar Mes: ";
    cin >> mes;
    cout << "Ingresar Anio: ";
    cin >> anio;
}

void Fecha::mostrar(){
    cout << "Fecha: " << dia << " / " << mes << " / " << anio << endl;
}

void Ruta::cargar(){
    char cod[5];
    cout << "Codigo de Ruta: ";
    cin >> cod;
    set_codRuta(cod);
    cout << "Codigo de Ciudad de Origen: ";
    cin >> cod;
    set_codCiudadOrigen(cod);
    cout << "Codigo de Ciudad de Fin: ";
    cin >> cod;
    set_codCiudadFin(cod);
    cout << "Longitud: ";
    cin >> longitud;
    cout << "Tipo de Ruta:" << endl;
    cout << "1: Autopista, 2: Asfalto, 3: Ripio, 4: Mejorado, 5: Tierra >";
    cin >> tipoRuta;
    cout << "Peaje S/N: ";
    char resp;
    cin >> resp;
    if(resp == 's' || resp == 'S'){
        peaje = true;
    } else {
        peaje = false;
    }
}

void Ruta::mostrar(){
    string tipos[5] = {"Autopista","Asfalto","Ripio","Mejorado","Tierra"};

    cout << "Codigo de Ruta: " << codRuta << endl;
    cout << "Codigo de Ciudad de Origen: " << codCiudadOrigen << endl;
    cout << "Codigo de Ciudad de Fin: " << codCiudadFin << endl;
    cout << "Longitud: " << longitud << endl;
    cout << "Tipo de Ruta: " << tipos[tipoRuta-1] << endl;
    cout << "Peaje S/N: ";
    if(peaje == true){
        cout << "Si" << endl;
    } else {
        cout << "No" << endl;
    }
}

void Estado::cargar(){
    char cod[5];
    cout << "Codigo de Ruta: ";
    cin >> cod;
    set_codRuta(cod);
    cout << "Fecha: ";
    fec.cargar();
    cout << "Estado: " << endl;
    cout << "1: Transitable, 2: Intransitable >";
    cin >> estado;
}

void Estado::mostrar(){
    string estados[2] = {"Transitable","Intransitable"};

    cout << "Codigo de Ruta: " << codRuta << endl;
    fec.mostrar();
    cout << "Estado: " << estados[estado-1] << endl;
}
