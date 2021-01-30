#include <iostream>
using namespace std;
int main(){
    int pr=0, se=0, n;
    cout<<"Ingresar numero: ";
    cin>>n;

    while(n!=0){
           if(n%2!=0){
                if(pr==0){pr=n;}
           else{if(se==0){se=n;}
            }
            }
    cout<<"Ingresar numero: ";
    cin>>n;
}
    cout<<"El primer numero impar: "<<pr<<endl;
    cout<<"El segundo numero impar: "<<se<<endl;

  return 0;
}
