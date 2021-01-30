#include <iostream>
using namespace std;
int main (){
    int n;
    int vec[10];
    int sumav=0;
    for(int i=0; i<10; i++)
    {
        cout<<"Ingresar numero: "<<endl;
        cin>>n;
         vec[i]=n;
    }
    for(int x=0; x<10; x++)
    {
        sumav+=vec[x];
    }
        cout<<"La suma es: "<<sumav<<endl;

    return 0;
}
