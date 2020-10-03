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
};

int main()
{
    cout << "Hello world! TP POO-1" << endl;


    return 0;
}
