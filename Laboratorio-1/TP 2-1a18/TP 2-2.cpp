#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;

    cout<<"Ingresar primer numero: "<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero: "<<endl;
    cin>>n2;

    if(n1%n2==0) {
        cout<<"El primer numero es multiplo del segundo"<<endl;
        } else {
        cout<<"El primer numero no es multiplo del segundo"<<endl;
        }

  return 0;
}
