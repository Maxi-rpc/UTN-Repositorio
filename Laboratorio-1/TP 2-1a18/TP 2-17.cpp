#include <iostream>
using namespace std;
int main(){

    int n1, n2, n3, n4;

    cout<<"Ingresar primer numero"<<endl;
    cin>>n1;
    cout<<"Ingresar segundo numero"<<endl;
    cin>>n2;
    cout<<"Ingresar tercer numero"<<endl;
    cin>>n3;
    cout<<"Ingresar cuarto numero"<<endl;
    cin>>n4;

    if(n1<=n2 && n2<=n3 && n3<=n4) {
        cout<<"Estan ordenados"<<endl;
    } else {
    cout<<"Estan desordenados"<<endl;}

  return 0;
}
