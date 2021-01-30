#include <iostream>
using namespace std;
int main(){

    int canh;
    int dias;
    int horas;
    int hs;

    hs=24;

    cout<<"Ingresar cantidad de horas: "<<endl;
    cin>>canh;

    dias=canh/hs;
    horas=canh%hs;

    cout<<"Equivale a : "<<dias<<" dias y "<<horas<<" horas"<<endl;


  return 0;
}
