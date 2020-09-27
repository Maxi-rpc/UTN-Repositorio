#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
    DECLARACION DE FUNCIONES MENÚ
*/
void subMenuJugar(int [], int, string[], int[], int []); ///MENU JUGAR
void subMenuPuntaje(string[], int[], int []); ///MENU PUNTAJE
void subMenuReglamento(); ///MENU REGLAMENTO
void reglas(); ///MUESTRA REGLAS
void combinacionesGanadoras(); ///MUESTRA COMBINACIONES GANADORAS

/**
    DECLARACION DE FUNCIONES DEL JUEGO
*/
void cargarDados(int [], int); ///CARGA DADOS
void juegoMain(int [], int, string[], int[], int []); ///MODO 1 JUGADOR
void juegoManual(int [], int, string[], int[], int[]); ///MODO JUGAR DEMOSTRACION INGRESO MANUAL DE DADOS
void mostrarDados(int [], int); ///MUESTRA LOS VALORES DE LOS DADOS
void tirarDados(int [], int, int); ///TIRA DADOS DE FORMA RANDOM
void cambiarDados(int [], int); ///CAMBIAR DADOS SEGUN ELECCION
int buscarDadosRepetidos(int [], int, int ); ///CUENTA LA CANTIDAD DE VECES QUE SE REPITE UN NUMERO EN EL VECTOR
int calcularPuntaje(int [], int); ///CALCULA QUE TIPO DE PUNTAJE CORRESPONDE POR JUGADA
void cargarNombre(char []); ///CARGA NOMBRE DE 1 JUGADOR
void ponerCero(int [], int); ///PONE EN 0 (CERO) TODAS LAS POSICIONES DEL VECTOR guardarPuntajes
int ultimoJugador(int []); ///BUSCA LA POSICION DEL VECTOR EN 0 (VACIO) Y LO DEVUELVE
void guardarDatos(int, char [], int, string [], int [], int []); ///RECIBE EL NOMBRE Y PUNTOS DEL JUGADOR Y LOS GUARDA EN PUNTAJES
void ordenarPuntaje(int [], string [], int []);///ORDENAR PUNTAJES MAYOR A MENOR
void mostrarPuntaje(int [], string [], int []); ///MUESTRA LO QUE CONTIENE LAS POSICIONES DEL VECTOR (PUNTAJES)
void copiarVector(int [], int, int[]); ///COPIA EN OTRO VECTOR EL CONTENIDO DEL VECTOR 1 EN EL VECTOR 2
void ordenarDados(int [], int); ///ORDENAR EL VECTOR DE DADOS DE MENOR A MAYOR.
void mostrarPuntosParciales(int [], int); ///MUESTRA LOS PUNTOS ACTUALES AL TIRAR LOS DADOS
void juegoMainDos(int [], int, string[], int[], int []); ///MODO 2 JUGADORES
void guardarDatosDos(int, int, int, char [], char [], string [], int [], int []); ///RECIBE AMBOS NOMBRES Y PUNTOS DE LOS JUGADORES Y LOS GUARDA EN PUNTAJES
void cargarNombreDos(char [], char []); ///CARGA 2 NOMBRES
void cargarDadosManual(int [], int); ///INGRESAR LOS DADOS MANUALMENTE
void tirarDadosManual(int [], int, int, int); ///TIRA LOS DADOS MANUALMENTE
void cambiarDadosManual(int [], int); ///CAMBIA DADOS MANUALMENTE
int validarIngreso(int, int , int ); ///VERIFICA LOS DATOS INGRESADOS QUE SEAN CORRECTOS

/**
    DECLARACION DE FUNCIONES DE CARTELES
*/
void cabeceraJuego(int[], int, int, int, int, char[]); ///MUESTRA LA CABECERA DEL JUEGO MOSTRANDO NOMBRE PUNTOS NUMERO DE RONDA
void cartelJugar(); ///CARTEL MENU JUGAR
void cartelPuntaje(); ///CARTEL DE PUNTAJE
void entreTurno(char [], int, int, bool); ///CARTEL ENTRE TURNOS
void cartelGameover(char [], int, int); ///CARTEL GAME OVER
void cartelGenerala(char [], int, int); ///CARTEL GENERALA!!!
void entreTurnoDos(char [],char [], int, int, int, bool); ///CARTEL ENTRE TURNOS DOS
void cartelGameoverDos(char [],char [], int, int, int); ///GAME OVER DOS
#endif // FUNCIONES_H_INCLUDED
