#include <iostream>
#include <windows.h>
#include <vector>
#include <cstring>
#include "consultas.h"
#include "funciones.h"
#include "clsArchivoPeliculas.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoSocios.h"
#include "clsArchivoCompras.h"
#include "clsArchivoSalas.h"
using namespace std;

//PELICULAS
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

//FUNCIONES
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
            funcionesPorFecha();
            break;
        case 3:
            funcionesPorSala();
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
    if (existePelicula==false){
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

void funcionesPorFecha()
{
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();
    if (cant <= 0)
    {
        cout << "No hay funciones registradas." << endl;
        system("pause");
        return;
    }

    cout << "=======================================" << endl;
    cout << "     CONSULTAR FUNCIONES POR FECHA     " << endl;
    cout << "=======================================" << endl;

    int dia = pedirEntero("Ingrese el dia: ");
    while (dia < 1 || dia > 31)
    {
        dia = pedirEntero("Error, dia invalido (1-31). Ingrese nuevamente: ");
    }

    int mes = pedirEntero("Ingrese el mes: ");
    while (mes < 1 || mes > 12)
    {
        mes = pedirEntero("Error, mes invalido (1-12). Ingrese nuevamente: ");
    }

    int anio = pedirEntero("Ingrese el año: ");
    while (anio <= 0)
    {
        anio = pedirEntero("Error, año invalido. Ingrese nuevamente: ");
    }

    vector<Funcion> vecFunciones;

    for (int i = 0; i < cant; i++)
    {
        Funcion obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            if (obj.getFecha().getAnio() == anio && obj.getFecha().getMes() == mes && obj.getFecha().getDia() == dia)
            {
                vecFunciones.push_back(obj);
            }
        }
    }

    int encontrados = vecFunciones.size();
    if (encontrados == 0)
    {
        cout << "No hay funciones registradas para la fecha ingresada." << endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "=======================================" << endl;
    cout << "     FUNCIONES DE LA FECHA" << dia<<"/"<<mes<<"/"<<anio<<endl;
    cout << "=======================================" << endl;
    for (int i = 0; i < encontrados; i++)
    {
        vecFunciones[i].mostrar();
        cout << "=======================================" << endl;
    }
    system("pause");
}

void funcionesPorSala()
{
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();
    if (cant <= 0)
    {
        cout << "No hay funciones registradas." << endl;
        return;
    }

    int idSala = pedirEntero("Ingrese el ID de la sala a consultar: ");
    ArchivoSalas archS;
    if (archS.buscarRegistro(idSala) == -1)
    {
        cout << "No existe una sala con ese ID." << endl;
        return;
    }

    vector<Funcion> vecFunciones;

    for (int i = 0; i < cant; i++)
    {
        Funcion obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            if (obj.getIdSala() == idSala)
            {
                vecFunciones.push_back(obj);
            }
        }
    }

    int encontrados = vecFunciones.size();
    if (encontrados == 0)
    {
        cout << "No hay funciones registradas para la sala " << idSala << "." << endl;
        return;
    }

    system("cls");
    cout << "=======================================" << endl;
    cout << "     FUNCIONES DE LA SALA " << idSala << endl;
    cout << "=======================================" << endl;
    cout << endl;
    for (int i = 0; i < encontrados; i++)
    {
        vecFunciones[i].mostrar();
    cout << "=======================================" << endl;
        cout << endl;
    }
}

//SOCIOS
void consultarSocios()
{
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|                CONSULTAR SOCIOS               |" << endl;
        cout << "|                                               |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. POR DNI" << endl;
        cout << "     2. POR APELLIDO" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            sociosPorDni();
            break;
        case 2:
            sociosPorApellido();
            break;
        case 0:
            return;
        }
        system("pause");
    }
}
void sociosPorDni()
{
    ArchivoSocios arch;
    int cant = arch.contarRegistros();
    if (cant <= 0)
    {
        cout << "No hay socios registrados." << endl;
        return;
    }

    int dniBuscado = pedirEntero("Ingrese el DNI a buscar: ");
    vector<Socio> vecSocios;

    for (int i = 0; i < cant; i++)
    {
        Socio obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            if (obj.getDni() == dniBuscado)
            {
                vecSocios.push_back(obj);
            }
        }
    }

    int encontrados = vecSocios.size();
    if (encontrados == 0)
    {
        cout << "No hay socios registrados con el DNI " << dniBuscado << "." << endl;
        return;
    }

    system("cls");
    cout << "=======================================" << endl;
    cout << "     SOCIOS CON DNI " << dniBuscado << endl;
    cout << "=======================================" << endl;
    for (int i = 0; i < encontrados; i++)
    {
        vecSocios[i].mostrar();
    }
}

void sociosPorApellido()
{
    ArchivoSocios arch;
    int cant = arch.contarRegistros();
    if (cant <= 0)
    {
        cout << "No hay socios registrados." << endl;
        return;
    }

    char apellidoBuscado[30];
    cargarCadena("Ingrese el apellido a buscar: ", apellidoBuscado, 30);
    vector<Socio> vecSocios;

    for (int i = 0; i < cant; i++)
    {
        Socio obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            if (_stricmp(obj.getApellido(), apellidoBuscado) == 0)
            {
                vecSocios.push_back(obj);
            }
        }
    }

    int encontrados = vecSocios.size();
    if (encontrados == 0)
    {
        cout << "No hay socios registrados con el apellido " << apellidoBuscado << "." << endl;
        return;
    }

    system("cls");
    cout << "=======================================" << endl;
    cout << "     SOCIOS CON APELLIDO " << apellidoBuscado << endl;
    cout << "=======================================" << endl;
    for (int i = 0; i < encontrados; i++)
    {
        vecSocios[i].mostrar();
    }
}

void comprasPorSocio() {
    ArchivoSocios archS;
    ArchivoCompras arcC;
    Socio socio;
    bool encontro = false;
    int id = pedirEntero("ID del socio a consultar: ");
    int pos = archS.buscarRegistro(id);
    if (pos == -1)
    {
        cout << "No existe un socio con ese ID." << endl;
        system("pause");
        return;
    }
    socio = archS.leerRegistro(pos);
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << " SOCIO: " << socio.getNombre() << " " << socio.getApellido() << " (ID: " << id << ")" << endl;
    cout << "---------------------------------------" << endl;
    int cantCompras = arcC.contarRegistros();
    if (cantCompras <= 0)
    {
        cout << "No hay compras registradas en el sistema o el archivo esta vacio." << endl;
        return;
    }
    for (int i = 0; i < cantCompras; i++)
    {
        Compra c= arcC.leerRegistro(i);
        if (c.getEstado() == true && c.getIdSocio() == id)
        {
            c.mostrar();
            cout << "---------------------------------------" << endl;
            encontro = true;
        }
    }
    if (encontro==false)
    {
        cout << "El socio no registra compras activas en el sistema." << endl;
    }
}
