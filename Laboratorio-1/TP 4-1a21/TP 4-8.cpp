#include <iostream>
using namespace std;
int main(){
    int n, nmax=0, cont=0, pos;
    cout<<"Ingresar un numero: ";
            cin>>n;
            nmax=n;
            cont++;


    while(n!=0){
            if(n>nmax){nmax=n , pos=cont;}
            cont++;
            cout<<"Ingresar un numero: ";
            cin>>n;
}
        cout<<"El maximo es: "<<nmax<<endl;
        cout<<"La posicion es: "<<pos<<endl;

  return 0;
}
