#ifndef CLSFUNCION_H
#define CLSFUNCION_H
#include "clsFecha.h"
#include "clsHora.h"

class Funcion
{
private:
    int _idFuncion;
    int _idPelicula;
    int _idSala;
    Hora _horario;
    Fecha _fecha;
    bool _estado;

public:
    Funcion();
    ~Funcion();
    void setIdFuncion(int idFuncion);
    void setIdPelicula(int idPelicula);
    void setIdSala(int idSala);
    void setHorario(Hora horario);
    void setFecha(Fecha fecha);
    void setEstado(bool estado);
    int getIdFuncion();
    int getIdPelicula();
    int getIdSala();
    Hora getHorario();
    Fecha getFecha();
    bool getEstado();
    void cargar();
    void mostrar();
};

#endif
