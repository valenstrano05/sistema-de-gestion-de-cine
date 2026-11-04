#include <iostream>
#include <windows.h>
#include "listados.h"
#include "funciones.h"

using namespace std;

void listadosPeliculas()
{
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|             LISTADOS DE PELICULAS             |" << endl;
        cout << "|                                               |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. LISTADO GENERAL" << endl;
        cout << "     2. ORDENADAS POR NOMBRE" << endl;
        cout << "     3. ORDENADAS POR FECHA DE ESTRENO" << endl;
        cout << "     4. ORDENADAS POR DURACION" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarPeliculas();
            break;
        case 2:
            listarPeliculasPorNombre();
            break;
        case 3:
            listarPeliculasCronologico();
            break;
        case 4:
            listarPeliculasPorDuracion();
            break;
        case 0:
            return;
            break;
        }
        system("pause");
    }
}

void listadosSocios()
{
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|              LISTADOS DE SOCIOS               |" << endl;
        cout << "|                                               |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. LISTADO GENERAL" << endl;
        cout << "     2. ORDENADOS POR APELLIDO" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarSocios();
            break;
        case 2:
            listarSociosAlfabetico();
            break;
        case 0:
            return;
            break;
        }
        system("pause");
    }
}


void listadosFunciones()
{
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|             LISTADOS DE FUNCIONES             |" << endl;
        cout << "|                                               |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. LISTADO GENERAL" << endl;
        cout << "     2. ORDENADAS POR FECHA Y HORA DE PROYECCION" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarFunciones();
            break;
        case 2:
            listarFuncionesCronologico();
            break;
        case 0:
            return;
            break;
        }
        system("pause");
    }
}

void listadosCompras()
{
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|              LISTADOS DE COMPRAS              |" << endl;
        cout << "|                                               |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. LISTADO GENERAL" << endl;
        cout << "     2. ORDENADAS POR FECHA" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarCompras();
            break;
        case 2:
            listarComprasPorFecha();
            break;
        case 0:
            return;
            break;
        }
        system("pause");
    }
}

void listarPeliculasPorNombre(){}
void listarPeliculasCronologico(){}
void listarPeliculasPorDuracion(){}
void listarSociosAlfabetico() {}
void listarFuncionesCronologico() {}
void listarComprasPorFecha() {}
