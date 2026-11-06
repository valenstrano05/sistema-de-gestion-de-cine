#ifndef CLSCOMPRA_H
#define CLSCOMPRA_H
#include "clsFecha.h"
#include "clsHora.h"

class Compra
{
private:
    int _idCompra;
    int _idSocio;
    Fecha _fecha;
    Hora _hora;
    bool _estado;

public:
    Compra();
    void setIdCompra(int ID);
    void setIdSocio(int ID);
    void setFecha(Fecha fechaCompra);
    void setHora(Hora horaCompra);
    void setEstado(bool estado);
    int getIdCompra();
    int getIdSocio();
    Fecha getFecha();
    Hora getHorario();
    bool getEstado();
    void cargar();
    void mostrar();
};

#endif // CLSCOMPRA_H
