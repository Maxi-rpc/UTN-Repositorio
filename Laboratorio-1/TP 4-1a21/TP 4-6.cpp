#include <iostream>
using namespace std;
int main(){
    int n, pos=0, neg=0;

    while(n!=0){
            cout<<"Ingresar un numero:"<<endl;
            cin>>n;
            if(n>0){pos++;}
            else{if(n!=0){neg++;};
            }

}
        cout<<"Total de positivos: "<<pos<<endl;
        cout<<"Total de negativos: "<<neg<<endl;

  return 0;
}
