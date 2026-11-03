#ifndef CLSSOCIO_H_INCLUDED
#define CLSSOCIO_H_INCLUDED

class Socio{
    private:
        int _idSocio;
        int _dni;
        char _nombre[30];
        char _apellido[30];
        bool _estado;
    public:
        Socio (int idSocio=0, int dni=0, const char * nombre="S/N", const char * apellido="S/N", bool estado=false);
        void cargar();
        void mostrar();
        void setIdSocio(int);
        void setDni(int);
        void setNombre(const char * nombre);
        void setApellido(const char * apellido);
        void setEstado(bool);
        int getIdSocio();
        int getDni();
        const char * getNombre();
        const char * getApellido();
        bool getEstado();
};

#endif // CLSSOCIO_H_INCLUDED
