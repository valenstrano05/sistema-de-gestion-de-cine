#include <iostream>
#include <cstring>
#include "clsArchivoFormato.h"

using namespace std;
#include <cerrno>


ArchivoFormato::ArchivoFormato(const char* nombre)
{
    strcpy(_nombreArchivo, nombre);
}


bool ArchivoFormato::guardarRegistro(Formato formato)
{
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == NULL) return false;

    bool escribio = fwrite(&formato, sizeof(Formato), 1, p);
    fclose(p);
    return escribio;
}

int ArchivoFormato::contarRegistros()
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);

    return tam / sizeof(Formato);
}

Formato ArchivoFormato::leerRegistro(int posicion)
{
    Formato obj;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL) return obj;

    fseek(p, posicion * sizeof(Formato), SEEK_SET);
    fread(&obj, sizeof (Formato), 1, p);
    fclose(p);

    return obj;
}


int ArchivoFormato::buscarPorID(int id)
{
    int cant = contarRegistros();
    for (int i=0; i<cant; i++)
    {
        Formato obj = leerRegistro(i);
        if (obj.getID()==id && obj.getEstado())
        {
            return i;
        }
    }
    return -1;
}

int ArchivoFormato::buscarPorIDInactivo(int id)
{
    int cant = contarRegistros();
    for (int i=0; i<cant; i++)
    {
        Formato obj = leerRegistro(i);
        if (obj.getID()==id)
        {
            return i;
        }
    }
    return -1;
}

bool ArchivoFormato::modificarRegistro(Formato obj, int posicion)
{
    FILE* p = fopen (_nombreArchivo, "rb+");
    if (p == nullptr) return false;

    fseek(p, posicion* sizeof(Formato), SEEK_SET);
    bool escribio = fwrite(&obj, sizeof(Formato), 1, p);
    fclose(p);

    return escribio;
}
