#ifndef CLSDETALLEENTRADA_H
#define CLSDETALLEENTRADA_H

class DetalleEntrada
{
private:
    int _idDetalleEntrada;
    int _idFuncion;
    int _idCompra;
    int _idSala;
    char _numeroButaca[7];
    int _idDescuento;

public:
    DetalleEntrada();
    void setIdDetalleEntrada(int ID);
    void setIdFuncion(int ID);
    void setIdCompra(int ID);
    void setIdSala(int ID);
    void setNumeroButaca(const char * num);
    void setIdDescuento(int ID);
    int getIdDetalleEntrada();
    int getIdFuncion();
    int getIdCompra();
    int getIdSala();
    const char * getNumeroButaca();
    int getIdDescuento();
    void cargar();
    void mostrar();
};

#endif // CLSDETALLEENTRADA_H
