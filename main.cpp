#include <iostream>
#include "clsArchivoPeliculas.h"
#include "clsPelicula.h"
#include "funciones.h"
#include <clocale>
using namespace std;
void menuPeliculas();
void menuDescuentos();


int main(){
setlocale(LC_ALL, "Spanish");
       while (true){
       int opcion;
        cout << endl;
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
        cout << endl;
       cout <<" 1. PELICULAS" <<endl;
       cout <<" 2. DESCUENTOS" <<endl;
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
       cout <<"                   PELICULAS" <<endl;
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
       cout <<endl;
       cout <<"  1. CARGAR PELICULAS" <<endl;
       cout <<"  2. LISTAR PELICULAS" <<endl;
       cout <<"  3. MODIFICAR" <<endl;
       cout <<"  4. DAR DE BAJA" <<endl;
       cout <<"  0. VOLVER AL MENU PRINCIPAL" <<endl;
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
       cout <<"  1. CARGAR DESCUENTOS" <<endl;
       cout <<"  2. LISTAR DESCUENTOS" <<endl;
       cout <<"  3. MODIFICAR" <<endl;
       cout <<"  4. DAR DE BAJA" <<endl;
       cout <<"  0. VOLVER AL MENU PRINCIPAL" <<endl;
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



