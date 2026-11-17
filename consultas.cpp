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
#include "clsArchivoDetalleEntradas.h"
using namespace std;

//PELICULAS
void consultarPeliculas()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|                CONSULTAR PELICULAS           |" << endl;
        cout << "|                                              |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. POR GENERO" << endl;
        cout << "     2. POR CLASIFICACION" << endl;
        cout << "     3. POR DIRECTOR" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "================================================" << endl;
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
        cout << "No hay peliculas registradas." << endl;
        system("pause");
        return;
    }

    char genero [30];
    cout << "=======================================" << endl;
    cout << "    CONSULTAR PELICULAS POR GENERO     " << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese el genero a buscar: ";
    cin >> ws;
    cin.getline(genero, 30);

    vector <Pelicula> vecPeliculas;
    for (int i=0; i<cant; i++){
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado()){
            if (strcmp(obj.getGenero(), genero) == 0){
                vecPeliculas.push_back(obj);
            }
        }
    }

    int encontrado = vecPeliculas.size();
    system("cls");
    if (encontrado == 0){
        cout << "No hay peliculas registradas del genero " << genero << "." << endl;
        system("pause");
        return;
    }

    cout << " ===============================================================================================================" << endl;
    cout << "                                PELICULAS DEL GENERO: " << genero << endl;
    cout << " ===============================================================================================================" << endl;
    for (int i=0; i<encontrado; i++){
        vecPeliculas[i].mostrar();
        cout << " ===============================================================================================================" << endl;
    }
    system("pause");
}


void peliculasPorClasificacion()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0){
        cout << "No hay peliculas registradas." << endl;
        system("pause");
        return;
    }

    int clasificacion;
    cout << "=============================================" << endl;
    cout << "    CONSULTAR PELICULAS POR CLASIFICACION" << endl;
    cout << "=============================================" << endl;
    cout << "1. ATP" << endl;
    cout << "2. +14" << endl;
    cout << "3. +18" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";
    cin >> clasificacion;

    while (clasificacion < 1 || clasificacion > 3){
        cout << "Opcion invalida. Intente de nuevo: ";
        cin >> clasificacion;
    }
    system("cls");
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
        cout << "No hay peliculas registradas con esta clasificacion." << endl;
        system("pause");
        return;
    }

    const char* clasificaciones[3]={"ATP", "+14", "+18"};
    cout << " ===============================================================================================================" << endl;
    cout << "                         PELICULAS CON LA CLASIFICACION " << clasificaciones[clasificacion-1] << endl;
    cout << " ===============================================================================================================" << endl;
    for (int i=0; i<encontradas; i++){
        vecPeliculas[i].mostrar();
        cout << " ===============================================================================================================" << endl;
    }
    system("pause");
}

void peliculasPorDirector()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0){
        cout << "No hay peliculas registradas." << endl;
        system("pause");
        return;
    }

    char directorBuscado[50]{};
    cout << "=======================================" << endl;
    cout << "  CONSULTAR PELICULAS POR DIRECTOR/A   " << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese el nombre del director a buscar: ";
    cin >> ws;
    cin.getline(directorBuscado, 50);

    vector <Pelicula> vecPeliculas;

    for (int i=0; i<cant; i++){
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado()){
            if (strcmp(obj.getDirector(), directorBuscado) == 0){
                vecPeliculas.push_back(obj);
            }
        }
    }

    int encontrado = vecPeliculas.size();
    system("cls");
    if (encontrado == 0){
        cout << "No hay peliculas registradas del director/a " << directorBuscado << "." << endl;
        system("pause");
        return;
    }

    cout << " ===============================================================================================================" << endl;
    cout << "                         PELICULAS DEL DIRECTOR/A: " << directorBuscado << endl;
    cout << " ===============================================================================================================" << endl;
    for (int i=0; i<encontrado; i++){
        vecPeliculas[i].mostrar();
        cout << " ===============================================================================================================" << endl;
    }
    system("pause");
}

//FUNCIONES
void consultarFunciones()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|                CONSULTAR FUNCIONES           |" << endl;
        cout << "|                                              |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. POR PELICULA" << endl;
        cout << "     2. POR FECHA" << endl;
        cout << "     3. POR SALA" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "================================================" << endl;
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
    }
}

void funcionesPorPelicula()
{
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();
    if (cant == 0){
        cout << "No hay funciones cargadas." << endl;
        system("pause");
        return;
    }

    ArchivoPeliculas archP;
    int cantP = archP.contarRegistros();
    if (cantP == 0){
        cout << "No hay peliculas registradas." << endl;
        system("pause");
        return;
    }

    int id;
    bool existePelicula = false;
    char titulo[50]{};

    while (true)
    {
        system("cls");
        cout << "=======================================" << endl;
        cout << "   CONSULTAR FUNCIONES POR PELICULA    " << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese el ID de la pelicula a consultar (o 0 para volver): ";
        cin >> id;

        if (id == 0) return;

        existePelicula = false;
        for (int i = 0; i < cantP; i++){
            Pelicula obj = archP.leerRegistro(i);
            if (obj.getEstado() && obj.getID() == id){
                existePelicula = true;
                strcpy(titulo, obj.getTitulo());
                break;
            }
        }

        if (existePelicula) {
            break;
        }

        cout << endl << "No se registro una pelicula con el ID " << id << ". Intente de nuevo." << endl;
        system("pause");
    }

    vector <Funcion> vecFunciones;
    for (int i=0; i<cant; i++){
        Funcion obj = arch.leerRegistro(i);
        if (obj.getEstado()){
            if (obj.getIdPelicula() == id){
                vecFunciones.push_back(obj);
            }
        }
    }

    int encontrados = vecFunciones.size();
    system("cls");
    if (encontrados == 0){
        cout << "====================================================" << endl;
        cout << "   FUNCIONES DE LA PELICULA: " << titulo << endl;
        cout << "====================================================" << endl;
        cout << "No hay funciones registradas para esta pelicula." << endl;
        system("pause");
        return;
    }

    cout << "====================================================" << endl;
    cout << "   FUNCIONES DE LA PELICULA: " << titulo << endl;
    cout << "====================================================" << endl;
    for (int i=0; i<encontrados; i++){
        vecFunciones[i].mostrar();
        cout << "====================================================" << endl;
    }
    system("pause");
}

void funcionesPorFecha()
{
    int dia, mes, anio;
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();
    if (cant <= 0)
    {
        cout << "No hay funciones registradas." << endl;
        system("pause");
        return;
    }

    cout << "=======================================" << endl;
    cout << "      CONSULTAR FUNCIONES POR FECHA    " << endl;
    cout << "=======================================" << endl;

    cout << "Ingrese el dia: ";
    cin >> dia;
    while (dia < 1 || dia > 31)
    {
        cout << "Error, dia invalido (1-31). Ingrese nuevamente: ";
        cin >> dia;
    }
    cout << "Ingrese el mes: ";
    cin >> mes;
    while (mes < 1 || mes > 12)
    {
        cout << "Error, mes invalido (1-12). Ingrese nuevamente: ";
        cin >> mes;
    }
    cout << "Ingrese el anio: ";
    cin >> anio;
    while (anio <= 0)
    {
        cout << "Error, anio invalido. Ingrese nuevamente: ";
        cin >> anio;
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
    system("cls");
    if (encontrados == 0)
    {
        cout << "No hay funciones registradas para la fecha ingresada." << endl;
        system("pause");
        return;
    }

    cout << "===========================================" << endl;
    cout << "      FUNCIONES DE LA FECHA " << dia << "/" << mes << "/" << anio << endl;
    cout << "===========================================" << endl;
    for (int i = 0; i < encontrados; i++)
    {
        vecFunciones[i].mostrar();
        cout << "===========================================" << endl;
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
        system("pause");
        return;
    }

    ArchivoSalas archS;
    int idSala;

    while (true)
    {
        system("cls");
        cout << "=======================================" << endl;
        cout << "      CONSULTAR FUNCIONES POR SALA     " << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese el ID de la sala a consultar (o 0 para volver): ";
        cin >> idSala;

        if (idSala == 0) return;

        if (archS.buscarRegistro(idSala) != -1)
        {
            break;
        }

        cout << endl << "No existe una sala con ese ID. Intente de nuevo." << endl;
        system("pause");
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
    system("cls");
    cout << "=======================================" << endl;
    cout << "      FUNCIONES DE LA SALA " << idSala << endl;
    cout << "=======================================" << endl;
    cout << endl;

    if (encontrados == 0)
    {
        cout << "No hay funciones registradas para la sala " << idSala << "." << endl;
    }
    else
    {
        for (int i = 0; i < encontrados; i++)
        {
            vecFunciones[i].mostrar();
            cout << "=======================================" << endl;
            cout << endl;
        }
    }
    system("pause");
}

//SOCIOS
void consultarSocios()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|                CONSULTAR SOCIOS              |" << endl;
        cout << "|                                              |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. POR DNI" << endl;
        cout << "     2. POR APELLIDO" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "================================================" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            socioPorDni();
            break;
        case 2:
            sociosPorApellido();
            break;
        case 0:
            return;
        }
    }
}

void socioPorDni()
{
    ArchivoSocios arch;
    int cant = arch.contarRegistros();
    if (cant <= 0)
    {
        cout << "No hay socios registrados." << endl;
        system("pause");
        return;
    }

    int dniBuscado;
    Socio socio;
    bool encontrado = false;

    while (true)
    {
        system("cls");
        cout << "=======================================" << endl;
        cout << "         CONSULTAR SOCIO POR DNI       " << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese el DNI a buscar (o 0 para volver): ";
        cin >> dniBuscado;

        if (dniBuscado == 0) return;

        encontrado = false;
        for (int i = 0; i < cant; i++)
        {
            Socio obj = arch.leerRegistro(i);
            if (obj.getEstado() && obj.getDni() == dniBuscado)
            {
                socio = obj;
                encontrado = true;
                break;
            }
        }

        if (encontrado)
        {
            break;
        }

        cout << endl << "No hay un socio registrado con el DNI " << dniBuscado << ". Intente de nuevo." << endl;
        system("pause");
    }

    system("cls");
    cout << "=======================================" << endl;
    cout << "          DATOS DEL SOCIO              " << endl;
    cout << "=======================================" << endl;
    socio.mostrar();
    cout << "=======================================" << endl;
    system("pause");
}

void sociosPorApellido()
{
    ArchivoSocios arch;
    int cant = arch.contarRegistros();
    if (cant <= 0)
    {
        cout << "No hay socios registrados." << endl;
        system("pause");
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
            if (strcmp(obj.getApellido(), apellidoBuscado) == 0)
            {
                vecSocios.push_back(obj);
            }
        }
    }

    int encontrados = vecSocios.size();
    system("cls");
    if (encontrados == 0)
    {
        cout << "No hay socios registrados con el apellido " << apellidoBuscado << "." << endl;
        system("pause");
        return;
    }

    cout << "=======================================" << endl;
    cout << "      SOCIOS CON APELLIDO " << apellidoBuscado << endl;
    cout << "=======================================" << endl;
    for (int i = 0; i < encontrados; i++)
    {
        vecSocios[i].mostrar();
        cout << "=======================================" << endl;
    }
    system("pause");
}

void comprasPorSocio() {
    ArchivoSocios archS;
    ArchivoCompras arcC;
    Socio socio;
    int id;

    int cantSocios = archS.contarRegistros();
    if (cantSocios <= 0)
    {
        cout << "No hay socios registrados." << endl;
        system("pause");
        return;
    }

    while (true)
    {
        system("cls");
        cout << "================================================" << endl;
        cout << "           CONSULTAR COMPRAS POR SOCIO          " << endl;
        cout << "================================================" << endl;
        cout << "ID del socio a consultar (o 0 para volver): ";
        cin >> id;

        if (id == 0) return;

        int pos = archS.buscarRegistro(id);
        if (pos != -1)
        {
            socio = archS.leerRegistro(pos);
            if (socio.getEstado())
            {
                break;
            }
        }

        cout << endl << "No existe un socio activo con ese ID. Intente de nuevo." << endl;
        system("pause");
    }

    system("cls");
    cout << "================================================" << endl;
    cout << " SOCIO: " << socio.getNombre() << " " << socio.getApellido() << " (ID: " << id << ")" << endl;
    cout << "================================================" << endl;

    int cantCompras = arcC.contarRegistros();
    if (cantCompras <= 0)
    {
        cout << "No hay compras registradas en el sistema." << endl;
        system("pause");
        return;
    }

    bool encontro = false;
    for (int i = 0; i < cantCompras; i++)
    {
        Compra c = arcC.leerRegistro(i);
        if (c.getEstado() == true && c.getIdSocio() == id)
        {
            c.mostrar();

            ArchivoDetalleEntradas archDetalle;
            int cantDetalles = archDetalle.contarRegistros();
            for (int d = 0; d < cantDetalles; d++)
            {
                DetalleEntrada det = archDetalle.leerRegistro(d);
                if (det.getIdCompra() == c.getIdCompra()){
                    det.mostrar();
                }
            }
            cout << "================================================" << endl;
            encontro = true;
        }
    }

    if (encontro == false)
    {
        cout << "El socio no registra compras activas en el sistema." << endl;
    }
    system("pause");
}
