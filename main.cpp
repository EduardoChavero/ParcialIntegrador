#include <iostream>
using namespace std;
#include "Funciones.h"
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
using namespace rlutil;

int main()
{
    setlocale(LC_ALL, "Spanish");
    setColor(LIGHTCYAN);
    char presentacion[24] = "UTN PACHECO PRESENTA...";
    gotoxy(20, 15);
    for(int i=0; i<23; i++)
    {
        cout << presentacion[i];
        msleep(100);
    }
    msleep(500);
    cls();
    gotoxy(20, 15);
    cout << "Un trabajo de Chavero Eduardo y De Cecco Nicolás";
    msleep(2000);
    cls();
    intro();
    menu();
}
