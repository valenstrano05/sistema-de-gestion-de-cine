#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "clsFuncion.h"

void cargarCadena (const char* mensaje, char* cadena, int tam);
int pedirEntero(const char * mensaje);
int butacasOcupadas(int idFuncion);
int butacasDisponibles(Funcion f);

void cargarPelicula();
void listarPeliculas();
void modificarPelicula();
void cambiarEstadoPelicula();
bool confirmacionSalida();

void cargarDescuento();
void listarDescuentos();
void modificarDescuento();
void cambiarEstadoDescuento();

void cargarSocio();
void listarSocios();
void modificarSocio();
void cambiarEstadoSocio();

void cargarFormato();
void listarFormatos();
void modificarFormato();
void cambiarEstadoFormato();

void cargarSala();
void listarSalas();
void modificarSala();
void cambiarEstadoSala();

void cargarButaca();
void listarButacas();
void cambiarEstadoButaca();

void cargarFuncion();
void listarFunciones();
void modificarFuncion();
void cambiarEstadoFuncion();

void registrarCompra();
void listarCompras();
void consultarComprasPorSocio();
void cambiarEstadoCompra();

void informeRankingRecaudacionPeliculas();
void informeOcupacionPorFuncion();
void informeEntradasPorFormato();
void informeSociosMasFrecuentes();
void informeImpactoDescuentos();
void informeTicketsSuperanPromedio();

#endif // FUNCIONES_H_INCLUDED
