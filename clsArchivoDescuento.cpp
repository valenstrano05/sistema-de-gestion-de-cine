#include <iostream>
#include <cstring>
#include "clsArchivoDescuento.h"
using namespace std;


ArchivoDescuento::ArchivoDescuento(const char* nombre)
{
    strcpy(nombreArchivo, nombre);
}


bool ArchivoDescuento::guardar(Descuento descuento)
{
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == NULL){ return false; }

    bool escribio = fwrite(&descuento, sizeof(Descuento), 1, p);

    fclose(p);

    return escribio;
}


int ArchivoDescuento::cantidadRegistros()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) { return 0; }

    fseek (p, 0, SEEK_END);
    int tam = ftell(p);

    return tam / sizeof(Descuento);
}


Descuento ArchivoDescuento::leer(int posicion)
{
    Descuento obj;

    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) { return obj; }

    fseek(p, posicion*sizeof(Descuento), SEEK_SET);
    fread(&obj, sizeof(Descuento), 1, p);

    fclose(p);

    return obj;

}


int ArchivoDescuento::buscarPorID(int id)
{
    int cant = cantidadRegistros();
    for (int i=0; i<cant; i++){
        Descuento obj = leer(i);
        if (obj.getID()==id && obj.getEstado()){
            return i;
        }
    }
    return -1;
}



bool ArchivoDescuento::modificar(Descuento obj, int posicion)
{
    FILE* p = fopen (nombreArchivo, "rb+");
    if (p == nullptr) return false;

    fseek(p, posicion* sizeof(Descuento), SEEK_SET);
    bool escribio = fwrite(&obj, sizeof(Descuento), 1, p);
    fclose(p);

    return escribio;
}


