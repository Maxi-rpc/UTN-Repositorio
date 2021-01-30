#include <iostream>
using namespace std;
int main(){
    int leg, codmateria, nota;
    int legant;
    int cantex, prom;
    int mejn, mejm;
    int mejp, mejl;

    cout<<"Ingresar legajo:"<<endl;
    cin>>leg;

    while(leg!=0){
        legant=leg;
        cantex=0;
        prom=0;
        mejn=0;
        mejp=0;

        while(leg==legant){
        cout<<"Ingresar codigo de materia:"<<endl;
         cin>>codmateria;

        cantex++;

        cout<<"Ingresar nota:"<<endl;
         cin>>nota;

        prom+=nota;

        if(nota>mejn){mejn = nota,
            mejm = codmateria;}
        if(nota==10){cout<<"Codigo de materia con nota 10: "<<codmateria<<endl;}

        cout<<"Ingresar legajo:"<<endl;
         cin>>leg;
}
        prom=prom/cantex;

        cout<<"Legajo: "<<legant<<endl;
        cout<<"Promedio: "<<prom<<endl;
        cout<<"Examenes rendidos: "<<cantex<<endl;
        cout<<"Materia con mejor nota: "<<mejm<<endl;
        cout<<"Mejor nota: "<<mejn<<endl;

        if(prom>mejp){mejp=prom,
            mejl=legant;}
}
        cout<<"Legajo: "<<mejl<<endl;
        cout<<"Mejor promedio: "<<mejp<<endl;



  return 0;
}
