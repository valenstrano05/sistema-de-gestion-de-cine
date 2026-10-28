#include <iostream>
#include <cstring>
#include "clsArchivoPeliculas.h"
using namespace std;


ArchivoPelicula::ArchivoPelicula(const char* nombre)
{
    strcpy(nombreArchivo, nombre);
}


bool ArchivoPelicula::guardar(Pelicula pelicula) {
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == NULL) return false;

    bool escribio = fwrite(&pelicula, sizeof(Pelicula), 1, p);
    fclose(p);
    return escribio;
}

int ArchivoPelicula::cantidadRegistros()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);

    return tam / sizeof(Pelicula);
}


Pelicula ArchivoPelicula::leer(int posicion)
{
    Pelicula obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return obj;

    fseek(p, posicion * sizeof(Pelicula), SEEK_SET);
    fread(&obj, sizeof (Pelicula), 1, p);
    fclose(p);

    return obj;
}


int ArchivoPelicula::buscarPorID(int id)
{
    int cant = cantidadRegistros();
    for (int i=0; i<cant; i++){
        Pelicula obj = leer(i);
        if (obj.getID()==id && obj.getEstado()){
            return i;
        }
    }
    return -1;
}


bool ArchivoPelicula::modificar(Pelicula obj, int posicion)
{
    FILE* p = fopen (nombreArchivo, "rb+");
    if (p == nullptr) return false;

    fseek(p, posicion* sizeof(Pelicula), SEEK_SET);
    bool escribio = fwrite(&obj, sizeof(Pelicula), 1, p);
    fclose(p);

    return escribio;
}










