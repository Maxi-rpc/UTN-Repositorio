#include <iostream>
using namespace std;
int main(){
    int n,pn=0,un=0;

    for(int i=0; i<7; i++)
{
    cout<<"Ingresar numero:"<<endl;
    cin>>n;
    if(n%2!=0){
            if(pn==0){pn=n;}
    else{un=n;}
        }

}
    cout<<"El primer numero impar: "<<pn<<endl;
    cout<<"El ultimo numero impar: "<<un<<endl;

  return 0;
}
