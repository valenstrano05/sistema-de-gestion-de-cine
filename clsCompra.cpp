#include <iostream>
#include "clsCompra.h"
#include "clsArchivoCompras.h"
#include "clsArchivoSocios.h"

using namespace std;

Compra::Compra()
{
    _idCompra = 0;
    _idSocio = 0;
    _estado = true;
}

void Compra::setIdCompra(int ID)
{
    _idCompra = ID;
}
void Compra::setIdSocio(int ID)
{
    _idSocio = ID;
}
void Compra::setFechaCompra(Fecha fechaCompra)
{
    _fechaCompra = fechaCompra;
}
void Compra::setHoraCompra(Hora horaCompra)
{
    _horaCompra = horaCompra;
}
void Compra::setEstado(bool estado)
{
    _estado = estado;
}

int Compra::getIdCompra()
{
    return _idCompra;
}
int Compra::getIdSocio()
{
    return _idSocio;
}
Fecha Compra::getFechaCompra()
{
    return _fechaCompra;
}
Hora Compra::getHoraCompra()
{
    return _horaCompra;
}
bool Compra::getEstado()
{
    return _estado;
}

void Compra::cargar()
{
    ArchivoCompras arcCompras;
    ArchivoSocios arcSocios;

    cout << "=== CARGAR NUEVA COMPRA ===" << endl;

    do
    {
        cout << "ID Compra: ";
        cin >> _idCompra;

        if (_idCompra <= 0)
        {
            cout << "Error, el ID de la compra tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else if (arcCompras.buscarRegistro(_idCompra) != -1)
        {
            cout << "Error, ya existe una compra registrada con ese ID, intente de nuevo." << endl;
            _idCompra = 0;
        }
    }
    while (_idCompra <= 0);

    do
    {
        cout << "ID Socio: ";
        cin >> _idSocio;

        if (_idSocio <= 0)
        {
            cout << "Error, el ID del socio tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else if (arcSocios.buscarRegistro(_idSocio) == -1)
        {
            cout << "Error, no existe un socio con ese ID, intente de nuevo." << endl;
            _idSocio = 0;
        }
    }
    while (_idSocio <= 0);

    cout << "Fecha de compra:" << endl;
    _fechaCompra.Cargar();

    cout << "Hora de compra:" << endl;
    _horaCompra.Cargar();

    _estado = true;
}

void Compra::mostrar()
{
    if (!_estado) return;

    cout << "ID Compra: " << _idCompra << endl;
    cout << "ID Socio: " << _idSocio << endl;
    cout << "Fecha de Compra: ";
    _fechaCompra.Mostrar();
    cout << "Hora de Compra: ";
    _horaCompra.Mostrar();
    cout << endl << "========================================" << endl;
}
