#ifndef ARCHIVOPELICULA_H_INCLUDED
#define ARCHIVOPELICULA_H_INCLUDED
#include "clsPelicula.h"


class ArchivoPeliculas
{
private:
    char nombreArchivo[30];
public:
    ArchivoPeliculas (const char* nombre = "Peliculas.dat");
    bool guardarRegistro (Pelicula);
    int contarRegistros();
    Pelicula leerRegistro (int posicion);
    int buscarPorID (int);
    int buscarPorIDInactivo (int);
    bool modificarRegistro (Pelicula, int);
};

#endif // ARCHIVOPELICULA_H_INCLUDED
