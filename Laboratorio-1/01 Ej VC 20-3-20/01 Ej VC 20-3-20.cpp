#include <iostream>
using namespace std;
int main(){

  int ch;
  int d;
  int hs;
  d=100;
  hs=12;
  int c;
  int h;
  int it;
  cout<<"Por favor ingrese la cantidad de huevos:"<< endl;
  cin >>ch;
  c=ch/12;
  h=ch%12;
  it=(c*d)+(h*hs);
  cout<<"El importe total a pagar es de: $"<<it<< endl;

  return 0;
}
