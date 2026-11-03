#ifndef CLSBUTACA_H_INCLUDED
#define CLSBUTACA_H_INCLUDED

class Butaca{
    private:
        int _idButaca;
        int _idSala;
        char _numeroButaca[7];   // Ej: F17B36 = fila 17, butaca 36
        bool _estado;
    public:
        Butaca (int idButaca=0, int idSala=0, const char * numeroButaca="S/N", bool estado=false);
        void cargar();
        void mostrar();
        void setIdButaca(int);
        void setIdSala(int);
        void setNumeroButaca(const char *);
        void setEstado(bool);
        int getIdButaca();
        int getIdSala();
        const char * getNumeroButaca();
        bool getEstado();
};

#endif // CLSBUTACA_H_INCLUDED
