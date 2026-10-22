#include <iostream>
#include "clsFecha.h"
using namespace std;
Fecha::Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::setDia(int d)
{
    dia = d;
}
void Fecha::setMes(int m)
{
    mes = m;
}
void Fecha::setAnio(int a)
{
    anio = a;
}
int Fecha::getDia()
{
    return dia;
}
int Fecha::getMes()
{
    return mes;
}
int Fecha::getAnio()
{
    return anio;
}
void Fecha::Cargar()
{
    do
    {
        cout << "Dia: ";
        cin >> dia;
        if (dia <= 0 || dia >= 32)
        {
            cout << "Error, el día tiene que estar entre 1 y 31, intente de nuevo." << endl;
        }
    }
    while (dia <= 0 || dia >= 32);

    do
    {
        cout << "Mes: ";
        cin >> mes;
        if (mes <= 0 || mes >= 13)
        {
            cout << "Error, el mes tiene que estar entre 1 y 12, intente de nuevo." << endl;
        }
    }
    while (mes <= 0 || mes >= 13);

    do
    {
        cout << "Año: ";
        cin >> anio;
        if (anio < 0)
        {
            cout << "Error, el año tiene que ser mayor o igual a 0, intente de nuevo." << endl;
        }
    }
    while (anio < 0);
}
void Fecha::Mostrar()
{
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
bool Fecha::operator==(Fecha fec){
    return dia == fec.dia and mes == fec.mes and anio == fec.anio;
}
Fecha::~Fecha()
{
}
