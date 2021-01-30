#include <iostream>
using namespace std;
int main(){

    int k, p1=10, p2=12, p3=15, imp, res, t;

    cout<<"Ingresar kilovatios:"<<endl;
    cin>>k;

    if(k<100){imp=k*p1;}
    else{if(k<200){res=k%100 , imp=(100*p1)+(res*p2);}
    else{t=k-200 , imp=(100*p1)+(100*p2)+(t*p3);}
    }



    cout<<"Importe a pagar: $"<<imp<<endl;



  return 0;
}
