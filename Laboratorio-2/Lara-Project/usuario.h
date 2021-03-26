#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

struct Fecha {
    int dia, mes, anio;
};

struct Usuario{
    int id;
    char nombre[50];
    char apellido[50];
    Fecha nacimiento;
    float altura;
    float peso;
    char perfilActividad;
    bool aptoMedico;
    bool estado;
};

Usuario nuevoUsuarios(); // Carga los datos de un usuario nuevo
Fecha cargarFechaUsuario(Fecha); // Carga la fecha de Usuario

#endif // USUARIO_H_INCLUDED
