#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

//PROTOTIPOS
void menuReportes();
void generarArchivoConsumos();
float calcularPromedioConsumo(char *codigoEmpresa);
bool grabarRegistroConsumos(puntoA aux);
void listadoEmpresaNoexterior();
void listadoEmpresaNoexterior2();
void consumoMesMarca();
void mostrarConsumoMesMarca(float m[][10]);
void cantKmRecorridosTNacional();

// FIN PROTOTIPOS

void menuReportes(){
    int opc;
    while(true){
      system("cls");
      cout << "-----MENU REPORTES-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. GENERAR ARCHIVO PROMEDIO CONSUMO" << endl;
      cout << "2. LISTADO EMPRESA QUE NO VIAJAN AL EXTERIOR" << endl;
      cout << "3. POR CADA MES Y MARCA COMBUSTIBLE CONSUMIDO" << endl;
      cout << "4. LA CANTIDAD DE KM RECORRIDOS TRANSPORTE NACIONAL" << endl;
      cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: generarArchivoConsumos();
                break;
        case 2: listadoEmpresaNoexterior2();
                break;
        case 3: consumoMesMarca();
                break;
        case 4: //cantKmRecorridosTNacional();
                break;
        case 0: return;
                break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
      system("pause");
    }
    return;
}

void generarArchivoConsumos(){
    empresa reg;
    puntoA aux;
    FILE *p = fopen("empresas.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    while(fread(&reg,sizeof reg, 1, p)==1){
        strcpy(aux.codigoEmpresa, reg.codigoEmpresa); //se copia en - desde
        strcpy(aux.nombreEmpresa, reg.nombreEmpresa);
        aux.promedioConsumo = calcularPromedioConsumo(reg.codigoEmpresa);
        if(!grabarRegistroConsumos(aux)){
            fclose(p);
            cout << "NO SE PUDO GRABAR EL REGISTRO" << endl;
            return;
        }
    }
    fclose(p);
    cout << "ARCHIVO CREADO" << endl;
}

float calcularPromedioConsumo(char *codigoEmpresa){
    viaje aux;
    float cantCombustible=0;
    int cantViajes=0;
    FILE *p = fopen("viajes.dat", "rb");
    if(p==NULL){
        return -1;
    }
    while(fread(&aux, sizeof aux, 1, p) == 1){
        if(strcasecmp(aux.codigoEmpresa, codigoEmpresa) == 0){
            if(aux.fechaViaje.anio == 2019){
                cantCombustible+=aux.cantidadCombustible;
                cantViajes++;
            }
        }
    }
    fclose(p);
    return cantCombustible / cantViajes;
}

bool grabarRegistroConsumos(puntoA aux){
    FILE *p = fopen("puntoA.dat", "ab");
    if(p==NULL){
        return false;
    }
    bool grabo = fwrite(&aux, sizeof aux, 1, p);
    fclose(p);
    return grabo;
}

void listadoEmpresaNoexterior(){
    empresa reg;
    puntoA aux;
    FILE *p = fopen("empresas.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    while(fread(&reg,sizeof reg, 1, p)==1){
        if(reg.tipoEmpresa != 4){
            mostrarEmpresa(reg);
        }
    }
    fclose(p);
}

void listadoEmpresaNoexterior2(){
    empresa reg;
    int i, cantReg = contarRegistrosEmpresa();
    for(i=0; i<cantReg; i++){
        reg = leerEmpresa(i);
        if(reg.tipoEmpresa != 4){
            mostrarEmpresa(reg);
        }
    }
}

void consumoMesMarca(){
    viaje aux;
    float combustibleMesMarca[12][10]={0};

    FILE *p = fopen("viajes.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
    }
    while(fread(&aux, sizeof aux, 1, p) == 1){
        if(aux.fechaViaje.anio == 2019){
            combustibleMesMarca[aux.fechaViaje.mes-1][aux.marca-1] += aux.cantidadCombustible;
        }
    }
    fclose(p);
    mostrarConsumoMesMarca(combustibleMesMarca);
}

void mostrarConsumoMesMarca(float combustibleMesMarca[12][10]){
    int i, v;
    system("cls");
    for(i=0; i<12; i++){
        cout << "MES " << i+1 <<": "<< endl;
        for(v=0; v<10; v++){
            if(combustibleMesMarca[i][v] != 0){
                cout << "MARCA " << v+1 << ": ";
                cout<<combustibleMesMarca[i][v]<<endl;
            }
        }
        cout << "-----------------------"<< endl;

    }

    system("pause>nul");
}

void cantKmRecorridosTNacional(){
    float totalKm=0;
    empresa emp;
    viaje viaj;
    char codEmp[5];
    FILE *e = fopen("empresas.dat", "rb");
    if(e==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
    }

    FILE *v = fopen("viajes.dat", "rb");
    if(v==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
    }

    while(fread(&emp,sizeof emp, 1, p)==1){
        if(emp.tipoEmpresa == 3){

        }
    }
    fclose(e);
    fclose(v);

}


#endif // REPORTES_H_INCLUDED
