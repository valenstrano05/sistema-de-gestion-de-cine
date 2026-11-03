#ifndef CLSARCHIVOBUTACAS_H_INCLUDED
#define CLSARCHIVOBUTACAS_H_INCLUDED

#include "clsButaca.h"

class ArchivoButacas{
    private:
        char _nombreArchivo[30];
    public:
        ArchivoButacas(const char * nombre="butacas.dat");
        bool grabarRegistro(Butaca reg);
        Butaca leerRegistro(int pos);
        int contarRegistros();
        int buscarRegistro(int idButaca);
        bool modificarRegistro(Butaca reg, int pos);
        bool generarButacas(int idSala, int capacidad);
};

#endif // CLSARCHIVOBUTACAS_H_INCLUDED
