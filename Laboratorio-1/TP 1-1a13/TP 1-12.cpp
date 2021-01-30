#include <iostream>
using namespace std;
int main(){

    int canh;
    int caja;
    int huevs;
    int prec;
    int prehs;
    int imcaj;
    int imhs;
    int imt;

    caja=12;
    prec=100;
    prehs=12;

    cout<<"Ingresar la cantidad de huevos: "<<endl;
    cin>>canh;

    imcaj=(canh/caja)*100;
    imhs=(canh%caja)*prehs;
    imt=imcaj+imhs;
    cout<<"Importe total a pagar: $"<<imt<<endl;



  return 0;
}
