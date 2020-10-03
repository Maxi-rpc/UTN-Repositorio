#include <iostream>

using namespace std;

class Botella{
private:
    float capacidad;
    float ocupacion;
    bool tapada;

public:
    void llenar(float);
    void vaciar();
    void vaciar(float);
    void tapar();
    void destapar();
    Botella(float);
};

Botella::Botella(float cap){
    capacidad = 100;
    ocupacion = 0;
    if(cap != 0){
        capacidad = cap;
    }
    cout << "*Se creo nueva Botella con " << capacidad << " ml." << endl;
    cout << "-Su ocupacion es de " << ocupacion << " ml."<< endl;
}

//void llenar(float){

//}


int main()
{
    cout << "========== Hello world! TP POO-1 ==========" << endl;
    cout << " " << endl;
    cout << "Ingresar Capacidad de la botella (por defecto 100 ml)" << endl;
    float inicial;
    cout << "> ";
    cin >> inicial;
    Botella bot(inicial);

    cout << " " << endl;
    return 0;
}
