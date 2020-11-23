#ifndef CIUDAD_H_INCLUDED
#define CIUDAD_H_INCLUDED

class Ciudad {
private:
    char codCiudad [5];
    char nombre [10];
    int codProvincia; // 1 a 24
public:
    void setCodCiudad(char *n);
    void setNombre(char *n);
    void setProvincia(int p);
    char *getCodCiudad(){return codCiudad;};
    char *getNombre(){return nombre;};
    int getProvincia(){return codProvincia;};
    bool escribirDisco();
    int leerDisco(int pos);
};

#endif // CIUDAD_H_INCLUDED
