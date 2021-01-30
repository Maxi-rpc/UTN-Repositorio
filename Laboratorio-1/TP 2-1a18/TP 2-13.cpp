#include <iostream>
using namespace std;
int main(){

    int n1;
    int n2;
    int n3;
    int med;

    cout<<"Ingresar primer numero:"<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero:"<<endl;
    cin>>n2;
    cout<<"Ingresar tercer numero:"<<endl;
    cin>>n3;

    if(n1>n2 && n1<n3 || n1<n2 && n1>n3) {med=n1;}
    else{if(n2>n1 && n2<n3 || n2<n1 && n2>n3) {med=n2;}
    else{n3>n2 && n3<n1 || n3<n2 && n3>n1;} {med=n3;}

    }
    cout<<"El numero del medio es:"<<med<<endl;


  return 0;
}
