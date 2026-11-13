#include <iostream>
#include <cstring>
#include "clsFormato.h"
#include "clsArchivoFormato.h"
#include "funciones.h"

using namespace std;


Formato::Formato(int id, const char* nombre, float precio)
{
    _id = id;
    strcpy(_nombre, nombre);
    _precio = precio;
    _estado = true;
}

void Formato::cargar()
{
    ArchivoFormato arch;
    cout << "ID: ";
    cin >> _id;
    while (_id <= 0 || arch.buscarPorID(_id) != -1)
    {
        if (_id <= 0)
        {
            cout << "Error, el ID no puede ser negativo o cero." << endl;
        }
        else
        {
            cout << "Error, el ID ya existe." << endl;
        }
        cout << "Ingresar ID nuevamente: ";
        cin >> _id;
    }

    cargarCadena("NOMBRE: ", _nombre, 10);

    cout <<"PRECIO: $";
    cin >> _precio;
    while (_precio<=0){
    cout << "Error, el precio debe ser un numero mayor a 0. Ingresar nuevamente: "; cin >> _precio;
    }

    _estado=true;
}

void Formato::mostrar()
{
    if (_estado)
    {
        cout <<"---------------------------------------" <<endl;
        cout <<"                  " <<_nombre <<endl;
        cout <<"---------------------------------------" <<endl;
        cout <<"\tID: " <<_id <<endl;
        cout <<"\tPRECIO: $" <<_precio <<endl;
        cout <<endl;
    }
}

void Formato::modificar()
{
    cout <<"ACTUALIZAR PRECIO: $";
    cin>> _precio;
}


void Formato::setID(int id)
{
    if (id>0) _id=id;
}
void Formato::setPrecio(float precio)
{
    if (precio > 0) _precio = precio;
}
void Formato::setNombre(const char* nombre)
{
    if (nombre != nullptr && nombre[0] != '\0')
    {
        strcpy(_nombre, nombre);
    }
}
void Formato::setEstado(bool estado)
{
    _estado=estado;
}


int Formato::getID()
{
    return _id;
}
const char* Formato::getNombre()
{
    return _nombre;
}
float Formato::getPrecio()
{
    return _precio;
}
bool Formato::getEstado()
{
    return _estado;
}


