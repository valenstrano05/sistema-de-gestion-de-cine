#include <iostream>
#include <cstring>
#include "clsDescuento.h"
#include "clsArchivoDescuento.h"
#include "funciones.h"
using namespace std;

Descuento::Descuento(int _id, const char* nombre, float _porcentaje, bool _estado)
{
    id = _id;
    strcpy(nombrePromo, nombre);
    porcentaje = _porcentaje;
    estado = _estado;
}

void Descuento::cargar()
{
    ArchivoDescuento arch;
    cout << "ID: ";
    cin >> id;
    while (id <= 0 || arch.buscarPorID(id) != -1)
    {
        if (id <= 0)
        {
            cout << "Error, el ID no puede ser negativo o cero." << endl;
        }
        else
        {
            cout << "Error, el ID ya existe." << endl;
        }
        cout << "Ingresar ID nuevamente: ";
        cin >> id;
    }

    cin.ignore();
    cargarCadena("NOMBRE PROMO: ", nombrePromo, 40);

    cout << "PORCENTAJE DE DESCUENTO (%): ";
    cin >> porcentaje;
    while (porcentaje <= 0 || porcentaje >= 100)
    {
        cout << "Porcentaje invalido, ingreselo nuevamente: ";
        cin >> porcentaje;
    }

    estado = true;
}

void Descuento::mostrar()
{
    cout <<"ID: "<<id <<endl;
    cout <<"NOMBRE: "<<nombrePromo <<endl;
    cout <<"PORCENTAJE DESCONTADO: " <<porcentaje <<"%" <<endl;
    cout << "============================="<<endl;
}

void Descuento::modificar()
{
    cout <<"ACTUALIZAR PORCENTAJE DE DESCUENTO(%): ";
    cin >>porcentaje;
    while (porcentaje <= 0 || porcentaje >= 100)
    {
        cout << "Porcentaje invalido, ingreselo nuevamente: ";
        cin >> porcentaje;
    }
}

void Descuento::setID(int _id)
{
    if (_id>0) id=_id;
}

int Descuento::getID()
{
    return id;
}

void Descuento::setNombre(const char* _nombre)
{
    if (_nombre != NULL && _nombre[0] != '\0')
    {
        strcpy(nombrePromo, _nombre);
    }
}

const char* Descuento::getNombre()
{
    return nombrePromo;
}

void Descuento::setPorcentaje(float porc)
{
    if (porc>0 && porc<100) porcentaje=porc;
}

float Descuento::getPorcentaje()
{
    return porcentaje;
}

void Descuento::setTipoDescuento(int _tipo)
{
    if (_tipo > 0) id = _tipo;
}

int Descuento::getIDDescuento()
{
    return id;
}

void Descuento::setEstado(bool _estado)
{
    estado=_estado;
}

bool Descuento::getEstado()
{
    return estado;
}
