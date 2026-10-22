#ifndef CLSARCHIVOCOMPRAS_H
#define CLSARCHIVOCOMPRAS_H
#include "clsCompra.h"
#include <cstring>

class ArchivoCompras
{
private:
    char nombre[30];

public:
    ArchivoCompras(const char* n = "Compras.dat");
    bool grabarRegistro(Compra obj);
    int contarRegistros();
    void listarRegistros();
    Compra leerRegistro(int pos);
    int buscarRegistro(int ID);
    bool modificarRegistro(Compra obj, int pos);
};

#endif // CLSARCHIVOCOMPRAS_H
