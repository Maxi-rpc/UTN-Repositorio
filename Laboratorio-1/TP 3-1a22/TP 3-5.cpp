#include <iostream>
using namespace std;
int main(){

    int n1, n2, may, men;

    cout<<"Ingresar primer numero:"<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero:"<<endl;
    cin>>n2;

    if(n1>n2){may=n1 , men=n2;}
    else{may=n2 , men=n1;}

    for(int v=men; v<may-1; v++)
{
    cout<<v<<endl;

    }

  return 0;
}
