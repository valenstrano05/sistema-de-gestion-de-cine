#ifndef CLSARCHIVODETALLEENTRADAS_H
#define CLSARCHIVODETALLEENTRADAS_H
#include "clsDetalleEntrada.h"
#include <cstring>

class ArchivoDetalleEntradas {
private:
    char nombre[30];

public:
    ArchivoDetalleEntradas(const char* n = "DetalleEntradas.dat");
    bool grabarRegistro(DetalleEntrada obj);
    int contarRegistros();
    void listarRegistros();
    DetalleEntrada leerRegistro(int pos);
    int buscarRegistro(int idDetalleEntrada);
    bool modificarRegistro(DetalleEntrada obj, int pos);
};
#endif // CLSARCHIVODETALLEENTRADAS_H
