#include <iostream>
using namespace std;
int main(){
    int n1, n2, men, may;
    cout<<"Ingresar primer numero:"<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero:"<<endl;
    cin>>n2;
    if(n1>n2){may=n1 , men=n2;}
    else{men=n1 , may=n2;}

    while(men<may){

    cout<<men<<endl;
    men++;
}

  return 0;
}
