#include <iostream>

using namespace std;
#include "rlutil.h"
#include "ui.h"
using namespace rlutil;
#include "menu.h"

void menuPrincipal(){
    initUI();

    title("MENÚ PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    gotoxy(1,5);
    cout << "Hello world POO-2" << endl;

}
