#include <iostream>
using namespace std;
int main(){

    int canm;
    int dias;
    int horas;
    int minutos;
    int hs;
    int mins;

    hs=1440;
    mins=60;

    cout<<"Ingresar cantidad de minutos: "<<endl;
    cin>>canm;

    dias=canm/hs;
    horas=(canm%hs)/mins;
    minutos=(canm%hs)%mins;

    cout<<"Equivale a : "<<dias<<" dia(s), "<<horas<<" hora(s) y "<<minutos<<" minuto(s)"<<endl;


  return 0;
}
