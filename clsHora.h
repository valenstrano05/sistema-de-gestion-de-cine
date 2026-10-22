#ifndef CLSHORA_H_INCLUDED
#define CLSHORA_H_INCLUDED

class Hora {
private:
    int hora;
    int minutos;
public:
    Hora(int h=0, int m=0);
    void setHora(int);
    void setMinutos(int);
    int getHora();
    int getMinutos();
    void Cargar();
    void Mostrar();
    ~Hora();
    bool operator==(Hora h);
};

#endif // CLSHORA_H_INCLUDED
