#include <iostream>
using namespace std;
int main(){
    int n,r;
    cout<<"Ingresar numero"<<endl;
    cin>>n;
    cout<<"Sus divisores son: "<<endl;

    for(int i=1; i<=n; i++)
{
    r=n%i;
    if(r==0){if(i%2==0){cout<<i<<endl;}
                }

}

  return 0;
}
