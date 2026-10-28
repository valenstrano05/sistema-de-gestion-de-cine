#include <iostream>
#include "clsDescuento.h"
#include "clsArchivoDescuento.h"
#include "funciones.h"
using namespace std;




Descuento::Descuento(int _id, const char* nombre, float _porcentaje, int tipo, bool _estado)
{
    id = _id;
    strcpy(nombrePromo, nombre);
    _porcentaje = porcentaje;
    tipoDescuento = tipo;
    estado = false;
}


void Descuento::cargar()
{
    ArchivoDescuento arch;
    cout << "ID: ";
    while (!(cin >> id) || id <= 0 || arch.buscarPorID(id) != -1) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Debe ingresar un número válido." << endl;
    }
    else if (id <= 0) {
        cout << "Error, el ID no puede ser negativo o cero." << endl;
    }
    else {
        cout << "Error, el ID ya existe." << endl;
    }
    cout << "Ingresar ID nuevamente: ";
    }

    cin.ignore();
    cargarCadena("NOMBRE PROMO: ", nombrePromo, 40);

    cout <<"PORCENTAJE DE DESCUENTO (%): ";
    while (porcentaje<=0 ||  porcentaje>=100){
        cout <<"Porcentaje invalido, ingreselo nuevamente: ";
        cin>> porcentaje;
    }

    cout <<"TIPO (1: EDAD, 2: DIA, 3: EVENTO): ";
    cin >>tipoDescuento;
    while (tipoDescuento < 1 || tipoDescuento > 3){
        cout <<"Error, ingrese una clasificación válida: ";
        cin >>tipoDescuento;
    }

    estado = true;
}


void Descuento::mostrar()
{
    cout <<"ID: "<<id <<endl;
    cout <<"NOMBRE: "<<nombrePromo <<endl;
    cout <<"PORCENTAJE DESCONTADO: " <<porcentaje <<"%" <<endl;
    cout <<"TIPO: ";
    switch(tipoDescuento){
    case 1: cout<<"Edad"<<endl; break;
    case 2: cout<<"Dia"<<endl; break;
    case 3: cout<<"Evento"<<endl; break;
    }
    cout <<endl;
}


void Descuento::modificar()
{
    cout <<"PORCENTAJE (%): " <<porcentaje;
}


void Descuento::setID(int _id)
{
    if (_id>0) id=_id;
}
int Descuento::getID()
{
    return id;
}

void Descuento::setNombre(const char* _nombre)
{
    if (_nombre != nullptr && _nombre[0] != '\0') {
        strcpy(nombrePromo, _nombre);
    }
}
const char* Descuento::getNombre()
{
    return nombrePromo;
}

void Descuento::setPorcentaje(float porc)
{
    if (porc>0 && porc<100) porcentaje=porc;
}
float Descuento::getPorcentaje()
{
    return porcentaje;
}

void Descuento::setTipoDescuento(int tipo)
{
    if (tipo>=1 && tipo<=3) tipoDescuento=tipo;
}
int Descuento::getTipoDescuento()
{
    return tipoDescuento;
}

void Descuento::setEstado(bool _estado)
{
    estado=_estado;
}
bool Descuento::getEstado()
{
    return estado;
}


