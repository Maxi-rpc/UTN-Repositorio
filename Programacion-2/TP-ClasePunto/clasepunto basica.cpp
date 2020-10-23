//Ejercicio:
//Autor:DEK
//Fecha:
//Comentario:

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
#include <windows.h>
#include <ctime>

using namespace std;


///DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el número 15

void ocultarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void mostrarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x, short y){ ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
///ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto=15, int colorFondo=0){
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

///**FIN FUNCIONES


///CLASE PUNTO
class Punto {
    private:
        int x;
        int y;
        int color;
    public:
        Punto(int a=0, int b=0, int nuevoColor=cNEGRO){
            x=a;
            y=b;
            color=nuevoColor;
        }
        void Mostrar(){
            textcolor(color, 15);
            gotoxy(x,y);
            cout<<".";
        }
        void MostrarValores();
        void Ocultar(){
            gotoxy(x,y);
            cout<<" ";
        }
        void setX(int valor){
            if(valor>=0 && valor<=75)  x=valor;
        }
        void setY(int valor){
            if(valor>=0)  y=valor;
        }

        void setColor(int nuevo){
            if(nuevo>0 && nuevo<=15)
            color=nuevo;
        }
        int getX(){return x;}
        int getY(){return y;}
        int getColor(){return color;}
        ~Punto(){///DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su alcance.
            textcolor(0,15);

        }
};

void Punto::MostrarValores(){
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<color<<endl;
    }



void punto1(){
    int x, y;
    cout << "INDICAR EJE X : >";
    cin >> x;
    cout << "INDICAR EJE Y : >";
    cin >> y;

    Punto obj(x,y, cAZUL);
    obj.Mostrar();

}

void punto2(){
    int x, y;
    cout << "Dibujar una línea de puntos horizontal en una posición del eje y definida" << endl;
    cout << "INIDCAR EJE Y: >";
    cin >> y;
    x = 80;

    Punto obj(x,y, cAZUL);
    for(int i=0; i<x; i++){
        obj.setX(i);
        obj.Mostrar();
    }


}

void punto3(){
    int x, y;
    cout << "Dibujar una línea de puntos vertical en una posición del eje x definida" << endl;
    x = 50;
    y = 10;

    Punto obj(x,y, cAZUL);
    for(int i=0; i<y; i++){
        obj.setY(i);
        obj.Mostrar();
    }
}

void punto4(){
    int x, y;
    cout << "Dibujar una línea de puntos horizontal que alterne 2 colores." << endl;
    x = 50;
    y = 10;

    Punto obj(x,y, cAZUL);
    for(int i=0; i<x; i++){
        obj.setX(i);
        obj.setColor(cAZUL);
        if(i%2 == 0){
            obj.setColor(cROJO);
        }
        obj.Mostrar();

    }
}

void punto5(){
    int x, y;
    cout << "Dibujar una línea de puntos vertical que alterne 2 colores." << endl;
    x = 50;
    y = 10;

    Punto obj(x,y, cAZUL);
    for(int i=0; i<y; i++){
        obj.setY(i);
        obj.setColor(cAZUL);
        if(i%2 == 0){
            obj.setColor(cROJO);
        }
        obj.Mostrar();

    }
}

int main() {
    int opc;
    while(true){
        system("cls");
        cout<<"----------MENU------------"<<endl;
        cout<<"1. DIBUJAR UN PUNTO"<<endl;
        cout<<"2. DIBUJAR UNA LINEA HORIZONTAL"<<endl;
        cout<<"3. DIBUJAR UNA LINEA DE PUNTOS VERTICAL"<<endl;
        cout<<"4. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"5. DIBUJAR UNA LINEA DE PUNTOS VERTICAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"6.PUNTO 6 "<<endl;
        cout<<"7. PUNTO 7 "<<endl;
        cout<<" 0. FIN DEL PROGRAMA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        ocultarCursor();
        switch(opc){
            case 1:punto1();
                break;
            case 2:punto2();
                break;

            case 3:punto3();
                break;
            case 4:punto4();
                break;
            case 5:punto5();
                break;
//            case 6:punto8();
                break;
  //          case 7:punto8();
                break;
            case 0:
                return 0;

        }
        system("pause>null");
        mostrarCursor();

    }
    return 0;
}

void aleatorio(Punto *vec, int tam){
    srand(time(NULL));
    for(int i=0;i<tam;i++){
       vec[i].setX(rand()%50);
       vec[i].setY(rand()%15);
      }
}
