#include <iostream>
using namespace std;
int main(){

  int n1;
  int n2;
  int n3;
  int n4;
  int n5;
  int may;

  cout<<"Por favor ingresar 5 numeros:"<< endl;
  cin >>n1;
  cin >>n2;
  cin >>n3;
  cin >>n4;
  cin >>n5;

  if(n1 > n2) {
    may=n1;
  } else{
  may=n2;}

  if(n3 > may) {
    may=n3;
  } else{
  }
  if(n4 > may) {
    may=n4;
  } else{
  }
  if(n5 > may) {
    may=n5;
  } else{
  }

  cout<<"El mayor es: "<< may << endl;

  return 0;
}
