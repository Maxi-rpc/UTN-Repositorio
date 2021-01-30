#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int aux;

    cout<<"Ingresar el primer numero"<<endl;
    cin>>n1;
    cout<<"Ingresar el segundo numero"<<endl;
    cin>>n2;
    aux=n1;
    n1=n2;
    n2=aux;
    cout<<"numeros ingresados: "<<n1<<","<<n2<<endl;

  return 0;
}
