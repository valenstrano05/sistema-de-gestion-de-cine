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
        cin >> dia >> mes >> anio;
        if (dia <= 0 || dia >= 32 || mes <= 0 || mes >= 13 || anio < 0)
        {
            cout << "Fecha incorrecta, intente de nuevo." << endl;
        }
    }
    while (dia <= 0 || dia >= 32 || mes <= 0 || mes >= 13 || anio < 0);
}
void Fecha::Mostrar()
{
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
bool Fecha::operator==(Fecha fec)
{
    return dia == fec.dia and mes == fec.mes and anio == fec.anio;
}
Fecha::~Fecha()
{
}
bool Fecha::operator>(Fecha fec)
{
if (anio!=fec.anio){
    if (anio>fec.anio){
        return true;
    }
    else{
        return false;
    }
}
if (mes!=fec.mes){
    if(mes>fec.mes){
        return true;
    }
    else{
        return false;
    }
}
if (dia!=fec.dia){
    if (dia>fec.dia){
        return true;
    }
    return false;
}
}

bool Fecha::operator<(Fecha fec)
{
if (anio!=fec.anio){
    if (anio<fec.anio){
        return true;
    }
    else{
        return false;
    }
}
if (mes!=fec.mes){
    if(mes<fec.mes){
        return true;
    }
    else{
        return false;
    }
}
if (dia!=fec.dia){
    if (dia<fec.dia){
        return true;
    }
    return false;
}
}
