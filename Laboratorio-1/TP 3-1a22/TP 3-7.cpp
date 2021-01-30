#include <iostream>
using namespace std;
int main(){
    int n,num,pos=0,neg=0,cero=0;
    cout<<"Ingresar valor N:"<<endl;
    cin>>n;

    for(int v=0; v<n; v++)
{
    cout<<"ingresar numero"<<endl;
    cin>>num;
    if(num>0){pos++;}
    else{
            if(num<0){neg++;}
    else{cero++;}
    }
}
   cout<<"Numeros positivos: "<<pos<<endl;
   cout<<"Numeros negativos: "<<neg<<endl;
   cout<<"Numeros iguales a cero: "<<cero<<endl;

  return 0;
}
