#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
/// SE CREA OBJETO BOTELLA
class Botella{
private:
    float capacidad;
    float ocupacion;
    bool tapada;

public:
    void setLlenar(float);
    void setVaciar();
    void setVaciar(float);
    void setTapar();
    void setDestapar();
    Botella(float);
    float getCapacidad();
    float getOcupacion();
    float getDisponibilidad();
    void getInfoBotella();
    bool getTapada();
};
// SE CREAN METODOS
Botella::Botella(float cap){
    capacidad = 100;
    ocupacion = 0;
    tapada = true;
    if(cap != 0){
        capacidad = cap;
    }
    cout << "*Se creo nueva Botella con " << capacidad << " ml." << endl;
    cout << "-Su ocupacion es de " << ocupacion << " ml."<< endl;
}

void Botella::setLlenar(float aumentar){
    if(aumentar <= capacidad){
        ocupacion += aumentar;
    }
    if(ocupacion >= capacidad){
        ocupacion = capacidad;
    }
}

float Botella::getCapacidad(){
    return capacidad;
}

float Botella::getOcupacion(){
    return ocupacion;
}

float Botella::getDisponibilidad(){
    float disponibilidad = capacidad - ocupacion;
    return disponibilidad;
}

void Botella::setVaciar(float disminuir){
    if(ocupacion > 0){
        ocupacion -= disminuir;
    }
    if(ocupacion <= 0){
        ocupacion = 0;
    }
}

void Botella::setVaciar(){
    ocupacion = 0;
}

void Botella::setTapar(){
    tapada = false; ///LA BOTELLA SE TAPA
}

void Botella::setDestapar(){
    tapada = true; ///LA BOTELLA SE DESTAPA
}

bool Botella::getTapada(){
    return tapada;
}

void Botella::getInfoBotella(){
    cout << "INFO DE LA BOTELLA: "<< endl;
    cout << "CAPACIDAD: " << getCapacidad() << " ml" << endl;
    cout << "OCUPACIÓN: " << getOcupacion() << " ml" << endl;
    cout << "DISPONIBILIDAD: " << getDisponibilidad() << " ml" << endl;
    cout << "TAPADA: ";
    if(tapada){
        cout << "NO" << endl;
    } else{cout << "SI" << endl;}

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
        cout << "3) VACIAR (VACÍA POR COMPLETO)" << endl;
        cout << "4) TAPAR BOTELLA" << endl;
        cout << "5) DESTAPAR BOTELLA" << endl;
        cout << "6) VER INFO DE BOTELLA" << endl;
        cout << "------------------" << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;
        cout << endl;

        switch(pos){
            case 1:
                if(bot.getTapada() == false){
                    msj("DESTAPAR LA BOTELLA PRIMERO", rlutil::WHITE, rlutil::RED);
                } else {
                    cout << "INDIQUE N° DE ml PARA AUMENTAR SU OCUPACION: "<< endl;
                    cout << endl << "> ";
                    float aumentar;
                    cin >> aumentar;
                    bot.setLlenar(aumentar);
                    cout<< "LA OCUPACIÓN ACTUAL ES: " << bot.getOcupacion() << endl;
                    anykey();
                }
            break;
            case 2:
                if(bot.getTapada() == false){
                    msj("DESTAPAR LA BOTELLA PRIMERO", rlutil::WHITE, rlutil::RED);
                } else {
                    cout << "INDIQUE N° DE ml PARA DISMINUIR SU OCUPACION: "<< endl;
                    cout << endl << "> ";
                    float disminuir;
                    cin >> disminuir;
                    bot.setVaciar(disminuir);
                    cout<< "LA OCUPACIÓN ACTUAL ES: " << bot.getOcupacion() << endl;
                    anykey();
                }
            break;
            case 3:
                if(bot.getTapada() == false){
                    msj("DESTAPAR LA BOTELLA PRIMERO", rlutil::WHITE, rlutil::RED);
                } else {
                    cout << "SE VACÍA POR COMPLETO EL CONTENIDO DE LA BOTELLA: "<< endl;
                    bot.setVaciar();
                    cout<< "LA OCUPACIÓN ACTUAL ES: " << bot.getOcupacion() << endl;
                    anykey();
                }
            break;
            case 4:
                if(bot.getTapada() == false){
                    msj("LA BOTELLA YA ESTA TAPADA", rlutil::WHITE, rlutil::RED);
                } else {
                    msj("SE TAPA LA BOTELLA", rlutil::WHITE, rlutil::GREEN);
                    bot.setTapar();
                }
            break;
            case 5:
                if(bot.getTapada() == true){
                    msj("LA BOTELLA YA ESTA DESTAPADA", rlutil::WHITE, rlutil::RED);
                } else {
                    msj("SE DESTAPA LA BOTELLA", rlutil::WHITE, rlutil::GREEN);
                    bot.setDestapar();
                }
            break;
            case 6:
                bot.getInfoBotella();
                anykey();
            break;
            case 0:
                return 0;
            break;
        }
    }
}
