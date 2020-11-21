#include <iostream>
using namespace std;
#include <clocale>
#include "Funciones.h"
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
#include <windows.h>
using namespace rlutil;

void menu()
{
    srand(time(NULL));
    char mejorPlayer[11];
    char nick1[11];
    char nick2[11];
    setlocale(LC_ALL, "Spanish");
    setBackgroundColor(LIGHTCYAN);
    cls();
    setColor(BLUE);
    char opcion;
    int mayorPuntaje = 0;
    bool original;

    do
    {
        system("cls");
        gotoxy(40,4);
        cout<<"*****************************************"<<endl;
        gotoxy(40,5);
        cout<<"|             Menu principal            |"<<endl;
        gotoxy(40,6);
        cout<<"|---------------------------------------|"<<endl;
        gotoxy(40,7);
        cout<<"|          1) Modo UN jugador           |"<<endl;
        gotoxy(40,8);
        cout<<"|          2) Modo DOS jugadores        |"<<endl;
        gotoxy(40,9);
        cout<<"|          3) Mejor puntuacion          |"<<endl;
        gotoxy(40,10);
        cout<<"|          4) Instrucciones             |"<<endl;
        gotoxy(40,11);
        cout<<"|          5) Créditos                  |"<<endl;
        gotoxy(40,12);
        cout<<"|---------------------------------------|"<<endl;
        gotoxy(40,13);
        cout<<"|          6) Salir                     |"<<endl;
        gotoxy(40,14);
        cout<<"|                                       |"<<endl;
        gotoxy(40,15);
        cout<<"*****************************************"<<endl;
        opcion = getch();


        switch(opcion)
        {
        case '1':
            cout << "Ingrese dificultad (0 dificil / 1  facil): ";
            cin >> original;
            singlePlayer(nick1, mejorPlayer, &mayorPuntaje, original);
            break;
        case '2':
            cout << "Ingrese dificultad (0 dificil / 1  facil): ";
            cin >> original;
            multiPlayer(nick1, nick2, mejorPlayer, &mayorPuntaje, original);
            break;
        case '3':
            mostrarMejor(mejorPlayer, mayorPuntaje);
            break;
        case '4':
            instrucciones();
            break;
        case '5':
            creditos();
            break;
        case '6':
            system("cls");
            cout<<"Muchas gracias por jugar! :)"<<endl<<endl;
            exit(1);
            break;
        default:
            setColor(RED);
            cout<<"Opción incorrecta"<<endl;
            system("pause");
            setColor(BLUE);
            break;
        }
    }
    while(opcion!='6');
}

void bloqManual(int bloq[], int tam)
{
   do
    {
        cout << "Ingrese dos bloqueadores distintos del 1 al 6..." << endl;
        cout << "Ingrese el bloqueador 1: ";
        cin >> bloq[0];
        cout << "Ingrese el bloqueador 2: ";
        cin >> bloq[1];
    }
    while(bloq[0]==bloq[1] || bloq[0]<1 || bloq[0]>6 || bloq[1]<1 || bloq[1]>6);
    cls();
}

void comprobarIgualdad(int bloq[], int tam)
{
for (int i=0; i<tam; i++)
    {
    while (bloq[i]==bloq[i+1]){
        dados(bloq, tam);
    }
    }
}

void dados(int vec[], int tam)
{
    srand(time(NULL));
    for(int i=0; i<tam; i++)
    {
        vec[i] = 1 + rand() % 6;
    }
}

void mostrar(int vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << vec[i] << "   ";
    }

}

int sumar(int vec[], int tam)
{
    int acu=0;
    for (int i=0; i<tam; i++)
    {
        acu+=vec[i];
    }
    return acu;
}

int eliminar(int vec1[], int tam1, int vec2[], int tam2)
{
    int acu=0;
    for(int i=0; i<tam1; i++)
    {
        for(int x=0; x<tam2; x++)
        {
            if (vec1[i]==vec2[x])
            {
                vec1[i]=0;
                acu++;
            }
        }
    }
    return acu;
}

void ponerCero(int vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i]=0;
    }
}

void mayus(char vec[])
{
    for (int i=0; i<11; i++)
    {
        vec[i] = toupper(vec[i]);
    }
}

void mostrarMejor(char nombre[], int puntos)
{
    int colorF;
    for (int i=0; i<5; i++)
    {
        colorF = rand() % 15 + 1;
        setBackgroundColor(colorF);
        system("cls");
        gotoxy(45, 10);
        if(i==1)
            sonidoMejorPuntaje();
        cout << "** ¡¡MEJOR PUNTAJE!! **" << endl << endl;
        gotoxy(50, 13);
        if(puntos == 0)
        {
            cout<<"No hay mejor puntaje guardado aun!!"<<endl;
            msleep(500);

        }
        else
        {
            cout << nombre << " CON " << puntos << " PUNTOS" << endl << endl;
            msleep(500);
        }


    }
    cout<<endl<<endl<<endl;
    system("pause");
    setBackgroundColor(LIGHTCYAN);
    setColor(BLUE);
}

void mostrarNuevo(char nombre[], int puntos)
{
    int colorF;
    for (int i=0; i<5; i++)
    {
        colorF = rand() % 15 + 1;
        setBackgroundColor(colorF);
        system("cls");
        gotoxy(45, 10);
        if(i==1)
            sonidoMejorPuntaje();
        cout << "** ¡¡ NUEVO MEJOR PUNTAJE!! **" << endl << endl;
        gotoxy(50, 13);
        cout << nombre << " CON " << puntos << " PUNTOS" << endl << endl;
        msleep(500);
    }
    cout<<endl<<endl<<endl;
    system("pause");
    setBackgroundColor(LIGHTCYAN);
    setColor(BLUE);
}

void mostrarGanador(char nombre[], int puntos)
{
    int colorF;
    for (int i=0; i<5; i++)
    {
        colorF = rand() % 15 + 1;
        setBackgroundColor(colorF);
        system("cls");
        gotoxy(45, 10);
        if(i==1)
            sonidoDescendente();
        cout << "** ¡¡ GANADOR !! **" << endl << endl;
        gotoxy(50, 13);
        cout << nombre << " CON " << puntos << " PUNTOS" << endl << endl<<endl;
        gotoxy(50, 14);
        cout<<"-----FIN DEL JUEGO-----"<<endl;

        msleep(500);
    }
    anykey();
    setBackgroundColor(LIGHTCYAN);
    setColor(BLUE);
}

void singlePlayer(char nick1[], char  mejorP[], int *mayor, bool original)
{
    sonidoAscendente();
    setBackgroundColor(GREY);
    setColor(BLACK);
    system("cls");
    const int T=5, B=2;
    int bloqueadores[B];
    int tirada[T];
    char seguir;
    int acuTotal = 0;
    cout << "Ingrese su Nick Name: ";
    gotoxy(1,25);
    cout<<"Ingrese X para salir al menu principal"<<endl;
    gotoxy(1,2);
    cin >> nick1;
    mayus(nick1);
    if(nick1[0] == 'X')
    {
        menu();
    }
    for (int i=1; i<=3; i++)
    {
        int contador = 0, acuRonda = 0, bloq = 0;
        setColor(RED);
        system("cls");
        gotoxy(20,2);
        cout << "<<RONDA " << i <<">>"<<endl<<endl;
        setColor(BLACK);
        if (original==true)
        {
            bloqManual(bloqueadores, B);
        }
        else
        {
            dados(bloqueadores, B);
            comprobarIgualdad(bloqueadores, B);
        }
        cout<< "-----BLOQUEADORES-----"<<endl;
        cout<<"|                    |"<<endl;
        cout<<"|                    |"<<endl;
        cout<<"|";
        gotoxy(9,7);
        mostrar(bloqueadores, B);
        cout<<"     |"<<endl;
        cout<<"|                    |"<<endl;
        cout<<"|                    |"<<endl;
        cout<<"----------------------"<<endl;
        cout << endl << endl;


        system("pause");
        do
        {
            contador++;
            cout<<endl<< "Tiro #" << contador << ":   ";
            dados(tirada, T-bloq);
            mostrar(tirada, T-bloq);
            bloq += eliminar(tirada, T, bloqueadores, B);
            acuRonda += sumar(tirada, T);
            ponerCero(tirada, T);

            if(bloq >= T)
            {
                setColor(RED);
                Beep(75,250);
                Beep(75,250);
                Beep(75,300);
                cout << "¡¡Se perdieron todos los puntos de esta ronda!!" << endl << endl;
                setColor(BLACK);
                seguir = 'N';
                acuRonda = 0;
            }
            else
            {
                cout << "¿Desea seguir lanzando los dados?  (S/N)   ";
                cout<<"(X Para salir al menu principal)"<<endl<<endl;
                cin >> seguir;
                seguir = toupper(seguir);

                if(seguir == 'X')
                {
                    menu();
                }
                while(seguir != 'N' && seguir != 'S')
                {
                    cout<<endl<<"Ingrese una opcion válida"<<endl<<endl;
                    cout << "¿Desea seguir lanzando los dados?  (S/N)   ";
                    cout<<"(X Para salir al menu principal)"<<endl<<endl;
                    cin >> seguir;
                    seguir = toupper(seguir);
                    if(seguir == 'X')
                    {
                        menu();
                    }
                }
            }
        }
        while (seguir == 'S');
        acuTotal+=acuRonda;
        setColor(BLUE);
        cout << endl << "Resultados RONDA " << i << " para ";
        cout << nick1 << endl << endl;
        setColor(BLACK);
        cout << "Esta ronda: " << acuRonda << endl;
        cout << "Acumulado parcial: " << acuTotal << endl;
        system("pause");
    }
    system("cls");
    sonidoDescendente();
    cout << "** PUNTAJE FINAL **" << endl << endl;
    cout << nick1 << ": " << acuTotal << endl << endl;
    cout<<"-----FIN DEL JUEGO-----"<<endl;
    system("pause");

    if (acuTotal > *mayor)
    {
        *mayor = acuTotal;
        strcpy(mejorP, nick1);
        mostrarNuevo(mejorP, *mayor);
    }

    setBackgroundColor(LIGHTCYAN);
    cls();
    setColor(BLUE);
}

void multiPlayer(char nick1[], char nick2[], char mejorP[], int *mayor, bool original)
{
    sonidoAscendente();
    setBackgroundColor(WHITE);
    setColor(BLACK);
    system("cls");

    const int T=5, B=2;
    int bloqueadores[B];
    int tirada[T];
    char seguir;
    int acuTotalP1 = 0, acuTotalP2 = 0;;

    cout << "Ingrese el nick Player 1: ";
    gotoxy(1,25);
    cout<<"Ingrese X para salir al menu principal"<<endl;
    gotoxy(1,2);
    cin >> nick1;
    mayus(nick1);
    if(nick1[0] == 'X')
    {
        menu();
    }
    cout << "Ingrese el nick Player 2: ";
    cin >> nick2;
    mayus(nick2);
    if(nick2[0] == 'X')
    {
        menu();
    }


    for (int i=1; i<=3; i++)
    {
        for (int x=1; x<3; x++)
        {
            if (x==1)
            {
                int contador=0, acuRonda = 0, bloq = 0;
                system("cls");
                setColor(RED);
                system("cls");
                gotoxy(20,2);
                cout << "<<RONDA " << i <<">>"<<endl<<endl;
                gotoxy(19,3);
                cout << "**PLAYER: " << nick1 << "**" << endl << endl;
                setColor(BLACK);
                if (original==true)
                {
                    bloqManual(bloqueadores, B);
                }
                else
                {
                    dados(bloqueadores, B);
                    comprobarIgualdad(bloqueadores, B);
                }
                cout<< "-----BLOQUEADORES-----"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"|";
                gotoxy(9,7);
                mostrar(bloqueadores, B);
                cout<<"     |"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"----------------------"<<endl;
                cout << endl << endl;

                system("pause");

                do
                {
                    contador++;
                    cout << "Tiro #" << contador << ":   ";
                    dados(tirada, T-bloq);
                    mostrar(tirada, T-bloq);
                    bloq += eliminar(tirada, T, bloqueadores, B);
                    acuRonda += sumar(tirada, T);
                    ponerCero(tirada, T);
                    if(bloq >= T)
                    {
                        setColor(RED);
                        Beep(75,250);
                        Beep(75,250);
                        Beep(75,300);
                        cout << "¡¡Se perdieron todos los puntos de esta ronda!!" << endl << endl;
                        setColor(BLACK);
                        seguir = 'N';
                        acuRonda = 0;
                    }
                    else
                    {
                        cout << "¿Desea seguir lanzando los dados?  (S/N)  ";
                        cout<<"(X Para salir al menu principal)"<<endl<<endl;
                        cin >> seguir;
                        seguir = toupper(seguir);
                        if(seguir == 'X')
                        {
                            menu();
                        }
                        while(seguir != 'N' && seguir != 'S')
                        {
                            cout<<endl<<"Ingrese una opcion válida"<<endl<<endl;
                            cout << "¿Desea seguir lanzando los dados?  (S/N)   ";
                            cout<<"(X Para salir al menu principal)"<<endl<<endl;
                            cin >> seguir;
                            seguir = toupper(seguir);
                            if(seguir == 'X')
                            {
                                menu();
                            }

                        }
                    }
                }
                while (seguir == 'S');

                acuTotalP1+=acuRonda;

                setColor(BLUE);
                cout << endl << "Resultados RONDA " << i << " para ";
                cout << nick1 << endl << endl;
                setColor(BLACK);
                cout << "Esta ronda: " << acuRonda << endl;
                cout << "Acumulado parcial: " << acuTotalP1 << endl;
                system("pause");
            }
            else
            {
                int contador=0, acuRonda = 0, bloq = 0;
                system("cls");
                setColor(RED);
                system("cls");
                gotoxy(20,2);
                cout << "<<RONDA " << i <<">>"<< endl;
                gotoxy(19,3);
                cout << "**PLAYER: " << nick2 << "**" << endl << endl;
                setColor(BLACK);
                if (original==true)
                {
                    bloqManual(bloqueadores, B);
                }
                else
                {
                    dados(bloqueadores, B);
                    comprobarIgualdad(bloqueadores, B);
                }
                cout<< "-----BLOQUEADORES-----"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"|";
                gotoxy(9,7);
                mostrar(bloqueadores, B);
                cout<<"     |"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"|                    |"<<endl;
                cout<<"----------------------"<<endl;
                cout << endl << endl;

                system("pause");

                do
                {
                    contador++;
                    cout << "Tiro #" << contador << ":   ";
                    dados(tirada, T-bloq);
                    mostrar(tirada, T-bloq);
                    bloq += eliminar(tirada, T, bloqueadores, B);
                    acuRonda += sumar(tirada, T);
                    ponerCero(tirada, T);
                    if(bloq >= T)
                    {
                        setColor(RED);
                        Beep(75,250);
                        Beep(75,250);
                        Beep(75,300);
                        cout << "¡¡Se perdieron todos los puntos de esta ronda!!" << endl << endl;
                        setColor(BLACK);
                        seguir = 'N';
                        acuRonda = 0;
                    }
                    else
                    {
                        cout << "¿Desea seguir jugando?  (S/N)  ";
                        cout<<"(X Para salir al menu principal)"<<endl<<endl;
                        cin >> seguir;
                        seguir = toupper(seguir);
                        if(seguir == 'X')
                        {
                            menu();
                        }
                        while(seguir != 'N' && seguir != 'S')
                        {
                            cout<<endl<<"Ingrese una opcion válida"<<endl<<endl;
                            cout << "¿Desea seguir jugando?  (S/N)   ";
                            cout<<"(X Para salir al menu principal)"<<endl<<endl;
                            cin >> seguir;
                            seguir = toupper(seguir);
                            if(seguir == 'X')
                            {
                                menu();
                            }

                        }
                    }
                }
                while (seguir == 'S');

                acuTotalP2+=acuRonda;
                setColor(RED);
                cout << endl << "Resultados RONDA " << i << " para ";
                cout << nick2 << endl << endl;
                setColor(BLACK);
                cout << "Esta ronda: " << acuRonda << endl;
                cout << "Acumulado parcial: " << acuTotalP2 << endl;
                system("pause");
            }
        }
    }
    if (acuTotalP1>acuTotalP2)
    {
        mostrarGanador(nick1, acuTotalP1);
        if (acuTotalP1 > *mayor)
        {
            *mayor = acuTotalP1;
            strcpy(mejorP, nick1);
            mostrarNuevo(mejorP, *mayor);
        }
    }
    else
    {
        mostrarGanador(nick2, acuTotalP2);
        if (acuTotalP2 > *mayor)
        {
            *mayor = acuTotalP2;
            strcpy(mejorP, nick2);
            mostrarNuevo(mejorP, *mayor);
        }
    }
}

void instrucciones()
{
    system("cls");
    cout<<"INSTRUCCIONES"<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"GREED es juego de dados que consiste en una serie de tres rondas en las cuales "<<endl<<
        "los jugadores deberán tirar dos dados llamados Bloqueadores y numerosas tiradas de hasta cinco dados."<<endl<<endl;
    cout<<"Por cada tirada de una ronda se deberán sumar todos los dados de la tirada cuyos valores "<<endl<<"no coincidan con los dados bloqueadores."<<endl<<endl;
    cout<<"Cada dado cuyo valor sea igual al de un dado bloqueador es un dado que no podrá "<<endl<<"utilizarse en la siguiente tirada disminuyendo así la cantidad de dados a tirar."<<endl<<endl;
    cout<<"Luego de cada tirada, se le debe preguntar al usuario si desea continuar tirando o no."<<endl<<"En caso negativo, se sumarán los puntos acumulados en la ronda y será el turno del próximo jugador"<<endl<<"(en el modo de dos jugadores) o comenzará la próxima ronda (en el modo de un jugador)."<<endl<<endl;
    cout<<"En caso de que el jugador decida seguir jugando en la ronda, se tirarán nuevamente los "<<endl<<"dados correspondientes y se procederá a la acumulación de puntos de esa tirada y así hasta que termine la ronda."<<endl<<endl;
    cout<<"Una ronda también puede finalizar si el jugador se queda sin dados disponibles para tirar"<<endl<<"(recordar que cada dado igual a un dado bloqueador se elimina para la próxima tirada),"<<endl<<"con la diferencia, de que si un jugador en una ronda se queda sin dados disponibles,"<<endl<<"el puntaje acumulado para esa ronda será de cero."<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl<<endl;

    musicaInstrucciones();
    system("pause");
}

void creditos()
{
    system("cls");

    cout<<"----------------------"<<endl;
    cout<<"       CREDITOS       "<<endl;
    cout<<"----------------------"<<endl<<endl<<endl;
    musicaCreditos1();
    cout<<"EQUIPO: ChavCecco"<<endl<<endl;
    cout<<"Integrantes: "<<endl<<endl<<"Eduardo Chavero - Legajo: 24171"<<endl<<endl<<"Nicolás De Cecco - Legajo: 21834"<<endl<<endl;
    cout<<"Carrera: TUP"<<endl<<endl;
    cout<<"Materia: LAB I"<<endl<<endl;
    cout<<"----------------------"<<endl<<endl;
    musicaCreditos2();
    system("pause");
}

void sonidoAscendente()
{
    for(int i=50; i<120; i+=10)
    {
        Beep(i,100);
    }
}

void sonidoDescendente()
{
    for(int i=120; i>50; i-=10)
    {
        Beep(i,70);
    }
}

void sonidoMejorPuntaje()
{
    Beep(300, 70);
    Beep(220, 70);
    Beep(270, 70);
    Beep(150, 70);
    Beep(180, 70);
    Beep(80, 70);
    Beep(110, 70);
}

void sonidoInicio()
{
    Beep (330,100);
    Sleep(70);
    Beep (330,100);
    Sleep(210);
    Beep (330,100);
    Sleep(210);
    Beep (262,100);
    Sleep(70);
    Beep (330,100);
    Sleep(210);
    Beep (392,100);
    Sleep(490);
    Beep (196,200);
    Sleep(490);
}

void musicaCreditos1()
{
    Beep(220,300);
    Beep(294,300);
    Beep(294,300);
    Beep(370,300);
    Beep(494,300);
    Beep(370,300);
    Beep(440,800);

}

void musicaCreditos2()
{
    Beep(440,300);
    Beep(494,300);
    Beep(440,300);
    Beep(370,300);
    Beep(392,300);
    Beep(370,300);
    Beep(330,800);
}

void musicaInstrucciones()
{
    Beep(247,300);
    Beep(330,300);
    Beep(330,300);
    Beep(370,300);
    Beep(555,300);
    Beep(555,300);
    Beep(494,300);
    Beep(440,300);
    Beep(392,800);
    Beep(392,300);
    Beep(370,300);
    Beep(247,800);
    Beep(278,300);
    Beep(294,300);
    Beep(330,1500);

}

void intro()
{
    setBackgroundColor(LIGHTCYAN);
    setColor(BLUE);
    cls();
    cout<<" -------------------------------"<<endl<<endl;
    cout<<"|      Bienvenido a GREED!     |"<<endl<<endl;
    cout<<" -------------------------------"<<endl<<endl;
    cout<< "Cargando..."<<endl;
    sonidoInicio();
    system("pause");
}
