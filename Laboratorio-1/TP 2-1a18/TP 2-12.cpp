#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int n3;
    int pos1;
    int pos2;
    int pos3;

    cout<<"Ingresar primer numero:"<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero:"<<endl;
    cin>>n2;
    cout<<"Ingresar tercer numero:"<<endl;
    cin>>n3;

    if(n1>n2) {
            pos1=n1;
            pos2=n2;
    }
    else {
            pos1=n2;
            pos2=n1;
    }
    if(n3>pos1) {
            pos3=pos2;
            pos2=pos1;
            pos1=n3;
    } else {if(n3>pos2){
    pos3=pos2;
    pos2=n3;}
    else {pos3=n3;}
    }

    cout<<"El orden de menor a mayor es: "<<pos3<<","<<pos2<<","<<pos1<<endl;

  return 0;
}
