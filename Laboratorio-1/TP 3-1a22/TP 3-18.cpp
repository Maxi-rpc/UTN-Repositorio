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

    cout<<d<<" Divisores."<<endl;

  return 0;
}
