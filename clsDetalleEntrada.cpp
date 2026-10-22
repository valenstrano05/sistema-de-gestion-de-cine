#include <iostream>
#include "clsDetalleEntrada.h"
#include "clsArchivoDetalleEntradas.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoCompras.h"
#include "clsArchivoButacas.h"
#include "clsArchivoDescuentos.h"

DetalleEntrada::DetalleEntrada()
{
    _idDetalleEntrada = 0;
    _idFuncion = 0;
    _idCompra = 0;
    _idButaca = 0;
    _idDescuento = 0;
}

void DetalleEntrada::setIdDetalleEntrada(int ID)
{
    _idDetalleEntrada = ID;
}
void DetalleEntrada::setIdFuncion(int ID)
{
    _idFuncion = ID;
}
void DetalleEntrada::setIdCompra(int ID)
{
    _idCompra = ID;
}
void DetalleEntrada::setIdButaca(int ID)
{
    _idButaca = ID;
}
void DetalleEntrada::setIdDescuento(int ID)
{
    _idDescuento = ID;
}
int DetalleEntrada::getIdDetalleEntrada()
{
    return _idDetalleEntrada;
}
int DetalleEntrada::getIdFuncion()
{
    return _idFuncion;
}
int DetalleEntrada::getIdCompra()
{
    return _idCompra;
}
int DetalleEntrada::getIdButaca()
{
    return _idButaca;
}
int DetalleEntrada::getIdDescuento()
{
    return _idDescuento;
}
void DetalleEntrada::cargar()
{
    ArchivoDetalleEntradas arcDetalle;
    ArchivoFunciones arcFunciones;
    ArchivoCompras arcCompras;
    ArchivoButacas arcButacas;
    ArchivoDescuentos arcDescuentos;

    cout << "=== CARGAR DETALLE DE ENTRADA ===" << endl;

    do
    {
        cout << "ID Detalle Entrada: ";
        cin >> _idDetalleEntrada;

        if (_idDetalleEntrada <= 0)
        {
            cout << "Error, el ID del detalle de entrada tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else if (arcDetalle.buscarRegistro(_idDetalleEntrada) != -1)
        {
            cout << "Error, ya existe un detalle de entrada registrado con ese ID, intente de nuevo." << endl;
            _idDetalleEntrada = 0;
        }
    }
    while (_idDetalleEntrada <= 0);

    do
    {
        cout << "ID Funcion: ";
        cin >> _idFuncion;

        if (_idFuncion <= 0)
        {
            cout << "Error, el ID de la función tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else if (arcFunciones.buscarRegistro(_idFuncion) == -1)
        {
            cout << "Error, no existe una función con ese ID, intente de nuevo." << endl;
            _idFuncion = 0;
        }
    }
    while (_idFuncion <= 0);

    do
    {
        cout << "ID Compra: ";
        cin >> _idCompra;

        if (_idCompra <= 0)
        {
            cout << "Error, el ID de la compra tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else if (arcCompras.buscarRegistro(_idCompra) == -1)
        {
            cout << "Error, no existe una compra con ese ID, intente de nuevo." << endl;
            _idCompra = 0;
        }
    }
    while (_idCompra <= 0);

    do
    {
        cout << "ID Butaca: ";
        cin >> _idButaca;

        if (_idButaca <= 0)
        {
            cout << "Error, el ID de la butaca tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else if (archButacas.buscarRegistro(_idButaca) == -1)
        {
            cout << "Error, no existe una butaca con ese ID, intente de nuevo." << endl;
            _idButaca = 0;
        }
    }
    while (_idButaca <= 0);

    do
    {
        cout << "ID Descuento (0 si no aplica): ";
        cin >> _idDescuento;

        if (_idDescuento < 0)
        {
            cout << "Error, el ID de descuento no puede ser negativo, intente de nuevo." << endl;
        }
        else if (_idDescuento > 0 && archDescuentos.buscarRegistro(_idDescuento) == -1)
        {
            cout << "Error, no existe un descuento con ese ID, intente de nuevo." << endl;
            _idDescuento = -1;
        }
    }
    while (_idDescuento < 0);
}

void DetalleEntrada::mostrar()
{
    cout << "ID Detalle Entrada: " << _idDetalleEntrada << <<endl;
    cout << "ID Funcion: " << _idFuncion << <<endl;
    cout << "ID Compra: " << _idCompra << <<endl;
    cout << "ID Butaca: " << _idButaca << <<endl;
    cout << "ID Descuento: " << _idDescuento<<endl;
    cout << "==========================================="<<endl;;
}
