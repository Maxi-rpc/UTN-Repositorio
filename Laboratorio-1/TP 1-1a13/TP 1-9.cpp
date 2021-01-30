#include <iostream>
using namespace std;
int main(){

    int camin;
    int horas;
    int minutos;
    int mins;
    mins=60;

    cout<<"Ingresar cantidad de minutos: "<<endl;
    cin>>camin;

    horas=camin/mins;
    minutos=camin%mins;

    cout<<"Equivale a: "<<horas<<" horas"<<endl;
    cout<<"Equivale a: "<<minutos<<" minutos"<<endl;

  return 0;
}
