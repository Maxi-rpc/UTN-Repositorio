#include <iostream>
#include <windows.h>/// para las funciones system... pause, cls..
#include <locale.h>/// para el setlocale(LC_ALL)

using namespace std;

#include "funciones.h"

int main()
{
    setlocale(LC_ALL, "Spanish");
    system("color 0a");
    const int tam = 5;
    int vec[tam];
    int opc;
    char sn;
    string guardarNombres[30];
    int guardarPuntajes[30];
    int guardarNumRonda[30];
    ponerCero(guardarPuntajes, 30);
    ponerCero(guardarNumRonda, 30);

    while(true){
        system("cls");
        cout << endl << endl;
        cout << "\t\t ..######...########.##....##.########.########.....###....##..........###... " << endl;
        cout << "\t\t .##....##..##.......###...##.##.......##.....##...##.##...##.........##.##.. " << endl;
        cout << "\t\t .##........##.......####..##.##.......##.....##..##...##..##........##...##. " << endl;
        cout << "\t\t .##...####.######...##.##.##.######...########..##.....##.##.......##.....## " << endl;
        cout << "\t\t .##....##..##.......##..####.##.......##...##...#########.##.......######### " << endl;
        cout << "\t\t .##....##..##.......##...###.##.......##....##..##.....##.##.......##.....## " << endl;
        cout << "\t\t ..######...########.##....##.########.##.....##.##.....##.########.##.....## " << endl << endl;
        cout << "1. Jugar " << endl;
        cout << "2. Puntajes " << endl;
        cout << "3. Reglas " << endl;
        cout << "4. Salir " << endl << endl;
        cout << "Ingrese la opción deseada: ";
        opc = validarIngreso(opc, 1, 4);
        system("cls");
        switch(opc){
            case 1: subMenuJugar(vec, tam, guardarNombres, guardarPuntajes, guardarNumRonda);
                break;
            case 2: subMenuPuntaje(guardarNombres, guardarPuntajes, guardarNumRonda);
                break;
            case 3: subMenuReglamento();
                break;
            case 4: cout << endl << "¿ESTA SEGURO QUE DESEA SALIR? (S/N): ";
                cin >> sn;
                if(sn=='S' || sn=='s'){
                    system("cls");
                    cout << endl << "\t\tDESARROLLADO POR CRISTIAN UHRIG Y MAXIMILIANO MIRANDA - TUP 1 AÑO - UTN FRGP" << endl << endl;
                    cout << endl << "¡Vuelvas prontos!" << endl << endl;
                    return 0;
                }
                break;
            default: cout << endl << "Ingrese una opción correcta (1-4)" << endl << endl;
                    system("pause");
        }

    }

    return 0;
}
