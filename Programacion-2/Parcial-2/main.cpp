#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

// instructores.dat: DNI (int), nombre y apellido (char[50]), código de nacionalidad (1 a 25), nivel (1 a 15)  y fecha de nacimiento.
class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    void setFecha(int d, int m, int a);
    int getDia(){return dia;};
    int getMes(){return mes;};
    int getAnio(){return anio;};
};

void Fecha::setFecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

class Instructor{
private:
    int dni;
    char nombre[50];
    char apellido[50];
    int codNacionalidad; // 1 a 25
    int nivel; // 1 a 15
    Fecha fechaNacimiento;
public:
    void setDni(int d);
    void setNombre(char *n);
    void setApellido(char *a);
    void setCodNacionalidad(int c);
    void setNivel(int n);
    Fecha setFecha(Fecha f);
    // GET
    int getDni(){return dni;};
    char *getNombre(){return nombre;};
    char *getApellido(){return apellido;};
    int getCodNacionalidad(){return codNacionalidad;};
    int getNivel(){return nivel;};
    Fecha getFecha(){return fechaNacimiento;};
    bool escribirDisco();
    int leerDisco(int pos);
    int cantInstructores();
};
void Instructor::setDni(int d){
    dni = d;
}

void Instructor::setNombre(char *n){
    strcpy(nombre, n);
}

void Instructor::setApellido(char *a){
    strcpy(apellido, a);
}

void Instructor::setCodNacionalidad(int c){
    codNacionalidad = c;
}

void Instructor::setNivel(int n){
    nivel = n;
}

Fecha Instructor::setFecha(Fecha f){
    fechaNacimiento = f;
}

bool Instructor::escribirDisco(){
    bool guardo;
    FILE *f = fopen("instructores.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Instructor::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("instructores.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

int Instructor::cantInstructores(){
    FILE *f;
    f = fopen("instructores.dat", "rb");
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Instructor);
    return cant;
}

//final.dat: DNI instructor (int), fecha (día, mes y año), código de avión (1 a 100), nivel de dificultad (inicial 1; intermedio 2; avanzado: 3), código de aspirante.
class Final{
private:
    int dni;
    Fecha fechaFinal;
    int codAvion; // 1 a 100
    int nivelDificultad; // 1-Inicial 2-Intermedio 3-Avanzado
    int codAspirante;
public:
    void setDni(int d);
    Fecha setFechaFinal(Fecha f);
    void setCodAvion(int c);
    void setNivelDificultad(int n);
    void setCodAspirante(int c);
    // GET
    int getDni(){return dni;};
    Fecha getFechaFinal(){return fechaFinal;};
    int getCodAvion(){return codAvion;};
    int getNivelDificultad(){return nivelDificultad;};
    int getCodAspirante(){return codAspirante;};
    bool escribirDisco();
    int leerDisco(int pos);
    int cantFinal();
};

void Final::setDni(int d){
    dni = d;
}

Fecha Final::setFechaFinal(Fecha f){
    fechaFinal = f;
}

void Final::setCodAvion(int c){
    codAvion = c;
}

void Final::setNivelDificultad(int n){
    nivelDificultad = n;
}

void Final::setCodAspirante(int c){
    codAspirante = c;
}

bool Final::escribirDisco(){
    bool guardo;
    FILE *f = fopen("final.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Final::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("final.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

int Final::cantFinal(){
    FILE *f;
    f = fopen("final.dat", "rb");
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Final);
    return cant;
}

class PuntoA{
private:
    char nombre[50];
    int cantFinales;
public:
    void setNombre(char *n);
    void setCantFinales(int c);
    bool escribirDisco();
};

void PuntoA::setNombre(char *n){
    strcpy(nombre, n);
}

void PuntoA::setCantFinales(int c){
    cantFinales = c;
}

bool PuntoA::escribirDisco(){
    bool guardo;
    FILE *f = fopen("final_2019.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

void puntoA();
void puntoB();

int main()
{
    cout << "Hello world!" << endl;

    puntoA();
    puntoB();

    return 0;
}

void puntoA(){
    Final f;
    int totalFinales = f.cantFinal(); // devuelve la cantidad de todos los finales
    int contar = 0, pos = 0;
    Instructor i;
    int cantIns = i.cantInstructores(); // devuelve la cantidad de Instructores
    int v=0, x=0;
    for(v; v<cantIns; v++){
        i.leerDisco(v);
        for(x; x<totalFinales; x++){
            f.leerDisco(x);
            if(f.getFechaFinal().getAnio() == 2019 && f.getNivelDificultad() == 3){
                contar++;
            }
        }
        PuntoA p;
        p.setNombre(i.getNombre());
        p.setCantFinales(contar);
        p.escribirDisco();
        contar = 0;
    }
}

void puntoB(){
    Final f;
    int totalFinales = f.cantFinal(); // devuelve la cantidad de todos los finales
    int a=0, b=0, c=0; // A-inicial 1; B-intermedio 2; C-avanzado: 3
    int i=0;
    for(i; i<totalFinales; i++){
        f.leerDisco(i);
        if(f.getNivelDificultad() == 1){a++;}
        if(f.getNivelDificultad() == 2){b++;}
        if(f.getNivelDificultad() == 3){c++;}
    }
    cout << "CANTIDAD DE FINAL POR NIVEL DE DIFICULTAD" << endl;
    cout << "INICIAL: " << a << endl;
    cout << "INTERMEDIO: " << b << endl;
    cout << "AVANZADO: " << c << endl;
}
