#include <iostream>
#include <windows.h>
#include <vector>
#include <cstring>
#include "consultas.h"
#include "funciones.h"
#include "clsArchivoPeliculas.h"
using namespace std;


void consultarPeliculas()
{
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|               CONSULTAR PELICULAS            |" << endl;
        cout << "|                                              |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. POR GENERO" << endl;
        cout << "     2. POR CLASIFICACION" << endl;
        cout << "     3. POR DIRECTOR" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            peliculasPorGenero();
            break;
        case 2:
            peliculasPorClasificacion();
            break;
        case 3:
            peliculasPorDirector();
            break;
        case 0:
            return;
        }
        system("pause");
    }
}


void peliculasPorGenero()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant == 0){
        cout <<"No hay peliculas registradas." <<endl;
        return;
    }

    char genero [30];
    cout << "=======================================" << endl;
    cout << "    CONSULTAR PELICULAS POR GENERO   " << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese el genero a buscar: ";
    cin>> ws;
    cin.getline(genero, 30);

    vector <Pelicula> vecPeliculas;
    for (int i=0; i<cant; i++){
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado()){
            if (_stricmp(obj.getGenero(), genero) == 0){
                vecPeliculas.push_back(obj);
            }
        }
    }

    int encontrado = vecPeliculas.size();
    if (encontrado == 0){
        cout <<"No hay peliculas registradas del genero " <<genero <<"." <<endl;
        return;
    }
    system("cls");
    cout << "=======================================" << endl;
    cout <<"   PELICULAS DEL GENERO " <<genero <<endl;
    cout << "=======================================" << endl;
    for (int i=0; i<encontrado; i++){
        vecPeliculas[i].mostrar();
    }

}



void peliculasPorClasificacion()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0){
        cout <<"No hay peliculas registradas. " <<endl <<endl;
        return;
    }

    int clasificacion;
    cout << "=============================================" << endl;
    cout << "    CONSULTAR PELICULAS POR CLASIFICACION" << endl;
    cout << "=============================================" << endl;
    cout << "\t1. ATP" << endl;
    cout << "\t2. +14" << endl;
    cout << "\t3. +18" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Ingrese la opcion deseada: "; cin >> clasificacion;

    if (clasificacion<1 || clasificacion>3){
        cout <<"Opcion invalida." <<endl;
        return;
    }

    system ("cls");

    vector<Pelicula> vecPeliculas;

    for (int i=0; i<cant; i++){
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado()){
            if (obj.getClasificacion() == clasificacion){
                vecPeliculas.push_back(obj);
            }
        }
    }

    int encontradas = vecPeliculas.size();
    if (encontradas == 0){
        cout <<"No hay peliculas registradas con esta clasificacion." <<endl;
        return;
    }

    const char* clasificaciones[3]={"ATP", "+14", "+18"};
    cout << "=======================================" << endl;
    cout <<"   PELICULAS CON LA CLASIFICACION " <<clasificaciones[clasificacion-1] <<endl;
    cout << "=======================================" << endl;
    for (int i=0; i<encontradas; i++){
        vecPeliculas[i].mostrar();
    }

}



void peliculasPorDirector()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0){
        cout <<"No hay peliculas registradas. " <<endl;
        return;
    }

    char directorBuscado[50]{};
    cout << "=======================================" << endl;
    cout << "  CONSULTAR PELICULAS POR DIRECTOR/A   " << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese el nombre del director a buscar: ";
    cin >>ws;
    cin.getline(directorBuscado, 50);

    vector <Pelicula> vecPeliculas;

    for (int i=0; i<cant; i++){
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado()){
            if (_stricmp(obj.getDirector(), directorBuscado) == 0){
                vecPeliculas.push_back(obj);
            }
        }
    }

    int encontrado = vecPeliculas.size();
    if (encontrado == 0){
        cout <<"No hay peliculas registradas del director/a "<<directorBuscado <<"."<<endl;
        return;
    }
    system ("cls");
    cout << "=======================================" << endl;
    cout <<"   PELICULAS DEL DIRECTOR/A " <<directorBuscado <<endl;
    cout << "=======================================" << endl;
    for (int i=0; i<encontrado; i++){
        vecPeliculas[i].mostrar();
    }
}

