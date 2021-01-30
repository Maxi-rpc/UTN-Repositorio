#include <iostream>
using namespace std;
int main(){

    int ano;

    cout<<"Ingresar ano:"<<endl;
    cin>>ano;

    if(ano%400==0){cout<<"Es biciesto."<<endl;}
    else{if(ano%4==0 && ano%100!=0) {cout<<"Es biciesto."<<endl;}
    else{cout<<"No es biciesto."<<endl;}
    }


  return 0;
}
