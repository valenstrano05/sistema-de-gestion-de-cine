#ifndef CLSARCHIVOSALAS_H_INCLUDED
#define CLSARCHIVOSALAS_H_INCLUDED

#include "clsSala.h"

class ArchivoSalas
{
private:
    char _nombreArchivo[30];
public:
    ArchivoSalas(const char * nombre="Salas.dat");
    bool grabarRegistro(Sala reg);
    Sala leerRegistro(int pos);
    int contarRegistros();
    int buscarRegistro(int idSala);
    int buscarRegistroInactivo(int idSala);
    bool modificarRegistro(Sala reg, int pos);
};

#endif // CLSARCHIVOSALAS_H_INCLUDED
