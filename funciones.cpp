#include <iostream>
#include "funciones.h"
#include "clsArchivoDescuento.h"
#include "clsArchivoPeliculas.h"
#include "clsArchivoButacas.h"
#include "clsArchivoSalas.h"
#include "clsArchivoSocios.h"

using namespace std;

// ----------------------------------
//UTILIDAD

void cargarCadena(const char* mensaje, char* palabra, int tam) {
    string texto;
    cout << mensaje;
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, texto);
    while (texto[0] == '\0') {
        cout << "Campo obligatorio. " << mensaje;
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        getline(cin, texto);
    }
    strncpy(palabra, texto.c_str(), tam);
    palabra[tam - 1] = '\0';
}
//-------------------------------------------
//Pide un numero entero. Si lo ingresado no es un numero devuelve -1 y deja el buffer limpio para poder usar getline despues.
int pedirEntero(const char * mensaje){
    int n;
    cout << mensaje;
    if (!(cin >> n)){
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    cin.ignore(1000, '\n');
    return n;
}
//-------------------------------------------
//PELICULAS

void cargarPelicula(){
    ArchivoPelicula arch;
    Pelicula obj;
       obj.cargar();
       if (arch.guardar(obj)){
            cout<<endl;
            cout<<"Registro exitoso!"<<endl;
        }else {
            cout<<endl;
            cout <<"Error al guardar el archivo"<<endl;
        }
}


void listarPeliculas(){
    ArchivoPelicula arch;
    if (arch.cantidadRegistros()==0){
        cout <<"No hay peliculas registradas."<<endl;
        return;
    }
    for (int i = 0; i < arch.cantidadRegistros(); i++) {
        Pelicula obj = arch.leer(i);
        obj.mostrar();
    }
    cout << endl;
    system("pause");
}

void modificarPelicula(){
    int idBuscado;
    cout <<"Ingrese ID de pelicula a modificar: "; cin>>idBuscado;

    ArchivoPelicula arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1){
        cout <<"No existe registro activo con el ID " <<idBuscado <<"." <<endl;
        return;
    }

    Pelicula obj = arch.leer(pos);
    obj.modificar();

    if (arch.modificar(obj, pos)) {
        cout << "Registro modificado con exito." << endl;
    }else {
        cout << "Error al intentar guardar los cambios." << endl;
    }
}


void darBajaPelicula(){
    int idBuscado;
    cout <<"Ingrese el ID a dar de baja: "; cin >>idBuscado;

    ArchivoPelicula arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1){
        cout <<"No se encontro un registro con el ID " <<idBuscado <<"." <<endl;
    }
    Pelicula obj = arch.leer(pos);
    obj.setEstado(false);

    if (arch.modificar(obj, pos)) {
        cout << "Registro dado de baja con exito." << endl;
    } else {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
}

bool confirmacionSalida(){
    char opcion;
    cout <<"Esta seguro/a de que desea salir? (S/N):"; cin >>opcion;
    if (opcion == 's' || opcion == 'S'){
        return true;
    }
    return false;
}

//-------------------------------------------
//SOCIOS

void cargarSocio(){
    ArchivoSocios arch;
    Socio obj;

    obj.cargar();
    if (arch.grabarRegistro(obj)){
        cout << "Socio cargado correctamente." << endl;
    }
    else {
        cout << "Error al guardar el socio." << endl;
    }
}

void listarSocios(){
    ArchivoSocios arch;
    int cantidad = arch.contarRegistros();

    if (cantidad == 0){
        cout << "No hay socios cargados." << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++){
        Socio obj = arch.leerRegistro(i);
        obj.mostrar();
    }
}

void modificarSocio(){
    ArchivoSocios arch;

    int id = pedirEntero("ID del socio a modificar: ");
    int pos = arch.buscarRegistro(id);
    if (pos == -1){
        cout << "No existe un socio con ese ID." << endl;
        return;
    }

    Socio obj = arch.leerRegistro(pos);
    cout << "1. DNI" << endl;
    cout << "2. NOMBRE" << endl;
    cout << "3. APELLIDO" << endl;
    cout << "0. CANCELAR" << endl;
    int opcion = pedirEntero("Que desea modificar: ");

    char texto[30];
    int dni;
    switch (opcion){
    case 1:
        dni = pedirEntero("NUEVO DNI: ");
        while (dni < 1000000 || dni > 99999999){
            dni = pedirEntero("Error, el DNI debe tener 7 u 8 digitos. Ingresar nuevamente: ");
        }
        obj.setDni(dni);
        break;
    case 2:
        cargarCadena("NUEVO NOMBRE: ", texto, 30);
        obj.setNombre(texto);
        break;
    case 3:
        cargarCadena("NUEVO APELLIDO: ", texto, 30);
        obj.setApellido(texto);
        break;
    default:
        cout << "No se modifico nada." << endl;
        return;
    }

    if (arch.modificarRegistro(obj, pos)){
        cout << "Socio modificado correctamente." << endl;
    }
    else {
        cout << "Error al modificar el socio." << endl;
    }
}

void darBajaSocio(){
    ArchivoSocios arch;

    int id = pedirEntero("ID del socio a dar de baja: ");
    int pos = arch.buscarRegistro(id);
    if (pos == -1){
        cout << "No existe un socio con ese ID." << endl;
        return;
    }

    Socio obj = arch.leerRegistro(pos);
    obj.setEstado(false);
    if (arch.modificarRegistro(obj, pos)){
        cout << "Socio dado de baja correctamente." << endl;
    }
    else {
        cout << "Error al dar de baja el socio." << endl;
    }
}
//-------------------------------------------
//SALAS

void cargarSala(){
    ArchivoSalas arch;
    ArchivoButacas archButacas;
    Sala obj;

    obj.cargar();
    if (arch.grabarRegistro(obj)){
        archButacas.generarButacas(obj.getIdSala(), obj.getCapacidadButacas());
        cout << "Sala cargada correctamente (" << obj.getCapacidadButacas() << " butacas generadas)." << endl;
    }
    else {
        cout << "Error al guardar la sala." << endl;
    }
}

void listarSalas(){
    ArchivoSalas arch;
    int cantidad = arch.contarRegistros();

    if (cantidad == 0){
        cout << "No hay salas cargadas." << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++){
        Sala obj = arch.leerRegistro(i);
        obj.mostrar();
    }
}

void modificarSala(){
    ArchivoSalas arch;

    int id = pedirEntero("ID de la sala a modificar: ");
    int pos = arch.buscarRegistro(id);
    if (pos == -1){
        cout << "No existe una sala con ese ID." << endl;
        return;
    }

    Sala obj = arch.leerRegistro(pos);
    cout << "1. FORMATO DE PROYECCION" << endl;
    cout << "2. PRECIO" << endl;
    cout << "0. CANCELAR" << endl;
    int opcion = pedirEntero("Que desea modificar: ");

    int formato;
    float precio;
    switch (opcion){
    case 1:
        formato = pedirEntero("NUEVO FORMATO (1: 2D, 2: 3D, 3: IMAX): ");
        while (formato < 1 || formato > 3){
            formato = pedirEntero("Error, ingrese un formato valido (1, 2 o 3): ");
        }
        obj.setFormatoProyeccion(formato);
        break;
    case 2:
        cout << "NUEVO PRECIO: ";
        while (!(cin >> precio) || precio <= 0){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error, el precio debe ser un numero mayor a 0. Ingresar nuevamente: ";
        }
        cin.ignore(1000, '\n');
        obj.setPrecio(precio);
        break;
    default:
        cout << "No se modifico nada." << endl;
        return;
    }

    if (arch.modificarRegistro(obj, pos)){
        cout << "Sala modificada correctamente." << endl;
    }
    else {
        cout << "Error al modificar la sala." << endl;
    }
}

void darBajaSala(){
    ArchivoSalas arch;
    ArchivoButacas archButacas;

    int id = pedirEntero("ID de la sala a dar de baja: ");
    int pos = arch.buscarRegistro(id);
    if (pos == -1){
        cout << "No existe una sala con ese ID." << endl;
        return;
    }

    Sala obj = arch.leerRegistro(pos);
    obj.setEstado(false);
    if (!arch.modificarRegistro(obj, pos)){
        cout << "Error al dar de baja la sala." << endl;
        return;
    }

    // Tambien se dan de baja las butacas de esa sala
    int cantidad = archButacas.contarRegistros();
    for (int i = 0; i < cantidad; i++){
        Butaca b = archButacas.leerRegistro(i);
        if (b.getIdSala() == id && b.getEstado()){
            b.setEstado(false);
            archButacas.modificarRegistro(b, i);
        }
    }
    cout << "Sala y sus butacas dadas de baja correctamente." << endl;
}
//-------------------------------------------
//BUTACAS

void cargarButaca(){
    ArchivoButacas arch;
    Butaca obj;

    obj.cargar();
    if (arch.grabarRegistro(obj)){
        cout << "Butaca cargada correctamente." << endl;
    }
    else {
        cout << "Error al guardar la butaca." << endl;
    }
}

void listarButacas(){
    ArchivoSalas archSalas;
    ArchivoButacas arch;

    int idSala = pedirEntero("ID de la sala: ");
    if (archSalas.buscarRegistro(idSala) == -1){
        cout << "No existe una sala con ese ID." << endl;
        return;
    }

    int cantidad = arch.contarRegistros();
    int mostradas = 0;
    for (int i = 0; i < cantidad; i++){
        Butaca obj = arch.leerRegistro(i);
        if (obj.getIdSala() == idSala && obj.getEstado()){
            obj.mostrar();
            mostradas++;
        }
    }
    cout << "Total de butacas de la sala " << idSala << ": " << mostradas << endl;
}

void darBajaButaca(){
    ArchivoButacas arch;

    int id = pedirEntero("ID de la butaca a dar de baja: ");
    int pos = arch.buscarRegistro(id);
    if (pos == -1){
        cout << "No existe una butaca con ese ID." << endl;
        return;
    }

    Butaca obj = arch.leerRegistro(pos);
    obj.setEstado(false);
    if (arch.modificarRegistro(obj, pos)){
        cout << "Butaca dada de baja correctamente." << endl;
    }
    else {
        cout << "Error al dar de baja la butaca." << endl;
    }
}
