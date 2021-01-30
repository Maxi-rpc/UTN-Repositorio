#include <iostream>
using namespace std;
int main(){

    int impvsd;
    int impvcd;
    int pdd;
    int pt;

    pt=100;

    cout<<"Ingresar impor de la venta sin descuento: "<<endl;
    cin>>impvsd;
    cout<<"Ingresar impor de la venta con descuento: "<<endl;
    cin>>impvcd;

    pdd=pt-((impvcd*pt)/impvsd);

    cout<<"El porcentaje de descuento aplicado es de: "<<pdd<<"%"<<endl;

  return 0;
}
