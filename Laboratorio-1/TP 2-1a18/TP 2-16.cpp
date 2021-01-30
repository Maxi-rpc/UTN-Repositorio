#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int n3;
    int n4;

    cout<<"Ingresar la primer nota de los examenes:"<<endl;
    cin>>n1;
    cout<<"Ingresar la segunda nota de los examenes:"<<endl;
    cin>>n2;
    cout<<"Ingresar la tercer nota de los examenes:"<<endl;
    cin>>n3;
    cout<<"Ingresar la cuarta nota de los examenes:"<<endl;
    cin>>n4;

    if(n1,n2,n3,n4>=7) {cout<<"Promociona."<<endl;}
    else{if(n1,n2,n3>=4 || n2,n3,n4>=4 || n1,n3,n4>=4){cout<<"Rinde examen final."<<endl;}
    else{if(n1,n2,n3,n4<4){cout<<"Recursa la materia."<<endl;}
    else{cout<<"Recupera parciales."<<endl;}
    }
    }

  return 0;
}
