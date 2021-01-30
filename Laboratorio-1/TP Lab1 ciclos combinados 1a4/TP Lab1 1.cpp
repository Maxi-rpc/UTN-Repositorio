#include <iostream>
using namespace std;
int main(){
    int coddest, numm, cantpv;
    float totr;
    int cantpvt=0;
    int coddesta;
    float totrec;

    cout<<"Codigo de destino:"<<endl;
     cin>>coddest;

    for(int i=1; i<=12; i++){

    coddesta=coddest;
    totrec=0;

    while(coddest==coddesta){
        cout<<"Numer de mes:"<<endl;
         cin>>numm;
        cout<<"Cantidad de pasajes vendidos:"<<endl;
         cin>>cantpv;
         cantpvt+=cantpv;
        cout<<"Total recaudado"<<endl;
         cin>>totr;
        totrec+=totr;
        cout<<"Codigo de destino:"<<endl;
     cin>>coddest;
    }
    cout<<"Total recaudado en el destino: "<<coddesta<<endl;
    cout<<totrec<<endl;

}
    cout<<"Cantidad de pasajes vendido en 2018"<<cantpvt<<endl;

  return 0;
}
