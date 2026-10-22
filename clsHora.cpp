#include <iostream>
#include "clsHora.h"

using namespace std;

Hora::Hora(int h, int m) {
    hora = h;
    minutos = m;
}

void Hora::setHora(int h) {
    hora = h;
}

void Hora::setMinutos(int m) {
    minutos = m;
}

int Hora::getHora() {
    return hora;
}

int Hora::getMinutos() {
    return minutos;
}

void Hora::Cargar() {
    do {
        cout << "Ingrese la hora (0-23): ";
        cin >> hora;
        if (hora < 0 || hora > 23) {
            cout << "Error, la hora tiene que estar entre 0 y 23, intente de nuevo." << endl;
        }
    } while (hora < 0 || hora > 23);

    do {
        cout << "Ingrese los minutos (0-59): ";
        cin >> minutos;
        if (minutos < 0 || minutos > 59) {
            cout << "Error, los minutoss tienen que estar entre 0 y 59, intente de nuevo." << endl;
        }
    } while (minutos < 0 || minutos > 59);
}

void Hora::Mostrar() {
    cout << "Hora: "<< hora<< ":"<<minutos<<endl;
}

bool Hora::operator==(Hora h) {
    return hora == h.hora && minutos == h.minutos;
}

Hora::~Hora() {
}
