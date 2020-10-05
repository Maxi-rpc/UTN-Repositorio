#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

struct fecha{
  int dia, mes, anio;
};

struct medico{
  int dni;
  char nombre30];
  char apellido[30];
  char email[40];
  char telefono[20];
  int cargo, especialidad, localidad;
   bool estado;
};

struct hospital{
  int numero;
  int especialidad, region, anio;
  char nombre[45];
  int dniDirector;
  bool estado;
};

struct contrato{
  int dniMédico;
  int numeroHospital;
  int tipoContrato;
 fecha fecha_contrato;
  bool estado;
};

struct punto2{
    int numeroHospital;
    char nombreHosp[45];
    int cantidadCont;
};

void punto1();
void punto2();
int contarContratos(contrato); //cuenta los contratos del archivo Contrato.dat
bool grabarPunto2(punto2); // graba los reg en un nuevo archivo.dat


void punto1(){
    medico reg;
    int contar=0, contarMun=0;
    FILE *p = fopen("Medicos.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    for(int i=0; i<135; i++){
        while(fread(&reg,sizeof reg, 1, p)==1){
            if(reg.localidad == i+1){
                contar++;
            }
        }
        if(contar < 50){
            contarMun++;
        }
    }
    fclose(p);
    cout << "La cantidad de municipios de residencia con menos de 50 médicos: "<< contarMun << endl;
}


void punto2(){
    hospital reg;
    punto2 aux;
    FILE *p = fopen("Contrato.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    while(fread(&reg,sizeof reg, 1, p)==1){
        strcpy(aux.numeroHospital, reg.numero); //se copia en - desde
        strcpy(aux.nombreHosp, reg.nombre);
        aux.cantidadCont = contarContratos(reg.numero);
        if(!grabarPunto2(aux)){
            fclose(p);
            cout << "NO SE PUDO GRABAR EL REGISTRO" << endl;
            return 0;
        }
    }
    fclose(p);
    cout << "ARCHIVO CREADO" << endl;
    return 0;
}

int contarContratos(hospital reg){
    int totalCont=0;
    contrato aux;
    FILE *p = fopen("Contratos.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    while(fread(&reg,sizeof reg, 1, p)==1){
        if(aux.numeroHospital == reg.numero){
            totalCont++;
        }
    }
    fclose(p);
    return totalCont;
}

bool grabarPunto2(punto2 aux){
    FILE *p = fopen("punto2.dat", "ab");
    if(p==NULL){
        return false;
    }
    bool grabo = fwrite(&aux, sizeof aux, 1, p);
    fclose(p);
    return grabo;
}
#endif // TIPO_H_INCLUDED
