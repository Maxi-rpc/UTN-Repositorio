#include <iostream>
using namespace std;
int main(){
    int n,r,d=0;
    cout<<"Ingresar numero"<<endl;
    cin>>n;

    for(int i=1; i<=n; i++)
{

    r=n%i;
    if(r==0){d++;}

}
    if(d==2){cout<<"El numero es primo"<<endl;}
    else{cout<<"El numero no es primo"<<endl;}


  return 0;
}
