#include <iostream>
#include "funciones.h"
#include "clsArchivoDescuento.h"
#include "clsArchivoPeliculas.h"
using namespace std;



// ----------------------------------

void cargarCadena (const char* mensaje, char* cadena, int tam){
        cout << mensaje;
        cin.getline(cadena, tam);
        while (cadena[0]=='\0'){
            cout <<"Campo obligatorio. "<<mensaje;
            cin.getline(cadena, tam);
        }
}
//-------------------------------------------

void cargarPelicula(){
    ArchivoPelicula arch;
    Pelicula obj;
       obj.cargar();
       if (arch.guardar(obj)){
            cout<<"\n\t Registro exitoso!"<<endl;
        }else {
            cout <<"\nError al guardar el archivo"<<endl;
        }
}


void listarPeliculas(){
    ArchivoPelicula arch;
    if (arch.cantidadRegistros()==0){
        cout <<"No hay peliculas registradas."<<endl;
        return;
    }
    for (int i = 0; i < arch.cantidadRegistros(); i++) {
        Pelicula obj = arch.leer(i);
        obj.mostrar();
        cout << "-----------------------------------" << endl;
    }
}

void modificarPelicula(){
    int idBuscado;
    cout <<"Ingrese ID de pelicula a modificar: "; cin>>idBuscado;

    ArchivoPelicula arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1){
        cout <<"No existe registro activo con el ID " <<idBuscado <<"." <<endl;
        return;
    }

    Pelicula obj = arch.leer(pos);
    obj.modificar();

    if (arch.modificar(obj, pos)) {
        cout << "Registro modificado con exito." << endl;
    }else {
        cout << "Error al intentar guardar los cambios." << endl;
    }
}


void darBajaPelicula(){
    int idBuscado;
    cout <<"Ingrese el ID a dar de baja: "; cin >>idBuscado;

    ArchivoPelicula arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1){
        cout <<"No se encontro un registro con el ID " <<idBuscado <<"." <<endl;
    }
    Pelicula obj = arch.leer(pos);
    obj.setEstado(false);

    if (arch.modificar(obj, pos)) {
        cout << "Registro dado de baja con exito." << endl;
    } else {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
}


void confirmacionSalida(){
    char opcion;
    cout <<"Esta seguro/a de que desea salir? (S/N):"; cin >>opcion;

    if (opcion == 's' || opcion == 'S'){
        return;
    }
}
