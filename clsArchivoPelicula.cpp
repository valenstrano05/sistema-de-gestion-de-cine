#include <iostream>
#include <cstring>
#include "clsArchivoPeliculas.h"
using namespace std;


ArchivoPeliculas::ArchivoPeliculas(const char* nombre)
{
    strcpy(nombreArchivo, nombre);
}

bool ArchivoPeliculas::guardarRegistro(Pelicula pelicula)
{
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == NULL) return false;

    bool escribio = fwrite(&pelicula, sizeof(Pelicula), 1, p);
    fclose(p);
    return escribio;
}

int ArchivoPeliculas::contarRegistros()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);

    return tam / sizeof(Pelicula);
}

Pelicula ArchivoPeliculas::leerRegistro(int posicion)
{
    Pelicula obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return obj;

    fseek(p, posicion * sizeof(Pelicula), SEEK_SET);
    fread(&obj, sizeof (Pelicula), 1, p);
    fclose(p);

    return obj;
}


int ArchivoPeliculas::buscarPorID(int id)
{
    int cant = contarRegistros();
    for (int i=0; i<cant; i++)
    {
        Pelicula obj = leerRegistro(i);
        if (obj.getID()==id && obj.getEstado())
        {
            return i;
        }
    }
    return -1;
}

int ArchivoPeliculas::buscarPorIDInactivo(int id)
{
    int cant = contarRegistros();
    for (int i=0; i<cant; i++)
    {
        Pelicula obj = leerRegistro(i);
        if (obj.getID()==id)
        {
            return i;
        }
    }
    return -1;
}

bool ArchivoPeliculas::modificarRegistro(Pelicula obj, int posicion)
{
    FILE* p = fopen (nombreArchivo, "rb+");
    if (p == nullptr) return false;

    fseek(p, posicion* sizeof(Pelicula), SEEK_SET);
    bool escribio = fwrite(&obj, sizeof(Pelicula), 1, p);
    fclose(p);

    return escribio;
}
