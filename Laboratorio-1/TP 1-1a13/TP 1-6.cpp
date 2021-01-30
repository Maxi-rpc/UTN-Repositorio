#include <iostream>
using namespace std;
int main(){

    float sem1;
    float sem2;
    float sem3;
    float sem4;
    float semt;
    float semprom;
    float semanas;
    float psem1;
    float psem2;
    float psem3;
    float psem4;
    float psemt;

    semanas=4;
    psemt=100;

    cout<<"Ingresar recaudacion primer semana: "<<endl;
    cin>>sem1;
    cout<<"Ingresar recaudacion segunda semana: "<<endl;
    cin>>sem2;
    cout<<"Ingresar recaudacion tercer semana: "<<endl;
    cin>>sem3;
    cout<<"Ingresar recaudacion cuarta semana: "<<endl;
    cin>>sem4;

    semt=sem1+sem2+sem3+sem4;
    semprom=semt/semanas;
    psem1=(sem1*psemt)/semt;
    psem2=(sem2*psemt)/semt;
    psem3=(sem3*psemt)/semt;
    psem4=(sem4*psemt)/semt;

    cout<<"Recaudacion promedio: $"<<semprom<<endl;
    cout<<"Porcentaje primer semana: "<<psem1<<"%"<<endl;
    cout<<"Porcentaje segunda semana: "<<psem2<<"%"<<endl;
    cout<<"Porcentaje tercer semana: "<<psem3<<"%"<<endl;
    cout<<"Porcentaje cuarta semana: "<<psem4<<"%"<<endl;


  return 0;
}
