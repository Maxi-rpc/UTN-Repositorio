#include <iostream>
using namespace std;
int main(){

    int cont=0, b=0, n;

    for(int i=0; i<10; i++)
{
    cout<<"Ingresar numero:"<<endl;
    cin>>n;
    if(n%2!=0){if(b==0){b=1;}
    else{cont++;}
    } else {b=0;}
}

    cout<<"Las duplas son: "<<cont<<endl;

  return 0;
}
