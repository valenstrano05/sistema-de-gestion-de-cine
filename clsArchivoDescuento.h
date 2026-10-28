 #ifndef ARCHIVODESCUENTO_H_INCLUDED
#define ARCHIVODESCUENTO_H_INCLUDED
#include "clsDescuento.h"


class ArchivoDescuento {
private:
    char nombreArchivo [30];
public:
    ArchivoDescuento (const char* nombre = "descuentos.dat");
    bool guardar (Descuento);
    int cantidadRegistros();
    Descuento leer (int posicion);
    int buscarPorID (int);
    bool modificar (Descuento, int);
};







#endif // ARCHIVODESCUENTO_H_INCLUDED
