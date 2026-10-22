#include <iostream>
#include "clsArchivoDetalleEntradas.h"
using namespace std;

ArchivoDetalleEntradas::ArchivoDetalleEntradas(const char* n) {
    strcpy(nombre, n);
}
bool ArchivoDetalleEntradas::grabarRegistro(DetalleEntrada obj) {
    FILE* p = fopen(nombre, "ab");
    if (p == nullptr) {
        return false;
    }
    bool escribio = (fwrite(&obj, sizeof(DetalleEntrada), 1, p) == 1);
    fclose(p);
    return escribio;
}

int ArchivoDetalleEntradas::contarRegistros() {
    FILE* p = fopen(nombre, "rb");
    if (p == nullptr) {
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(DetalleEntrada);
}

void ArchivoDetalleEntradas::listarRegistros() {
    int cantReg = contarRegistros();
    if (cantReg <= 0) {
        cout << "No hay detalles de entradas registrados o el archivo esta vacio."<<endl;
        return;
    }

    cout << "======================================="<<endl;
    cout << "    LISTADO DE DETALLES DE ENTRADAS    "<<endl;
    cout << "======================================="<<endl;

    for (int i = 0; i < cantReg; i++) {
        DetalleEntrada obj = leerRegistro(i);
        obj.mostrar();
        cout << "======================================="<<endl;
    }
}

DetalleEntrada ArchivoDetalleEntradas::leerRegistro(int pos) {
    FILE* p = fopen(nombre, "rb");
    DetalleEntrada obj;
    if (p == nullptr) {
        obj.setIdDetalleEntrada(-1);
        return obj;
    }
    fseek(p, pos * sizeof(DetalleEntrada), SEEK_SET);
    fread(&obj, sizeof(DetalleEntrada), 1, p);
    fclose(p);
    return obj;
}

int ArchivoDetalleEntradas::buscarRegistro(int idDetalleEntrada) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        DetalleEntrada obj = leerRegistro(i);
        if (obj.getIdDetalleEntrada() == idDetalleEntrada) {
            return i;
        }
    }
    return -1;
}

bool ArchivoDetalleEntradas::modificarRegistro(DetalleEntrada obj, int pos) {
    FILE* p = fopen(nombre, "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof(DetalleEntrada), SEEK_SET);
    bool escribio = (fwrite(&obj, sizeof(DetalleEntrada), 1, p) == 1);
    fclose(p);
    return escribio;
}
