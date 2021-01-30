#include <iostream>
using namespace std;
int main(){

    int n,pos1=0,pos2=0;

    for(int i=0; i<7; i++)
{
        cout<<"Ingresar numero:"<<endl;
        cin>>n;
        if(n%2!=0){
                if(pos1==0){pos1=n;}
                else{
                    if(pos2==0){pos2=n;}
                        }
            }
}
cout<<"Primer numero impar:"<<pos1<<endl;
cout<<"Segundo numero impar:"<<pos2<<endl;

  return 0;
}
