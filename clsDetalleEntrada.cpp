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

void DetalleEntrada::cargar(int idCompra)
{
    ArchivoDetalleEntradas archDetalle;
    ArchivoFunciones archFunciones;
    ArchivoButacas archButacas;
    ArchivoDescuento archDescuentos;

    _idDetalleEntrada = archDetalle.contarRegistros() + 1;
    _idCompra = idCompra;

    int posFuncion;
    do
    {
        cout << "ID Funcion: ";
        cin >> _idFuncion;

        if (_idFuncion <= 0)
        {
            cout << "Error, el ID de la funcion tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else
        {
            posFuncion = archFunciones.buscarRegistro(_idFuncion);
            if (posFuncion == -1 || archFunciones.leerRegistro(posFuncion).getEstado()==false)
            {
                cout << "Error, no existe una funcion activa con ese ID, intente de nuevo." << endl;
                _idFuncion = -1;
            }
        }
    }
    while (_idFuncion <= 0);

    Funcion f = archFunciones.leerRegistro(posFuncion);
    _idSala = f.getIdSala();
    cout << "ID de Sala encontrado automaticamente: " << _idSala << endl;

    bool butacaValida = false;
    do
    {
        cargarCadena("Numero de butaca (ej: F01B05): ", _numeroButaca, 7);

        int posButaca = archButacas.buscarRegistro(_idSala, _numeroButaca);
        if (posButaca == -1 || archButacas.leerRegistro(posButaca).getEstado()==false)
        {
            cout << "Error, la butaca no existe o no esta habilitada en la sala " << _idSala << "." << endl;
            continue;
        }

        bool yaVendida = false;
        int cantD = archDetalle.contarRegistros();
        ArchivoCompras archCompras;

        for (int i = 0; i < cantD; i++)
        {
            DetalleEntrada d = archDetalle.leerRegistro(i);
            if (d.getIdFuncion() == _idFuncion && strcmp(d.getNumeroButaca(), _numeroButaca) == 0)
            {
                int posC = archCompras.buscarRegistro(d.getIdCompra());
                if (posC != -1 && archCompras.leerRegistro(posC).getEstado())
                {
                    yaVendida = true;
                    break;
                }
            }
        }

        if (yaVendida)
        {
            cout << "Error, esa butaca ya fue vendida para esta funcion. Elija otra." << endl;
        }
        else
        {
            butacaValida = true;
        }
    }
    while (butacaValida==false);

    do
    {
        cout << "ID Descuento (0 si no aplica): ";
        cin >> _idDescuento;

        if (_idDescuento < 0)
        {
            cout << "Error, el ID de descuento no puede ser negativo, intente de nuevo." << endl;
        }
        else if (_idDescuento > 0)
        {
            int posDesc = archDescuentos.buscarPorID(_idDescuento);
            if (posDesc == -1 || archDescuentos.leer(posDesc).getEstado()==false)
            {
                cout << "Error, no existe un descuento activo con ese ID, intente de nuevo." << endl;
                _idDescuento = -1;
            }
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
