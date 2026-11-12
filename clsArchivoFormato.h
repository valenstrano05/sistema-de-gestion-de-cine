#ifndef CLSARCHIVOFORMATO_H_INCLUDED
#define CLSARCHIVOFORMATO_H_INCLUDED
#include "clsFormato.h"

class ArchivoFormato {
private:
    char _nombreArchivo[30];
public:
    ArchivoFormato(const char* nombre = "formatos.dat");
    bool guardarRegistro(Formato);
    int contarRegistros();
    Formato leerRegistro(int );
    int buscarPorID(int);
    int buscarPorIDInactivo (int);
    bool modificarRegistro(Formato, int);
};


#endif // CLSARCHIVOFORMATO_H_INCLUDED
