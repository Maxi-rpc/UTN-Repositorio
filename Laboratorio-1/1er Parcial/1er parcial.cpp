#include <iostream>
using namespace std;
int main(){

    int ncartero, dia, cantenv;
    float import, promedio;
    int i, c;
    int cantenvtot;
    float rectotal=0, rectotalc;
    int cartmenrep=0, ncarteroant, menenvi;

    for(int c=1; c<=40; c++){
        cout<<"Numero de cartero: "<<endl;
        cin>>ncartero;
        promedio=0;
        cantenvtot=0;
        ncarteroant = ncartero;
        rectotalc=0;

    for(int i=1; i<=30; i++){
        dia=i;
        cout<<"Dia: "<<dia<<endl;
        cout<<"Cantidad de envios realizados: "<<endl;
        cin>>cantenv;
        cout<<"Importe total recaudado: "<<endl;
        cin>>import;
        cantenvtot+=cantenv;
        rectotal+=import;
        rectotalc+=import;

        }
    if(cartmenrep==0){menenvi = cantenvtot,
    cartmenrep = ncarteroant;
   } else {if( cantenvtot < menenvi){cartmenrep = ncarteroant; }
   }
    promedio=rectotalc/cantenvtot;
    ///PUNTO A
        cout<<"Promedio de recaudacion: "<<promedio<<endl;
    }

        ///PUNTO B
        cout<<"PUNTO B, Cartero que menos repartos hizo: "<<cartmenrep<<endl;
        ///PUNTO C
        cout<<"PUNTO C, Recaudacion de todo el mes: "<<rectotal<<endl;



    return 0;
}
