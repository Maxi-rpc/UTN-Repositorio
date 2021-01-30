#include <iostream>
using namespace std;
int main(){

    int imp;
    int bmil;
    int bquin;
    int bdos;
    int bcien;
    int bme;
    int bqe;
    int bde;
    int bce;

    bmil=1000;
    bquin=500;
    bdos=200;
    bcien=100;

    cout<<"Ingresar importe a retirar: "<<endl;
    cin>>imp;

    bme=imp/bmil;
    bqe=(imp%bmil)/bquin;
    bde=((imp%bmil)%bquin)/bdos;
    bce=(((imp%bmil)%bquin)%bdos)/bcien;

    cout<<"Se entregan "<<bme<<" billete(s) de $1000, "<<bqe<<
    " billete(s) de $500, "<<bde<<" billete(s) de $200, "<<bce<<
    " billete(s) de $100.";



  return 0;
}
