#include <iostream>
#include "clsArchivoFunciones.h"
using namespace std;

ArchivoFunciones::ArchivoFunciones(const char* n) {
    strcpy(nombre, n);
}

bool ArchivoFunciones::grabarRegistro(Funcion obj) {
    FILE* p = fopen(nombre, "ab");
    if (p == nullptr) {
        return false;
    }
    bool escribio = (fwrite(&obj, sizeof(Funcion), 1, p) == 1);
    fclose(p);
    return escribio;
}

int ArchivoFunciones::contarRegistros() {
    FILE* p = fopen(nombre, "rb");
    if (p == nullptr) {
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Funcion);
}

void ArchivoFunciones::listarRegistros() {
    int cantReg = contarRegistros();
    if (cantReg <= 0) {
        cout << "No hay funciones registradas o el archivo esta vacio."<<endl;
        return;
    }

    cout << "======================================="<<endl;
    cout << "       LISTADO DE FUNCIONES ACTIVAS    "<<endl;
    cout << "======================================="<<endl;

    for (int i = 0; i < cantReg; i++) {
        Funcion obj = leerRegistro(i);
        if (obj.getEstado() == true) {
            obj.mostrar();
            cout << "======================================="<<endl;
        }
    }
}

Funcion ArchivoFunciones::leerRegistro(int pos) {
    FILE* p = fopen(nombre, "rb");
    Funcion obj;
    if (p == nullptr) {
        obj.setIdFuncion(-1);
        return obj;
    }
    fseek(p, pos * sizeof(Funcion), SEEK_SET);
    fread(&obj, sizeof(Funcion), 1, p);
    fclose(p);
    return obj;
}

int ArchivoFunciones::buscarRegistro(int idFuncion) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Funcion obj = leerRegistro(i);
        if (obj.getIdFuncion() == idFuncion) {
            return i;
        }
    }
    return -1;
}

bool ArchivoFunciones::modificarRegistro(Funcion obj, int pos) {
    FILE* p = fopen(nombre, "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof(Funcion), SEEK_SET);
    bool escribio = (fwrite(&obj, sizeof(Funcion), 1, p) == 1);
    fclose(p);
    return escribio;
}
