#include <windows.h>
#include "clsArchivoPelicula.h"
#include "clsPelicula.h"
#include "funciones.h"
using namespace std;


void menuPeliculas();
void menuDescuentos();


int main(){
       SetConsoleOutputCP(CP_UTF8);
       SetConsoleCP(CP_UTF8);
       while (true){
       int opcion;
       cout << "\n";
        cout << "  ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐" << endl;
        cout << "  ⭐                                                             ⭐" << endl;
        cout << "  ⭐            ██████╗ ██╗███╗   ██╗███████╗                    ⭐" << endl;
        cout << "  ⭐           ██╔════╝ ██║████╗  ██║██╔════╝                    ⭐" << endl;
        cout << "  ⭐           ██║      ██║██╔██╗ ██║█████╗                      ⭐" << endl;
        cout << "  ⭐           ██║      ██║██║╚██╗██║██╔══╝                      ⭐" << endl;
        cout << "  ⭐            ╚██████╗ ██║██║ ╚████║███████╗                   ⭐" << endl;
        cout << "  ⭐             ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝                   ⭐" << endl;
        cout << "  ⭐                                                             ⭐" << endl;
        cout << "  ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐" << endl;
        cout << "\n";
       cout <<"\t 1. PELICULAS" <<endl;
       cout <<"\t 2. DESCUENTOS" <<endl;
       cout <<endl;
       cout <<"------------------------------------------------" <<endl;
       cout <<"Ingrese una opción: "; cin >>opcion;
       cout <<"------------------------------------------------" <<endl;
       system("cls");

       switch(opcion){
       case 1:
           menuPeliculas();
        break;
       case 2:
           menuDescuentos();
        break;
       default:
        break;
       }
       }

return 0;}



void menuPeliculas(){
    while (true){
       int opcion;
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
       cout <<"\n                   PELICULAS" <<endl;
       cout <<"\n||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
       cout <<endl;
       cout <<"\t 1. CARGAR PELICULAS" <<endl;
       cout <<"\t 2. LISTAR PELICULAS" <<endl;
       cout <<"\t 3. MODIFICAR" <<endl;
       cout <<"\t 4. DAR DE BAJA" <<endl;
       cout <<"\t 0. VOLVER AL MENU PRINCIPAL" <<endl;
       cout <<endl;
       cout <<"------------------------------------------------" <<endl;
       cout <<"Ingrese una opción: "; cin >>opcion;
       cout <<"------------------------------------------------" <<endl;
       system("cls");

       switch(opcion){
       case 1:
           cargarPelicula();
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
           confirmacionSalida();
        break;
       default:
        break;
       }
    }
}



void menuDescuentos(){
    while (true){
       int opcion;
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
       cout <<"                   DESCUENTOS" <<endl;
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
       cout <<endl;
       cout <<"\t 1. CARGAR DESCUENTOS" <<endl;
       cout <<"\t 2. LISTAR DESCUENTOS" <<endl;
       cout <<"\t 3. MODIFICAR" <<endl;
       cout <<"\t 4. DAR DE BAJA" <<endl;
       cout <<"\t 0. VOLVER AL MENU PRINCIPAL" <<endl;
       cout <<endl;
       cout <<"------------------------------------------------" <<endl;
       cout <<"Ingrese una opción: "; cin >>opcion;
       cout <<"------------------------------------------------" <<endl;

       switch(opcion){
       case 1:
        break;
       case 2:
        break;
       case 3:
        break;
       case 4:
        break;
       case 0:
           confirmacionSalida();
        break;
       default:
        break;
       }
    }
}



