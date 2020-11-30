#include <iostream>
#include <string.h>
using namespace std;

// Deportistas.dat
// Figuran en el archivo todos los deportistas de la UTN. Hay un registro por cada deportista.
struct Deportista{
    int dni;
    char nombre[30];
    char apellido[30];
    int numUnidadAcad; // 1 a 30
    char email[30];
    int especialidad; // 1 a 10
};

struct Fecha{
    int dia, mes, anio;
};

// Torneos.dat
// Figuran en el archivo todos los torneos de la UTN. Hay un registro por cada torneo
struct Torneo{
    int numTorneo;
    char nombreTorneo[30];
    int especialidad; // 1 a 10
    Fecha fechaTorneo;
    int numUnidadAcadOrg;
};

// Inscripciones.dat
// En el archivo están todas las inscripciones desde el 2010 a la fecha.
struct Inscripcion{
    int dniDeportista;
    int numTorneo;
    int tipoTorneo; // Tipo de torneo (1: abierto 2: cerrado: sólo para deportistas de la UTN)
    Fecha fechaInscripcion;
};
// RESOLUCION
struct Puntouno{
    char nombre[30];
    int dniDeportista;
    int cantInscripcionesCerrados;
};
void puntoUno();
int contarInsCerrado(int dni);
bool grabarPuntoUno(Puntouno);

void puntoDos();
int contarEsp(int especialidades);

int main()
{
    cout << "PROGRAMACION II - RECUPERATORIO I" << endl;
    cout << "1- PUNTO UNO" << endl;
    cout << "2- PUNTO DOS" << endl;
    cout << "> ";
    int opc;
    cin >> opc;

    switch(opc){
        case 1:
            puntoUno();
        break;
        case 2:
            puntoDos();
        break;
        case 0:
            return 0;
        break;
        default: cout << "OPCION INCORRECTA" << endl;
        break;
    }

    return 0;
}

void puntoUno(){
    cout << "PUNTO UNO" << endl;
    Deportista dep;
    Puntouno reg;

    FILE *f = fopen("Deportistas.dat", "rb");
    if(f == NULL){
        cout << "ERROR AL ABRIR Deportistas.dat";
        return;
    }
    while(fread(&dep, sizeof(Deportista), 1, f)){
        strcpy(reg.nombre, dep.nombre);
        reg.dniDeportista = dep.dni;
        reg.cantInscripcionesCerrados = contarInsCerrado(reg.dniDeportista);

        if(grabarPuntoUno(reg)){cout << "ARCHIVO GUARDADO";}
        else{cout << "ERROR AL GUARDAR ARCHIVO";}
    }
    fclose(f);
}

int contarInsCerrado(int dni){
    int inscrip=0;
    Inscripcion reg;
    FILE *f = fopen("Inscripciones.dat", "rb");
    if(f == NULL){
        return -1;
    }
    while(fread(&reg, sizeof(Inscripcion), 1, f)){
        if(reg.dniDeportista == dni && reg.tipoTorneo == 2){
            inscrip++;
        }
    }
    fclose(f);
    return inscrip;
}

bool grabarPuntoUno(Puntouno aux){
    bool guardo;
    FILE *f = fopen("Puntouno.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar Puntouno.dat";
        return false;
    }
    guardo = fwrite(&aux, sizeof(Puntouno), 1, f);
    fclose(f);
    return guardo;
}

void puntoDos(){
    int especialidades = 1;
    int deportistas = 0;
    string esp[10] = {"FUTBOL MASCULINO","FUTBOL FEMENINO","VOLEY MASCULINO","VOLEY FEMENINO","HANDBALL MASCULINO","HANDBALL FEMENINO","BASQUET MASCULINO","BASQUET FEMENINO","AJEDREZ","ATLETISMO"};

    cout << "PUNTO DOS" << endl;
    cout << "LAS ESPECIALIDAD CON MAS DE 50 DEPORTISTAS: " << endl;
    for(especialidades; especialidades<11; especialidades++){
        deportistas = contarEsp(especialidades);
        //if(deportistas > 50){
            cout << esp[especialidades-1] << "," << deportistas << endl;
            cout << "-----------" << endl;
        //}
    }
}

int contarEsp(int especialidades){
    int contar=0;
    Deportista dep;
    FILE *f = fopen("Deportistas.dat", "rb");
    if(f == NULL){
        return -1;
    }
    while(fread(&dep, sizeof(Deportista), 1, f)){
        if(especialidades == dep.especialidad){
            contar++;
        }
    }
    fclose(f);
    return contar;
}
