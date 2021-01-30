#include <iostream>
using namespace std;
int main(){

    int l1;
    int l2;
    int l3;

    cout<<"Ingresar longitud del primer lado:"<<endl;
    cin>>l1;
    cout<<"Ingresar longitud del segundo lado:"<<endl;
    cin>>l2;
    cout<<"Ingresar longitud del tercer lado:"<<endl;
    cin>>l3;

    if(l1==l2 && l2==l3) {
        cout<<"Es equilatero"<<endl;
    } else {if(l1!=l2 && l2!=l3 && l1!=l3) {
    cout<<"Es escaleno"<<endl;
    } else {cout<<"Es isoceles"<<endl;
    }
    }

  return 0;
}
