#include <iostream>
using namespace std;
int main(){
    int n,m=0,pos;

    for(int v=0; v<10; v++)
{
    cout<<"ingresar numero"<<endl;
    cin>>n;
    if(n>m){m=n,pos=v;}
    else{}

}
   cout<<"El maximo es: "<<m<<endl;
   cout<<"En la posicion: "<<pos+1<<endl;

  return 0;
}
