#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

// SE CREA OBJETO / CLASE EXAMEN
class Fecha{
private:
    int dia, mes, anio;

public:
    Fecha(int = 0, int = 0, int = 0);
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    void cargarFecha();
    void mostrarFecha();
};

#endif // FECHA_H_INCLUDED
