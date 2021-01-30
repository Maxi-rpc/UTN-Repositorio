#include <iostream>
using namespace std;
int main(){
    int n1, n, nmax=0;

    cout<<"Ingresar un numero: ";
    cin>>n1;

    while(n!=0){
            cout<<"Ingresar un numero: ";
            cin>>n;
            if(nmax==0){if(n1>n){nmax=n1;}
            else{nmax=n;}
            }else{if(n>nmax){nmax=n;}
            }
}
        cout<<"El maximo es: "<<nmax<<endl;

  return 0;
}
