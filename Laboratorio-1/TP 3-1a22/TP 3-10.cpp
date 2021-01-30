#include <iostream>
using namespace std;
int main(){
    int n,ma,mi;
    cout<<"ingresar numero"<<endl;
    cin>>n;
    ma=n;
    mi=n;

    for(int v=2; v<11; v++)
{
    cout<<"ingresar numero"<<endl;
    cin>>n;
    if(n<mi){mi=n;}
    else{if(n>ma){ma=n;}

    }

}
   cout<<"El maximo es: "<<ma<<endl;
   cout<<"El minimo es: "<<mi<<endl;

  return 0;
}
