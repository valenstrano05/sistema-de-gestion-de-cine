#ifndef CLSDETALLEENTRADA_H
#define CLSDETALLEENTRADA_H

class DetalleEntrada {
private:
    int _idDetalleEntrada;
    int _idFuncion;
    int _idCompra;
    int _idButaca;
    int _idDescuento;

public:
    DetalleEntrada();
    void setIdDetalleEntrada(int ID);
    void setIdFuncion(int ID);
    void setIdCompra(int ID);
    void setIdButaca(int ID);
    void setIdDescuento(int ID);
    int getIdDetalleEntrada();
    int getIdFuncion();
    int getIdCompra();
    int getIdButaca();
    int getIdDescuento();
    void cargar();
    void mostrar();
};

#endif // CLSDETALLEENTRADA_H
