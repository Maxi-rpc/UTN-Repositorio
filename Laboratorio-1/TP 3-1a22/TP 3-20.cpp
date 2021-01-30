#include <iostream>
using namespace std;
int main(){
    int num, sum=0, mul=0;
    cout<<"Ingresar un numero:"<<endl;
    cin>>num;
	for(int i=1; i<num; i++)
{
		mul=num%i;
		if(mul==0){sum+=i;}
}
	if(sum==num){cout<<"El numero es perfecto."<<endl;}
	else{cout<<"El numero no es perfecto."<<endl;}

	return 0;
}
