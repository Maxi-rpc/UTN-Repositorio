#include <iostream>
using namespace std;
int main(){

  int n1;
  int n2;
  int n3;
  int n4;
  int n5;
  int pos;
  pos=0;

  cout<<"Por favor ingrese cinco numeros:"<< endl;
  cin >>n1;
  cin >>n2;
  cin >>n3;
  cin >>n4;
  cin >>n5;
  if(n1 > 0) {
    pos++;
  } else{}
  if(n2 > 0) {
    pos++;
  } else{}
  if(n3 > 0) {
    pos++;
  } else{}
  if(n4 > 0) {
    pos++;
  } else{}
  if(n5 > 0) {
    pos++;
  } else{}
  cout<<"Los numeros positivos son:"<<pos++ <<endl;


  return 0;
}
