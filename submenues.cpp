#include <iostream>
#include <windows.h>
#include "clsArchivoPeliculas.h"
#include "clsPelicula.h"
#include "funciones.h"
#include "submenues.h"
#include "listados.h"
#include "consultas.h"
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
        cout <<    "     4. FORMATO"<<endl;
        cout <<    "     5. SALAS"<<endl;
        cout <<    "     6. BUTACAS"<<endl;
        cout <<    "     7. FUNCIONES"<<endl;
        cout <<    "     8. COMPRAS"<<endl;
        cout <<    "     9. INFORMES"<<endl;
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
            menuFormato();
            break;
        case 5:
            menuSalas();
            break;
        case 6:
            menuButacas();
            break;
        case 7:
            menuFunciones();
            break;
        case 8:
            menuCompras();
            break;
        case 9:
            menuInformes();
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
        cout <<    "     5. CONSULTAR" <<endl;
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
            listadosPeliculas();
            break;
        case 3:
            modificarPelicula();
            break;
        case 4:
            darBajaPelicula();
            break;
        case 5:
            consultarPeliculas();
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
        system("cls");
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
            listadosSocios();
            break;
        case 3:
            modificarSocio();
            break;
        case 4:
            darBajaSocio();
            break;
        case 0:
            if (confirmacionSalida()){
            return;
            }
        }
    }
}

void menuFormato()
{
    while (true){
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|                  FORMATOS                     |"<< endl;
        cout << "|                                               |" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << endl;
        cout << "     1. CARGAR FORMATOS" << endl;
        cout << "     2. LISTAR FORMATOS" << endl;
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
            cargarFormato();
            break;
        case 2:
            listarFormatos();
            break;
        case 3:
            modificarFormato();
            break;
        case 4:
            darBajaFormato();
            break;
        case 0:
            if (confirmacionSalida()){
            return;
            }
        }
    }
}

void menuSalas(){
    while (true){
            system("cls");
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
            if (confirmacionSalida()){
            return;
            }
        }
    }
}

void menuButacas(){
    while (true){
    system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|                    BUTACAS                    |"<< endl;
        cout << "|                                               |" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << endl;
        cout << "     1. LISTAR BUTACAS DISPONIBLES DE UNA SALA" << endl;
        cout << "     2. DAR DE BAJA" << endl;
        cout << "     0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");

        switch (opcion){
        case 1:
            listarButacas();
            break;
        case 2:
            darBajaButaca();
            break;
        case 0:
            confirmacionSalida();
            return;
        }
    }
}
void menuFunciones()
{
    system("cls");
    while (true)
    {
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|                    FUNCIONES                  |" << endl;
        cout << "|                                               |" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. CARGAR FUNCION" << endl;
        cout << "     2. LISTAR FUNCIONES" << endl;
        cout << "     3. MODIFICAR" << endl;
        cout << "     4. DAR DE BAJA" << endl;
        cout << "     5. CONSULTAR" <<endl;
        cout << "     0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");

        switch (opcion)
        {
        case 1:
            cargarFuncion();
            break;
        case 2:
            listadosFunciones();
            break;
        case 3:
            modificarFuncion();
            break;
        case 4:
            darBajaFuncion();
            break;
        case 5:
            consultarFunciones();
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

void menuCompras()
{
    system("cls");
    while (true)
    {
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|                 COMPRAS / VENTAS              |" << endl;
        cout << "|                                               |" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. NUEVA COMPRA (REGISTRAR VENTA)" << endl;
        cout << "     2. LISTAR COMPRAS" << endl;
        cout << "     3. CONSULTAR HISTORIAL DE COMPRAS POR SOCIO" << endl;
        cout << "     4. DAR DE BAJA"<<endl;
        cout << "     0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");

        switch (opcion)
        {
        case 1:
            registrarCompra();
            break;
        case 2:
            listadosCompras();
            break;
        case 3:
            consultarComprasPorSocio();
            break;
        case 4:
            darBajaCompra();
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

void menuInformes()
{
    system("cls");
    while (true)
    {
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                               |" << endl;
        cout << "|               INFORMES Y ESTADISTICAS         |" << endl;
        cout << "|                                               |" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. RANKING DE RECAUDACION POR PELICULA" << endl;
        cout << "     2. PORCENTAJE DE OCUPACION POR FUNCION" << endl;
        cout << "     3. ENTRADAS VENDIDAS POR TIPO DE FORMATO" << endl;
        cout << "     4. RANKING DE SOCIOS MAS FRECUENTES" << endl;
        cout << "     5. IMPACTO FINANCIERO DE PROMOCIONES Y DESCUENTOS" << endl;
        cout << "     6. TICKETS QUE SUPERAN EL GASTO PROMEDIO" << endl;
        cout << "     0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        int opcion = pedirEntero("Ingrese una opcion: ");
        cout << "------------------------------------------------" << endl;
        system("cls");

        switch (opcion)
        {
        case 1:
            informeRankingRecaudacionPeliculas();
            break;
        case 2:
            informeOcupacionPorFuncion();
            break;
        case 3:
            informeEntradasPorFormato();
            break;
        case 4:
            informeSociosMasFrecuentes();
            break;
        case 5:
            informeImpactoDescuentos();
            break;
        case 6:
            informeTicketsSuperanPromedio();
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
