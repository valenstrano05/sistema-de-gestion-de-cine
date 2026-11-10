#ifndef FORMATO_H_INCLUDED
#define FORMATO_H_INCLUDED

class Formato {
private:
    int _id;
    char _nombre[10];
    float _precio;
    bool _estado;
public:
    Formato(int id = 0, const char* nombre = "", float precio = 0);
    void cargar();
    void mostrar();
    void modificar();
    void setID(int id);
    void setNombre (const char* nombre);
    void setPrecio(float precio);
    void setEstado (bool estado);
    int getID();
    const char* getNombre();
    float getPrecio();
    bool getEstado();

};


#endif // FORMATO_H_INCLUDED
