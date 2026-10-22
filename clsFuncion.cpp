#include <iostream>
using namespace std;
#include "clsFuncion.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoPeliculas.h"
#include "clsArchivoSalas.h"

Funcion::Funcion()
{
_idFuncion = 0;
_idPelicula = 0;
_idSala = 0;
_precio = 0;
_butacasDisponibles = 0;
_estado = true;
}

Funcion::~Funcion() {}

void Funcion::setIdFuncion(int ID)
{
_idFuncion = ID;
}

void Funcion::setIdPelicula(int ID)
{
_idPelicula = ID;
}

void Funcion::setIdSala(int ID)
{
_idSala = ID;
}

void Funcion::setHorario(Hora valor)
{
_horario = valor;
}

void Funcion::setFecha(Fecha valor)
{
_fecha = valor;
}

void Funcion::setPrecio(float valor)
{
_precio = valor;
}

void Funcion::setButacasDisponibles(int valor)
{
_butacasDisponibles = valor;
}

void Funcion::setEstado(bool valor)
{
_estado = valor;
}

int Funcion::getIdFuncion()
{
return _idFuncion;
}

int Funcion::getIdPelicula()
{
return _idPelicula;
}

int Funcion::getIdSala()
{
return _idSala;
}

Hora Funcion::getHorario()
{
return _horario;
}

Fecha Funcion::getFecha()
{
return _fecha;
}

float Funcion::getPrecio()
{
return _precio;
}

int Funcion::getButacasDisponibles()
{
return _butacasDisponibles;
}

bool Funcion::getEstado()
{
return _estado;
}

void Funcion::cargar()
{
ArchivoFunciones arcFunciones;
ArchivoPeliculas arcPeliculas;
ArchivoSalas arcSalas;
cout << "=== CARGAR NUEVA FUNCION ==="<<endl;
do
{
cout << "ID Funcion: ";
cin >> _idFuncion;
if(_idFuncion<=0)
{
cout << "Error, el ID de la función tiene que ser mayor a 0, intente de nuevo."<<endl;
}
else if (arcFunciones.buscarRegistro(_idFuncion)!=-1)
{
cout << "Error, ya existe una función registrada con ese ID, intente de nuevo."<<endl;
}
}
while (_idFuncion<=0 || arcFunciones.buscarRegistro(_idFuncion)!=-1);

do
{
    cout << "ID Pelicula: ";
    cin >> _idPelicula;
    if(_idPelicula<=0)
    {
        cout << "Error, el ID de la película tiene que ser mayor a 0, intente de nuevo."<<endl;
    }
    else if (arcPeliculas.buscarRegistro(_idPelicula)==-1)
    {
        cout << "Error, no existe una película con ese ID, intente de nuevo."<<endl;
        _idPelicula=0;
    }
}
while (_idPelicula<=0);

do
{
    cout << "ID Sala: ";
    cin >> _idSala;
    if (_idSala <= 0)
    {
        cout << "Error, el ID de la sala tiene que ser mayor a 0, intente de nuevo."<<endl;
    }
    else if (arcSalas.buscarRegistro(_idSala) == -1)
    {
        cout << "Error, no existe una sala con ese ID, intente de nuevo."<<endl;
        _idSala = 0;
    }
}
while (_idSala <= 0);

cout << "Fecha de proyeccion: ";
_fecha.cargar();
cout << "Horario de proyeccion: ";
_horario.cargar();

do
{
    cout << "Precio de la entrada ($): ";
    cin >> _precio;
    if (_precio <= 0)
    {
        cout << "Error, el precio de la entrada tiene que ser mayor a 0, intente de nuevo."<<endl;
    }
}
while (_precio <= 0);

do
{
    cout << "Butacas disponibles iniciales: ";
    cin >> _butacasDisponibles;
    if (_butacasDisponibles <= 0)
    {
        cout << "Error, la cantidad de butacas disponibles iniciales tiene que ser mayor a 0, intente de nuevo."<<endl;
    }
}
while (_butacasDisponibles <= 0);

_estado = true;
}

void Funcion::mostrar()
{
if(_estadofalse)
{
return;
}
cout << "ID Funcion: " << _idFuncion << endl;
cout << "ID Pelicula: " << _idPelicula <<endl;
cout << "ID Sala: " << _idSala << endl;
_fecha.mostrar();
_horario.mostrar();
cout << "\nPrecio: $ " << _precio <<endl;
cout << "Butacas Disponibles: " << _butacasDisponibles << endl;
cout << "===================================" << endl;
}
