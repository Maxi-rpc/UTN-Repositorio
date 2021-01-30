#include <iostream>
using namespace std;
int main(){
    int n,n1,m1,m2;

    cout<<"Ingresar numero:"<<endl;
    cin>>n1;
    m1=n1;
    for(int i=1; i<5; i++)
{
    cout<<"Ingresar numero:"<<endl;
    cin>>n;
    if(n>=m1){m2=m1 , m1=n;}
    else{if(n>=m2){m2=n;}

    }

}
cout<<"Resultado: "<<m1<<","<<m2<<endl;

  return 0;
}
