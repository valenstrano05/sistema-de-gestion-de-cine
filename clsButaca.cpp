#include <iostream>
#include <cstring>
#include "clsButaca.h"
#include "clsArchivoButacas.h"
#include "clsArchivoSalas.h"

using namespace std;

bool codigoValido(const char *codigo)
{
    if (codigo == NULL || strlen(codigo) != 6)
    {
        return false;
    }

    return (codigo[0] == 'F' && codigo[1] >= '0' && codigo[1] <= '9' && codigo[2] >= '0' && codigo[2] <= '9' && codigo[3] == 'B' && codigo[4] >= '0' && codigo[4] <= '9' && codigo[5] >= '0' && codigo[5] <= '9');
}

Butaca::Butaca (int idSala, const char * numeroButaca, bool estado)
{
    _idSala=idSala;
    strcpy(_numeroButaca, numeroButaca);
    _estado=estado;
}

void Butaca::mostrar()
{
    if (_estado)
    {
        cout << "SALA: " << _idSala
             << " | BUTACA: " << _numeroButaca << endl;
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
