#ifndef DESCUENTO_H_INCLUDED
#define DESCUENTO_H_INCLUDED
#include <cstring>



class Descuento {
private:
    int id;
    char nombrePromo[40];
    float porcentaje;
    int tipoDescuento;
    bool estado;
public:
    Descuento (int _id=0, const char* nombre ="", float _porcentaje=0.0, int tipo=1, bool _estado=0);
    void cargar();
    void mostrar();
    void modificar();
    void setID (int);
    int getID();
    void setNombre(const char*);
    const char* getNombre();
    void setPorcentaje (float);
    float getPorcentaje ();
    void setTipoDescuento (int);
    int getTipoDescuento ();
    void setEstado (bool);
    bool getEstado ();
    };





#endif // DESCUENTO_H_INCLUDED
