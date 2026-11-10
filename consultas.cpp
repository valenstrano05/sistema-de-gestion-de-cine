#include <iostream>
#include <windows.h>
#include <vector>
#include <cstring>
#include "consultas.h"
#include "funciones.h"
#include "clsArchivoPeliculas.h"
#include "clsArchivoFunciones.h"
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








void consultarFunciones()
{
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|               CONSULTAR FUNCIONES            |" << endl;
        cout << "|                                              |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. POR PELICULA" << endl;
        cout << "     2. POR FECHA" << endl;
        cout << "     3. POR SALA" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            funcionesPorPelicula();
            break;
        case 2:
            //funcionesPorFecha();
            break;
        case 3:
            //funcionesPorSala();
            break;
        case 0:
            return;
        }
        system("pause");
    }
}


void funcionesPorPelicula()
{
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();
    if (cant == 0){
        cout <<"No hay funciones cargadas." <<endl;
        return;
    }

    int id;
    cout << "=======================================" << endl;
    cout << "   CONSULTAR FUNCIONES POR PELICULA    " << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese el ID de la pelicula a consultar: ";
    cin>>id;

    ArchivoPeliculas archP;
    int cantP = archP.contarRegistros();
    if (cant == 0){
        cout <<"No hay peliculas registradas. " <<endl;
        return;
    }
    bool existePelicula = false;
    char titulo[50]{};

    for (int i=0; i<cantP; i++){
        Pelicula obj = archP.leerRegistro(i);
        if (obj.getEstado() && obj.getID() == id){
            existePelicula=true;
            strcpy(titulo, obj.getTitulo());
            break;
        }
    }
    if (!existePelicula){
        cout <<"No se registro una pelicula con el ID " <<id <<"." <<endl;
        return;
    }

    vector <Funcion> vecFunciones;
    for (int i=0; i<cant; i++){
        Funcion obj = arch.leerRegistro(i);
        if (obj.getEstado()){
            if (obj.getIdPelicula()==id){
                vecFunciones.push_back(obj);
            }
        }
    }

    int encontrados=vecFunciones.size();
    if (encontrados == 0){
        cout <<"No hay funciones registradas para la pelicula " <<titulo<<"." <<endl;
        return;
    }
    system ("cls");
    cout << "=======================================" << endl;
    cout <<"   FUNCIONES DE LA PELICULA " <<titulo <<endl;
    cout << "=======================================" << endl;
    for (int i=0; i<encontrados; i++){
        vecFunciones[i].mostrar();
    }

}




