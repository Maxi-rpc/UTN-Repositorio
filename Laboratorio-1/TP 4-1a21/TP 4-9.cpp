#include <iostream>
using namespace std;
int main(){
    int n, mi, may;
    cout<<"Ingresar numero: ";
    cin>>n;
    may=n;
    cout<<"Ingresar numero: ";
    cin>>n;
    if(n>may){mi=may , may=n;}
    else{mi=n;}

    while(n!=0){
            cout<<"Ingresar numero: ";
    cin>>n;
    if(n!=0){
            if(n>may){may=n;}
            else{if(n<mi){mi=n;}
            }
            }

}
    cout<<"El maximo es: "<<may<<endl;
    cout<<"El minimi es: "<<mi<<endl;


  return 0;
}
