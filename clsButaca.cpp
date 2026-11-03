#include <iostream>
#include <cstring>
#include "clsButaca.h"
#include "clsArchivoButacas.h"
#include "clsArchivoSalas.h"

using namespace std;

// Formato valido: F + 2 digitos + B + 2 digitos (ej: F17B36)
static bool codigoValido(const char * codigo)
{
    if (codigo == nullptr || strlen(codigo) != 6) return false;
    return codigo[0]=='F' && codigo[3]=='B'
           && isdigit((unsigned char)codigo[1]) && isdigit((unsigned char)codigo[2])
           && isdigit((unsigned char)codigo[4]) && isdigit((unsigned char)codigo[5]);
}

Butaca::Butaca (int idButaca, int idSala, const char * numeroButaca, bool estado)
{
    _idButaca=idButaca;
    _idSala=idSala;
    strcpy(_numeroButaca, numeroButaca);
    _estado=estado;
}

void Butaca::cargar()
{
    ArchivoButacas arch;
    ArchivoSalas archSalas;

    cout << "ID: ";
    while (!(cin >> _idButaca) || _idButaca <= 0 || arch.buscarRegistro(_idButaca) != -1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else if (_idButaca <= 0)
        {
            cout << "Error, el ID no puede ser negativo o cero." << endl;
        }
        else
        {
            cout << "Error, el ID ya existe." << endl;
        }
        cout << "Ingresar ID nuevamente: ";
    }

    cout << "ID SALA: ";
    while (!(cin >> _idSala) || _idSala <= 0 || archSalas.buscarRegistro(_idSala) == -1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Debe ingresar un numero valido." << endl;
        }
        else if (_idSala <= 0)
        {
            cout << "Error, el ID de la sala no puede ser negativo o cero." << endl;
        }
        else
        {
            cout << "Error, no existe una sala con ese ID." << endl;
        }
        cout << "Ingresar ID de sala nuevamente: ";
    }

    cin.ignore(1000, '\n');
    cout << "NUMERO DE BUTACA (ej: F17B36 = fila 17, butaca 36): ";
    cin.getline(_numeroButaca, 7);
    while (cin.fail() || !codigoValido(_numeroButaca))
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Error, formato invalido. Ingresar nuevamente (ej: F17B36): ";
        cin.getline(_numeroButaca, 7);
    }

    _estado = true;
}

void Butaca::mostrar()
{
    if (_estado)
    {
        cout << "ID: " << _idButaca
             << " | SALA: " << _idSala
             << " | BUTACA: " << _numeroButaca << endl;
    }
}

void Butaca::setIdButaca(int idButaca)
{
    if(idButaca>0)
    {
        _idButaca=idButaca;
    }
}
void Butaca::setIdSala(int idSala)
{
    if(idSala>0)
    {
        _idSala=idSala;
    }
}
void Butaca::setNumeroButaca(const char * numeroButaca)
{
    if (codigoValido(numeroButaca))
    {
        strcpy(_numeroButaca, numeroButaca);
    }
}
void Butaca::setEstado(bool estado)
{
    _estado=estado;
}
int Butaca::getIdButaca()
{
    return _idButaca;
}
int Butaca::getIdSala()
{
    return _idSala;
}
const char * Butaca::getNumeroButaca()
{
    return _numeroButaca;
}
bool Butaca::getEstado()
{
    return _estado;
}
