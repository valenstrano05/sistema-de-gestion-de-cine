#include <iostream>
#include <cstring>
#include "clsSocio.h"
#include "clsArchivoSocios.h"
#include "funciones.h"

using namespace std;

Socio::Socio (int idSocio, int dni, const char * nombre, const char * apellido, bool estado)
{
    _idSocio=idSocio;
    _dni=dni;
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    _estado=estado;
}

void Socio::cargar()
{
    ArchivoSocios arch;

    cout << "ID: ";
    while (!(cin >> _idSocio) || _idSocio <= 0 || arch.buscarRegistro(_idSocio) != -1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else if (_idSocio <= 0)
        {
            cout << "Error, el ID no puede ser negativo o cero." << endl;
        }
        else
        {
            cout << "Error, el ID ya existe." << endl;
        }
        cout << "Ingresar ID nuevamente: ";
    }

    cout << "DNI: ";
    while (!(cin >> _dni) || _dni < 1000000 || _dni > 99999999)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else
        {
            cout << "Error, el DNI debe tener 7 u 8 digitos." << endl;
        }
        cout << "Ingresar DNI nuevamente: ";
    }

    cin.ignore(1000, '\n');
    cargarCadena("NOMBRE: ", _nombre, 30);
    cargarCadena("APELLIDO: ", _apellido, 30);

    _estado = true;
}

void Socio::mostrar()
{
    if (_estado)
    {
        cout << "---------------------------------------" << endl;
        cout << "ID: " << _idSocio << endl;
        cout << "DNI: " << _dni << endl;
        cout << "NOMBRE: " << _nombre << endl;
        cout << "APELLIDO: " << _apellido << endl;
        cout << endl;
    }
}

void Socio::setIdSocio(int idSocio)
{
    if(idSocio>0)
    {
        _idSocio=idSocio;
    }
}
void Socio::setDni(int dni)
{
    if(dni>0)
    {
        _dni=dni;
    }
}
void Socio::setNombre(const char * nombre)
{
    if (nombre != nullptr && nombre[0] != '\0')
    {
        strcpy(_nombre, nombre);
    }
}
void Socio::setApellido(const char * apellido)
{
    if (apellido != nullptr && apellido[0] != '\0')
    {
        strcpy(_apellido, apellido);
    }
}
void Socio::setEstado(bool estado)
{
    _estado=estado;
}
int Socio::getIdSocio()
{
    return _idSocio;
}
int Socio::getDni()
{
    return _dni;
}
const char * Socio::getNombre()
{
    return _nombre;
}
const char * Socio::getApellido()
{
    return _apellido;
}
bool Socio::getEstado()
{
    return _estado;
}
