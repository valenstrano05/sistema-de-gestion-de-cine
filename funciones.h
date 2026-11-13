#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "clsFuncion.h"

void cargarCadena (const char* mensaje, char* cadena, int tam);
int pedirEntero(const char * mensaje);
int butacasOcupadas(int idFuncion);
int butacasDisponibles(Funcion f);

void cargarPelicula();
void modificarPelicula();
void cambiarEstadoPelicula();
bool confirmacionSalida();

void cargarDescuento();
void modificarDescuento();
void cambiarEstadoDescuento();

void cargarSocio();
void modificarSocio();
void cambiarEstadoSocio();

void cargarFormato();
void modificarFormato();
void cambiarEstadoFormato();

void cargarSala();
void modificarSala();
void cambiarEstadoSala();

void cargarButaca();
void cambiarEstadoButaca();

void cargarFuncion();
void modificarFuncion();
void cambiarEstadoFuncion();

void registrarCompra();
void consultarComprasPorSocio();
void cambiarEstadoCompra();

void informeRankingRecaudacionPeliculas();
void informeOcupacionPorFuncion();
void informeEntradasPorFormato();
void informeSociosMasFrecuentes();
void informeImpactoDescuentos();
void informeTicketsSuperanPromedio();

#endif // FUNCIONES_H_INCLUDED
