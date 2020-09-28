#include <iostream>

using namespace std;

int main(){
    int opc;
    while(true){
      system("cls");
      cout << "-----MODELO DE PARCIAL-1-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. PUNTO 1" << endl;
      cout << "2. PUNTO 2" << endl;
      cout << "0. FIN DEL PROGRAMA" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: //menuEmpresas();
                break;
        case 2: //menuViajes();
                break;
        case 0: return 0;
                break;
        default: cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
      system("pause");
    }
    return 0;
}
