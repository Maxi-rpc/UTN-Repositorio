#include <iostream>
#include <stdlib.h> /// para la funcion RAND
#include <time.h> /// para la funcion TIME
using namespace std;
#include "funciones.h"

/**
    DEFINICION DE LAS FUNCIONES PARA EL MENU
*/

///MENU JUGAR
void subMenuJugar(int vec[], int tam, string guardarNombres[], int guardarPuntajes[], int guardarNumRonda[]){
    bool menu = false;
    int opc;
    system("cls");
    while(!menu){
        system("cls");
        cartelJugar();
        cout << "1. 1 Jugador " << endl;
        cout << "2. 2 Jugadores " << endl;
        cout << "3. Demo - Ingreso manual de dados " << endl;
        cout << "4. Volver " << endl << endl;
        cout << "Ingrese la opción deseada: ";
        opc = validarIngreso(opc, 1, 4);
        system("cls");
        switch(opc){
            case 1:
                juegoMain(vec, tam, guardarNombres, guardarPuntajes, guardarNumRonda);
                break;
            case 2:
                juegoMainDos(vec, tam, guardarNombres, guardarPuntajes, guardarNumRonda);
                break;
            case 3: juegoManual(vec, tam, guardarNombres, guardarPuntajes, guardarNumRonda);
                break;
            case 4: menu = true;
                break;
        }

    }
}

///MENU PUNTAJE
void subMenuPuntaje(string guardarNombres[], int guardarPuntajes[], int guardarNumRonda[]){
    cartelPuntaje(); /// cartel de puntaje
    ordenarPuntaje(guardarPuntajes, guardarNombres, guardarNumRonda); /// ordena los puntajes de mayor a menor
    mostrarPuntaje(guardarPuntajes, guardarNombres, guardarNumRonda); /// muestra los puntajes siempre y cuando existan entradas
}
///MENU REGLAMENTO
void subMenuReglamento(){
    bool menu = false;
    int opc;
    system("cls");
    while(!menu){
        system("cls");
        cout << "\t\t\t\tREGLAMENTO Y COMBINACIONES GANADORAS" << endl;
        cout << "1. Reglamento " << endl;
        cout << "2. Combinaciones ganadoras " << endl;
        cout << "3. Volver " << endl << endl;
        cout << "Ingrese la opción deseada: ";
        opc = validarIngreso(opc, 1, 3);
        system("cls");
        switch(opc){
            case 1: reglas();
                break;
            case 2: combinacionesGanadoras();
                break;
            case 3: menu = true;
                break;
        }
    }
}
///MUESTRA REGLAS
void reglas(){
    system("cls");
    cout << endl << "\t\t\t\t\tREGLAMENTO DEL JUEGO" << endl << endl << endl;

    cout << "\tEl objetivo del juego es sacar Generala Servida, u obtener la puntuación más alta" << endl;
    cout << "\tde un conjunto de rondas establecidas. " << endl << endl;

    cout << "\tUna ronda puede estar compuesta por hasta tres lanzamientos por jugador." << endl;
    cout << "\tUn lanzamiento consiste en tirar los cinco dados y evaluar sus valores para determinar el puntaje." << endl;
    cout << "\tEn caso que el jugador lo considere puede volver a tirar todos a algunos de los dados en dos oportunidades más." << endl;
    cout << "\tEl sistema preguntará si quiere volver a lanzar,  y si la respuesta es sí," << endl;
    cout << "\tpreguntará cuáles son los dados que quiere elegir para volver a tirar. " << endl << endl;

    cout << "\tEl puntaje de un lanzamiento está determinado por una serie de reglas que figuran" << endl;
    cout << "\ten la sección Combinaciones ganadoras." << endl << endl;

    cout << "\tEl puntaje obtenido se suma al puntaje anterior del jugador. Si un jugador saca" << endl;
    cout << "\tGenerala en el primer tiro gana la partida." << endl << endl << endl << endl;
    system("pause");
}
///MUESTRA COMBINACIONES GANADORAS
void combinacionesGanadoras(){
    system("cls");
    cout << endl << "\t\t\t\tCOMBINACIONES GANADORAS" << endl << endl << endl;
    cout << "\t             Combinación             | Nombre jugada |    Puntaje otorgado    " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t1 ó más dados con valor 1            | Juego de 1    | Suma de la cantidad    " << endl;
    cout << "\t                                     |               | de dados con el valor 1" << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t1 ó más dados con valor 2            | Juego de 2    | 2*suma cantidad de     " << endl;
    cout << "\t                                     |               | dados con valor 2      " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t1 ó más dados con valor 3            | Juego de 3    | 3*suma cantidad de     " << endl;
    cout << "\t                                     |               | dados con valor 3      " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t1 ó más dados con valor 4            | Juego de 4    | 4*suma cantidad de     " << endl;
    cout << "\t                                     |               | dados con valor 4      " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t1 ó más dados con valor 5            | Juego de 5    | 5*suma cantidad de     " << endl;
    cout << "\t                                     |               | dados con valor 5      " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t1 ó más dados con valor 6            | Juego de 6    | 6*suma cantidad de     " << endl;
    cout << "\t                                     |               | dados con valor 6      " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t5 dados en orden creciente           | Escalera      | 25                     " << endl;
    cout << "\t(1, 2, 3, 4, 5) ó (2,3,4,5,6)        |               |                        " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t3 dados iguales, más otros 2 iguales | Full          | 30                     " << endl;
    cout << "\tEjemplo:                             |               |                        " << endl;
    cout << "\t(3,3,3,2,2), (1,1,4,4,4)             |               |                        " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t 4 dados iguales                     | Póker         | 40                     " << endl;
    cout << "\t Ejemplo:                            |               |                        " << endl;
    cout << "\t(3,3,3,3,2), (1,4,4,4,4)             |               |                        " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl;
    cout << "\t5 dados con el mismo valor           | Generala      | 50                     " << endl;
    cout << "\tEjemplos:                            |               | Si es en un tiro       " << endl;
    cout << "\t(1,1,1,1,1) , (6,6,6,6,6), etc       |               | sólo gana el partido   " << endl;
    cout << "\t------------------------------------------------------------------------------" << endl << endl;

    cout << "\tDe obtener más de una combinación en el mismo lanzamiento, siempre deberá     " << endl;
    cout << "\tsumar el puntaje de mayor valor.                                              " << endl;
    cout << endl << endl;
    system("pause");
}
/**
    DEFINICION DE LAS FUNCIONES PARA EL JUEGO
*/


/**
    JUEGO DE UN JUGADOR
*/
///MODO 1 JUGADOR
void juegoMain(int vec[],int tam, string guardarNombres[], int guardarPuntajes[], int guardarNumRonda[]){

    int cantDados, nRonda=0, puntajeTotal=0, i, puntosRonda=0, lanzamiento;
    char conf, nombre[25];
    bool generalaServida = true, mostrarEntreTurno = true;
    cargarNombre(nombre); /// CARGA EL NOMBRE

    for(i=0;i<10 && generalaServida;i++){
        cargarDados(vec, tam);
        puntosRonda = calcularPuntaje(vec, tam);
        nRonda = i+1;
        lanzamiento = 2; //prueba ciclos
        while(lanzamiento>0){
            if(puntosRonda==50){
                lanzamiento = -1;
                generalaServida = false;
                puntajeTotal += 1000;
                mostrarEntreTurno = false;
                cartelGenerala(nombre, nRonda, puntajeTotal);
            }else{
                lanzamiento--;
                cabeceraJuego(vec, tam, nRonda, puntajeTotal, lanzamiento, nombre);/// desde cabecera llama a a funcion mostrarDados
                cout << endl << endl;
                mostrarPuntosParciales(vec, tam);
                cout << "¿CONTINUAR LANZANDO? (S/N): ";
                cin >> conf;
                while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
                    cout << "\nIngrese una opcion valida!" << endl;
                    cin >> conf;
                }
                if(conf=='S' || conf == 's'){
                    cout << endl << "¿CUANTOS DADOS VOLVES A TIRAR? (1-5): ";
                    cantDados = validarIngreso(cantDados, 1, 5);
                    switch(cantDados){
                        case 1: cambiarDados(vec, 1);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 2: cambiarDados(vec, 2);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 3: cambiarDados(vec, 3);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 4: cambiarDados(vec, 4);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 5: cargarDados(vec, tam);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        }
                    }else{
                        puntosRonda = calcularPuntaje(vec, tam);
                        lanzamiento = -1; //termina ciclo;
                    }
                    cabeceraJuego(vec, tam, nRonda, puntajeTotal, lanzamiento, nombre);
                    system("pause");
                }

            }
            entreTurno(nombre, nRonda, puntosRonda, mostrarEntreTurno); ///MUESTRA NOMBRE, RONDA, PUNTOS ENTRE RONDAS
            puntajeTotal+=puntosRonda;
        }
        //puntajeTotal+=puntosRonda;

        if(nRonda==10){
            cartelGameover(nombre, nRonda, puntajeTotal);
        }

        guardarDatos(puntajeTotal, nombre, nRonda, guardarNombres, guardarPuntajes, guardarNumRonda); ///GUARDA LOS DATOS EN PUNTAJE
}

/**
    JUEGO DE DOS JUGADORES
*/
///MODO 2 JUGADORES
void juegoMainDos(int vec[],int tam, string guardarNombres[], int guardarPuntajes[], int guardarNumRonda[]){

    int cantDados, nRonda=0, puntajeTotalUno=0, puntajeTotalDos=0, i, puntosRonda=0, lanzamiento;
    char conf, nombreUno[25], nombreDos[25];
    bool generalaServida = true, mostrarEntreTurno = true, proximoTurno;
    //char nombre[25]; ///la declare para que me deje correr todo
    cargarNombreDos(nombreUno, nombreDos); /// CARGA 2 NOMBRES

    for(i=0;i<10 && generalaServida;i++){
        cargarDados(vec, tam);
        puntosRonda = calcularPuntaje(vec, tam);
        nRonda = i+1;
        lanzamiento = 2; //prueba ciclos

        /// Comienza ciclo del primer jugador
        while(lanzamiento>0){
            if(lanzamiento == 2 && puntosRonda==50){
                lanzamiento = -1;
                generalaServida = false;
                puntajeTotalUno += 1000;
                mostrarEntreTurno = false;
                cartelGenerala(nombreUno, nRonda, puntajeTotalUno);
            }else{
                lanzamiento--;
                cabeceraJuego(vec, tam, nRonda, puntajeTotalUno, lanzamiento, nombreUno);
                cout << endl << endl;
                mostrarPuntosParciales(vec, tam);
                cout << "¿CONTINUAR LANZANDO? (S/N): ";
                cin >> conf;
                while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
                    cout << "\nIngrese una opcion valida!" << endl;
                    cin >> conf;
                }
                if(conf=='S' || conf == 's'){
                    cout << endl << "¿CUANTOS DADOS VOLVES A TIRAR? (1-5): ";
                    cantDados = validarIngreso(cantDados, 1 ,5);
                    switch(cantDados){
                        case 1: cambiarDados(vec, 1);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 2: cambiarDados(vec, 2);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 3: cambiarDados(vec, 3);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 4: cambiarDados(vec, 4);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 5: cargarDados(vec, tam);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        }
                    }else{
                        puntosRonda = calcularPuntaje(vec, tam);
                        lanzamiento = -1; //termina ciclo;
                    }
                    cabeceraJuego(vec, tam, nRonda, puntajeTotalUno, lanzamiento, nombreUno);
                    system("pause");
                }

            }
            puntajeTotalUno+=puntosRonda;
            cargarDados(vec, tam);
            puntosRonda = calcularPuntaje(vec, tam);
            lanzamiento = 2;
            proximoTurno = true;
            entreTurnoDos(nombreUno, nombreDos, nRonda, puntajeTotalUno, puntajeTotalDos, proximoTurno);///MUESTRA NOMBRE, RONDA, PUNTOS ENTRE RONDAS

            /// Comienza ciclo del segudo jugador
            while(lanzamiento>0){
            if(lanzamiento == 2 && puntosRonda==50){
                lanzamiento = -1;
                generalaServida = false;
                puntajeTotalDos += 1000;
                mostrarEntreTurno = false;
                cartelGenerala(nombreDos, nRonda, puntajeTotalDos);
            }else{
                lanzamiento--;
                cabeceraJuego(vec, tam, nRonda, puntajeTotalDos, lanzamiento, nombreDos);
                cout << endl << endl;
                mostrarPuntosParciales(vec, tam);
                cout << "¿CONTINUAR LANZANDO? (S/N): ";
                cin >> conf;
                while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
                    cout << "\nIngrese una opcion valida!" << endl;
                    cin >> conf;
                }
                if(conf=='S' || conf == 's'){
                    cout << endl << "¿CUANTOS DADOS VOLVES A TIRAR? (1-5): ";
                    cantDados = validarIngreso(cantDados, 1, 5);
                    switch(cantDados){
                        case 1: cambiarDados(vec, 1);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 2: cambiarDados(vec, 2);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 3: cambiarDados(vec, 3);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 4: cambiarDados(vec, 4);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 5: cargarDados(vec, tam);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        }
                    }else{
                        puntosRonda = calcularPuntaje(vec, tam);
                        lanzamiento = -1; //termina ciclo;
                    }
                    cabeceraJuego(vec, tam, nRonda, puntajeTotalDos, lanzamiento, nombreDos);
                    system("pause");
                }

            }
            proximoTurno = false;
            puntajeTotalDos+=puntosRonda;
            entreTurnoDos(nombreUno, nombreDos, nRonda, puntajeTotalUno, puntajeTotalDos, proximoTurno);///MUESTRA NOMBRE, RONDA, PUNTOS ENTRE RONDAS

        }


        if(nRonda==10){
            cartelGameoverDos(nombreUno, nombreDos, nRonda, puntajeTotalUno, puntajeTotalDos);///CARTEL GAME OVER DOS JUGADORES
        }
        guardarDatosDos(puntajeTotalUno, puntajeTotalDos, nRonda, nombreUno, nombreDos, guardarNombres, guardarPuntajes, guardarNumRonda); ///GUARDA LOS DATOS EN PUNTAJE
}


/**
    JUEGO CON DADOS MANUALES
*/
///MODO JUGAR DEMOSTRACION INGRESO MANUAL DE DADOS
void juegoManual(int vec[],int tam, string guardarNombres[], int guardarPuntajes[], int guardarNumRonda[]){
    ponerCero(vec, tam);
    int cantDados, nRonda=0, puntajeTotal=0, i, puntosRonda=0, lanzamiento;
    char conf, nombre[25];
    bool generalaServida = true, mostrarEntreTurno = true;
    cargarNombre(nombre); /// CARGA EL NOMBRE

    for(i=0;i<10 && generalaServida;i++){
        lanzamiento = 3; //prueba ciclos
        nRonda = i+1;
        ponerCero(vec, tam);
        cabeceraJuego(vec, tam, nRonda, puntajeTotal, lanzamiento-1, nombre);
        cargarDadosManual(vec, tam);
        puntosRonda = calcularPuntaje(vec, tam);
        while(lanzamiento>0){
            if(lanzamiento == 3 && puntosRonda==50){
                lanzamiento = -1;
                generalaServida = false;
                puntajeTotal += 1000;
                mostrarEntreTurno = false;
                cartelGenerala(nombre, nRonda, puntajeTotal);
            }
            else{
                lanzamiento--;
                cabeceraJuego(vec, tam, nRonda, puntajeTotal, lanzamiento, nombre);
                cout << endl << endl;
                mostrarPuntosParciales(vec, tam);
                cout << "¿CONTINUAR LANZANDO? (S/N): ";
                cin >> conf;
                while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
                    cout << "\nIngrese una opcion valida!" << endl;
                    cin >> conf;
                }
                if(conf=='S' || conf == 's'){
                    cout << endl << "¿CUANTOS DADOS VOLVES A TIRAR? (1-5): ";
                    cantDados = validarIngreso(cantDados, 1, 5);
                    switch(cantDados){
                        case 1: cambiarDadosManual(vec, 1);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 2: cambiarDadosManual(vec, 2);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 3: cambiarDadosManual(vec, 3);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 4: cambiarDadosManual(vec, 4);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        case 5: cargarDadosManual(vec, tam);
                                puntosRonda = calcularPuntaje(vec, tam);
                            break;
                        }
                    }else{
                        puntosRonda = calcularPuntaje(vec, tam);
                        lanzamiento = -1; //termina ciclo;
                    }
                    cabeceraJuego(vec, tam, nRonda, puntajeTotal, lanzamiento, nombre);
                    system("pause");
                }
                //ponerCero(vec, tam);
            }

            entreTurno(nombre, nRonda, puntosRonda, mostrarEntreTurno); ///MUESTRA NOMBRE, RONDA, PUNTOS ENTRE RONDAS
            puntajeTotal+=puntosRonda;
        }


        if(nRonda==10){
            cartelGameover(nombre, nRonda, puntajeTotal);
        }
        guardarDatos(puntajeTotal, nombre, nRonda, guardarNombres, guardarPuntajes, guardarNumRonda); ///GUARDA LOS DATOS EN PUNTAJE
}
///CARGA DADOS
void cargarDados(int vec[],int tam){

    int i;
    srand(time(NULL));
    for(i=0;i<tam;i++){
        vec[i] = 1 + (rand()%6);
    }
}
///VERIFICA LOS DATOS INGRESADOS QUE SEAN CORRECTOS
int validarIngreso(int j, int menor, int mayor){
    //validamos que el ingreso sea un entero y entre el 1 y el 6
    while(!(cin >> j) || (j < menor || j > mayor)){
        //le indicamos el error al usuario
        cout << "\nError: Ingrese un numero del " << menor << " al " << mayor << " por favor: ";
        //limpiamos el ultimo ingreso
        cin.clear();
        //descartamos el ultimo ingreso
        cin.ignore(132, '\n');
    }
    return j;
}
///INGRESAR LOS DADOS MANUALMENTE
void cargarDadosManual(int vec[], int tam){

    int i, j, menor=1, mayor=6;
    for(i=0;i<tam;i++){
        cout << "Ingrese un valor para el dado n° " << i+1 << " (1-6): ";
        j = validarIngreso(j, menor, mayor);
        vec[i] = j;
    }
}
///MUESTRA LOS VALORES DE LOS DADOS
void mostrarDados(int vec[], int tam){
    int i;
    cout << "Posición: \t1\t2\t3\t4\t5" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Valor dado: ";
    for(i=0;i<tam; i++){
        cout << "\t" << vec[i];
    }
    cout << endl;
}
///TIRA DADOS DE FORMA RANDOM
void tirarDados(int vec[], int cant, int pos){
    int i;
    srand(time(NULL));
    for(i=0;i<cant;i++){
        vec[pos] = 1 + (rand()%6);
    }
}
///TIRA LOS DADOS MANUALMENTE
void tirarDadosManual(int vec[], int cant, int pos, int valor){
    int i;
    for(i=0;i<cant;i++){
        vec[pos] = valor;
    }
}
///CAMBIAR DADOS SEGUN ELECCION
void cambiarDados(int vec[],int i){
    int j, pos;
    for(j=0; j<i; j++){
        cout << endl << j+1 << " - ¿CUAL? ";
        cin >> pos;
        tirarDados(vec, i, pos-1);
    }
}
///CAMBIA DADOS MANUALMENTE
void cambiarDadosManual(int vec[], int cant){
    int i, pos, valor;
    for(i=0; i<cant; i++){
        cout << endl << i+1 << " - ¿CUAL? ";
        pos = validarIngreso(pos, 1, 5);
        cout << endl << "POR QUE VALOR? ";
        valor = validarIngreso(valor, 1, 6);
        tirarDadosManual(vec, cant, pos-1, valor);
    }

}
///CUENTA LA CANTIDAD DE VECES QUE SE REPITE UN NUMERO EN EL VECTOR
int buscarDadosRepetidos(int vec[], int tam, int numero){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(vec[i]==numero) cant++;
        }
    return cant;
}

/**
    FUNCIONES PARA EL CALCULO DEL PUNTAJE
*/

///ORDENAR EL VECTOR DE DADOS DE MENOR A MAYOR.
void ordenarDados(int vec[], int tam){
    int i,j, posmin, aux;
    for(i=0;i<tam;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(vec[j]<vec[posmin]) posmin=j;
        }
        aux=vec[i];
        vec[i]=vec[posmin];
        vec[posmin]=aux;
    }
}

/// COPIA EN OTRO VECTOR EL CONTENIDO DEL VECTOR 1 EN EL VECTOR 2
void copiarVector(int vec[], int tam, int v2[]){
    int i;
    for(i=0;i<tam;i++){
        v2[i]=vec[i];
    }
}

/// CALCULA QUE TIPO DE PUNTAJE CORRESPONDE POR JUGADA
int calcularPuntaje(int vec[], int tam){
    int vCopia[tam], puntos;
    int uno, dos, tres, cuatro, cinco, seis;

    copiarVector(vec, tam, vCopia); /// Copiamos el vector para que al ordenarlo no altere los indices cuando volvemos a tirar
    ordenarDados(vCopia,tam); /// ordenamos el vector para que sea mas facil calcular los puntajes

    if (vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4]){ //GENERALA
        puntos=50;
        cout << endl<<"Sacaste: GENERALA" << endl;
    }
    else{
        if ((vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3]) || (vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4])){ //POKER
            puntos=40;
            cout << endl << "Sacaste: POKER" << endl;
        }
        else{
            if (((vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2]) && (vCopia[3]==vCopia[4])) || ((vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4]) && (vCopia[0]==vCopia[1]))){ //FULL
                puntos=30;
                cout << endl << "Sacaste: FULL" << endl;
            }
            else{
                if (vCopia[0]==(vCopia[1]-1) && vCopia[1]==(vCopia[2]-1) && vCopia[2]==(vCopia[3]-1) && vCopia[3]==(vCopia[4]-1)){ //ESCALERA
                    puntos=25;
                    cout << endl << "Sacaste: ESCALERA" << endl;
                }
                else{
                    uno = buscarDadosRepetidos(vec, tam, 1)*1;
                    dos = buscarDadosRepetidos(vec, tam, 2)*2;
                    tres = buscarDadosRepetidos(vec, tam, 3)*3;
                    cuatro = buscarDadosRepetidos(vec, tam, 4)*4;
                    cinco = buscarDadosRepetidos(vec, tam, 5)*5;
                    seis = buscarDadosRepetidos(vec, tam, 6)*6;
                    if (seis>uno && seis>dos && seis>tres && seis>cuatro && seis>cinco){
                        puntos=seis;
                    }
                    else{
                        if (cinco>uno && cinco>dos && cinco>tres && cinco>cuatro){
                            puntos=cinco;
                        }
                        else{
                            if (cuatro>uno && cuatro>dos && cuatro>tres){
                                puntos=cuatro;
                            }
                            else{
                                if (tres>uno && tres>dos){
                                    puntos=tres;
                                }
                                else{
                                    if(dos>uno){
                                        puntos=dos;
                                    }
                                    else{
                                        puntos=uno;
                                    }
                                }
                            }
                        }
                    }
                    cout<<endl;
                }
            }
        }
    }
    return puntos;
}
/**
    FIN FUNCIONES PUNTAJE
*/

///MUESTRA LA CABECERA DEL JUEGO MOSTRANDO NOMBRE PUNTOS NUMERO DE RONDA
void cabeceraJuego(int vec[], int tam, int nRonda, int puntaje, int lanzamiento, char nombre[]){
    system("cls");
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "\t\tTURNO DE " << nombre << " | RONDA N°: " << nRonda << " | PUNTAJE: " << puntaje << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "--------------------- TE QUEDAN "<< lanzamiento+1 << " LANZAMIENTOS ----------------------------------" << endl << endl;
    mostrarDados(vec, tam);
    cout << endl;
}

///CARGA NOMBRE DE 1 JUGADOR
void cargarNombre(char nombre[]){
    cin.ignore();
    cout << endl << endl;
    cout << "\t\t.########..####.########.##....##.##.....##.########.##....##.####.########...#######." << endl;
    cout << "\t\t.##.....##..##..##.......###...##.##.....##.##.......###...##..##..##.....##.##.....##" << endl;
    cout << "\t\t.##.....##..##..##.......####..##.##.....##.##.......####..##..##..##.....##.##.....##" << endl;
    cout << "\t\t.########...##..######...##.##.##.##.....##.######...##.##.##..##..##.....##.##.....##" << endl;
    cout << "\t\t.##.....##..##..##.......##..####..##...##..##.......##..####..##..##.....##.##.....##" << endl;
    cout << "\t\t.##.....##..##..##.......##...###...##.##...##.......##...###..##..##.....##.##.....##" << endl;
    cout << "\t\t.########..####.########.##....##....###....########.##....##.####.########...#######." << endl << endl;
    cout << endl << endl;
    cout<<"Ingrese su nombre para registrarse: ";
    cin.getline(nombre,25);
    /// UN WHILE PARA COMPROBAR QUE NO HAYAN INGRESADO UN NOMBRE VACIO O AL MENOS EL PRIMER CARACTER
    while(nombre[0]=='\0'){
        system("cls");
        cout << endl << endl;
        cout << "\t\t.########..####.########.##....##.##.....##.########.##....##.####.########...#######." << endl;
        cout << "\t\t.##.....##..##..##.......###...##.##.....##.##.......###...##..##..##.....##.##.....##" << endl;
        cout << "\t\t.##.....##..##..##.......####..##.##.....##.##.......####..##..##..##.....##.##.....##" << endl;
        cout << "\t\t.########...##..######...##.##.##.##.....##.######...##.##.##..##..##.....##.##.....##" << endl;
        cout << "\t\t.##.....##..##..##.......##..####..##...##..##.......##..####..##..##.....##.##.....##" << endl;
        cout << "\t\t.##.....##..##..##.......##...###...##.##...##.......##...###..##..##.....##.##.....##" << endl;
        cout << "\t\t.########..####.########.##....##....###....########.##....##.####.########...#######." << endl << endl;
        cout << endl << endl;
        cout<<"Ingrese su nombre para registrarse: ";
        cin.getline(nombre,25);
    }
    cout<< endl;
    cout << nombre<<" listo para continuar?"<< endl << endl;
    system("pause");
}

//RANKING DE PUNTAJE
///PONE EN 0 (CERO) TODAS LAS POSICIONES DEL VECTOR guardarPuntajes
void ponerCero(int guardarPuntajes[], int tam){
    int i;
    for(i=0;i<tam;i++){
        guardarPuntajes[i]=0;
    }
}

///BUSCA LA POSICION DEL VECTOR EN 0 (VACIO) Y LO DEVUELVE
int ultimoJugador(int puntos[]){
    for (int i=0;i<30;i++){
        if (puntos[i]==0){
            return(i);
        }
    }
}

///RECIBE EL NOMBRE Y PUNTOS DEL JUGADOR Y LOS GUARDA EN PUNTAJES
void guardarDatos(int puntos, char nombre[], int nRonda, string guardarNombres[], int guardarPuntajes[], int guardarNumRonda[]){
     int ultimoRegistro;
     ultimoRegistro = ultimoJugador(guardarPuntajes);
     guardarPuntajes[ultimoRegistro] = puntos;
     guardarNombres[ultimoRegistro] = string (nombre);
     guardarNumRonda[ultimoRegistro] = nRonda;
}

///ORDENAR PUNTAJES MAYOR A MENOR
void ordenarPuntaje(int guardarPuntajes[], string guardarNombres[], int guardarNumRonda[]){
    int i,j, posmax;
    int limite, auxPuntos, auxRonda;
    string auxNombres;
    limite = ultimoJugador(guardarPuntajes);
    for(i=0; i < limite-1; i++){
        posmax=i;
        for(j=i+1; j < limite; j++){
            if(guardarPuntajes[j] > guardarPuntajes[posmax]) posmax=j;
        }
        auxPuntos = guardarPuntajes[i];
        guardarPuntajes[i] = guardarPuntajes[posmax];
        guardarPuntajes[posmax] = auxPuntos;

        auxNombres = guardarNombres[i];
        guardarNombres[i] = guardarNombres[posmax];
        guardarNombres[posmax] = auxNombres;

        auxRonda = guardarNumRonda[i];
        guardarNumRonda[i] = guardarNumRonda [posmax];
        guardarNumRonda[posmax] = auxRonda;
    }
}

///MUESTRA LO QUE CONTIENE LAS POSICIONES DEL VECTOR (PUNTAJES)
void mostrarPuntaje(int guardarPuntajes[], string guardarNombres[], int guardarNumRonda[]){

    int i, tam=10;
    void cartelPuntaje();
    cout << "\t\t----------------------------------------------------------------------------" << endl << endl;
    if(guardarPuntajes[0]!=0){
       for(i=0;i<tam;i++){
            if(guardarPuntajes[i]!=0){
                cout << "\t\t\t"<< i+1 << " - JUGADOR " << guardarNombres[i] << "\t| PUNTAJE: " << guardarPuntajes[i] << "\t| RONDAS: " << guardarNumRonda[i]<< endl << endl;
            }
        }
    }else{
        cout << "\t\t\tAun no hay puntajes guardados, se el primero!" << endl << endl;
    }

    cout << "\t\t----------------------------------------------------------------------------" << endl << endl;
    cout << endl << endl;
    system("pause");
}
///MUESTRA LOS PUNTOS ACTUALES AL TIRAR LOS DADOS
void mostrarPuntosParciales(int vec[], int tam){
    int puntos = 0;
    puntos = calcularPuntaje(vec, tam);
    cout << "PUNTOS ACTUALES: " << puntos << endl << endl;
}

///CARTEL ENTRE TURNOS
void entreTurno(char nombre[], int nronda, int puntos, bool estado){
    if(estado==true){
        system("cls");
        cout << "---------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\tRONDA N° " <<nronda << " | JUGADOR " << nombre << " | PUNTAJE: " << puntos << endl << endl;
        cout << "---------------------------------------------------------------------------------" << endl << endl;
        cout << endl << endl;
        system("pause");
    }
}

/**
    CARTELES
*/

///CARTEL MENU JUGAR
void cartelJugar(){
cout << endl << endl;
    cout << "\t\t.......##.##.....##..######......###....########.." << endl;
    cout << "\t\t.......##.##.....##.##....##....##.##...##.....##." << endl;
    cout << "\t\t.......##.##.....##.##.........##...##..##.....##." << endl;
    cout << "\t\t.......##.##.....##.##...####.##.....##.########.." << endl;
    cout << "\t\t.##....##.##.....##.##....##..#########.##...##..." << endl;
    cout << "\t\t.##....##.##.....##.##....##..##.....##.##....##.." << endl;
    cout << "\t\t..######...#######...######...##.....##.##.....##." << endl << endl;
    cout << endl << endl;
}

///CARTEL DE PUNTAJE
void cartelPuntaje(){
cout << endl << endl;
    cout << "\t\t.########..##.....##.##....##.########....###..........##.########..######.." << endl;
    cout << "\t\t.##.....##.##.....##.###...##....##......##.##.........##.##.......##....##." << endl;
    cout << "\t\t.##.....##.##.....##.####..##....##.....##...##........##.##.......##......." << endl;
    cout << "\t\t.########..##.....##.##.##.##....##....##.....##.......##.######....######.." << endl;
    cout << "\t\t.##........##.....##.##..####....##....#########.##....##.##.............##." << endl;
    cout << "\t\t.##........##.....##.##...###....##....##.....##.##....##.##.......##....##." << endl;
    cout << "\t\t.##.........#######..##....##....##....##.....##..######..########..######.." << endl << endl;
    cout << endl << endl;
}

///CARTEL GAME OVER
void cartelGameover(char nombre[], int nronda, int puntos){
    system("cls");
    cout << endl << endl;
    cout << "\t\t..######......###....##.....##.########.....#######..##.....##.########.########.." << endl;
    cout << "\t\t.##....##....##.##...###...###.##..........##.....##.##.....##.##.......##.....##." << endl;
    cout << "\t\t.##.........##...##..####.####.##..........##.....##.##.....##.##.......##.....##." << endl;
    cout << "\t\t.##...####.##.....##.##.###.##.######......##.....##.##.....##.######...########.." << endl;
    cout << "\t\t.##....##..#########.##.....##.##..........##.....##..##...##..##.......##...##..." << endl;
    cout << "\t\t.##....##..##.....##.##.....##.##..........##.....##...##.##...##.......##....##.." << endl;
    cout << "\t\t..######...##.....##.##.....##.########.....#######.....###....########.##.....##." << endl << endl;
    cout << endl << endl;
    cout << "\t\t\tNO CONSEGUISTE SACAR GENERALA SERVIDA :( MEJOR SUERTE LA PROXIMA!" << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\tRONDAS TOTALES: " <<nronda << " | JUGADOR: " << nombre << " | PUNTAJE TOTAL: " << puntos << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    cout << endl << endl;
    system("pause");
}

///CARTEL GENERALA!!!
void cartelGenerala(char nombre [], int nRonda, int puntos){
    int c=1;
    system("cls");
    for(int i=0; i<10; i++){
        if(c==1){
            c=2;
            system("color 0a");
        } else {
            c=1;
            system("color 0c");
        }
        cout << "\t\t..######...########.##....##.########.########.....###....##..........###..." << endl;
        cout << "\t\t.##....##..##.......###...##.##.......##.....##...##.##...##.........##.##.." << endl;
        cout << "\t\t.##........##.......####..##.##.......##.....##..##...##..##........##...##." << endl;
        cout << "\t\t.##...####.######...##.##.##.######...########..##.....##.##.......##.....##" << endl;
        cout << "\t\t.##....##..##.......##..####.##.......##...##...#########.##.......#########" << endl;
        cout << "\t\t.##....##..##.......##...###.##.......##....##..##.....##.##.......##.....##" << endl;
        cout << "\t\t..######...########.##....##.########.##.....##.##.....##.########.##.....##" << endl << endl;
        cout << endl << endl;
        system("cls");
    }
    system("color 0a");
        cout << "\t\t..######...########.##....##.########.########.....###....##..........###..." << endl;
        cout << "\t\t.##....##..##.......###...##.##.......##.....##...##.##...##.........##.##.." << endl;
        cout << "\t\t.##........##.......####..##.##.......##.....##..##...##..##........##...##." << endl;
        cout << "\t\t.##...####.######...##.##.##.######...########..##.....##.##.......##.....##" << endl;
        cout << "\t\t.##....##..##.......##..####.##.......##...##...#########.##.......#########" << endl;
        cout << "\t\t.##....##..##.......##...###.##.......##....##..##.....##.##.......##.....##" << endl;
        cout << "\t\t..######...########.##....##.########.##.....##.##.....##.########.##.....##" << endl << endl;
        cout << endl << endl;
    cout << "\t\t-----------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\tGANADOR JUGADOR: " << nombre << " | PUNTAJE TOTAL: " << puntos << " | RONDAS TOTALES: " << nRonda << endl << endl;
    cout << "\t\t-----------------------------------------------------------------------------" << endl << endl;
    system("pause");
}

/**
    DEFINICION DE LAS FUNCIONES PARA EL MODO 2 JUGADORES
*/

///CARGA 2 NOMBRES
void cargarNombreDos(char nombreUno[], char nombreDos[]){
    cin.ignore();
    cout << endl << endl;
    cout << "\t\t.########..####.########.##....##.##.....##.########.##....##.####.########...#######...######." << endl;
    cout << "\t\t.##.....##..##..##.......###...##.##.....##.##.......###...##..##..##.....##.##.....##.##....##" << endl;
    cout << "\t\t.##.....##..##..##.......####..##.##.....##.##.......####..##..##..##.....##.##.....##.##......" << endl;
    cout << "\t\t.########...##..######...##.##.##.##.....##.######...##.##.##..##..##.....##.##.....##..######." << endl;
    cout << "\t\t.##.....##..##..##.......##..####..##...##..##.......##..####..##..##.....##.##.....##.......##" << endl;
    cout << "\t\t.##.....##..##..##.......##...###...##.##...##.......##...###..##..##.....##.##.....##.##....##" << endl;
    cout << "\t\t.########..####.########.##....##....###....########.##....##.####.########...#######...######." << endl << endl;
    cout << endl << endl;
    cout<<"1er Jugador ingrese su nombre para registrarse: ";
    cin.getline(nombreUno,25);
    /// UN WHILE PARA COMPROBAR QUE NO HAYAN INGRESADO UN NOMBRE VACIO
    while(nombreUno[0]=='\0'){
        system("cls");
        cout << endl << endl;
        cout << "\t\t.########..####.########.##....##.##.....##.########.##....##.####.########...#######...######." << endl;
        cout << "\t\t.##.....##..##..##.......###...##.##.....##.##.......###...##..##..##.....##.##.....##.##....##" << endl;
        cout << "\t\t.##.....##..##..##.......####..##.##.....##.##.......####..##..##..##.....##.##.....##.##......" << endl;
        cout << "\t\t.########...##..######...##.##.##.##.....##.######...##.##.##..##..##.....##.##.....##..######." << endl;
        cout << "\t\t.##.....##..##..##.......##..####..##...##..##.......##..####..##..##.....##.##.....##.......##" << endl;
        cout << "\t\t.##.....##..##..##.......##...###...##.##...##.......##...###..##..##.....##.##.....##.##....##" << endl;
        cout << "\t\t.########..####.########.##....##....###....########.##....##.####.########...#######...######." << endl << endl;
        cout << endl << endl;
        cout<<"1er Jugador ingrese su nombre para registrarse: ";
        cin.getline(nombreUno,25);
    }
    cout<< endl;
    cout<<"2do Jugador ingrese su nombre para registrarse: ";
    cin.getline(nombreDos,25);
    while(nombreDos[0]=='\0'){
        system("cls");
        cout << endl << endl;
        cout << "\t\t.########..####.########.##....##.##.....##.########.##....##.####.########...#######...######." << endl;
        cout << "\t\t.##.....##..##..##.......###...##.##.....##.##.......###...##..##..##.....##.##.....##.##....##" << endl;
        cout << "\t\t.##.....##..##..##.......####..##.##.....##.##.......####..##..##..##.....##.##.....##.##......" << endl;
        cout << "\t\t.########...##..######...##.##.##.##.....##.######...##.##.##..##..##.....##.##.....##..######." << endl;
        cout << "\t\t.##.....##..##..##.......##..####..##...##..##.......##..####..##..##.....##.##.....##.......##" << endl;
        cout << "\t\t.##.....##..##..##.......##...###...##.##...##.......##...###..##..##.....##.##.....##.##....##" << endl;
        cout << "\t\t.########..####.########.##....##....###....########.##....##.####.########...#######...######." << endl << endl;
        cout << endl << endl;
        cout<<"2do Jugador ingrese su nombre para registrarse: ";
        cin.getline(nombreDos,25);
    }
    cout<< endl;
    cout << nombreUno<<" y "<< nombreDos<<" listos para continuar?"<< endl << endl;
    system("pause");
}

///RECIBE AMBOS NOMBRES Y PUNTOS DE LOS JUGADORES Y LOS GUARDA EN PUNTAJES
void guardarDatosDos(int puntosUno, int puntosDos, int nRonda, char nombreUno[], char nombreDos[], string guardarNombres[], int guardarPuntajes[], int guardarNumRonda[]){
     int ultimoRegistro, ultimoRegistro2;
     ultimoRegistro = ultimoJugador(guardarPuntajes);
     guardarPuntajes[ultimoRegistro] = puntosUno;
     guardarNombres[ultimoRegistro] = string (nombreUno);
     guardarNumRonda[ultimoRegistro] = nRonda;


    ///GUARDA EL 2DO JUGADOR
     ultimoRegistro2 = ultimoJugador(guardarPuntajes);
     guardarPuntajes[ultimoRegistro2] = puntosDos;
     guardarNombres[ultimoRegistro2] = string (nombreDos);
     guardarNumRonda[ultimoRegistro2] = nRonda;
}

///CARTEL ENTRE TURNOS DOS
void entreTurnoDos(char nombreUno[],char nombreDos[], int nRonda, int puntosUno, int puntosDos, bool proximoTurno){
    system("cls");

    cout << "---------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\tRONDA N° " << nRonda << endl << endl;
    cout << "---------------------------------------------------------------------------------" << endl << endl;
    if(proximoTurno==true){
        cout << "\t\t\tPROXIMO TURNO " << nombreDos << endl << endl;
    }else{
        cout << "\t\t\tPROXIMO TURNO " << nombreUno << endl << endl;
    }
    cout << "\t\tJUGADOR N° 1: " << nombreUno << " | PUNTAJE: " << puntosUno << endl << endl;
    cout << "---------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\tJUGADOR N° 2: " << nombreDos << " | PUNTAJE: " << puntosDos << endl << endl;
    cout << "---------------------------------------------------------------------------------" << endl << endl;
    cout << endl << endl;
    system("pause");
}

///CARTEL GAME OVER DOS
void cartelGameoverDos(char nombreUno[],char nombreDos[], int nRonda, int puntosUno, int puntosDos){
    system("cls");
    int primero, segundo;
    primero = puntosUno;
    segundo = puntosDos;

    cout << endl << endl;
    cout << "\t\t..######......###....##.....##.########.....#######..##.....##.########.########.." << endl;
    cout << "\t\t.##....##....##.##...###...###.##..........##.....##.##.....##.##.......##.....##." << endl;
    cout << "\t\t.##.........##...##..####.####.##..........##.....##.##.....##.##.......##.....##." << endl;
    cout << "\t\t.##...####.##.....##.##.###.##.######......##.....##.##.....##.######...########.." << endl;
    cout << "\t\t.##....##..#########.##.....##.##..........##.....##..##...##..##.......##...##..." << endl;
    cout << "\t\t.##....##..##.....##.##.....##.##..........##.....##...##.##...##.......##....##.." << endl;
    cout << "\t\t..######...##.....##.##.....##.########.....#######.....###....########.##.....##." << endl << endl;
    cout << endl << endl;
    cout << "\t\t\tNO CONSEGUIERON SACAR GENERALA SERVIDA :( MEJOR SUERTE LA PROXIMA!" << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\t\tRONDAS TOTALES: " <<nRonda << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    if(primero > segundo){

    cout << "\t\t\t\tGANADOR JUGADOR: " << nombreUno << " | PUNTAJE TOTAL: " << puntosUno << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\tPERDEDOR JUGADOR: " << nombreDos << " | PUNTAJE TOTAL: " << puntosDos << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;

    }else{if(segundo > primero){

    cout << "\t\t\t\tGANADOR JUGADOR: " << nombreDos << " | PUNTAJE TOTAL: " << puntosDos << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\tPERDEDOR JUGADOR: " << nombreUno << " | PUNTAJE TOTAL: " << puntosUno << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;

    }else{

    cout << "\t\t\t\t\tEMPATE AMBOS JUGADORES"<< endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\tJUGADOR: " << nombreUno << " | JUGADOR: " << nombreDos << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\tOBTUVIERON EL MISMO PUNTAJE TOTAL: " << puntosUno << endl << endl;
    cout << "\t\t---------------------------------------------------------------------------------" << endl << endl;
    }
}
    cout << endl << endl;
    system("pause");
}
