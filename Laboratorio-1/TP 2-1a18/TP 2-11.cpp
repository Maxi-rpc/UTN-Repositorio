#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int pos;
    pos=0;

    cout<<"Ingresar primer numero:"<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero:"<<endl;
    cin>>n2;
    cout<<"Ingresar tercer numero:"<<endl;
    cin>>n3;
    cout<<"Ingresar cuarto numero:"<<endl;
    cin>>n4;
    cout<<"Ingresar quinto numero:"<<endl;
    cin>>n5;

    if(n1>0) {
            pos++;}
    else{};
    if(n2>0) {pos++;}
    else{};
    if(n3>0) {pos++;}
    else{};
    if(n4>0) {pos++;}
    else{};
    if(n5>0) {pos++;}
    else{};

    cout<<"Los numeros positivos son: "<<pos<<endl;

  return 0;
}
