#include <iostream>

using namespace std;
#include "rlutil.h"
#include "ui.h"
using namespace rlutil;
#include "archivo.h"

bool grabarEnDisco(int pos){
    bool guardo;
    Examen reg;
    FILE *f = fopen("archivo.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(&reg, sizeof(Examen), 1, f);
    fclose(f);
    return guardo;
}

