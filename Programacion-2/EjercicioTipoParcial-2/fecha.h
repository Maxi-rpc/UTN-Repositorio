#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    void setFecha(int d, int m, int a);
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    int getDia(){return dia;};
    int getMes(){return mes;};
    int getAnio(){return anio;};
};


#endif // FECHA_H_INCLUDED
