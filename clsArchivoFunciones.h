#ifndef ARCHIVOFUNCIONES_H
#define ARCHIVOFUNCIONES_H
#include "clsFuncion.h"
#include <cstring>

class ArchivoFunciones {
private:
    char nombre[30];

public:
    ArchivoFunciones(const char* n = "Funciones.dat");
    bool grabarRegistro(Funcion obj);
    int contarRegistros();
    void listarRegistros();
    Funcion leerRegistro(int pos);
    int buscarRegistro(int idFuncion);
    bool modificarRegistro(Funcion obj, int pos);
};

#endif // ARCHIVOFUNCIONES_H
