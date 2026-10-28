#ifndef ARCHIVOPELICULA_H_INCLUDED
#define ARCHIVOPELICULA_H_INCLUDED
#include "clsPelicula.h"


class ArchivoPelicula{
private:
    char nombreArchivo[30];
public:
    ArchivoPelicula (const char* nombre = "peliculas.dat");
    bool guardar (Pelicula);
    int cantidadRegistros();
    Pelicula leer (int posicion);
    int buscarPorID (int);
    bool modificar (Pelicula, int);
};

#endif // ARCHIVOPELICULA_H_INCLUDED
