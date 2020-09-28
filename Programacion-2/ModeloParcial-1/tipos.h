#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct fecha{
  int dia, mes, anio;
};

struct musico{
  int dni;
  char nombreMusico[30];
  char apellidoMusico[30];
  char email[40];
  char telefono[20];
  int claustro, instrumento, tipoMusica;
  fecha fechaInscripcion;
  bool estado;
};

struct sesion{
  int numeroSesion;
  fecha fechaSesion;
  int horaInicio, horaFin;
  int instrumento;
  char url[45];
  int dniCoordinador;
  bool estado;
};

struct inscripcion{
  int dni;
  int numeroSesion;
  int tipoParticipacion;
  bool estado;
};

void punto1();
void punto2();
int contarSesion(musico reg);
bool grabarPunto2(puntos2 aux);

struct puntos2{
    int dniMusico;
    char nombreMusico[30];
    char apellidoMusico[30];
    int sesiones;
};

#endif // TIPOS_H_INCLUDED
