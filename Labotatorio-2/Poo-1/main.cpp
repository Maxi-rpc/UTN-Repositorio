#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

class Botella{
private:
    float capacidad;
    float ocupacion;
    bool tapada;

public:
    void setLlenar(float);
    void setVaciar();
    void setVaciar(float);
    void getTapar();
    void getDestapar();
    Botella(float);
    float getCapacidad();
    float getOcupacion();
    float getDisponibilidad();
};

Botella::Botella(float cap){
    capacidad = 100;
    ocupacion = 0;
    if(cap != 0){
        capacidad = cap;
    }
    cout << "*Se creo nueva Botella con " << capacidad << " ml." << endl;
    cout << "-Su ocupacion es de " << ocupacion << " ml."<< endl;
}

void Botella::setLlenar(float aumentar){
    ocupacion += aumentar;
}

float Botella::getOcupacion(){
    return ocupacion;
}
int main()
{
    initUI();
    title("HELLO WORLD TP POO-1", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    gotoxy(1, 5);
    cout << "Ingresar Capacidad de la botella (por defecto 100 ml)" << endl;
    float inicial;
    cout << "> ";
    cin >> inicial;
    Botella bot(inicial);

    while(true){
        cls();
        title("HELLO WORLD TP POO-1", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5);

        cout << " " << endl;
        cout << "1) LLENAR (DEBE SER MENOR A LA CAPACIDAD INDICADA)" << endl;
        cout << "2) VACIAR DE A POCO" << endl;
        cout << "3) VACIAR" << endl;
        cout << "4) TAPAR BOTELLA" << endl;
        cout << "5) DESTAPAR BOTELLA" << endl;
        cout << "6) VER INFO DE BOTELLA" << endl;
        cout << "------------------" << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                cout << "INDIQUE N° DE ml PARA AUMENTAR SU OCUPACION: "<< endl;
                cout << endl << "> ";
                float aumentar;
                cin >> aumentar;
                bot.setLlenar(aumentar);
                cout<< "LA OCUPACIÓN ACTUAL ES: " << bot.getOcupacion() << endl;
                anykey();
            break;
            case 2:
                //menuEntrenamientos();
            break;
            case 3:
                //menuReportes();
            break;
            case 4:
                //menuConfiguracion();
            break;
            case 5:
                //menuConfiguracion();
            break;
            case 6:
                //menuConfiguracion();
            break;
            case 0:
                return 0;
            break;
        }
    }
}
