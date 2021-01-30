#include <iostream>
using namespace std;
int main(){
    int n,nmax=0,pmin=0;

    for(int v=1; v<11; v++)
{
    cout<<"ingresar numero"<<endl;
    cin>>n;
    if(n>0){
        if(pmin==0){
            pmin=n;
        }else{
        if(n<pmin){
            pmin=n;
        }
        }
    }else{
        if(nmax==0){
            nmax=n;
        }else{
            if(n>nmax){
                nmax=n;
            }
            }
        }
}
   cout<<"El maximo de los negativos: "<<nmax<<endl;
   cout<<"El minimo de los positivos: "<<pmin<<endl;

  return 0;
}
