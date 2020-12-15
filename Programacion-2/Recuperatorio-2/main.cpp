#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

class Proyecto{
private:
    int num;
    char nombre[30];
    int tiempo; // DIAS
    float presupuesto;
public:
    int getNum(){return num;};
    char *getNombre(){return nombre;};
    float getPres(){return presupuesto;};
    int leerDisco(int pos);
    bool Proyecto::operator!=(Asignacion asig);
};

bool Proyecto::operator!=(Asignacion asig){
    int i=0;
    for(i; i<30; i++){
        if(nombre[i] != nombre[i]){
            return false;
        }
    }
    return true;
}


class Fecha{
private:
    int dia, mes, anio;
};

class Asignacion{
private:
    int num;
    int dni;
    Fecha nacimiento;
    int cargo; // 1 A 10
    char nombre[30];
    int tiempo; // DIAS
    float presupuesto;
public:
    int getNum(){return num;};
    int getCargo(){return cargo;};
    int leerDisco(int pos);
};

// PUNTO A
class PuntoA{
private:
    int numProyecto;
    char nombreProyecto[30];
    int cantAsignacion;
public:
    void setNumP(int p){numProyecto = p;};
    void setNombreP(char *n){strcpy(nombreProyecto,n);};
    void setCantA(int cant){cantAsignacion = cant;};
    //GET
    int getNumP(){return numProyecto;};
    char *getNombreP(){return nombreProyecto;};
    int getCantA(){return cantAsignacion;};
    bool escribirDisco();
};
// PUNTO A
void puntoA();
int sumarCanAsig(int num);
// PUNTO B
void puntoB();

int main()
{
    cout << "PROGRAMACION II" << endl;
    cout << "RECUPERATORIO PARCIAL-2" << endl;

    puntoA();
    puntoB();

    return 0;
}

//PUNTO A
void puntoA(){
    cout << "PUNTO A" << endl;
    cout << "SE CREA proy_bajo.dat" << endl;
    int pos=0, total=0;
    float minimo =  1500000;
    Proyecto proy;
    while(proy.leerDisco(pos)==1){

        if(proy.getPres() < minimo){
            total = sumarCanAsig(proy.getNum());

            PuntoA p;
            p.setNumP(proy.getNum());
            p.setNombreP(proy.getNombre());
            p.setCantA(total);
            p.escribirDisco();
        }
        total=0;
        pos++;
    }
}

bool PuntoA::escribirDisco(){
    bool guardo;
    FILE *f = fopen("proy_bajo.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Proyecto::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("Proyectos.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

int Asignacion::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("Asignacion.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

int sumarCanAsig(int num){
	int pos=0, suma=0;
	Asignacion asig;
	while(asig.leerDisco(pos)==1){
		if(asig.getNum() == num){
            suma++;
		}
		pos++;
    }
	return suma;
}

void puntoB(){
    cout << "PUNTO A" << endl;
    int cantCargo[10]={}, pos=0;

	Asignacion asig;
    while(asig.leerDisco(pos)==1){
		cantCargo[asig.getCargo()-1]++;
        pos++;
    }
    for(int i=0; i<10; i++){
        cout << "CARGO: " << i+1 << endl;
        cout << "CANTIDAD: " << cantCargo[i] << endl;
    }

}

