#include <iostream>
#include "clsSala.h"
#include "clsArchivoSalas.h"
#include "clsArchivoFormato.h"

using namespace std;

Sala::Sala (int idSala, int capacidadButacas, int formatoProyeccion, bool estado)
{
    _idSala=idSala;
    _capacidadButacas=capacidadButacas;
    _formatoProyeccion=formatoProyeccion;
    _estado=estado;
}

void Sala::cargar()
{
    ArchivoSalas arch;
    cout << "ID: ";
    while (!(cin >> _idSala) || _idSala <= 0 || arch.buscarRegistro(_idSala) != -1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else if (_idSala <= 0)
        {
            cout << "Error, el ID no puede ser negativo o cero." << endl;
        }
        else
        {
            cout << "Error, el ID ya existe." << endl;
        }
        cout << "Ingresar ID nuevamente: ";
    }

    cout << "CAPACIDAD DE BUTACAS (1 a 500): ";
    while (!(cin >> _capacidadButacas) || _capacidadButacas < 1 || _capacidadButacas > 500)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else
        {
            cout << "Error, la capacidad debe estar entre 1 y 500." << endl;
        }
        cout << "Ingresar capacidad nuevamente: ";
    }

    ArchivoFormato archF;
    cout << "ID FORMATO: ";
    while (!(cin >> _formatoProyeccion) || _formatoProyeccion <= 0 || archF.buscarPorID(_formatoProyeccion) == -1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else if (_idSala <= 0)
        {
            cout << "Error, el ID no puede ser negativo o cero." << endl;
        }
        else
        {
            cout << "Error, el ID de formato no esta registrado." << endl;
        }
        cout << "Ingresar ID nuevamente: ";
    }

    _estado = true;
}

void Sala::mostrar()
{
    if (_estado)
    {
        cout << "---------------------------------------" << endl;
        cout << "ID: " << _idSala << endl;
        cout << "CAPACIDAD: " << _capacidadButacas << " butacas" << endl;

        ArchivoFormato arch;
        int pos = arch.buscarPorID(_formatoProyeccion);
        if (pos != -1){
            Formato obj = arch.leerRegistro(pos);
            cout << "FORMATO: " <<obj.getNombre() <<endl;
            cout << "PRECIO: " <<obj.getPrecio() <<endl;
        }else {
            cout <<"Formato no encontrado."<<endl;
        }
        cout << endl;
    }
}

void Sala::setIdSala(int idSala)
{
    if(idSala>0)
    {
        _idSala=idSala;
    }
}
void Sala::setCapacidadButacas(int capacidad)
{
    if(capacidad>0)
    {
        _capacidadButacas=capacidad;
    }
}
void Sala::setFormatoProyeccion(int formato)
{
    if(formato>=1 && formato<=3)
    {
        _formatoProyeccion=formato;
    }
}
//void Sala::setPrecio(float precio)
//{
//    if(precio>0)
//    {
//        _precio=precio;
//    }
//}
void Sala::setEstado(bool estado)
{
    _estado=estado;
}
int Sala::getIdSala()
{
    return _idSala;
}
int Sala::getCapacidadButacas()
{
    return _capacidadButacas;
}
int Sala::getFormatoProyeccion()
{
    return _formatoProyeccion;
}


float Sala::getPrecio(){
    ArchivoFormato arch;
    int pos = arch.buscarPorID(_formatoProyeccion);
    if (pos == -1) return 0;
    return arch.leerRegistro(pos).getPrecio();
}
bool Sala::getEstado()
{
    return _estado;
}
