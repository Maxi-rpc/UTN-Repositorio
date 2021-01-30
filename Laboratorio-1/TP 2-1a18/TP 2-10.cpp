#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int may;

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

    if(n1>n2) {
            may=n1;
    }
    else{
            may=n2;
    }
    if(n3>may) {
            may=n3;
    } else {}
    if(n4>may){
        may=n4;
    } else {}
    if(n5>may) {
        may=n5;
    } else {}

    cout<<"El maximo de los tres es: "<<may<<endl;

  return 0;
}
