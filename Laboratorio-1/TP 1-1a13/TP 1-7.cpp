#include <iostream>
using namespace std;
int main(){

    int imv;
    int pord;
    int impt;
    float port;
    port=100;

    cout<<"Ingresar importe de venta: "<<endl;
    cin>>imv;
    cout<<"Ingresar porcentaje de descuento: "<<endl;
    cin>>pord;

    impt=(imv*(port-pord))/port;

    cout<<"Importe a pagar: $"<<impt<<endl;



  return 0;
}
