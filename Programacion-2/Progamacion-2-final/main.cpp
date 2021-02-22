#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Jugador{ // jugador.dat
private:
    int dni;
    char nombreYapellido[50];
    int localidad; // 1 a 10
    int edad;
    int posicion; // 1 a 11
    int equipo; // 1 15
public:
    Jugador(char *n){
        set_nombreYap(n);
    }
    void set_dni(int n){dni = n;};
    void set_nombreYap(char *n){strcpy(nombreYapellido,n);}
    void set_localidad(int n){localidad = n;};
    void set_edad(int n){edad = n;};
    void set_pos(int n){posicion = n;};
    void set_eq(int n){equipo = n;};
    // Get
    int get_dni(){return dni;};
    char *get_nombreYap(){return nombreYapellido;};
    int get_localidad(){return localidad;};
    int get_edad(){return edad;};
    int get_pos(){return posicion;};
    int get_eq(){return equipo;};
    int leerDisco(int pos);
};

class Fecha{
private:
    int dia, mes, anio;
public:
    void Fecha::Fecha(){
    dia = 0;
    mes = 0;
    anio = 0;
    };
    void set_dia(int d){dia = d;};
    void set_mes(int m){mes = m;};
    void set_anio(int a){anio = a;};
    int get_dia(){return dia;};
    int get_mes(){return mes;};
    int get_anio(){return anio;};
};
class Inscripcion{ // Inscripciones.dat
private:
    int numPart;
    int dni;
    Fecha fec;
    int campeonato; // 1 a 10
    char nombreCancha[30];
public:
    void set_numPart(int num){numPart = num;};
    void set_dni(int d){dni = d;};
    void set_camp(int c){campeonato = c;};
    void set_nombreC(char *n){strcpy(nombreCancha,n);}
    // Get
    int get_numPart(){return numPart;};
    int get_dni(){return dni;};
    int get_camp(){return campeonato;};
    char *get_nombreC(){return nombreCancha;};
    int leerDisco(int pos);
};

class Torneo30{ // torneo30.dat
private:
    int dni;
    char nombreYapellido[50];
    int cant;
public:
    void set_dni(int n){dni = n;};
    void set_nombreYap(char *n){strcpy(nombreYapellido,n);}
    void set_cant(int n){cant = n;};
    bool escribirEnDisco();
};

// funcion externa
int cantInscrip(int dni);

void puntoA();
void puntoB();

int cantPorLocalidad();


int main()
{
    cout << "Hello world!" << endl;
    puntoA();
    puntoB();

    return 0;
}

void puntoA(){
   Jugador jug;
   int pos=0;
   while(jug.leerDisco(pos)){
        if(jug.get_edad() > 30){ // Busco mayor a 30
            Torneo30 t;
            t.set_dni(jug.get_dni());
            t.set_nombreYap(jug.get_nombreYap());
            int cant = cantInscrip(jug.get_dni()); // busco cantidad de inscripciones
            t.set_cant(cant);
            if(t.escribirEnDisco()){cout << "se guardo con exito";}
            else{cout << "error al guardar";};
        }
        pos++:
   }
}

bool Torneo30::escribirEnDisco(){
    bool guardo;
    FILE *f = fopen("torneo30.dat", "ab"); // Se abre archivo
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f); // Se escribe en el archivo
    fclose(f);
    return guardo;
}

int cantInscrip(int dni){
    int cant=0, pos=0;
    Inscripcion u;
    while(u.leerDisco(pos)==1){
        if(dni == u.get_dni() && u.get_camp() == 3){ // condicion campeonato 3
            cant++;
        }
        pos++;
    }
    return cant;
}

void puntoB(){
    Jugador jug;
    int eq[15]={}, int pacheco = 5;
    int cant=0;
    int pos=0;
    while(jug.leerDisco(pos)){
        if(jug.get_localidad() == pacheco){
            eq[jug.get_eq()-1]++;
        }
        pos++;
    }
    int mayor=0 , x=1, v=0;
    for(x=0; x<15; x++){
        if(eq[x] > mayor){
            mayor = eq[x];
        }
    }
    cout << "El equipo es:" << mayor << endl;
}

