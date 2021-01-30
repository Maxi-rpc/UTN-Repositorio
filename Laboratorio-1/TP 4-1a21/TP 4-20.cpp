#include <iostream>
using namespace std;
int main(){

    int nc, loc, kv;
    int p1=10, p2=12, p3=15, pf=100, total;
    int cmc1, cmc2, cmc3;
    int kvm1=0, kvm2=0, kvm3=0;
    int trc1=0, trc2=0, trc3=0;
    int cmenc=0, kvm=0;

    cout<<"Ingresar numero de cliente:"<<endl;
    cin>>nc;
    cout<<"Ingresar localidad:"<<endl;
    cin>>loc;
    cout<<"Ingresar kilovatios consumidos:"<<endl;
    cin>>kv;

    while(nc!=0){

    if(kv>0){if(cmenc==0){kvm=kv, cmenc=nc;}
        else{if(kv<kvm){kvm=kv, cmenc=nc;}
            }

    if(kv<=100){total=(kv*p1)+pf;}
    else{if(kv<=200){total=((kv-100)*p2)+(100*p1)+pf;}
    else{total=((kv-200)*p3)+(100*p2)+(100*p1)+pf;}
    }

    switch(loc){
        case 1:
            if(kv>kvm1){cmc1=nc, kvm1=kv;}
    trc1+=total;
    break;
        case 2:
            if(kv>kvm2){cmc2=nc, kvm2=kv;}
    trc2+=total;
    break;
        case 3:
            if(kv>kvm3){cmc3=nc, kvm3=kv;}
    trc3+=total;
    break;
        }
        }
    cout<<"Ingresar numero de cliente:"<<endl;
    cin>>nc;
    if(nc!=0){cout<<"Ingresar localidad:"<<endl;
    cin>>loc;
    cout<<"Ingresar kilovatios consumidos:"<<endl;
    cin>>kv;
    }
    }

    cout<<"Cliente con mayor consumo:"<<endl;
    cout<<"Localidad 1: "<<cmc1<<endl;
    cout<<"Localidad 2: "<<cmc2<<endl;
    cout<<"Localidad 3: "<<cmc3<<endl;

    cout<<"total recaudado:"<<endl;
    cout<<"localidad 1: "<<trc1<<endl;
    cout<<"Localidad 2: "<<trc2<<endl;
    cout<<"Localidad 3: "<<trc3<<endl;

    cout<<"Cliente con menor consumo:"<<endl;
    cout<<cmenc<<endl;

  return 0;
}
