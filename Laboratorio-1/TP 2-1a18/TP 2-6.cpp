#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int n3;

    cout<<"Ingresar primer numero:"<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero:"<<endl;
    cin>>n2;
    cout<<"Ingresar tercer numero:"<<endl;
    cin>>n3;

    if(n1==n2 && n2==n3) {
        cout<<"Los tres numeros son iguales"<<endl;
    }


  return 0;
}
