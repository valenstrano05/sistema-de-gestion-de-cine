#ifndef CLSARCHIVOSOCIOS_H_INCLUDED
#define CLSARCHIVOSOCIOS_H_INCLUDED

#include "clsSocio.h"

class ArchivoSocios
{
private:
    char _nombreArchivo[30];
public:
    ArchivoSocios(const char * nombre="socios.dat");
    bool grabarRegistro(Socio reg);
    Socio leerRegistro(int pos);
    int contarRegistros();
    int buscarRegistro(int idSocio);
    int buscarRegistroInactivo(int idSocio);
    bool modificarRegistro(Socio reg, int pos);
};

#endif // CLSARCHIVOSOCIOS_H_INCLUDED
