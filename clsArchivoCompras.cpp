#include <iostream>
#include "clsArchivoCompras.h"
using namespace std;

ArchivoCompras::ArchivoCompras(const char* n) {
    strcpy(nombre, n);
}

bool ArchivoCompras::grabarRegistro(Compra obj) {
    FILE* p = fopen(nombre, "ab");
    if (p == nullptr) {
        return false;
    }
    bool escribio = (fwrite(&obj, sizeof(Compra), 1, p) == 1);
    fclose(p);
    return escribio;
}

int ArchivoCompras::contarRegistros() {
    FILE* p = fopen(nombre, "rb");
    if (p == nullptr) {
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Compra);
}

void ArchivoCompras::listarRegistros() {
    int cantReg = contarRegistros();
    if (cantReg <= 0) {
        cout << "No hay compras registradas o el archivo esta vacio." << endl;
        return;
    }

    cout << "=======================================" << endl;
    cout << "         LISTADO DE COMPRAS            " << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < cantReg; i++) {
        Compra obj = leerRegistro(i);
        if (obj.getEstado() == true) {
            obj.mostrar();
            cout << "=======================================" << endl;
        }
    }
}

Compra ArchivoCompras::leerRegistro(int pos) {
    FILE* p = fopen(nombre, "rb");
    Compra obj;
    if (p == nullptr) {
        obj.setIdCompra(-1);
        return obj;
    }
    fseek(p, pos * sizeof(Compra), SEEK_SET);
    fread(&obj, sizeof(Compra), 1, p);
    fclose(p);
    return obj;
}

int ArchivoCompras::buscarRegistro(int idCompra) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Compra obj = leerRegistro(i);
        if (obj.getIdCompra() == idCompra) {
            return i;
        }
    }
    return -1;
}

bool ArchivoCompras::modificarRegistro(Compra obj, int pos) {
    FILE* p = fopen(nombre, "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof(Compra), SEEK_SET);
    bool escribio = (fwrite(&obj, sizeof(Compra), 1, p) == 1);
    fclose(p);
    return escribio;
}
