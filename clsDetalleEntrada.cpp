#include <iostream>
#include <cstring>
#include "clsDetalleEntrada.h"
#include "clsArchivoDetalleEntradas.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoCompras.h"
#include "clsArchivoButacas.h"
#include "clsArchivoDescuento.h"
#include "clsArchivoSalas.h"
#include "funciones.h"
using namespace std;

DetalleEntrada::DetalleEntrada()
{
    _idDetalleEntrada = 0;
    _idFuncion = 0;
    _idCompra = 0;
    _idSala = 0;
    strcpy(_numeroButaca, "S/N");
    _idDescuento = 0;
}

void DetalleEntrada::setIdDetalleEntrada(int ID) { _idDetalleEntrada = ID; }
void DetalleEntrada::setIdFuncion(int ID) { _idFuncion = ID; }
void DetalleEntrada::setIdCompra(int ID) { _idCompra = ID; }
void DetalleEntrada::setIdSala(int ID) { _idSala = ID; }
void DetalleEntrada::setNumeroButaca(const char *num) { strcpy(_numeroButaca, num); }
void DetalleEntrada::setIdDescuento(int ID) { _idDescuento = ID; }

int DetalleEntrada::getIdDetalleEntrada() { return _idDetalleEntrada; }
int DetalleEntrada::getIdFuncion() { return _idFuncion; }
int DetalleEntrada::getIdCompra() { return _idCompra; }
int DetalleEntrada::getIdSala() { return _idSala; }
const char * DetalleEntrada::getNumeroButaca() { return _numeroButaca; }
int DetalleEntrada::getIdDescuento() { return _idDescuento; }

void DetalleEntrada::cargar()
{
    ArchivoDetalleEntradas arcDetalle;
    ArchivoFunciones arcFunciones;
    ArchivoCompras arcCompras;
    ArchivoSalas arcSalas;
    ArchivoButacas arcButacas;
    ArchivoDescuento arcDescuentos;

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
        cout << "ID de la Sala de la butaca: ";
        cin >> _idSala;

        if (_idSala <= 0 || arcSalas.buscarRegistro(_idSala) == -1)
        {
            cout << "Error, la sala no existe o el ID es invalido, intente de nuevo." << endl;
            _idSala = 0;
            continue;
        }
        cargarCadena("Numero de butaca (ej:F01B05:", _numeroButaca, 7);

        if (arcButacas.buscarRegistro(_idSala, _numeroButaca) == -1)
        {
            cout << "Error, no existe esa butaca en la sala indicada (o no esta disponible)." << endl;
            _idSala = 0; // Forzar a repetir el ciclo
        }
    }
    while (_idSala <= 0);

    do
    {
        cout << "ID Descuento (0 si no aplica): ";
        cin >> _idDescuento;

        if (_idDescuento < 0)
        {
            cout << "Error, el ID de descuento no puede ser negativo, intente de nuevo." << endl;
        }
        else if (_idDescuento > 0 && arcDescuentos.buscarPorID(_idDescuento) == -1)
        {
            cout << "Error, no existe un descuento con ese ID, intente de nuevo." << endl;
            _idDescuento = -1;
        }
    }
    while (_idDescuento < 0);
}

void DetalleEntrada::mostrar()
{
    cout << "ID Detalle Entrada: " << _idDetalleEntrada << endl;
    cout << "ID Funcion: " << _idFuncion << endl;
    cout << "ID Compra: " << _idCompra << endl;
    cout << "Sala: " << _idSala << " | Butaca: " << _numeroButaca << endl;
    cout << "ID Descuento: " << _idDescuento << endl;
    cout << "===========================================" << endl;
}
