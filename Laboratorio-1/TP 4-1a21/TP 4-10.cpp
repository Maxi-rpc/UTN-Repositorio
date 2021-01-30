#include <iostream>
using namespace std;
int main(){
    int pos=0, neg=0, n;
    cout<<"Ingresar numero: ";
    cin>>n;

    while(n!=0){
           if(n>0){if(pos==0){pos=n;}
           else{if(n<pos){pos=n;}
           }
           }else{if(neg==0){neg=n;}
           else{if(n>neg){neg=n;}
           }
           }
    cout<<"Ingresar numero: ";
    cin>>n;
}
    cout<<"Maximo negativo: "<<neg<<endl;
    cout<<"Minimo positivo: "<<pos<<endl;


  return 0;
}
