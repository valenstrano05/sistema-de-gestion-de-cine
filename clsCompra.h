#ifndef CLSCOMPRA_H
#define CLSCOMPRA_H
#include "clsFecha.h"
#include "clsHora.h"

class Compra {
private:
    int _idCompra;
    int _idSocio;
    Fecha _fechaCompra;
    Hora _horaCompra;
    bool _estado;

public:
    Compra();
    void setIdCompra(int ID);
    void setIdSocio(int ID);
    void setFechaCompra(Fecha fechaCompra);
    void setHoraCompra(Hora horaCompra);
    void setEstado(bool estado);
    int getIdCompra();
    int getIdSocio();
    Fecha getFechaCompra();
    Hora getHoraCompra();
    bool getEstado();
    void cargar();
    void mostrar();
};

#endif // CLSCOMPRA_H
