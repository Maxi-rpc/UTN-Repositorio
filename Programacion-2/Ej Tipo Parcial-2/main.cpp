#include <iostream>

using namespace std;

class Cliente{
private:
    char cuit[12];
    char nombre[40];
    int categoria; // 1: responsable inscripto; 2: no responsable; 3: monotributo; 4: exento
public:
    char *getCuit(){return cuit;};
    char *getNombre(){return nombre;};
    int getCategoria(){return categoria;};
};

class Fecha{
private:
    int dia, mes, anio;
public:
    int getDia(){return dia;};
    int getMes(){return mes;};
    int getAnio(){return anio;};
};

class Prestamo{
private:
    int numPrestamo;
    int codBanco;
    char cuitCliente[12];
    float impCred;
    int plazo;
    Fecha fechaP;
public:
    int getNumPres(){return numPrestamo;};
    int getCodBanco(){return codBanco;};
    char *getCuitCliente(){return cuitCliente;};
    float getImpCred(){return impCred;};
    int getPlazo(){return plazo;};
    Fecha getFechaP(){return fechaP;};
};

class PuntoA{
private:
    char nombre[40];
    char cuit[12];
    float impTotal;
public:
    void setNombre(char *nombre);
    void setCuit(char *cuit);
    void setImpTotal(float impTotal);
    bool escribirDisco();
};


int main()
{
    cout << "EJERCICIO TIPO PARCIAL 2" << endl;



    return 0;
}

bool PuntoA::escribirDisco(){
    bool guardo;
    FILE *f = fopen("puntoA.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}
