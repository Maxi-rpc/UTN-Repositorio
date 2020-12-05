#include <iostream>

using namespace std;
#include "strPelicula.h"

Pelicula cargar_pelicula(Pelicula *lista, tam){
    Pelicula pel;

    cout << "Ingresar Datos: " << endl;
    cout << "Titulo: " << endl;
    cin >>pel.titulo;
    cout << "Costo: " << endl;
    cin >>pel.costo;
    while (validarNeg(pel.costo) == false){
        cout << "Ingresar valor mayor a cero: " << endl;
        cin >>pel.costo;
    }
    cout << "Recaudacion: " << endl;
    cin >>pel.recaudacion;
    while (validarNeg(pel.recaudacion) == false){
        cout << "Ingresar valor mayor a cero: " << endl;
        cin >>pel.recaudacion;
    }
    cout << "ID Pais: " << endl;
    cin >>pel.idPais;
    while (validarId(pel.idPais) == false){
        cout << "Ingresar ID entre 1 a 999: " << endl;
        cin >>pel.idPais;
    }
    pel.rentabilidad = calcular_rentabilidad(pel.costo, pel.recaudacion);

    return pel;
};

void mostrar_pelicula(Pelicula pel){
    cout << "..............................." << endl;
    cout << "Titulo: " << pel.titulo << endl;
    cout << "Costo: " << pel.costo << endl;
    cout << "Recaudacion: " << pel.recaudacion << endl;
    cout << "ID Pais: " << pel.idPais << endl;
    cout << "Rentabilidad: " << pel.rentabilidad << endl;
}

bool validarNeg(float num){
    bool ok;
    if(num < 0){
        ok = false;
    } else {
        ok = true;
    }
    return ok;
}

bool validarId(short id){
    bool ok;
    if(id >= 1 && id <= 999){
        ok = true;
    } else {
        ok = false;
    }
    return ok;
}

float calcular_rentabilidad(float costo, float recaudacion){
    float res;
    res = recaudacion - costo;
    return res;
}

void cargar_lista_pelicula(Pelicula *vec, int tam){
    int i;
    for(i=0; i<tam; i++){
        vec[i] = cargar_pelicula();
    }
}
void mostrar_lista_pelicula(Pelicula *vec, int tam){
    int i;
    for(i=0; i<tam; i++){
        mostrar_pelicula(vec[i]);
        cout << "----------" << endl;
    }
}
int buscar_id(int id, Participante *lista, int tam){
    for()
}
