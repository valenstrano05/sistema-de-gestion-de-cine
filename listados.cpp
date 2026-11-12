#include <iostream>
#include <windows.h>
#include "listados.h"
#include "funciones.h"
#include "clsArchivoPeliculas.h"
#include <vector>
#include "clsArchivoSocios.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoCompras.h"
using namespace std;

void listadosPeliculas()
{
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|             LISTADOS DE PELICULAS            |" << endl;
        cout << "|                                              |" << endl;
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
        }
        system("pause");
    }
}

void listarPeliculasPorNombre()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay peliculas registradas en el archivo." << endl;
        return;
    }
    vector<Pelicula> vecPeliculas;

    for (int i = 0; i < cant; i++)
    {
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecPeliculas.push_back(obj);
        }
    }
    int activas = vecPeliculas.size();
    if (activas == 0)
    {
        cout << "No hay peliculas activas para ordenar." << endl;
        return;
    }
    Pelicula  aux;
    for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1; j++)
        {
            if (strcmp(vecPeliculas[j].getTitulo(),vecPeliculas[j+1].getTitulo()) > 0)
            {
                aux = vecPeliculas[j];
                vecPeliculas[j] = vecPeliculas[j+1];
                vecPeliculas[j+1] = aux;
            }
        }
    }
    cout << "=======================================" << endl;
    cout << "    PELICULAS ORDENADAS POR NOMBRE     " << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecPeliculas[i].mostrar();

    }
}

void listarPeliculasCronologico() {
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay peliculas registradas en el archivo." << endl;
        return;
    }
    vector<Pelicula> vecPeliculas;

    for (int i = 0; i < cant; i++)
    {
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecPeliculas.push_back(obj);
        }
    }
    int activas = vecPeliculas.size();
    if (activas == 0)
    {
        cout << "No hay peliculas activas para ordenar." << endl;
        return;
    }

    Pelicula aux;
    for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1 - i; j++)
        {
            if (vecPeliculas[j].getFechaEstreno() > vecPeliculas[j+1].getFechaEstreno())
            {
                aux = vecPeliculas[j];
                vecPeliculas[j] = vecPeliculas[j+1];
                vecPeliculas[j+1] = aux;
            }
        }
    }

    cout << "=======================================" << endl;
    cout << "PELICULAS ORDENADAS POR FECHA DE ESTRENO" << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecPeliculas[i].mostrar();

    }
}
}

void listarPeliculasPorDuracion()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay peliculas registradas en el archivo." << endl;
        return;
    }
    vector<Pelicula> vecPeliculas;

    for (int i = 0; i < cant; i++)
    {
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecPeliculas.push_back(obj);
        }
    }
    int activas = vecPeliculas.size();
    if (activas == 0)
    {
        cout << "No hay peliculas activas para ordenar." << endl;
        return;
    }

    Pelicula aux;
    for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1 - i; j++)
        {
            if (vecPeliculas[j].getDuracion() > vecPeliculas[j+1].getDuracion())
            {
                aux = vecPeliculas[j];
                vecPeliculas[j] = vecPeliculas[j+1];
                vecPeliculas[j+1] = aux;
            }
        }
    }

    cout << "=======================================" << endl;
    cout << "   PELICULAS ORDENADAS POR DURACION" << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecPeliculas[i].mostrar();

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
        cout << "     2. ORDENADOS DE FORMA ALFABÉTICA" << endl;
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

void listarSociosAlfabetico()
{
    ArchivoSocios arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay socios registrados en el archivo." << endl;
        return;
    }
    vector<Socio> vecSocios;

    for (int i = 0; i < cant; i++)
    {
        Socio obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecSocios.push_back(obj);
        }
    }
    int activos = vecSocios.size();
    if (activos == 0)
    {
        cout << "No hay socios activos para ordenar." << endl;
        return;
    }
    Socio aux;
    for (int i = 0; i < activos-1; i++)
    {
        for (int j = 0; j < activos-1; j++)
        {
            if (strcmp(vecSocios[j].getApellido(),vecSocios[j+1].getApellido()) > 0)
            {
                aux = vecSocios[j];
                vecSocios[j] = vecSocios[j+1];
                vecSocios[j+1] = aux;
            }
        }
    }
    for (int i = 0; i < activos-1; i++)
    {
        for (int j = 0; j < activos-1; j++)
        {
            if (strcmp(vecSocios[j].getApellido(),vecSocios[j+1].getApellido()) == 0){
            if (strcmp(vecSocios[j].getNombre(),vecSocios[j+1].getNombre())>0)
            {
                aux = vecSocios[j];
                vecSocios[j] = vecSocios[j+1];
                vecSocios[j+1] = aux;
            }
            }
        }
    }
    cout << "=======================================" << endl;
    cout << "SOCIOS ORDENADOS DE FORMA ALFABÉTICA" << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < activos; i++)
    {
        vecSocios[i].mostrar();

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
        }
    }
}

void listarFuncionesCronologico()
{
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay funciones registradas en el archivo." << endl;
        return;
    }
    vector<Funcion> vecFunciones;

    for (int i = 0; i < cant; i++)
    {
        Funcion obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecFunciones.push_back(obj);
        }
    }
    int activas = vecFunciones.size();
    if (activas == 0)
    {
        cout << "No hay funciones activas para ordenar." << endl;
        return;
    }

    Funcion aux;
    for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1 - i; j++)
        {
            if (vecFunciones[j].getFecha() > vecFunciones[j+1].getFecha())
            {
                aux = vecFunciones[j];
                vecFunciones[j] = vecFunciones[j+1];
                vecFunciones[j+1] = aux;
            }
        }
    }
        for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1 - i; j++)
        {
            if (vecFunciones[j].getFecha() == vecFunciones[j+1].getFecha()){
                if(vecFunciones[j].getHorario()>vecFunciones[j+1].getHorario())
            {
                aux = vecFunciones[j];
                vecFunciones[j] = vecFunciones[j+1];
                vecFunciones[j+1] = aux;
            }
        }
    }
}
    cout << "=======================================" << endl;
    cout << "FUNCIONES ORDENADAS DE FORMA CRONOLÓGICA" << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecFunciones[i].mostrar();

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

void listarComprasPorFecha()
{
    ArchivoCompras arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay compras registradas en el archivo." << endl;
        return;
    }
    vector<Compra> vecCompras;

    for (int i = 0; i < cant; i++)
    {
        Compra obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecCompras.push_back(obj);
        }
    }
    int activas = vecCompras.size();
    if (activas == 0)
    {
        cout << "No hay funciones activas para ordenar." << endl;
        return;
    }

    Compra aux;
    for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1 - i; j++)
        {
            if (vecCompras[j].getFecha() > vecCompras[j+1].getFecha())
            {
                aux = vecCompras[j];
                vecCompras[j] = vecCompras[j+1];
                vecCompras[j+1] = aux;
            }
        }
    }
        for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1 - i; j++)
        {
            if (vecCompras[j].getFecha() == vecCompras[j+1].getFecha()){
                if(vecCompras[j].getHorario()>vecCompras[j+1].getHorario())
            {
                aux = vecCompras[j];
                vecCompras[j] = vecCompras[j+1];
                vecCompras[j+1] = aux;
            }
        }
    }
}
    cout << "=======================================" << endl;
    cout << "COMPRAS ORDENADAS DE FORMA CRONOLÓGICA" << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecCompras[i].mostrar();

    }
}
