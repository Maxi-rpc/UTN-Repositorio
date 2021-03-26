#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ui.h"
#include "rlutil.h"
#include "menu.h"
using namespace rlutil;

int main()
{
    initUI(); // INICIA UI, NECESARIO
    menuPrincipal();
}
