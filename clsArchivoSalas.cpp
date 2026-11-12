#include <cstdio>
#include <cstring>
#include "clsArchivoSalas.h"

ArchivoSalas::ArchivoSalas(const char * nombre)
{
    strcpy(_nombreArchivo, nombre);
}

bool ArchivoSalas::grabarRegistro(Sala reg)
{
    FILE *p = fopen(_nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Sala), 1, p) == 1;
    fclose(p);
    return ok;
}

Sala ArchivoSalas::leerRegistro(int pos)
{
    Sala reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr)
    {
        return reg;
    }
    fseek(p, pos * sizeof(Sala), SEEK_SET);
    fread(&reg, sizeof(Sala), 1, p);
    fclose(p);
    return reg;
}

int ArchivoSalas::contarRegistros()
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cantidad = ftell(p) / sizeof(Sala);
    fclose(p);
    return cantidad;
}

int ArchivoSalas::buscarRegistro(int idSala)
{
    int cantidad = contarRegistros();
    for(int i = 0; i < cantidad; i++)
    {
        Sala reg = leerRegistro(i);
        if(reg.getIdSala() == idSala && reg.getEstado())
        {
            return i;
        }
    }
    return -1;
}

int ArchivoSalas::buscarRegistroInactivo(int idSala)
{
    int cantidad = contarRegistros();
    for(int i = 0; i < cantidad; i++)
    {
        Sala reg = leerRegistro(i);
        if(reg.getIdSala() == idSala)
        {
            return i;
        }
    }
    return -1;
}

bool ArchivoSalas::modificarRegistro(Sala reg, int pos)
{
    FILE *p = fopen(_nombreArchivo, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof(Sala), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Sala), 1, p) == 1;
    fclose(p);
    return ok;
}
