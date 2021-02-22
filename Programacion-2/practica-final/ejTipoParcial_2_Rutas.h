#ifndef EJTIPOPARCIAL_2_RUTAS_H_INCLUDED
#define EJTIPOPARCIAL_2_RUTAS_H_INCLUDED

class Ruta{ // ruta.dat
private:
    char codRuta[5];
    char codCiudadOrigen[5];
    char codCiudadFin[5];
    float longitud; // KM
    int tipoRuta; // 1: Autopista, 2: Asfalto, 3: Ripio, 4: Mejorado, 5: Tierra
    bool peaje; // True = Si, False = No
public:
    char *get_codRuta(){return codRuta;};
    char *get_codOrigen(){return codCiudadOrigen;};
    char *get_codFin(){return codCiudadFin;};
    float get_longitud(){return longitud;};
    int get_tipoRuta(){return tipoRuta;};
    bool get_peaje(){return peaje;};
    void set_codRuta(char *n){strcpy(codRuta,n);};
    void set_codCiudadOrigen(char *n){strcpy(codCiudadOrigen,n);};
    void set_codCiudadFin(char *n){strcpy(codCiudadFin,n);};
    void cargar();
    void mostrar();
    int leerDisco(int pos);
};

class Fecha{
private:
    int dia, mes, anio;
public:
    int get_dia(){return dia;};
    int get_mes(){return mes;};
    int get_anio(){return anio;};
    void cargar();
    void mostrar();
};

class Estado{ // estado.dat
private:
    Fecha fec;
    char codRuta[5];
    int estado; // 1: Transitable, 2: Intransitable
public:
    Fecha get_fecha(){return fec;};
    char *get_codRuta(){return codRuta;};
    int get_estado(){return estado;};
    void set_codRuta(char *n){strcpy(codRuta,n);};
    void set_fecha(Fecha f){fec = f;};
    void cargar();
    void mostrar();
    int leerDisco(int pos);
};

class Ciudad{ // ciudad.dat
private:
    char codCiudad[5];
    char nombreCiudad[20];
    int codProvincia; // 1 a 24
public:
    char *get_codCiudad(){return codCiudad;};
    char *get_nombreCiudad(){return nombreCiudad;};
    int get_codProvincia(){return codProvincia;};
    void set_codCiudad(char *n){strcpy(codCiudad,n);};
    void set_nombreCiudad(char *n){strcpy(nombreCiudad,n);};
    int leerDisco(int pos);
};

class Provincia{ // provincia.dat
private:
    int codProvincia; // 1 a 24
    char nombreProvincia[20];
    char region[1];
public:
    int get_codProvincia(){return codProvincia;};
    char *get_nombreProvincia(){return nombreProvincia;};
    char *get_region(){return region;};
    void set_nombreProvincia(char *n){strcpy(nombreProvincia,n);};
    void set_region(char *n){strcpy(region,n);};
    int leerDisco(int pos);
};

void ejTipoParcial_2_Rutas();
void puntoA();

void puntoB();
int contarDias(char *n);
int contarRutas();
class Punto_B{
private:
    char codRuta[5];
    int cant_dias_intransitable; // año 2015
public:
    void set_codRuta(char *n){strcpy(codRuta,n);};
    void set_cant_dias(int c){cant_dias_intransitable = c;};
    bool escribirDisco();
};


#endif // EJTIPOPARCIAL_2_RUTAS_H_INCLUDED
