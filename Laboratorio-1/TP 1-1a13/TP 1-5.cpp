#include <iostream>
using namespace std;
int main(){

    float a;
    float b;
    float c;
    float t;
    float pt;
    float pa;
    float pb;
    float pc;
    pt=100;

    cout<<"Ingresar cantidad vendida de A: "<<endl;
    cin>>a;
    cout<<"Ingresar cantidad vendida de B: "<<endl;
    cin>>b;
    cout<<"Ingresar cantidad vendida de C: "<<endl;
    cin>>c;

    t=a+b+c;
    pa=(a*pt)/t;
    pb=(b*pt)/t;
    pc=(c*pt)/t;

    cout<<"Porcentaje de A: "<<pa<<"%"<<endl;
    cout<<"Porcentaje de A: "<<pb<<"%"<<endl;
    cout<<"Porcentaje de A: "<<pc<<"%"<<endl;

  return 0;
}
