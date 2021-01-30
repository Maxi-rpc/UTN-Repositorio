#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int n3;
    int n4;

    cout<<"Ingresar las 4 notas de los examenes:"<< endl;
    cin >>n1;
    cin >>n2;
    cin >>n3;
    cin >>n4;

    if(n1,n2,n3,n4>=7) {
        cout<<"Promociona";
    } else{if((n1,n2,n3 >=4) || (n1,n2,n4 >=4) || (n2,n3,n4 >=4)) {
    cout<<"Rinde examen final";}
    else{if((n1>=4) || (n2>=4) || (n3>=4) || (n4>=4)) {
        cout<<"Recupera parciales";}
        else{cout<<"Recursa la materia";}
             }
    }

  return 0;
}
