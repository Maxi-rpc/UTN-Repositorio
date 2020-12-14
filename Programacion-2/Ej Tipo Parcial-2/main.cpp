#include <iostream>

using namespace std;

class Cliente{
private:
    char cuit[12];
    char nombre[40];
    int categoria; // 1: responsable inscripto; 2: no responsable; 3: monotributo; 4: exento
public:
    char *getCuit(){return cuit;};
    char *getNombre(){return nombre;};
    int getCategoria(){return categoria;};
    int leerDisco(int pos);
};

class Fecha{
private:
    int dia, mes, anio;
public:
    int getDia(){return dia;};
    int getMes(){return mes;};
    int getAnio(){return anio;};
};

class Prestamo{
private:
    int numPrestamo;
    int codBanco;
    char cuitCliente[12];
    float impCred;
    int plazo;
    Fecha fechaP;
public:
    int getNumPres(){return numPrestamo;};
    int getCodBanco(){return codBanco;};
    char *getCuitCliente(){return cuitCliente;};
    float getImpCred(){return impCred;};
    int getPlazo(){return plazo;};
    Fecha getFechaP(){return fechaP;};
    int leerDisco(int pos);
};

// PUNTO A
class PuntoA{
private:
    char nombre[40];
    char cuit[12];
    float impTotal;
public:
    void setNombre(char *n){strcpy(nombre,n);};
    void setCuit(char *c){strcpy(cuit,c);};
    void setImpTotal(float impT){impTotal = impT;};
    bool escribirDisco();
};

void puntoA();
float sumaTodoPrestamo(char *cuit);

// PUNTO B
class Mamifero{
private:
    char nombre[40];
public:
    void cargarDatos();
    void mostrarDatos();
};

class MamiferoTerrestre{
private:
    Mamifero;
    int cantPatas;
    float velocidadDes;
public:
    void setCantPatas(int cant){cantPatas = cant;};
    void setVelDes(float vel){velocidadDes = vel;};
    int getCantPatas(){return cantPatas;};
    float getVelDes(){return velocidadDes;};
    void cargarDatos();
    void mostrarDatos();
};

void puntoB();

int main()
{
    cout << "EJERCICIO TIPO PARCIAL 2" << endl;

    puntoA();
    puntoB();

    return 0;
}

// PUNTO A

void puntoA(){
    cout << "SE CREA ARCHIVO.DAT" << endl;
    int pos=0;
    float total=0;
    Cliente cl;
    while(cl.leerDisco(pos)==1){

        total = sumaTodoPrestamo(cl.getCuit());

        if(total > 0){
            PuntoA p;
            p.setNombre(cl.getNombre());
            p.setCuit(cl.getCuit());
            p.setImpTotal(total);
            p.escribirDisco();
        }
        total=0;
        pos++;
    }
}

bool PuntoA::escribirDisco(){
    bool guardo;
    FILE *f = fopen("puntoA.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

float sumaTodoPrestamo(char *cuit){
	int pos=0, suma=0;
	Prestamo p;
	while(p.leerDisco(pos)==1){
		if(strcmp(cuit,p.getCuitCliente()){
            suma += p.getImpCred();
		}
		pos++;
    }
	return suma;
}

// PRESTAMO
int Prestamo::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("Préstamo.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

// CLIENTE
int Cliente::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("Clientes.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

//PUNTO B

void puntoB(){
    MamiferoTerrestre m;

}

void MamiferoTerrestre::cargarDatos(){
    cout << "INGRESAR LOS SIGUIENTES DATOS:" << endl;
    Mamifero.cargarDatos();
    cout << "CANTIDAD DE PATAS:";
    cin >> cantPatas;
    cout << "VELOCIDAD DE DESPLAZAMIENTO:";
    cin >> velocidadDes;
}

void MamiferoTerrestre::mostrarDatos(){
    cout << "MAMIFERO TERRESTRE:" << endl;
    Mamifero.mostrarDatos();
    cout << "CANTIDAD DE PATAS:" << cantPatas << endl;
    cout << "VELOCIDAD DE DESPLAZAMIENTO:" << velocidadDes << endl;
}
