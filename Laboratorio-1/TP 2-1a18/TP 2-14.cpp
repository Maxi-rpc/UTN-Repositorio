#include <iostream>
using namespace std;
int main(){

    int dian;
    int mesn;
    int anon;
    int dia;
    int mes;
    int ano;
    int edad;
    int an;

    cout<<"Ingresar fecha de nacimiento:"<<endl;
    cout<<"Ingresar dia:"<<endl;
    cin>>dian;
    cout<<"Ingresar mes:"<<endl;
    cin>>mesn;
    cout<<"Ingresar ano:"<<endl;
    cin>>anon;

    cout<<"Ingresar fecha actual:"<<endl;
    cout<<"Ingresar dia:"<<endl;
    cin>>dia;
    cout<<"Ingresar mes:"<<endl;
    cin>>mes;
    cout<<"Ingresar ano:"<<endl;
    cin>>ano;

    an=ano-anon;
    if(mes>=mesn && dia>=dian) {edad=an;}
    else {edad=an-1;}


    cout<<"La edad actual es: "<<edad<<endl;

  return 0;
}
