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


bool Funcion::getEstado()
{
    return _estado;
}

void Funcion::cargar()
{
    ArchivoFunciones arcFunciones;
    ArchivoPeliculas arcPeliculas;
    ArchivoSalas arcSalas;
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
        else if (arcPeliculas.buscarPorID(_idPelicula)==-1)
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
    _fecha.Cargar();
    cout << "Horario de proyeccion... " <<endl;
    _horario.Cargar();

    _estado = true;
}

void Funcion::mostrar()
{
    if(_estado==false)
    {
        return;
    }
    cout << "ID Funcion: " << _idFuncion << endl;

    ArchivoPeliculas archP;
    int pos = archP.buscarPorID(_idPelicula);
    if (pos != -1){
        Pelicula objP = archP.leerRegistro(pos);
        cout <<"PELICULA: " <<objP.getTitulo() <<endl;
    }

    cout << "ID Sala: " << _idSala << endl;
    cout << "FECHA: ";
    _fecha.Mostrar();
    _horario.Mostrar();

    ArchivoSalas archS;
    int posS = archS.buscarRegistro(_idSala);
    if (posS != -1){
        Sala objS = archS.leerRegistro(pos);
        cout << "PRECIO: " <<objS.getPrecio() <<endl;
    }
}


void Funcion::modificar()
{
    int opcion;
    cout <<"Seleccione el campo a modificar..." <<endl;
    cout <<"1. PELICULA " <<endl;
    cout <<"2. SALA " <<endl;
    cout <<"3. HORARIO " <<endl;
    cout <<"4. FECHA " <<endl;
    cin >>opcion;
    system("cls");
    switch(opcion)
    {
    case 1:{
        ArchivoPeliculas arcPeliculas;
        do{
        cout << "NUEVO ID PELICULA: ";
        cin >> _idPelicula;
        if(_idPelicula<=0)
        {
            cout << "Error, el ID de la película tiene que ser mayor a 0, intente de nuevo."<<endl;
        }
        else if (arcPeliculas.buscarPorID(_idPelicula)==-1)
        {
            cout << "Error, no existe una película con ese ID, intente de nuevo."<<endl;
            _idPelicula=0;
        }
    }while (_idPelicula<=0);
        break;}
    case 2:{
        ArchivoSalas arcSalas;
        do{
        cout << "NUEVO ID SALA: ";
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
    }while (_idSala <= 0);
        break;}
    case 3:
        cout <<"NUEVO HORARIO: ";
        _horario.Cargar();
        break;
    case 4:
        cout <<"NUEVA FECHA: ";
        _fecha.Cargar();
        break;
    default:
        cout <<"Opcion invalida." <<endl;
        break;
    }
}
