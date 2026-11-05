#ifndef CLSBUTACA_H_INCLUDED
#define CLSBUTACA_H_INCLUDED

class Butaca
{
private:
    int _idSala;
    char _numeroButaca[7];
    bool _estado;
public:
    Butaca (int idSala=0, const char * numeroButaca="S/N", bool estado=false);
    void mostrar();
    void setIdSala(int);
    void setNumeroButaca(const char *);
    void setEstado(bool);
    int getIdSala();
    const char * getNumeroButaca();
    bool getEstado();
};

#endif // CLSBUTACA_H_INCLUDED
