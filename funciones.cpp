#include <iostream>
#include <windows.h>
#include "funciones.h"
#include "clsArchivoDescuento.h"
#include "clsArchivoPeliculas.h"
#include "clsArchivoButacas.h"
#include "clsArchivoSalas.h"
#include "clsArchivoSocios.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoFormato.h"
#include "clsArchivoCompras.h"
#include "clsArchivoDetalleEntradas.h"

using namespace std;

// ----------------------------------
//UTILIDAD

void cargarCadena(const char* mensaje, char* palabra, int tam)
{
    cout << mensaje;
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    cin.getline(palabra, tam);
    while (palabra[0] == '\0')
    {
        cout << "Campo obligatorio. " << mensaje;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(palabra, tam);
    }
}

int pedirEntero(const char * mensaje)
{
    int n;
    cout << mensaje;
    if (!(cin >> n))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    cin.ignore(1000, '\n');
    return n;
}

//-------------------------------------------

int butacasOcupadas(int idFuncion)
{
    ArchivoDetalleEntradas archD;
    ArchivoCompras archC;
    int ocupadas = 0;

    for (int i = 0; i < archD.contarRegistros(); i++)
    {
        DetalleEntrada detalle = archD.leerRegistro(i);

        if (detalle.getIdFuncion() == idFuncion)
        {
            int pos = archC.buscarRegistro(detalle.getIdCompra());
            if (pos != -1 && archC.leerRegistro(pos).getEstado())
            {
                ocupadas++;
            }
        }
    }
    return ocupadas;
}

int butacasDisponibles(Funcion f)
{
    ArchivoSalas arc;
    int pos = arc.buscarRegistro(f.getIdSala());
    if (pos == -1) return 0;

    int capacidad = arc.leerRegistro(pos).getCapacidadButacas();
    return capacidad - butacasOcupadas(f.getIdFuncion());
}

//-------------------------------------------
//PELICULAS

void cargarPelicula()
{
    ArchivoPeliculas arch;
    Pelicula obj;
    obj.cargar();
    if (arch.guardarRegistro(obj))
    {
        cout << "\n Registro exitoso!" << endl;
    }
    else
    {
        cout << "\n Error al guardar el archivo." << endl;
    }
    system("pause");
}

void listarPeliculas()
{
    ArchivoPeliculas arch;
    if (arch.contarRegistros() == 0)
    {
        cout << "No hay peliculas registradas." << endl << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < arch.contarRegistros(); i++)
    {
        Pelicula obj = arch.leerRegistro(i);
        obj.mostrar();
    }
    cout << endl;
    system("pause");
}

void modificarPelicula()
{
    int idBuscado;
    cout << "Ingrese ID de pelicula a modificar: ";
    cin >> idBuscado;

    ArchivoPeliculas arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1)
    {
        cout << "No existe registro activo con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Pelicula obj = arch.leerRegistro(pos);
    obj.modificar();

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Registro modificado con exito." << endl;
    }
    else
    {
        cout << "Error al intentar guardar los cambios." << endl;
    }
    system("pause");
}

void cambiarEstadoPelicula()
{
    int idBuscado;
    cout << "Ingrese el ID a modificar su estado: ";
    cin >> idBuscado;

    ArchivoPeliculas arch;
    int pos = arch.buscarPorIDInactivo(idBuscado);
    if (pos == -1)
    {
        cout << "No se encontro un registro con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }
    Pelicula obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "La película previamente dada de baja ha vuelto a ser activada." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de película " << idBuscado << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
    system("pause");
}

bool confirmacionSalida()
{
    char opcion;
    cout << "Esta seguro/a de que desea salir? (S/N):";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S')
    {
        return true;
    }
    return false;
}

//-------------------------------------------
//DESCUENTOS

void cargarDescuento()
{
    ArchivoDescuento arch;
    Descuento obj;
    obj.cargar();
    if (arch.guardar(obj))
    {
        cout << "\nRegistro exitoso!" << endl;
    }
    else
    {
        cout << "\nError al guardar el archivo." << endl;
    }
    system("pause");
}

void listarDescuentos()
{
    ArchivoDescuento arch;
    int cant = arch.cantidadRegistros();
    if (cant == 0)
    {
        cout << "No hay registros activos." << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < cant; i++)
    {
        Descuento obj = arch.leer(i);
        obj.mostrar();
    }
    cout << endl;
    system("pause");
}

void modificarDescuento()
{
    int idBuscado;
    cout << "Ingrese el ID del descuento a modificar: ";
    cin >> idBuscado;
    ArchivoDescuento arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1)
    {
        cout << "No hay descuentos activos con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }
    Descuento obj = arch.leer(pos);
    obj.modificar();
    if (arch.modificar(obj, pos))
    {
        cout << "Registro modificado con exito!" << endl;
    }
    else
    {
        cout << "Error al modificar el archivo." << endl;
    }
    system("pause");
}

void cambiarEstadoDescuento()
{
    int idBuscado;
    cout << "Ingrese el ID del descuento a modificar su estado: ";
    cin >> idBuscado;

    ArchivoDescuento arch;
    int pos = arch.buscarPorIDInactivo(idBuscado);
    if (pos == -1)
    {
        cout << "No hay descuento activo con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Descuento obj = arch.leer(pos);
    if (obj.getEstado() == false)
    {
        cout << "El descuento previamente dado de baja ha vuelto a ser activado." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificar(obj, pos))
    {
        cout << "Estado de descuento " << idBuscado << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
    system("pause");
}

//-------------------------------------------
//SOCIOS

void cargarSocio()
{
    ArchivoSocios arch;
    Socio obj;

    obj.cargar();
    if (arch.grabarRegistro(obj))
    {
        cout << "Socio cargado correctamente." << endl;
    }
    else
    {
        cout << "Error al guardar el socio." << endl;
    }
    system("pause");
}

void listarSocios()
{
    ArchivoSocios arch;
    int cantidad = arch.contarRegistros();

    if (cantidad == 0)
    {
        cout << "No hay socios cargados." << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < cantidad; i++)
    {
        Socio obj = arch.leerRegistro(i);
        obj.mostrar();
    }
    system("pause");
}

void modificarSocio()
{
    ArchivoSocios arch;

    int id = pedirEntero("ID del socio a modificar: ");
    int pos = arch.buscarRegistro(id);
    if (pos == -1)
    {
        cout << "No existe un socio con ese ID." << endl;
        system("pause");
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
    switch (opcion)
    {
    case 1:
        dni = pedirEntero("NUEVO DNI: ");
        while (dni < 1000000 || dni > 99999999)
        {
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
        system("pause");
        return;
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Socio modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al modificar el socio." << endl;
    }
    system("pause");
}

void cambiarEstadoSocio()
{
    ArchivoSocios arch;

    int id = pedirEntero("ID del socio a modificar estado: ");
    int pos = arch.buscarRegistroInactivo(id);
    if (pos == -1)
    {
        cout << "No existe un socio con ese ID." << endl;
        system("pause");
        return;
    }

    Socio obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "El socio previamente dado de baja ha vuelto a ser activado." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de socio " << id << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
    system("pause");
}

//-------------------------------------------
//FORMATOS

void cargarFormato()
{
    ArchivoFormato arch;
    Formato obj;
    obj.cargar();
    if (arch.guardarRegistro(obj))
    {
        cout << "\n Registro exitoso!" << endl;
    }
    else
    {
        cout << "\n Error al guardar el archivo." << endl;
    }
    system("pause");
}

void listarFormatos()
{
    ArchivoFormato arch;
    if (arch.contarRegistros() == 0)
    {
        cout << "No hay formatos registrados." << endl << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < arch.contarRegistros(); i++)
    {
        Formato obj = arch.leerRegistro(i);
        obj.mostrar();
    }
    cout << endl;
    system("pause");
}

void modificarFormato()
{
    int idBuscado;
    cout << "Ingrese ID del formato a modificar: ";
    cin >> idBuscado;

    ArchivoFormato arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1)
    {
        cout << "No existe registro activo con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Formato obj = arch.leerRegistro(pos);
    obj.modificar();

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Registro modificado con exito." << endl;
    }
    else
    {
        cout << "Error al intentar guardar los cambios." << endl;
    }
    system("pause");
}

void cambiarEstadoFormato()
{
    int idBuscado;
    cout << "Ingrese el ID a modificar su estado: ";
    cin >> idBuscado;

    ArchivoFormato arch;
    int pos = arch.buscarPorIDInactivo(idBuscado);
    if (pos == -1)
    {
        cout << "No se encontro un registro con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }
    Formato obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "El formato previamente dado de baja ha vuelto a ser activado." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de formato " << idBuscado << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
    system("pause");
}

//-------------------------------------------
//SALAS

void cargarSala()
{
    ArchivoSalas arch;
    ArchivoButacas archButacas;
    Sala obj;

    obj.cargar();
    if (arch.grabarRegistro(obj))
    {
        archButacas.generarButacas(obj.getIdSala(), obj.getCapacidadButacas());
        cout << "Sala cargada correctamente (" << obj.getCapacidadButacas() << " butacas generadas)." << endl;
    }
    else
    {
        cout << "Error al guardar la sala." << endl;
    }
    system("pause");
}

void listarSalas()
{
    ArchivoSalas arch;
    int cantidad = arch.contarRegistros();

    if (cantidad == 0)
    {
        cout << "No hay salas cargadas." << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < cantidad; i++)
    {
        Sala obj = arch.leerRegistro(i);
        obj.mostrar();
    }
    system("pause");
}

void modificarSala()
{
    ArchivoSalas arch;

    int id = pedirEntero("ID de la sala a modificar: ");
    int pos = arch.buscarRegistro(id);
    if (pos == -1)
    {
        cout << "No existe una sala con ese ID." << endl;
        system("pause");
        return;
    }

    Sala obj = arch.leerRegistro(pos);
    cout << "1. FORMATO DE PROYECCION" << endl;
    cout << "0. CANCELAR" << endl;
    int opcion = pedirEntero("Que desea modificar: ");

    int formato;
    switch (opcion)
    {
    case 1:
        formato = pedirEntero("NUEVO FORMATO (1: 2D, 2: 3D, 3: IMAX): ");
        while (formato < 1 || formato > 3)
        {
            formato = pedirEntero("Error, ingrese un formato valido (1, 2 o 3): ");
        }
        obj.setFormatoProyeccion(formato);
        break;
    default:
        cout << "No se modifico nada." << endl;
        system("pause");
        return;
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Sala modificada correctamente." << endl;
    }
    else
    {
        cout << "Error al modificar la sala." << endl;
    }
    system("pause");
}

void cambiarEstadoSala()
{
    ArchivoSalas arch;
    ArchivoButacas archButacas;

    int id = pedirEntero("ID de la sala a cambiar de estado: ");
    int pos = arch.buscarRegistroInactivo(id);
    if (pos == -1)
    {
        cout << "No existe una sala con ese ID." << endl;
        system("pause");
        return;
    }

    Sala obj = arch.leerRegistro(pos);
    bool nuevoEstado = !obj.getEstado();
    obj.setEstado(nuevoEstado);

    if (!arch.modificarRegistro(obj, pos))
    {
        cout << "Error al modificar el estado de la sala." << endl;
        system("pause");
        return;
    }

    int cantidad = archButacas.contarRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        Butaca b = archButacas.leerRegistro(i);
        if (b.getIdSala() == id)
        {
            b.setEstado(nuevoEstado);
            archButacas.modificarRegistro(b, i);
        }
    }
    if (nuevoEstado)
    {
        cout << "Sala y sus butacas reactivadas correctamente." << endl;
    }
    else
    {
        cout << "Sala y sus butacas dadas de baja correctamente." << endl;
    }
    system("pause");
}

//-------------------------------------------
//BUTACAS

void listarButacas()
{
    ArchivoSalas archSalas;
    ArchivoButacas arch;

    int idSala = pedirEntero("ID de la sala: ");
    if (archSalas.buscarRegistro(idSala) == -1)
    {
        cout << "No existe una sala con ese ID." << endl;
        system("pause");
        return;
    }

    int cantidad = arch.contarRegistros();
    int mostradas = 0;
    for (int i = 0; i < cantidad; i++)
    {
        Butaca obj = arch.leerRegistro(i);
        if (obj.getIdSala() == idSala && obj.getEstado())
        {
            obj.mostrar();
            mostradas++;
        }
    }
    cout << "Total de butacas disponibles de la sala " << idSala << ": " << mostradas << endl;
    system("pause");
}

void cambiarEstadoButaca()
{
    ArchivoSalas archSalas;
    ArchivoButacas archButacas;
    int idSala = pedirEntero("ID de la sala: ");
    while (idSala <= 0)
    {
        idSala = pedirEntero("ID invalido. Ingrese un ID de sala mayor a 0: ");
    }

    if (archSalas.buscarRegistroInactivo(idSala) == -1)
    {
        cout << "No existe una sala registrada con ese ID." << endl;
        system("pause");
        return;
    }
    char numButaca[7];
    cargarCadena("Ingrese el numero de la butaca a modificar estado (ej: F11B26): ", numButaca, 7);
    int cantidad = archButacas.contarRegistros();
    int posBuscada = -1;

    for (int i = 0; i < cantidad; i++)
    {
        Butaca b = archButacas.leerRegistro(i);
        if (b.getIdSala() == idSala && strcmp(b.getNumeroButaca(), numButaca) == 0)
        {
            posBuscada = i;
            break;
        }
    }

    if (posBuscada == -1)
    {
        cout << "No se encontro una butaca con ese numero en la sala " << idSala << "." << endl;
        system("pause");
        return;
    }

    Butaca obj = archButacas.leerRegistro(posBuscada);

    if (obj.getEstado() == false)
    {
        cout << "La butaca previamente dada de baja ha vuelto a ser activada." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }
    if (archButacas.modificarRegistro(obj, posBuscada))
    {
        cout << "Estado de Butaca " << numButaca << " de la sala " << idSala << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo de butacas." << endl;
    }
    system("pause");
}

//-------------------------------------------
//FUNCIONES

void cargarFuncion()
{
    ArchivoFunciones arch;
    Funcion obj;
    obj.cargar();
    if (arch.grabarRegistro(obj))
    {
        cout << "\n Registro exitoso!" << endl;
    }
    else
    {
        cout << "\n Error al guardar el archivo." << endl;
    }
    system("pause");
}

void listarFunciones()
{
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();
    if (cant == 0)
    {
        cout << "No hay funciones registradas." << endl;
    }
    else
    {
        for (int i = 0; i < cant; i++)
        {
            Funcion obj = arch.leerRegistro(i);
            if(obj.getEstado()){
            obj.mostrar();
            cout << "BUTACAS DISPONIBLES: " << butacasDisponibles(obj) << endl;
            cout << "=====================================" << endl;
            }
        }
    }
    cout << endl;
    system("pause");
}

void modificarFuncion()
{
    int idBuscado;
    cout << "Ingrese el ID de la funcion a modificar: ";
    cin >> idBuscado;
    ArchivoFunciones arch;
    int pos = arch.buscarRegistro(idBuscado);
    if (pos == -1)
    {
        cout << "Error, no hay funcion registrada con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Funcion obj = arch.leerRegistro(pos);
    obj.modificar();

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Registro actualizado." << endl;
    }
    else
    {
        cout << "Error al actualizar el registro." << endl;
    }
    system("pause");
}

void cambiarEstadoFuncion()
{
    int idBuscado;
    cout << "Ingrese el ID de la funcion a modificar estado: ";
    cin >> idBuscado;
    ArchivoFunciones arch;
    int pos = arch.buscarRegistroInactivo(idBuscado);
    if (pos == -1)
    {
        cout << "Error, no se registro una funcion con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Funcion obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "La funcion previamente dada de baja ha vuelto a ser activada." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de funcion " << idBuscado << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al cambiar el estado de la funcion." << endl;
    }
    system("pause");
}

//-------------------------------------------
//COMPRAS
void registrarCompra() {
    ArchivoCompras arch;
    Compra obj;
    obj.cargar();
    if (arch.grabarRegistro(obj))
    {
        cout << "\n Registro exitoso!" << endl;
    }
    else
    {
        cout << "\n Error al guardar el archivo." << endl;
    }
    system("pause");
}
void listarCompras()
{
    ArchivoCompras arch;
    int cant = arch.contarRegistros();
    if (cant == 0)
    {
        cout << "No hay compras registradas." << endl;
    }
    else
    {
        for (int i = 0; i < cant; i++)
        {
            Compra obj = arch.leerRegistro(i);
            obj.mostrar();
            cout << "=====================================" << endl;
        }
    }
    cout << endl;
    system("pause");
}

void cambiarEstadoCompra()
{
    int idBuscado;
    cout << "Ingrese el ID de la compra a modificar su estado: ";
    cin >> idBuscado;

    ArchivoCompras arch;
    int pos = arch.buscarRegistroInactivo(idBuscado);
    if (pos == -1)
    {
        cout << "No se encontro una compra con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Compra obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "La compra previamente dada de baja ha vuelto a ser activada." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de compra " << idBuscado << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo de compras." << endl;
    }
    system("pause");
}

//-------------------------------------------
//INFORMES
void informeRankingRecaudacionPeliculas() {}
void informeOcupacionPorFuncion() {}
void informeEntradasPorFormato() {}
void informeSociosMasFrecuentes() {}
void informeImpactoDescuentos() {}
void informeTicketsSuperanPromedio() {}
