#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include "clsFecha.h"

class Pelicula{
private:
    int id;
    char titulo[50];
    char genero[30];
    char director[50];
    char sinopsis[500];
    Fecha fechaEstreno;
    int duracion;
    int clasificacion;
    bool estado;
public:
    Pelicula(int _id=0, const char* _titulo="", const char* _genero="", const char* _director="", const char* _sinopsis="",
    Fecha _fecha=Fecha(), int _duracion=0, int _clasificacion=0, bool _estado=0);
    void cargar();
    void mostrar();
    void modificar();
    void setID (int);
    int getID();
    void setTitulo (const char*);
    const char* getTitulo();
    void setGenero (const char*);
    const char* getGenero();
    void setDirector (const char*);
    const char* getDirector();
    void setSinopsis (const char*);
    const char* getSinopsis();
    void setFecha (Fecha);
    Fecha getFecha();
    void setDuracion (int);
    int getDuracion();
    void setClasificacion (int);
    int getClasificacion ();
    void setEstado (bool);
    bool getEstado();
    };



#endif // PELICULA_H_INCLUDED
