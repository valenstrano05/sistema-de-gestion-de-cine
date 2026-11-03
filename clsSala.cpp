#include <iostream>
#include "clsSala.h"
#include "clsArchivoSalas.h"

using namespace std;

Sala::Sala (int idSala, int capacidadButacas, int formatoProyeccion, float precio, bool estado){
    _idSala=idSala;
    _capacidadButacas=capacidadButacas;
    _formatoProyeccion=formatoProyeccion;
    _precio=precio;
    _estado=estado;
}

void Sala::cargar(){
    ArchivoSalas arch;

    cout << "ID: ";
    while (!(cin >> _idSala) || _idSala <= 0 || arch.buscarRegistro(_idSala) != -1) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else if (_idSala <= 0) {
            cout << "Error, el ID no puede ser negativo o cero." << endl;
        }
        else {
            cout << "Error, el ID ya existe." << endl;
        }
        cout << "Ingresar ID nuevamente: ";
    }

    cout << "CAPACIDAD DE BUTACAS (1 a 500): ";
    while (!(cin >> _capacidadButacas) || _capacidadButacas < 1 || _capacidadButacas > 500) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else {
            cout << "Error, la capacidad debe estar entre 1 y 500." << endl;
        }
        cout << "Ingresar capacidad nuevamente: ";
    }

    cout << "FORMATO DE PROYECCION (1: 2D, 2: 3D, 3: IMAX): ";
    while (!(cin >> _formatoProyeccion) || _formatoProyeccion < 1 || _formatoProyeccion > 3) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else {
            cout << "Error, ingrese un formato valido." << endl;
        }
        cout << "Ingresar formato nuevamente: ";
    }

    cout << "PRECIO: ";
    while (!(cin >> _precio) || _precio <= 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else {
            cout << "Error, el precio debe ser mayor a 0." << endl;
        }
        cout << "Ingresar precio nuevamente: ";
    }

    cin.ignore(1000, '\n');
    _estado = true;
}

void Sala::mostrar(){
    if (_estado){
        cout << "---------------------------------------" << endl;
        cout << "ID: " << _idSala << endl;
        cout << "CAPACIDAD: " << _capacidadButacas << " butacas" << endl;
        cout << "FORMATO: ";
        switch(_formatoProyeccion){
            case 1: cout << "2D" << endl; break;
            case 2: cout << "3D" << endl; break;
            case 3: cout << "IMAX" << endl; break;
        }
        cout << "PRECIO: $" << _precio << endl;
        cout << endl;
    }
}

void Sala::setIdSala(int idSala){
    if(idSala>0){
        _idSala=idSala;
    }
}
void Sala::setCapacidadButacas(int capacidad){
    if(capacidad>0){
        _capacidadButacas=capacidad;
    }
}
void Sala::setFormatoProyeccion(int formato){
    if(formato>=1 && formato<=3){
        _formatoProyeccion=formato;
    }
}
void Sala::setPrecio(float precio){
    if(precio>0){
        _precio=precio;
    }
}
void Sala::setEstado(bool estado){
    _estado=estado;
}
int Sala::getIdSala(){
    return _idSala;
}
int Sala::getCapacidadButacas(){
    return _capacidadButacas;
}
int Sala::getFormatoProyeccion(){
    return _formatoProyeccion;
}
float Sala::getPrecio(){
    return _precio;
}
bool Sala::getEstado(){
    return _estado;
}
