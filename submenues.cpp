#include <iostream>
#include <windows.h>
#include "clsArchivoPeliculas.h"
#include "clsPelicula.h"
#include "funciones.h"
#include "submenues.h"

using namespace std;

int menuPrincipal()
{
    while (true)
    {
        system("cls");
        int opcion;
        cout << endl;
        cout << "  * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "  *                                         *" << endl;
        cout << "  *     ██████╗  ██╗███╗   ██╗███████╗      *" << endl;
        cout << "  *     ██╔════╝ ██║████╗  ██║██╔════╝      *" << endl;
        cout << "  *     ██║      ██║██╔██╗ ██║█████╗        *" << endl;
        cout << "  *     ██║      ██║██║╚██╗██║██╔══╝        *" << endl;
        cout << "  *     ╚██████╗ ██║██║ ╚████║███████╗      *" << endl;
        cout << "  *      ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝      *" << endl;
        cout << "  *                                         *" << endl;
        cout << "  * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << endl;
        cout <<    "     1. PELICULAS" <<endl;
        cout <<    "     2. DESCUENTOS" <<endl;
        cout <<    "     3. SOCIOS"<<endl;
        cout <<    "     4. SALAS"<<endl;
        cout <<    "     5. BUTACAS"<<endl;
        cout <<    "     0. SALIR"<<endl;
        cout <<endl;
        cout <<"------------------------------------------------" <<endl;
        cout <<"Ingrese una opción: ";
        cin >>opcion;
        cout <<"------------------------------------------------" <<endl;
        system("cls");

        switch(opcion)
        {
        case 1:
            menuPeliculas();
            break;
        case 2:
            menuDescuentos();
            break;
        case 3:
            menuSocios();
            break;
        case 4:
            menuSalas();
            break;
        case 5:
            menuButacas();
            break;
        case 0:
            system("cls");
            cout<<"Saliendo del programa..."<<endl;
            return 0;
            break;
        }
    }
    return 0;
}

void menuPeliculas()
{
    while (true)
    {
        system("cls");
        int opcion;
        cout <<"||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
        cout <<"|                                              |" << endl;
        cout <<"|                   PELICULAS                  |" <<endl;
        cout <<"|                                              |" << endl;
        cout <<"||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
        cout <<endl;
        cout <<    "     1. CARGAR PELICULAS" <<endl;
        cout <<    "     2. LISTAR PELICULAS" <<endl;
        cout <<    "     3. MODIFICAR" <<endl;
        cout <<    "     4. DAR DE BAJA" <<endl;
        cout <<    "     0. VOLVER AL MENU PRINCIPAL" <<endl;
        cout <<endl;
        cout <<"------------------------------------------------" <<endl;
        cout <<"Ingrese una opción: ";
        cin >>opcion;
        cout <<"------------------------------------------------" <<endl;
        system("cls");

        switch(opcion)
        {
        case 1:
            cargarPelicula();
            system("pause");
            break;
        case 2:
            listarPeliculas();
            break;
        case 3:
            modificarPelicula();
            break;
        case 4:
            darBajaPelicula();
            break;
        case 0:
            if(confirmacionSalida())
            {
                return;
            }
            break;
        }
    }
}

void menuDescuentos()
{
    while (true)
    {
        system("cls");
        int opcion;
        cout <<"||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
        cout <<"|                                              |" << endl;
        cout <<"|                   DESCUENTOS                 |" <<endl;
        cout <<"|                                              |" << endl;
        cout <<"||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
        cout <<endl;
        cout <<    "     1. CARGAR DESCUENTOS" <<endl;
        cout <<    "     2. LISTAR DESCUENTOS" <<endl;
        cout <<    "     3. MODIFICAR" <<endl;
        cout <<    "     4. DAR DE BAJA" <<endl;
        cout <<    "     0. VOLVER AL MENU PRINCIPAL" <<endl;
        cout <<endl;
        cout <<"------------------------------------------------" <<endl;
        cout <<"Ingrese una opción: ";
        cin >>opcion;
        cout <<"------------------------------------------------" <<endl;
        system("cls");
        switch(opcion)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            if(confirmacionSalida())
            {
                return;
            }
            break;
        }
    }
}

void menuSocios(){
    while (true){
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|                   SOCIOS                      |"<< endl;
        cout << "|                                               |" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. CARGAR SOCIO" << endl;
        cout << "     2. LISTAR SOCIOS" << endl;
        cout << "     3. MODIFICAR" << endl;
        cout << "     4. DAR DE BAJA" << endl;
        cout << "     0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");

        switch (opcion){
        case 1:
            cargarSocio();
            break;
        case 2:
            listarSocios();
            break;
        case 3:
            modificarSocio();
            break;
        case 4:
            darBajaSocio();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

void menuSalas(){
    while (true){
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|                    SALAS                      |"<< endl;
        cout << "|                                               |" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << endl;
        cout << "     1. CARGAR SALA" << endl;
        cout << "     2. LISTAR SALAS" << endl;
        cout << "     3. MODIFICAR" << endl;
        cout << "     4. DAR DE BAJA" << endl;
        cout << "     0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");

        switch (opcion){
        case 1:
            cargarSala();
            break;
        case 2:
            listarSalas();
            break;
        case 3:
            modificarSala();
            break;
        case 4:
            darBajaSala();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

void menuButacas(){
    while (true){
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|                    BUTACAS                    |"<< endl;
        cout << "|                                               |" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << endl;
        cout << "     1. CARGAR BUTACA" << endl;
        cout << "     2. LISTAR BUTACAS DE UNA SALA" << endl;
        cout << "     3. DAR DE BAJA" << endl;
        cout << "     0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");

        switch (opcion){
        case 1:
            cargarButaca();
            break;
        case 2:
            listarButacas();
            break;
        case 3:
            darBajaButaca();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}
