#include <iostream>
#include "clsHora.h"

using namespace std;

Hora::Hora(int h, int m)
{
    hora = h;
    minutos = m;
}

void Hora::setHora(int h)
{
    hora = h;
}

void Hora::setMinutos(int m)
{
    minutos = m;
}

int Hora::getHora()
{
    return hora;
}

int Hora::getMinutos()
{
    return minutos;
}

void Hora::Cargar()
{
    do
    {
        cin >> hora >> minutos;
        if (hora < 0 || hora > 23 || minutos < 0 || minutos > 59)
        {
            cout << "Hora incorrecta, intente de nuevo." << endl;
        }
    }
    while (hora < 0 || hora > 23 || minutos < 0 || minutos > 59);
}

void Hora::Mostrar()
{
    cout << hora<< ":"<<minutos;
}

bool Hora::operator==(Hora h)
{
    return hora == h.hora && minutos == h.minutos;
}

Hora::~Hora()
{
}
bool Hora::operator>(Hora h)
{
    if (hora != h.hora)
    {
        if (hora > h.hora)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (minutos != h.minutos)
    {
        if (minutos > h.minutos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool Hora::operator<(Hora h)
{
    if (hora != h.hora)
    {
        if (hora < h.hora)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (minutos != h.minutos)
    {
        if (minutos < h.minutos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
