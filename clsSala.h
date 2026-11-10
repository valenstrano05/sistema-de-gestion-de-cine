#ifndef CLSSALA_H_INCLUDED
#define CLSSALA_H_INCLUDED

class Sala
{
private:
    int _idSala;
    int _capacidadButacas;
    int _formatoProyeccion;
    bool _estado;
public:
    Sala (int idSala=0, int capacidadButacas=120, int formatoProyeccion=1, bool estado=false);
    void cargar();
    void mostrar();
    void setIdSala(int);
    void setCapacidadButacas(int);
    void setFormatoProyeccion(int);
    void setEstado(bool);
    int getIdSala();
    int getCapacidadButacas();
    int getFormatoProyeccion();
    float getPrecio();
    bool getEstado();
};

#endif // CLSSALA_H_INCLUDED
