#include <iostream>
using namespace std;
int main(){
    int n, res, par, pos=0, d=0;

	for(int i=1; i<7; i++)
{
		cout<<"Ingresar un numero:"<<endl;
		cin>>n;
		res=n%2;
		if(res==0){if(pos==0){par=n , pos=i;}
            }

}

    cout<<"Primer numero par: "<<par<<", ubicacion "<<pos<<endl;


	return 0;
}
