#include <cstdio>
#include <cstring>
#include "clsArchivoSocios.h"

using namespace std;

ArchivoSocios::ArchivoSocios(const char * nombre)
{
    strcpy(_nombreArchivo, nombre);
}

bool ArchivoSocios::grabarRegistro(Socio reg)
{
    FILE *p = fopen(_nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Socio), 1, p) == 1;
    fclose(p);
    return ok;
}

Socio ArchivoSocios::leerRegistro(int pos)
{
    Socio reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr)
    {
        return reg;
    }
    fseek(p, pos * sizeof(Socio), SEEK_SET);
    fread(&reg, sizeof(Socio), 1, p);
    fclose(p);
    return reg;
}

int ArchivoSocios::contarRegistros()
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cantidad = ftell(p) / sizeof(Socio);
    fclose(p);
    return cantidad;
}

int ArchivoSocios::buscarRegistro(int idSocio)
{
    int cantidad = contarRegistros();
    for(int i = 0; i < cantidad; i++)
    {
        Socio reg = leerRegistro(i);
        if(reg.getIdSocio() == idSocio && reg.getEstado())
        {
            return i;
        }
    }
    return -1;
}

bool ArchivoSocios::modificarRegistro(Socio reg, int pos)
{
    FILE *p = fopen(_nombreArchivo, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof(Socio), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Socio), 1, p) == 1;
    fclose(p);
    return ok;
}
