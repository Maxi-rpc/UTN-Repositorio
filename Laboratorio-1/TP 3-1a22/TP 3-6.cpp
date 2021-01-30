#include <iostream>
using namespace std;
int main(){
    int n,num,pos=0;
    cout<<"Ingresar valor N:"<<endl;
    cin>>n;

    for(int v=0; v<n; v++)
{
    cout<<"ingresar numero"<<endl;
    cin>>num;
    if(num>0){pos++;}
    else{}
}
   cout<<"Numeros positivos: "<<pos<<endl;
  return 0;
}
