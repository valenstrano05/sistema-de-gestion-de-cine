#include <cstdio>
#include <cstring>
#include "clsArchivoButacas.h"

ArchivoButacas::ArchivoButacas(const char * nombre){
    strcpy(_nombreArchivo, nombre);
}

bool ArchivoButacas::grabarRegistro(Butaca reg){
    FILE *p = fopen(_nombreArchivo, "ab");
    if(p == nullptr){
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Butaca), 1, p) == 1;
    fclose(p);
    return ok;
}

Butaca ArchivoButacas::leerRegistro(int pos){
    Butaca reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr){
        return reg;
    }
    fseek(p, pos * sizeof(Butaca), SEEK_SET);
    fread(&reg, sizeof(Butaca), 1, p);
    fclose(p);
    return reg;
}

int ArchivoButacas::contarRegistros(){
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cantidad = ftell(p) / sizeof(Butaca);
    fclose(p);
    return cantidad;
}

int ArchivoButacas::buscarRegistro(int idButaca){
    int cantidad = contarRegistros();
    for(int i = 0; i < cantidad; i++){
        Butaca reg = leerRegistro(i);
        if(reg.getIdButaca() == idButaca && reg.getEstado()){
            return i;
        }
    }
    return -1;
}

bool ArchivoButacas::modificarRegistro(Butaca reg, int pos){
    FILE *p = fopen(_nombreArchivo, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof(Butaca), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Butaca), 1, p) == 1;
    fclose(p);
    return ok;
}

// Crea 'capacidad' butacas para la sala: F01B01, F01B02, ... (10 por fila)
bool ArchivoButacas::generarButacas(int idSala, int capacidad){
    const int ASIENTOS_POR_FILA = 10;
    int primerId = contarRegistros() + 1;

    FILE *p = fopen(_nombreArchivo, "ab");
    if(p == nullptr){
        return false;
    }
    bool ok = true;
    for(int i = 0; i < capacidad; i++){
        int fila = (i / ASIENTOS_POR_FILA + 1) % 100;
        int num  = (i % ASIENTOS_POR_FILA + 1) % 100;
        char codigo[7];
        snprintf(codigo, sizeof(codigo), "F%02dB%02d", fila, num);
        Butaca reg(primerId + i, idSala, codigo, true);
        if(fwrite(&reg, sizeof(Butaca), 1, p) != 1){
            ok = false;
            break;
        }
    }
    fclose(p);
    return ok;
}
