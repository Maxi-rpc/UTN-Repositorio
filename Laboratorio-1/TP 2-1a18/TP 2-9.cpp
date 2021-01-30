#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int n3;
    int may;

    cout<<"Ingresar primer numero:"<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero:"<<endl;
    cin>>n2;
    cout<<"Ingresar tercer numero:"<<endl;
    cin>>n3;

    if(n1>n2) {
            may=n1;
    }
    else{
            may=n2;
    }
    if(n3>may) {
            may=n3;
    } else {}

    cout<<"El maximo de los tres es: "<<may<<endl;

  return 0;
}
