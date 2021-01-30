#include <iostream>
using namespace std;
int main(){
    int n1,n,ord=0;

    for(int i=0; i<8; i++)
{
    cout<<"Ingresar numero:"<<endl;
    cin>>n;
    if(i==0){n1=n;}
    else{if(n>=n1){n1=n , ord++;}
    else{}

    }

}
    if(ord==7){cout<<"Conjunto ordenado"<<endl;}
    else{cout<<"Conjunto no ordenado"<<endl;}

  return 0;
}
