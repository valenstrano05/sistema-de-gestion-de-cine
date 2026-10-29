#include <iostream>
#include <cstring>
#include "clsPelicula.h"
#include "clsArchivoPeliculas.h"
#include "fecha.h"
#include "funciones.h"
using namespace std;



Pelicula::Pelicula(int _id, const char* _titulo, const char* _genero, const char* _director, const char* _sinopsis,
Fecha _fecha, int _duracion, int _clasificacion, bool _estado)
{
    id = _id;
    strcpy(titulo, _titulo);
    strcpy(genero, _genero);
    strcpy(director, _director);
    strcpy(sinopsis, _sinopsis);
    fechaEstreno = _fecha;
    duracion = _duracion;
    clasificacion = _clasificacion;
    estado = _estado;
}


void Pelicula::cargar()
{
    ArchivoPelicula arch;
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
    cout << "Ingresar Id nuevamente: ";
    }

    cin.ignore();
    cargarCadena("TITULO: ", titulo, 50);

    cargarCadena("GENERO: ", genero, 30);

    cargarCadena("DIRECTOR: ", director, 50);

    cargarCadena("SINOPSIS: \n", sinopsis, 500);

    cout <<"FECHA DE ESTRENO (DD MM AAAA): ";
    fechaEstreno.Cargar();

    cout <<"DURACION (en minutos): ";
    cin >>duracion;
    while (duracion<=0 || duracion>=300){
        cout <<"Error, ingrese una duracion valida: ";
        cin >>duracion;
    }

    cout <<"CLASIFICACION (1: ATP, 2: +14, 3: +18): ";
    cin >>clasificacion;
    while (clasificacion < 1 || clasificacion > 3){
        cout <<"Error, ingrese una clasificación válida: ";
        cin >>clasificacion;
    }

    estado = true;
}



void Pelicula::mostrar()
{
    if (estado){
        cout <<"---------------------------------------" <<endl;
        cout <<"             " <<titulo <<endl;
        cout <<"---------------------------------------" <<endl;
        cout <<"ID: " <<id <<endl;
        cout <<"GENERO: " <<genero <<endl;
        cout <<"DIRECTOR: " <<director <<endl;
        cout <<"SINOPSIS: " <<sinopsis <<endl;
        cout <<"FECHA DE ESTRENO: ";
        fechaEstreno.Mostrar();
        cout <<"DURACION: " <<duracion <<endl;
        cout <<"CLASIFICACION: ";
        switch(clasificacion){
        case 1: cout <<"ATP"<<endl; break;
        case 2: cout <<"+14" <<endl; break;
        case 3: cout <<"+18" <<endl; break;}
        cout <<endl;
    }
}



void Pelicula::modificar()
{
    int opcion;
    cout <<"Seleccione el campo a modificar..." <<endl;
<<<<<<< HEAD
    cout <<"1. TITULO " <<endl;
    cout <<"2. GENERO " <<endl;
    cout <<"3. DIRECTOR " <<endl;
    cout <<"4. SINOPSIS " <<endl;
    cout <<"5. FECHA DE ESTRENO " <<endl;
    cout <<"6. DURACION " <<endl;
    cout <<"7. CLASIFICACION" <<endl;
    cin >>opcion;
=======
    cout <<"1. TITULO: " <<endl;
    cout <<"2. GENERO: " <<endl;
    cout <<"3. DIRECTOR: " <<endl;
    cout <<"4. SINOPSIS: " <<endl;
    cout <<"5. FECHA DE ESTRENO: ";
    cout <<"6. DURACION: " <<endl;
    cout <<"7. CLASIFICACION: " <<endl;
    cin >> opcion;
>>>>>>> 643727e8bd71fed0e8af1ba20871ce70a4e00511
    switch(opcion){
        case 1:
            cin.ignore();
            cargarCadena("TITULO: ", titulo, 50);
        break;
        case 2:
            cin.ignore();
            cargarCadena("GENERO: ", genero, 30);
        break;
        case 3:
            cin.ignore();
            cargarCadena("DIRECTOR: ", director, 50);
        break;
        case 4:
            cin.ignore();
            cargarCadena("SINOPSIS: ", sinopsis, 500);
        break;
        case 5:
            cout <<"FECHA DE ESTRENO (DD MM AAAA): ";
            fechaEstreno.Cargar();
        break;
        case 6:
            cout <<"DURACION (en minutos): ";
            cin >>duracion;
            while (duracion<=0 || duracion>=300){
                cout <<"Error, ingrese una duracion valida: ";
                cin >>duracion;
            }
        break;
        case 7:
            cout <<"CLASIFICACION (1: ATP, 2: +14, 3: +18): ";
            cin >>clasificacion;
            while (clasificacion < 1 || clasificacion > 3){
                cout <<"Error, ingrese una clasificación válida: ";
                cin >>clasificacion;
            }
        break;
        default:
            cout <<"Opcion invalida." <<endl;
        break;
    }
}



void Pelicula::setID(int _id)
{
    if (_id>0) id=_id;
}

int Pelicula::getID()
{
    return id;
}


void Pelicula::setTitulo(const char* _titulo)
{
    if (_titulo != nullptr && _titulo[0] != '\0') {
        strcpy(titulo, _titulo);
    }
}
const char* Pelicula::getTitulo()
{
    return titulo;
}


void Pelicula::setGenero(const char* _genero)
{
    if (_genero!= nullptr && _genero[0] != '\0') {
        strcpy(genero, _genero);
    }
}
const char* Pelicula::getGenero()
{
    return genero;
}


void Pelicula::setDirector(const char* _director)
{
    if (_director != nullptr && _director[0] != '\0') {
        strcpy(director, _director);
    }
}

const char* Pelicula::getDirector()
{
    return director;
}


void Pelicula::setSinopsis(const char* _sinopsis)
{
    if (_sinopsis != nullptr && _sinopsis[0] != '\0') {
        strcpy(sinopsis, _sinopsis);
    }
}
const char* Pelicula::getSinopsis()
{
    return sinopsis;
}


void Pelicula::setFecha(Fecha fecha)
{
    fechaEstreno=fecha;
}
Fecha Pelicula::getFecha()
{
    return fechaEstreno;
}


void Pelicula::setDuracion(int _duracion)
{
    if (_duracion>0) duracion=_duracion;
}
int Pelicula::getDuracion()
{
    return duracion;
}


void Pelicula::setClasificacion(int clas)
{
    if (clas>=1 && clas<=3) clasificacion=clas;
}
int Pelicula::getClasificacion()
{
    return clasificacion;
}


void Pelicula::setEstado(bool _estado)
{
    estado=_estado;
}
bool Pelicula::getEstado()
{
    return estado;
}



