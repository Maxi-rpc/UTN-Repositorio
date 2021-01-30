#include <iostream>
using namespace std;
int main(){

    int imp;
    int d5;
    int d10;
    int d15;
    int impcd;

    d5=95;
    d10=90;
    d15=85;

    cout<<"Ingresar importe original: "<<endl;
    cin>>imp;

    if(imp<100) {
        impcd=(imp*d5)/100;
    } else {if(imp<=500) {
    impcd=(imp*d10)/100;
    } else {
        impcd=(imp*d15)/100;}
    }
    cout<<"El importe con descuento es de: $"<<impcd<<endl;


  return 0;
}
