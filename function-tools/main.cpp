#include <iostream>
#include <stdio.h> /// PARA USAR strcpy
#include <string.h> /// PARA USAR strcmp

using namespace std;

class Objeto{
private:
    int num;
    char nombre[10];
    bool estado;
public:
    //Set Se guarda variable en la PROPIEDAD
    void set_num(int n){num = n;};
    void set_nombre(char *n){strcpy(nombre,n);} // Se copia en DESTINO desde ORIGEN
    void set_estado(bool e){estado = e;};
    //Get Devuelve el valor de la PROPIEDAD
    int get_num(){return num;};
    char *get_nombre(){return nombre;};
    bool get_estado(){return estado;};
    // Funciones comunes
    bool escribirEnDisco(); // Guarda en archivo el objeto
    int leerDisco(int pos); // Lee el objeto que se le indique segun su POSICION
    bool modDisco(int pos); // Guarda la modificacion del objeto segun su POSICION
    // Sobre carga de operador
    bool operator==(char *n); // usar == Para comparar 2 nombres
};

// FUNCIONES EXTERNAS
int buscarNum(int num); // Busca NUM = ENTERO devuelve la POSICION del OBJETO
int buscarNombre(char *nombreB); // Busca por NOMBRE = CHAR* devuelve la POSICION del OBJETO
int cantDeObjetos(); // Devuelve la cantidad de OBJETO guardados en el ARCHIVO
int cantDeObjetosFiltros(); // Devuelve la cantidad de OBJETO que coinciden con el filtro

int main()
{
    cout << "Hello world Function-Tools!" << endl;
    cout << endl;


    cout << "--------" << endl;
    return 0;
}

/// Al usar FILE "ARCHIVO" tenemos los metodos de apertura:
// RB = Read Byte - Lectura solamente. El archivo debe existir
// WB = Write Byte - Crea un archivo para escribir o lo trunca a longitud cero
// AB = Add Byte - Añade, abre o crea un archivo para escribir al final del archivo
// RB+ = Read Byte Plus - Abre un archivo para leer o escribir

bool Objeto::escribirEnDisco(){
    bool guardo;
    FILE *f = fopen("objeto.dat", "ab"); // Se abre archivo
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f); // Se escribe en el archivo
    fclose(f);
    return guardo;
}

int Objeto::leerDisco(int pos){ // Se le pasa POSICION
    int x;
	FILE *p;
	p=fopen("objeto.dat","rb"); // Se abre archivo
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p); // Se lee el archivo
	fclose(p);
	return x; // Devuelve objeto
}

bool Objeto::modDisco(int pos){ // Se le pasa POSICION
    bool guardo;
    FILE *p;
	p=fopen("objeto.dat","rb+"); // Se abre archivo
	if(p==NULL){
        cout<<"Error de archivo";
        return false;
    }
	fseek(p,pos*sizeof *this,0);
	guardo = fwrite(this,sizeof *this,1,p); // Se escribe en el archivo
	fclose(p);
	return guardo; // Devuelve true si grabo o false en caso de no grabar
}

// Sobre carga de operador
bool Objeto::operator==(char *n){
    bool confirm;
    if(strcmp(n,nombre)==0){ // Se compara ambos nombres
        confirm = true;
    } else {
        confirm = false;
    }
    return confirm;
}

// Funciones externas
int buscarNum(int num){ // Se le pasa NUMERO a buscar
    int pos=0;
	Objeto c;
	while(c.leerDisco(pos)==1){ // Se lee el archivo
		if(num == c.get_num()){ // Se aplica condicion
            return pos; // Devuelve la POSICION si es encontrado
		}
		pos++;
    }
	return -1;
}

int buscarNombre(char *nombreB){ // Se le pasa CHAR NOMBRE a buscar
	int pos=0;
	Objeto c;
	while(c.leerDisco(pos)==1){ // Se lee el archivo
		if(strcmp(nombreB,c.get_nombre())==0){ // Se aplica condicion
            return pos; // Devuelve la POSICION si es encontrado
		}
		pos++;
    }
	return -1;
}

int cantDeObjetos(){
    FILE *f;
    f = fopen("objeto.dat", "rb"); // Se abre archivo
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END); // Se posiciona sobre el final del archivo
    bytes = ftell(f); // Obtenemos el valor de la posicion del archivo
    fclose(f); // Cerramos el archivo
    cant = bytes / sizeof(Objeto); // Dividimos el valor del archivo por el tamaño del OBJETO
    return cant; // Devuelve la cantidad
}

int cantDeObjetosFiltros(){
    int cant=0, pos=0;
    Objeto u;
    while(u.leerDisco(pos)==1){ // Lee el archivo
        if(u.get_estado()== true){ // Se filtra por lo que sea desea buscar
            cant++; // Acumula coincidencias
        }
        pos++;
    }
    return cant; // Devuelve cantidad
}

