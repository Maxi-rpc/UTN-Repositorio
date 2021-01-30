#include <iostream>
using namespace std;
int main(){

    int cad;
    int cpo;
    int po;
    int pd;
    int pt;

    pt=100;

    cout<<"Ingresar cantidad de asientos disponibles"<<endl;
    cin>>cad;
    cout<<"ingresar cantidad de pasajes ocupados"<<endl;
    cin>>cpo;

    po=(cpo*pt)/cad;
    pd=pt-po;

    cout<<"El porcentaje de ocupacion: "<<po<<"%"<<endl;
    cout<<"El porcentaje de no ocupacion: "<<pd<<"%"<<endl;





  return 0;
}
