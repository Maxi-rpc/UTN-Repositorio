#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int da;

    cout<<"Ingresar el primer numero:"<<endl;
    cin>>n1;
    cout<<"Ingresar el segundo numero:"<<endl;
    cin>>n2;

    if(n1>n2) {
        da=n1-n2;
    } else {
        da=n2-n1;
    }
    cout<<"La diferencia absoluta es: "<<da<<endl;


  return 0;
}
